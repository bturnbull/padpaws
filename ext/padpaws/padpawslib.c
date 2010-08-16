#include "ruby.h"

#include "padpawslib.h"
#include "codec.h"

static VALUE padpawslib_encode(VALUE self, VALUE codec, VALUE string)
{
  pp_codec * ppCodec;

  Data_Get_Struct(codec, pp_codec, ppCodec);
  padpaws_encode(ppCodec, StringValuePtr(string));

  return string;
}

static VALUE padpawslib_decode(VALUE self, VALUE codec, VALUE string)
{
  pp_codec * ppCodec;

  Data_Get_Struct(codec, pp_codec, ppCodec);
  padpaws_decode(ppCodec, StringValuePtr(string));

  return string;
}

VALUE mPadPaws;  // PadPawsLib module

void Init_padpawslib()
{
  mPadPaws = rb_define_module("PadPawsLib");
  Init_codec();

  rb_define_module_function(mPadPaws, "encode", padpawslib_encode, 2);
  rb_define_module_function(mPadPaws, "decode", padpawslib_decode, 2);
}


