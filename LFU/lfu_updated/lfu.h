#ifndef __LFU_H__
#define __LFU_H__

#include "list.h"

#pragma warning (disable : 4996)


//! DEFINE FOR MODE OF OUR PROGRAM

#define MODE 0 

//! if 0 then realese version
//! if 1 then debug version


typedef int data_type;
typedef int hash_t;

//! Structure for list of frequency

struct Freq
{
	int value;

	struct Freq* prev;
	struct Freq* next;

	struct Item* child;
	struct Item* old_child;
};


//! Structure for LFU-cache algoritm

struct Cache
{
	int cache_max_size, cache_size, cache_hits;

	struct Hash_Item* hashtable[TABLE_MAXSIZE];
	struct Freq* freq_head;
};


//***************************

//Constructors for structures

//struct Cache* Hashtab_Constructor();

struct Freq* Empty_Freq_Constructor();

struct Item* New_Item_Constructor(data_type data, struct Freq* parent);

struct Cache* Cache_Constructor(int Cache_MAXSIZE);

//struct Hash_Item* Hash_Item_Constructor();

//**************************

//Distructors for structures

void Delete_Freq(struct Freq* freq);

void Cache_Distructor(struct Cache* cache);

void Freq_Distructor(struct Freq* freq);


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