#include "ruby.h"

#include "padpawslib.h"
#include "codec.h"

static VALUE codec_alloc(VALUE);
static VALUE codec_free(void *);
static VALUE codec_initialize(VALUE, VALUE);

static VALUE codec_alloc(VALUE klass)

{
  pp_codec * codec;
  VALUE obj;

  codec = malloc(sizeof(pp_codec));

  obj = Data_Wrap_Struct(klass, 0, codec_free, codec);

  return obj;
}

static VALUE codec_free(void * ptr)
{
  padpaws_free((pp_codec *)ptr);
  free(ptr);
}

static VALUE codec_initialize(VALUE self, VALUE pad)
{
  pp_codec * codec;

  Data_Get_Struct(self, pp_codec, codec);
  padpaws_init(codec, StringValuePtr(pad));

  return self;
}

VALUE cPadPawsCodec;  // PadPaws::Codec class

void Init_codec()
{
  cPadPawsCodec = rb_define_class_under(mPadPaws, "Codec", rb_cObject);
  rb_define_alloc_func(cPadPawsCodec, codec_alloc);

  rb_define_method(cPadPawsCodec, "initialize", codec_initialize, 1);
}
