#include "_lemon_math.h"

// Ruby
#include <ruby.h>

// Lemon
#include <lemon/math.h>

static VALUE wrap_round(VALUE self, VALUE num) {
  return DBL2NUM( lemon::round( NUM2DBL(num) ) );
}

static VALUE wrap_isNan(VALUE self, VALUE num) {
  return lemon::isNaN( NUM2DBL(num) ) ? Qtrue : Qfalse ;
}

void register_math(VALUE rb_mlemon) {
   
   rb_define_const(rb_mlemon, "E", DBL2NUM(lemon::E));
   rb_define_const(rb_mlemon, "LOG2E", DBL2NUM(lemon::LOG2E));
   rb_define_const(rb_mlemon, "LOG10E", DBL2NUM(lemon::LOG10E));
   rb_define_const(rb_mlemon, "LN2", DBL2NUM(lemon::LN2));
   rb_define_const(rb_mlemon, "LN10", DBL2NUM(lemon::LN10));
   rb_define_const(rb_mlemon, "PI", DBL2NUM(lemon::PI));
   rb_define_const(rb_mlemon, "PI_2", DBL2NUM(lemon::PI_2));
   rb_define_const(rb_mlemon, "PI_4", DBL2NUM(lemon::PI_4));
   rb_define_const(rb_mlemon, "SQRT2", DBL2NUM(lemon::SQRT2));
   rb_define_const(rb_mlemon, "SQRT1_2", DBL2NUM(lemon::SQRT1_2));  

   rb_define_module_function(rb_mlemon, "round", RUBY_METHOD_FUNC(wrap_round), 1);
   rb_define_module_function(rb_mlemon, "is_nan", RUBY_METHOD_FUNC(wrap_isNan), 1);
}
