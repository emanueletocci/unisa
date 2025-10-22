module massimo(A,B,Y);
	input wire [3:0] A,B;
	output reg [3:0] Y;
	
	always @(A,B) begin
		if (A>B) Y <= A;
		else Y <= B;
	end
endmodule