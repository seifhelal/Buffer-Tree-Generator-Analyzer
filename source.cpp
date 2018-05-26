//
//  main.cpp
//  mini_project
//
//  Created by SEIF on 4/12/18.
//  Copyright © 2018 SEIF. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "liberty.h"
using namespace std;
liberty::Library liberty_lib;
string FlipFlop_type, buff_type, inv_type;

float buff_capacitance(int size)
{
    return( liberty_lib.getCell(buff_type+to_string(size)).getPins()[0].getCapacitance());
}

struct buff{
    int level;
    float size;
    float updated_size;
    double delay[2]={0,0};
    double transition[2]={0,0};
    float stage_delay;
};
int main(int argc, char*argv[]) {
    string path="/Users/air/Desktop/osu035_stdcells.txt",out_file ;
    liberty_lib=liberty::parse(path);
    double ff_num=0;
    float C_out, C_in, delay_per_stage, inv;
    cout << "Please enter number of FlipFlops: " << endl;
    cin>>ff_num;
    cout << "Please enter name of FlipFlop: " << endl;
    cin>>FlipFlop_type;
    cout << "Please enter name of Buffer: " << endl;
    cin>>buff_type;
    cout << "Please enter name of inv: " << endl;
    cin>>inv_type;
    cout << "Please destination to save file: " << endl;
    cin>>out_file;
    int levels_num = log2(ff_num);
    if (pow(2, levels_num) < ff_num)
    levels_num+=1;
    C_out= liberty_lib.getCell(FlipFlop_type).getPins()[0].getCapacitance();
    C_in=buff_capacitance(1);
    inv=liberty_lib.getCell(inv_type+to_string(1)).getPins()[0].getCapacitance();
    delay_per_stage= pow(C_out/C_in*pow(2,levels_num),1.0/(levels_num+1));
    buff branch[levels_num];
    
    for (int i=levels_num; i>=1; i--)
    {
        if (i==levels_num)
            branch[i].size=C_out/(delay_per_stage*inv);
        else
            branch[i].size=(branch[i+1].size *2)/delay_per_stage;
    }
    branch[0].size=1;
    // get the right sizes
    vector<string> lines=liberty_lib.getCellNames();
    vector <string> real_sizes;

    for (int i=0; i < lines.size(); i++)
    {
        //search for the size
        string str="CLKBUF";
        int temp=lines[i].find(str);
        if (temp!=std::string::npos)
        {
            string sub=lines[i].substr(temp+str.size(), (lines[i].size()-(temp+str.size())));
            real_sizes.push_back(sub);
        }
    }
    
    for (int i=0; i<= levels_num; i++)
    {
        float min= 10000;
        for (int j =0; j < real_sizes.size(); j++)
        {
            if (abs(branch[i].size - stoi(real_sizes[j])) < min)
            {
                    branch[i].updated_size=stoi(real_sizes[j]);
                    min=abs(branch[i].size - stoi(real_sizes[j]));
            }
        }
    }
   //delay and transition times
   //1- delay
    for (int i=0; i <= levels_num; i++)
    {
        if (i==0)
        {
        branch[i].delay[0]= liberty_lib.getCell(buff_type+to_string(int(branch[i].updated_size))).getPins()[1].getTiming()[0].getCellRiseTable().getValue(buff_capacitance(branch[i+1].updated_size)*2, 0);
        
        branch[i].delay[1]= liberty_lib.getCell(buff_type+to_string(int(branch[i].updated_size))).getPins()[1].getTiming()[0].getCellFallTable().getValue(buff_capacitance(branch[i+1].updated_size)*2, 0);
        }
        else if (i==levels_num)
        {
            branch[i].delay[0]= liberty_lib.getCell(buff_type+to_string(int(branch[i].updated_size))).getPins()[1].getTiming()[0].getCellRiseTable().getValue(C_out, branch[i-1].transition[0]);
            
            branch[i].delay[1]= liberty_lib.getCell(buff_type+to_string(int(branch[i].updated_size))).getPins()[1].getTiming()[0].getCellFallTable().getValue(C_out, branch[i-1].transition[1]);
        }
        else
        {
            branch[i].delay[0]= liberty_lib.getCell(buff_type+to_string(int(branch[i].updated_size))).getPins()[1].getTiming()[0].getCellRiseTable().getValue(buff_capacitance(branch[i+1].updated_size)*2, branch[i-1].transition[0]);
            
            branch[i].delay[1]= liberty_lib.getCell(buff_type+to_string(int(branch[i].updated_size))).getPins()[1].getTiming()[0].getCellFallTable().getValue(buff_capacitance(branch[i+1].updated_size)*2, branch[i-1].transition[1]);
        }
    }
    //2- transition
    
    for (int i=0; i <= levels_num; i++)
    {
        if (i==0)
        {
            branch[i].transition[0]= liberty_lib.getCell(buff_type+to_string(int(branch[i].updated_size))).getPins()[1].getTiming()[0].getRiseTransitionTable().getValue(buff_capacitance(branch[i+1].updated_size)*2, 0);
            
            branch[i].transition[1]= liberty_lib.getCell(buff_type+to_string(int(branch[i].updated_size))).getPins()[1].getTiming()[0].getFallTransitionTable().getValue(buff_capacitance(branch[i+1].updated_size)*2, 0);
        }
        else if (i==levels_num)
        {
            branch[i].transition[0]= liberty_lib.getCell(buff_type+to_string(int(branch[i].updated_size))).getPins()[1].getTiming()[0].getRiseTransitionTable().getValue(C_out, branch[i-1].transition[0]);
            
            branch[i].transition[1]= liberty_lib.getCell(buff_type+to_string(int(branch[i].updated_size))).getPins()[1].getTiming()[0].getFallTransitionTable().getValue(C_out, branch[i-1].transition[1]);
        }
        else
        {
            branch[i].transition[0]= liberty_lib.getCell(buff_type+to_string(int(branch[i].updated_size))).getPins()[1].getTiming()[0].getRiseTransitionTable().getValue(buff_capacitance(branch[i+1].updated_size)*2, branch[i-1].transition[0]);
            
            branch[i].transition[1]= liberty_lib.getCell(buff_type+to_string(int(branch[i].updated_size))).getPins()[1].getTiming()[0].getFallTransitionTable().getValue(buff_capacitance(branch[i+1].updated_size)*2, branch[i-1].transition[1]);
        }
    }
    float dr=0, df=0, tr=0,tf=0;
    for (int i=0; i <= levels_num; i++)
    {
        dr+=branch[i].delay[0];
        df+=branch[i].delay[1];
        tr=branch[i].transition[0];
        tf=branch[i].transition[1];
    }
    
    
    ofstream file;
    file.open(out_file);
    
    //netlist
    file << "//Rise Delay =" << dr << endl;
    file << "//Clock Rise Transition Time =" << tr << endl;
    file << "//Fall Delay =" << df << endl;
    file << "//Clock Fall transition time =" << tf << endl;

    file << "1timescale 1ns/1ns" << endl;
    file<< "module Buffer_tree(clk, out);" << endl;
    file <<'\t'<< "parameter n= " << pow(2, levels_num) << ";"<< endl;
    file<<'\t' << "input clk;" << endl;
    file <<'\t'<< "output [n-1:0] out;" << endl;
    
    for (int i=0; i <  pow(2,levels_num+1)-1 ; i++)
    {
        file<<'\t' << "wire out_" << i << ";" << endl;
    }
    
    
    file<<'\t' << "CLKBUF" << branch[0].updated_size <<" buff_"<<0<<"(.A(clk)), .Y(out_"<<0<<"));"<<  endl;
    for (int i=1; i <  pow(2,levels_num+1)-1 ; i++)
    {
        file <<'\t'<< "CLKBUF" << branch[int(sqrt(i+1))].updated_size <<" buff_"<<i<<"(.A(out_"<<(i-1)/2<<"), .Y(out_"<<i<<"));"<<  endl;
    }
    
    
    for (int i=pow(2,levels_num+1); i >pow(2,levels_num); i--)
    {
        file<<'\t' << "assign out["<<  i-pow(2,levels_num)-1 << "] = out_" << i-2 << ";" << endl;
    }
    
    file << "end module" << endl;
}

/*
 8
 DFFPOSX1
 CLKBUF
 INVX
 */
