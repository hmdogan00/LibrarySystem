/* Name: Hami Mert Doðan
 * CS201 Section 3
 * Student No: 21802550
 */
#ifndef __STUDENT_H
#define __STUDENT_H

#include <string>
#include "BookList.h"


class Student
{
private:
	int id;
	int checkedOutBooks;
	std::string name;
	BookList studentBookList;
public:
	Student();
	Student(const int studentId, const std::string& studentName);
	Student(Student& R);
	~Student();
	Student& operator=(const Student& R);
	
	int getId() const;
	std::string getName() const;
	int getCheckedOutBookSize() const;
	
	void setId(int& newId);
	void setName(std::string& newName);
	void setCheckedOutBookSize(int newSize);
	
	bool addBook(Book& b);
	BookList* getBookList();
	bool checkBookOfStudent(int id) const;
	bool printBookList() const;
};
#endif