// flip flop D con reset ed abilitazione attivo basso, sensibile sulla salita del clock

module ffRENasync (d,q,clk,en,r);
    input wire d,clk,en,r;
    output reg q;

    always @(posedge clk, negedge r) begin
        if (r==1'b0) q<=1'b0;   //reset attivo basso
        else if (en) q<=d;
    end
endmodule