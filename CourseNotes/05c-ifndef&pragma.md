# Header Guards: `#ifndef` and `#pragma once`

When working with multiple files in C++, you may include the same header file more than once. If a header file is included multiple times during compilation, it can result in redefinition errors. Header guards prevent this by ensuring a header is only processed once.

---

## Using `#ifndef`, `#define`, `#endif`

This is the standard and portable way to guard a header file.

### Syntax

```cpp
#ifndef HEADER_NAME_H
#define HEADER_NAME_H

// contents of the header file

#endif // HEADER_NAME_H
```

This checks whether `HEADER_NAME_H` has been defined. If not, it defines it and includes the header contents. The next time the file is included, the definition will already exist and the contents will be skipped.

---

### Example: `Player.h`

```cpp
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    void update();
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape shape;
};

#endif // PLAYER_H
```

You can use any naming convention for the macro, but it is common to base it on the file name in all caps with underscores.

---

## Alternative: `#pragma once`

Most modern compilers support the simpler directive:

```cpp
#pragma once
```

This also ensures the file is only included once per compilation, without needing to define a macro.

---

### Example Using `#pragma once`

```cpp
#pragma once

#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    void update();
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape shape;
};
```

This approach is shorter, but less portable than traditional guards.

---

## When to Use Each

| Technique        | Portability     | Style               |
|------------------|------------------|----------------------|
| `#ifndef` guard  | Works with all C/C++ compilers | Recommended for cross-platform and collaborative work |
| `#pragma once`   | Supported by most modern compilers (GCC, Clang, MSVC) | Simpler, less cluttered |

---

## Best Practice

Use `#ifndef` in all `.h` files unless you are certain the compiler supports `#pragma once` and your project doesn't need maximum portability.
