// BFS for tress, No recursive, this is nothing but level order, 
// means printing all values in each level

// source https://www.geeksforgeeks.org/level-order-tree-traversal/


#include <iostream>
using namespace std;
#include<list>

struct Node
{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data)
{
    Node *temp = new Node; // this is bad design but it's just for reference
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

list<Node*> queue;
void printLeafNodes(Node* root) {
    if(root != NULL) queue.push_back(root);
    while(!queue.empty()) {
        if(queue.front()->left != NULL) queue.push_back(queue.front()->left);
        if(queue.front()->right != NULL) queue.push_back(queue.front()->right);
        cout << queue.front()->data << endl;
        queue.pop_front();
    }
    return;
}

int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(8);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);
  printLeafNodes(root);
}
