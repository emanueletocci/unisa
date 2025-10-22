module LUT4_2 (A,Y);
    input wire [3:0] A;
    output reg [1:0] Y;
    always @(A) begin
        casex(A)
            4'd0, 4'd3, 4'd12, 4'd13, 4'd15 : Y <= 2'b00;
            4'd1, 4'd5, 4'd11, 4'd14 : Y <= 2'b01;
            4'd6, 4'd7, 4'd8 : Y <= 2'b10;
            4'd2 : Y <= 2'b11;
            default : Y <= 2'bxx;
        endcase
    end
endmodule
