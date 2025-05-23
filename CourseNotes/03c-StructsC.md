# Structures and Unions in C

C provides compound data types to group multiple values under one name:

- **Structures**: group values of different types
- **Unions**: share memory between multiple values (only one active at a time)

---

## Structures

A `struct` groups related values of different types.

```c
struct stock {
    char id[20];
    int shares;
    int whole;
    int numer;
    int denom;
    float value;
};
```

---

## Declaring and Accessing Fields

```c
struct stock my_stock;

my_stock.shares = 100;
my_stock.value = 150.25;

printf("Shares: %d\n", my_stock.shares);
```

---

## Nested Structures

```c
struct price {
    int whole;
    int numer;
    int denom;
};

struct stock {
    char id[20];
    int shares;
    struct price buying;
    struct price selling;
    float value;
};

my_stock.buying.whole = 11;
my_stock.selling.denom = 4;
```

---

## Pointers and the `->` Operator

```c
struct stock *ptr = &my_stock;
ptr->shares = 75;  // same as (*ptr).shares = 75
```

---

## Arrays of Structures

```c
struct stock folio[100];

folio[0].shares = 57;
folio[1].buying.whole = 13;
```

---

## `typedef struct`

Using `typedef` simplifies structure syntax by creating an alias.

### Without `typedef`

```c
struct stock {
    int shares;
};

struct stock s1;
```

### With `typedef`

```c
typedef struct {
    int shares;
} Stock;

Stock s1;
```

You can also typedef the name explicitly:

```c
typedef struct stock {
    int shares;
    float price;
} Stock;
```

---

## `union` in C

A `union` allows different fields to **share the same memory**. Only one field can be used at a time.

### Example

```c
union number {
    int i;
    float f;
};

union number n;
n.i = 5;
printf("int: %d\n", n.i);

n.f = 3.14;
printf("float: %f\n", n.f);
```

Assigning to `n.f` **overwrites** the value of `n.i`.

---

### When to Use `union`

- Memory-constrained environments
- Representing a value that could be of multiple types
- Efficient data representation (e.g., protocol headers)

---

## Comparison: `struct` vs `union`

| Feature         | `struct`                    | `union`                    |
|------------------|-----------------------------|----------------------------|
| Memory usage     | Sum of all fields           | Size of largest field      |
| Field access     | All fields usable at once   | Only one field at a time   |
| Use case         | Group different data        | Share memory for different options |

---

## Access Patterns Recap

| Context               | Syntax           |
|------------------------|------------------|
| Struct field           | `s.field`        |
| Struct pointer         | `p->field`       |
| Array of structs       | `a[i].field`     |
| Nested struct          | `s.sub.field`    |
| Typedef struct         | `S s;`           |
| Union field            | `u.field`        |

---
