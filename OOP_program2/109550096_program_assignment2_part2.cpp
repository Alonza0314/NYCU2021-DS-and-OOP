#include<iostream>
#include<deque>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
//aabbbcccccccdddddddddddddddd
class treenode
{
public:
	char alphabat;
	int frequency;
	treenode* left;
	treenode* right;
	treenode() {}
};
class a_z
{
public:
	char alphabat;
	int frequency;
	int wwpl;
	string code;
};
map<char, int> m;
map<char, string> mm;
map<char, int>::iterator itt;
map<char, string>::iterator itz;
deque<treenode*> q;
deque<a_z> qq;
deque<a_z>::iterator ite;
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
		mm[temp.alphabat] = temp.code;
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
bool cmpcmp(a_z a, a_z b)
{
	return (int)a.alphabat < (int)b.alphabat;
}

void main()
{
	cout << "Enter characters:";
	char c;
	string input = "";
	while ((c = getchar()) != '\n')
	{
		input += c;
		if (m.count(c))
		{
			m[c]++;
		}
		else
		{
			m[c] = 1;
		}
	}
	for (itt = m.begin(); itt != m.end(); itt++)
	{
		treenode* temp = new treenode;
		temp->alphabat = itt->first;
		temp->frequency = itt->second;
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
	
	string tot_code = "";
	cout << "encoding result:";
	for (int i = 0; i < input.length(); i++)
	{
		for (ite = qq.begin(); ite != qq.end(); ite++)
		{
			if (input[i] == ite->alphabat)
			{
				tot_code += ite->code;
				break;
			}
		}
	}
	cout << tot_code << endl;
	
	int wpl = 0;
	cout << "code list:{" << endl;
	while (!qq.empty())
	{
		a_z temp = qq.front();
		qq.pop_front();
		cout << "  " << temp.alphabat << ":" << temp.code << endl;
		wpl += temp.frequency * temp.wwpl;
	}
	cout << "}" << endl;
	cout << "wpl = " << wpl << endl;

	cout << "decoding result:";
	string temp = "";
	string output = "";
	for (int i = 0; i < tot_code.length(); i++)
	{
		temp += tot_code[i];
		for (itz = mm.begin(); itz != mm.end(); itz++)
		{
			if (temp == itz->second)
			{
				output += itz->first;
				temp = "";
				break;
			}
		}
	}
	cout << output << endl;
}