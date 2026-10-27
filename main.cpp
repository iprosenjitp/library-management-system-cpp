#include <bits/stdc++.h>

using namespace std;

class Book {
private:
    string title, author;
    const int book_id;
    int total_copies, available_copies;
    static int total_books, next_book_id;

    void registerBook() {
        next_book_id++;
        total_books++;
    }

public:
    Book() :
        title("Unknown"),
        author("Unknown"),
        book_id(next_book_id),
        total_copies(0),
        available_copies(0) {
            registerBook();
        }

    Book(const string& title, const string& author, int total_copies) :
        title(title),
        author(author),
        book_id(next_book_id),
        total_copies(total_copies),
        available_copies(total_copies) {
            registerBook();
        }

    Book(const Book& book) = delete;
//    :
//        title(book.title),
//        author(book.author),
//        book_id(next_book_id),
//        total_copies(book.total_copies),
//        available_copies(book.available_copies) {
//            registerBook();
//        }

    Book& operator = (const Book& other) = delete;
//    {
//        if (this == &other) return *this;
//        title = other.title;
//        author = other.author;
//        book_id = other.book_id;
//        return *this;
//    }

    int getBookId() const {
        return book_id;
    }

    string getBookTitle() const {
        return title;
    }

    string getBookAuthor() const {
        return author;
    }

    int getTotalCopies() const {
        return total_copies;
    }

    int getAvailableCopies() const {
        return available_copies;
    }

    static int getTotalBooks() {
        return total_books;
    }

    void updateBookTitle(const string& new_title) {
        title = new_title;
    }

    void updateBookAuthor(const string& new_author) {
        author = new_author;
    }

    void displayBook() const {
        cout << "Book Title - " << title << "\n";
        cout << "Author - " << author << "\n";
        cout << "Book Id - " << book_id << "\n";
        cout << "Total Copies - " << total_copies << "\n";
        cout << "Available Copies - " << available_copies << "\n";
        cout << "\n";
    }

    void displayBookCount() const {
        cout << "Total Books - " << total_books << "\n";
    }

    ~Book() {
        total_books--;
        cout << "Book object destroyed\n";
    }
};

int Book::total_books = 0;
int Book::next_book_id = 101;

int main() {
    Book book_1("The C++ Programming Language", "Bjarne Stroustrup", 5);
    book_1.displayBook();

    Book book_2("Clean Code", "Robert C. Martin", 6);
    book_2.displayBook();

    Book book_3("Effective Modern C++", "Scott Meyers", 10);
    book_3.displayBook();

    Book book_4;
    book_4.displayBook();

//    Book book_5(book_1);
//    book_4 = book_1;
//    book_4.displayBook();
    Book book_5;
    cout << Book::getTotalBooks() << "\n";
    book_5.displayBook();
    book_5.updateBookTitle("New C++ Book");

//    book_1.displayBook();
//    book_5.displayBook();

//    book_5.displayBookCount();
//    int total_books = Book::getTotalBooks();
    int total_books = book_5.getTotalBooks();
    cout << "Total Books - " << total_books << "\n";

    {
        Book book_6;
        cout << Book::getTotalBooks() << "\n";
    }

    cout << Book::getTotalBooks() << "\n";
}

/*
    total_books++;
    string title = "The C++ Programming Language";
    string author = "Bjarne Stroustrup";
    int book_id = 101;
    book_1.updateBookTitle(title);
    book_1.updateBookAuthor(author);
    book_1.updateBookId(book_id);
    book_1.displayBook();
    string new_title = "C++ Primer";
    book_1.updateBookTitle(new_title);
    book_1.displayBook();
    int book_1_id = book_1.getBookId();
    string book_1_title = book_1.getBookTitle();
    string book_1_author = book_1.getBookAuthor();
    cout << book_1_id << " - " << book_1_title << " - " << book_1_author << "\n";

    Book book_2;
    total_books++;
    title = "Clean Code";
    author = "Robert C. Martin";
    book_id = 102;
    book_2.updateBookTitle(title);
    book_2.updateBookAuthor(author);
    book_2.updateBookId(book_id);
    book_2.displayBook();
    string new_author = "Robert C. Martin (Updated)";
    book_2.updateBookAuthor(new_author);
    book_2.displayBook();
    string book_2_author = book_2.getBookAuthor();
    cout << "Book 2 Author - " << book_2_author << "\n";

    Book book_3;
    total_books++;
    title = "Effective Modern C++";
    author = "Scott Meyers";
    book_id = 103;
    book_3.updateBookTitle(title);
    book_3.updateBookAuthor(author);
    book_3.updateBookId(book_id);
    book_3.displayBook();
    int new_book_id = 303;
    book_3.updateBookId(new_book_id);
    book_3.displayBook();

    book_3.displayBookCount(total_books);
*/
