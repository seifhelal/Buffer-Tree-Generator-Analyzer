//Rise Delay =1.24339
//Clock Rise Transition Time =0.048357
//Fall Delay =1.26465
//Clock Fall transition time =0.0459664
1timescale 1ns/1ns
module Buffer_tree(clk, out);
	parameter n= 8;
	input clk;
	output [n-1:0] out;
	wire out_0;
	wire out_1;
	wire out_2;
	wire out_3;
	wire out_4;
	wire out_5;
	wire out_6;
	wire out_7;
	wire out_8;
	wire out_9;
	wire out_10;
	wire out_11;
	wire out_12;
	wire out_13;
	wire out_14;
	CLKBUF1 buff_0(.A(clk)), .Y(out_0));
	CLKBUF3 buff_1(.A(out_0), .Y(out_1));
	CLKBUF3 buff_2(.A(out_0), .Y(out_2));
	CLKBUF2 buff_3(.A(out_1), .Y(out_3));
	CLKBUF2 buff_4(.A(out_1), .Y(out_4));
	CLKBUF2 buff_5(.A(out_2), .Y(out_5));
	CLKBUF2 buff_6(.A(out_2), .Y(out_6));
	CLKBUF2 buff_7(.A(out_3), .Y(out_7));
	CLKBUF2 buff_8(.A(out_3), .Y(out_8));
	CLKBUF2 buff_9(.A(out_4), .Y(out_9));
	CLKBUF2 buff_10(.A(out_4), .Y(out_10));
	CLKBUF2 buff_11(.A(out_5), .Y(out_11));
	CLKBUF2 buff_12(.A(out_5), .Y(out_12));
	CLKBUF2 buff_13(.A(out_6), .Y(out_13));
	CLKBUF2 buff_14(.A(out_6), .Y(out_14));
	assign out[7] = out_14;
	assign out[6] = out_13;
	assign out[5] = out_12;
	assign out[4] = out_11;
	assign out[3] = out_10;
	assign out[2] = out_9;
	assign out[1] = out_8;
	assign out[0] = out_7;
end module
