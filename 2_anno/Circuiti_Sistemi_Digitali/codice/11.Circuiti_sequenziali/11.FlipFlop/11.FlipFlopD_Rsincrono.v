// flip flop D con segnale di reset sincrono e sensibilitá sul fronte attivo

module ffRsync (d,q,clk,r);
    input wire d, clk, r;
    output reg q;

    always @(posedge clk) begin
        if (r) q<=1'b0;
        else q<=d;
    end
endmodule