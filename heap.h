//Garrette Johnson 
#ifndef heap_h 
#define heap_h 

typedef struct TAG_ELEMENT{
int index; // index of the element
double key; // key value of the element
int pos; // index in the heap-array, 0 if not in the heap
// Other fields as you see fit
}ELEMENT;   //V is element 

typedef struct TAG_HEAP{
int capacity; // capacity of the heap
int size; // current size of the heap
int *H; // array of indices to the ELEMENT array
// Other fields as you see fit
}HEAP;  //pHeap is heap 

void printArray(ELEMENT **V, int numElements);

void printHeap(HEAP *pHeap, ELEMENT **V); 

// ELEMENT **arrayInsert(ELEMENT **V, double Key){
    
//     return V;  
// }

#endif
