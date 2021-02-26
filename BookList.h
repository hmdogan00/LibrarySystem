/* Name: Hami Mert Doðan
 * CS201 Section 3
 * Student No: 21802550
 */
#ifndef __BOOKLIST_H
#define __BOOKLIST_H
#include "Book.h"

class BookList
{
private:
	struct BookNode
	{
		Book item;
		BookNode* next;
	};

	BookNode* head;
	int size;
	BookNode* find(int index) const;
public:
	BookList();
	~BookList();
	BookList(const BookList& R);
	BookList& operator=(BookList R);
	bool isEmpty() const;
	int getLength() const;
	bool insert(int index, Book newItem);
	bool remove(int index);
	bool retrieve(int index, Book*& dataItem) const;
};
#endif

