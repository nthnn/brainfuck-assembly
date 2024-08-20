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

#include <bfasm/parser.hpp>

BrainfuckAsmParser::BrainfuckAsmParser(const string& assemblyCode) {
    this->assemblyCode = assemblyCode;
}

vector<BrainfuckAsmParsedInstruction> BrainfuckAsmParser::parseAssembly() {
    vector<BrainfuckAsmParsedInstruction> instructions;
    istringstream iss(this->assemblyCode);
    string line;

    while(getline(iss, line)) {
        if(line.find(";") != string::npos)
            line = line.substr(0, line.find(";"));

        line = BrainfuckAsmParser::trim(line);
        if(!line.empty())
            instructions.push_back(BrainfuckAsmParser::parseLine(line));
    }

    return instructions;
}

string BrainfuckAsmParser::trim(const string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");

    return (start == string::npos || end == string::npos) ? "" :
        str.substr(start, end - start + 1);
}

BrainfuckAsmParsedInstruction BrainfuckAsmParser::parseLine(const string& line) {
    static unordered_map<string, BrainfuckAsmInstruction> instructionMap = {
        { "in",         BFASM_IN        },
        { "out",        BFASM_OUT       },
        { "inc dat",    BFASM_INC_VAL   },
        { "dec dat",    BFASM_DEC_VAL   },
        { "inc ptr",    BFASM_SHIFT_PTR },
        { "dec ptr",    BFASM_SHIFT_PTR },
        { "jmp begin",  BFASM_JMP_BEGIN },
        { "jmp end",    BFASM_JMP_END   }
    };

    regex whitespace("\\s+");
    string cleanLine = regex_replace(trim(line), whitespace, " ");

    if(cleanLine.find("mov ptr,") != string::npos) {
        istringstream iss(cleanLine);
        string command, ptr;
        int addr;

        iss >> command >> ptr >> addr;
        return BrainfuckAsmParsedInstruction(BFASM_SHIFT_PTR, addr);
    }
    else if(cleanLine.find("mov dat,") != string::npos) {
        istringstream iss(cleanLine);
        string command, dat;
        int val;

        iss >> command >> dat >> val;
        return BrainfuckAsmParsedInstruction(val > 0 ? BFASM_INC_VAL : BFASM_DEC_VAL, val);
    }
    else if(cleanLine.find("ld") != string::npos) {
        istringstream iss(cleanLine);
        string command;
        int val;

        iss >> command >> val;
        return BrainfuckAsmParsedInstruction(val > 0 ? BFASM_INC_VAL : BFASM_DEC_VAL, val);
    }

    unordered_map<string, BrainfuckAsmInstruction>::iterator it = instructionMap.find(cleanLine);
    if(it != instructionMap.end())
        return BrainfuckAsmParsedInstruction(it->second);

    throw runtime_error("Unknown instruction: " + cleanLine);
}