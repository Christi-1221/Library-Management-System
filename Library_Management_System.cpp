#include <iostream>
#include <string>
using namespace std;

bool login(int& attempt);
void register_user();
void main_portal();
void add_book();
void show_all_books();
void search_book();
void borrow_book();
void return_book();

const int MAX_USERS = 10;
string users[MAX_USERS][2];
int userCount = 0;

const int MAX_BOOKS = 20;
string books[MAX_BOOKS];
bool borrowed[MAX_BOOKS] = {false}; // false = available, true = borrowed
int bookCount = 0;

int main() {
	// VARIABLES
    int choice, login_attempt = 0;
    bool running = true;
    
    while(running) {
    	system("cls");
    	cout<<"==== WELCOME TO LIBRARY MANAGEMENT SYSTEM ===="<<endl;
    	cout<<"[1]Register"<<endl;
    	cout<<"[2]Login"<<endl;
    	cout<<"[3]Exit"<<endl;
    	cout<<"Enter your choice: ";
    	
    	cin>>choice;
    	cin.ignore();
    
    	// SWITCH CASE 
    	switch(choice) {
	    	case 1:
	    		register_user();
	    		break;
	    	case 2:
	    		if (login_attempt < 3) {
				    bool success = login(login_attempt);
				    if (success) {
				        main_portal();
				    }
				} else {
                    cout << "LOGIN ATTEMPT REACHED, ACCESS DENIED";
                    running = false;
                }
                break;
	    	case 3:
	    		cout << "Exiting program...";
                running = false;
                break;
	    	default:
	    		cout<<"INVALID INPUT";
	    		cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
		}	
	}
    
	return 0;
}

bool login(int& attempt){
    system("cls");
    string username, password;
    bool found = false;

    cout << "=======================================\n";
    cout << "               LOGIN PANEL             \n";
    cout << "=======================================\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    for (int i = 0; i < userCount; i++) {
        if (users[i][0] == username && users[i][1] == password) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Login successful. Welcome, " << username << "!\n";
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        return true;
    } else {
        cout << "? Invalid username or password.\n";
        attempt++;
        cout << "Login attempts used: " << attempt << "/3\n";
        cout << "\nPress Enter to return to main menu...";
        cin.ignore();
        cin.get();
        return false;
    }
}

void register_user(){
	string username, password;
	system("cls");
	cout<<"======================================="<<endl;
    cout<<"          Register New User            "<<endl;
	cout<<"======================================="<<endl;
	
	cout<<"Enter new username: ";
	cin>>username;
	
	cout<<"Enter new password: ";
	cin>>password;
	
	if (username.empty() || password.empty()) {
    	cout << "Username and password cannot be empty.\n";
    	return;
	}
	
	for (int i = 0; i < userCount; i++) {
    	if (users[i][0] == username) {
      		cout << "Username already exists. Please choose a different one.\n";
      		cout << "\nPress Enter to continue...";
			cin.ignore();
			cin.get();
			return;
   		}
	}

	users[userCount][0] = username;
	users[userCount][1] = password;
	userCount++;
	
	cout << "Registration successful!\n";
	cout << "\nPress Enter to continue...";
	cin.ignore();
	cin.get();
}

void main_portal() {
    int choice;
    bool inPortal = true;

    while (inPortal) {
        system("cls");
        cout << "=======================================\n";
        cout << "              Library System            \n";
        cout << "=======================================\n\n";

        cout << "1. Add Book\n";
        cout << "2. Show All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";
        cout << "6. Logout\n\n";

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                add_book();
                break;
            case 2:
                show_all_books();
                break;
            case 3:
                search_book();
                break;
            case 4:
                borrow_book();
                break;
            case 5:
                return_book();
                break;
            case 6:
                cout << "\nLogging out...\n";
                inPortal = false;
                cout << "Press Enter to continue...";
                cin.get();
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
                cout << "Press Enter to continue...";
                cin.get();
        }
    }
}

void add_book() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Book limit reached. Cannot add more books.\n";
        cout << "Press Enter to continue...";
        cin.get();
        return;
    }

    string title;
    cout << "Enter book title to add: ";
    getline(cin, title);

    if (title.empty()) {
        cout << "Book title cannot be empty.\n";
        cout << "Press Enter to continue...";
        cin.get();
        return;
    }

    books[bookCount] = title;
    borrowed[bookCount] = false;
    bookCount++;

    cout << "Book \"" << title << "\" added successfully!\n";
    cout << "Press Enter to continue...";
    cin.get();
}

void show_all_books() {
    if (bookCount == 0) {
        cout << "No books available.\n";
    } else {
        cout << "Books in library:\n";
        for (int i = 0; i < bookCount; i++) {
            cout << i+1 << ". " << books[i] << " [" << (borrowed[i] ? "Borrowed" : "Available") << "]\n";
        }
    }
    cout << "Press Enter to continue...";
    cin.get();
}

void search_book() {
    string searchTitle;
	cout << "Enter book title to search: ";
	getline(cin, searchTitle);

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i] == searchTitle) {
            cout << "Found: " << books[i] << " [" << (borrowed[i] ? "Borrowed" : "Available") << "]\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No matching book found.\n";
    }
    cout << "Press Enter to continue...";
    cin.get();
}

void borrow_book() {
    if (bookCount == 0) {
        cout << "No books available to borrow.\n";
        cout << "Press Enter to continue...";
        cin.get();
        return;
    }
    show_all_books();

    int bookNum;
    cout << "Enter book number to borrow: ";
    cin >> bookNum;
    cin.ignore();

    if (bookNum < 1 || bookNum > bookCount) {
        cout << "Invalid book number.\n";
    } else if (borrowed[bookNum - 1]) {
        cout << "Book already borrowed.\n";
    } else {
        borrowed[bookNum - 1] = true;
        cout << "You borrowed \"" << books[bookNum - 1] << "\".\n";
    }
    cout << "Press Enter to continue...";
  	cin.get();
}

void return_book() {
    if (bookCount == 0) {
        cout << "No books in the library.\n";
        cout << "Press Enter to continue...";
        cin.get();
        return;
    }
    show_all_books();

    int bookNum;
    cout << "Enter book number to return: ";
    cin >> bookNum;
    cin.ignore();

    if (bookNum < 1 || bookNum > bookCount) {
        cout << "Invalid book number.\n";
    } else if (!borrowed[bookNum - 1]) {
        cout << "Book was not borrowed.\n";
    } else {
        borrowed[bookNum - 1] = false;
        cout << "You returned \"" << books[bookNum - 1] << "\".\n";
    }
    cout << "Press Enter to continue...";
    cin.get();
}