# Folder Structure

## folder structure based on Arduino Documentation

- Each folder must contain at most one .ino file
- the folder SHOULD be the same as the one .ino file that it includes
- the .ino files __can not__ include headers with relative path that refer to an upper level folder.

Next, it's necessary for you to understand how Arduino's library discovery system works. You can learn all about that here:
<https://arduino.github.io/arduino-cli/latest/sketch-build-process/#dependency-resolution>

That's a pretty dense read, so I'll give some important points:

- If the double quotes syntax is used, the relative or absolute path is checked.
- If found at that path only the specified header file is included. The accompanying source files in that folder are not given any special treatment.
- If not found at that path or in the current include search paths list, the root of the source folder of all libraries installed in the standard Arduino library folder installation locations (e.g., /libraries, /libraries, /libraries, core library, core variant library) is searched for the file.
- If the file is found, that library folder is added to the include search paths list and the source files of that library are compiled.

So let's start with the correct structure of the library:

libraries
|_ Test_Library
|_ library.properties
|_ examples
| |_ etc.
|_ src
|_ Test_Library.h
|_ core
|_ Func.h
|_ Func.cpp

## PlatformIO recognizes library headers only in subfolders

### platformio.ini

``` c++
[env]
lib_extra_dirs = ../../src
 
[platformio]
src_dir = .

[env:mkrwifi1010]
platform = atmelsam
board = mkrwifi1010
framework = arduino
```
