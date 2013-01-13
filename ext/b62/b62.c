/*
 * b62.c
 * 
 * Original function by Jason Hullinger (2010)
 * Original ruby extension by Teng Siong Ong (2011)
 * Refactored by Adrià Planas (2013)
 * 
 */

#include <stdlib.h>
#include <ruby.h>

static const char b62_table[] = { "0123456789"
                                  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                  "abcdefghijklmnopqrstuvwxyz" };

static VALUE encode(VALUE self, VALUE arg)
{
  u_int64_t input = NUM2ULL(arg);
  char output[12];
  unsigned short i = 11;

  output[i] = '\0';

  do
  { 
    output[--i] = b62_table[input % 62]; 
  }
  while((input = input / 62) > 0);

  return rb_str_new2(&output[i]);
}

void Init_b62(void)
{
  VALUE klass = rb_define_class("B62", rb_cObject);
  rb_define_singleton_method(klass, "to_b62", encode, 1);
}