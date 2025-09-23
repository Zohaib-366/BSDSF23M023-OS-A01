# BSDSF23M023-OS-A01 REPORT

## Feature 2: Multi-file Compilation

**Objective:**  
Compile a C program split across multiple source files into a single executable using a Makefile.  

**Project Structure:**


BSDSF23M023-OS-A01/
├── src/
│ ├── main.c
│ ├── mystrfunctions.c
│ └── myfilefunctions.c
├── include/
│ ├── mystrfunctions.h
│ └── myfilefunctions.h
├── obj/
├── bin/
│ └── client
├── Makefile
├── test.txt


**Key Points in Makefile:**
- `CC = gcc` and `CFLAGS = -Wall -Iinclude` for compiler and include path.
- `SRCS = $(wildcard src/*.c)` collects all `.c` files.
- `OBJS` maps source files to object files.
- `all: $(TARGET)` defines the default target.
- Object files are compiled using `$(CC) $(CFLAGS) -c $< -o $@`.
- Executable is linked from object files using `$(CC) $(CFLAGS) -o $@ $^`.
- `clean` target removes `.o` files and executable.

**Workflow:**
1. Create branch `multifile-build`.
2. Write `mystrfunctions.c` and `myfilefunctions.c` implementing string and file functions.
3. Write `main.c` to test all functions.
4. Build with `make`, producing `bin/client`.
5. Test program output to verify correctness.
6. Commit changes, create tag `v1.0-multifile`, push, and draft GitHub release with binary attached.

**Observations:**
- Linking uses all object files directly.
- Adding new source files requires updating the Makefile or using wildcard patterns.
- Simple and effective for small projects.

---

## Feature 3: Static Library Build

**Objective:**  
Refactor the project to use a static library (`libmyutils.a`) for utility functions, making the project scalable.

**Project Structure:**


BSDSF23M023-OS-A01/
├── lib/
│ └── libmyutils.a
├── bin/
│ └── client_static
├── obj/
│ ├── main.o
│ ├── mystrfunctions.o
│ └── myfilefunctions.o
├── src/
│ ├── main.c
│ ├── mystrfunctions.c
│ └── myfilefunctions.c


**Key Points in Makefile:**
- `LIB = lib` directory holds `libmyutils.a`.
- `LIB_OBJS` lists object files to be archived.
- Static library created with:


$(STATIC_LIB): $(LIB_OBJS) | $(LIB)
ar rcs $@ $(LIB_OBJS)

- `TARGET` links only `main.o` with `libmyutils.a`:


$(TARGET): $(MAIN_OBJ) $(STATIC_LIB) | $(BIN)
$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ) $(STATIC_LIB)

- Object files for library are compiled separately.

**Workflow:**
1. Merge `multifile-build` into `main`.
2. Create branch `static-build`.
3. Compile library object files and create `lib/libmyutils.a` using `ar`.
4. Link `main.o` with `libmyutils.a` to create `bin/client_static`.
5. Test program output to verify correctness.
6. Commit changes, create tag `v0.2.1-static`, push, and draft GitHub release with both library and executable attached.

**Observations & Answers:**
1. **Key differences from Feature 2 Makefile:**
 - Feature 2: executable linked directly from all object files.
 - Feature 3: utility functions are bundled into a static library and linked separately.  
 - New variables: `LIB`, `STATIC_LIB`, `LIB_OBJS`, `LIB_SRCS`.
 - New rules: build static library using `ar rcs`.

2. **Purpose of `ar` and `ranlib`:**
 - `ar` archives multiple object files into a single library (`.a` file).
 - `ranlib` updates the library index for faster linking (often optional on modern systems).

3. **Symbol check using `nm`:**
 - `nm bin/client_static` shows `mystrlen`, `mystrcpy`, etc., are included in the executable.
 - Indicates **static linking** copies function code into the executable.

---

**Conclusion:**
- Feature 2 demonstrates basic multi-file compilation.
- Feature 3 shows how to modularize code with a static library for scalability.
- Git workflow, tags, and releases document progress and provide versioned snapshots.
Feature 4: Dynamic Library Build

Objective:
Enhance the project by building and linking against a dynamic library (libmyutils.so). Unlike static linking, where function code is copied into the executable, dynamic linking keeps the executable smaller and allows the library to be shared by multiple programs at runtime.

Project Structure (New Files/Changes):

BSDSF23M023-OS-A01/
├── lib/
│   ├── libmyutils.a
│   └── libmyutils.so       # NEW: Shared library
├── bin/
│   ├── client_static
│   └── client_dynamic      # NEW: Executable using dynamic linking
├── src/
│   ├── main.c
│   ├── mystrfunctions.c
│   └── myfilefunctions.c
├── include/
│   ├── mystrfunctions.h
│   └── myfilefunctions.h
├── Makefile (updated)


Key Points in Makefile:

Added rules to compile Position-Independent Code (PIC) objects with -fPIC.

New target to build the shared library:

$(DYNAMIC_LIB): $(LIB_OBJS) | $(LIB)
	$(CC) -shared -o $@ $(LIB_OBJS)


New executable rule to link against libmyutils.so:

$(DYNAMIC_TARGET): $(MAIN_OBJ) $(DYNAMIC_LIB) | $(BIN)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ) -L$(LIB) -lmyutils


Workflow:

Created branch dynamic-build from main.

Modified Makefile for dynamic library build.

Built shared library:

gcc -fPIC -c src/mystrfunctions.c -o obj/mystrfunctions.o
gcc -fPIC -c src/myfilefunctions.c -o obj/myfilefunctions.o
gcc -shared -o lib/libmyutils.so obj/mystrfunctions.o obj/myfilefunctions.o


Linked main.o against libmyutils.so to produce bin/client_dynamic.

Verified executable size difference:

ls -lh bin/
-rwxr-xr-x ... client_static   (~bigger)
-rwxr-xr-x ... client_dynamic  (~smaller)


→ The dynamic client is smaller because it references functions at runtime instead of embedding them.

Initial run of ./bin/client_dynamic failed with:

error while loading shared libraries: libmyutils.so: cannot open shared object file


Fixed by setting LD_LIBRARY_PATH:

export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH
./bin/client_dynamic


→ Executed successfully, producing correct output.

Verified linking with ldd bin/client_dynamic:

libmyutils.so => ./lib/libmyutils.so
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6
...


Committed changes with message:

git commit -m "Added dynamic library build: client_dynamic with libmyutils.so"


Created annotated tag:

git tag -a v0.3.1-dynamic -m "Dynamic Library Build"
git push origin v0.3.1-dynamic


Drafted GitHub release Version 0.3.1: Dynamic Library Build with assets:

bin/client_dynamic

lib/libmyutils.so

Report Questions & Answers

1. What is Position-Independent Code (-fPIC) and why is it fundamental for shared libraries?

Position-Independent Code is machine code that executes correctly regardless of its memory load address.

Shared libraries (.so) may be loaded at different addresses in different processes, so they must not assume a fixed address.

-fPIC ensures all memory accesses are relative, making the code relocatable.

2. Explain the difference in file size between static and dynamic clients. Why does this difference exist?

client_static is larger because all library function code is copied directly into the executable.

client_dynamic is smaller because it only stores references to library functions. At runtime, the shared library is loaded into memory and linked dynamically.

3. What is the LD_LIBRARY_PATH environment variable? Why was it necessary to set it?

LD_LIBRARY_PATH tells the dynamic loader where to search for .so files before system paths.

Without setting it, the loader could not find ./lib/libmyutils.so.

This shows that the OS loader’s job is to resolve symbols and locate required shared libraries at runtime.
