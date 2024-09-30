# Text Editor Undo Function Using Stacks in C++

## Project Description

This C++ program simulates a simple text editor that supports insert, delete, and undo operations using a **stack** data structure. The program processes a series of commands from an input file, modifies a text string, and supports undoing the last action. The program is designed to handle edge cases like deleting unique substrings and maintaining spaces correctly between inserted strings.

## Features

- **Insert**: Appends a string of text to the output.
- **Delete**: Removes a specific, unique substring from the output.
- **Undo**: Reverts the most recent operation (either insert or delete).
- The operations are handled using the standard library's **stack**.

## Instructions

### Input Format

- The input file contains multiple commands separated by newlines (`endl`). Each command represents a modification to the string.
  
  Command formats:
  - `Insert "text"`: Appends the string `"text"` to the current output.
  - `Delete "text"`: Removes the unique substring `"text"` from the current output.
  - `Undo`: Reverts the last operation (either insert or delete).
