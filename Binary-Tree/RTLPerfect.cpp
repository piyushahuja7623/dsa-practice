// ------------ this code return Root To Leaf PATH--------

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

// --------------------- vector ----------------------

Struct vector
{
    Node ** data;
    int size, capacity;
    vector()
    {
        capacity = 2;
        size = 0;
        data = new Node*[capacity];
    }
    void push_back(Node* val)
    {
        if(size == capacity)
        {
            capacity *= 2;
            Node ** newData = new Node*[capacity];
            for(int i = 0; i < size; i++)
            {
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
        }
        data[size] = val;
        size++;
    }
    void pop_back()
    {
        if(size > 0)
            size--;
    }
    bool empty()
    {
        return size == 0;
    }
    void printPath(vector & path)
    {
        for(int i = 0, i < path.size, i++)
        {
            cout << path.data[i] -> data << " ";
        }
    }
};

// ---------------- RTL() ----------------------

bool RTL(Node * root, int target, int sum, vector & path)
{
    if(root == nullptr)
        return false;

    path.push_back(root);
    sum += root -> data;

    if(sum == target && root -> left == nullptr && root -> right == nullptr)
    {
        return true;
    }

    // bool left = RTL(root -> left, target, sum, path);
    // if(!left.empty())
    // {
    //     return true;
    // }
    // easy way,
    if(RTL(root ->left, target, sum, path))
        return true;

    // bool right = RTL(root -> right, target, sum);
    // if(!right.empty())
    // {
    //     return true;
    // }
    // easy way,
    if(RTL(root -> right, target, sum, path))
        return true;

    // controls comes here means the current node is not in the path, so pop it from it vector,
    path.pop_back();

    return false;
}
// ---------------------- main() --------------------------
int main()
{
    Node * root = buildTree();

    int target;
    cin >> target;

    vector path;
    bool found = RTL(root, target, 0, path);
   
    if(found)
    {
        cout << "Path founded: ";
        path.
        
        printPath;
    }
    else
        cout << "No path found";

    return 0;
}