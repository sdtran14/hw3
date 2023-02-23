#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
using namespace std;
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) 
{
	smaller = NULL;
	larger = NULL;
	Node* headCopy = head;
	head = NULL;
	if(headCopy != NULL) 
	{
		Node* temp = headCopy->next;
		headCopy->next = NULL;
		if(headCopy->val > pivot) 
		{
			larger = headCopy;
			llpivot(temp, smaller, headCopy->next, pivot);

		} else 
		{
			 smaller = headCopy;
			llpivot(temp, headCopy->next, larger, pivot);
		}
	} 
}
/*
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) 
{
	Node* headCopy = head;
	head = NULL;
	smaller = NULL;

	if(headCopy = NULL)
	{

	}
	else 
	{
		
	}

}

*/