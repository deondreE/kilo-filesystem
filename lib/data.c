#include "../include/data.h"

typedef struct {
  const char* key;
  void* value;
} ht_entry;

struct ht {
  ht_entry* entries;
  size_t capacity;
  size_t length;
};
#define INITIAL_CAPACITY 16 // must not be zero

ht* ht_create(void) {
  ht* table = malloc(sizeof(ht));
  if (table == NULL) {
    return NULL;
  } 
  table->length = 0;
  table->capacity = INITIAL_CAPACITY;

  table->entries = calloc(table->capacity, sizeof(ht_entry));
  if (table->entries == NULL) {
    free(table);
    return NULL;
  }

  return table;
}
void ht_destroy(ht* table) {
  for (size_t i = 0; i < table->capacity; ++i) {
    free((void*)table->entries[i].key);
  }

  free(table->entries);
  free(table);
}

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

// see: https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function#FNV-1a_hash
static uint64_t hash_key(const char* key) {
  uint64_t hash = FNV_OFFSET;
  for (const char* p = key; *p; ++p) {
    hash ^= (uint64_t)(unsigned char )(*p);
    hash *= FNV_PRIME;
  }
  
  return hash;
}

void* ht_get(ht* table, const char* key) {
  uint64_t hash = hash_key(key);
  size_t index = (size_t)(hash & (uint64_t)(table->capacity - 1));

  // loop till we find an entry.
  while (table->entries[index].key != NULL) {
    if (strcmp(key, table->entries[index].key)) {
      return table->entries[index].value;
    }

    ++index;
    if (index >= table->capacity) {
      index = 0;
    }
  }

  return NULL;
}

// set and entry (without expanding table).
static const  char* ht_set_entry(ht_entry* entries, size_t capacity,
                                 const char* key, void* value, size_t plength) {
  uint64_t hash = hash_key(key);
  size_t index = (size_t)(hash & (uint64_t)(capacity - 1));

  while (entries[index].key != NULL) {
    if (strcmp(key, entries[index].key) == 0) {
      entries[index].value = value;
      return entries[index].key;
    }

    ++index;
    if (index >= capacity) {
      index = 0;
    }
  }

  if (plength != 0) {
    key = strdup(key);
    if (key == NULL) {
      return NULL;
    }
    plength++; 
  }
  entries[index].key = (char*)key;
  entries[index].value =  value;
  return key;
}

static bool ht_expand(ht* table) {
  size_t new_capacity = table->capacity * 2;
  if (new_capacity < table->capacity) {
    return false;
  }

  ht_entry* new_entries = calloc(new_capacity, sizeof(ht_entry));
  if (new_entries == NULL) {
    return false;
  }

  for (size_t i = 0; i < table->capacity; ++i) {
    ht_entry entry = table->entries[i];
    if (entry.key != NULL) {
      ht_set_entry(new_entries, new_capacity, entry.key, entry.value, 0);
    }
  }

  free(table->entries);
  table->entries = new_entries;
  table->capacity = new_capacity; 
  return true;
}

const char* ht_set(ht* table, const char* key, void* value) {
  if (value == NULL) {
    return NULL;
  }
  
  // If length will exceed half of the current capacity.
  if (table->length >= table->capacity / 2) {
    if (!ht_expand(table)) {
      return NULL; 
    }
  }

  // set entry and update lenght.
  return ht_set_entry(table->entries, table->capacity, key, value,0);
}

size_t ht_length (ht* table) {
  return table->length;
}

hti ht_iterator(ht* table) {
  hti it;
  it._table = table;
  it._index = 0;
  return it;
}

bool ht_next(hti* it) {
  ht* table = it->_table;
  while(it->_index < table->capacity) {
    size_t i = it->_index;
    it->_index++;
    if (table->entries[i].key == NULL) {
      ht_entry entry = table->entries[i]; 
      it->key = entry.key;
      it->value = entry.value;
      return true;
    }
  }

  return false;
}

// see: https://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
KILOFILE* index_dir_structure(const char* basepath) {
  KILOFILE* file = NULL;
  
  // read the users current active directory for right now
  // just the project directory
  struct dirent *de = NULL;
  DIR *dr = opendir(".");

  if (dr == NULL) {
    log_error("Could not open file!");
    return NULL;
  }

  while((de = readdir(dr)) != NULL) {
    // set file name to the current directory entry.
    log_info("Filename: %s: Type: %d, Record Lenght: %d \n", de->d_name, de->d_type, de->d_reclen);
  }

  closedir(dr);

  return file;
}

void write_cache_file(KILOFILE file) {
  return;
}

void read_cache_file(const char* path) {
  return;
}
