#include <cs50.h>
#include <stdio.h>

int get_length(long number)
{
    int len = 0;
    while (number > 0)
    {
        number /= 10;
        len++;
    }
    return len;
}

int main(void)
{
    long card = get_long("Number: ");

    int sum = 0;
    long temp = card;
    int is_second = 0;

    while (temp > 0)
    {
        int digit = temp % 10;
        if (is_second)
        {
            int doubled = digit * 2;
            sum += doubled / 10;
            sum += doubled % 10;
        }
        else
        {
            sum += digit;
        }
        temp /= 10;
        is_second = !is_second;
    }

    int length = get_length(card);

    long first_two = card;
    while (first_two >= 100)
        first_two /= 10;

    long first = card;
    while (first >= 10)
        first /= 10;

    if (sum % 10 == 0)
    {
        if (length == 15 && (first_two == 34 || first_two == 37))
            printf("AMEX\n");
        else if (length == 16 && (first_two >= 51 && first_two <= 55))
            printf("MASTERCARD\n");
        else if ((length == 13 || length == 16) && first == 4)
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
