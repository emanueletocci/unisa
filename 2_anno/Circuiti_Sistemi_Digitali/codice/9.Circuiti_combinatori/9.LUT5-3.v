module LUT5_3(A,Y);
    input wire [4:0] A;
    output reg [2:0] Y;

    always @(A) begin
        case(A)
            5'd1: Y<=3'b010;
            5'd2: Y<=3'b100;
            //..
            //.
            5'd31: Y<=3'b110;
            default : Y<=3'b000;
        endcase
    end
endmodule