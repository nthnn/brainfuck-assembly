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

#include <bfasm/instructions.hpp>
#include <bfasm/io.hpp>
#include <bfasm/parser.hpp>
#include <bfasm/transpiler.hpp>

using namespace std;

void printUsage(const char* programName);
int processTranspilation(
    const char* inputFile,
    const char* outputFile
);

int main(int argc, char** argv) {
    if(argc != 3) {
        printUsage(argv[0]);
        return -1;
    }

    return processTranspilation(argv[1], argv[2]);
}

void printUsage(const char* programName) {
    cerr << "Usage: "
        << programName
        << " <input_file> <output_file>"
        << endl;
}

int processTranspilation(const char* inputFile, const char* outputFile) {
    try {
        string contents = BrainfuckAsmIO::readInputFile(inputFile);
        BrainfuckAsmParser parser(contents);
        vector<BrainfuckAsmParsedInstruction> instructions = parser.parseAssembly();
        BrainfuckAsmTranspiler translator(instructions);

        if(!BrainfuckAsmIO::writeOutputFile(outputFile, translator.translate())) {
            cerr << "Failed to write to output file: "
                << outputFile
                << endl;
            return -1;
        }
        else cout << "Successfully transpiled to Brainfuck!" << endl;
    }
    catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return -1;
    }

    return 0;
}