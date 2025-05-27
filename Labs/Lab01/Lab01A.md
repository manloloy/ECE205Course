## Lab 01A: Bash + vi + Hello World in C and C++

### Objective

- Practice basic Unix terminal commands
- Use `vi` to edit files
- Compile and run basic C and C++ programs

### Tasks

1. Open your terminal.
2. Navigate to your home directory:
   ```bash
   cd ~
   ```
3. Create a directory for all your labs:
   ```bash
   mkdir labs
   cd labs
   ```
4. Create a directory for this lab:
   ```bash
   mkdir Lab01
   cd Lab01
   ```
5. Create a file called `hello.c` using `vi`:
   ```bash
   vi hello.c
   ```
6. Press `i` to enter insert mode. Type or paste the following code:

```c
#include <stdio.h>

int main() {
    printf("Hello, world!\n");
    return 0;
}
```

7. Press `Esc`, then type `:wq` to save and quit.
8. Compile your program:
   ```bash
   gcc hello.c -o hello
   ```
9. Run it:
   ```bash
   ./hello
   ```

Repeat the same steps for `hello.cpp`:

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}
```

Compile and run:
```bash
g++ hello.cpp -o hello_cpp
./hello_cpp
```

---


