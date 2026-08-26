#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value)
    {
        left = right = nullptr;
        data = value;
    }
};
Node* buildTree()
{
    int value;
    cin >> value;

    if(value == -1)
        return nullptr;
    
    Node * root = new Node(value);

    root -> left = buildTree();
    root -> right = buildTree();
    return root; 
}
int main()
{
    Node * root = buildTree();
    return 0;
}