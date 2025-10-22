`timescale 1ns/1ps
module tb_count_udl();
    localparam period=30;
    reg ck,r,entb,udtb,loadtb;
    reg [7:0] dtb;
    wire [7:0] cnt_tb;

    count_udl UUT(.ck(ck),.en(entb),.reset(r),.cnt(cnt_tb) ,. d(dtb) ,. load(loadtb) ,. ud(udtb));
    always begin
        ck=1'b0; #(period/2.0) ;
        ck=1'b1; #(period/2.0) ;
    end
    initial begin
        r=1'b1;entb=1'b1; udtb=1'b1; loadtb=1'b0; dtb=8'b00000000; #period;
        r=1'b1;entb=1'b0; udtb=1'b1; loadtb=1'b0; dtb=8'b00000000; #period;
        r=1'b0;entb=1'b1; udtb=1'b1; loadtb=1'b0; dtb=8'b00000000; #(period*5);
        r=1'b0;entb=1'b0; udtb=1'b1; loadtb=1'b0; dtb=8'b00000000; #(period*2);
        r=1'b1;entb=1'b0; udtb=1'b1; loadtb=1'b0; dtb=8'b00000000; #period;
        r=1'b0;entb=1'b0; udtb=1'b1; loadtb=1'b0; dtb=8'b00000000; #period;
        entb=1'b1; udtb=1'b1; loadtb=1'b0; dtb=8'b00000000; #(period*5);
        entb=1'b1; udtb=1'b0; loadtb=1'b0; dtb=8'b00000000; #(period*4);
        entb=1'b1; udtb=1'b1; loadtb=1'b1; dtb=8'b00001111; #period;
        entb=1'b1; udtb=1'b1; loadtb=1'b0; dtb=8'b00000000; #(period*4);$stop;
    end
endmodule