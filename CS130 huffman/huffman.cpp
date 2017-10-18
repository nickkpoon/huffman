//
//  huffman.cpp
//  CS130 huffman
//
//  Created by Nicholas Poon on 10/17/17.
//  Copyright © 2017 Nicholas Poon. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include "minHeap.cpp"

using namespace std;



struct MyStreamingHelper
{
    MyStreamingHelper(ostream& out1,
                      ostream& out2) : out1_(out1), out2_(out2) {}
    ostream& out1_;
    ostream& out2_;
};

template <typename T>
MyStreamingHelper& operator<<(MyStreamingHelper& h, T const& t)
{
    h.out1_ << t;
    h.out2_ << t;
    return h;
}

MyStreamingHelper& operator<<(MyStreamingHelper& h, ostream&(*f)(ostream&))
{
    h.out1_ << f;
    h.out2_ << f;
    return h;
}


class Node
{
public:
    
    Node *leftNode;
    Node *rightNode;
    
    int character;
    int frequency;

    string huff; //the binary code for tree traversal
    
    Node()
    {
        leftNode = 0;
        rightNode = 0;
        
        character = INT_MAX;
        frequency = INT_MAX;

        
        huff = "";

    }
    
    Node(int freq, int ascii)
    {
        leftNode = 0;
        rightNode = 0;
        
        character = ascii;
        frequency = freq;
        
        huff = "";
    }
    
    ~Node()
    {
        delete leftNode;
        delete rightNode;
    }

    bool operator==(Node &param)
    {
        return frequency == param.frequency;
    }
    bool operator<(Node &param)
    {
        return frequency < param.frequency;
    }
    bool operator>(Node &param)
    {
        return frequency > param.frequency;
    }
    
    static void getCode(Node*);
    static void show(Node*, bool);
};

void Node::getCode(Node* node)
{
    
    if (node == 0)
    {
        return;
    }
    
    if (node->leftNode != 0)
    {
        node->leftNode->huff = node->huff + "0";
    }
    
    if (node->rightNode != 0)
    {
        node->rightNode->huff = node->huff + "1";
    }
    
    
    
    getCode(node->leftNode);
    getCode(node->rightNode);
    
}


void Node::show(Node* node, bool leavesOnly = 1)
{
    //ofstream myfile;
   // myfile.open ("huffmancode.txt");

    if (node == 0)
    {
        return;
    }
    
    
    show(node->leftNode, leavesOnly);
    
    
    if (leavesOnly)
    {
        if (node->leftNode == 0 && node->rightNode == 0)
        {
            if(node->frequency !=0)
            {
                //cout << *node << "\n";
                cout << node->character << " " << node->huff << endl;

            }
        }
    }
    
    
    else
        
        
    {
        if(node->frequency !=0)
            
        {
            
            //cout << *node << "\n";
            cout << node->character << " " << node->huff << endl;

        }
    }
    
    show(node->rightNode, leavesOnly);
   // myfile.close();

}


void huffman(int *frequency, int *characters, int length)
{
    heap<Node> *min = new heap<Node > (length);
    
    
    for (int i = 0; i < length; i++)
    {
        min->put(new Node(frequency[i], characters[i]));
    }
    
    //cout << PASSED FIRST FOR LOOP IN HUFF
    
    for (int i = 0; i < length - 1; i++)
    {
        Node *x = min->getMin();
        Node *y = min->getMin();
        Node *z = new Node(x->frequency + y->frequency, x->character + y->character);
        
        z->leftNode = x;
        z->rightNode = y;
        
        min->put(z);
    }
    
    //cout << PASSED SECOND FOR LOOP IN HUFF
    
    Node *root = min->getMin();
     
    Node::getCode(root);
    Node::show(root);
}


int main()
{

    
    string input = "";
    int count = 0;
    int first[256] = {0};
    int second[256] = {0};
    while(!cin.eof())
    {
        getline(cin, input);
        //cout << input << endl;
        istringstream(input) >> first[count] >> second[count];
        
        count++;
    }
    
    int* chars = new int[count];
    int* frequency = new int[count];
    int inc1 = 0;
    int inc2 = 0;
    for(int i = 0; i < 256; i++)
    {
        if(first[i]!=0)
        {
            chars[inc1] = first[i];
            inc1++;
            
        }
        if(second[i]!=0)
        {
            frequency[inc2] = second[i];
            //cout << frequency[inc2]<< endl;    FOR DEBUG
            inc2++;
        }
        
    }
    
    huffman(frequency, chars, count);
}
