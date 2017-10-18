//
//  decode.cpp
//  CS130 huffman
//
//  Created by Nicholas Poon on 10/17/17.
//  Copyright © 2017 Nicholas Poon. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iterator>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream infile;
    infile.open("code");
    if (!infile)
    {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }
    
    string input = "";
    int count = 0;
    int first[256] = {0};
    //string *second = new string[256];
    int second[256] = {0};
    while(!infile.eof())
    {
        getline(infile, input);
        //cout << input << endl;
        istringstream(input) >> first[count] >> second[count];
        count++;
        
    }
    
    char temp;
    while(!cin.eof())
    {
        cin.get(temp);
        //cout << temp;
        if (cin.eof())
        {
            break;
        }
        for (int i = 0; i < count; i++)
        {
            if (first[i] == (int)temp)
            {
                cout<<second[i];
            }
        }
    }
    
    /*int* chars = new int[count];
     string *frequency = new string[count];
     int inc1 = 0;
     int inc2 = 0;
     for(int i = 0; i < 256; i++)
     {
     if(first[i]!=0)
     {
     chars[inc1] = first[i];
     inc1++;
     
     }
     if((second[i].compare(NULL)==1))
     {
     frequency[inc2] = second[i];
     //cout << frequency[inc2]<< endl;    FOR DEBUG
     inc2++;
     }
     
     }*/
    
    
}

