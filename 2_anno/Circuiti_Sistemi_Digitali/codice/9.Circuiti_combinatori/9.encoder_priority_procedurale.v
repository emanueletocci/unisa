//encoder priority procedurale
module prenc8to3withifelse (A,Y,Idle);
    output reg [2:0] Y;
    // Assigned in a procedural block => reg type
    output wire Idle;
    input wire [7:0] A;

    assign Idle = ~(|A); 
    always @(A) // Procedural block. Activated whenever A experiences an event. Sensitivity list 
    begin 
        if (A[7] == 1'b1) Y <= 4'd7; // If statement. Guarantees priority to the inputs
        else if (A[6] == 1'b1) Y <= 4'd6;
        else if (A[5] == 1'b1) Y <= 4'd5;
        else if (A[4] == 1'b1) Y <= 4'd4;
        else if (A[3] == 1'b1) Y <= 4'd3;
        else if (A[2] == 1'b1) Y <= 4'd2;
        else if (A[1] == 1'b1) Y <= 4'd1;
        else Y <= 4'd0;  // Manages all the remaining cases
    end
endmodule