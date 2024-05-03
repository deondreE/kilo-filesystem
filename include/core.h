#pragma once

// core file for general std libriries / export macros.
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

// File Handle Struct
void list_files(const char *basepath);