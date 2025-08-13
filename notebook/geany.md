# 🛠️ Geany Useful Commands and Settings (Ubuntu)

A handy reference for managing files, compiling, and running tests efficiently when working with C++ in **Geany** on **Ubuntu**.

# Commands Geany

### Compile with Warnings (F8)
```bash
g++ -std=gnu++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra -D_GLIBCXX_DEBUG -c "%f"
```

### Build (F9)
```bash
g++ -std=gnu++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra -D_GLIBCXX_DEBUG -o "%e" "%f"
```

### Execute All Tests and Save Output in a File (F5)
> If the file is named `problem.cpp`. The tests have to be `problem*.in` and the output will be saved in `problem.out`
```bash
> "%e".out; for x in "./%e"*.in ; do echo "$(basename "$x")"  >> "%e".out ; "./%e" < "$x" >> "%e".out 2>&1 ; echo "==========================" >> "%e".out ; done
```

### Generate a `.in` File for Testing  
```bash
"./%e" > "%e".in
```

### Execute All Tests
```bash
for x in "./%e"*.in ; do
    echo "$(basename "$x")"
    "./%e" < "$x"
    echo "=========================="
done
```

# Commands

### Delete Executables in the Current Directory
```bash
find . -maxdepth 1 -type f -executable -exec rm -f {} \;
```

### Find All Executable Files (Current Directory + Subdirectories)
```bash
find . -type f -executable
```

### Delete All Executable Files (Current Directory + Subdirectories)
```bash
find . -type f -executable -delete
```
### Find All `.in` Files (Current Directory + Subdirectories)
```bash
find . -type f -name "*.in"
```

### Delete All `.in` Files
```bash
find . -type f -name "*.in" -delete
```

### Compare Two Output Files  
> No output means the files are equal.
```bash
diff file_name.out file_name2.out
```