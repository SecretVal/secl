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
      int res = fread(buf, 1, len, f);
      if (res == 0) {
	fprintf(stderr, "Error: Could not fread file\n");
	exit(1);
      }
    }
  }
  return buf;
}

#endif
