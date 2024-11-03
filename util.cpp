//Garrette Johnson 
//ASU ID: 1232552024
#include <stdio.h>
#include <string.h>
#include "util.h" 

int nextInstruction(char *Word, double *Key, int *numindex, double *newkey)
{
    int  returnV;
    fscanf(stdin, "%s", Word);

    if (strcmp(Word, "Stop")==0)     return 1;
    if (strcmp(Word, "Read")==0)     return 1; 
    if (strcmp(Word, "PrintArray")==0) return 1; 
    if (strcmp(Word, "PrintHeap")==0) return 1;
    if (strcmp(Word, "BuildHeap")==0) return 1;
    if (strcmp(Word, "ExtractMin")==0) return 1; 
    //if (strcmp(Word, "DecreaseKey")==0) return 1; 
    if (strcmp(Word, "Write")==0) return 1;

    if (strcmp(Word, "DecreaseKey")==0) {
        returnV = fscanf(stdin, "%d %lf", numindex, newkey);
        return returnV; 
    }
    
    if (strcmp(Word, "Insert")==0) {
        returnV = fscanf(stdin, "%lf", Key); 
        return returnV; 
    }
    return 0;
}
