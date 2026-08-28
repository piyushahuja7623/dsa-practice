struct Node{
    Node * left;
    Node * right;
    int data;
    Node(int val)
    {
        left = nullptr;
        right = nullptr;
        data = val;
    }
};
Node* buildTree()
{
    int value;

    cout << "Enter value to insert in tree";
    cin >> value;
     
    if(value == -1)
        return nullptr;
    
    Node * root = new Node(value);

    root -> left = buildTree();
    root -> right = buildTree();

    return root;
}
int countNode(Node * root)
{
    if(root == nullptr)
        return 0;

    int left = countNode(root -> left);
    int right = count(root -> right);

    return 1 + (left + right);
}
int main()
{
    Node * root = buildTree();
    int countNodeOutput = countNode(root);
    cout << "Total Nodes:" + countNodeOutput;
    return 0;
}