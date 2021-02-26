/* Name: Hami Mert Doðan
 * CS201 Section 3
 * Student No: 21802550
 */
#include "Student.h"

#include <iomanip>

#include "BookList.h"
#include <iostream>
using namespace std;

Student::Student()
{
	id = 0;
	name = "noName";
	checkedOutBooks = 0;
}

Student::Student(const int studentId, const std::string& studentName)
{
	id = studentId;
	name = studentName;
	checkedOutBooks = 0;
}

Student::~Student()
{
}

Student::Student(Student& R)
{
	this->id = R.id;
	this->name = R.name;
	this->checkedOutBooks = R.checkedOutBooks;
	this->studentBookList = R.studentBookList;
}

Student& Student::operator=(const Student& R)
{
	this->id = R.id;
	this->name = R.name;
	this->checkedOutBooks = R.checkedOutBooks;
	this->studentBookList = R.studentBookList;
	return *this;
}

int Student::getId() const
{
	return id;
}

std::string Student::getName() const
{
	return name;
}

void Student::setId(int& newId)
{
	id = newId;
}

void Student::setName(std::string& newName)
{
	name = newName;
}

void Student::setCheckedOutBookSize(int newSize)
{
	checkedOutBooks = newSize;
}

bool Student::addBook(Book& b)
{
	if (checkBookOfStudent(b.getId()))
	{
		cout << "Book " << b.getId() << " already has been checked out by this student" << endl;
		return false;
	}
	studentBookList.insert(1, b);
	checkedOutBooks++;
	cout << "Book " << b.getId() << " has been checked out by student " << id << endl;
	return true;
}

BookList* Student::getBookList()
{
	return &studentBookList;
}

bool Student::checkBookOfStudent(int bookId) const
{
	if (studentBookList.isEmpty())
	{
		return false;
	}
	for (int i = 1; i < studentBookList.getLength() + 1; i++)
	{
		Book* b;
		const bool foundBook = studentBookList.retrieve(i, b);
		if (foundBook && b->getId() == bookId)
		{
			return true;
		}
	}
	return false;
}

int Student::getCheckedOutBookSize() const
{
	return checkedOutBooks;
}

bool Student::printBookList() const
{
	if (checkedOutBooks != 0)
	{
		cout << left << setw(10) << "Book id" << left << setw(24) << "Book name" << setw(4) << "Year" << endl;
		for (int i = 1; i < checkedOutBooks + 1; i++)
		{
			Book* b;
			studentBookList.retrieve(i, b);
			cout << left << setw(10) << b->getId() << left << setw(24) << b->getTitle() << setw(4) << b->getYear() << endl;
		}
		return true;
	}
	return false;
}
