//encoder binario 8-3 con blocco procedurale/ L'encoder prende in input n bit (2^n) e restituisce in output log_2(n) bit (n)
module enc8_3proc (A,Y);
    input wire [7:0] A;
    output reg [2:0] Y;

    always @(A) begin
        case(A)
            8'b10000000 : Y<=3'd7;
            8'b01000000 : Y<=3'd6;
            8'b00100000 : Y<=3'd5;
            8'b00010000 : Y<=3'd4;
            8'b00001000 : Y<=3'd3;
            8'b00000100 : Y<=3'd2;
            8'b00000010 : Y<=3'd1;
            8'b00000001 : Y<=3'd0;
            default: Y<=3'bxxx;
        endcase
    end
endmodule