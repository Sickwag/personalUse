#include "util.h"
#include <stdio.h>
#include <stdlib.h>

void errif(bool judgement, const char* prompt) {
    if(judgement){
        perror(prompt);
        perror("\n");
        exit(EXIT_FAILURE);
    }
}
