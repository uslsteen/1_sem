#ifndef __HASH_TAB_H__
#define __HASH_TAB_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <malloc.h>
#include <string.h>

#pragma warning (disable : 4996)


//! Module of hashtable.
//! Here you can find all fucntions, which we used in LFU.


typedef int data_type;
typedef int hash_t;

//! Enum for size of hashtable
enum
{
	TABLE_MAXSIZE = 100,
	NO_ELEM = -1
};

//! Enum for helper structures OUTPUT for hashtab_lookup

enum CONDITIONS
{
	EXIST = 1,
	DOESNT_EXIST = 0,
};


//! Signle list of hashtable

struct Hash_Item
{
	data_type value;

	struct Item* item;
	struct Hash_Item* next;
};

//! Sigle list of item - data

struct Item
{
	data_type data;
};

//! Helpler structure for hashtable_lookup

struct Output
{
	enum CONDITIONS res;
	struct Item* item;
};


//! Functions for working with hashtable
//! See mo discriptions in list.c

struct Output* Hashtab_Lookup(struct Hash_Item* cur_hash, data_type data);

void Hashtab_Constructor(struct Hash_Item** hashtable);

//! Generally speaking, in the list instead of a pointer to item, you could simply write data and rewrite the hash-table for the most general case.
//! But I decided not to depart much from the previously set task.
//! Therefore, I left a pointer to the item structure in the Hash_Item list.

struct Item* New_Item_Constructor(data_type data);

void Hashtab_Distructor(struct Hash_Item** hashtab);

Hash_Item* Hashtab_Delete(data_type data, Hash_Item** hashtable);

void Hashtab_Insert(struct Item* item, Hash_Item** hashtable);

int Hash_Func(data_type key);

struct Hash_Item* Hashtab_Top(hash_t index, struct Hash_Item** hashtable);

#endif