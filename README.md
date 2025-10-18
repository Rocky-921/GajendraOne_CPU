# GajendraOne_CPU - 8-bit CPU Design

A complete 8-bit processor implementation built from scratch using CircuitVerse, featuring a custom instruction set architecture and microprogrammed control unit.

## Overview

GajendraOne_CPU is an educational 8-bit CPU design that demonstrates fundamental computer architecture concepts, including:

- Common bus architecture
- Microprogrammed control
- Custom instruction set
- Von Neumann architecture (unified memory for code and data)
- Basic ALU operations (ADD/SUB)

## Architecture

### Core Components

- **General Purpose Registers**: 8-bit registers (A, B, C) for flexible data manipulation
- **Instruction Register (IR)**: Holds the current instruction being executed
- **Memory Address Register (MAR)**: 4-bit address pointer
- **Program Counter (PC)**: 4-bit program counter for sequential execution
- **Arithmetic Logic Unit (ALU)**: Supports unsigned addition and subtraction
- **Status Register**: 4-bit flags (Z, NZ, C, NC)

### Memory Architecture

- **Address Space**: 16 memory locations (4-bit addressing)
- **Word Size**: 8-bit words for both data and instructions
- **Unified Memory**: Von Neumann architecture with shared program/data memory

### Instruction Format

```
[7:4] - Operation Code (4 bits)
[3:0] - Address/Immediate Data (4 bits)
```

## Instruction Set

The processor supports a minimal but complete instruction set including:

- **Load/Store Operations**: LDA (Load to Accumulator), STA (Store from Accumulator)
- **Immediate Load**: LDI (Load Immediate)
- **Arithmetic**: ADD, SUB
- **Control Flow**: JMP (Unconditional Jump)
- **I/O**: OUT (Display output in hexadecimal)

*Refer to the full documentation for complete opcode listings and microinstruction sequences.*

## Features

- ✅ Fixed T-state execution cycle for simplified timing
- ✅ Microprogrammed control unit with ROM-based control words
- ✅ TTY-style hexadecimal display
- ✅ System reset capability
- ✅ Modular component design for easy testing and debugging

## Example Programs

The design includes several example programs demonstrating various capabilities:

1. **Addition**: Adding two numbers and displaying results
2. **Complex Arithmetic**: Combined addition and subtraction (e.g., 17-8+25-12)
3. **Array Summation**: Adding numbers from a memory range
4. **Multiplication**: Using repeated addition algorithm
5. **Sorting** (if conditional jumps are implemented)

## Project Structure

```text
├── Report.pdf                   # Complete design documentation
├── GajendraOne.cv               # CircuitVerse Simulation
├── Gajendra.c                   # Script to generate control ROM
└── README.md                    # This file
```

## Getting Started

### Prerequisites

- [CircuitVerse](https://circuitverse.org/) account
- Basic understanding of digital logic and computer architecture

### Running the Simulation

1. Import the CircuitVerse project files
2. Load a sample program into memory
3. Press the reset button to initialize PC to 0x0
4. Start the clock to begin execution
5. Observe results on the TTY display

## Design Decisions

- **Common Bus Architecture**: Simplifies interconnections while maintaining clarity
- **Fixed T-states**: Ensures predictable timing for all instructions
- **4-bit Addressing**: Provides adequate space for educational programs while keeping design manageable
- **Separate Control Bus**: Reduces complexity and potential bus contention issues
