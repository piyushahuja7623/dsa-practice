#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        left = right = nullptr;
        data = val;
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
int height(Node * root)
{
    if(root == nullptr)
    {
        return 0;
    }
    int left = height(root -> left);
    int right = height(root -> right);
    return 1 + max(left,right);
}
int main()
{
    Node * root = buildTree();
    cout<< "height of Binary tree is: " + height(root);
    return 0;
}