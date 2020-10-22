#ifndef BST_H
#define BST_H

#include <iostream>
#include "DoubleLL.h"
using namespace std;

struct NodeBST
{
    NodeBST* right = nullptr;
    NodeBST* left = nullptr;
    long long unsigned ip;

    NodeBST(long long unsigned ip)
    {
        this->ip = ip;
    }
};

class BST
{
    public:
        BST(DoubleLL* bitacora);
        ~BST();
        void insert(long long ip);
        void inorder(int amount);

    private:
        NodeBST* root;
        void inorder(int& amount, NodeBST* current);
        void remove(NodeBST* current);

};

#endif
