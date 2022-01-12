#include <stdio.h>
#include <stdlib.h>

int pow(int base, int exponent)
{
    if (exponent != 1)
        return base*pow(base, exponent-1);
    else if (exponent == 1)
        return base;
}

void invert_binary(int *bits, int binary_length)
{
    for (int i = 0; i < binary_length; i++)
    {
        if (bits[i] == 0)
            bits[i] = 1;
        else if (bits[i] == 1)
            bits[i] = 0;
    }
}

int convert_binary_to_int(int *bits, int binary_length)
{
    int number;
    for (int i = 0; i < binary_length; i++)
    {
        number += pow(2, binary_length-i)*bits[i];
    }
    number -= pow(2, binary_length+1)*bits[0];
    return number;
}

void convert_int_to_binary(int *bits, int number, int mask, int binary_length)
{
        int mask_shifted = 0;
        int number_and_mask = 0;
        for (int i = 0; i < binary_length; ++i)
        {
                mask_shifted = mask << i;
                number_and_mask = number & mask_shifted;
                bits[i] = number_and_mask >> i;
        }
        mask_shifted = 0;
        number_and_mask = 0;
}

int main(int argc, char *argv[])
{
    int binary_length = 32;
    int negatif_of_number = 0;
    int *bits = (int *)malloc(binary_length*sizeof(int));
    convert_int_to_binary(bits, 2, 1, binary_length);
    for (int i = 0; i < binary_length; i++)
    {
        printf("%d ", bits[i]);
    }
    printf("\n\n");
    invert_binary(bits, binary_length);
    for (int i = 0; i < binary_length; i++)
    {
        printf("%d ", bits[i]);
    }
    printf("\n\n");
    printf("%d\n", pow(2, 3));
    negatif_of_number = convert_binary_to_int(bits, binary_length);
    printf("%d\n", negatif_of_number);
    return 0;
}
