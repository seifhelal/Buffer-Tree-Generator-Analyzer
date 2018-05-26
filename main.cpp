//
//  main.cpp
//  mini_project
//
//  Created by SEIF on 4/15/18.
//  Copyright © 2018 SEIF. All rights reserved.
//
/*
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "liberty.h"
using namespace std;
liberty::Library liberty_lib;
string FlipFlop_type, buff_type;

float buff_capacitance(int size)
{
    return( liberty_lib.getCell(buff_type+to_string(size)).getPins()[0].getCapacitance());
}

struct buff{
    int level;
    float size;
    float updated_size;
    float delay[3];
    float transition[3];
    float stage_delay;
};
int main() {
    string path="/Users/air/Desktop/mini_project/mini_project/mini_project/osu035_stdcells.lib";
    liberty_lib=liberty::parse(path);
    double ff_num=0;
    float C_out, C_in, delay_per_stage;
    cout << "Please enter number of FlipFlops: " << endl;
    cin>>ff_num;
    cout << "Please enter type of FlipFlops: " << endl;
    cin>>FlipFlop_type;
    cout << "Please enter type of Buffer: " << endl;
    cin>>buff_type;
    int levels_num = log2(ff_num);
    if (pow(2, levels_num) < ff_num)
        levels_num+=1;
    C_out= liberty_lib.getCell(FlipFlop_type).getPins()[0].getCapacitance();
    C_in=buff_capacitance(1);
    delay_per_stage= pow(C_out/C_in*pow(2,levels_num),1/levels_num);
    cout << "delay  " << delay_per_stage << endl; 
    buff branch[levels_num];
    
    return 0;
}
*/
