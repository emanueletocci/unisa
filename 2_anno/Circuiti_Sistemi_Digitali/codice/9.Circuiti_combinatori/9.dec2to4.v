module decoder2to4(A1,A0,Y3,Y2,Y1,Y0); //descrive la funzione o la struttura del circuito e le porte di collegamento

//dichiarazioni
input A1,A0;    // si definiscono gli input
output Y3,Y2,Y1,Y0; // si definiscono gli output
wire A1,A0,Y3,Y2,Y1,Y0; // si definiscono i collegamenti interni

assign Y0 = (~A1) & (~A0);
// costrutti
assign Y1 = (~A1) & (A0);
assign Y2 = (A1) & (~A0);
assign Y3 = (A1) & (A0);
endmodule

/*Verilog e' case sensitive!*/

/*  SEGNALI VETTORIALI

module decoder2to4 (A,Y);
input [1:0] A; // Ingresso vettoriale a 2 bit
output [3:0] Y; // Uscita vettoriale a 4 bit
wire [1:0] A;
 // Il segnale A è un wire a 2 bit
 wire [3:0] Y;
 // Il segnale Y è un wire a 4 bit
assign Y[0] = (∼A[1])&(∼A[0]);
assign Y[1] = (∼A[1])&( A[0]);
assign Y[2] = ( A[1])&(∼A[0]);
assign Y[3] = ( A[1])&( A[0]);
endmodule

*/