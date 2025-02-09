#ifndef SECL_H
#define SECL_H
#include <stdio.h>
#include <stdlib.h>

char* secl_read_file(FILE *f)
{
  char* buf = 0;
  long len;
  if (f)  {
    fseek(f, 0, SEEK_END);
    len = ftell(f);
    fseek(f, 0, SEEK_SET);
    buf = malloc(len);
    if (buf) {
      fread(buf, 1, len, f);
    }
  }
  return buf;
}

#endif
