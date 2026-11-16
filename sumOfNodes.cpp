int sumOfNodes(Node * root)
{
    if(root == nullptr)
    return 0;
    int left = sumOfNodes(root -> left);
    int right = sumOfNodes(root -> right);
    return root -> data + (left + right);
}