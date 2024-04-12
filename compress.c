#include <stdio.h>
#include "compress.h"

int toBinary(int num){
    int ansBinary = 0;

    for(int i=0; i<4; i++){
        ansBinary = ansBinary << 1 |(num&1);
    }

    return ansBinary;
}

int change(int num){
    int ansChange = ~num;
    
    return ansChange;
}




