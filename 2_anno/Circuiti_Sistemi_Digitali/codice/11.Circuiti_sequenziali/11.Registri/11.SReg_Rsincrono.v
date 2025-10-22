// registro a scorrimento con ingresso ad 1 bit, uscita ad 8 bit e reset sincrono attivo alto

module sregRsync1_8 (d,clk,r,q);
    input wire d,clk,r;
    output reg [7:0] q;

    always @(clk) begin
        if (r) q<=8'b00000000;
        else begin
            q[6:0]<=q[7:1];
            q[7]<=d;
        end
    end
endmodule   