#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include "SinglyLinkedList.cpp"

using namespace std;

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position);

void print_singly_linked_list(SinglyLinkedListNode* node, string sep);

void free_singly_linked_list(SinglyLinkedListNode* node);

int main()
{
	SinglyLinkedList* llist = new SinglyLinkedList();

	int llist_count;
	cin >> llist_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < llist_count; i++) {
		int llist_item;
		cin >> llist_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		llist->insert_node(llist_item);
	}

	int position;
	cin >> position;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	SinglyLinkedListNode* llist_head = deleteNode(llist->head, position);

	print_singly_linked_list(llist_head, " ");
	cout << "\n";

	free_singly_linked_list(llist_head);

	return 0;
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
	if (head == nullptr) {
		return head;
	}

	if (position == 0) {
		SinglyLinkedListNode* temp = head;
		head = head->next;

		delete temp;

		return head;
	}

	int counter = 0;
	SinglyLinkedListNode* current = head;
	while (true) {
		if (counter == position - 1) {
			SinglyLinkedListNode* temp = current->next;
			current->next = temp->next;

			delete temp;

			break;
		}
		else {
			counter++;
			current = current->next;
		}
	}

	return head;
}

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
	while (node) {
		cout << node->data;

		node = node->next;

		if (node) {
			cout << sep;
		}
	}
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
	while (node) {
		SinglyLinkedListNode* temp = node;
		node = node->next;

		free(temp);
	}
}