/* Name: Hami Mert Doðan
 * CS201 Section 3
 * Student No: 21802550
 */
#include "BookList.h"
#include <iostream>
using namespace std;

BookList::BookList()
{
	head = NULL;
	size = 0;
}

BookList::~BookList()
{
	while (!isEmpty()) {
		remove(1);
	}
}

BookList::BookList(const BookList& R) : size(R.size)
{
	if (R.head == NULL)
	{
		head = NULL;
	}
	else
	{
		head = new BookNode;
		head->item = R.head->item;
		BookNode* newPtr = head;

		for (BookNode* origPtr = R.head->next; origPtr != NULL; origPtr = origPtr->next)
		{
			newPtr->next = new BookNode;
			newPtr = newPtr->next;
			newPtr->item = origPtr->item;
		}
		newPtr->next = NULL;
	}
}

BookList& BookList::operator=(BookList R)
{
	if (R.head == NULL)
	{
		head = NULL;
		size = 0;
	}
	else
	{
		head = new BookNode;
		head->item = R.head->item;
		BookNode* newPtr = head;
		size = 1;
		for (BookNode* origPtr = R.head->next; origPtr != NULL; origPtr = origPtr->next)
		{
			newPtr->next = new BookNode;
			newPtr = newPtr->next;
			newPtr->item = origPtr->item;
			size++;
		}
		newPtr->next = NULL;
	}
	return *this;
}

BookList::BookNode* BookList::find(int index) const
{
	if ((index < 1) || (index > getLength()))
	{
		return NULL;
	}
	BookNode* cur = head;
	for (int skip = 1; skip < index; ++skip)
	{
		cur = cur->next;
	}
	return cur;
}

int BookList::getLength() const
{
	return size;
}

bool BookList::insert(int index, Book newItem)
{
	if ((index < 1) || (index > getLength() + 1))
	{
		return false;
	}
	BookNode* newPtr = new BookNode;
	size = getLength() + 1;
	newPtr->item = newItem;
	if (index == 1)
	{
		newPtr->next = head;
		head = newPtr;
	}
	else
	{
		BookNode* prev = find(index - 1);
		newPtr->next = prev->next;
		prev->next = newPtr;
	}
	return true;
}

bool BookList::isEmpty() const
{
	return size == 0;
}

bool BookList::remove(int index)
{
	if ((index < 1) || (index > getLength()))
	{
		return false;
	}
	BookNode* cur;
	--size;
	if (index == 1)
	{
		cur = head;
		head = cur->next;
	}
	else
	{
		BookNode* prev = find(index - 1);
		cur = prev->next;
		prev->next = cur->next;
	}
	cur->next = NULL;
	delete cur;
	cur = NULL;
	return true;
}

bool BookList::retrieve(int index, Book*& dataItem) const
{
	if ((index < 1) || (index > getLength()))
	{
		return false;
	}
	BookNode* cur = find(index);
	dataItem = &(cur->item);
	return true;
}


