#include<iostream>
using namespace std;

struct Node
{
    Node * left, * right;
    int data;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

Node* buildTree()
{
    int val;
    cin >> val;

    if(val == -1)
    return nullptr;

    Node * root = new Node(val);

    root -> left = buildTree();
    root -> right = buildTree();

    return root;
}

Node* lca(Node * root, Node * p, Node * q)
{
    if(root == nullptr)
    return nullptr;

    if(root == p || root == q)
    return root;

    Node * left = lca(root -> left, p, q);
    Node * right = lca(root -> right, p, q);

    if(left != nullptr && right != nullptr)
    return root;

    if(left != nullptr)
    return left;

    if(right != nullptr)
    return right;

    return nullptr;
}
Node * findNode(Node * root, int val)
{
    if(root == nullptr)
    return nullptr;

    Node * left = findNode(root -> left, val);
    if(left != nullptr)
    return left;

    return findNode(root -> right, val);
// this is the shortened way of,
    //  Node * right = findNode(root -> right, val);
    // if(right != nullptr)
    // return right;
}

int main()
{
    Node * root = buildTree();
    Node * p = findNode(root, 10);
    Node * q = findNode(root, 9);
    lca(root, p, q);

    return 0;
}