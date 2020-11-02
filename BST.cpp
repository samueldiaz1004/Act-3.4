#include "BST.h"

BST::BST(string fileName)
{

}

BST::~BST()
{
    removePostorder(root);
}

void BST::insert(string ip, int n)
{
    NodeBST* nvo = new NodeBST(ip, n);

    if(this->root == nullptr){
        this->root = nvo;
        return;
    }

    NodeBST* current = this->root;
    NodeBST* previous;

    while(current != nullptr){
        if(n < current->cont){
            previous = current;
            current = current->left;
        }
        else{
            previous = current;
            current = current->right;
        }
    }

    if(n < previous->cont){
        previous->left = nvo;
    }
    else{
        previous->right = nvo;
    }
}

void BST::inorder(int amount) {
    inorder(amount, this->root);
    cout << endl;
}

void BST::inorder(int &amount, NodeBST *current) {
    if(current != nullptr) {
        inorder(amount, current->right);
        if (amount > 0) {
            cout << "IP: " << current->ip << " Accesos: " << current->cont << endl;
            amount--;
        }
        inorder(amount, current->left);
    }
}

void BST::removePostorder(NodeBST* current)
{
    if(current != nullptr){
        removePostorder(current->left);
        removePostorder(current->right);
        delete current;
    }
}
