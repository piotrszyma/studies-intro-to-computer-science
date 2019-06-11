#include <stdio.h>

int main(void)
{

    signed short int ssint = 1;

    while(ssint>=1)
    {
        ssint*=2;
    }
    printf("signed short int min: %hi\n", ssint);
    printf("signed short int max: %hi\n", (short)(ssint-1));



    unsigned short usint = 1;
    while(usint>=1)
    {
        usint*=2;
    }
    printf("unsigned short int min: %hu\n", usint);
    printf("unsigned short int max: %hu\n", (short)(usint-1));




    signed int sint = 1;

    while(sint>=1)
    {
        sint*=2;
    }
    printf("signed int min: %d\n", sint);
    printf("signed int max: %d\n", sint-1);



    unsigned int uint = 1;

    while(uint>=1)
    {
        uint*=2;
    }
    printf("unsigned int min: %u\n", uint);
    printf("unsigned int max: %u\n", uint-1);

    signed long int slint = 1;

    while(slint>=1)
    {
        slint*=2;
    }
    printf("signed long int min: %ld\n", slint);
    printf("signed long int max: %ld\n", slint-1);



    unsigned long int ulint = 1;

    while(ulint>=1)
    {
        ulint*=2;
    }
    printf("unsigned long int min: %lu\n", ulint);
    printf("unsigned long int max: %lu\n", ulint-1);


    return 0;

}

