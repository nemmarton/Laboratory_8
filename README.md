# Laboratory_8

Tasks:

->Vertically

->Trimmer

->Values backwards

->Convert to upper case

->Line wrap

->Job assignments in a file 



# Memo: Strings and Files in C

## 1. Strings in C

- In C, a **string** is an array of characters ending with a special character `\0` (null terminator).
- Unlike other languages, strings are not a separate data type — they are just `char` arrays.

### Declaring and Initializing Strings
```c
char str1[6] = "Hello"; // {'H','e','l','l','o','\0'}
char str2[] = "World";   // compiler counts size automatically
```

- You must always leave space for the terminating `\0`!

### Accessing Characters
```c
printf("%c", str1[0]); // prints 'H'
```

### String Input and Output
```c
char name[50];
printf("Enter your name: ");
scanf("%s", name); // reads until whitespace, no & needed, name is a pointer already!
printf("Hello, %s!\n", name);
```

`scanf("%s", ...)` can cause buffer overflows. Prefer `fgets` in production:


### String Library Functions (`<string.h>`)
- `strlen(s)` – length of string
- `strcpy(dest, src)` – copy string
- `strcat(dest, src)` – append string
- `strcmp(s1, s2)` – compare strings alphabetically (0 if equal)

Example:
```c
if (strcmp(str1, str2) == 0) {
    printf("Strings have same content!\n");
}
```

---

## 2. Files in C

- C provides file handling functions in `<stdio.h>`.
- A **file pointer** (`FILE *`) is used to work with files.
- It is nothing else, but a pointer to a FILE structure defined in the header

### Opening a File
```c
FILE *fp;
fp = fopen("data.txt", "r"); // open for reading
if (fp == NULL) {
    printf("File not found!\n");
    return 1;
}
```

- Modes:
  - `"r"` – read
  - `"w"` – write (creates/overwrites)
  - `"a"` – append
  - 
### Reading from a File
```c
char line[100];
while (fgets(line, sizeof(line), fp)) {//becomes false on EOF
    printf("%s", line);
}
```
You can use fscanf() also!
### Writing to a File
```c
FILE *fp = fopen("output.txt", "w");
if (fp == NULL) return 1;

fprintf(fp, "Hello, file!\n");
fputs("Another line.\n", fp);

fclose(fp);
```



### Closing a File
```c
fclose(fp);
```
Always close files to save data properly.

---

## 3. Example: Copy File Content
```c
#include <stdio.h>

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("copy.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    char c;
    while ((c = fgetc(in)) != EOF) {
        fputc(c, out);
    }

    fclose(in);
    fclose(out);
    return 0;
} //homework: Same with fscanf() and fprintf()!
```

---

