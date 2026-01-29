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

## Instruction listing

```
NAME       OPCODE    Description          TYPE
-------------------------------------------------------
NOP        0x00      No-operation            [A]
-------------------------------------------------------
```
