// registro (flip flop ad ingresso vettoriale) 8b, sensibile al fronte di discesa, reset sincrono attivo alto

module reg8Rsync(d,q,r,clk); 
    input wire [7:0] d;
    input wire r,clk;
    output reg [7:0] q;

    always @(posedge clk) begin
        if(r) q<=8'b00000000;
        else q<=d;
    end
endmodule