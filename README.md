### CMake project for CLion

**Importing**
 
- Just **git clone** & **File -> Import Project...** or **Import Project from Sources** in CLion


**Programming:**

- Use AVR USB ISP dongle. 


**Project rename:** 

- Change ```_PROJECT(avr-mcu-clion-template)_``` to ```_PROJECT(your-project-name-here)_``` in _CMakeLists.txt_ file.

- Change hex filename in upload.sh script in scripts folder.

**Building:**

- Go to project root folder

- Run command from console: ```cmake .```
- Then run command from console: ```make```