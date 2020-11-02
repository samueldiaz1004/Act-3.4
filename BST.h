#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct NodeBST
{
    NodeBST* right = nullptr;
    NodeBST* left = nullptr;
    string ip;
    int cont;

    NodeBST(string ip, int cont)
    {
        this->ip = ip;
        this->cont = cont;
    }
};

class BST
{
    public:
        BST(string fileName);
        ~BST();
        void inorder(int amount);

    private:
        NodeBST* root;
        void insert(string ip, int n);
        void inorder(int& amount, NodeBST* current);
        void removePostorder(NodeBST* current);

};

#endif
