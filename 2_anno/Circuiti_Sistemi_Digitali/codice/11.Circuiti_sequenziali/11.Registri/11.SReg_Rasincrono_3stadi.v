// registro a scorrimento a 3 stadi con reset asincrono - si realizza mettendo in cascata 3 registri a scorrimento. Implementazione sconsigliata in quanto poco leggibile, meglio usare cicli for e segnali bidimensionali

module shiftreg8b3tap(ck,reset,Din,Dout);
    input wire ck,reset; 
    input wire [7:0] Din;
    output wire [7:0] Dout;
    reg [7:0] D0, D1, D2; // Nodes for the 3 registers . Each register contains 8 bit

    always @(posedge ck, posedge reset) begin // register #1
        if (reset) D0<=8'h00;
        else D0<=Din;
    end

    always @(posedge ck, posedge reset) begin // register #2
        if (reset) D1<=8'h00;
        else D1<=D0;
    end

    always @(posedge ck, posedge reset) begin //register #3
        if (reset) D2<=8'h00;
        else D2<=D1;
    end

    assign Dout = D2;
endmodule