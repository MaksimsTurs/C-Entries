#pragma once

/*=======================================================================*/

#include <stdlib.h>	
#include <string.h>

#include "./include/CString.h"

/*=======================================================================*/

typedef char*              CENT_Char_Ptr;
typedef unsigned char      CENT_Ret_Code;
typedef unsigned char      CENT_Bool;

typedef unsigned char      CENT_UChar;
typedef signed char        CENT_SChar;
typedef char               CENT_Char;

typedef unsigned long long CENT_ULLong;
typedef signed long long   CENT_SLLong;
typedef long long          CENT_LLong;
typedef long               CENT_Long;

typedef unsigned short     CENT_UShort;
typedef signed short       CENT_SShort;
typedef short              CENT_Short;

typedef float              CENT_Float;

typedef double             CENT_Double;

typedef void*              CENT_Any;

/*=======================================================================*/

// Validation/restrictions constants.
#define CENT_KEY_MAX_LENGTH           (CENT_UChar)64
// Types constants.
#define CENT_TRUE                     (CENT_UChar)1
#define CENT_FALSE                    (CENT_UChar)0
// Error/success constants.
#define CENT_ERROR_INVALID_KEY_LENGTH (CENT_UChar)0
#define CENT_ERROR_INVALID_SIZE       (CENT_UChar)1
#define CENT_ERROR_INVALID_PTR        (CENT_UChar)2
#define CENT_ERROR_MEMALLOC           (CENT_UChar)3
#define CENT_SUCCESS                  (CENT_UChar)4

// Utils macros.
#define CENT_FAIL_IF(condition, error_code) do { \
	if(condition) return error_code;              \
} while(0);

/*=======================================================================*/

typedef struct {
	CENT_Char_Ptr key;
	CENT_Any value;
} CENT_Entrie;

typedef struct {
	CENT_Entrie** items;
	CENT_UShort size;
} CENT_Entries;

/*=======================================================================*/

CENT_Ret_Code cent_push(CENT_Entries* const this, CENT_Char_Ptr const key, CENT_Any const value, CENT_UChar const value_size);
CENT_Ret_Code cent_pop(CENT_Entries* const this);
CENT_Ret_Code cent_free(CENT_Entries* const this);

/*=======================================================================*/