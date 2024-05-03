#!/bin/bash

# check if the platform is macOS.
if [[ "$(uname)" == "Darwin" ]]; then
  #  macOS specific code.
  brew install xcodegen ffmpeg
  # generate xcodeproj
  xcodegen
  # generate backend source.
  make all
elif [[ "$(expr substr $(uname -s) 1 5)" == "Linux" ]]; then
  # TODO;
  echo "linux code"
else
 echo "no worky."
fi