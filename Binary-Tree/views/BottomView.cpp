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

struct queue
{
    int hd;
    queue * next;
    Node * data;
    queue(Node * ptr)
    {
        data = ptr;
        hd = 0;
        next = nullptr;
    }
};
queue * front = nullptr;
queue * rear = nullptr;

void pop()
{
    queue * temp = front;
    if(front != nullptr)
    {
        front = front -> next;
        delete temp;
    }
    if(front == nullptr)
    rear = nullptr;
}

void bottomView(Node * root)
{
    queue * newNode = new queue(root);
    front = rear = newNode;
    unordered_map<int, Node*> mp;
    while(front != nullptr)
    {
        Node * temp = front -> data;
        queue * current = front;
        mp[current -> hd] = temp -> data;
        if(temp -> left)
        {
            queue * newNode = new queue(temp -> left);
            newNode -> hd = temp -> hd - 1;
            rear -> next = newNode;
            rear = newNode;
        }
        if(temp -> right)
        {
            queue * newNode = new queue(temp -> right);
            newNode -> hd = temp -> hd + 1;
            rear -> next = newNode;
            rear = newNode;
        }
        pop();
    }
}