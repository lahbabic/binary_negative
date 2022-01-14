#include <stdio.h>
#include <stdlib.h>

typedef struct binary{
    int *binary;
    int length;
}binaries;


long int pow(long int base, long int exponent)
{
    if (exponent == 0)
        return 1;
    else if (exponent > 0)
    {
        return base*pow(base, exponent-1);
    }
    return 0;
}

void invert_binary(binaries *bin)
{
    int tmp = 0;
    for (int i = 0; i < bin->length/2; i++)
    {
        tmp = bin->binary[i];
        bin->binary[i] = bin->binary[bin->length-i-1];
        bin->binary[bin->length-i-1] = tmp;
    }
    for (int i = 0; i < bin->length; i++)
    {
        if (bin->binary[i] == 0)
            bin->binary[i] = 1;
        else if (bin->binary[i] == 1)
            bin->binary[i] = 0;
        else if (bin->binary[i] == -1)
            bin->binary[i] = 0;    
    }
}

int add_one(binaries *bin, int i)
{
    if (bin->binary[i] == 0){
        bin->binary[i] = 1;
        return 0;    
    }
    else if (bin->binary[i] == 1)
    {
        if (i == 0)
        {
            bin->length += 1;
            bin->binary = (int *)realloc(bin->binary, bin->length*sizeof(int));
        }
        bin->binary[i] = 0;
        return add_one(bin, i-1);
    }
    return 0;
}

int convert_binary_to_int(binaries *bin)
{
    int number = 0;
    for (int i = 0; i < bin->length; i++)
    {
        number += pow(2, bin->length-i-1)*bin->binary[i];
    }
    return number;
}

binaries *convert_int_to_binary(int number, int mask, int binary_length)
{
    int mask_shifted = 0;
    int number_and_mask = 0;
    binaries *bin;
    bin = (binaries *)malloc(sizeof(binaries));
    bin->binary = (int *)malloc(sizeof(int));
    int i = 0;
    while (1)
    {
        mask_shifted = mask << i;
        number_and_mask = number & mask_shifted;
        bin->binary[i] = number_and_mask >> i;
        if (i == binary_length-1)
            break; 
        bin->binary = (int *)realloc(bin->binary, (i+2)*sizeof(int));
        i++;
    }
    bin->length = i+1;
    return bin;
}



int main(int argc, char *argv[])
{
    int binary_length = 32;
    int number = atoi(argv[1]);
    binaries *bin = (binaries *)malloc(sizeof(binaries));
    bin = convert_int_to_binary(number, 1, binary_length);
    invert_binary(bin);
    add_one(bin, bin->length-1);
    number = convert_binary_to_int(bin);
    printf("%d\n", number);
    return 0; 
}
