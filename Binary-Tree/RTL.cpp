// ----------- This code returns true if the Root To Leaf path exists -------------

#include<iostream>
using namespace std;

// --------------------- Tree -----------------------
Struct Node
{
    int data;
    Node * left, * right;
    Node(int data)
    {
        this -> data = data;
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

    root -> left = builTree();
    root -> right = buildTree();

    return root;
}

bool RTL(Node * root, int target, int sum)
{
    if(root == nullptr)
        return false;

    sum += root -> data;

    if(sum == target && root -> left == nullptr && root -> right == nullptr)
    {
        return true;
    }

    // bool left = RTL(root -> left, target, sum);
    // if(!left.empty())
    // {
    //     return true;
    // }
    // easy way,
    if(RTL(root ->left, target, sum))
        return true;

    // bool right = RTL(root -> right, target, sum);
    // if(!right.empty())
    // {
    //     return true;
    // }
    // easy way,
    if(RTL(root -> right, target, sum))
        return true;

    return false;
}

int main()
{
    Node * root = buildTree();

    int target;
    cin >> target;

    bool result = RTL(root, target, 0);
    cout << "Path found: " << result;
    
    return false;
}