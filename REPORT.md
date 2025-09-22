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

