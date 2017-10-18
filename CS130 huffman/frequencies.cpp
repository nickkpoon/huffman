//
//  frequencies.cpp
//  CS130 huffman
//
//  Created by Nicholas Poon on 10/17/17.
//  Copyright © 2017 Nicholas Poon. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char temp;
    
    int freq[256] = {0};
    char in[256] = {'\0'};
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
            //count++;
            cout << (int)in[i] << " " << freq[i] << endl;
        }
    }

}
