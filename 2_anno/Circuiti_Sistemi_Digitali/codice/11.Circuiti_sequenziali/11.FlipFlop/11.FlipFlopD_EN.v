// flip flop D con abilitazione, sensibile al fronte di salita

module ffEN (d,q,clk,en);
    input wire d, clk, en;
    output reg q;

    always @(posedge clk) begin
        if (en) q<=d;
    end
endmodule