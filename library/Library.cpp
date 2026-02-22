#include "Library.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

double totalBorrowedBooks = 0;

inline void removeElement(std::vector<std::string>& vec, const std::string& target) {
    auto it = std::find(vec.begin(), vec.end(), target);
    
    if (it != vec.end()) {
        vec.erase(it);
    }
}

Library::Library() : totalBorrowedBooks(0), reservedCount(0) {}

void Library::listBooks() {
  for (const auto& book : bookList) {
    std::cout << book << endl;
  }
}

void Library::addBook(std::string title, double cost) {
  if (bookList.size() < 100) {
    bookList.push_back(title);
    libraryBudget += cost;
  } else {
    std::cout << "Library is full!" << endl;
  }
}

bool Library::borrowBook(std::string title) {
  std::vector<std::string>::iterator it = std::find(bookList.begin(), bookList.end(), title);
  if (it != bookList.end()) { 
    totalBorrowedBooks++;
    removeElement(bookList, title);
    std::cout << "Book borrowed!" << endl;
    return true;
  }

  std::cout << "Book not found!" << endl;

  return false;
}

void Library::reserveBook(std::string title) {
  std::vector<std::string>::iterator inBookList = std::find(bookList.begin(), bookList.end(), title);

  std::vector<std::string>::iterator inReservedBooks = std::find(reservedBooks.begin(), reservedBooks.end(), title);

  if (inBookList != bookList.end() && inReservedBooks == reservedBooks.end()) {
    reservedCount++;
    std::cout << "Book reserved: " << title << endl;
    reservedBooks.push_back(title);
    std::cout << "Reserved book count: " << reservedCount << endl;
  } else {
    std::cout << "Book not reserved!";
  }
}
