#include "drive.h"

#ifdef KPLAFORM_WINDOWS
#include <Windows.h>

DriveData get_drive_data(char drive_letter) {
  DriveData drive;
  ULARGE_INTEGER total_size, free_space; // unsiged_long
  

  char root_path[] = {drive_letter, ':', '\\', '\0'};

  if (GetDiskFreeSpaceEx(root_path, NULL, &total_size, &free_space)) 
  {
    drive.drive_letter = drive_letter; 
    drive.total_size   = total_size.QuadPart; 
    drive.free_space   = free_space.QuadPart; 
  } 
  else
  {
    // Error
    drive.drive_letter = '\0';
    drive.total_space  = 0;
    drive.free_space   = 0;
  }

  return drive;
}
#elif KPLATFORM_POSTIX
#include <sys/mount.h>

DriveData get_drive_data(char drive_letter) 
{
  DriveData drive;

  char root_path[] = { '/', drive_letter, '\0' };

  struct statfs stats; 
  if (statfs(root_path, &stats) == 0)
  {
    drive.drive_letter = drive_letter;
    drive.total_size   = (unsigned long long)stats.f_blocks * stats.f_bsize;
    drive.free_space   = (unsigned long long)stats.fbfree   * stats.fbsize;
  }
  else
  {
    drive.drive_letter = '\0';
    drive.total_size   = 0;
    drive.free_space   = 0; 
  }

  return drive;
}
#endif