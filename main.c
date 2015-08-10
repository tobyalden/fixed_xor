#include <stdio.h>
#include <gmp.h>

void fixed_xor(char *hex, char *mask);

int main(int argc, char *argv[])
{
  printf("HEX INPUT: %s\n", argv[1]);
  printf("HEX MASK: %s\n", argv[2]);
  fixed_xor(argv[1], argv[2]);
}

void fixed_xor(char *hex, char *mask)
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
  for(int i = 0; xored_hex[i] != '\0'; i++)
  {
    printf("%c", xored_hex[i]);
  }
  printf("\n");
}

// — Function: char * mpz_get_str (char *str, int base, const mpz_t op)
// Convert op to a string of digits in base base. The base argument may vary from 2 to 62 or from −2 to −36.
//
// For base in the range 2..36, digits and lower-case letters are used; for −2..−36, digits and upper-case letters are used; for 37..62, digits, upper-case letters, and lower-case letters (in that significance order) are used.
//
// If str is NULL, the result string is allocated using the current allocation function (see Custom Allocation). The block will be strlen(str)+1 bytes, that being exactly enough for the string and null-terminator.
//
// If str is not NULL, it should point to a block of storage large enough for the result, that being mpz_sizeinbase (op, base) + 2. The two extra bytes are for a possible minus sign, and the null-terminator.
//
// A pointer to the result string is returned, being either the allocated block, or the given str.
