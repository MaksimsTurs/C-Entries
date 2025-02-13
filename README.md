# C Entries

Push a new entrie in to `Entries* entries->items`.
```c
Ent_Return_Code entrie_push(Entries* entries, Ent_CString key, Ent_Any value, Ent_UShort value_size);
```

Remove the last entrie from `Entries entries->items`.
```c
Ent_Return_Code entrie_pop(Entries entries);
```

Delete and free `Entries entries->items`.
```c
Ent_Return_Code entrie_delete(Entries entries);
```

## Example
```c
#include "./Entries.h"

#include <stdio.h>

int main(void) {
	Entries header = {0};

	entrie_push(&header, "Content-Type", "text/html\0", 11);
	entrie_push(&header, "Connection", "close\0", 7);
	int length = 2356;
	entrie_push(&header, "Content-Length", &length, sizeof(int));

	entrie_pop(header);
	entrie_pop(header);

	entrie_delete(header);

	return 0;
}
```