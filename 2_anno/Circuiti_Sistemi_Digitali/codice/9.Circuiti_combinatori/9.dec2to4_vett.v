//decoder 2-4 vettoriale
module decoder2to4 (A,Y);

    input [1:0] A; // Ingresso vettoriale a 2 bit
    output [3:0] Y; // Uscita vettoriale a 4 bit
    wire [1:0] A; // Il segnale A è un wire a 2 bit
    wire [3:0] Y; // Il segnale Y è un wire a 4 bit

    assign Y[0] = (~A[1]) & (~A[0]);
    assign Y[1] = (~A[1]) & (A[0]);
    assign Y[2] = (A[1]) & (~A[0]);
    assign Y[3] = (A[1]) & (A[0]);

endmodule
