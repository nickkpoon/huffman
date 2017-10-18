//
//  frequency.cpp
//  CS130 huffman
//
//  Created by Nicholas Poon on 10/17/17.
//  Copyright © 2017 Nicholas Poon. All rights reserved.
//

#include "frequency.hpp"
#include <iostream>
#include <stdio.h>
#include "minHeap.cpp"

using namespace std;

void frequency()
{
    int count = 0;
    
    int freq[256] = {0};
    char in[256] = {'\0'};
    char temp;
    while(!cin.eof())
    {
        cin.get(temp);
        if (cin.eof())
        {
            break;
        }
    
        in[(int)temp] = temp;
        ++freq[(int)temp];
        
    }
        
    for (int i = 0; i < 256; i++)
    {
        if (freq[i]!=0)
        {
            count++;
            cout << (int)in[i] << " " << freq[i] << endl;
        }
    }
    
    /*cout << "FINAL COUNT: " << count << endl;

    int* heap = new int[count];
    int inc = 0;
    for (int i = 0; i < 256; i++)
    {
        if(freq[i]!=0)
        {
            heap[inc] = freq[i];
            inc++;
            
            cout << freq[i] << " ";
        }
        
    }
    
    cout << endl;
    
    Q<int> *q = new Q<int>(count);
    for (int i = 0; i < count; i++)
    {
        q->insert(&heap[i]);
    }
    
    for (int i = 0; i < count; i++)
    {
        cout << (*q->extractMin()) << " ";
    }*/
    
}

int main()
{
    /*int *freq;
    int count = 0;
    
    freq = frequency();
    int frequency[256] = {0};
    for (int i = 0; i < 256; i++)
    {
        if (freq[i]!=0)
        {
            frequency[i] = freq[i];
            count++;
        }
    }*/
    frequency();

}
