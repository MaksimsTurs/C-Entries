#include "./Entries.h"

Ent_Return_Code entrie_push(Entries* entries, Ent_CString key, Ent_Any value, Ent_UShort value_size) {
	if(entries->items == NULL)
		entries->items = (Entrie**)malloc(sizeof(Entrie*));
	else
		entries->items = (Entrie**)realloc(entries->items, (entries->size + 1) * sizeof(Entrie*));
	
	if(entries->items == NULL)
		return ENTRY_ERROR_MEMALLOC;

	Ent_ULLong key_length = strlen(key) + 1;
	Ent_ULLong size_of_entrie = sizeof(Entrie);
	
	Entrie* item = (Entrie*)malloc(size_of_entrie + key_length + value_size);
	if(entries->items == NULL)
		return ENTRY_ERROR_MEMALLOC;

	Ent_String key_position = (Ent_String)item + size_of_entrie;
	Ent_Any value_position = key_position + key_length;

	item->key = key_position;
	item->value = value_position;
	
	memmove(item->key, key, key_length);
	mempcpy(item->value, value, value_size);

	entries->items[entries->size++] = item;

	return ENTRY_SUCCES;
}

void entrie_foreach(Entries entries, Ent_Callback callback) {
	for(Ent_ULLong index = 0; index < entries.size; index++)
		callback(*entries.items[index]);
}