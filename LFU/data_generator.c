#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#pragma warning (disable:4996)


//! This is a cache data generator.
//! Its file exists in two versions - c and cpp.
//! We used it to create reasonable tests to test our caching algorithm.

int main()
{
    FILE* out;
	int num_cache = -1, num_pages = -1, page = -1, i = 0;

    out = fopen("input10.txt", "w");
    srand(time(0));

    num_cache = rand() % 100;
    num_pages = 100 + rand() % 10000;

    fprintf (out, "%d ", num_cache);
    fprintf (out, "%d ", num_pages);

    for (i = 0; i < num_pages; ++i) 
	{
        page = rand() % num_pages;
        fprintf ( out, "%d ", page );
    }

    fclose(out);

    return 0;
}

