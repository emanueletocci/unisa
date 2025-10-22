// flip flop sensibile al fronte di salita con segnali di preset, reset e abilitazione (attivo basso)

module ffPRENasync (d,q,clk,reset,preset,en);
    input wire d,clk,reset,preset,en;       //preset = positive reset
    output reg q;

    always @(posedge clk, negedge reset, negedge preset) begin
        if (reset==1'b0) q<=1'b0;
        else if (preset==1'b0) q<=1'b0;
        else if (en) q<=d;
    end
endmodule