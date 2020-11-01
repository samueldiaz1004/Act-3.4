#include "BST.h"

BST::BST(string fileName)
{

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