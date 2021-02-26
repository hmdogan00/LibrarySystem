/* Name: Hami Mert Doðan
 * CS201 Section 3
 * Student No: 21802550
 */
#include "StudentList.h"

StudentList::StudentList()
{
	head = NULL;
	size = 0;
}

StudentList::~StudentList()
{
	while (!isEmpty())
		remove(1);
}

StudentList::StudentList(const StudentList& R) : size(R.size)
{
	if (R.head == NULL)
	{
		head = NULL;
	}
	else
	{
		head = new StudentNode;
		head->item = R.head->item;
		StudentNode* newPtr = head;

		for (StudentNode* origPtr = R.head->next; origPtr != NULL; origPtr = origPtr->next)
		{
			newPtr->next = new StudentNode;
			newPtr = newPtr->next;
			newPtr->item = origPtr->item;
		}
		newPtr->next = NULL;
	}
}

StudentList& StudentList::operator=( StudentList R)
{
	std::swap(head, R.head);
	return *this;
}

StudentList::StudentNode* StudentList::find(int index) const
{
	if ((index < 1) || (index > getLength()))
	{
		return NULL;
	}
	StudentNode* cur = head;
	for (int skip = 1; skip < index; ++skip)
	{
		cur = cur->next;
	}
	return cur;
}

int StudentList::getLength() const
{
	return size;
}

bool StudentList::insert(int index, const Student newItem)
{
	if ((index < 1) || (index > getLength() + 1))
	{
		return false;
	}
	StudentNode* newPtr = new StudentNode;
	size = getLength() + 1;
	newPtr->item = newItem;
	if (index == 1)
	{
		newPtr->next = head;
		head = newPtr;
	}
	else
	{
		StudentNode* prev = find(index - 1);
		newPtr->next = prev->next;
		prev->next = newPtr;
	}
	return true;
}

bool StudentList::isEmpty() const
{
	return size == 0;
}

bool StudentList::remove(int index)
{
	if ((index < 1) || (index > getLength()))
	{
		return false;
	}
	StudentNode* cur;
	--size;
	if (index == 1)
	{
		cur = head;
		head = cur->next;
	}
	else
	{
		StudentNode* prev = find(index - 1);
		cur = prev->next;
		prev->next = cur->next;
	}
	cur->next = NULL;
	delete cur;
	cur = NULL;
	return true;
}

bool StudentList::retrieve(int index, Student*& dataItem) const
{
	if ((index < 1) || (index > getLength()))
	{
		return false;
	}
	StudentNode* cur = find(index);
	dataItem = &(cur->item);
	return true;
}
