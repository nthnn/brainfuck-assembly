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

#include <bfasm/transpiler.hpp>

BrainfuckAsmTranspiler::BrainfuckAsmTranspiler(const vector<BrainfuckAsmParsedInstruction>& instructions) {
    this->instructions = instructions;
}

string BrainfuckAsmTranspiler::translate() {
    string brainfuckCode;

    for(const BrainfuckAsmParsedInstruction& instr : this->instructions)
        brainfuckCode += BrainfuckAsmTranspiler::translateInstruction(instr);
    return brainfuckCode;
}

string BrainfuckAsmTranspiler::translateInstruction(const BrainfuckAsmParsedInstruction& instr) {
    string code;
    switch(instr.instruction) {
        case BFASM_INC_VAL:
            code.append(instr.value > 0 ? instr.value : 1, '+');
            break;

        case BFASM_DEC_VAL:
            code.append(instr.value > 0 ? instr.value : 1, '-');
            break;

        case BFASM_SHIFT_PTR:
            if(instr.value >= 0)
                code.append(instr.value == 0 ? instr.value : 1, '>');
            else code.append(abs(instr.value), '<');
            break;

        case BFASM_JMP_BEGIN:
            code += '[';
            break;

        case BFASM_JMP_END:
            code += ']';
            break;

        case BFASM_OUT:
            code += '.';
            break;

        case BFASM_IN:
            code += ',';
            break;
    }

    return code;
}