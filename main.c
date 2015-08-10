#include <stdio.h>
#include <gmp.h>

char * fixed_xor(char *hex, char *mask);
void printstr(char *str);

int main(int argc, char *argv[])
{
  printf("HEX INPUT: %s\n", argv[1]);
  printf("HEX MASK: %s\n", argv[2]);
  printstr(fixed_xor(argv[1], argv[2]));
}

char * fixed_xor(char *hex, char *mask)
{
  mpz_t decimal;
  mpz_t decimal_mask;
  mpz_t xored_decimal;
  mpz_init_set_str (decimal, hex, 16);
  mpz_init_set_str (decimal_mask, mask, 16);
  mpz_init(xored_decimal);

  mpz_xor(xored_decimal, decimal, decimal_mask);

  char *xored_hex = mpz_get_str(NULL, 16, xored_decimal);

  printf("XORED HEX: ");
  return xored_hex;
}

void printstr(char *str)
{
  for(int i = 0; str[i] != '\0'; i++)
  {
    printf("%c", str[i]);
  }
  printf("\n");
}
