#include  <stdio.h>
#include <stdlib.h>

//this is the custom function to sum up
//all the file size

void add_to_firlesize(const char *fpath, const struct stat *sb,
             int typeflag, struct FTW *ftwbuf)
{
    printf("filename: %s\n", fpath);

}
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
      printf("usage: %s <dirname>\n", argv[0]);
      exit (0);
  }

  // find the size of the entire directory
  // 1. get directory dirname
  char *dirname = argv[1];
  printf("Dirname: %s\n", dirname);

  nftw(dirname, add_to_firlesize,

  return 0;
}

// hello this is a test for git!!!!
