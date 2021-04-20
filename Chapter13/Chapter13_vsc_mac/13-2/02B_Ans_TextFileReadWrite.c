#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int     main(int argc, char *argv[])
{
    int     ch;
    FILE    *fr, *fw;

    const char       *out_filename = "copy.txt";

    unsigned long    count = 0;

    if (argc != 2)
    {
       printf("Usage: %s filename\n", argv[0]);
       exit(EXIT_FAILURE);
    }

    if ((fr = fopen(argv[1], "r")) == NULL)  // Open a text file for reading.
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((fw = fopen(out_filename, "w")) == NULL)
    {
        printf("Can't open %s\n", out_filename);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fr)) != EOF)
    {
        fputc(ch, stdout);
        fputc(ch, fw);
        count++;
    }

    fclose(fr);
    fclose(fw);

    printf("FILE %s has %lu characters\n", argv[1], count);
    printf("Copied to %s\n", out_filename);

    return 0;
}