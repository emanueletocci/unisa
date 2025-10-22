// flip-flop-d senza reset,preset ed enable

module df(d,q,clk); // Module definition
    input wire d,clk;
    output reg q; // Assigned in a procedural block => reg type
    always @(posedge clk) // Procedural block. Activated by the positive edge of the clock. posedge restituisce vero quando il segnale ha una transizione 0->1
        begin
        q <=d;
    end
endmodule

