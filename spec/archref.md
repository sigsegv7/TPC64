# The TPC64 architecture reference manual

```
Copyright (c) 2026, Ian Moffett.
Provided under the BSD-3 clause.
```

## Scope

The scope of this manual is to describe the underlying architecture and mechanisms
in order to inform developers of system software.

## Terminology

```
Processing domain)
    A processing domain (PD) is a single processor core [unit of execution]
    consisting of its own register bank, ALU, control unit, etc.

Bootstrap PD)
    The bootstrap processing domain is the first processing domain to be brought
    up when the system is powered up.

PC inhibit line)
    Describes an electrical connection to a processing domain that results in
    the program counter being held if set.
```

## Machine power-up state

When power is asserted to the SoC, all processing domains besides the bootstrap
processing domain are to be idle with their PC inhibit lines high. All register
banks are to have their general purpose and ABI registers initialized to a fixed
bitpattern (0x1C1A1C1A1C1A1C1A). All other registers including stack pointers,
frame pointers, control registers and translation table base registers are to be
initialized to zero. The program counter is to have an initial value of 0x00000000
which is mapped to BIOS SPI flash containing platform firmware.
