module Glue_logic(addr,cs_ram,cs_rom,cs_vr);
    input wire [19:0] addr;
    output wire [3:0] cs_ram; output wire cs_rom, cs_vr;
    wire ram; 
    wire [3:0] cs_int; // Internal nodes

    // constant addresses defining address space for ROM and VRAM
    localparam [19:0] ROMaddr=20'h04000, VRaddr=20'hf0000;
    assign cs_rom = (addr < ROMaddr); // bit signaling the access to the ROM
    assign cs_vr = (addr >= VRaddr); // bit signaling the access to the VRAM
    assign ram = (~cs_rom)&(~cs_vr); // logical condition to access the RAM

    // 2 to 4 decoder for 4 RAM chips
    assign cs_int[0] = (addr[19:18]==2'b00);
    assign cs_int[1] = (addr[19:18]==2'b01);
    assign cs_int[2] = (addr[19:18]==2'b10);
    assign cs_int[3] = (addr[19:18]==2'b11);
    assign cs_ram = (ram) ? cs_int : 4'b0000; // the mu
endmodule