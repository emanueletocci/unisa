// flip flop D con reset asincrono, sensibile sul fronte di salita

module ffRasync(d,q,clk,r);
    input wire d,clk,r;
    output reg q;

    always @(posedge clk, posedge r) begin
        if (r) q<=1'b0;
        else q<=d;
    end 
endmodule