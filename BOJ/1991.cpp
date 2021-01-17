#include <iostream>
using namespace std;
#define MAX_SIZE 26

typedef struct _Node
{
	char val = NULL;
	char left = NULL;
	char right = NULL;
}Node;

Node nodes[MAX_SIZE];

Node* GetNode(char val) 
{
	if (val == NULL) return NULL;

	Node *ret = NULL;
	for (int i = 0; i < MAX_SIZE; i++) 
	{
		if (nodes[i].val == val)
		{
			ret = &nodes[i];
			break;
		}
	}

	return ret;
}


void PreOrder(Node *n) 
{
	if (n == NULL) return;

	cout << n->val;
	PreOrder(GetNode(n->left));
	PreOrder(GetNode(n->right));
}

void InOrder(Node *n)
{
	if (n == NULL) return;

	InOrder(GetNode(n->left));
	cout << n->val;
	InOrder(GetNode(n->right));
}

void PostOrder(Node *n)
{
	if (n == NULL) return;

	PostOrder(GetNode(n->left));
	PostOrder(GetNode(n->right));
	cout << n->val;
}

int main()
{
	int  n;
	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		char val, left, right;
		cin >> val >> left >> right;

		nodes[i].val = val;
		nodes[i].left = left == '.' ? NULL : left;
		nodes[i].right = right == '.' ? NULL : right;
	}

	PreOrder(&nodes[0]);
	cout << endl;

	InOrder(&nodes[0]);
	cout << endl;

	PostOrder(&nodes[0]);
	cout << endl;

	return 0;
}
