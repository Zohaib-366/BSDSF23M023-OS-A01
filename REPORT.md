At this point, Feature 3 (Static Library Build) is fully complete:

main.c links against lib/libmyutils.a

Makefile is updated for static library creation

Executable bin/client_static works correctly

Git workflow: static-build branch created, committed, and merged

Tag v0.2.1-static created and pushed

GitHub release drafted with client_static and libmyutils.a attached

Your assignment now has Feature 1 (single-file), Feature 2 (multi-file), and Feature 3 (static library) fully implemented and versioned.

The next steps are:

Prepare REPORT.md combining Features 2 and 3 with explanations.

Ensure your Makefile and project structure are documented clearly in the report.

If you want, I can draft a complete REPORT.md covering everything so you can submit it immediately. Do you want me to do that next?

You said:
ok 
ChatGPT said:

Great! Let’s draft a complete REPORT.md for your assignment, covering Features 2 (Multi-file Build) and 3 (Static Library Build). I’ll keep it clear, structured, and ready for submission.

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
