/*
Si descriva in Verilog l'operazione di arrotondamento di un segnale in rappresentazione Q(4,4) al fine di ottenere un 
segnale in rappresentazione Q(4,0). Il circuito che effettua l'operazione sia denominato round4 ed abbia come ingresso 
il segnale Q e come uscita il segnale Y.
*/

module round4(Q,Y);
    input wire [7:0] Q;
    output wire [3:0] Y;
    wire [3:0] tmp;
    localparam [7:0] RoundCons = 8'b0000_1000;

    assign tmp=Q+RoundCons;
    assign Y=tmp[7:3];
endmodule