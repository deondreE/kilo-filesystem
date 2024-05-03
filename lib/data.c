#include "../include/data.h"

// see: https://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
KAPI KILOFILE* index_dir_structure(const char* basepath) {
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
