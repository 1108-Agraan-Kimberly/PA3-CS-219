# Kimberly_Agraan_proj3
## How to Use
Compile using ./gcc machine.c -o start

To run the code use ./start

## More Machine Operations
The program is a basic simulation of an ARM-like assembly processor written in C. It interprets commands from a file named "Programming-Project-3.txt", processes them, and updates the simulated processor's register values accordingly. The output includes the state of the registers and condition flags after processing each instruction.

**MOV** will read the operation, the register, then the value that the register will update to. 

**ADDS** since the registers are defined adding the values in the registers can now be added. The next register to be updated will be the sum of the first two registers that were just updated.

**SUBS** the next register to be updated will be the difference between the previous reigster (r3) and (r2).

**orr** operation will update the register r0 

**xor** operation the value in the file will be turned into a binary number and each bit will be inverted, the returned result will be the hex value of all the inverted bits. 
 
**lsrs** operation will read the hex values, use the binary converions and compare each bit to each other, if the bits are both 0 then it will be 0, otherwise the result is a 1.
 
**lsls** operation will read the two hex values and take the binary conversion and subtract the second operand value from the first one.


## Updating Flags
 But there are more than the add operation, 8 other operations are also used along with the variation of that operation changing the status flag of the result. Operations with an S at the end make sure the instruction will update the flag if needed. The "S" in an opcode means the operation will perform as usual but also update the status flags based on the result. 