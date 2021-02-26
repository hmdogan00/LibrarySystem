/* Name: Hami Mert Doðan
 * CS201 Section 3
 * Student No: 21802550
 */
#ifndef __LIBRARYSYSTEM_H
#define __LIBRARYSYSTEM_H
#include <string>

#include "BookList.h"
#include "StudentList.h"

class LibrarySystem {
private:
	BookList bookList;
	StudentList studentList;
	int bookSize;
	int studentSize;
public:
	LibrarySystem();
	~LibrarySystem();
	void addBook(const int bookId, const std::string bookName, const int bookYear);
	void deleteBook(const int bookId);
	void addStudent(const int studentId, const std::string studentName);
	void deleteStudent(const int studentId);
	void checkoutBook(const int bookId, const int studentId);
	void returnBook(const int bookId);
	void showAllBooks() const;
	void showBook(const int bookId) const;
	void showStudent(const int studentId) const;
	bool checkStudent(const int id) const;
	bool checkBook(const int id) const;
	bool isCheckedOut(const int bookId, int& studentId) const;
	bool printBookList() const;
};
#endif
