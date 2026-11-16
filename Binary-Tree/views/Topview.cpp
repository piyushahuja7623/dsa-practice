struct queue
{
    Node * data;
    int hd;
    queue * next;
    queue(Node * ptr)
    {
        data = ptr;
        next = nullptr;
    }
};
void tv(Node * root)
{
    queue * newNode = new queue(root);
    newNode -> hd = 0;
    front = rear = newNode;
    unordered_map <int,Node*> mp;

    while(front != nullptr)
    {
        queue * temp = front;
        Node * current = front -> data;

        // if(!mp[temp -> hd]) this condition is also gives correct output but in this concept our question is that "Is key exist?" that's we use if(mp.find(temp -> hd) == mp.end())   and if your quesiton is that "we have to change/access key's value?" then use mp[key] concept further as per requirement.
        if(mp.find(temp -> hd) == mp.end())
        {
            cout << current -> data; // Because in queue data is in form of Node*, so you have to print current -> data;
            mp[temp -> hd] = current -> data;
        }
        if(current -> left)
        {
            queue * newNode = new queue(current -> left);
            newNode -> hd = (temp -> hd) - 1;

            rear -> next = newNode;
            rear = newNode;            
        }
        if(current -> right)
        {
            queue * newNode = new queue(current -> right);
            newNode -> hd = (temp -> hd) + 1;

            rear -> next = newNode;
            rear = newNode;            
        }
        pop();
    }
}