# Prerequisites for Running the Assembly Program:

1. **Virtual Box with Lubantu:**
   - Ensure you have VirtualBox installed on your system.
   - Download and set up a Lubantu (Linux Ubuntu-based distribution) virtual machine within VirtualBox.

2. **NASM x86/x64 Assembler:**
   - Install NASM (Netwide Assembler) on your Lubantu system.
   - This can typically be done using the package manager.
     ```
     sudo apt-get update
     sudo apt-get install nasm
     ```

3. **joey_lib_io_v9_release.asm Library:**
   - Ensure it is in the same directory as your main assembly program or in a location accessible during assembly/linking.

4. **libasm_io-master:**
   - Download and set up [libasm_io-master](https://github.com/Teriks/libasm_io).
   - This library contains support files required by the main program.
   - Follow the steps mentioned in Readme.md to set up.

5. **Assembler and Linker:**
   - Set up an appropriate build system that uses the NASM assembler and linker (gcc) to build the assembly program.

## Commands to Run the Code:
- **To Build:**
```nasm -g -f elf64 -o test-io.o final.asm```
- **To Link:**
```gcc test-io.o /usr/lib/libasm_io.a -no-pie -o test-io```
(Replace `/usr/lib/libasm_io.a` with the actual location of `libasm_io.a` file)




## Code file

final.asm is the code file

## Report
Report.doc is the report file

## Testing
log.txt contains the logs of the test run.
#   Z O O _ M A N A G E M E N T _ A P P  
 #   Z O O _ M A N A G E M E N T _ A P P  
 