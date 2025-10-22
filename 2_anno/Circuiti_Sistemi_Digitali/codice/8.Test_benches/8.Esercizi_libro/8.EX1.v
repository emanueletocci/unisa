/*
Es. 2 – Test bench combinatorio
Esercizio Cap. 8, par. 8.5, E1, pag. 129 [1]
Si testi un circuito denominato ‘rael’ con port di ingresso ‘ontiveros’ a 8 bit e ‘rami’ a 2 bit, e uscita ‘Y’ a 32
bit. I segnali da usare nel test bench sono A, B e C, da collegare a port a scelta. La sequenza di ingresso
testa il circuito con rami = 002 e facendo variare ontiveros da 0 a 10 (base 10) ogni 10 ns. In seguito si attendono 5
ns e si imposta rami = 102 e si fa variare ontiveros da 11 a 20 (base 10) ogni 5 ns

A - onteveros
B - rami
C - Y
*/

`timescale 1ns/1ps
module tb_rael();
    reg [7:0] A;
    reg [1:0] B;
    wire [31:0] C;

    rael UUT(.ontiveros(A), .rami(B), .Y(C));
    intial begin    //initial: costrutto procedurale non sintetizzabile da usare solo nei tb
        B = 2'b00; A = 8'd0;   #10;
        B = 2'b00; A = 8'd1;   #10;
        B = 2'b00; A = 8'd2;   #10;
        B = 2'b00; A = 8'd3;   #10;
        B = 2'b00; A = 8'd4;   #10;
        B = 2'b00; A = 8'd5;   #10;
        B = 2'b00; A = 8'd6;   #10;
        B = 2'b00; A = 8'd7;   #10;
        B = 2'b00; A = 8'd8;   #10;
        B = 2'b00; A = 8'd9;   #10;
        B = 2'b00; A = 8'd10;   #5;
        B = 2'b10; A = 8'd11;   #5;
        B = 2'b10; A = 8'd12;   #5;
        B = 2'b10; A = 8'd13;   #5;
        B = 2'b10; A = 8'd14;   #5;
        B = 2'b10; A = 8'd15;   #5;
        B = 2'b10; A = 8'd16;   #5;
        B = 2'b10; A = 8'd17;   #5;
        B = 2'b10; A = 8'd18;   #5;
        B = 2'b10; A = 8'd19;   #5;
        B = 2'b10; A = 8'd20;   #5;
        $stop;
    end
endmodule