#include "./core.h"
#include <dirent.h>

#define PIN 0

// this will be returned per parent that is read.
typedef struct {
  DIR* dir;
} parent_dir;

// this will be returned per file that is read.
typedef struct {
  char name[255];
} KILOFILE;

// hash table for storing file data inside of.
typedef struct ht ht;

// create and return pointer to the table.
ht* ht_create(void);

// Free memory  allocated for hash table.
void ht_destroy(ht* table);

// Set item with given key (NULL) to value (which must not be NULL). 
const char* ht_set(ht* table, const char* key, void* value);

// returns the length in a number.
size_t ht_length(ht* table);

typedef struct {
  const char* key; // current key
  void* value;

  // don't use these feilds directly.
  ht* _table;
  size_t _index;
} hti; 

// Return new hash table interator (for use with ht_next).
hti ht_iterator(ht* table);

bool ht_next(hti *it);

// Indexing the dir structures returns a large subset of data.
// takes the user home directory and traverses it.
// This will also create the cache file it it doesn't exist.
KAPI KILOFILE* index_dir_structure(const char* basepath);

// write the cache file to not have to read all directories again.
void write_cache_file(KILOFILE file);

// read the cache file inside from the given path.
void read_cache_file(const char* path);

