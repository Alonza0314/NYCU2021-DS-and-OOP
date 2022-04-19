#include<iostream>
#include<deque>
#include<cstring>
#include<algorithm>
#define max 26
using namespace std;
//aaaaaaabbccdddeeeeeeeeeeeffgghhhhhhiiiiiijkllllmmmnnnnnnnoooooooooppqrrrrrrssssssttttttttuuuuvwwxyyz
class treenode
{
public:
	char alphabat;
	int frequency;
	treenode* left;
	treenode* right;
	treenode(){}
};
class a_z
{
public:
	char alphabat;
	int frequency;
	int wwpl;
	string code;
};
deque<a_z> qq;
void cout_tree(const treenode* root, string code)
{
	if (root->left == NULL || root->right == NULL)
	{
		a_z temp;
		temp.alphabat = root->alphabat;
		temp.frequency = root->frequency;
		temp.code = code;
		temp.wwpl = code.length();
		qq.push_back(temp);
	}	
	if (root->left != NULL)
	{
		cout_tree(root->left, string(code + '0'));
	}

	if (root->right != NULL)
	{
		cout_tree(root->right, string(code + '1'));
	}
}
bool cmp(const treenode* a, const treenode* b)
{
	return a->frequency < b->frequency;
}
bool cmpcmp( a_z a, a_z b)
{
	return (int)a.alphabat < (int)b.alphabat;
}

void main()
{
	char al[max] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	int fre[max] = { 7,2,2,3,11,2,2,6,6,1,1,4,3,7,9,2,1,6,6,8,4,1,2,1,2,1 };
	deque<treenode*> q;
	for (int i = 0; i < max; i++)
	{
		treenode* temp = new treenode;
		temp->alphabat = al[i];
		temp->frequency = fre[i];
		temp->left = NULL;
		temp->right = NULL;
		q.push_back(temp);
	}
	while (q.size() != 1)
	{
		sort(q.begin(), q.end(), cmp);	
		treenode* temp1 = q.front();
		q.pop_front();
		treenode* temp2 = q.front();
		q.pop_front();
		treenode* temp = new treenode;
		temp->alphabat = '$';
		temp->frequency = temp1->frequency + temp2->frequency;
		temp->left = temp1;
		temp->right = temp2;
		q.push_back(temp);
	}
	string code = "";
	cout_tree(q.front(), code);
	sort(qq.begin(), qq.end(), cmpcmp);
	int wpl = 0;
	cout << "code list:{" << endl;
	while (!qq.empty())
	{
		a_z temp = qq.front();
		qq.pop_front();
		cout <<"  "<< temp.alphabat << ":" << temp.code << endl;
		wpl += temp.frequency * temp.wwpl;
	}
	cout << "}" << endl;
	cout << "wpl = " << wpl << endl;
}