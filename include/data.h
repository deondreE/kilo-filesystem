#include "./core.h"
#include <dirent.h>

// this will be returned per parent that is read.
typedef struct {
  DIR* dir;
} parent_dir;

// this will be returned per file that is read.
typedef struct {
  char name[255];
} KILOFILE;

// Indexing the dir structures returns a large subset of data.
// takes the user home directory and traverses it.
KAPI KILOFILE* index_dir_structure(const char* basepath);

// write the cache file to not have to read all directories again.
void write_cache_file(KILOFILE file);