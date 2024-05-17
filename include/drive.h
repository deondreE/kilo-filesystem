// retrieve drive data
#pragma once

#include "core.h"

typedef struct {
  char drive_name[256];
  long long total_size;
  long long free_space;
} DriveData;

KAPI DriveData get_drive_data(char drive_letter);
/// returns the default drive according to the system.
KAPI DriveData get_default_drive();