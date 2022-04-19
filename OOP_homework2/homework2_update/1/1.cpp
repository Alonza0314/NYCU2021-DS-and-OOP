#include<iostream>
using namespace std;

struct node
{
	int number;
	node* next;
};
class queue
{
private:
	int size;
	node* front;
	node* back;
public:
	queue()
	{
		size = 0;
		front = back = NULL;
	}
	void push_first(int);
	void push(int);
	void pop();
	void cout_the_queue();
	int get_front();
	int get_back();
	int get_size();
	bool isempty();
};
void queue::push_first(int n)
{
	node* temp = new node;
	temp->number = n;
	temp->next = NULL;
	this->front = temp;
	this->back = temp;
	this->size++;
	cout << "The number " << n << " has been push to the queue." << endl;
}
void queue::push(int n)
{
	if (this->isempty())
	{
		this->push_first(n);
	}
	else
	{
		node* temp = new node;
		temp->number = n;
		temp->next = NULL;
		this->back->next = temp;
		this->back = temp;
		this->size++;
		cout << "The number " << n << " has been push to the queue." << endl;
	}
}
void queue::pop()
{
	if (this->isempty())
	{
		cout << "This queue is empty!" << endl;
	}
	else
	{
		node* temp = this->front;
		cout << "Number " << temp->number << " has been popped out." << endl;
		this->front = temp->next;
		this->size--;
		delete(temp);
	}
}
void queue::cout_the_queue()
{
	node* temp = this->front;
	if (this->isempty())
	{
		cout << "This queue is empty!" << endl;
	}
	else
	{
		cout << "Queue:";
		while (temp != NULL)
		{
			cout << temp->number << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}
int queue::get_front()
{
	return this->front->number;
}
int queue::get_back()
{
	return this->back->number;
}
int queue::get_size()
{
	return this->size;
}
bool queue::isempty()
{
	if (this->size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void main()
{
	queue q;
	cout << "This is a queue. Please selsect which active do you want." << endl;
	int flag = 1;
	cout << "1.Push a number to the queue." << endl;
	cout << "2.Pop a number from the queue." << endl;
	cout << "3.Get the front number from the queue." << endl;
	cout << "4.Get the back number from the queue." << endl;
	cout << "5.Get the size of the queue." << endl;
	cout << "6.Is the queue empty?" << endl;
	cout << "7.Print out the queue." << endl;
	cout << "8.End queue." << endl;
	while (flag)
	{
		int n;

		cin >> n;
		switch (n)
		{
		case 1: {
			int m;
			cout << "The number = ";
			cin >> m;
			q.push(m);
			break;
			}
		case 2: {
			q.pop();
			break;
			}
		case 3: {
			int m = q.get_front();
			cout << "The number at the front of the queue:" << m << endl;
			break;
		}
		case 4: {
			int m = q.get_back();
			cout << "The number at the back of the queue:" << m << endl;
			break;
		}
		case 5: {
			int m = q.get_size();
			cout << "The size of the queue:" << m << endl;
			break;
		}
		case 6: {
			if (q.isempty())
			{
				cout << "Yes!" << endl;
			}
			else
			{
				cout << "No!" << endl;
			}
			break;
		}
		case 7: {
			q.cout_the_queue();
			break;
		}
		case 8: {
			flag = 0;
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