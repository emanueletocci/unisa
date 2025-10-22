/*Si descriva in Verilog l'operazione di troncamento di un segnale in rappresentazione Q(4,4) 
al fine di ottenere un segnale in rappresentazione Q(4,0). Il cricuito ha in ingresso il segnale
Q ed in uscita il segnale Y. */

module trunc4 (Q,Y);
    input wire [8:0] Q;
    output wire [4:0] Y;

    assign Y = Q[8:4];
endmodule