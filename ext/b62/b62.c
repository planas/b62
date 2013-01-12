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

int encode(u_int64_t input, char* ptr) 
{
  short i = 11;
  u_int64_t r = 0;

  ptr[i] = '\0';

  do
  { 
    i--;
    r = input % 62;
    input = (input - r) / 62;
    ptr[i] = b62_table[r];
  }while(input > 0);

  return i;
}

static VALUE encode62(VALUE self, VALUE arg)
{
  char output[12];
  
  return rb_str_new2(&output[encode(NUM2ULL(arg), output)]);
}

void Init_b62(void)
{
  VALUE klass = rb_define_class("B62", rb_cObject);
  rb_define_singleton_method(klass, "to_b62", encode62, 1);
}