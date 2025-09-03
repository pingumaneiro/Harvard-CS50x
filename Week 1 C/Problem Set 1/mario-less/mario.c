#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for the pyramid's height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    // Print a pyramid of that height
    for (int row = 0; row < height; row++)
    {
        // Print the pyramid
        for (int space = 0; space < height - row - 1; space++)
        {
            // Print the spaces
            printf(" ");
        }
        for (int hash = 0; hash < row + 1; hash++)
        {
            // Print the hash
            printf("#");
        }
        printf("\n");
    }
}
