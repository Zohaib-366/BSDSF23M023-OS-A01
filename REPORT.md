# OS Assignment 1 – Utility Library  

**Roll No:** BSDSF23A001  
**Name:** Muhammad Zohaib  
**Course:** Operating Systems  
**Assignment:** A01  

---

## Feature-1: Project Scaffolding and Version Control  

### Step 1: Repository Creation  
- Created a new GitHub repository named **BSDSF23A001-OS-A01** (public).  
- Initialized repository with:  
  - `README.md` (basic project description)  
  - `.gitignore` (C template to ignore compiled files, binaries, and object files)  
  - `LICENSE` (MIT License for open-source usage)  

---

### Step 2: Cloning the Repository  
Cloned repository to local Linux machine:  

```bash
git clone <repo-link>
cd BSDSF23A001-OS-A01
# Step 3: Project Structure

**Created the following hierarchy using shell commands:**

```bash
mkdir src include lib bin obj
touch REPORT.md
```

**Final structure:**

```
BSDSF23A001-OS-A01/
├── src/       # Source code for library and application
├── include/   # Header files
├── lib/       # Compiled static and dynamic libraries
├── bin/       # Final executable programs
├── obj/       # Intermediate object files
└── REPORT.md  # Analysis report (maintained step by step)
```

**Verification (example):**

```bash
ls -R
# or,:tree -L 1
```


## Feature-2: Multi-file Project using Make Utility
### Linking Rule in Makefile

In our Makefile, the main linking rule is:

```make
$(TARGET): $(OBJECTS)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
$(TARGET) is the final executable (bin/client).

$(OBJECTS) are all the compiled object files (obj/main.o obj/mystrfunctions.o obj/myfilefunctions.o).

This rule tells make to link all object files into the final executable.

Difference from linking against a library:
When linking with a library, instead of using all object files directly, you link against a precompiled .a or .so library. This allows reuse of code without recompiling everything.

### Git Tags and Annotated Tags

**Git Tag:**  
A git tag is a reference to a specific commit, typically used to mark release points in the project history.

**Annotated Tag (`-a`):**  
- Created with `git tag -a <tagname> -m "message"`.  
- Stores metadata: tagger name, email, date, and a message.  
- Useful for releases because it preserves context about the version.

**Lightweight (simple) Tag:**  
- Created with `git tag <tagname>`.  
- Just points to a commit, with no extra metadata.  
- Useful for quick references, not for formal releases.

**Why tags are useful:**  
- Easily reference a specific version of your code.  
- Helps in version control and collaboration.  
- Makes it simple to create GitHub releases from a specific commit.

### GitHub Releases

**Purpose of a GitHub Release:**  
- A release is a snapshot of the project at a specific point in time, usually tied to a tag.  
- Helps users and collaborators download stable versions of the project.  
- Can include release notes, descriptions, and compiled binaries for convenience.

**Steps Taken in This Project:**  
1. Created an annotated tag `v1.0-multifile` for the first multi-file build.  
2. Drafted a new release on GitHub using this tag.  
3. Added a descriptive title: `Version 1.0: Multi-file Build`.  
4. Included a brief description:  
   *“A simple, directly compiled executable from all source files, testing string and file functions.”*  
5. Attached the compiled executable `bin/client` as a binary asset.  
6. Published the release publicly.

**Significance of Attaching Binaries:**  
- Provides users immediate access to the compiled executable without needing to build the project.  
- Ensures the exact tested version is available for download and use.  
- Supports reproducibility and stable distribution of the software.

