#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

// Function prototypes for handling operations
void handle_mov(const char* registr, int32_t hexA, int32_t* registers);
int get_register_index(const char* registr);

int main() {
    int32_t registers[8] = {0}; // Registers R0 to R7 initialized to 0
    FILE* commands;
    const char* txt = "Programming-Project-3.txt"; // Replace with your file name
    commands = fopen(txt, "r");
    if (commands == NULL) {
        printf("File is empty or cannot be opened.\n");
        return 0;
    }

    char line[256]; // Buffer to store a line from the file
    while (fgets(line, sizeof(line), commands)) {
        // Remove newline character if present
        line[strcspn(line, "\n")] = 0;

        // Tokenize the line
        char op[10], registr[10];
        int32_t hexA;
        if (sscanf(line, "%s %[^,], #%X", op, registr, &hexA) == 3) {
            if (strcmp(op, "MOV") == 0 || strcmp(op, "mov") == 0) {
                handle_mov(registr, hexA, registers);
            } else {
                printf("Unknown operation: %s\n", op);
            }
        } else {
            printf("Error parsing line: %s\n", line);
        }
    }

    fclose(commands);
    return 0;
}

// Function to handle MOV operation
void handle_mov(const char* registr, int32_t hexA, int32_t* registers) {
    int regIndex = get_register_index(registr);
    if (regIndex != -1) {
        registers[regIndex] = hexA;
        printf("MOV %s, #0x%X\n", registr, hexA);
        printf("R0: 0x%X R1: 0x%X R2: 0x%X R3: 0x%X R4: 0x%X R5: 0x%X R6: 0x%X R7: 0x%X\n",
               registers[0], registers[1], registers[2], registers[3],
               registers[4], registers[5], registers[6], registers[7]);
    } else {
        printf("Unknown register: %s\n", registr);
    }
}

// Function to get register index from name
int get_register_index(const char* registr) {
    if (strcmp(registr, "R0") == 0) return 0;
    if (strcmp(registr, "R1") == 0) return 1;
    if (strcmp(registr, "R2") == 0) return 2;
    if (strcmp(registr, "R3") == 0) return 3;
    if (strcmp(registr, "R4") == 0) return 4;
    if (strcmp(registr, "R5") == 0) return 5;
    if (strcmp(registr, "R6") == 0) return 6;
    if (strcmp(registr, "R7") == 0) return 7;
    return -1; // Invalid register
}