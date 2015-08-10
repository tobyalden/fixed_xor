#include <stdio.h>

void fixed_xor(char *hex, char *mask);

int main(int argc, char *argv[])
{
  printf("HEX INPUT: %s\n", argv[1]);
  printf("HEX MASK: %s\n", argv[2]);
  fixed_xor(argv[1], argv[2]);
}

void fixed_xor(char *hex, char *mask)
{
  for(int i = 0; hex[i] != '\0'; i++)
  {
    printf("%c", hex[i]);
  }
}
