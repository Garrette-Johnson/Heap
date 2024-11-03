// which coordinates all modules
//Garrette Johnson 
//ASU ID: 1232552024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "heap.h"
#include "data_structures.h"
#include "main.h"

int main(int argc, char **argv){ 
    FILE  *fp1, *fp2;
    double key;
    ELEMENT **V = NULL; //array of pointers 
    HEAP   *pHeap = NULL;
    int    returnV;
    int    numindex; 
    double newkey; 
    int    i = 0; 
    int    numElements = 0; 
    char   Word[100]; 

    // Check commandline arguments
    if (argc < 3){
        fprintf(stderr, "Usage: %s <ifile> <ofile> \n", argv[0]);
        exit(0);
    }
    // flag  = atoi(argv[3]); //The argv[0] part will read the 1 for the flag
    // the atoi part converts the string to a integer
    fp1   = NULL;
    fp2   = NULL;

    // open the output file
    fp2 = fopen(argv[2], "w"); //opens the O-file 
    if (!fp2){
        fprintf(stderr, "Error: cannot open file %s\n", argv[2]);
        exit(0);
    }

    // Loop over the instructions
    while (1){
        returnV = nextInstruction(Word, &key, &numindex, &newkey); // returnV = 1 (succes), OR 0 if failed

        if (returnV == 0){
            fprintf(stderr, "Warning: Invalid instruction: %s\n", Word);
            continue;
        }

        if (strcmp(Word, "Stop")==0){
            fprintf(stdout, "Instruction: Stop\n"); 
            if (fp2){
                fclose(fp2);
            }
            for (int i = 0; i < numElements; i++){
                free(V[i]); 
            }
            free(V); 
            free(pHeap->H); 
            free(pHeap); 
            return 0;
        }

        if (strcmp(Word, "Read")==0){
            fprintf(stdout, "Instruction: Read\n"); 
            // File opened for reading... 
            fp1 = fopen(argv[1], "r");
            if (!fp1){ //This is where Im getting the error 
                fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
                exit(0);
            }
            if ((returnV = fscanf(fp1, "%lf", &key)) == 1 ){
                numElements = key; 
                V = (ELEMENT **)calloc(numElements + 1, sizeof(ELEMENT *)); 
                for(i = 1; i <= numElements; i++){
                    returnV = fscanf(fp1, "%lf", &key); 
                    //start of while loop  
                    V[i] = (ELEMENT *)calloc (1, sizeof(ELEMENT));
                    V[i]->key = key;    //sets the key in array to the input value
                    V[i]->index = i;    //assigns index to i++ 
                    V[i]->pos = 0;      //means currently not in the heap 
                } //the end of the for loop
                i = 0; 

                pHeap = (HEAP *)calloc(1, sizeof(HEAP)); //we only want one heap 
                if (pHeap == NULL){
                    fprintf(stdout, "\n");
                }
                pHeap->H = (int*)calloc(numElements + 1, sizeof(int)); //maybe error
                if (pHeap->H == NULL){
                    fprintf(stdout, "2\n"); 
                } 
                pHeap->capacity = numElements;              // set the capacity with num elements from input 
                pHeap->size = 0;
            } 
             
            fclose(fp1); // close the input file
            continue; 
        } //End of Read

        if (strcmp(Word, "PrintArray")==0){ 
            fprintf(stdout, "Instruction: PrintArray\n"); 

        if (V == NULL){
            fprintf(stderr, "Error: array is NULL");
        }
        else{ 
            printArray(V, numElements); 
        }
            continue; 
        }

        if (strcmp(Word, "PrintHeap")==0){ 
            fprintf(stdout, "Instruction: PrintHeap\n"); 

        if (pHeap == NULL){
            fprintf(stderr, "Error: heap is NULL\n");
        }
        else{ 
            printHeap(pHeap, V); 
        }
            continue; 
        }

        if (strcmp(Word, "BuildHeap")==0){ 
            fprintf(stdout, "Instruction: BuildHeap\n"); 
            buildHeap(pHeap, V, numElements); 
        
            continue; 
        }
        if (strcmp(Word, "Insert")==0){ 
            if (numElements == 0){
                fprintf(stderr, "Heap is null\n"); 
            }
            else if((int)key <= 0 || (int)key > numElements){ //checks the boundary for 
                fprintf(stdout, "Instruction: Insert %d\n", (int)key); 
            }
            else if ((int) key == V[(int)key]->pos){
                fprintf(stdout, "Instruction: Insert %d\n", (int)key); 
                //fprintf(stdout, "Element V[%d] inserted into the heap\n", (int)key);
            }
               else{
                fprintf(stdout, "Instruction: Insert %d\n", (int)key); 
                if (key < 1 || key > numElements){
                    fprintf(stderr, "Error: index out of bound\n"); 
                    continue; 
                }
                else{ 
                    if (V[(int)key]->pos != 0){ //need to build heap first
                        fprintf(stderr, "Error: %d already in the heap", V[(int)key]->pos);
                    }
                    else {
                        pHeap->size = pHeap->size + 1; //makes heap new size by adding one 
                        pHeap->H[pHeap->size] = (int)key; //= (int)key
                        V[(int)key]->pos = pHeap->size; 
                        heapDecreaseKey(pHeap, pHeap->size, (int)key, V); //when doiing test 9, pos 1 and pos 2 have to flip
                        fprintf(stdout, "Element V[%d] inserted into the heap\n", (int)key); 
                    }
                }
            } //for else statment
        }

        if (strcmp(Word, "ExtractMin")==0){
            fprintf(stdout, "Instruction: ExtractMin\n"); 
            if (pHeap == NULL){
                fprintf(stderr, "Error: heap is NULL\n"); 
            }
            else if (pHeap->size == 0){
                fprintf(stderr, "Error: heap is empty\n");
            }
            else{
                ELEMENT *min = extractMin(pHeap, V); 
                //accidently added another extractmin call 

            }     
        }

        if (strcmp(Word, "DecreaseKey")==0){ 
            fprintf(stdout, "Instruction: DecreaseKey %d %lf\n", numindex, newkey); 
            if (numindex <= 0 || numindex > numElements || newkey >= V[numindex]->key){
                fprintf(stderr, "Error: invalid call to DecreaseKey"); 
                continue; 
            }
            else if(V[numindex]->pos == 0){
                fprintf(stderr, "Error: V[%d] not in the heap", numindex); 
                continue; 
            }
            else{
                DecreaseingKey(pHeap, numindex, newkey, V); 
                continue; 
            }

        }  

        if (strcmp(Word, "Write")==0){
            if (!V){
            fprintf(stderr, "Error: In write"); 
            continue; 
        }
        else{
            fprintf(stdout, "Instruction: Write\n"); 
            FILE *file = fopen(argv[2], "w");
            if (file == NULL){
                fprintf(stderr, "Error: Can't open the file %s", argv[2]); 
                continue; 
            }
            else {
               // fprintf(file, "wrote in o-file\n"); //delete later, but just for clafication
                for (int i = 1; i <= numElements; i++){
                    fprintf(file, "%d %lf %d\n", i, V[i]->key, V[i]->pos); //This sends to the O-file 
                }
                fclose(file); 
                continue; 
            }

        }
            continue;  
        }
    }
    return 1;
}
