// Reset sincrono attivo alto, circuito attivo ad abilitazione (en) alta e sensibile sulla salita del clock

module FFToggle (ck,en,r,led);
    input wire ck, en, r;
    output reg led;

    always @(posedge ck) begin
        if (r)
            led<=1'b0;
        else if (en) 
            led<=~led;
    end
endmodule