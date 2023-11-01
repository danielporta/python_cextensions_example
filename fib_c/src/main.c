/*
 * ============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Main file of the project
 *
 *        Created:  03/24/2016 19:40:56
 *
 *         Author:  Gustavo Pantuza
 *   Organization:  Software Community
 *
 * ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "args.h"
#include "colors.h"
#include "fib.h"


int
main (int argc, char* argv[])
{

    /* Read command line options */
    options_t options;
    options_parser(argc, argv, &options);


#ifdef DEBUG
    fprintf(stdout, BLUE "Command line options:\n" NO_COLOR);
    fprintf(stdout, BROWN "help: %d\n" NO_COLOR, options.help);
    fprintf(stdout, BROWN "version: %d\n" NO_COLOR, options.version);
    fprintf(stdout, BROWN "use colors: %d\n" NO_COLOR, options.use_colors);
    fprintf(stdout, BROWN "filename: %s\n" NO_COLOR, options.file_name);
#endif

    struct timeval start, end;
    long mtime, seconds, useconds;

    for (int i=0; i<43; i++) {
        gettimeofday(&start, NULL);
        int f = fib(i);
        gettimeofday(&end, NULL);

        seconds = end.tv_sec - start.tv_sec;
        useconds = end.tv_usec - start.tv_usec;
        mtime = ((seconds) * 1000 + useconds / 1000.0); // Calculate the duration in milliseconds
        printf("fib(%d) = %d - duration %ld\n", i, f, mtime);        
    }     

    return EXIT_SUCCESS;
}

