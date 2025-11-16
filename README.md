# Postfix Expression Converter (C++ Data Structures Project)

## Overview:
Console-based program that converts infix expressions using the four basic arithmetic operators, implemented with array and linked-list-based stacks in C++. This project demonstrates how stacks can be used to evaluate arithmetic expressions and shows the differences between static array and dynamic linked-list implementations. It reinforces understanding of the Stack ADT, operator precedence, and memory management in C++.

--- 

## Features 
- Convert infix expressions to postfix notation
- Evaluate arithmetic expressions using a stack
- Implements two stack models:
  - **ArrayStack** — static array-based implementation
  - **LinkedStack** — dynamic linked list implementation
- Demonstrates templates, class inheritance, and object-oriented design
- Modular and efficient memory management

---

## Installation: 
1. Clone the repository
``` bash
git clone https://github.com/1106-Guillebeau-Georgia/Postfix-Expression-Converter-CPP-Data-Structures-Project.git
```

2. Compile the program
``` bash
make
```

---

## Usage
After compiling the program, run it from the console:
```bash
./driver
```

Example Output:
```text
1. Convert Infix Expression
0. Exit
1
Enter an infix expression of integers & (+, -, *, /) Operators: (5 + 6) * (4 / 3)
56+43/*
Result: 14.6667
1. Convert Infix Expression
0. Exit
1 
Enter an infix expression of integers & (+, -, *, /) Operators: (3 + 2) / 5
32+5/
Result: 1
1. Convert Infix Expression
0. Exit
0
```
--- 

## Technologies 
- C++ Programming Language
- Object-Oriented Programming (OOP)
- Abstract Data Types (ADT)
- Templates and Class Inheritance
- Dynamic Memory Management (Pointers)
- Arrays and Linked Stack Data Structures 
- Makefile for compilation automation

---

## Notes
  - Input validation is minimal; the program assumes the user enters valid integers for menu selections, single digit inputs and basic arithmetic operators.
  - Focus of this project is on implementing the Stack ADT using array and linked list storage, as well as analyzing the time complexity differences between the two.

---

## About
  Created by Georgia Guillebeau — Computer Science & Engineering student at UNR.
  [LinkedIn](https://www.linkedin.com/in/georgia-guillebeau-3b3636285)

