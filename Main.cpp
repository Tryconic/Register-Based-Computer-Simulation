#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Initialize registers and RAM
vector<int> registers(10, 0);
vector<int> ram(1000, 0);

// Execute an instruction
void executeInstruction(int instruction) {
    int opcode = instruction / 100;
    int d = (instruction / 10) % 10;
    int n = instruction % 10;

    switch (opcode) {
    case 2: // Set register d to value n
        registers[d] = n;
        break;
    case 3: // Multiply register d by value n
        registers[d] = (registers[d] * n) % 1000;
        break;
    case 4: // Add value n to register d
        registers[d] = (registers[d] + n) % 1000;
        break;
    case 5: // Set register d to value in register s
        registers[d] = registers[n];
        break;
    case 6: // Multiply register d by value in register s
        registers[d] = (registers[d] * registers[n]) % 1000;
        break;
    case 7: // Add value in register s to register d
        registers[d] = (registers[d] + registers[n]) % 1000;
        break;
    case 8: // Set register d to value in RAM at address in register a
        registers[d] = ram[registers[n]];
        break;
    case 9: // Set value in RAM at address in register a to that of register s
        ram[registers[n]] = registers[d];
        break;
    case 0: // Go to location in register d unless register s contains 0
        if (registers[n] != 0) {
            return; // Exit early
        }
        break;
    case 100: // Halt
        return; // Exit early
    }
}

int main() {
    ifstream inputFile("C:/Users/col21/source/repos/assignment1COSC3355/assignment1COSC3355/input3.txt");
    //if (!inputFile.is_open()) {
    //    cout << "Error opening file." << endl;
    //    return 1; // exit with an error code
    //}
    int instruction;
    int numInstructions = 0;

    // Read instructions from input file
    while (inputFile >> instruction) {
        ram[numInstructions] = instruction;
        numInstructions++;
    }

    // Execute instructions
    for (int pc = 0; pc < numInstructions; pc++) {
        executeInstruction(ram[pc]);
    }

    // Output register values
    cout << "Register values:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Register " << i << ": " << registers[i] << endl;
    }

    cout << "Number of instructions executed: " << numInstructions << endl;

    return 0;
}
