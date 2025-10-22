// Copyright (C) 2023  Intel Corporation. All rights reserved.
// Your use of Intel Corporation's design tools, logic functions 
// and other software and tools, and any partner logic 
// functions, and any output files from any of the foregoing 
// (including device programming or simulation files), and any 
// associated documentation or information are expressly subject 
// to the terms and conditions of the Intel Program License 
// Subscription Agreement, the Intel Quartus Prime License Agreement,
// the Intel FPGA IP License Agreement, or other applicable license
// agreement, including, without limitation, that your use is for
// the sole purpose of programming logic devices manufactured by
// Intel and sold by Intel or its authorized distributors.  Please
// refer to the applicable agreement for further details, at
// https://fpgasoftware.intel.com/eula.

// PROGRAM		"Quartus Prime"
// VERSION		"Version 23.1std.0 Build 991 11/28/2023 SC Lite Edition"
// CREATED		"Fri Jul 19 18:59:48 2024"

module decoder(
	A1,
	A0,
	Y0,
	Y1,
	Y2,
	Y3
);


input wire	A1;
input wire	A0;
output wire	Y0;
output wire	Y1;
output wire	Y2;
output wire	Y3;

wire	SYNTHESIZED_WIRE_4;
wire	SYNTHESIZED_WIRE_5;




assign	Y0 = SYNTHESIZED_WIRE_4 & SYNTHESIZED_WIRE_5;

assign	Y1 = A0 & SYNTHESIZED_WIRE_5;

assign	Y2 = SYNTHESIZED_WIRE_4 & A1;

assign	Y3 = A0 & A1;

assign	SYNTHESIZED_WIRE_4 =  ~A0;

assign	SYNTHESIZED_WIRE_5 =  ~A1;


endmodule
