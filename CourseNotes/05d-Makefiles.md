# Makefiles and Build Automation in C++

When building C++ programs with multiple `.cpp` and `.h` files, typing the full compiler command every time becomes tedious and error-prone. **Makefiles** allow you to automate this process with a single `make` command.

---

## Compiling Without Makefiles

### Example 1: One-file program

```bash
g++ hello.cpp -o hello
```

If you make changes to `hello.cpp`, you must rerun this manually. As projects grow, this becomes hard to manage.

---

## Makefile: Automating the Build

A `Makefile` tells `make`:
- **how to build your program**
- **what files depend on each other**

---

### Example 2: Basic Makefile

Assume you have:

```cpp
// file: hello.cpp
#include <iostream>
int main() {
    std::cout << "Hello, world!\n";
    return 0;
}
```

Create a file named `Makefile`:

```makefile
hello: hello.cpp
	g++ hello.cpp -o hello
```

Now run:

```bash
make
```

It will only recompile `hello.cpp` **if it has changed**.

---

## Variables in Makefiles

Makefiles support variables to reduce duplication.

### Example 3: Using Variables

```makefile
CXX = g++
CXXFLAGS = -Wall -std=c++17

hello: hello.cpp
	$(CXX) $(CXXFLAGS) hello.cpp -o hello
```

---

## Multi-File Projects

Now assume a project with multiple source files:

```
.
├── main.cpp
├── utils.cpp
├── utils.h
```

### Example 4: Compiling multiple files

```makefile
CXX = g++
CXXFLAGS = -Wall -std=c++17

SRC = main.cpp utils.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
```

---

## Explanation of Rules

```makefile
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)
```

This links all object files into a single executable.

```makefile
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
```

This rule says: for every `.cpp` file, compile it into a `.o` file.

---

## SFML Project Makefile

In SFML Module 2, we used this Makefile:

```makefile
CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp Player.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
```

This builds an executable called `game` from `main.cpp` and `Player.cpp`, linking it with SFML libraries.

---

## Expanding the Makefile

To add more files:

1. Add new `.cpp` files to the `SRC` list:

```makefile
SRC = main.cpp Player.cpp Button.cpp Game.cpp
```

2. No need to touch the rest — the pattern rules will generate `.o` files for each source file automatically.

3. Add any SFML or other library flags to `LDFLAGS`.

---

## Summary of Key Concepts

| Term         | Meaning                                  |
|--------------|-------------------------------------------|
| `make`       | Builds the project using a Makefile       |
| `TARGET`     | The name of the output executable         |
| `SRC`        | List of `.cpp` source files               |
| `OBJ`        | Corresponding `.o` object files           |
| Pattern rule | `%` is a wildcard for matching filenames  |
| `clean`      | Deletes compiled files                    |

This Makefile setup will work for most C++ projects you'll write in this course, including SFML-based projects.
