#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node
{
    char data;
    int val;

    node*left,*right;


    node(char data, int val)
    {
        this->data = data;
        this->val = val;

        left=right=NULL;
    }
};

struct compare
{
    bool operator()(node*l,node*r)
    {
        return l->val>r->val;
    }
};


void printTree(node* root,string str)
{
    if(!root)
        return;
    if(root->data!='$')
        cout<<root->data<<" : "<<str<<endl;

    printTree(root->left, str+'0');
    printTree(root->right, str+'1');


}


void huffman(vector<char> chars, vector<int> freq,int n)
{
    // node*left,*right,*top;

    priority_queue<node*, vector<node*>,compare> minHeap;

    for (int i = 0; i < n; i++)
    {
        minHeap.push(new node(chars[i], freq[i]));
    }   

    while(minHeap.size()!=1)
    {
        node* left = minHeap.top();
        minHeap.pop();

        node* right = minHeap.top();
        minHeap.pop();

        node* top = new node('$',left->val+right->val);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printTree(minHeap.top(), "");



}

int main()
{
    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;

    vector<char> chars(n);
    vector<int> freq(n);

//Taking the input
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the "<<i<<" th character"<<endl;
        cin>>chars[i];

        cout<<"Enter the "<<i<<" th character frequency"<<endl;
        cin>>freq[i];
    }       

    huffman(chars,freq,n);
}


