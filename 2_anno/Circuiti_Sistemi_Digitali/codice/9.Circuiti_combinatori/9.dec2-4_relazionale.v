// decoder 2-4 relazionale
module dec2to4(A,Y);
    input wire [1:0] A; // declaration section
    output wire [3:0] Y;
    // description section
    assign Y[0] = ((A) == (2'b00));
    assign Y[1] = ((A) == (2'b01));
    assign Y[2] = ((A) == (2'b10));
    assign Y[3] = ((A) == (2'b11));
endmodule
