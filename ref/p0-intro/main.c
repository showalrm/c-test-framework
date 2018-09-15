/*
 * CS 261: Intro project driver
 *
 * Name: 
 */

#include "p0-intro.h"

int main (int argc, char **argv)
{
    // BEGIN_SOLUTION

    const size_t BUFFER_SIZE = 4096;
    bool hello = true;
    bool goodbye = false;
    bool cat = false;
    char *cat_fn = NULL;

    char c;
    while ((c = getopt(argc, argv, "gt:c:h:u:e:")) != -1) {
        switch (c) {

            case 'g': goodbye = true; hello = false;                      break;
            case 'c':     cat = true; hello = false;     cat_fn = optarg; break;

            default:
                printf("Invalid argument.\n");
                return EXIT_FAILURE;
        }
    }

    if (hello) {
        printf("Hello, world!\n");
    }
    if (goodbye) {
        printf("Goodbye!\n");
    }

    if (cat) {
        FILE *fin = fopen(cat_fn, "r");
        if (!fin) {
            printf("Invalid file.\n");
            exit(EXIT_FAILURE);
        }
        char buffer[BUFFER_SIZE];
        while (fgets(buffer, BUFFER_SIZE, fin) != NULL) {
            printf("%s", buffer);
        }
        fclose(fin);
    }

    // END_SOLUTION
    // BOILERPLATE: printf("Hello, class!\n");
    return EXIT_SUCCESS;
}

