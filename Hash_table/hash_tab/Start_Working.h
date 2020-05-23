#ifndef __START_WORKING__
#define __START_WORKING__

#include "hash_tab.h"

//! define for different colors for input to consol
#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_GREEN      "\x1b[32m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"
#define ANSI_COLOR_MAGENTA    "\x1b[35m"
#define ANSI_COLOR_CYAN       "\x1b[36m"
#define ANSI_COLOR_WHITE      "\x1b[37m"
#define ANSI_COLOR_RESET      "\x1b[0m"

enum FLAG
{
	FOR_LIST = 1,
	FOR_HASHTAB = 2,
};

//! define for debug

<<<<<<< HEAD
#define REGIME 0;
=======
#define REGIME 1;
>>>>>>> hashtable

//! set REGIME = 1 if you want to receive more info
//! set REGIME = 0 if you dont want to receive a lot of information

//! DEBUG FUNCTION OF MY HASH-TABLE

//! Main func for debug - start_working
void Start_Working();

//! Functions for working with hash-table
void Test_for_insertion(struct Hash_Item** hashtable, FILE* in, FILE* out);

void Test_for_deleting(struct Hash_Item** hashtable, FILE* in, FILE* out);

void Test_for_top(struct Hash_Item** hashtable, FILE* in, FILE* out);

//! Just Dump.
void Dump(struct Hash_Item** hashtable, FLAG mode, hash_t hash, FILE* out);


#endif
