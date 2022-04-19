#include<iostream>
using namespace std;

class treenode
{
public:
	int data;
	treenode* leftchild, * rightchild;
	bool get;
	treenode()
	{
		this->leftchild = NULL;
		this->rightchild = NULL;
		get = 0;
	}
};
void root(treenode* t, int n)
{
	t->data = n;
}
void add(treenode* t, int n)
{
	if (n <= t->data && t->leftchild != NULL)
	{
		add(t->leftchild, n);
	}
	else if (n <= t->data && t->leftchild == NULL)
	{
		treenode* temp = new treenode;
		temp->data = n;
		temp->leftchild = NULL;
		temp->rightchild = NULL;
		temp->get = 0;
		t->leftchild = temp;
	}
	else if (n > t->data && t->rightchild != NULL)
	{
		add(t->rightchild, n);
	}
	else if (n > t->data && t->rightchild == NULL)
	{
		treenode* temp = new treenode;
		temp->data = n;
		temp->leftchild = NULL;
		temp->rightchild = NULL;
		temp->get = 0;
		t->rightchild = temp;
	}
	else
	{
		cout << "|||" << endl;
	}
}
void print(treenode* t)
{
	treenode* current = t;
	while (current->get == 0)
	{
		if (current->leftchild != NULL && current->leftchild->get == 0)
		{
			current = current->leftchild;
		}
		else if (current->rightchild != NULL && current->rightchild->get == 0)
		{
			current = current->rightchild;
		}
		else
		{
			cout << current->data << " ";
			current->get = 1;
			current = t;
		}
	}
	cout << endl;
}

void main()
{
	treenode* tree = new treenode;
	int flag_while = 1;
	int flag_root = 1;
	cout << "This is a tree." << endl;
	cout << "1.Add number." << endl;
	cout << "2.Print tree." << endl;
	cout << "3.End tree" << endl;
	while (flag_while)
	{
		int flag;
		cin >> flag;
		switch (flag)
		{
		case 1: {
			if (flag_root)
			{
				int n;
				cout << "Add number:";
				cin >> n;
				root(tree, n);
				flag_root = 0;
			}
			else
			{
				int n;
				cout << "Add number:";
				cin >> n;
				add(tree, n);
			}
			break;
		}
		case 2: {
			print(tree);
			break;
		}
		case 3: {
			flag_while = 0;
			break;
		}
		default: {
			break;
		}
		}
		for (int i = 0; i < 30; i++)
		{
			cout << "~";
		}
		cout << endl;
	}
}