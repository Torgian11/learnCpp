#include <vector>
#include <string>

using namespace std;

extern double libraryBudget;

class Library {
  private:
    std::vector<std::string> bookList;
    int totalBorrowedBooks;
    int reservedCount;
    std::vector<std::string> reservedBooks;

  public:
    void addBook(std::string title, double bookCost);
    
    bool borrowBook(std::string title);
    void listBooks();
    
    Library();
    
    int getTotalBorrowedBooks() {
      return totalBorrowedBooks;
    };
    
    void reserveBook(std::string title);
};
