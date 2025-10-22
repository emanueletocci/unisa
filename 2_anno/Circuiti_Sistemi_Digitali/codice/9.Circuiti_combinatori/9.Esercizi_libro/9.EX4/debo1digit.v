// led accesi a stato basso, encoder
//encoder 1 digit

module debo1digit (A,L,H,Dig);
	input wire [3:0] A;	//considero 4bit in ingresson in quanto 1 display puo' mostrare max 16 cifra (24))
	output wire H;
	output wire [3:0] Dig;
	output reg [6:0] L;
	
	assign Dig = 4'b1110; //accesa solo l'ultima cifra
	assign H = 1'b1; //punto decimale spento
	
	always @(A) begin
		case(A)
        4'd0 : L<=7'b1000000; //0
        4'd1 : L<=7'b1111001; //1
        4'd2 : L<=7'b0100100; //2
        4'd3 : L<=7'b0110000; //3
        4'd4 : L<=7'b0011001; //4
        4'd5 : L<=7'b0010010; //5
        4'd6 : L<=7'b0000010; //6
        4'd7 : L<=7'b1011000; //7
        4'd8 : L<=7'b0000000; //8
        4'd9 : L<=7'b0010000; //9
        4'd10 : L<=7'b0001000; //A
        4'd11 : L<=7'b0000011; //B
        4'd12 : L<=7'b1000110; //C
        4'd13 : L<=7'b0100001; //D
        4'd14 : L<=7'b0000110; //E
        4'd15 : L<=7'b0001110; //F
        default : L<=7'b1111111; //OFF
		endcase
	end
endmodule