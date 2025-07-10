# 📘 Library Management System

## 📍 University: [Your University Name Here]  
**Project Title**: Library Management System  
**Course**: Programming Fundamentals I  
**Group Members**:
- Christian Fitsum – [Your ID Here]  
- [Member 2 Name] – [ID]  
- [Member 3 Name] – [ID]  

**Instructor**: [Instructor's Name]  
**Submission Date**: [Date]

---

## 🔍 Overview

This **Library Management System** is a basic C++ console application that allows users to register, log in, and manage books through a command-line interface. It simulates key operations of a real library system using core programming concepts such as:

- Functions
- Arrays
- Conditionals and loops
- Input/output streams
- String handling

The project showcases how simple logic and arrays can be used to create a user-driven, menu-based application with multiple functionalities.

---

## ✅ Functionalities

1. **User Registration**  
   - New users can register with a unique username and password.

2. **User Login**  
   - Only registered users can log in.
   - Users have a maximum of 3 login attempts.

3. **Main Portal (Post-Login)**  
   - Add a book to the library
   - Show all books with availability status
   - Search a book by title
   - Borrow a book (if available)
   - Return a borrowed book
   - Logout from the system

4. **Book Management**  
   - Books are stored in arrays.
   - Each book has a "borrowed" flag to track status.

---

## 💻 Code Snippets

### 🔐 Login Function

```cpp
bool login() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    for (int i = 0; i < userCount; i++) {
        if (users[i][0] == username && users[i][1] == password) {
            cout << "Login successful.\n";
            return true;
        }
    }
    cout << "Invalid login.\n";
    attempt++;
    return false;
}
```
### 📚 Add Book Function

```cpp
void add_book() {
    string title;
    cout << "Enter book title to add: ";
    getline(cin, title);
    books[bookCount] = title;
    borrowed[bookCount] = false;
    bookCount++;
    cout << "Book added successfully!\n";
}
```
---
## 📦 Project Constraints
- Max Users: 10
- Max Books: 20
- No persistent storage (data lost after exit)
- Username and password stored in arrays (plaintext)
- Console-only interface
