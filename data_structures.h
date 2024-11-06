//Which defines the data types descried in section 1.1 or their equivalent 
//Garrette Johnson 
#ifndef data_structures_h
#define data_structures_h
#include "heap.h"
#include <iostream> 

    int left(int i); 
    
    int right(int i); 

    int parent(int i); 

    void minheapify(ELEMENT **V, int i, HEAP *pHeap); 

    void buildHeap(HEAP *pHeap, ELEMENT **V, int numElements); 

    ELEMENT* extractMin(HEAP *pHeap, ELEMENT **V); 

    void heapDecreaseKey(HEAP *pHeap, int i, int key, ELEMENT **V); 

    void minHeapInsert(HEAP *pHeap, ELEMENT **V, int key); 

    void  DecreaseingKey(HEAP *pHeap, int index, double newkey, ELEMENT **V);


#endif
