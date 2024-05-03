#pragma once

// core file for general std libriries / export macros.
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>


// File Handle Struct
typedef struct {
    FILE *file;

    int is_dir; // could have files inside of it. 
} FileHandle;

