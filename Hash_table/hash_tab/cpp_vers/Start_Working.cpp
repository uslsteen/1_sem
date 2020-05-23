#include "start_working.h"

void Start_Working()
{
	struct Hash_Item* hashtable[TABLE_MAXSIZE];
	int data = 0, res = 0, num = 0;
	hash_t hash = 0;
	FILE* in, * out;

	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");

	Hashtab_Constructor(hashtable);


	int mode = 0, choice = 0, check = 0;


		while (true)
		{
			if ((check = fscanf(in, "%d", &mode)) != 1)
			{
				printf(ANSI_COLOR_RED "Error in scanf start_working(1)!\n" ANSI_COLOR_RESET);
				return;
			}

			switch (mode)
			{
			case 0:


				while (true)
				{
					choice = -1;

					if (check = fscanf(in, "%d", &choice) != 1)
					{
						fprintf(out, "Error in scanf start_working(2)!\n\n");
						return;
					}

					if (choice == 1)
					{
						fprintf(out, "**   -Bye. Nice to see you, dude! **\n");
						return;
					}

					else
						if (choice == 0)
						{
							break;
						}

						else
							if (choice != 0 && choice != 1)
							{
								return;
							}
				}

				break;


			case 1:

				Test_for_insertion(hashtable, in, out);

				break;

			case 2:

				Test_for_deleting(hashtable, in, out);

				break;

			case 3:

				Test_for_top(hashtable, in, out);

				break;

			case 4:

				Dump(hashtable, FOR_HASHTAB, hash, out);

				break;


			default:
				fprintf(out, "I don't undestand what you want from me, dude!\n\n");

				break;
			}

		}

		fclose(in);
		fclose(out);

		Hashtab_Distructor(hashtable);
}


//! There's functions for testing my hashtable. 
//! I suggest use it with help hashtab_dump, but you can check your inputed data by other ways.
//! See more about hashtab_dump below

//! Testing function for insertion in hashtable

void Test_for_insertion(struct Hash_Item** hashtable, FILE* in, FILE* out)
{
	int data = 0, res = 0, num = 0;
	hash_t hash = 0;
	struct Item* test = NULL;

	res = fscanf(in, "%d", &num);
	assert(res);

	for (int i = 0; i < num; ++i)
	{
		res = fscanf(in, "%d", &data);
		assert(res);

		test = New_Item_Constructor(data);
		Hashtab_Insert(test, hashtable);

		hash = Hash_Func(data);

#if REGIME > 0
		Dump(hashtable, FOR_LIST, hash, out);
#endif

	}
}


//! Testing function for deleting from hashtable

void Test_for_deleting(struct Hash_Item** hashtable, FILE* in, FILE* out)
{
	int data = 0, res = 0, num = 0;
	hash_t hash = 0;
	struct Item* test = NULL;

	res = fscanf(in, "%d", &num);
	assert(res);

	for (int i = 0; i < num; ++i)
	{
		res = fscanf(in, "%d", &data);
		assert(res);

		Hashtab_Delete(data, hashtable);

		hash = Hash_Func(data);

#if REGIME > 0
		Dump(hashtable, FOR_LIST, hash,out);
#endif

	}
}

//! Testing function for getting top from hashtable

void Test_for_top(struct Hash_Item** hashtable, FILE* in, FILE* out)
{
	int data = 0, res = 0, num = 0;
	hash_t hash = 0;
	struct Item* test = NULL;

	res = fscanf(in, "%d", &num);
	assert(res);

	for (int i = 0; i < num; ++i)
	{
		res = fscanf(in, "%d", &data);
		assert(res);

		hash = Hash_Func(data);

		Hashtab_Top(hash, hashtable);

#if REGIME > 0
		Dump(hashtable, FOR_LIST, hash, out);
#endif

	}
}



//! Hashtab_Dump - function exist for checking data of item in our hashtable list. 

//*************************************
//! This function has two modes of operation.
//! 1) FOR_LIST. Then after each function executed(insertion, delete, top), the hashtab_dump shows the condition of the list with which this function worked.
//! 2) FOR_HASHTAB. A call through the main debugging interface shows a fully hash-table.

void Dump(struct Hash_Item** hashtable, FLAG mode, hash_t hash, FILE* out)
{
	struct Hash_Item* hash_debug = NULL;
	assert(hashtable);

	if (mode == FOR_LIST)
	{

		hash_debug = hashtable[hash];

		fprintf(out, "\n");

		fprintf(out, "| hashtable[%d]: |", hash);

		while (hash_debug != NULL)
		{
			if (hash_debug->value == NO_ELEM)
			{
				fprintf(out, "There is no elements!");
				break;
			}
			else
			{
				fprintf(out, "| %d | -> ", hash_debug->value);
				hash_debug = hash_debug->next;
			}
		}
		fprintf(out, "\n\n");
	}
	else if (mode == FOR_HASHTAB)
	{
		fprintf(out, "It's dump for all hashtable!\n");

		hash_debug = NULL;

		assert(hashtable);

		fprintf(out, "\n");

		for (hash = 0; hash < TABLE_MAXSIZE; ++hash)
		{
			hash_debug = hashtable[hash];
			fprintf(out, "| hashtable[%d]: | ", hash);

			while (hash_debug != NULL)
			{
				if (hash_debug->value == NO_ELEM)
				{
					fprintf(out, "There is no elements!");
					break;
				}
				else
				{
					fprintf(out, "| %d | -> ", hash_debug->value);
					hash_debug = hash_debug->next;
				}
			}
			fprintf(out, "\n");
		}
	}

	else
	{
		fprintf(out, "ERROR IN HASH-TAB DUMP!\n");
		abort();
	}
}
