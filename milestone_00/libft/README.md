# Libft

> Reimplementing the C Standard Library from scratch.

## 📖 About the Project

**Libft** was my first project in the 42 Common Core and the one that established the foundations for everything that followed.

The objective was not simply to recreate existing C library functions, but to understand **how they work internally**. Every function had to be implemented from scratch while following the 42 coding standard (The Norm), with special attention to memory management, modularity, and code quality.

By the end of the project, I had built my own static library containing dozens of reusable functions that became an essential dependency for many later projects, including **ft_printf**, **get_next_line**, **push_swap**, **minishell**, and others.

---

# 🎯 Objectives

During this project I learned to:

- Understand pointers and pointer arithmetic
- Work safely with dynamic memory
- Manipulate strings and memory blocks
- Implement linked lists
- Write reusable utility functions
- Organize code into modules
- Build static libraries with Makefiles
- Follow strict coding standards

---

# 📂 Project Structure

```text
libft/
│
├── includes/
│   └── libft.h
│
├── src/
│   ├── libc/
│   ├── strings/
│   ├── memory/
│   ├── conversions/
│   ├── output/
│   └── bonus/
│
├── Makefile
└── README.md
```

---

# ⚙️ Compilation

Compile the library with:

```bash
make
```

Compile bonus functions:

```bash
make bonus
```

Clean object files:

```bash
make clean
```

Remove everything:

```bash
make fclean
```

Recompile:

```bash
make re
```

---

# 📚 Function Categories

I organized the library into several groups of functions.

## Character functions

```c
ft_isalpha()
ft_isdigit()
ft_isalnum()
ft_isascii()
ft_isprint()
ft_toupper()
ft_tolower()
```

These functions classify or transform characters.

---

## String manipulation

```c
ft_strlen()
ft_strdup()
ft_strjoin()
ft_strtrim()
ft_split()
ft_substr()
```

These functions manipulate C strings safely while handling memory allocation correctly.

Example:

```c
char *name = ft_strjoin("Karen", " Pineda");

// Result
Karen Pineda
```

---

## Memory manipulation

```c
ft_memset()
ft_bzero()
ft_memcpy()
ft_memmove()
ft_memchr()
ft_memcmp()
```

These functions operate directly on memory instead of null-terminated strings.

Memory example:

Before

```
+----+----+----+----+
| A  | B  | C  | D  |
+----+----+----+----+
```

After

```c
ft_memset(buffer, 'X', 4);
```

```
+----+----+----+----+
| X  | X  | X  | X  |
+----+----+----+----+
```

---

## Memory allocation

Functions such as

```c
ft_calloc()
```

allocate memory dynamically.

```
malloc()

Memory

+------+------+------+------+
| ???? | ???? | ???? | ???? |
+------+------+------+------+

calloc()

+------+------+------+------+
|  0   |  0   |  0   |  0   |
+------+------+------+------+
```

Understanding the difference between these functions was essential for avoiding undefined behavior.

---

# 🔗 Bonus: Linked Lists

One of the most valuable parts of Libft was implementing singly linked lists.

```
+------+      +------+      +------+
|data  | ---> |data  | ---> |data  | ---> NULL
+------+      +------+      +------+
```

I implemented functions to:

- create nodes
- add nodes
- iterate through the list
- delete nodes
- clear the entire list
- map functions over a list

This was my first experience working with dynamic data structures in C.

---

# 💡 What I Learned

Libft completely changed the way I understood C.

Instead of relying on the standard library, I had to build my own implementations and understand every pointer movement, every memory allocation, and every edge case.

More importantly, I learned that writing code is only part of software development. Designing reusable functions, organizing a project, handling errors correctly, and maintaining readability are equally important.

Although Libft was my first project at 42, it quickly became the backbone of almost every project I developed afterwards.

---

# 🚀 Final Thoughts

Looking back, Libft was much more than a collection of utility functions.

It was the project that taught me how C really works under the hood and gave me the confidence to tackle more complex challenges such as **ft_printf**, **get_next_line**, **minishell**, and **webserv**.