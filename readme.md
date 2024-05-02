# filesystem

On Linux, mac, and windows the file explorer expierence is terrible. Often things are hidden, pinning something is like 10 steps. The goal of this project is to improve the file explorer from the ground up.


## steps to run the project.

```bash
 #step 1
 git clone "<repo link>"
 # step 2
 make setup
 # step 3
 make <platform to build to>
```

# General Information 

This project takes advantage of SwiftUi on all platform, we didn't want something that looked aweful, was a terrible developer expierence, and wanted to communicate directly with the native layer.

We also take advantage of XCodeGen to generate the project for all user, on the mac platform, ever other platform is currently under development and the DX around them is still being looked into. 

Yes swift works on windows, and linux.

The backend of the filesystem is written in C/C++ / Objective-C for somethings on the mac operating system.