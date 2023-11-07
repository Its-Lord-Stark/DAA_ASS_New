// // C++(STL) program for Huffman Coding with STL 
// #include <iostream> 
// #include <iterator>
// #include <queue>
// #include <vector> 

// using namespace std; 

// struct MinHeapNode { 

// 	char data; 

// 	unsigned freq; 

// 	MinHeapNode *left, *right; 

// 	MinHeapNode(char data, unsigned freq) 

// 	{ 

// 		left = right = NULL; 
// 		this->data = data; 
// 		this->freq = freq; 
// 	} 
// }; 


// struct compare { 

// 	bool operator()(MinHeapNode* l, MinHeapNode* r) 

// 	{ 
// 		return (l->freq > r->freq); 
// 	} 
// }; 


// void printCodes(struct MinHeapNode* root, string str) 
// { 

// 	if (!root) 
// 		return; 

// 	if (root->data != '$') 
// 		cout << root->data << ": " << str << "\n"; 

// 	printCodes(root->left, str + "0"); 
// 	printCodes(root->right, str + "1"); 
// } 

// void HuffmanCodes(char data[], int freq[], int size) 
// { 
// 	struct MinHeapNode *left, *right, *top; 

// 	priority_queue<MinHeapNode*, vector<MinHeapNode*>, 
// 				compare> 
// 		minHeap; 

// 	for (int i = 0; i < size; ++i) 
// 		minHeap.push(new MinHeapNode(data[i], freq[i])); 

// 	while (minHeap.size() != 1) { 

// 		left = minHeap.top(); 
// 		minHeap.pop(); 

// 		right = minHeap.top(); 
// 		minHeap.pop(); 

// 		top = new MinHeapNode('$', 
// 							left->freq + right->freq); 

// 		top->left = left; 
// 		top->right = right; 

// 		minHeap.push(top); 
// 	} 

 
// 	printCodes(minHeap.top(), ""); 
// } 


// int main() 
// { 

//     int n;
//     cout<<"Size?"<<endl;
//     cin>>n;

//     char arr[n];
//     int freq[n];

//     for(int i=0;i<n;i++)
//     {
//         char c;
//         cout<<"Enter "<<i<<" character"<<endl;
//         cin>>c;
//         arr[i]=c;

//         int x;
//         cout<<"Enter "<<i<<" freq"<<endl;
//         cin>>x;
//         freq[i]=x;
//     }
// 	HuffmanCodes(arr, freq, n); 

// } 













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