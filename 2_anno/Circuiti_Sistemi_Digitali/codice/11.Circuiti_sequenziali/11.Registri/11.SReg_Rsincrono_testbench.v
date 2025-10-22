`timescale 1ns/1ps
    module shift_reg_tb();
    // test bench. 8 bit shift register .
    localparam period=30;
    reg ck,dtb,r;
    wire [7:0] atb;
    11.sregRsync1_8 UUT(.din(dtb),.a(atb),.clk(ck) ,. reset(r) ) ;
    always begin
        ck=1'b0; #(period/2.0) ;
        ck=1'b1; #(period/2.0) ;
    end
    initial begin
        r=1'b1; dtb=1'b1; #period;
        r=1'b0; dtb=1'b1; #(period*8);
        dtb=1'b0; #(period*8); $stop;
    end
endmodule