/*
Si descriva un registro a scorrimento con ingresso a 8 bit denominato 'A' e uscita a 8 bit denominata 'B'.
Il registro a scorrimento è composto da 4 elementi di memoria e l'uscita B è connessa all'ultimo elemento di memoria.
In pratica il registro a scorrimento riporta sull'uscita B quanto arriva sull'ingresso A ma ritardato di 4 colpi di clock.

Il circuito è denominato 'myAnswer', ha reset asincrono (NON sincrono), ed è sincronizzato sul fronte di salita del segnale di clock.
Il segnale di reset è denominato 'reset' mentre il segnale di clock è denominato 'clk'.
*/

module sreg8_8 (A,B, clk);
    input wire [7:0] A;
    input wire clk, reset;
    output reg [7:0] B; // The array is composed of Num_reg elements. Each element is composed by 'Width' bit. reg [Width−1:0] mem [Num_reg−1:0]; 
    reg [7:0] D [3:0];
    integer k;

    always @(posedge clk) begin
        if (reset) 
            for (k=0; k<4; k=k+1) D[k]<=8'h00;
        else begin
            for(k=3; k>0; k=k-1) D[k]<=D[k-1];
            D[0]<=A;
        end
    end
    assign Y=D[3];
endmodule
