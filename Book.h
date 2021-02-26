/* Name: Hami Mert Doðan
 * CS201 Section 3
 * Student No: 21802550
 */
#ifndef __BOOK_H
#define __BOOK_H
#include <string>

class Student;

class Book
{
private:
	int id;
	std::string title;
	int year;
	bool isCheckedOut;
	Student* checkOutStudent;
public:
	Book();
	Book(const int bookId, const std::string& bookTitle, const int bookYear);
	~Book();
	Book(const Book& R);
	
	int getId() const;
	std::string getTitle() const;
	int getYear() const;
	bool getIsCheckedOut() const;
	Student* getCheckOutStudent() const;
	
	void setId(int newId);
	void setTitle(std::string newTitle);
	void setYear(int newYear);
	void setIsCheckedOut(bool checkOut);
	void setCheckOutStudent(Student& S);
};
#endif
