// retrieve drive data
#pragma once

#include "core.h"

typedef struct {
  char drive_letter;
  unsigned long total_size;
  unsigned long free_space;
} DriveData;

KAPI DriveData get_drive_data(char drive_letter);