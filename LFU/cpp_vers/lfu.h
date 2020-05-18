#ifndef __LFU_H__
#define __LFU_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <malloc.h>
#include <string.h>

#pragma warning (disable : 4996)

#define MODE 0

enum CONDITIONS
{
	EXIST = 1,
	DOESNT_EXIST = 0,
};

enum
{
	TABLE_MAXSIZE = 100,
};


typedef int data_type;
typedef int hash_t;


struct Item
{
	data_type data;

	struct Item* prev;
	struct Item* next;
	struct Freq* parent;
};

struct Freq
{
	int value;

	struct Freq* prev;
	struct Freq* next;
	struct Item* child;
	struct Item* old_child;
};

struct Hash_Item
{
	data_type value;

	struct Item* item;
	struct Hash_Item* next;
};

struct Cache
{
	int cache_max_size, cache_size, cache_hits;

	struct Hash_Item* hashtable[TABLE_MAXSIZE];
	struct Freq* freq_head;
};

struct Output
{
	int res;
	struct Item* item;
};

//***************************

//Constructors for structures

struct Cache* Hashtab_Constructor();

struct Freq* Empty_Freq_Constructor();

struct Item* New_Item_Constructor(data_type data, struct Freq* parent);

struct Cache* Cache_Constructor(int Cache_MAXSIZE);

struct Hash_Item* Hash_Item_Constructor();

//**************************

//Distructors for structures

void Delete_Freq(struct Freq* freq);

void Cache_Distructor(struct Cache* cache);

void Freq_Distructor(struct Freq* freq);

void Hashtab_Distructor(struct Hash_Item** hashtab);

//************************************

//Functions for working with hashtable

void Hashtab_Delete(data_type data, hash_t index, struct Cache* cache);

void Hashtab_Insert(struct Item* Item, hash_t index, struct Cache* cache);

struct Output* Hashtab_Lookup(struct Hash_Item* cur_hash, data_type data);

int Hash_Func(data_type key);

//************************************************************

//Functoins for working with cache structure and freq structure

struct Freq* Insert_new_Freq(int freq, struct Freq* prev, struct Freq* next);

struct Item* Insert_in_Cache(hash_t index, data_type data, struct Cache* cache);

void Add(struct Freq* freq, hash_t index, data_type data, struct Cache* cache);

void Remove_Item(struct Item* cur, hash_t index, struct Cache* cache);

int Remove_LFU(struct Cache* cache);

data_type Access_to_Item(data_type data, hash_t index, struct Cache* cache);

hash_t Input(FILE* f, struct Cache* cache);


#if MODE == 1

void Cache_Dump(struct Cache* cache, hash_t hash);

#endif
//************************************************************


#endif