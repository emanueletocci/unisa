// registro a scorrimento a 8 stadi con reset asincrono, implementato con for e segnali bidimensionali 

module shiftreg16b8tap(ck,reset,Din,Dout);
    input wire ck,reset; 
    input wire [15:0] Din;
    output wire [15:0] Dout;
    reg [15:0] D [7:0]; // flip flop array
    integer k; // integer variable used in the FOR loop.

    always @(posedge ck, posedge reset) begin
        if (reset)
            for (k=0; k<8 ; k=k+1) D[k] <= 16'h0000;
        else begin
            for (k=7; k>0 ; k=k-1) D[k]<=D[k-1];
            D[0]<=Din;
        end
    end
    assign Dout=D[7];
endmodule