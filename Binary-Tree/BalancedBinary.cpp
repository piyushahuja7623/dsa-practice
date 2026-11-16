// this logic is correct but the more optimized solution is in BalancedBinary2.cpp file.

int height(Node * root)
{
    if(root == nullptr)
        return 0;

    int left = height(root -> left);
    if(left == -1)
        return -1;

    int right = height(root -> right);
    if(right == -1)
        return -1;

    if(abs(left - right) > 1)
    return -1;
    else
    return 1 + max(left,right); 
}
bool bbTree(Node * root) 
{ 
    if(root == nullptr)
    return true;

    int left = height(root -> left); 
    if(left == -1)
        return false;
    
    int right = height(root -> right);
         if(right == -1 || abs(left - right) > 1)
        return false;

     return true; 
}