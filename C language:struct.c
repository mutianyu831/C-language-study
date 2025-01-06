In C language, a **struct** (short for structure) is a user-defined data type that groups different types of variables (called members or fields) together under a single name. This allows you to store and manage related data more effectively, even if the data types of those variables are different.

### Basic Syntax:
```c
struct StructureName {
    dataType member1;
    dataType member2;
    // ... more members
};
```

### Key Points:
1. **Definition**: A structure is defined using the `struct` keyword followed by the name of the structure and a block containing the members.
   
2. **Members**: The members of a structure can be of different data types, such as `int`, `float`, `char[]`, etc.

3. **Accessing Members**: To access the members of a structure, we use the dot (`.`) operator if working with a structure variable.

4. **Creating Structure Variables**: You can create variables of the defined structure type.

### Example of a Simple Structure:
Here’s an example that defines a structure to store information about a `Book`:

```c
#include <stdio.h>

struct Book {
    char title[100];
    char author[100];
    int year;
    float price;
};

int main() {
    // Create a structure variable
    struct Book book1;
    
    // Assign values to the structure members
    strcpy(book1.title, "The C Programming Language");
    strcpy(book1.author, "Brian W. Kernighan and Dennis M. Ritchie");
    book1.year = 1978;
    book1.price = 29.95;

    // Access and print the values
    printf("Book Title: %s\n", book1.title);
    printf("Author: %s\n", book1.author);
    printf("Year: %d\n", book1.year);
    printf("Price: $%.2f\n", book1.price);

    return 0;
}
```

### Explanation:
- `struct Book` defines the structure with 4 members: `title`, `author`, `year`, and `price`.
- In `main()`, we create a variable `book1` of type `struct Book`.
- The `strcpy` function is used to copy strings into `title` and `author` because `title` and `author` are character arrays (strings).
- We use the dot operator `.` to access each member and print their values.

### More Advanced Use:
Structures can also be used with pointers, arrays, and functions. Here's an example with a pointer to a structure:

```c
#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    // Declare a structure variable
    struct Point point1 = {5, 10};
    
    // Declare a pointer to the structure
    struct Point *ptr = &point1;

    // Access members using the pointer
    printf("x: %d, y: %d\n", ptr->x, ptr->y);  // Use '->' to access members via pointer

    return 0;
}
```

### Key Takeaways:
- **Pointer and Member Access**: When working with pointers to structures, use the `->` operator instead of the dot operator (`.`).
- **Structures in Functions**: You can pass structures to functions by value or by reference (using pointers).

This basic structure allows you to model real-world entities with different attributes, making your code much more organized and manageable.
