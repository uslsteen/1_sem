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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> cdcb8b0ac8e186dc212604e30f9134f75946ecb9
#define REGIME 0;
=======
#define REGIME 1;
>>>>>>> hashtable
=======
<<<<<<< HEAD
#define REGIME 1;
>>>>>>> f55494c... hashtable
=======
#define REGIME 0;
>>>>>>> 1c9e264... upd regime
=======
#define REGIME 1;
>>>>>>> cafc32c... hashtable
=======
#define REGIME 0;
>>>>>>> 281dfef... upd regime
=======
#define REGIME 0;
>>>>>>> cf32063390d7c3259ddc6d4c018feffd135e2138
>>>>>>> cdcb8b0ac8e186dc212604e30f9134f75946ecb9

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
