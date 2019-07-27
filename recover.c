#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    //check that there is only one command line argument
    if(argc != 2) {
        fprintf(stderr, "Usage: recover file\n");
        return 1;
    }

    //create a pointer to the file and open it
    FILE *input = fopen(argv[1], "r");

    //check that the file can be opened
    if(input == NULL) {
        fprintf(stderr, "File cannot be opened\n");
        return 2;
    }

    //temporary storage
    unsigned char *buffer = malloc(512);

    //check that the memory was successfully created
    if(buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 3;
    }

    //declare file pointer
    FILE *img = NULL;

    //variable to keep track of how many images have been opened
    int counter = 0;

    //allocate memory to hold the filenames
    char *filename = malloc(8);

    //and check that it was successfully allocated
    if(filename == NULL) {
        fprintf(stderr, "Memory allocation failed");
        return 3;
    }

    //this will run until the remaining data is fewer than 512 bytes and therefore not part of a JPEG
    while((fread(buffer, 512, 1, input)) == 1) {

        //check for JPEG header
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {

            //create filename and open new file
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");

            //if this is the first JPEG, do this
            if(counter == 0) {

                fwrite(buffer, 512, 1, img);
                counter ++;

            //if this is a new JPEG, close the previous file and open a new one
            } else if(counter > 0) {

                fclose(img);
                img = fopen(filename, "w");
                fwrite(buffer, 512, 1, img);
                counter ++;

            }
        //if this is part of a JPEG, but not the start of one, continue writing
        } else if (counter > 0) {

            fwrite(buffer, 512, 1, img);
        }


    }

    //free allocated memory
    free(buffer);
    free(filename);

    return 0;

}
