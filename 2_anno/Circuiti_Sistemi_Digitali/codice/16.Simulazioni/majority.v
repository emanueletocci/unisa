/* circuito con un ingresso A a 3bit e uscita Y ad 1 bit.
Y=1 se la maggioranza dei bit di A é 1 altrimenti é 0.
Piú semplicemente, l'uscita Y é 1 solo se due o tre bit di A sono 1. */

module majority(A,Y);
    input wire [2:0] A;
    output reg Y;

    always @(A) begin
        case(A)
            3'b011 : Y <= 1;
            3'b110 : Y <= 1;
            3'b101 : Y <= 1;
            3'b111 : Y <= 1;
            default : Y <= 0;
        endcase
    end
endmodule