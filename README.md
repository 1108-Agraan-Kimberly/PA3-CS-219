# Kimberly_Agraan_proj3
## How to Use
Compile using ./gcc machine.c -o start

To run the code use ./start

## More Machine Operations
The program is a basic simulation of an ARM-like assembly processor written in C. It interprets commands from a file named "Programming-Project-3.txt", processes them, and updates the simulated processor's register values accordingly. The output includes the state of the registers and condition flags after processing each instruction.

**MOV** will read the operation, the register, then the value that the register will update to. The flags wont be changed since it is initializing the values.

**ADDS** since the registers are defined adding the values in the registers can now be added. The next register to be updated will be the sum of the first two registers that were just updated.

**SUBS** the next register to be updated will be the difference between the previous reigster (r3) and (r2).

**orr** and **xor** operation will update the register r0 based on the value of r2 and r3. Then update r5 using r3 and r4.

**lsrs** For LSRS, you're comparing the bits in two numbers, and if both bits are 0, the result is 0. If either of the bits is 1, then the result is 1. It's like comparing each pair of bits and deciding the result based on that.
 
**lsls** subtracting the value of the second operand from the first one to perform the shift, filling with 0s where necessary. This is a bit like sliding all the bits over to the left and filling in the gaps with zeros.