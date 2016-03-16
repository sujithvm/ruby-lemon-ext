#include "_lemon.h"

void register_lemon(){
    static VALUE rb_mlemon = rb_define_module("Lemon");

    register_math(rb_mlemon);
    register_list_graph(rb_mlemon);

}
