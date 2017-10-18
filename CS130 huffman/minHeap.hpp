//
//  minHeap.hpp
//  CS130 huffman
//
//  Created by Nicholas Poon on 10/17/17.
//  Copyright © 2017 Nicholas Poon. All rights reserved.
//

#ifndef minHeap_hpp
#define minHeap_hpp

#include <stdio.h>

template<class T> class Q {
    int array_size, heap_size;
    T** A; // pointer for the array
    
public:
    Q(int s);
    ~Q();
    bool isEmpty();
    bool isFull();
    T** getArray();
    int getArraySize();
    T* minimum();
    T* extractMin();
    bool insert(T*);
    
private:
    int left(int i);
    int right(int i);
    int parent(int i);
    void decreaseKey(int, T*);
    void minHeapify(int);
};

#endif /* minHeap_hpp */
