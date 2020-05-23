#include "list.h"

//! Function - constructor of hashtab

void Hashtab_Constructor(struct Hash_Item** hashtable)
{
	int i = 0;
	assert(hashtable);

	for (i = 0; i < TABLE_MAXSIZE; ++i)
	{
		hashtable[i] = (struct Hash_Item*) calloc(1, sizeof(struct Hash_Item));
		hashtable[i]->value = NO_ELEM;
	}
}

//! Function for instertion in hashtable

void Hashtab_Distructor(struct Hash_Item** hashtab)
{
	int i = 0;
	struct Hash_Item* h_item = NULL, * h_next = NULL;

	for (i = 0; i < TABLE_MAXSIZE; i++)
	{
		h_item = hashtab[i];

		while (h_item != NULL)
		{
			h_next = h_item->next;

			free(h_item->item);
			free(h_item);

			h_item = h_next;
		}
	}
}


//! Function for instertion in hashtable
//! Use this func for push to hashtable

//! ATTENTION! NEXT COMMENTS ACTUAL FOR LFU-ALGORITHM
//! In the LFU algorithm, we use push only if we know for sure that such an item is not in the hash table.
//! Search for an item occurs separately in the hashtab_lookup function

void Hashtab_Insert(struct Item* item, struct Hash_Item** hashtable)
{

	struct Hash_Item* cur_hash = NULL;
	struct Hash_Item* tmp = (struct Hash_Item*) calloc(1, sizeof(struct Hash_Item));
	hash_t index = -1;

	assert(tmp);
	assert(hashtable);

	index = Hash_Func(item->data);
	cur_hash = hashtable[index];

	if (cur_hash->item == NULL)
	{
		cur_hash->value = item->data;
		cur_hash->item = item;
	}
	else
	{
		tmp->next = cur_hash->next;
		cur_hash->next = tmp;
		tmp->item = item;
		tmp->value = item->data;
	}
}


//! Function for getting hash_item from the head of the list.

struct Hash_Item* Hashtab_Top(hash_t index, struct Hash_Item** hashtable)
{
	struct Hash_Item* cur_hash = hashtable[index];
	struct Hash_Item* hash_top = (struct Hash_Item*) calloc(1, sizeof(struct Hash_Item));
	struct Hash_Item* tmp = (struct Hash_Item*) calloc(1, sizeof(struct Hash_Item));

	assert(hash_top);
	assert(tmp);
	assert(hashtable);

	if (cur_hash->value == NO_ELEM)
	{
		printf("There is no such element in this list!\n");
		abort();
	}
	else
	{
		if (cur_hash->next == NULL)
		{
			hash_top->item = cur_hash->item;
			hash_top->value = cur_hash->value;

			cur_hash->item = NULL;
			cur_hash->value = NO_ELEM;

			return hash_top;
		}
		else
		{
			tmp = cur_hash->next;
			hash_top->item = cur_hash->item;
			hash_top->value = cur_hash->value;

			cur_hash = NULL;
			hashtable[index] = tmp;

			return hash_top;
		}
	}
}

//! Function for removing from hashtable
//! Use this function for pop something from hashtab

//! ATTENTION! NEXT COMMENTS ACTUAL FOR LFU-ALGORITHM
//! We use deleting from the hash-table only if we are sure that such an item exists in the hash table.
//! Search for an item occurs separately in the hashtab_lookup function

Hash_Item* Hashtab_Delete(data_type data, struct Hash_Item** hashtable)
{
	struct Hash_Item* cur_hash = NULL; //
	struct Hash_Item* tmp = NULL;
	struct Hash_Item* hash_pop = NULL;
	hash_t index = -1;

	assert(hashtable);

	index = Hash_Func(data);
	cur_hash = hashtable[index];

	if (cur_hash->value == NO_ELEM)
	{
		printf("There is no such element in this list!\n");
		abort();
	}
	else
	{
		if (cur_hash->next == NULL) //если в данной €чейки хэш-таблицы лист cur_hash единственный => cur_hash - искомый лист 
		{
			hash_pop = cur_hash;
			cur_hash->item = NULL;
			cur_hash->value = NO_ELEM;
		}
		else
		{
			if (cur_hash->value == data) //если первый лист(cur_hash) из данной €чейки - есть искомый лист
			{
				hash_pop = cur_hash;
				tmp = cur_hash->next;

				cur_hash->value = cur_hash->next->value;
				cur_hash->item = cur_hash->next->item;
				cur_hash->next = cur_hash->next->next;

				free(tmp);
			}
			else
			{
				while (cur_hash->next != NULL) //идем по списку листов hash_item до тех пор, пока не встретим null. ≈сли следующий после 
				{
					if (cur_hash->next->value == data)
						break;

					cur_hash = cur_hash->next;
				}

				tmp = cur_hash->next;
				cur_hash->next = tmp->next;

				free(tmp);
			}
		}
	}
	return hash_pop;
}


//! Function for calculating hash
//! Maybe it should be easier

int Hash_Func(data_type key)
{
	hash_t hash = 0;
	size_t bytes_len = sizeof(key);

	hash = key;

	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);


	return (abs(hash % TABLE_MAXSIZE));
}


//! Function for searching item in hashtable

//! ATTENTION! NEXT COMMENTS ACTUAL FOR LFU-ALGORITHM

//! In cache LFU we use this function for searching item in hashtable. 
//! If we did not find the item in the hashtable, we add the item to the hashtable.
//! If we know for sure that there is such an item, go to the 'else' branchand increase the cache hits, delete the item from the hashtable, the frequency list.
//! Then add to the new list of frequencies, return the updated item to the hash table.

struct Output* Hashtab_Lookup(struct Hash_Item* cur_hash, data_type data)
{
	struct Output* res = (struct Output*) calloc(1, sizeof(struct Output));
	assert(res);

	if (cur_hash->item == NULL)
	{
		res->res = DOESNT_EXIST;
		res->item = NULL;

		return res;
	}
	else if (cur_hash->next == NULL)
	{
		if (cur_hash->value == data)
		{
			res->item = cur_hash->item;
			res->res = EXIST;
			return res;
		}
		else
		{
			res->item = NULL;
			res->res = DOESNT_EXIST;
			return res;
		}
	}
	else
		while (cur_hash != NULL)
		{
			if (data == cur_hash->value)
			{
				res->item = cur_hash->item;
				res->res = EXIST;
				return res;
			}
			cur_hash = cur_hash->next;
		}

	res->res = DOESNT_EXIST;
	res->item = NULL;
	return res;
}


