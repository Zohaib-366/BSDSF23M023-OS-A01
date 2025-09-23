**Operating Systems – Programming Assignment 01**  
**Student:** Muhammad Zohaib (BSDSF23M023)  
**Instructor:** Dr. Muhammad Arif Butt  

---

## Feature 1: Project Scaffolding & Version Control

### Project Structure
```
BSDSF23M023-OS-A01/
├── src/         # Source code
├── include/     # Header files
├── lib/         # Libraries (.a, .so)
├── bin/         # Executables
├── obj/         # Object files
├── man/         # Man pages
└── REPORT.md    # This report
```

### Git Workflow
- Initialized repo with `README.md`.
- Created directories as required.
- Committed and pushed the structure to GitHub.

✅ Deliverables completed.

---

## Feature 2: Multi-file Project using Make Utility

### Q1. Linking rule explanation
Rule:  
```
$(TARGET): $(OBJECTS)
    $(CC) $(CFLAGS) -o $@ $^
```
- This links object files (`.o`) directly into an executable.  
- If we linked against a library, the rule would instead specify `-L` (library path) and `-l` (library name) instead of directly listing `.o` files.

### Q2. What is a Git tag? Difference between simple and annotated tags?
- A **Git tag** marks a specific commit as important (like a release).  
- **Simple tag:** just a pointer (lightweight).  
- **Annotated tag:** includes metadata (tagger, date, message). Best for official releases.

### Q3. Purpose of GitHub Release & attaching binaries?
- A **GitHub Release** provides packaged versions for users.  
- Attaching binaries (like `bin/client`) allows users to download and run the program without compiling.

✅ We created branch `multifile-build`, wrote Makefile, tested, tagged `v0.1.1-multifile`, and pushed release.

---

## Feature 3: Static Library

### Q1. Compare Makefiles of Part 2 and Part 3
- **Part 2:** Compiled all `.c` directly into one executable.  
- **Part 3:** Compiled `.c` into `.o`, archived into `lib/libmyutils.a`, then linked `main.c` with `-Llib -lmyutils`.

### Q2. Purpose of `ar` and `ranlib`
- `ar`: bundles object files into a static library (`.a`).  
- `ranlib`: generates an index for faster linking (sometimes optional).

### Q3. Running `nm` on `client_static`
- Functions like `mystrlen` appear in the executable.  
- This shows static linking **copies the library code** into the executable.

✅ We created branch `static-build`, built `libmyutils.a`, tested, tagged `v0.2.1-static`, and attached both binary + `.a` file in release.

---

## Feature 4: Dynamic Library

### Q1. What is Position-Independent Code (-fPIC)?
- `-fPIC` compiles code that can be loaded at any memory address.  
- Required for shared libraries (`.so`) so the OS can load them dynamically.

### Q2. File size difference between static and dynamic executables
- `client_static` is larger (library code is copied inside).  
- `client_dynamic` is smaller (only references library, code is loaded at runtime).  

### Q3. LD_LIBRARY_PATH
- An environment variable telling the loader where to search for `.so` files.  
- Without it, loader cannot find custom libraries.  
- Setting `export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH` fixed the issue.

✅ We created branch `dynamic-build`, built `libmyutils.so`, tested with `LD_LIBRARY_PATH`, tagged `v0.3.1-dynamic`, and released with both `.so` + executable.

---

## Feature 5: Man Pages & Install Target

### Work Done
- Created `man/man1/client.1` and `man/man3/*.3` for functions.  
- Added `install` target to Makefile → copies binary + man pages into system paths.  
- Tested with `sudo make install`, then verified:
  - `client` runs from anywhere.  
  - `man client` and `man mystrlen` display documentation.

✅ Branch `man-pages` merged, tagged `v0.4.1-final`, release created.

---

## Feature 6: Final Submission

### Git Workflow
- All branches (`multifile-build`, `static-build`, `dynamic-build`, `man-pages`) merged into `main`.  
- All branches + tags pushed to GitHub.

### Final Checklist
- Modular programming ✔  
- Static & dynamic libraries ✔  
- Makefiles (recursive, professional) ✔  
- Documentation with man pages ✔  
- Installation workflow ✔  
- Git branching, tagging, releases ✔  

---

# Conclusion
This assignment taught the complete professional C project workflow:
- From project scaffolding to building static/dynamic libraries.  
- From Git feature branching to annotated releases.  
- From writing Makefiles to installing binaries and man pages.  

**Final Release:** [v0.4.1-final](https://github.com/Zohaib-366/BSDSF23M023-OS-A01/releases/tag/v0.4.1-final)

