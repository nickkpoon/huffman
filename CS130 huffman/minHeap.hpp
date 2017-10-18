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

template<class MIN> class heap
{
    int array_size, heap_size;
    MIN** myArray;
    
public:
    heap(int s);
    ~heap();
    bool full();
    bool empty();
    int getSize();
    MIN** getArray();
    MIN* minimum();
    MIN* getMin();
    bool put(MIN*);
    
private:
    int leftNode(int i);
    int rightNode(int i);
    int parentNode(int i);
    void lower(int, MIN*);
    void minimize(int);
};

#endif
