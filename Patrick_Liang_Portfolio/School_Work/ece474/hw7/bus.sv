class bus;
    rand bit [15:0] a_in;
    rand bit [15:0] b_in;

    constraint a_constraint { a_in <= 500; }
    constraint b_constraint { b_in > 0; }
    constraint sum_constraint { a_in + b_in == 500; }
endclass