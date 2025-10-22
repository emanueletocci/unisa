// MUX9-5 con case
module mux_9_5(D8, D7, D6, D5, D4, D3, D2, D1, D0, Sel, Y);
    input wire [4:0] D8, D7, D6, D5, D4, D3, D2, D1, D0;
    input wire [3:0] Sel;
    output reg [4:0] Y;
    always @(Sel, D8, D7, D6, D5, D4, D3, D2, D1, D0)
        begin
            case (Sel)
            4'h0 : Y<=D0;
            4'h1 : Y<=D1;
            4'h2 : Y<=D2;
            4'h3 : Y<=D3;
            4'h4 : Y<=D4;
            4'h5 : Y<=D5;
            4'h6 : Y<=D6;
            4'h7 : Y<=D7;
            4'h8 : Y<=D8;
            default: Y<=5'b00000;
            endcase
        end // always
endmodule