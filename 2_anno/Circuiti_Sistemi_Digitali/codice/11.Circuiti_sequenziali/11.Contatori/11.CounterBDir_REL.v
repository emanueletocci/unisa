// contatore biudirezionale a 8 bit sincronizzato sul fronte di salita del clock, con reset sincrono e abilitato dal segnale en

module count_udl(ck,reset,en,ud,load,d,cnt);
    input wire ck,reset,en,ud,load;
    input wire [7:0] d;
    output reg [7:0] cnt;

    always @(posedge ck) begin
        if (reset) cnt<=8'b00000000;    // reset has the highest priority
        else if (en) begin
            if (load) cnt<=d;
            else if (ud) cnt<=cnt + 1'b1;   //ud=1 - up counter, ud=0 - down counter
            else cnt<=cnt - 1'b1;
        end
    end
endmodule