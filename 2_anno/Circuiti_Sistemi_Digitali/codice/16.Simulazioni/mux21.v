/* Si riporti la descrizione in Verilog di un mux con 2 ingressi da 8 bit (ln1 e ln2) ed uscita 8 bit (Art)
Il segnale di selezione A porta in uscita ln1 se A=1. */

module mux21(ln1, ln2, Art);
    input wire [7:0] ln1, ln2;
    input wire A;
    output wire [7:0] Art;

    assign Art = A ? ln1 : ln2;     //se A=1, Art=ln1 altrimenti Art=ln2
endmodule

/* In alternativa:
module mux21(ln1, ln2, Art);
    input wire [7:0] ln1, ln2;
    input wire A;
    output reg [7:0] Art;

    always @(ln1, ln2) begin
        if (A == 1 ) Art <= ln1;
        else Art <= ln2;
    end
endmodule
*/