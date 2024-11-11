#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char x;
    scanf("%c", &x);

    printf(
        "  %c\n"
        " %c%c%c\n"
        "%c%c%c%c%c\n",
        x, x, x, x, x, x, x, x, x);

    return EXIT_SUCCESS;
}
