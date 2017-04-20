#include <stdio.h>
#include <assert.h>
#include <sys/stat.h>

int main() {
  FILE *fp, *fpout;
  fp = fopen("mutant-happy-face.data", "rb");
  fpout = fopen("mutant-happy-face.out", "r+b");
  int packed_nibbles;
  int b, c;
  
  /* TODO: Check if image is multiple of 2. If not
     exit with an error.
  */
  while((b = getc(fp)) != EOF) {
    assert(b < 0x10);
    c = getc(fp);
    assert(c < 0x10);
    packed_nibbles = (b<<4) | c;
    printf("%02x,", putc(packed_nibbles, fpout));
  }
  /* TODO: Compress resulting file with RLE. After that
     try other compression algorithms.
   */
  /* fclose(fpout); */
  /* fpout = fopen("mutant-happy-face.out", "rb"); */

  struct stat st;
  fstat(fileno(fp), &st);
  long size = st.st_size;
  printf("\ninput file size: %lu\n", size);


  printf("fileno(fpout) returns: %d\n", fileno(fpout));
  printf("fileno(fp) returns: %d\n", fileno(fp));
  
  struct stat st2;
  fstat(fileno(fpout), &st2);
  long size2 = st2.st_size;
  printf("ouput file size: %lu\n", size2);

  fclose(fp);


  return 0;
}
