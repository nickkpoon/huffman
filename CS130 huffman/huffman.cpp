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
#include "minHeap.cpp"

class Node {
public:
    int name;
    int f;
    Node *left, *right;
    string code;
    
    Node() {
        name = INT_MAX;
        code = "";
        f = INT_MAX;
        left = right = 0;
    }
    
    Node(int ff, int n) {
        name = n;
        f = ff;
        left = right = 0;
        code = "";
    }
    
    ~Node() {
        delete left;
        delete right;
    }
    
    bool operator<(Node &param) {
        return f < param.f;
    }
    
    bool operator>(Node &param) {
        return f > param.f;
    }
    
    bool operator==(Node &param) {
        return f == param.f;
    }
    
    static void display(Node*, bool);
    static void encode(Node*);
    
    friend ostream& operator <<(ostream&, Node&);
};

void Node::display(Node* node, bool leavesOnly = 1) {
    if (node == 0) {
        return;
    }
    display(node->left, leavesOnly);
    if (leavesOnly)
    {
        if (node->left == 0 && node->right == 0)
        {
            if(node->f !=0)
            {
                //cout << *node << "\n";
                cout << node->name << " " << node->code << endl;

            }
        }
    }
    else
    {
        if(node->f !=0)
        {
            //cout << *node << "\n";
            cout << node->name << " " << node->code << endl;

        }
    }
    display(node->right, leavesOnly);
}



void Node::encode(Node* node)
{
    if (node == 0)
    {
        return;
    }
    if (node->left != 0)
    {
        node->left->code = node->code + "0";
    }
    if (node->right != 0)
    {
        node->right->code = node->code + "1";
    }
    encode(node->left);
    encode(node->right);
}


void huffman(int *freqs, int *names, int length)
{
    Q<Node> *q = new Q<Node > (length);
    for (int i = 0; i < length; i++)
    {
        q->insert(new Node(freqs[i], names[i]));
    }
    
    for (int i = 0; i < length - 1; i++)
    {
        Node *x = q->extractMin();
        Node *y = q->extractMin();
        Node *z = new Node(x->f + y->f, x->name + y->name);
        z->left = x;
        z->right = y;
        q->insert(z);
    }
    Node *root = q->extractMin();
     
    Node::encode(root);
    Node::display(root);
    cout << endl;
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
    
    int* character = new int[count];
    int* frequency = new int[count];
    int inc1 = 0;
    int inc2 = 0;
    for(int i = 0; i < 256; i++)
    {
        if(first[i]!=0)
        {
            character[inc1] = first[i];
            inc1++;
            
        }
        if(second[i]!=0)
        {
            frequency[inc2] = second[i];
            cout << frequency[inc2]<< endl;
            inc2++;
        }
        
    }
    
    huffman(frequency, character, count);

}
