// MUX 2-1 CONDIZIONALE
module Mux2(D,Sel,Y);
    input wire [1:0] D;
    input wire Sel;
    output wire Y;
    assign Y = Sel ? D[1] : D[0];
endmodule