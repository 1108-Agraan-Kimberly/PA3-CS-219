//Author: Kimberly Agraan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define txt "Programming-Project-3.txt"

int main(){
    //Part one
    int32_t R1 = 0x72DF9901;
    int32_t R2 = 0x2E0B484A;
    int32_t R3 = R1 + R2; 
    int32_t R4 = R3 - R2;
    //Part two
    int32_t r0 = 0xAAA5555; 
    int32_t r0a = r0 & R4;
    int32_t r0o = R2 | R3;
    int32_t r5 = R3 ^ R4;
    int32_t r6 = 0xFFFFFFFF;
    int32_t r7 = r6 >> 2;
    int32_t r6o = r7 << 1;

    FILE* commands;
    commands = fopen(txt, "r");
    if(commands == NULL){
        printf("empty");
        return 0;
    }
    char op[10]; 
    
    while(fscanf(commands,"%s", op) == 1){
        const char movU[] = "MOV";
        const char movL[] = "mov";
        const char add[] = "ADDS";
        const char sub[] = "SUBS";
        const char and[] = "ands";
        const char orr[] = "orr";
        const char xor[] = "xor";
        const char lslr[] = "lsrs";
        const char lslrL[] = "LSRS";
        const char cmp[] = "CMP";
        const char tst[] = "tst";

        if(strcmp(op, movU) == 0 || strstr(op, movU ) || strcmp(op, movL) == 0 || strstr(op, movL)){
            char registr[8];
            int32_t hexA;            
            if(fscanf(commands, "%3s #%X", registr, &hexA) == 2){ //MOV operation
            printf("%s %s #0x%X \n", op, registr, hexA);
            }  
        }
        if(strcmp(op, add) == 0 || strstr(op, add)){
            char registr[8];
            char registr2[4];            
            if(fscanf(commands, "%3s %2s", registr, registr2) == 2){ //ADD operation
            printf("%s %s %s %s  \n", op, registr, registr, registr2);
            }             
        }
        if(strcmp(op, sub) == 0 || strstr(op, sub)){
            char registr[8];
            char registr2[4];            
            if(fscanf(commands, "%3s %2s", registr, registr2) == 2){ //SUBS operation
            printf("%s %s %s %s  \n", op, registr, registr, registr2);
            }             
        }
        if(strcmp(op, and) == 0 || strstr(op, and)){
            char registr[8];
            char registr2[4];            
            if(fscanf(commands, "%3s %2s", registr, registr2) == 2){ //SUBS operation
            printf("%s %s %s %s  \n", op, registr, registr, registr2);
            }             
        }
        if(strcmp(op, or) == 0 || strstr(op, or)){
            char registr[8];
            char registr2[4];            
            if(fscanf(commands, "%3s %2s", registr, registr2) == 2){ //SUBS operation
            printf("%s %s %s %s  \n", op, registr, registr, registr2);
            }             
        }
    }
    fclose(commands);
    return 0;
}

