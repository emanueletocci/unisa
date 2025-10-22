//tabella di verita con ingresso a 5 bit ed uscita a 1 bit

module LUT5_1 (A,Y);
    input wire [4:0] A;
    output reg Y;

    always @(A) begin
      case(A)
        5'd1,5'd2,5'd4,5'd7,5'd8,5'd11,5'd13,5'd14,5'd16,5'd19,5'd21,5'd25,5'd26,5'd28,5'd31 : Y<=1'b1;
        default : Y<=1'b0;
      endcase
    end
endmodule