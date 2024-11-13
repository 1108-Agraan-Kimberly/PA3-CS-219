//Author: Kimberly Agraan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define txt "Programming-Project-3.txt"

int main(){
FILE* commands;
    commands = fopen(txt, "r");
    if(commands == NULL){
        printf("empty");
        return 0;
    }
    return 0;
}