/* Il circuito ha UN ingresso a 8bit "A" ed un ingresso ad 1 bit ¨B". L'uscita é "C".
Se B=1, C=(6,4,2,0)A altrimenti (7,5,3,1) */

module oddeven(A,B,C);
    input wire [7:0] A;
    input wire B;
    output wire [3:0] C;

    assign Y = B ? {A[6], A[4], A[2], A[0]} : {A[7], A[5], A[3], A[1]};
endmodule