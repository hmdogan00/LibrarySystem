/* Name: Hami Mert Doðan
 * CS201 Section 3
 * Student No: 21802550
 */
#ifndef __STUDENT_LIST_H
#define __STUDENT_LIST_H

#include "Student.h"

class StudentList
{
private:
	struct StudentNode
	{
		Student item;
		StudentNode* next;
	};

	StudentNode* head;
	int size;
	StudentNode* find(int index) const;
public:
	StudentList();
	~StudentList();
	StudentList(const StudentList& R);
	StudentList& operator=(StudentList R);
	
	bool isEmpty() const;
	int getLength() const;
	
	bool insert(int index, const Student newItem);
	bool remove(int index);
	bool retrieve(int index, Student*& dataItem) const;
};
#endif

