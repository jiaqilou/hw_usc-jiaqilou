#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

Node* merge (Node*& first, Node*& second)
{
	int a, b;
	if (first == NULL)//if first list reaches the end
	{
		return second;//return second one since it still has element in the list
	}
	else if(second == NULL)//if second list reaches the end
	{
		return first;//return first one since it still has element in the list
	}
	else 
	{
		a = first -> value;
		b = second -> value;
		if (a > b)//if value on first list is bigger
		{
			second -> next = merge (first, second -> next);//connect second one onto either the first one or the next node of second one
			return second;//return the node with smaller value, since its next node has bigger value
		}
		else if (a < b)//if value on first list is smaller
		{
			first -> next = merge (first -> next, second);//connect first one onto either the second one or the next node of first one
			return first;//return the node with smaller value, since its next node has bigger value
		}
		else if (a == b)//if value on first list is equal to the second one
		{
			first -> next = merge (first -> next, second);//connect first one onto either the second one or the next node of first one
			return first;//return the node with smaller value, since its next node has bigger or the same value
		}
	}
}
