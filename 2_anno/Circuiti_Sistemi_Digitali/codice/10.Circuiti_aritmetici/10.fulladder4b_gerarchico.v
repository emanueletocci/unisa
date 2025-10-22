//carry ripple full adder - gerarchico

// addizionatora a 1 bit
module fulladd (s, Cout, a, b, Cin);
    output wire s, Cout;
    input wire a, b, Cin;

    assign s = a ^ b ^ Cin;
    assign Cout = ( (a ^ b) & Cin ) | ( a & b );
endmodule

//addizionatore a 4 bit, ottenuto dall'interconnessione di 4 fulladder 1bit

module add_ger(A,B,S);
    output wire [3:0] S;
    input wire [3:0] A, B;
    wire [2:0] C;
    fulladd add_0(.s(S[0]), .Cout(C[0]), .a(A[0]), .b(B[0]), .Cin(1'b0));
    fulladd add_1(.s(S[1]), .Cout(C[1]), .a(A[1]), .b(B[1]), .Cin(C[0]));
    fulladd add_2(.s(S[2]), .Cout(C[2]), .a(A[2]), .b(B[2]), .Cin(C[1]));
    fulladd add_3(.s(S[3]), .a(A[3]), .b(B[3]), .Cin(C[2]));
endmodule