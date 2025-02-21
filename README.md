# CENT Library

The `CENT` library is a C-based utility designed to manage a collection of key-value entries. It provides operations to add, remove, and manage entries, ensuring memory is handled efficiently. The library allows keys and values of dynamic sizes to be stored, supporting any data type.

## Features

- **Memory Safe:** The library ensures proper memory allocation for key-value pairs and uses validation checks to avoid memory issues.
- **Dynamic Entries:** Each entry consists of a key and a value, where the value can be of any type, and both can be dynamically sized.
- **Error Handling:** The library uses error codes for handling invalid operations or memory issues.

## Functions

### `cent_push(CENT_Entries* const this, CENT_Char_Ptr const key, CENT_Any const value, CENT_UChar const value_size)`
Adds a new key-value entry into the collection.

- **Parameters:**
  - `this`: A pointer to the `CENT_Entries` object.
  - `key`: The key to associate with the value.
  - `value`: The value to store.
  - `value_size`: The size of the value.
  
- **Returns:** `CENT_Ret_Code` (success or error code)

### `cent_pop(CENT_Entries* const this)`
Removes the last entry from the collection.

- **Parameters:**
  - `this`: A pointer to the `CENT_Entries` object.
  
- **Returns:** `CENT_Ret_Code` (success or error code)

### `cent_free(CENT_Entries* const this)`
Frees the memory used by the collection and its entries.

- **Parameters:**
  - `this`: A pointer to the `CENT_Entries` object.
  
- **Returns:** `CENT_Ret_Code` (success or error code)

## Example Usage

```c
#include "CEntries.h"

int main() {
    CENT_Entries entries = {0};

    // Add a key-value pair
    int value = 42;
    cent_push(&entries, "example_key", &value, sizeof(value));

    // Pop the last entry
    cent_pop(&entries);

    // Free memory
    cent_free(&entries);

    return 0;
}
```