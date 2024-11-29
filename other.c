#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {
    // Initialize registers
    int32_t r0 = 0, R1 = 0, R2 = 0, R3 = 0, R4 = 0, r5 = 0, r6 = 0, r7 = 0;

    // Open the file containing commands
    FILE* commands;
    const char* txt = "Programming-Project-3.txt"; // Replace with your file name
    commands = fopen(txt, "r");
    if (commands == NULL) {
        printf("File is empty or cannot be opened.\n");
        return 0;
    }

    // Variables to read operation and arguments
    char op[10], registr[8];
    int32_t hexA;

    // Read commands
    while (fscanf(commands, "%s", op) == 1) {
        if (strcmp(op, "MOV") == 0 || strcmp(op, "mov") == 0) {
            // Parse register name and value
            if (fscanf(commands, "%[^,], #%X", registr, &hexA) != 2) {
                printf("Error parsing register and value.\n");
                continue;
            }

            // Update the appropriate register
            if (strcmp(registr, "R0") == 0) r0 = hexA;
            else if (strcmp(registr, "R1") == 0) R1 = hexA;
            else if (strcmp(registr, "R2") == 0) R2 = hexA;
            else if (strcmp(registr, "R3") == 0) R3 = hexA;
            else if (strcmp(registr, "R4") == 0) R4 = hexA;
            else if (strcmp(registr, "R5") == 0) r5 = hexA;
            else if (strcmp(registr, "R6") == 0) r6 = hexA;
            else if (strcmp(registr, "R7") == 0) r7 = hexA;
            else {
                printf("Unknown register: %s\n", registr);
                continue;
            }

            // Print the MOV operation and updated registers
            printf("%s %s #0x%X\n", op, registr, hexA);
            printf("R0:0x%X R1:0x%X R2:0x%X R3:0x%X R4:0x%X R5:0x%X R6:0x%X R7:0x%X\n",
                   r0, R1, R2, R3, R4, r5, r6, r7);
        }
    }

    fclose(commands);
    return 0;
}
