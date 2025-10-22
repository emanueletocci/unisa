module encoder8to3 (A,Y);
    input wire [7:0] A;
    output wire [2:0] Y;
    assign Y[2] = A[7] | A[6] | A[5] | A[4];
    assign Y[1] = A[7] | A[6] | A[3] | A[2];
    assign Y[0] = A[7] | A[5] | A[3] | A[1];
endmodule