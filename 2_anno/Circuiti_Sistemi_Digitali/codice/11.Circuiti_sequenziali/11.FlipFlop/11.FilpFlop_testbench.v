// test bench per un flip flop con reset attivo basso e segnale di enable attivo alto. 
`timescale 1ns/1ps
module tb_mydff();
    wire Qtb;
    reg CLKtb, Dtb, CLRtb, ENtb;
    mydff UUT(.d(Dtb),.clk(CLKtb),aClrn(CLRtb),.en(ENtb),.q(Qtb));
    
    // Generates the clock waveform
    localparam period=20; // Clock period is 20 ns
    always begin     // Repeat forever the following cycle
        CLKtb=1'b0;
        #(period/2.0) ; // 2.0 is needed to obtain a real number
        CLKtb=1'b1;
        #(period/2.0) ;
    end
    
    // Defines the remaining input waveforms. Apply these test vectors once at the beginning of the simulation

    initial begin
        CLRtb=1'b0; // Start with a reset
        ENtb=1'b1; Dtb=1'b1; // Assign every input. Do not simulate with unspecified signals.
        #(3.75*period);

        // Delay 3+3/4 clock periods
        CLRtb=1'b1;

        // Disable the reset signal
        ENtb=1'b1; Dtb=1'b1; // Also not changing inputs are assigned to improve readability
        #period;
        
        // Wait one clock period
        ENtb=1'b1; Dtb=1'b0; // Apply inputs. Reset inputs are constant. No need to repeat them
        #period;
        ENtb=1'b1; Dtb=1'b1;#period;
        ENtb=1'b0; Dtb=1'b0; #period; // Disabled
        ENtb=1'b0; Dtb=1'b1; #period; // Disabled
        $stop; // End of simulation
    end
endmodule