#include<iostream>
#include<vector>
using namespace std;

void insert(vector<int> &v, int val)
{
    v.push_back(val);
    int index = v.size() - 1;
    
    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(v[index] < v[parent])
        {
            swap(v[index], v[parent]);
            index = parent;
        }
        else
            break;
    }
}
int main()
{
    vector<int> v = {2,3,4,5};

    insert(v, 1);

    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}