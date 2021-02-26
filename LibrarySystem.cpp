/* Name: Hami Mert Doðan
 * CS201 Section 3
 * Student No: 21802550
 */
#include "LibrarySystem.h"

#include <iomanip>
#include <iostream>
using namespace std;

LibrarySystem::LibrarySystem()
{
	studentSize = 0;
	bookSize = 0;
}

LibrarySystem::~LibrarySystem()
{
}

void LibrarySystem::addBook(const int bookId, const std::string bookName, const int bookYear)
{
	if (bookId <= 0)
	{
		cout << "Book id's should be positive." << endl;
		return;
	}
	if (checkBook(bookId))
	{
		cout << "Book " << bookId << " already exists" << endl;
		return;
	}
	const Book newBook(bookId, bookName, bookYear);
	bookList.insert(1, newBook);
	bookSize++;
	cout << "Book " << bookId << " has been added" << endl;
}

void LibrarySystem::addStudent(const int studentId, const std::string studentName)
{
	if (studentId < 0)
	{
		cout << "Student id should be positive." << endl;
		return;
	}
	if (checkStudent(studentId))
	{
		cout << "Student " << studentId << " already exists" << endl;
		return;
	}
	Student newStudent(studentId, studentName);
	studentList.insert(1, newStudent);
	studentSize++;
	cout << "Student " << studentId << " has been added" << endl;
}

void LibrarySystem::checkoutBook(const int bookId, const int studentId)
{
	if (!checkBook(bookId))
	{
		cout << "Book " << bookId << " does not exist for checkout" << endl;
		return;
	}
	if (!checkStudent(studentId))
	{
		cout << "Student " << studentId << " does not exist for checkout" << endl;
		return;
	}
	int studentNo;
	if (!isCheckedOut(bookId, studentNo))
	{
		Student* s = NULL;
		bool isFoundStudent = false;
		bool isFoundBook = false;
		for (int i = 1; i < studentSize + 1; i++)
		{
			isFoundStudent = studentList.retrieve(i, s);
			if (studentId == s->getId())
			{
				break;
			}
		}
		Book* b = NULL;
		for (int i = 1; i < bookSize + 1; i++)
		{
			isFoundBook = bookList.retrieve(i, b);
			if (bookId == b->getId())
			{
				break;
			}
		}
		if (isFoundBook && isFoundStudent) 
		{
			s->addBook(*b);
			b->setIsCheckedOut(true);
			b->setCheckOutStudent(*s);
		}
	}
	else
	{
		cout << "Book " << bookId << " has been already checked out by another student" << endl;
	}
}

void LibrarySystem::deleteBook(const int bookId)
{
	if (!checkBook(bookId))
	{
		cout << "Book " << bookId << " does not exist" << endl;
		return;
	}
	int studentId;
	if (isCheckedOut(bookId, studentId))
	{
		returnBook(bookId);
	}
	else
	{
		cout << "Book " << bookId << " has not been checked out" << endl;
	}
	Book* b;
	bool isRemoved = false;
	for (int i = 1; i < bookSize + 1; i++)
	{
		const bool foundBook = bookList.retrieve(i, b);
		if (foundBook && bookId == b->getId())
		{
			isRemoved = bookList.remove(i);
		}
	}
	if (isRemoved) 
	{
		cout << "Book " << bookId << " has been deleted" << endl;
		bookSize--;
	}
	else
	{
		cout << "Removal was not successful." << endl;
	}
}

void LibrarySystem::deleteStudent(const int studentId)
{
	if (!checkStudent(studentId))
	{
		cout << "Student " << studentId << " does not exist." << endl;
		return;
	}
	Student* s;
	bool isRemoved = false;
	for (int i = 1; i < studentSize + 1; i++)
	{
		const bool foundStudent = studentList.retrieve(i, s);
		if (foundStudent && studentId == s->getId())
		{
			if (s->getCheckedOutBookSize() != 0) 
			{
				BookList* books = s->getBookList();
				Book* b;
				while (s->getCheckedOutBookSize() != 0)
				{
					books->retrieve(1, b);
					returnBook(b->getId());
				}
			}
			isRemoved = studentList.remove(i);
		}
	}
	if (isRemoved)
	{
		cout << "Student " << studentId << " has been deleted." << endl;
		studentSize--;
	}
	else
	{
		cout << "Removal was not successful." << endl;
	}
}

void LibrarySystem::returnBook(const int bookId)
{
	if (!checkBook(bookId))
	{
		cout << "Book " << bookId << " does not exist" << endl;
		return;
	}
	int studentId;
	const bool isCheckedOutByStudent = isCheckedOut(bookId, studentId);
	if (!isCheckedOutByStudent)
	{
		cout << "Book " << bookId << " has not been checked out" << endl;
	}
	else
	{
		Student* s;
		bool isFoundStudent;
		bool isFoundBook = false;
		for (int i = 1; i < studentSize + 1; i++)
		{
			isFoundStudent = studentList.retrieve(i, s);
			if (isFoundStudent && studentId == s->getId())
			{
				BookList* bList = s->getBookList();
				for (int k = 1; k < bList->getLength() + 1; k++)
				{
					Book* b;
					isFoundBook = bList->retrieve(k, b);
					if (isFoundBook && bookId == b->getId())
					{
						for (int j = 1; j < bookList.getLength() + 1; j++)
						{
							Book* listBook;
							bookList.retrieve(j, listBook);
							if (listBook->getId() == bookId)
							{
								Student nullStd;
								listBook->setCheckOutStudent(nullStd);
								listBook->setIsCheckedOut(false);
							}
						}
						bList->remove(k);
						s->setCheckedOutBookSize(bList->getLength());
						cout << "Book " << bookId << " has been returned" << endl;
						break;
					}
				}
				break;
			}
		}
	}
}

void LibrarySystem::showAllBooks() const
{
	if (bookSize != 0)
	{
		cout << left << setw(10) << "Book id" << left << setw(24) << "Book name" << setw(10) << "Year" << "Status" << endl;
		for (int i = 1; i < bookSize + 1; i++)
		{
			Book* b;
			bookList.retrieve(i, b);
			cout << left << setw(10) << b->getId() << left << setw(24) << b->getTitle() << setw(10) << b->getYear();
			if (b->getIsCheckedOut())
			{
				cout << "Checked out by student " << b->getCheckOutStudent()->getId() << endl;
			}
			else
			{
				cout << "Not checked out" << endl;
			}
		}
	}
	else
	{
		cout << "There are no books in the system" << endl;
	}
}

void LibrarySystem::showBook(const int bookId) const
{
	if (checkBook(bookId))
	{
		Book* b = NULL;
		for (int i = 1; i < bookSize + 1; i++)
		{
			const bool isFound = bookList.retrieve(i, b);
			if (isFound && b->getId() == bookId)
			{
				cout << left << setw(10) << b->getId() << left << setw(24) << b->getTitle() << setw(10) << b->getYear();
				if (b->getIsCheckedOut())
				{
					cout << "Checked out by student " << b->getCheckOutStudent()->getId() << endl;
					break;
				}
				else
				{
					cout << "Not checked out" << endl;
					break;
				}
			}
		}
	}
	else
	{
		cout << "Book " << bookId << " does not exist" << endl;
	}
}

void LibrarySystem::showStudent(const int studentId) const
{
	if (!checkStudent(studentId))
	{
		cout << "Student " << studentId << " does not exist." << endl;
		return;
	}
	Student* s = NULL;
	for (int i = 1; i < studentSize + 1; i++)
	{
		const bool foundStudent = studentList.retrieve(i, s);
		if (foundStudent && studentId == s->getId())
		{
			cout << "Student id: " << s->getId() << " Student name: " << s->getName() << endl;
			break;
		}
	}
	if (s->getCheckedOutBookSize() != 0) {
		cout << "Student " << studentId << " has checked out the following books:" << endl;
		s->printBookList();
	}
	else 
	{
		cout << "Student " << studentId << " has no books" << endl;
	}
}

bool LibrarySystem::checkStudent(const int id) const
{
	if (studentList.getLength() == 0)
	{
		return false;
	}
	for (int i = 1; i < studentList.getLength() + 1; i++)
	{
		Student* s = NULL;
		const bool foundStudent = studentList.retrieve(i, s);
		if (foundStudent && s->getId() == id)
		{
			return true;
		}
	}
	return false;
}

bool LibrarySystem::checkBook(const int id) const
{
	if (bookList.getLength() == 0)
	{
		return false;
	}
	for (int i = 1; i < bookList.getLength() + 1; i++)
	{
		Book* b;
		const bool foundBook = bookList.retrieve(i, b);
		if (foundBook && b->getId() == id)
		{
			return true;
		}
	}
	return false;
}

bool LibrarySystem::isCheckedOut(const int bookId, int& studentId) const
{
	for (int i = 1; i < studentSize + 1; i++)
	{
		Student* s;
		studentList.retrieve(i, s);
		if (s->checkBookOfStudent(bookId))
		{
			studentId = s->getId();
			return true;
		}
	}
	studentId = 0;
	return false;
}
