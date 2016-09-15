#include <stdio.h>
#include <stdlib.h>

int is_bit_i_set(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    printf("%d\n", mask);
    return mask & c;
}

int main()
{
    printf("%d\n", is_bit_i_set('a', 3));
    printf("%d", 'c');
}
