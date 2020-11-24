#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include "SinglyLinkedList.cpp"

using namespace std;

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);

int main() {
	return 0;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
	vector<SinglyLinkedListNode*> used;

	SinglyLinkedListNode* current1 = head1;
	SinglyLinkedListNode* current2 = head2;
	while (true) {
		if (current1 != nullptr) {
			if (find(used.begin(), used.end(), current1) == used.end()) {
				used.push_back(current1);
				current1 = current1->next;
			}
			else {
				return current1->data;
			}
		}

		if (current2 != nullptr) {
			if (find(used.begin(), used.end(), current2) == used.end()) {
				used.push_back(current2);
				current2 = current2->next;
			}
			else {
				return current2->data;
			}
		}
	}

	delete current1;
	delete current2;

	return -1;
}