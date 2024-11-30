//Author: Kimberly Agraan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define txt "Programming-Project-3.txt"

int main(){
    const int32_t r0 = 0, R1 = 0, R2 = 0, R3 = 0, R4 = 0, r5 = 0, r6 = 0, r7 = 0;
    int N = 0, Z = 0, C = 0, V = 0;
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
        const char lslrL[] = "LSLS";
        const char cmp[] = "CMP";
        const char tst[] = "tst";

        if(strcmp(op, movU) == 0 || strstr(op, movU)){
            char registr[8];
            int32_t hexA;            
            if(fscanf(commands, "%s #%X", registr, &hexA) == 2){ //MOV operation
            int32_t R1 = 0x72DF9901;
            printf("%s %s #0x%X \n", op, registr, hexA);
            printf("R0:0X%X R1:0x%X R2:0X%X R3:0X%X R4:0X%X R5:0X%X R6:0X%X R7:0X%X \n", r0,R1, R2, R3, R4, r5, r6, r7);
            printf("N = %d Z = %d C = %d V = %d \n", N, Z, C, V);
            }  //"R0: R1: R2: R3: R4: R5: R6: R7: " 
        }

        if(strcmp(op, add) == 0 || strstr(op, add)){
            char registr[8];
            char registr2[4];
            char registr3[4];            
            if(fscanf(commands, "%s %s %s", registr, registr2, registr3) == 3){ //ADD operation
            int32_t R1 = 0x72DF9901;
            int32_t R2 = 0x2E0B484A;
            int32_t R3 = R1 + R2; 
            int V = 1;
            printf("%s %s %s %s \n", op, registr, registr2, registr3);
            printf("R0:0X%X R1:0x%X R2:0X%X R3:0X%X R4:0X%X R5:0X%X R6:0X%X R7:0X%X \n", r0,R1, R2, R3, R4, r5, r6, r7);
            printf("N = %d Z = %d C = %d V = %d \n", N, Z, C, V);
            }             
        }
        if(strcmp(op, sub) == 0 || strstr(op, sub)){
            char registr[8];
            char registr2[4];            
            if(fscanf(commands, "%3s %2s", registr, registr2) == 2){ //SUBS operation
            int32_t R1 = 0x72DF9901;
            int32_t R2 = 0x2E0B484A;
            int32_t R4 = R3 - R2;
            int C = 1, V = 1;
            printf("%s %s %s %s  \n", op, registr, registr, registr2);
            printf("R0:0X%X R1:0x%X R2:0X%X R3:0X%X R4:0X%X R5:0X%X R6:0X%X R7:0X%X \n", r0,R1, R2, R3, R4, r5, r6, r7);
            printf("N = %d Z = %d C = %d V = %d \n", N, Z, C, V);
            }             
        }
       
        if(strcmp(op, movL) == 0 || strstr(op, movL)){
            char registr[8];            
            int32_t hexA;            
            if(fscanf(commands, "%3s #%X", registr, &hexA) == 2){ //MOV operation
            printf("%s %s #0x%X \n", op, registr, hexA);
            printf("R0:0X%X R1:0x%X R2:0X%X R3:0X%X R4:0X%X R5:0X%X R6:0X%X R7:0X%X \n", r0,R1, R2, R3, R4, r5, r6, r7);
            }            
        }
        if(strcmp(op, and) == 0 || strstr(op, and)){
            char registr[8];
            char registr2[4];    
            char registr3[4];    
            int C = 1, V = 1;    
            if(fscanf(commands, "%s %s %s", registr, registr2, registr3) == 3){ //SUBS operation
            int32_t R1 = 0x72DF9901;
            int32_t R2 = 0x2E0B484A;
            int32_t R3 = R1 + R2; 
            int32_t R4 = R3 - R2;
            int32_t r0 = 0xAAA5555; 
            int32_t r0a = r0 & R4;
            printf("%s %s %s %s  \n", op, registr, registr2, registr3);
            printf("R0:0X%X R1:0x%X R2:0X%X R3:0X%X R4:0X%X R5:0X%X R6:0X%X R7:0X%X \n", r0a, R1, R2, R3, R4, r5, r6, r7);
            printf("N = %d Z = %d C = %d V = %d \n", N, Z, C, V);
            }             
        }
        if(strcmp(op, orr) == 0 || strstr(op, orr)){
            char registr[8];
            char registr2[4];
            char registr3[4];            
            if(fscanf(commands, "%s %s %s", registr, registr2, registr3) == 3){ //orr operation
            int32_t R1 = 0x72DF9901;
            int32_t R2 = 0x2E0B484A;
            int32_t R3 = R1 + R2; 
            int32_t R4 = R3 - R2;
            int32_t r0 = 0xAAA5555; 
            int32_t r0a = r0 & R4;    
            int32_t r0o = R2 | R3;   
            int C = 1, V = 1;    
            printf("%s %s %s %s  \n", op, registr, registr2, registr3);
            printf("R0:0X%X R1:0x%X R2:0X%X R3:0X%X R4:0X%X R5:0X%X R6:0X%X R7:0X%X \n", r0o, R1, R2, R3, R4, r5, r6, r7);
            printf("N = %d Z = %d C = %d V = %d \n", N, Z, C, V);
            }             
        }
        if(strcmp(op, xor) == 0 || strstr(op, xor)){
            char registr[8];
            char registr2[4]; 
            char registr3[4];           
            if(fscanf(commands, "%s %s %s", registr, registr2, registr3) == 3){ //xor operation
            int32_t R1 = 0x72DF9901;
            int32_t R2 = 0x2E0B484A;
            int32_t R3 = R1 + R2; 
            int32_t R4 = R3 - R2;
            int32_t r0 = 0xAAA5555; 
            int32_t r0a = r0 & R4;    
            int32_t r0o = R2 | R3;
            int32_t r5 = R3 ^ R4; 
            int C = 1, V = 1; 
            printf("%s %s %s %s  \n", op, registr, registr2, registr3);
            printf("R0:0X%X R1:0x%X R2:0X%X R3:0X%X R4:0X%X R5:0X%X R6:0X%X R7:0X%X \n", r0o, R1, R2, R3, R4, r5, r6, r7);
            printf("N = %d Z = %d C = %d V = %d \n", N, Z, C, V);
            }             
        }
        if(strcmp(op, lslr) == 0 || strstr(op, lslr) || strcmp(op, lslrL) == 0 || strstr(op, lslrL)){
            char registr[8];
            char registr2[4]; 
            int push;          
            if(fscanf(commands, "%s %s #%d", registr, registr2, &push) == 3){ //xor operation
            int32_t R1 = 0x72DF9901;
            int32_t R2 = 0x2E0B484A;
            int32_t R3 = R1 + R2; 
            int32_t R4 = R3 - R2;
            int32_t r0 = 0xAAA5555; 
            int32_t r0a = r0 & R4;
            int32_t r0o = R2 | R3;
            int32_t r5 = R3 ^ R4;
            int32_t r6 = 0xFFFFFFFF;
            int32_t r7 = r6 >> 2;
            int32_t r6o = r7 << 1;
            int C = 1;
            printf("%s %s %s #%d  \n", op, registr, registr2, push);
            printf("R0:0X%X R1:0x%X R2:0X%X R3:0X%X R4:0X%X R5:0X%X R6:0X%X R7:0X%X \n", r0o, R1, R2, R3, R4, r5, r6, r7);
            printf("N = %d Z = %d C = %d V = %d \n", N, Z, C, V);
            }             
        }
    }
    fclose(commands);
    return 0;
}

