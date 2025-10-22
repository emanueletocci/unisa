`timescale 1ns/1ps
module tb_Glue_logic();
    reg [19:0] addr;
    wire [3:0] cs;
    wire cs_rom, cs_vr;
    Glue_logic UUT(.addr(addr),.cs_ram(cs),.cs_rom(cs_rom),.cs_vr(cs_vr));
    initial
    begin
        addr=20'h00000; #100; // ROM
        addr=20'h03FFF; #100; // ROM
        addr=20'h04000; #100; // RAM #1
        addr=20'h3FFFF; #100; // RAM #1
        addr=20'h40000; #100; // RAM #2
        addr=20'h7FFFF; #100; // RAM #2
        addr=20'h80000; #100; // RAM #3
        addr=20'hBFFFF; #100; // RAM #3
        addr=20'hC0000; #100; // RAM #4
        addr=20'hEFFFF; #100; // RAM #4
        addr=20'hF0000; #100; // VRAM
        addr=20'hFFFFF; #100; // VRAM
        $stop;
    end
endmodule