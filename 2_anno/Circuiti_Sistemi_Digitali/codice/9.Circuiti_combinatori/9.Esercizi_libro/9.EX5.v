/*Es. 3 – Codificatore con priorità
Esercizio Cap. 9, par. 9.10, E5, pag. 155 [1]
Si realizzi un codificatore binario con priorità. L’ingresso del circuito è costituito da 6 bit (b[5:0]). In uscita si
visualizza sul display a 7 segmenti della scheda DEBO la cifra ‘0’ se è alto il primo bit b0, la cifra ‘1’ se è alto
il secondo bit b1, la cifra ‘2’ se è alto b2, e via di seguito.

Se sono alti due o più bit di ingresso, si dovrà rappresentare in uscita il numero corrispondente al bit con
priorità più alta. Si assuma che il bit con maggiore priorità sia b5, mentre quello con minore priorità sia b0.
Nel caso in cui tutti gli ingressi siano bassi, tutti i segmenti del display dovranno essere spenti.*/

module pencoder(b, Y);
    input wire [5:0] b;
    output wire idle;
    output reg [6:0] Y;
    output wire [3:0] Dig;

    assign Dig = 4'b0001;
    assign idle = 1'b0;

    always @(b) begin
        casex(b)
            6'b000001 : Y <= 7'b0111111;    //0
            6'b00001x : Y <= 7'b0000110;    //1
            6'b0001xx : Y <= 7'b1011011;    //2
            6'b001xxx : Y <= 7'b1001111;    //3
            6'b01xxxx : Y <= 7'b0100110;    //4
            6'b01xxxx : Y <= 7'b1101101;    //4
            6'b1xxxxx : Y <= 7'b1101101;    //4
            default : Y <= 7'b0000000;      //off
        endcase
    end
endmodule