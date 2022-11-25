// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node {
	int data;
	Node* next;
};

// Utility function to create a
// new Linked List Node
Node* newNode(int val)
{
	Node* temp = new Node;

	temp->data = val;

	temp->next = NULL;

	return temp;
}

// Function to sort a linked list using selection
// sort algorithm by swapping the next pointers
Node* selectionSort(Node* head)
{
	Node *a, *b, *c, *d, *r;

	a = b = head;

	// While b is not the last node
	while (b->next) {

		c = d = b->next;

		// While d is pointing to a valid node
		while (d) {

			if (b->data > d->data) {

				// If d appears immediately after b
				if (b->next == d) {

					// Case 1: b is the head of the linked list
					if (b == head) {

						// Move d before b
						b->next = d->next;
						d->next = b;

						// Swap b and d pointers
						r = b;
						b = d;
						d = r;

						c = d;

						// Update the head
						head = b;

						// Skip to the next element
						// as it is already in order
						d = d->next;
					}

					// Case 2: b is not the head of the linked list
					else {

						// Move d before b
						b->next = d->next;
						d->next = b;
						a->next = d;

						// Swap b and d pointers
						r = b;
						b = d;
						d = r;

						c = d;

						// Skip to the next element
						// as it is already in order
						d = d->next;
					}
				}

				// If b and d have some non-zero
				// number of nodes in between them
				else {

					// Case 3: b is the head of the linked list
					if (b == head) {

						// Swap b->next and d->next
						r = b->next;
						b->next = d->next;
						d->next = r;
						c->next = b;

						// Swap b and d pointers
						r = b;
						b = d;
						d = r;

						c = d;

						// Skip to the next element
						// as it is already in order
						d = d->next;

						// Update the head
						head = b;
					}

					// Case 4: b is not the head of the linked list
					else {

						// Swap b->next and d->next
						r = b->next;
						b->next = d->next;
						d->next = r;
						c->next = b;
						a->next = d;

						// Swap b and d pointers
						r = b;
						b = d;
						d = r;

						c = d;

						// Skip to the next element
						// as it is already in order
						d = d->next;
					}
				}
			}
			else {

				// Update c and skip to the next element
				// as it is already in order
				c = d;
				d = d->next;
			}
		}

		a = b;
		b = b->next;
	}

	return head;
}

// Function to print the list
void printList(Node* head)
{
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver Code
int main()
{
	Node* head = newNode(5);
	head->next = newNode(4);
	head->next->next = newNode(3);

	head = selectionSort(head);

	printList(head);

	return 0;
}

