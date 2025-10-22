`timescale 1ns/1ps
module tb_massimo();
	reg [3:0] Atb,Btb;
	wire [3:0] Ytb;
	massimo UUT(.A(Atb), .B(Btb), .Y(Ytb));
	initial begin
		Atb = 4'b0000; Btb = 4'b0000;	#10	//#x introduce un ritardo temporale necessario a far eseurire i transitori
		Atb = 4'b0111; Btb = 4'b0000;	#10
		Atb = 4'b0000; Btb = 4'b0110;	#10
		Atb = 4'b1111; Btb = 4'b1110;	#10
		$stop;
	end
endmodule