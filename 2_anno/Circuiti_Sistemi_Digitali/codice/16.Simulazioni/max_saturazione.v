/*GPT

Si descriva in HDL Verilog un circuito combinatorio con due segnali di ingresso a 8 bit denominati 'A' e 'B' e un 
segnale a 8 bit di uscita denominato 'Y'. L'uscita è uguale al massimo tra A e B visti come numeri senza segno in 
rappresentazione U(7,0) ma è saturata al valore di 200. Quindi se uno dei due segnali è maggiore di 200 l'uscita deve 
essere pari a 200. Il nome del circuito è 'myAnswer'.*/

module max_sat(A,B,Y);
    input wire [7:0]A,B;
    output reg [7:0]Y;

    always @(A,B) begin
      if (A>8'd200 || B>8'd200) Y<=8'd200;
      else if (A>B) Y<=A;
      else Y<=B;
    end
endmodule