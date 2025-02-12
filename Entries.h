#pragma once

#include <stdio.h>
#include <stdlib.h>

#define ENTRY_ERROR_MEMALLOC 0
#define ENTRY_SUCCES 1

/*===========================================*/
typedef char* Ent_String;
typedef unsigned char Ent_Return_Code;
typedef const char* Ent_CString;
/*===========================================*/
typedef void* Ent_Any;
/*===========================================*/
typedef unsigned int Ent_UInt;
/*===========================================*/
typedef unsigned short Ent_UShort;
/*===========================================*/
typedef unsigned long long Ent_ULLong;
/*===========================================*/

typedef struct Entrie {
	Ent_String key;
	Ent_Any value;
} Entrie;

typedef struct Entries {
	Entrie** items;
	Ent_UInt size;
} Entries;

/*===========================================*/
typedef void (*Ent_Callback)(Entrie);
/*===========================================*/

Ent_Return_Code entrie_push(Entries* entries, Ent_CString key, Ent_Any value, Ent_UShort value_size);
void entrie_foreach(Entries entries, Ent_Callback callback);