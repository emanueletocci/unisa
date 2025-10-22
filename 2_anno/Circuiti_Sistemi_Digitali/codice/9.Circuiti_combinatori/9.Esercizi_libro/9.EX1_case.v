// LUT 5-1
// {m0,m5,m7 ,m9 ,m12 ,m13 ,m15 ,m16,m19,m20,m26 ,m31 } OFF set
/*
/*Si implementi la funzione combinatoria a 5 ingressi (A4, . . . , A0 ) e con uscita Y ad 1 bit il cui
OFF set è il seguente insieme di mintermini:
{m0,m5,m7 ,m9 ,m12 ,m13 ,m15 ,m16,m19,m20,m26 ,m31 }.
Si effettui sia un’implementazione che utilizza le funzioni booleane per definire l’uscita, sia
un’implementazione che utilizza il costrutto case. Si verifichi il funzionamento del circuito
mediante simulazione.
Il circuito può essere sperimentato con la scheda DE0, collegando gli ingressi a 4 interrut-
tori e un pulsante e l’uscita su uno dei LED.*/

module LUT51 (A,Y);
    input wire [4:0] A;
    output reg Y;

    always @(A) begin
        case(A)
            5'd0, 5'd5, 5'd7, 5'd9, 5'd12, 5'd13, 5'd15, 5'd16, 5'd19, 5'd20, 5'd26, 5'd31 : Y <= 1'b0;
            default: Y <= 1'b1;
        endcase
    end
endmodule