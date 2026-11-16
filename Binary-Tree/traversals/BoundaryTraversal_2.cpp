#include<iostream>
using namespace std;
struct Node
{
    Node * left;
    Node * right;
    int data;
    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};
Node * root = nullptr;
Node * buildTree()
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

struct Vector
{
    int * data;
    int size;
    int capacity;
    Vector()
    {
        size = 0;
        capacity = 2;
        data = new int[capacity];
    }
    void push_back(int val)
    {
        if(size == capacity)
        {
            int * newData = new int[capacity * 2];
            for(int i = 0; i < size; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = capacity * 2;
        }
        data[size] = val;
        size++;
    }
    void pop_back()
    {
        size--;
    }
    int back()
    {
        return data[size - 1];
    }
    bool empty()
    {
        return size == 0;
    }  
};


//print leaf node from left to right.
    //helper function needed for printing leaf nodes.
    void printLeafs(Node * root)
    {
        if(root == nullptr)
            return;
        
        if(root -> left == nullptr && root -> right == nullptr)
            cout << root -> data;

        printLeafs(root -> left);
        printLeafs(root -> right);
    }

void boundaryTraversal(Node * root)
{
    //left boundary printing
    if(root == nullptr)
        return;
    cout << root -> data;
    Node * temp = root;
    while(temp -> left != nullptr || temp -> right != nullptr)
    {
        if(temp -> left)
            temp = temp -> left;
        else
            temp = temp -> right;

        if(temp -> left != nullptr || temp -> right != nullptr)
        cout << temp -> data;
    }
    
//calling printLeafs to print Leaf nodes from left to right.
printLeafs(root);

//now printing right boundaries but we need a ds because we need to print from bottom to top.
temp = root;
Vector v;
while(temp -> left != nullptr || temp -> right != nullptr)
    {
        if(temp -> right)
            temp = temp -> right;
        else
            temp = temp -> left;

         if(temp -> left != nullptr || temp -> right != nullptr)
            v.push_back(temp -> data);
    }
    // printing bottom to top.
        for(int i = v.size - 1; i--)
        {
            cout << v[i];
            v.pop_back();
        }

        // or easy loop.
        // while(!v.empty())
        // {
        //     cout << v.back();
        //     v.pop_back();
        // }
}

//print leaf node from left to right.
    //helper function needed for printing leaf nodes.
    void printLeafs(Node * root)
    {
        if(root == nullptr)
            return;
        
        if(root -> left == nullptr && root -> right == nullptr)
            cout << root -> data;

        printLeafs(root -> left);
        printLeafs(root -> right);
    }