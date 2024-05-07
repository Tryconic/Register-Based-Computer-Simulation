# Register-Based-Computer-Simulation

**COSC 3355 Course Assignment I: Register-Based Computer Simulation**

In this assignment, I was tasked with simulating the behavior of a computer with ten registers and a maximum of 1000 words of RAM. Each register or RAM location holds a three-digit integer between 0 and 999. The instruction set includes various operations such as setting registers, arithmetic operations, and memory access. The goal is to interpret a program encoded as three-digit integers, execute the instructions, and output the final values of the registers along with the total number of executed instructions (including the halt instruction). Arithmetic results are reduced module 1000.

**Key components of the assignment:**

Registers: Ten registers, initially containing 000.
RAM: Holds instructions encoded as three-digit integers.
**Instruction Set:**

	100: Halt
	2dn: Set register d to value n
	3dn: Multiply register d by value n
	4dn: Add value n to register d
	5ds: Set register d to the value in register s
	6ds: Multiply register d by the value in register s
	7ds: Add the value in register s to register d
	8da: Set register d to the value in RAM whose address is in register a
	9sa: Set the value in RAM whose address is in register a to that of register s
	0ds: Go to the location in register d unless register s contains 0

Input Files: Read from an input file containing up to 1000 three-digit unsigned integers representing the initial contents of consecutive RAM locations (unspecified locations initialized to 000). Input files are included in repo.
Programming Language: C++.
Output: Display the final register values and the total number of executed instructions. Included in the repo.

