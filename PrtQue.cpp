// Priority Queue
// May 2, 2017

#include <iostream>
#include <string>
#include <queue>

using namespace std;

enum shipping
{
	ONE_DAY = 11,
	TWO_DAY = 8,
	STANDARD = 4,
	FREE = 1
};

class order
{
public:
	order(string i, shipping c) { itemName = i; shippingCode = c; }
	void print() const { cout << "Item: " << itemName << " Code: " << shippingCode << endl; }
	bool operator<(order rhs) const { return shippingCode < rhs.shippingCode; }
private:
	string itemName;
	shipping shippingCode;
};


int main()
{

	priority_queue<order> q;		// empty queue - only version of the constructor

	order o1("Apple Air Pods", TWO_DAY);
	order o2("Nintendo Switch", ONE_DAY);
	order o3("Book", FREE);
	order o4("OLED TV", TWO_DAY);
	order o5("Detergent", STANDARD);

	q.push(o1);
	q.push(o2);
	q.push(o3);
	q.push(o4);
	q.push(o5);

	int choice;
	string itemName;
	shipping code;

	while (!q.empty())
	{
		cout << "Enter Code: 1 - Fill Order, 2 - Add Order: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "Filling Order" << endl;
			q.top().print();
			q.pop();
			cout << endl;
		}
		else if (choice == 2)
		{
			cout << "Enter Name: ";
			cin >> itemName;

			//cout << "Enter Shipping: ";
			code = FREE;

			order newO(itemName, code);

			q.push(newO);
		}

	}


	return 0;
}
