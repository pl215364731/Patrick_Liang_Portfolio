module manip( 
    input logic [7:0] in, 
    output logic [1:0] out, 
    output int result);

always_comb begin
    if(in[0]) begin
        out = 0;
        result = 0;
    end
    else if(in && !(in & (in-1))) begin
        out = 1;
        for(int i = 0; i < 8; i++) begin
            if(in[i]) begin
                result = i;
            end
        end
    end
    else if(in[7:3]) begin
        out = 2;
        result = in[1:0];
    end
    else begin
        out = 3;
        result = 0;
    end
end



endmodule