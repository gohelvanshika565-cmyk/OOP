#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

// ==========================================
// 1. Abstract Base Class: LibraryItem
// ==========================================
class LibraryItem {
private:
    // Encapsulated data members
    string title;
    string author;
    string dueDate;

public:
    // Constructor
    LibraryItem(string t, string a, string d) {
        title = t;
        author = a;
        dueDate = d;
    }

    // Virtual Destructor
    virtual ~LibraryItem() {}

    // Public Getters (Const so they can be called inside const functions)
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

    // Public Setters
    void setTitle(string newTitle) { title = newTitle; }
    void setAuthor(string newAuthor) { author = newAuthor; }
    void setDueDate(string newDueDate) { dueDate = newDueDate; }

    // Pure virtual functions (Abstraction)
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};

// ==========================================
// 2. Derived Class: Book
// ==========================================
class Book : public LibraryItem {
private:
    string isbn;
    int quantity;

public:
    Book(string t, string a, string d, string i, int q) : LibraryItem(t, a, d) {
        // Exception Handling: Invalid Input Checks
        if (q < 0) {
            throw invalid_argument("Error: Book quantity cannot be negative!");
        }
        if (i.length() < 5) {
            throw invalid_argument("Error: Incorrect ISBN format! Must be at least 5 characters long.");
        }
        isbn = i;
        quantity = q;
    }

    void checkOut() override {
        if (quantity > 0) {
            quantity--;
            cout << "Book '" << getTitle() << "' checked out successfully! Remaining: " << quantity << endl;
        } else {
            cout << "Sorry, Book '" << getTitle() << "' is currently out of stock!" << endl;
        }
    }

    void returnItem() override {
        quantity++;
        cout << "Book '" << getTitle() << "' returned successfully! Total Stock: " << quantity << endl;
    }

    void displayDetails() const override {
        cout << "[Book] Title: " << getTitle() << " | Author: " << getAuthor()<< " | Due Date: " << getDueDate()<< " | ISBN: " << isbn << " | Qty: " << quantity << endl;
    }
};

// ==========================================
// 3. Derived Class: DVD
// ==========================================
class DVD : public LibraryItem {
private:
    int duration; // Duration in minutes
    bool isCheckedOut;

public:
    DVD(string t, string a, string d, int dur) : LibraryItem(t, a, d) {
        if (dur <= 0) {
            throw invalid_argument("Error: DVD duration must be positive!");
        }
        duration = dur;
        isCheckedOut = false;
    }

    void checkOut() override {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << "DVD '" << getTitle() << "' checked out successfully!" << endl;
        } else {
            cout << "Sorry, DVD '" << getTitle() << "' is already checked out!" << endl;
        }
    }

    void returnItem() override {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << "DVD '" << getTitle() << "' returned successfully!" << endl;
        } else {
            cout << "This DVD was not checked out!" << endl;
        }
    }

    void displayDetails() const override {
        cout << "[DVD] Title: " << getTitle() << " | Director: " << getAuthor() << " | Due Date: " << getDueDate() << " | Duration: " << duration << " mins | Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }
};

// ==========================================
// 4. Derived Class: Magazine
// ==========================================
class Magazine : public LibraryItem {
private:
    int issueNumber;
    bool isCheckedOut;

public:
    Magazine(string t, string a, string d, int issue) : LibraryItem(t, a, d) {
        issueNumber = issue;
        isCheckedOut = false;
    }

    void checkOut() override {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << "Magazine '" << getTitle() << "' checked out successfully!" << endl;
        } else {
            cout << "Sorry, Magazine '" << getTitle() << "' is already checked out!" << endl;
        }
    }

    void returnItem() override {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << "Magazine '" << getTitle() << "' returned successfully!" << endl;
        } else {
            cout << "This Magazine was not checked out!" << endl;
        }
    }

    void displayDetails() const override {
        cout << "[Magazine] Title: " << getTitle() << " | Publisher: " << getAuthor()<< " | Due Date: " << getDueDate() << " | Issue No: " << issueNumber << " | Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }
};


// ==========================================
// Main Function (User Interaction Interface)
// ==========================================
int main() {
    // Array of base class pointers for Polymorphism
    LibraryItem* libraryItems[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    while (true) {
        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add a Book\n";
        cout << "2. Add a DVD\n";
        cout << "3. Add a Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Search & Check Out Item\n";
        cout << "6. Search & Return Item\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                if (itemCount >= MAX_ITEMS) throw overflow_error("Library catalog is full!");
                
                string title, author, due, isbn;
                int qty;
                
                cout << "Enter Book Title: "; cin >> title;
                cout << "Enter Author: "; cin >> author;
                cout << "Enter Due Date (e.g. 15-May): "; cin >> due;
                cout << "Enter ISBN: "; cin >> isbn;
                cout << "Enter Quantity: "; cin >> qty;

                // Dynamic Memory Allocation
                libraryItems[itemCount] = new Book(title, author, due, isbn, qty);
                itemCount++;
                cout << "=> Book added successfully!\n";
            }
            else if (choice == 2) {
                if (itemCount >= MAX_ITEMS) throw overflow_error("Library catalog is full!");
                
                string title, director, due;
                int duration;
                
                cout << "Enter DVD Title: "; cin >> title;
                cout << "Enter Director: "; cin >> director;
                cout << "Enter Due Date (e.g. 15-May): "; cin >> due;
                cout << "Enter Duration (mins): "; cin >> duration;

                // Dynamic Memory Allocation
                libraryItems[itemCount] = new DVD(title, director, due, duration);
                itemCount++;
                cout << "=> DVD added successfully!\n";
            }
            else if (choice == 3) {
                if (itemCount >= MAX_ITEMS) throw overflow_error("Library catalog is full!");
                
                string title, publisher, due;
                int issue;
                
                cout << "Enter Magazine Title: "; cin >> title;
                cout << "Enter Publisher: "; cin >> publisher;
                cout << "Enter Due Date (e.g. 15-May): "; cin >> due;
                cout << "Enter Issue Number: "; cin >> issue;

                // Dynamic Memory Allocation
                libraryItems[itemCount] = new Magazine(title, publisher, due, issue);
                itemCount++;
                cout << "=> Magazine added successfully!\n";
            }
            else if (choice == 4) {
                if (itemCount == 0) {
                    cout << "=> No items in the library.\n";
                } else {
                    cout << "\n--- Library Catalog ---\n";
                    for (int i = 0; i < itemCount; i++) {
                        // Polymorphism in action
                        libraryItems[i]->displayDetails(); 
                    }
                }
            }
            else if (choice == 5) {
                string searchTitle;
                cout << "Enter Title of the item to Check Out: "; cin >> searchTitle;
                bool found = false;
                
                for (int i = 0; i < itemCount; i++) {
                    if (libraryItems[i]->getTitle() == searchTitle) {
                        libraryItems[i]->checkOut(); // Polymorphism
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "=> Item not found in catalog!\n";
            }
            else if (choice == 6) {
                string searchTitle;
                cout << "Enter Title of the item to Return: "; cin >> searchTitle;
                bool found = false;
                
                for (int i = 0; i < itemCount; i++) {
                    if (libraryItems[i]->getTitle() == searchTitle) {
                        libraryItems[i]->returnItem(); // Polymorphism
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "=> Item not found in catalog!\n";
            }
            else if (choice == 7) {
                cout << "Exiting system. Cleaning up memory...\n";
                break;
            }
            else {
                cout << "Invalid choice! Please try again.\n";
            }
        } 
        // Exception Handling block
        catch (const invalid_argument& e) {
            cout << "\n[Input Error] " << e.what() << "\n";
        }
        catch (const overflow_error& e) {
            cout << "\n[Memory Error] " << e.what() << "\n";
        }
        catch (...) {
            // General exception handler
            cout << "\n[Unknown Error] An unexpected exception occurred!\n";
        }
    }

    // Freeing memory with delete
    for (int i = 0; i < itemCount; i++) {
        delete libraryItems[i];
    }

    return 0;
}
