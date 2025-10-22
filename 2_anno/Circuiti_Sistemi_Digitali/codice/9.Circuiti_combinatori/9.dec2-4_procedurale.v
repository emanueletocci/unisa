//decoder 2-4 procedurale

module dec2to4(D,Y);
    input wire [1:0] D; // declaration section
    output reg [3:0] Y;
    // description section
    always @(D)
    begin
        case (D)
            2'd0 : Y<=4'b0001; // Y[0]
            2'd1 : Y<=4'b0010; // Y[1]
            2'd2 : Y<=4'b0100; // Y[2]
            2'd3 : Y<=4'b1000; // Y[3]
            default : Y<=4'b0000;
        endcase
    end
endmodule