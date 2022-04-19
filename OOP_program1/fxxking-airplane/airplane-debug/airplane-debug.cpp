#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct landing //landing struct
{
	int id;
	int waitingtime = 0;
	int fuel;
	landing* next;
};
struct takeoff //takeoff struct
{
	int id;
	int waitingtime = 0;
	takeoff* next;
};

float ave_landing_time = 0;
float airplane_landing = 0;
float ave_takeoff_time = 0;
float airplane_takeoff = 0;
float ave_fuel = 0;
int airplane_broken = 0;
int airplane_em = 0;

int randomfuel(int seed, int n);
int randomland(int seed, int n);
int randomtakeoff(int seed, int n);


bool isempty_landing(landing* head);
void add_first_landing(landing*& head, landing*& last, int idnum, int fuelnum, int maxfuel);
void add_landing(landing*& head, landing*& last, int idnum, int fuelnum, int maxfuel);
void sub_landing(landing*& head);
void em_landing(landing*& temp, int flag);
void em_landing_first(landing*& temp, int flag);

bool isempty_takeoff(takeoff* head);
void add_first_takeoff(takeoff*& head, takeoff*& last, int idnum);
void add_takeoff(takeoff*& head, takeoff*& last, int idnum);
void sub_takeoff(takeoff*& head);

int compair(takeoff* takeoffhead, landing* landinghead_1, landing* landinghead_2);

int main()
{
	landing* b1_head = NULL, * b1_last = NULL, * b4_head = NULL, * b4_last = NULL;
	landing* c2_head = NULL, * c2_last = NULL, * c5_head = NULL, * c5_last = NULL;
	landing* d3_head = NULL, * d3_last = NULL, * d6_head = NULL, * d6_last = NULL;
	takeoff* a_head = NULL, * a_last = NULL, * b_head = NULL, * b_last = NULL, * c_head = NULL, * c_last = NULL, * d_head = NULL, * d_last = NULL;

	int time, how_fuel, how_landing, how_takeoff;
	cout << "How many time unit do you want?" << endl;
	cin >> time;
	cout << endl;
	cout << "Max fuel = ";
	cin >> how_fuel;
	cout << "Max landing airplane going queue = ";
	cin >> how_landing;
	cout << "Max takeoff airplane going queue = ";
	cin >> how_takeoff;
	cout << endl << endl;

	int landingnum = 1;
	int takeoffnum = 0;
	int landing_runway = 1;
	int takeoff_runway = 1;
	int timetemp = 0;

	while (timetemp < time)
	{
		int timeunit = timetemp + 1;
		int temptemp = timetemp;
		int flag_a = 0;

		cout << "This is " << timeunit << " unit." << endl;

		if (!isempty_takeoff(a_head))
		{
			takeoff* current = a_head;
			while (current != NULL)
			{
				current->waitingtime++;
				current = current->next;
			}
		}
		if (!isempty_takeoff(b_head))
		{
			takeoff* current = b_head;
			while (current != NULL)
			{
				current->waitingtime++;
				current = current->next;
			}
		}
		if (!isempty_takeoff(c_head))
		{
			takeoff* current = c_head;
			while (current != NULL)
			{
				current->waitingtime++;
				current = current->next;
			}
		}
		if (!isempty_takeoff(d_head))
		{
			takeoff* current = d_head;
			while (current != NULL)
			{
				current->waitingtime++;
				current = current->next;
			}
		}

		if (!isempty_landing(b1_head))
		{
			b1_head->fuel--;
			b1_head->waitingtime++;
			while (b1_head != NULL && b1_head->fuel == 0)
			{
				flag_a++;
				em_landing_first(b1_head, flag_a);
			}
			if (b1_head != NULL)
			{
				landing* current = b1_head->next;
				while (current != NULL)
				{
					current->fuel--;
					current->waitingtime++;
					if (current->fuel == 0)
					{
						flag_a++;
						em_landing(current, flag_a);
					}
					else
					{
						current = current->next;
					}
				}
			}
		}
		if (!isempty_landing(b4_head))
		{
			b4_head->fuel--;
			b4_head->waitingtime++;
			while (b4_head != NULL && b4_head->fuel == 0)
			{
				flag_a++;
				em_landing_first(b4_head, flag_a);
			}
			if (b4_head != NULL)
			{
				landing* current = b4_head->next;
				while (current != NULL)
				{
					current->fuel--;
					current->waitingtime++;
					if (current->fuel == 0)
					{
						flag_a++;
						em_landing(current, flag_a);
					}
					else
					{
						current = current->next;
					}
				}
			}
		}
		if (!isempty_landing(c2_head))
		{
			c2_head->fuel--;
			c2_head->waitingtime++;
			while (c2_head != NULL && c2_head->fuel == 0)
			{
				flag_a++;
				em_landing_first(c2_head, flag_a);
			}
			if (c2_head != NULL)
			{
				landing* current = c2_head->next;
				while (current != NULL)
				{
					current->fuel--;
					current->waitingtime++;
					if (current->fuel == 0)
					{
						flag_a++;
						em_landing(current, flag_a);
					}
					else
					{
						current = current->next;
					}
				}
			}
		}
		if (!isempty_landing(c5_head))
		{
			c5_head->fuel--;
			c5_head->waitingtime++;
			while (c5_head != NULL && c5_head->fuel == 0)
			{
				flag_a++;
				em_landing_first(c5_head, flag_a);
			}
			if (c5_head != NULL)
			{
				landing* current = c5_head->next;
				while (current != NULL)
				{
					current->fuel--;
					current->waitingtime++;
					if (current->fuel == 0)
					{
						flag_a++;
						em_landing(current, flag_a);
					}
					else
					{
						current = current->next;
					}
				}
			}
		}
		if (!isempty_landing(d3_head))
		{
			d3_head->fuel--;
			d3_head->waitingtime++;
			while (d3_head != NULL && d3_head->fuel == 0)
			{
				flag_a++;
				em_landing_first(d3_head, flag_a);
			}
			if (d3_head != NULL)
			{
				landing* current = d3_head->next;
				while (current != NULL)
				{
					current->fuel--;
					current->waitingtime++;
					if (current->fuel == 0)
					{
						flag_a++;
						em_landing(current, flag_a);
					}
					else
					{
						current = current->next;
					}
				}
			}
		}
		if (!isempty_landing(d6_head))
		{
			d6_head->fuel--;
			d6_head->waitingtime++;
			while (d6_head != NULL && d6_head->fuel == 0)
			{
				flag_a++;
				em_landing_first(d6_head, flag_a);
			}
			if (d6_head != NULL)
			{
				landing* current = d6_head->next;
				while (current != NULL)
				{
					current->fuel--;
					current->waitingtime++;
					if (current->fuel == 0)
					{
						flag_a++;
						em_landing(current, flag_a);
					}
					else
					{
						current = current->next;
					}
				}
			}
		}

		int num_of_landing = randomland(temptemp + 583, how_landing);
		int num_of_takeoff = randomtakeoff(temptemp + 449, how_takeoff);

		for (int i = 0; i < num_of_landing; i++)
		{
			if (landing_runway == 7)
			{
				landing_runway = 1;
				continue;
			}
			if (landing_runway == 1)
			{
				add_landing(b1_head, b1_last, landingnum, temptemp + 204, how_fuel);
				cout << "-B landing quene-b1." << endl;
				landingnum = landingnum + 2;
				landing_runway++;
			}
			else if (landing_runway == 2)
			{
				add_landing(c2_head, c2_last, landingnum, temptemp + 254, how_fuel);
				cout << "-C landing quene-c2." << endl;
				landingnum = landingnum + 2;
				landing_runway++;
			}
			else if (landing_runway == 3)
			{
				add_landing(d3_head, d3_last, landingnum, temptemp + 134, how_fuel);
				cout << "-D landing quene-d3." << endl;
				landingnum = landingnum + 2;
				landing_runway++;
			}
			else if (landing_runway == 4)
			{
				add_landing(b4_head, b4_last, landingnum, temptemp + 295, how_fuel);
				cout << "-B landing quene-b4." << endl;
				landingnum = landingnum + 2;
				landing_runway++;
			}
			else if (landing_runway == 5)
			{
				add_landing(c5_head, c5_last, landingnum, temptemp + 555, how_fuel);
				cout << "-C landing quene-c5." << endl;
				landingnum = landingnum + 2;
				landing_runway++;
			}
			else if (landing_runway == 6)
			{
				add_landing(d6_head, d6_last, landingnum, temptemp + 978, how_fuel);
				cout << "-D landing quene-d6." << endl;
				landingnum = landingnum + 2;
				landing_runway++;
			}
		}
		for (int i = 0; i < num_of_takeoff; i++)
		{
			if (takeoff_runway == 5)
			{
				takeoff_runway = 1;
				continue;
			}
			if (takeoff_runway == 1)
			{
				add_takeoff(a_head, a_last, takeoffnum);
				cout << "enter the runway-A." << endl;
				takeoffnum = takeoffnum + 2;
				takeoff_runway++;
			}
			else if (takeoff_runway == 2)
			{
				add_takeoff(b_head, b_last, takeoffnum);
				cout << "enter the runway-B." << endl;
				takeoffnum = takeoffnum + 2;
				takeoff_runway++;
			}
			else if (takeoff_runway == 3)
			{
				add_takeoff(c_head, c_last, takeoffnum);
				cout << "enter the runway-C." << endl;
				takeoffnum = takeoffnum + 2;
				takeoff_runway++;
			}
			else if (takeoff_runway == 4)
			{
				add_takeoff(d_head, d_last, takeoffnum);
				cout << "enter the runway-D." << endl;
				takeoffnum = takeoffnum + 2;
				takeoff_runway++;
			}
		}

		cout << endl;

		if (a_head != NULL && flag_a == 0)
		{
			cout << "The plane id = " << a_head->id << " with waiting time = " << a_head->waitingtime << " toakeoff from runway-A." << endl;
			a_head = a_head->next;
		}
		
		int b = compair(b_head, b1_head, b4_head);
		int c = compair(c_head, c2_head, c5_head);
		int d = compair(d_head, d3_head, d6_head);

		if (flag_a < 2)
		{
			switch (b)
			{
			case 0:
				break;
			case 1:
				sub_takeoff(b_head);
				cout << "B." << endl;
				break;
			case 2:
				sub_landing(b1_head);
				cout << "B." << endl;
				break;
			case 3:
				sub_landing(b4_head);
				cout << "B." << endl;
				break;
			}
		}
		if (flag_a < 3)
		{
			switch (c)
			{
			case 0:
				break;
			case 1:
				sub_takeoff(c_head);
				cout << "C." << endl;
				break;
			case 2:
				sub_landing(c2_head);
				cout << "C." << endl;
				break;
			case 3:
				sub_landing(c5_head);
				cout << "C." << endl;
				break;
			}
		}
		if (flag_a < 4)
		{
			switch (d)
			{
			case 0:
				break;
			case 1:
				sub_takeoff(d_head);
				cout << "D." << endl;
				break;
			case 2:
				sub_landing(d3_head);
				cout << "D." << endl;
				break;
			case 3:
				sub_landing(d6_head);
				cout << "D." << endl;
				break;
			}
		}

		cout << endl;
		timetemp++;
	}

	cout << "queue-a:" << endl;
	while (a_head != NULL)
	{
		cout << "id = " << a_head->id << " " << "waiting time = " << a_head->waitingtime << endl;
		a_head = a_head->next;
	}
	cout << "queue-b:" << endl;
	while (b_head != NULL)
	{
		cout << "id = " << b_head->id << " " << "waiting time = " << b_head->waitingtime << endl;
		b_head = b_head->next;
	}
	cout << "queue-c:" << endl;
	while (c_head != NULL)
	{
		cout << "id = " << c_head->id << " " << "waiting time = " << c_head->waitingtime << endl;
		c_head = c_head->next;
	}
	cout << "queue-d:" << endl;
	while (d_head != NULL)
	{
		cout << "id = " << d_head->id << " " << "waiting time = " << d_head->waitingtime << endl;
		d_head = d_head->next;
	}
	cout << endl;

	cout << "queue-B1:" << endl;
	while (b1_head != NULL)
	{
		cout << "id = " << b1_head->id << " " << "fuel = " << b1_head->fuel << " " << "waiting time = " << b1_head->waitingtime << endl;
		b1_head = b1_head->next;
	}
	cout << "queue-B4:" << endl;
	while (b4_head != NULL)
	{
		cout << "id = " << b4_head->id << " " << "fuel = " << b4_head->fuel << " " << "waiting time = " << b4_head->waitingtime << endl;
		b4_head = b4_head->next;
	}
	cout << "queue-C2:" << endl;
	while (c2_head != NULL)
	{
		cout << "id = " << c2_head->id << " " << "fuel = " << c2_head->fuel << " " << "waiting time = " << c2_head->waitingtime << endl;
		c2_head = c2_head->next;
	}
	cout << "queue-C5:" << endl;
	while (c5_head != NULL)
	{
		cout << "id = " << c5_head->id << " " << "fuel = " << c5_head->fuel << " " << "waiting time = " << c5_head->waitingtime << endl;
		c5_head = c5_head->next;
	}
	cout << "queue-D3:" << endl;
	while (d3_head != NULL)
	{
		cout << "id = " << d3_head->id << " " << "fuel = " << d3_head->fuel << " " << "waiting time = " << d3_head->waitingtime << endl;
		d3_head = d3_head->next;
	}
	cout << "queue-D6:" << endl;
	while (d6_head != NULL)
	{
		cout << "id = " << d6_head->id << " " << "fuel = " << d6_head->fuel << " " << "waiting time = " << d6_head->waitingtime << endl;
		d6_head = d6_head->next;
	}
	cout << endl;

	cout << "The average landing waiting time = " << ave_landing_time / airplane_landing << endl;
	cout << "The average takeoff waiting time = " << ave_takeoff_time / airplane_takeoff << endl;
	cout << "The average fuel saved = " << ave_fuel / airplane_landing << endl;
	cout << "Total airplane run out of fuel and landing in emergency = " << airplane_em << endl;
	cout << "Total airplane broken without landing = " << airplane_broken << endl;

	return 0;
}

int randomfuel(int seed, int n)
{
	srand(seed);
	int x = rand() % n + 1;
	return x;
}
int randomland(int seed, int n)
{
	srand(seed);
	int x = rand() % (n + 1);
	return x;
}
int randomtakeoff(int seed, int n)
{
	srand(seed);
	int x = rand() % (n + 1);
	return x;
}

bool isempty_landing(landing* head)
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void add_first_landing(landing*& head, landing*& last, int idnum, int fuelnum, int maxfuel)
{
	landing* temp = new landing;
	temp->id = idnum;
	cout << "The plane id = " << temp->id << " ,";
	temp->fuel = randomfuel(fuelnum, maxfuel);
	cout << "and its fuel = " << temp->fuel << " ,enter the runway-";
	temp->next = NULL;
	head = temp;
	last = temp;
}
void add_landing(landing*& head, landing*& last, int idnum, int fuelnum, int maxfuel)
{
	if (isempty_landing(head))
	{
		add_first_landing(head, last, idnum, fuelnum, maxfuel);
	}
	else
	{
		landing* temp = new landing;
		temp->id = idnum;
		cout << "The plane id = " << temp->id << " ,";
		temp->fuel = randomfuel(fuelnum, maxfuel);
		cout << "and its fuel = " << temp->fuel << " ,enter the runway-";
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}
void sub_landing(landing*& head)
{
	cout << "The plane id = " << head->id << " with fuel = " << head->fuel << " with waitingtime = " << head->waitingtime << " landing at runway-";
	ave_fuel = ave_fuel + head->fuel;
	ave_landing_time = ave_landing_time + head->waitingtime;
	airplane_landing++;
	landing *temp = head;
	head = head->next;
	delete(temp);
}
void em_landing(landing*& temp, int flag)
{
	if (flag == 1)
	{
		cout << "The plane id = " << temp->id << " run out of fuel ,with waiting time = " << temp->waitingtime << " ,landing at runway-A." << endl;
		ave_landing_time + ave_landing_time + temp->waitingtime;
		airplane_em++;
		if (temp->next != NULL)
		{
			landing* tempp = temp;
			temp = tempp->next;
			delete(tempp);
		}
		else
		{
			temp = NULL;
		}
	}
	else if (flag == 2)
	{
		cout << "The plane id = " << temp->id << " run out of fuel ,with waiting time = " << temp->waitingtime << " ,landing at runway-B." << endl;
		ave_landing_time + ave_landing_time + temp->waitingtime;
		airplane_em++;
		if (temp->next != NULL)
		{
			landing* tempp = temp;
			temp = tempp->next;
			delete(tempp);
		}
		else
		{
			temp = NULL;
		}
	}
	else if (flag == 3)
	{
		cout << "The plane id = " << temp->id << " run out of fuel ,with waiting time = " << temp->waitingtime << " ,landing at runway-C." << endl;
		ave_landing_time + ave_landing_time + temp->waitingtime;
		airplane_em++;
		if (temp->next != NULL)
		{
			landing* tempp = temp;
			temp = tempp->next;
			delete(tempp);
		}
		else
		{
			temp = NULL;
		}
	}
	else if (flag == 4)
	{
		cout << "The plane id = " << temp->id << " run out of fuel ,with waiting time = " << temp->waitingtime << " ,landing at runway-D." << endl;
		ave_landing_time + ave_landing_time + temp->waitingtime;
		airplane_em++;
		if (temp->next != NULL)
		{
			landing* tempp = temp;
			temp = tempp->next;
			delete(tempp);
		}
		else
		{
			temp = NULL;
		}
	}
	else
	{
		cout << "The plane id = " << temp->id << " run out of fuel ,and it is broken." << endl;
		airplane_broken++;
		if (temp->next != NULL)
		{
			landing* tempp = temp;
			temp = tempp->next;
			delete(tempp);
		}
		else
		{
			temp = NULL;
		}
	}
}
void em_landing_first(landing*& temp, int flag)
{
	if (flag == 1)
	{
		cout << "The plane id = " << temp->id << " run out of fuel ,with waiting time = " << temp->waitingtime << " ,landing at runway-A." << endl;
		ave_landing_time = ave_landing_time + temp->waitingtime;
		airplane_em++;
		landing* tempp = temp;
		temp = tempp->next;
		delete(tempp);
	}
	else if (flag == 2)
	{
		cout << "The plane id = " << temp->id << " run out of fuel ,with waiting time = " << temp->waitingtime << " ,landing at runway-B." << endl;
		ave_landing_time = ave_landing_time + temp->waitingtime;
		airplane_em++;
		landing* tempp = temp;
		temp = tempp->next;
		delete(tempp); delete(temp);
	}
	else if (flag == 3)
	{
		cout << "The plane id = " << temp->id << " run out of fuel ,with waiting time = " << temp->waitingtime << " ,landing at runway-C." << endl;
		ave_landing_time = ave_landing_time + temp->waitingtime;
		airplane_em++;
		landing* tempp = temp;
		temp = tempp->next;
		delete(tempp);
	}
	else if (flag == 4)
	{
		cout << "The plane id = " << temp->id << " run out of fuel ,with waiting time = " << temp->waitingtime << " ,landing at runway-D." << endl;
		ave_landing_time = ave_landing_time + temp->waitingtime;
		airplane_em++;
		landing* tempp = temp;
		temp = tempp->next;
		delete(tempp);
	}
	else
	{
		airplane_broken++;
		cout << "The plane id = " << temp->id << " run out of fuel ,and it is broken." << endl;
		landing* tempp = temp;
		temp = tempp->next;
		delete(tempp);
	}
}

bool isempty_takeoff(takeoff* head)
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void add_first_takeoff(takeoff*& head, takeoff*& last, int idnum)
{
	takeoff* temp = new takeoff;
	temp->id = idnum;
	cout << "The plane id = " << temp->id << " ,";
	temp->next = NULL;
	head = temp;
	last = temp;
}
void add_takeoff(takeoff*& head, takeoff*& last, int idnum)
{
	if (isempty_takeoff(head))
	{
		add_first_takeoff(head, last, idnum);
	}
	else
	{
		takeoff* temp = new takeoff;
		temp->id = idnum;
		cout << "The plane id = " << temp->id << " ,";
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}
void sub_takeoff(takeoff*& head)
{
	cout << "The plane id = " << head->id << " with waiting time = " << head->waitingtime << " toakeoff from runway-";
	ave_takeoff_time = ave_takeoff_time + head->waitingtime;
	airplane_takeoff++;
	takeoff* temp = head;
	head = head->next;
	delete(temp);
}

int compair(takeoff* takeoffhead, landing* landinghead_1, landing* landinghead_2)
{
	
	if (takeoffhead != NULL && landinghead_1 != NULL && landinghead_2 != NULL)
	{
		if (takeoffhead->id < landinghead_1->id && takeoffhead->id < landinghead_2->id)
		{
			return 1;
		}
		else if (landinghead_1->id < takeoffhead->id && landinghead_1->id < landinghead_2->id)
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
	else if (takeoffhead == NULL && landinghead_1 != NULL && landinghead_2 != NULL)
	{
		if (landinghead_1->id < landinghead_2->id)
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
	else if (takeoffhead != NULL && landinghead_1 == NULL && landinghead_2 != NULL)
	{
		if (takeoffhead->id < landinghead_2->id)
		{
			return 1;
		}
		else
		{
			return 3;
		}
	}
	else if (takeoffhead != NULL && landinghead_1 != NULL && landinghead_2 == NULL)
	{
		if (landinghead_1->id < takeoffhead->id)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	else if (takeoffhead != NULL && landinghead_1 == NULL && landinghead_2 == NULL)
	{
		return 1;
	}
	else if (takeoffhead == NULL && landinghead_1 != NULL && landinghead_2 == NULL)
	{
		return 2;
	}
	else if (takeoffhead == NULL && landinghead_1 == NULL && landinghead_2 != NULL)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}