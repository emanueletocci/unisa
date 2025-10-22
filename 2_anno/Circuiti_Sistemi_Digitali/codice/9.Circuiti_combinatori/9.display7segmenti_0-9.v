// display a 7 segmenti in grado di visualizzare numeri hexa [0-F]
module BCD_decoder (A,Y);
    input wire [3:0] A; // 4 input bits
    output reg [6:0] Y; // Active low 7 segment display
    //Y0 is the top LED. Y1..Y5 proceed clockwise. Y6 is the middle LED.
    always @(A)
    begin
        case (A)
        4'b0000 : Y<=7'b1000000; //0
        4'b0001 : Y<=7'b1111001; //1
        4'b0010 : Y<=7'b0100100; //2
        4'b0011 : Y<=7'b0110000; //3
        4'b0100 : Y<=7'b0011001; //4
        4'b0101 : Y<=7'b0010010; //5
        4'b0110 : Y<=7'b0000010; //6
        4'b0111 : Y<=7'b1011000; //7
        4'b1000 : Y<=7'b0000000; //8
        4'b1001 : Y<=7'b0010000; //9
        default : Y<=7'bxxxxxxx; // don't care
        endcase
    end
endmodule