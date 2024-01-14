#include <stdio.h>

int bitlength(int number)
{
    if(number == 0)
    {
        return 0;
    }
    int count = 0;
    while(number)
    {
        count++;
        number >>= 1;
    }
    return count;
}


int main(void)
{
    printf("hello, world");

    int number = 65;

    int bitlengthresult = bitlength(number);

    printf("The bit length of %d is : %d\n", number, bitlengthresult);

    return 0;
}
