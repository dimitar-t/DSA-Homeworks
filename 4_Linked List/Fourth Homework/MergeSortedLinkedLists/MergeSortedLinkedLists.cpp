#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include "SinglyLinkedList.cpp"

using namespace std;

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);

void print_singly_linked_list(SinglyLinkedListNode* node, string sep);

void free_singly_linked_list(SinglyLinkedListNode* node);

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		SinglyLinkedList* llist1 = new SinglyLinkedList();

		int llist_count;
		cin >> llist_count;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		for (int i = 0; i < llist_count; i++) {
			int llist_item;
			cin >> llist_item;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			llist1->insert_node(llist_item);
		}

		SinglyLinkedList* llist2 = new SinglyLinkedList();

		int llist_count2;
		cin >> llist_count2;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		for (int i = 0; i < llist_count2; i++) {
			int llist_item;
			cin >> llist_item;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			llist2->insert_node(llist_item);
		}

		SinglyLinkedListNode* llist_head = mergeLists(llist1->head, llist2->head);

		print_singly_linked_list(llist_head, " ");
		cout << "\n";

		free_singly_linked_list(llist_head);
	}

	return 0;
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
	SinglyLinkedList merged;

	SinglyLinkedListNode* current1 = head1;
	SinglyLinkedListNode* current2 = head2;
	while (current1 != nullptr && current2 != nullptr) {
		if (current1->data <= current2->data) {
			merged.insert_node(current1->data);
			current1 = current1->next;
		}
		else {
			merged.insert_node(current2->data);
			current2 = current2->next;
		}
	}

	while (current1 != nullptr) {
		merged.insert_node(current1->data);
		current1 = current1->next;
	}

	while (current2 != nullptr) {
		merged.insert_node(current2->data);
		current2 = current2->next;
	}

	return merged.head;
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