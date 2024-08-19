/*
 * This file is part of QLBase (https://github.com/nthnn/QLBase).
 * Copyright 2024 - Nathanne Isip
 * 
 * Permission is hereby granted, free of charge,
 * to any person obtaining a copy of this software
 * and associated documentation files (the “Software”),
 * to deal in the Software without restriction,
 * including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice
 * shall be included in all copies or substantial portions
 * of the Software.
 * 
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF
 * ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 * OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef BFASM_INSTRUCTIONS_HPP
#define BFASM_INSTRUCTIONS_HPP

typedef enum {
    BFASM_INC_VAL       = 0x00,
    BFASM_DEC_VAL       = 0x01,
    BFASM_SHIFT_PTR     = 0x02,
    BFASM_JMP_BEGIN     = 0x03,
    BFASM_JMP_END       = 0x04,
    BFASM_OUT           = 0x05,
    BFASM_IN            = 0x06
} BrainfuckAsmInstruction;

struct BrainfuckAsmParsedInstruction {
    BrainfuckAsmInstruction instruction;
    int value;

    BrainfuckAsmParsedInstruction(BrainfuckAsmInstruction instr, int val = -1)
        : instruction(instr), value(val) { }
};

#endif