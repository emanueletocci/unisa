module latch (d,q,clk);
    input wire d,clk;
    output reg q;

    always @(posedge clk, d) begin   //si inserisce anche d in quanto il latch modifica l'uscita NON solo in corrispondenza dei fronti del clock
        if (clk) q<=d;
    end
endmodule