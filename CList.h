#include"node.h"


class CList
{
private:
	node* head; 

public:
	
	CList();

	
	bool emptyList();

	
	void insertafter(int oldV, int newV);

	
	void insert_begin(int value);

	
	void insert_end(int value);

	
	void deleteNode(int pos);

	void delete_begin();

	void delete_end();

	void traverse();
};