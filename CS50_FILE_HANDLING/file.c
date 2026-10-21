#include <stdio.h>
#include <stdlib.h>

const int HEADER_SIZE = 44;

int main (int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./volume input_file output_file scale_factor\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open input_file\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Could not open output_file\n");
        return 1;
    }
    

    int scale_factor = atof(argv[3]);

    // copy header of wav file
    char header[HEADER_SIZE];

    fread(&header, HEADER_SIZE, 1, input);
    fwrite(&header, HEADER_SIZE, 1, output);

    // scale the samples to the output.wav
    int16_t sample; // not a pointer, actual value

    while (fread(&sample, sizeof(int16_t), 1, input) != 0)
    {
        sample *= scale_factor;
        fwrite(&sample, sizeof(int16_t), 1, output);
    }


    fclose(input);
    fclose(output);

    return 0;
}
