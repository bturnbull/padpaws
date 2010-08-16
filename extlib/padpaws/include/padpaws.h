#include <sys/types.h>

#ifndef __PADPAWS_H__
#define __PADPAWS_H__

typedef struct {
  char * in;
  char * out;
  size_t len;
} pp_codec; 

#define PP_OK    0
#define PP_ERROR 1

#ifdef __cplusplus
extern "C" {
#endif

  // Initialize the translation codec with a 52 char buffer
  // mapping to:
  //
  //  ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 
  //
  // For example, to implement ROT13:
  //
  //  padpaws_init(codec,
  //               "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm");
  //
  extern void padpaws_init(pp_codec *, const char *);

  // Free the memory allocated for the codec
  extern void padpaws_free(pp_codec *);

  // Decode a buffer
  extern int padpaws_decode(const pp_codec *, char *);

  // Encode a buffer
  extern int padpaws_encode(const pp_codec *, char *);

#ifdef __cplusplus
}
#endif

#endif // __PADPAWS_H__
