#include <bits/stdc++.h>
using namespace std;

class HashingWithChaining {
	int slots;		// total number of slots in the hash table
	list<int> *table;		// pointer to a hash table

public:
	HashingWithChaining(int slots);		// constructor
	void insertItem(int x);
	void deleteItem(int key);
	void display();
	int getHashKey(int x) {
		return x % slots;
	}
};

// constructor
HashingWithChaining::HashingWithChaining(int slots) {
	this->slots = slots;	
	table = new list<int>[slots];
}

// insert an item into the hash table
void HashingWithChaining::insertItem(int x) {
	int hashKey = getHashKey(x);	// get the hash key
	table[hashKey].push_back(x);
}

// delete an item from the hash table
void HashingWithChaining::deleteItem(int x) {
	int hashKey = getHashKey(x);

	list<int> :: iterator itr; // get the iterator for the given list
	for (itr = table[hashKey].begin(); itr != table[hashKey].end(); itr++)
		if (x == *itr)
			break;

	if (itr != table[hashKey].end())
		table[hashKey].erase(itr);
}

// display all the elements in the given hash table
void HashingWithChaining::display() {
	for (int i=0; i<slots; i++) {
		cout << i << " -> ";
		for (auto val : table[i])
			cout << val << "   ";
		cout << endl; 
	}
}

int main() {
	int a[] = {15, 20, 8, 29, 33, 87, 100, 102, 25, 30};
	int n = sizeof(a) / sizeof(a[0]);	// size of the given array

	HashingWithChaining h(15);	// create a hash table with 15 slots

	// insert the items from array into the given hash table
	for (int i=0; i<n; i++) 
		h.insertItem(a[i]);

	// display
	cout << "Initial elements in hash table" << endl;
	h.display();

	// delete 100 from hash table
	h.deleteItem(100);

	cout << endl;
	cout << "After deleting 100 from hash table" << endl;

	// again display
	h.display();

	return 0;
}
