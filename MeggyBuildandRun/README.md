# MeggyBuildandRun
Makefile and C++ run-time library for running on devices, MJ.jar, MJSIM.jar, examples, and Java-only run-time library.

## Building and Uploading .cpp or .s files to Meggy
1. The Arduino IDE is already installed on the Macs in G-S 930 and 228. 
Look in the applications folder, find Arduino, and open it.
2. Plug in your MeggyJr cable. In the Arduino application, look under the Tools menu to see what the port is called for your cable (e.g., /dev/cu.usbserial-XXXXXXX).  IMPORTANT: the black wire should be closest
to the screen on the device.
3. Edit the port name in the Makefile to match your port.
4. Follow the directions at the top of the Makefile file to 
compile the example and install it on your Meggy Jr device.


## Use the reference compiler to compile a MeggyJava program

The reference compiler compiles MeggyJava code to AVR assembly, 
which is what your compilers will be doing as well. 
It can be helpful to use the reference compiler on 
your test cases to see what code it generates.
To try out the reference compiler in your
clone of the MeggyBuildandRun repository type the following:
```
    java -jar MJ.jar PA5Cylon.java
```
This will generate a PA5Cylon.java.s file, which you can then 
compile and upload to the Meggy Jr using the provided Makefile.

## AVR simulator and MeggyJr emulator

The MJSIM.jar program enables you to step through an
AVR assembly code file and visualize what impact it
will have on the MeggyJr.  It has a GUI mode or a batch mode.
```
    java -jar MJSIM.jar -f PA5Cylon.java.s
    java -jar MJSIM.jar -b -f PA5Cylon.java.s
```


## Trying out more MeggyJr examples using Arduino

1. Download MeggyJrRGBv15.zip from (https://github.com/evil-mad/MeggyJrRGB/releases/download/v1.5/MeggyJrRGBv15.zip).
2. Exit out of Arduino application.
3. Put the unzipped folder into the location `/home/your-user-name/Documents/Arduino/libraries`.
4. Remove all the files in the unzipped MeggyJrRGB folder that start with a "._" (for example ._MeggyJr.cpp). Do this on the command line because files that start with a "." might be hidden in the finder.
5. Restart the Arduino application.
6. You should be able to open the MeggyJr examples. 
For instance, try 
File->Examples->MeggyJrRGB->MeggyJr-Attack in the Arduino application. 
