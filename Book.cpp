/* Name: Hami Mert Doðan
 * CS201 Section 3
 * Student No: 21802550
 */
#include "Book.h"
#include "Student.h"

Book::Book()
{
	id = 0;
	title = "";
	year = 1900;
	isCheckedOut = false;
	checkOutStudent = NULL;
}

Book::Book(const int bookId, const std::string& bookTitle, const int bookYear)
{
	id = bookId;
	title = bookTitle;
	year = bookYear;
	isCheckedOut = false;
	checkOutStudent = NULL;
}

Book::~Book()
{
	if (!checkOutStudent)
		delete checkOutStudent;
}

Book::Book(const Book& R)
{
	this->id = R.id;
	this->title = R.title;
	this->year = R.year;
	this->isCheckedOut = R.isCheckedOut;
	this->checkOutStudent = R.checkOutStudent;
}

int Book::getId() const
{
	return id;
}

std::string Book::getTitle() const
{
	return title;
}

int Book::getYear() const
{
	return year;
}

bool Book::getIsCheckedOut() const
{
	return isCheckedOut;
}

Student* Book::getCheckOutStudent() const
{
	return checkOutStudent;
}

void Book::setCheckOutStudent(Student& S)
{
	checkOutStudent = &S;
}

void Book::setIsCheckedOut(bool checkOut)
{
	isCheckedOut = checkOut;
}

void Book::setId(int newId)
{
	id = newId;
}

void Book::setTitle(std::string newTitle)
{
	title = newTitle;
}

void Book::setYear(int newYear)
{
	year = newYear;
}
