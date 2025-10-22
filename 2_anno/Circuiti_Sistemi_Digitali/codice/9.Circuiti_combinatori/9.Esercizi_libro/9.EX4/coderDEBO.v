module coderDEBO (b, Dig, Y, H);
	input wire [5:0] b;
	output wire H;
	output wire [3:0] Dig ;
	output reg [6:0] Y;
	reg [2:0] N;
	
	debo1digit DEBO(.A({1'b0, N}), .L(Y), .H(H), .Dig(Dig));
	always @(b) begin
		case(b)
			6'b000001 : N<=3'b001;
			6'b000010 : N<=3'b010;
			6'b000100 : N<=3'b011;
			6'b001000 : N<=3'b100;
			6'b010000 : N<=3'b101;
			6'b100000 : N<=3'b110;
			default: N<=3'b000;
		endcase
	end
endmodule