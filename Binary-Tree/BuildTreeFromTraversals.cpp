#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

Node * buildTree(Vector<int, int> preOrder, Vector<int, int> inOrder, int & preIndex, int inStart, int inEnd)
{
    if(inStart > inEnd)
        return nullptr;

    int rootValue = preOrder[preIndex];
    preIndex++;

    Node * newNode = new Node(rootValue);

    int rootIndex = inStart;

    while(inOrder[rootIndex] != rootValue)
        rootIndex++;

    root -> left = buildTree(preOrder, inOrder, preIndex, inStart, rootIndex - 1);

    root -> right = buildTree(preOrder, inOrder, preIndex, rootIndex + 1, inEnd);

    return root;
}

void inOrderPrint(Node * root)
{
    if(root == nullptr)
        return;

    inOrderPrint(root -> left);
    
    cout << root -> data << " ";

    inOrderPrint(root -> right);
}

int main()
{
    vector<int> preOrder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inOrder  = {4, 2, 5, 1, 6, 3, 7};

    int preIndex = 0;

    Node * root = buildTree(preOrder, inOrder, preIndex, 0, inOrder.size() - 1);

    cout << "printed inorder sequence of the constructed tree: ";
    inOrderPrint(root);

    return 0;
}