`timescale 1ns/1ps // Defines time unit and time resolution for the simulation
    module tb_prenc83(); // Module with no inputs nor outputs
    reg [7:0] Atb; // Reg net type. To be assigned in the initial block
    wire [2:0] Ytb; // Wire net types used for the UUT output signals
    wire Idletb;

    prenc8to3withifelse UUT(.A(Atb), .Y(Ytb), .Idle(Idletb)); // Circuit under test named UUT 8
    /*    
            <module name> <instance name>(<interface ports>)

        *   <module name> : nome modulo da testare
        *   <module name> : nome che identifica il componente nel testbench
        *   <interface ports> : ports  
    */
    initial // il blocco viene eseguito 1 sola volta
    begin
        Atb = 8'h01;
        #100;       // ritardo temporale composto da n=100 intervalli di tempo unitari (1ns)
        Atb = 8'h02; #100;
        Atb = 8'h04; #100;
        Atb = 8'h08; #100;
        Atb = 8'h10; #100;
        Atb = 8'h20; #100;
        Atb = 8'h40; #100;
        Atb = 8'h80; #100;
        Atb = 8'h44; #100;
        Atb = 8'hF0; #100;
        Atb = 8'h00; #100;
        Atb = 8'hCF; #100;
        $stop; // System call that stops the simulation
    end
endmodule