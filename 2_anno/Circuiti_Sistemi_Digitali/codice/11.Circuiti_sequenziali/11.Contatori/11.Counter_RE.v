// contatore a 8 bit sincronizzato sul fronte di salita del clock, con reset sincrono e abilitato dal segnale en

module counter8RE (reset, clk, cnt, en);
    input wire reset, clk, en;
    output reg [7:0] cnt;
    always @(posedge clk) begin
      if (reset) cnt=8'h00;
      else if (en) cnt<=cnt+1'b1;
    end
endmodule