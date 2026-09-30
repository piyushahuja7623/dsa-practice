// -------------- Tree ----------------
struct Node
{
    Node * left;
    Node * right;
    int data;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// -----------  Queue  -----------------
struct queue
{
    queue * next;
    Node * data;
    queue(Node * val)
    {
        data = val;
        next = nullptr;
    }
}
queue * front, *rear;
front = rear = nullptr;

void qPush(Node * ptr)
{
    queue * newNode = new queue(ptr);

    if(front == nullptr)
    {
        front = rear = newNode;
        return;
    }

    rear -> next = newNode;
    rear = newNode;
}

Node * front()
{
    return front -> data;
}

void qPop()
{
    queue * temp = front;  // or front().
    front = front -> next;

    if(front == nullptr)
    {
        rear = nullptr;
    }
    
    delete temp;
}

bool qEmpty()
{
    return front == nullptr;
}

int qSize()
{
    int count = 0;
    queue * temp = front;
    while(temp)
    {
        count += 1;
        temp = temp -> next;
    }
    return count;
}

struct vector
{
    int size, capacity;
    Node** data;

    public:
    vector()
    {
        size = 0;
        capacity = 2;
        data = new Node*[capacity];
    }

    void push_back(Node * val)
    {
        if(size == capacity)
        {
            capacity *= 2;
            Node** newData = new Node*[capacity];
            for(int i = 0; i < size; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
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
        return data[size - 1] -> data;
    }
    
    bool vEmpty()
    {
        return size == 0;
    }
};

// ----------  Actual ZigZag traversal function.  ----------------------
void zigZag(Node * root)
{
    if(root == nullptr)
        return;

    qPush(root);
    
    int level = 0;
    while(!qEmpty())
    {
        vector v;
        int n = qSize();
        for(int i = 0; i < n; i++)
        {
            Node * temp = front -> data;
            qPop();

            v.push_back(temp);

            if(temp -> left)
                qPush(temp -> left);
            if(temp -> right)
                qPush(temp -> right);
        }

        if(level % 2 != 0)
        {
           while(!v.vEmpty())
           {
                cout << v.back();
                v.pop_back();
           }
        }
        else
        {
            for(int i = 0; i < v.size; i++)
            {
                cout << v[i] -> data;
            }
        }
        level += 1;
    }
    
}