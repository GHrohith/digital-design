module prio_enc (
    input wire [3:0] d,
    output reg A,
    output reg B
);
    assign A = !d[3] && !d[2];
    assign B = (!d[3] && !d[1]) || (!d[3] && d[2]);
endmodule
