#include "BST.h"

BST::BST(string fileName)
{
    fstream file;
    file.open(fileName);
    string ip_, 
           pastIp = "";
    int ipReps = 0;

    while(getline(file, ip_)) {
        string ip = "";
        int spaces = 0;

        for (int i = 0; i < ip_.length(); i++) {
            if (ip_[i] != ' ') {
                if (spaces == 3) {
                    if (ip_[i] != ':') {
                        ip += ip_[i];
                    } else {
                        break;
                    }
                }
            } else {
                spaces++;
            }
        }
        
        cout << ip << endl;
        if (ip != pastIp && pastIp != "") {
            cout << pastIp << " " << ipReps << endl;
            insert(pastIp, ipReps);
            ipReps = 1;
        } else {
            ipReps++;
        }

        pastIp = ip;
    }
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
