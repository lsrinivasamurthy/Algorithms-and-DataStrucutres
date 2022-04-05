/*
 * Linked List Demonistration
 */

#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;

	Node(int data){
		this->data = data;
		next = NULL;
	}
};

/* Insert at Begin :
   1.Create a New Node
   2. Make new node point to head
   3. Make new node as head.
   T.C : O(1)
 */
Node* insert_at_begin(Node *head, int data){
	Node *new_node = new Node(data);
	new_node->next = head;
	head = new_node;

	return head;
}

/* Insert at End :
   1.Create a New Node
   2.Traverse the list untill the last node of next is NULL
   3.Point this to the new node.

   But here after traverse we will loose the head, so just traverse using some other dummy variable.
   T.C : O(N)
 */
Node* insert_at_end(Node *head, int data){
	if (head == NULL){
		return insert_at_begin(head, data);
	}

	Node *new_node = new Node(data);
	Node *temp = head; // once we traverse, we will loose the head so just keep a copy in dummy and use dummy for traversing.
	while (temp->next != NULL){
		temp = temp->next;
	}
	temp->next = new_node;
	// new_node->next = NULL.... This is not required as it is already taken care in Node Constructor.
	return head;
}

/* Insert at Position :
 * T.C : O(min(n,pos))
 */
Node* insert_at_pos(Node *head, int data, int pos)
{
	// some edge cases to be covered.
	// 1. If pos > (len + 1) => insert at the end of the linked list. Taken care in while statment.
	// 2. Assuming 1 based index. Pos <1 is invallid so return head as it is.
	// 3. If pos is starting of Linked List , then insert at beign.

	if (pos < 1){
		return head;
	}

	if (pos == 1 || head == NULL){
		return insert_at_begin(head, data);
	}

	Node *temp = head;
	Node *new_node = new Node(data);

	pos = pos - 2; // The position to be jumped is less than 2 of what we require.
	while (pos > 0 && temp->next != NULL){
		temp = temp->next;
		pos--;
	}
	// Now temp is holding a node just before the node to be inserted.
	new_node->next = temp->next;
	temp->next = new_node;

	return head;
}
// Delete at beginning
// T.C : O(1)
Node* delete_at_begin(Node *head){
	if (head == NULL){
		return head; // Nothing to delete, already list is empty.
	}

	Node* temp = head;
	head = head->next;
	delete(temp);

	return head;
}

// Delete at end
// T.C : O(N)

Node* delete_at_end(Node* head){

	if (head == NULL || head->next == NULL){
		return delete_at_begin(head);
	}

	Node *temp = head;
	while (temp->next->next != NULL){
		temp = temp->next;
	}
	Node *temp2 = temp->next;
	temp->next = NULL;
	delete(temp2);

	return head;
}

/* Delete at Position pos.
   1. Traverse till the position before the node to be deleted.
   2. store the node to be deleted.
   3. Adjust the address stored to point it.
   T.C : O(min(n,pos))
 */ 
Node* delete_at_pos(Node *head, int pos)
{
	// For pos > n dont delete any nodes.
	if (pos < 1){
		return head; 
	}
	if (head == NULL){
		return head;
	}
    if (head->next == NULL){
		if (pos == 1){
			delete(head);
			return NULL;
		}
		else{
			return head;
		}
	}

	Node *temp = head;
	
	pos = pos - 2;
	while (pos > 0 && temp->next != NULL)
	{
		temp = temp->next;
		pos--;
	}

	Node *temp2 = temp->next;
	temp->next = temp2->next;
	delete(temp2);

	return head;
}

// reverse the Linked List
// T.C : O(n)
Node * reverse(Node *head)
{
	Node *curr = head;
	Node *prev = NULL;
	while (curr != NULL){
		Node *temp = curr->next;
		curr->next = prev;

		prev = curr;
		curr = temp;
	}
	return prev;
}

// Print Linked List
// T.C : O(n)
void print_list(Node *head)
{
	while (head!= NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

// Returns the middle element
// Two pointer approach
Node *get_Middle(Node *head){
	Node *slow = head;
	Node *fast = head;
	while (fast->next != NULL && fast->next->next != NULL){
 		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

int main()
{
	cout << "Demo of Linked List" << endl;
	
	///////////////////////////////////////
	Node *head = NULL;
	head = insert_at_begin(head, 4);
	head = insert_at_begin(head, 3);
	head = insert_at_begin(head, 2);
	head = insert_at_begin(head, 1);
	//print_list(head);
	/////////////////////////////////////////
	head = insert_at_end(head, 6);
	head = insert_at_end(head, 7);
	head = insert_at_end(head, 8);
	//print_list(head);
    ////////////////////////////////////////
	head = insert_at_pos(head, 5, 5);
	//print_list(head);
	////////////////////////////////////////
	head = NULL;
	head = insert_at_end(head, 1);
	head = insert_at_end(head, 2);
	head = insert_at_end(head, 3);

	//print_list(head);

	head = delete_at_begin(head);

	//print_list(head);
	///////////////////////////////////////
	head = NULL;
	head = insert_at_end(head, 1);
	head = insert_at_end(head, 2);
	head = insert_at_end(head, 3);
	head = insert_at_end(head, 4);
	head = insert_at_end(head, 5);

	//print_list(head);

	head = delete_at_end(head);

	//print_list(head);
	///////////////////////////////////////
	cout << endl;

	head = NULL;
	head = insert_at_end(head, 1);
	head = insert_at_end(head, 2);
	head = insert_at_end(head, 3);
	head = insert_at_end(head, 4);
	head = insert_at_end(head, 5);

	print_list(head);

	head = reverse(head);

	print_list(head); 
	////////////////////////////
	Node *head = NULL;
	head = insert_at_end(head, 1);
	head = insert_at_end(head, 2);
	head = insert_at_end(head, 3);
	head = insert_at_end(head, 4);
	head = insert_at_end(head, 5);

	print_list(head);	
	cout << "Middle Element : " << get_Middle(head)->data<< endl;
	system("pause");
	return 0;
}