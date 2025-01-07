In C programming, **data types** are used to define the type of data a variable can hold. They determine the **size** and **range** of values that can be stored. C provides several categories of data types:  

---

## **1. Primary (Basic) Data Types**
These are the fundamental data types used to declare variables.  

| **Type**   | **Size (bytes)** | **Range**                                |
|-----------|-------------------|------------------------------------------|
| `char`    | 1                 | -128 to 127 (signed) or 0 to 255 (unsigned) |
| `int`     | 2 or 4            | -32,768 to 32,767 (2 bytes) or larger    |
| `float`   | 4                 | 3.4E-38 to 3.4E+38                       |
| `double`  | 8                 | 1.7E-308 to 1.7E+308                     |
| `_Bool`   | 1                 | 0 (false) or 1 (true)                    |

### Example:
```c
char ch = 'A';
int num = 100;
float pi = 3.14;
double largeNum = 12345.6789;
```

---

## **2. Derived Data Types**
Derived data types are created using the **basic data types**.  

### **(a) Arrays**
- **Definition:** A collection of elements of the same type stored in contiguous memory.  
- **Example:**
  ```c
  int arr[5] = {1, 2, 3, 4, 5}; // Integer array
  char str[] = "Hello";        // Character array (string)
  ```

### **(b) Pointers**
- **Definition:** Variables that store the **memory address** of another variable.  
- **Example:**
  ```c
  int x = 10;
  int *ptr = &x; // Pointer to an integer
  printf("%d", *ptr); // Dereference to get the value
  ```

### **(c) Structures (`struct`)**
- **Definition:** A collection of **different data types** grouped together.  
- **Example:**
  ```c
  struct Student {
      char name[20];
      int age;
      float marks;
  };
  struct Student s1 = {"John", 20, 85.5};
  ```

### **(d) Unions (`union`)**
- **Definition:** Similar to structures, but members **share the same memory location**.  
- **Example:**
  ```c
  union Data {
      int i;
      float f;
  };
  union Data d1;
  d1.i = 10; // Shares memory
  ```

---

## **3. Enumeration (enum)**
An **enumeration** is a user-defined data type that assigns names to integer constants.  

### Example:
```c
enum Color {RED, GREEN, BLUE};
enum Color c = GREEN; // GREEN = 1
```

---

## **4. Void Type (`void`)**
- **Definition:** Represents **no value** or **no type**.  
- **Usage:**
  1. **Function without return type:**
     ```c
     void printMessage() {
         printf("Hello");
     }
     ```
  2. **Pointer to unspecified data type:**
     ```c
     void *ptr;
     ```

---

## **5. Type Modifiers**
Type modifiers alter the **size** and **sign** of basic data types.  

| Modifier      | Description                                           |
|---------------|-------------------------------------------------------|
| `signed`      | Allows storing **positive** and **negative** values.  |
| `unsigned`    | Stores **only positive** values (doubles range).      |
| `short`       | Reduces size for smaller numbers (e.g., `short int`). |
| `long`        | Increases size for larger numbers (e.g., `long int`). |

### Example:
```c
unsigned int x = 100; // Only positive
long int y = 1000000; // Larger range
```

---

## **6. User-Defined Data Types**
### **(a) `typedef`**
- Allows defining **aliases** for existing data types.  
- **Example:**
  ```c
  typedef unsigned int uint;
  uint age = 25; // Equivalent to unsigned int
  ```

### **(b) `struct` and `enum`**
Already mentioned above.

---

## **7. Boolean Type**
- Introduced in **C99** as `_Bool`.  
- **Requires `stdbool.h` for `bool`.**  
- **Example:**
  ```c
  #include <stdbool.h>
  bool isTrue = true; // 'true' and 'false' keywords
  ```

---

### **Summary Table of Categories**
| **Category**       | **Examples**                                       |
|--------------------|---------------------------------------------------|
| Primary Types      | `char`, `int`, `float`, `double`, `_Bool`         |
| Derived Types      | Arrays, Pointers, Structures, Unions              |
| Enumeration        | `enum Color {RED, GREEN, BLUE}`                   |
| Void Type          | `void` (No value or unspecified data)             |
| Type Modifiers     | `signed`, `unsigned`, `short`, `long`             |
| User-Defined Types | `typedef`, `struct`, `enum`                       |

