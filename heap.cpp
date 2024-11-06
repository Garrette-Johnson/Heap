//Garrette Johnson 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#include "data_structures.h"

    int left(int i){
        return (2 * i) ;
    }
    int right(int i){
        return (2 * i) + 1; 
    }
    int parent(int i){
        return (i / 2); //round(i / 2) include <cmath> 
    }

    void minheapify(ELEMENT **V, int i, HEAP *pHeap){ //i = 4  //v = 9 8 7 6 5 4 3 2 1 
        int l = left(i);  //l = 8 
        int r = right(i); // r = 9
        int smallest = i; 
        
        if (l <= pHeap->size && V[pHeap->H[l]]->key < V[pHeap->H[i]]->key){ //size = 9 // 8 <= 9 // 2 > 6 
            smallest = l; 
        }
        // else {
        //     smallest = i; // smallest = 4 
        // }

        if (r <= pHeap->size && V[pHeap->H[r]]->key < V[pHeap->H[smallest]]->key){ //size = 9 // 9 <= 9 // 1 > 6 
            smallest = r; 
        }
        if (smallest != i ){ // smallest = 4, i = 4
            int temp = pHeap->H[i]; //temp = 6
            pHeap->H[i] = pHeap->H[smallest]; // V[4]= 
            pHeap->H[smallest] = temp; 
 
            V[pHeap->H[i]]->pos = i;
            V[pHeap->H[smallest]]->pos = smallest; 
            minheapify(V, smallest,pHeap); 
        }
    }

    void buildHeap(HEAP *pHeap, ELEMENT **V, int numElements){
        pHeap->size = numElements; //numElements = 4 so we need a round function to 5
        //numElements; //use round 0000000000
        int i; 
        for (i = 1; i <= pHeap->size; i++){
            V[i]->pos = i; 
            pHeap->H[i] = i; 
        } 
        //build the heap 
        for (i = parent(pHeap->size); i >= 1; i--){
            minheapify(V, i, pHeap); 
            // i = 4
            //v = 9 8 7 6 5 4 3 2 1 
        }
    }

    ELEMENT* extractMin(HEAP *pHeap, ELEMENT **V){
        int Index = pHeap->H[1]; // Index = 9 
        ELEMENT *min = V[Index]; //we make an ELEMENT min for minimum value 

        pHeap->H[1] = pHeap->H[pHeap->size]; 
        V[pHeap->H[1]]->pos = 1; 
        pHeap->size--; //the size gets smaller 

        minheapify(V, 1, pHeap); // re strucutes the heap with new values 
        V[Index]->pos = 0; 
        return min; 
    }

    void heapDecreaseKey(HEAP *pHeap, int i, int key, ELEMENT **V){ // i = heapsizes key = (int)key 
        if (key > pHeap->H[i]){
            fprintf(stderr, "Error: new key is smaller than current key");
        }
        else {
            V[pHeap->H[i]]->pos = key; // V[ Heap's H[current value]] -> pos = key
            while(i > 1 && V[pHeap->H[parent(i)]]->key > V[pHeap->H[i]]->key){
                int temp = pHeap->H[parent(i)]; 
                pHeap->H[parent(i)] = pHeap->H[i]; 
                pHeap->H[i] = temp; 

                V[pHeap->H[i]]->pos = i; 
                V[pHeap->H[parent(i)]]->pos = parent(i);
                i = parent(i); 
            }
        }
    }

    void minHeapInsert(HEAP *pHeap, ELEMENT **V, int key){
       // pHeap->size++; 
        int i = pHeap->size; 
        pHeap->H[i] = key; // stoped here but this value will move the value to the far right 
        V[key]->pos = i; 
        heapDecreaseKey(pHeap, i, V[key]->key, V); //make heap increase key(v, i, =key);
    }

    void  DecreaseingKey(HEAP *pHeap, int index, double newkey, ELEMENT **V){
        int i = V[index]->pos; 
        V[index]->key = newkey; 

        while (i > 1 && V[pHeap->H[i]]->key < V[pHeap->H[parent(i)]]->key){ 
            int temp = pHeap->H[i]; 
            pHeap->H[i] = pHeap->H[parent(i)]; 
            pHeap->H[parent(i)] = temp; 

            V[pHeap->H[i]]->pos = i; 
            V[pHeap->H[parent(i)]]->pos = parent(i); 
            i = parent(i); 
        }
    }

void printArray(ELEMENT **V, int numElements){
    int i; 
    if (!V){
        fprintf(stderr, "Error in printArray: NULL Array"); 
    }
    else{
        for(i = 1; i <= numElements; i++){
            fprintf(stdout, "%d %f %d\n", V[i]->index, V[i]->key, V[i]->pos); 
        }
    }
}

void printHeap(HEAP *pHeap, ELEMENT **V){
    fprintf(stdout, "Capacity = %d, size = %d\n", pHeap->capacity, pHeap->size);
    for(int i = 1; i <= pHeap->size; i++){
        if (pHeap->H[i] >= 1 && pHeap->H[i] <= pHeap->capacity && V[pHeap->H[i]]->pos >= 1){
            fprintf(stdout, "H[%d] = %d\n", V[pHeap->H[i]]->pos, V[pHeap->H[i]]->index); 
        }
        else{
            continue; 
        }
    }

}
