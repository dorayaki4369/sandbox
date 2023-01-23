module clock_gen(clock, oclock);
	parameter scale = 100; //oclock = clock(1kHz) / scale
	input  clock;
	output oclock;
	
	reg  [15:0] cnt;
	wire iclk;
	
	assign oclock = (cnt == (scale - 1)) ? 1'b1 : 1'b0;
	always @(posedge clock) begin
		cnt = (cnt == (scale - 1)) ? 0 : cnt + 1;
endmodule
