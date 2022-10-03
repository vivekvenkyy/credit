#include <cs50.h>
#include <stdio.h>

// Declaration of functions
int length(long num);
int first_digit(long first);
int two_digit(long second);
int total_digits;
// main
int main(void)
{
    //getting total digits
    long number;
    do
    {
         number = get_long("enter the credit card number: ");
    }
    while(number < 0);

    total_digits = length(number);
    int first1digit = first_digit(number);
    int first2digit = two_digit(number);
    printf("%i\n", total_digits);


//checksum
     int sum1 = 0;
     int sum2 = 0;
     long N = number;
     int total = 0;
     int modulo1;
     int modulo2;
     int x1;
     int x2;

     for(int i = 0; i < length(number); i++)
     {
        modulo1 = N % 10;
        N = N / 10;
        sum1 = sum1 + modulo1;

        modulo2 = N % 10;
        modulo2 = modulo2 * 2;
        x1 = modulo2 % 10;
        x2 = modulo2 / 10;
        sum2 = sum2 + x1 + x2;
        N = N/10;
     }

     total = sum1 + sum2;

     //luhn algorithm
     if(total % 10 != 0)
     {
        printf("INVALID\n");
     }
     else if(total_digits == 15 && (first2digit == 34 || first2digit == 37))
     {
        printf("american express\n");
     }

     else if(total_digits == 1 && (first2digit == 51 || first2digit == 52 || first2digit == 53 || first2digit == 54 || first2digit == 55))
     {
        printf("mastercard\n");
     }

     else if((total_digits == 13  || total_digits == 16) && first1digit == 4)
     {
        printf("amex\n");
     }
     else
     {
        printf("INVALID");
     }

}



// my functions
int length(long num)
{
    int counter = 0;
    while(num>0)
    {
         num = num/10;
         counter++;
    }
    return counter;
}


//for visa
//to find the first digit for visa card
int first_digit(long first)
{
    int no = first / (10^(total_digits-1));
    printf("%i",no);
    return no;
}


//for mastercard or american express
int two_digit(long second)
{
    int no = second / (10^(total_digits-2));
    printf("%i",no);
    return no;
}





















