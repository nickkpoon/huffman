//
//  minHeap.cpp
//  CS130 huffman
//
//  Created by Nicholas Poon on 10/17/17.
//  Copyright © 2017 Nicholas Poon. All rights reserved.
//

#include "minHeap.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

template<class MIN> heap<MIN>::heap(int s)
{
    array_size = s;
    heap_size = -1;
    myArray = new MIN*[s];
}

template<class MIN> heap<MIN>::~heap()
{
    delete myArray;
}

template<class MIN> bool heap<MIN>::full()
{
    return heap_size >= array_size - 1;
}

template<class MIN> bool heap<MIN>::empty()
{
    return heap_size < 0;
}

template<class MIN> MIN* heap<MIN>::minimum()
{
    return myArray[0];
}

template<class MIN> int heap<MIN>::leftNode(int i)
{
    return 2 * (i + 1) - 1;
}

template<class MIN> int heap<MIN>::rightNode(int i)
{
    return 2 * (i + 1);
}

template<class MIN> int heap<MIN>::parentNode(int i)
{
    return max((i + 1) / 2 - 1, 0);
}


template<class MIN> int heap<MIN>::getSize()
{
    return array_size;
}

template<class MIN> bool heap<MIN>::put(MIN* key)
{
    if (full())
    {
        cout << "HEAP IS FULL";
        return false;
    }
    
    else
        
    {
        heap_size++;
        lower(heap_size, key);
        return true;
    }
}


template<class MIN> MIN** heap<MIN>::getArray()
{
    return myArray;
}

template<class MIN> MIN* heap<MIN>::getMin()
{
    if (empty())
    {
        cout << "HEAP IS EMPTY\n";
        MIN* t;
        return t;
    }
    
    else
    
    {
        MIN* min = myArray[0];
        myArray[0] = myArray[heap_size];
        heap_size--;
        minimize(0);
        return min;
    }
}

template<class MIN> void heap<MIN>::minimize(int i)
{
    int l = leftNode(i);
    int r = rightNode(i);
    int smallest = i;
    
    
    if (l <= heap_size && ((*(myArray[l])) < (*(myArray[i]))))
    {
        smallest = l;
    }
    
    if (r <= heap_size && ((*(myArray[r])) < (*(myArray[smallest]))))
    {
        smallest = r;
    }
    
    if (smallest != i)
    {
        MIN* t = myArray[i];
        myArray[i] = myArray[smallest];
        myArray[smallest] = t;
        minimize(smallest);
    }
}


template<class MIN> void heap<MIN>::lower(int i, MIN* key)
{
    myArray[i] = key;
    
    while ((i > 0) && ((*(myArray[parentNode(i)])) > (*(myArray[i]))))
    {
        MIN* t = myArray[i];
        myArray[i] = myArray[parentNode(i)];
        
        myArray[parentNode(i)] = t;
        i = parentNode(i);
    }
}

