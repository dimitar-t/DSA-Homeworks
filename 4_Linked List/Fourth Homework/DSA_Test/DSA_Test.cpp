#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "DoublyLinkedList.h"
#include <string>

using namespace std;

const string GUN_CMD = "gun";
const string MILEN_CMD = "milen";

void rearrangeList(DoublyLinkedList<int>& guns);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cin.ignore();

	DoublyLinkedList<int> guns;
	for (int i = 0; i < n; i++) {
		string input;
		getline(cin, input);

		if (input.compare(GUN_CMD) == 0) {
			guns.removeTail();
		}
		else if (input.compare(MILEN_CMD) == 0) {
			rearrangeList(guns);
		}
		else { // the command is "add x"
			int toAdd = stoi(input.substr(input.find(" "), input.length()));
			guns.addBack(toAdd);
		}
	}

	guns.print();

	return 0;
}

void rearrangeList(DoublyLinkedList<int>& guns) {
	if (guns.count > 1) {
		// sort out head
		guns.mid->next->prev = nullptr;
		guns.tail->next = guns.head;
		guns.head->prev = guns.tail;
		guns.head = guns.mid->next;
		guns.mid->next = nullptr;

		// sort out tail
		DoublyLinkedListNode<int>* temp = guns.tail;
		guns.tail = guns.mid;
		guns.tail->prev = guns.mid->prev;
		guns.tail->next = nullptr;

		// sort out mid
		if (guns.count % 2 == 0) {
			guns.mid = temp;
		}
		else {
			guns.mid = temp->prev;
		}
	}
}