# The TPC64 ISA reference manual

```
Copyright (c) 2026, Ian Moffett.
Provided under the BSD-3 clause.
```

## Scope

This manual describes the instruction-set architecture of the TPC64 architecture, this provides
descriptions of register encodings, instruction encodings and the list of instruction mnemonics
for developers of system software and specialized user-level utilities.

## Register list

```
NAME     ID      PURPOSE
----------------------------------------
R0      0x00     General purpose
R1      0x01     General purpose
R2      0x02     General purpose
R3      0x03     General purpose
R4      0x04     General purpose
R5      0x05     General purpose
R6      0x06     General purpose
R7      0x07     General purpose
A0      0x08     ABI specific
A1      0x09     ABI specific
A2      0x0A     ABI specific
A3      0x0B     ABI specific
A4      0x0C     ABI specific
A5      0x0D     ABI specific
A6      0x0E     ABI specific
A7      0x0F     ABI specific
SP      0x10     Stack pointer
FP      0x11     Frame pointer
ZERO    0x12     Always-zero
TTBR    0x13     Translation table base
RSVD    0xFF     Reserved
----------------------------------------
```

## Instruction encoding types

### A-type instructions

```
+--------+
| Opcode |
|  7:0   |
+--------+
```

### B-type instructions

```
+-----------------------+
| Opcode    Rd     Rs   |
|  7:0     15:8   23:16 |
+-----------------------+
```

### C-type instructions [WIDE-IMM]

```
+-----------------------+
| Opcode    Rd     Imm  |
|  7:0     15:8   63:16 |
+-----------------------+
```

### D-type instructions [SHORT-IMM]

```
+-----------------------+
| Opcode    Rd     Imm  |
|  7:0     15:8   31:16 |
+-----------------------+
```

### E-type instructions

```
 OPCODE    ARG A  ARG B  BRANCH DST
+-------------------------------+
| Opcode    Ra     Rb    Rc     |
|  7:0     15:8   23:16  31:24  |
+-------------------------------+
```

### F-type instructions

```
+----------------+
| Opcode    Rd   |
|  7:0     15:8  |
+----------------+
```

## Instruction listing

```
NAME       OPCODE    Description          TYPE
-------------------------------------------------------
NOP        0x00      No-operation            [A]
MOV [IMM]  0x01      Wide IMM register load  [C]
MOV [REG]  0x02      Register load           [B]
MOV [IMM]  0x03      Short IMM register load [D]
RESERVED   0x04      N/A                     [N/A]
ADD [IMM]  0x05      IMM register ADD        [D]
ADD [REG]  0x06      Register ADD            [B]
SUB [IMM]  0x07      IMM register SUB        [D]
SUB [REG]  0x08      Register SUB            [B]
RESERVED   0x09      N/A                     [N/A]
RESERVED   0x0A      N/A                     [N/A]
RESERVED   0x0B      N/A                     [N/A]
RESERVED   0x0C      N/A                     [N/A]
HLT        0x0D      Halt the processor      [A]
SRR        0x0E      Special register read   [A]
SRW        0x0F      Special register write  [A]
OR [IMM]   0x10      IMM bitwise OR          [D]
RESERVED   0x11      N/A                     [N/A]
RESERVED   0x12      N/A                     [N/A]
RESERVED   0x13      N/A                     [N/A]
RESERVED   0x14      N/A                     [N/A]
STB        0x15      Store byte into memory  [B]
STW        0x16      Store word into memory  [B]
STL        0x17      Store long into memory  [B]
STQ        0x18      Store quad into memory  [B]
LDB        0x19      Load byte from memory   [B]
LDW        0x1A      Load word from memory   [B]
LDL        0x1B      Load dword from memory  [B]
LDQ        0x1C      Load qword from memory  [B]
B          0x1D      Indirect branch         [F]
BLT        0x1E      Branch if less-than     [E]
BGT        0x1F      Branch if greater-than  [E]
BEQ        0x20      Branch if equal         [E]
BS         0x21      Branch if set           [E]
-------------------------------------------------------
```
