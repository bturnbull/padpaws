#include "padpaws.h"

#include <stdlib.h>
#include <string.h>

#define PP_ENCODE 0
#define PP_DECODE 1

void padpaws_init(pp_codec * codec, const char * out)
{
  char * in = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

  codec->len = strlen(in);
  if (codec->len > strlen(out)) { codec->len = strlen(out); }

  codec->in  = malloc(sizeof(char) * codec->len + 1);
  codec->out = malloc(sizeof(char) * codec->len + 1);
  
  strncpy(codec->in, in, codec->len);
  codec->in[codec->len] = '\0';
  strncpy(codec->out, out, codec->len);
  codec->out[codec->len] = '\0';
}

void padpaws_free(pp_codec * codec)
{
  free(codec->in);
  free(codec->out);
}

static char translate_char(const pp_codec * codec, int direction, char in_char)
{
  char out_char;
  char * in;
  char * out;
  int i;

  if (direction == PP_ENCODE) { in = codec->in; out = codec->out; }
  else { in = codec->out; out = codec->in; }
  
  for (i = 0 ; i < codec->len ; i++)
  {
    if (in[i] == in_char) { out_char = out[i]; return out[i]; } 
  }
  
  return '\0';
}

static int translate(const pp_codec * codec, int direction, char * buf)
{
  char character;
  int i;

  if (direction != PP_ENCODE && direction != PP_DECODE) { return PP_ERROR; }
  
  for (i = 0 ; i < strlen(buf) ; i++)
  {
    character = translate_char(codec, direction, buf[i]); 
    if (character != '\0') { buf[i] = character; } 
  }
  
  return PP_OK;
}

int padpaws_decode(const pp_codec * codec, char * buf)
{
  return translate(codec, PP_DECODE, buf);
}

int padpaws_encode(const pp_codec * codec, char * buf)
{
  return translate(codec, PP_ENCODE, buf);
}

