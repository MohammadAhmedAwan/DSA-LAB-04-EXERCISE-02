#include "CList.h"

CList::CList() {
	head = NULL;
}

bool CList::emptyList() {
	return head == NULL; 
}

void CList::insertafter(int old, int New) {
	node* current = head; 

	if (head == NULL) {
		head = new node(old);
		head->set_next(head); 
	}

	do {
		if (current->get_val() == old) {
			node* Newnode = new node(New);
			Newnode->set_next(current->get_next());
			current->set_next(Newnode);
			return;
		}
		current = current->get_next();
	} while (current != head); 

	node* Newnode = new node(New);
	current->set_next(Newnode);
	Newnode->set_next(head); 
}


void CList::deleteNode(int pos) {
	if (head == NULL) {
		cout << "List is empty" << endl;
		return;
	}

	if (pos == 0) {
		cout << "Cannot delete the first node" << endl;
		return; 
	}

	node* current = head;
	node* prev = nullptr;
	int index = 0;

	do {
		if (index == pos) {
			if (prev != nullptr) {
				prev->set_next(current->get_next());
			}

			delete current;
			return; 
		}

		prev = current;
		current = current->get_next();
		index++;
	} while (current != head);

	cout << "Position: " << pos << " not found in the list" << endl;
}

void CList::delete_begin() {
	if (head == NULL) {
		cout << "List is empty" << endl;
		return; 
	}

	if (head->get_next() == head) {
		delete head;
		head = NULL; 
	}
	else {
		node* temp = head;
		
		node* tail = head;
		while (tail->get_next() != head) {
			tail = tail->get_next();
		}
		head = head->get_next(); 
		tail->set_next(head); 
		delete temp; 
	}
}

void CList::delete_end() {
	if (head == NULL) {
		cout << "List is empty" << endl;
		return; 
	}

	if (head->get_next() == head) {
		
		delete head;
		head = NULL; 
		return;
	}

	node* current = head;
	node* prev = NULL;

	
	while (current->get_next() != head) {
		prev = current;
		current = current->get_next();
	}

	
	prev->set_next(head); 
	delete current; 
}





void CList::insert_begin(int value) {
	node* Newnode = new node(value);
	if (head == NULL) {
		head = Newnode;
		head->set_next(head); 
	}
	else {
		node* tail = head;
		while (tail->get_next() != head) {
			tail = tail->get_next();
		}
		tail->set_next(Newnode);
		Newnode->set_next(head); 
		head = Newnode; 
	}
}

void CList::insert_end(int value) {
	node* Newnode = new node(value);
	if (head == NULL) {
		head = Newnode;
		head->set_next(head); 
	}
	else {
		node* current = head;
		while (current->get_next() != head) {
			current = current->get_next();
		}
		current->set_next(Newnode);
		Newnode->set_next(head); 
	}
}

void CList::traverse() {
	if (head == NULL) {
		cout << "List is empty" << endl;
		return;
	}

	node* current = head;
	do {
		cout << current->get_val() << endl;
		current = current->get_next();
	} while (current != head);
	cout << endl;
}

int main() {
	CList* a = new CList;
	a->insert_begin(1);
	a->insert_begin(2);
	a->insert_end(3);
	a->insert_end(4);


	cout << "Node:\n";
	a->traverse();

	cout << "deleat begin:\n";
	a->delete_begin();
	a->traverse();

	cout << "deleat end:\n";
	a->delete_end();
	a->traverse();



}
