#include<iostream>
#include<queue>
#include<vector>
#include <iterator>

using namespace std;

struct minHeapNode
{
	char data;
	unsigned freq;

	minHeapNode*left;
	minHeapNode*right;

	minHeapNode(char data, unsigned freq)
	{
		this->data = data;
		this->freq = freq;
		left=right=NULL;
	}

};

struct compare{
bool operator() (minHeapNode *l, minHeapNode *r)
{
	return l->freq > r->freq;
}
};

void printCodes(struct minHeapNode* root, string str) 
{ 

	if (!root) 
		return; 

	if (root->data != '$') 
		cout << root->data << ": " << str << "\n"; 

	printCodes(root->left, str + "0"); 
	printCodes(root->right, str + "1"); 
} 

void huffmanSolve(vector<char> dataarr, vector<int> freqarr,int n)
{
	struct minHeapNode *top,*left,*right;

	priority_queue<minHeapNode*, vector<minHeapNode*>,compare> minHeap;

	for(int i=0;i<n;i++)
	{
		minHeap.push(new minHeapNode(dataarr[i] , freqarr[i]));
	}

	while(minHeap.size() !=1)
	{
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new minHeapNode('$',left->freq+right->freq);

		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	printCodes(minHeap.top(), "");

}

int main()
{
	int n;
	cout<<"Enter number of nodes"<<endl;
	cin>>n;

	vector<char> dataarr(n);
	vector<int> freqarr(n);

	for (int i = 0; i < n; i++)
	{
		cout<<"Enter char for "<<i<<" one"<<endl;
		cin>>dataarr[i];
	}


	for (int i = 0; i < n; i++)
	{
		cout<<"Enter fre1 for "<<i<<" one"<<endl;
		cin>>freqarr[i];
	}

	huffmanSolve(dataarr,freqarr,n);

}