#include "lfu.h"

int main()
{
	struct Cache* cache = NULL;
	int max_size = 0, i = 0, num_of_calls = 0, res = 0;
	double cache_coeffs = 0;
	FILE* in, * out;
	hash_t hash = -1;

	in = fopen("input6.txt", "r");
	out = fopen("output.txt", "w");
	assert(in);
	assert(out);

	res = fscanf(in, "%d", &max_size);
	assert(res == 1);
	assert(max_size > 0);

	res = fscanf(in, "%d", &num_of_calls);
	assert(res == 1);

	cache = Cache_Constructor(max_size);
	assert(cache);

	for (i = 0; i < num_of_calls; ++i)
	{
		hash = Input(in, cache);

#if MODE == 1
		Cache_Dump(cache, hash);
#endif
	}

	cache_coeffs = (double)(cache->cache_hits) / (num_of_calls);

	fprintf(out, "Cache hits: %d\n", cache->cache_hits);
	fprintf(out, "Cache coeffs: %lf\n", cache_coeffs);

	fclose(in);
	fclose(out);

	Cache_Distructor(cache);

	return 0;
}
