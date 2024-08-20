# Brainfuck Assembly Language

Brainfuck Assembly (BFASM) is a human-readable assembly language designed to simplify the process of writing Brainfuck programs. Brainfuck, a minimalist esoteric language, uses only eight commands and is notoriously difficult to write and maintain due to its cryptic syntax. Brainfuck Assembly serves as an intermediate language, allowing developers to write more understandable code, which can then be translated into Brainfuck.

## Example

This example implements a simple echo program that reads input from the user and outputs it, effectively functioning as a basic "cat" command in Unix, which outputs its input to the standard output.

```assembly
in          ; Get an initial input
jmp begin   ; Begin the loop
    out     ; Output the previous value
    in      ; Get another input
jmp end     ; End of loop
```

Simply transpile the `cat.bfasm` example program if the Brainfuck Assembly is already installed on the current system with the following command:

```bash
bfasm examples/cat.bfasm dist/cat.bf
```

## Instructions

1. `in`: This command reads one character from standard input and stores its ASCII value in the current memory cell. The `in` instruction has an equivalent Brainfuck instruction of `,`.

2. `out`: This command prints the ASCII character stored in the current memory cell to standard output also has an equivalent Brainfuck instruction `.`.

3. `mov ptr, <addr>`: Moves the memory pointer to the specified relative address. This instruction takes a parameter `addr` which is the relative address to move the pointer to. Positive values move the pointer to the right, and negative values move it to the left.

    - **Example Usage**:
    ```assembly
    mov ptr, 3    ; Moves the pointer 3 cells to the right (equivalent to `>>>`)
    mov ptr, -2   ; Moves the pointer 2 cells to the left (equivalent to `<<`)
    ```

    The first command moves the pointer 3 cells to the right, and the second command moves it 2 cells to the left.

4. `mov dat, <val>`: Sets the value of the current memory cell to the specified value. Also takes a parameter named `val` for value to set in the current memory cell. If the value is positive, it corresponds to a series of `+` commands; if negative, to a series of `-` commands.

    - **Example Usage**:
    ```assembly
    mov dat, 5    ; Sets the current cell value to 5 (equivalent to `+++++`)
    mov dat, -3   ; Decreases the current cell value by 3 (equivalent to `---`)
    ```
    The first command sets the current memory cell to 5, and the second decreases it by 3.

5. `inc dat`: Increments the value of the current memory cell by 1, which has an equivalent Brainfuck instruction of `+`.

6. `dec dat`: Decrements the value of the current memory cell by 1, which has an equivalent Brainfuck instruction of `-`.

7. `inc ptr`: Moves the memory pointer one cell to the right, similar to Brainfuck's `>`.

8. `dec ptr`: Moves the memory pointer one cell to the left, similar to Brainfuck's `<`.

9. `ld <val>`: Loads a value into the current memory cell by repeatedly incrementing it to reach the specified value. The parameter `val` is the value to load into the current memory cell.

    - **Example Usage**:
    ```assembly
    ld 3    ; Loads the value 10 into the current memory cell (equivalent to `+++`)
    ```
    This command increments the current cell to reach the value 3.

10. `jmp begin`: This command begins a loop. The loop will continue to execute until the current memory cell's value is zero.

11. `jmp end`: Ends the loop that started with `jmp begin`.

## License

Copyright 2024 - Nathanne Isip

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
