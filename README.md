# 🔐 RBAC Library System (C++)

## 📌 Overview

This project is a **Role-Based Access Control (RBAC) Library System** built in C++.
It implements a **secure authentication system** with password hashing, session management, and role-based user handling.

---

## 🚀 Features Implemented

### 🔐 Authentication System

* User Registration (Student, Faculty, Librarian, Staff)
* Login with credential verification
* Secure password storage using **salted hashing**
* Password strength validation

---

### 🧂 Password Security

* Salted hashing implementation
* Multiple hashing iterations
* Password verification mechanism
* Prevents identical password hashes

---

### 🎭 Role-Based System

* Supported roles:

  * STUDENT
  * FACULTY
  * LIBRARIAN
  * STAFF
* Role selection during login & registration
* Role validation (email-based restrictions)

---

### 🎟️ Session Management (Token System)

* Custom **TokenManager** implemented
* Generates unique session tokens on login
* Token expiry handling (1 hour)
* Logout invalidates session
* Token validation for protected actions

---

### 💾 Data Persistence

* User data stored in `users.txt`
* File-based storage system
* Automatic load/save on program start/end

---

### 🧠 Input Handling Improvements

* Supports multi-word input using `getline`
* Fixes common `cin` + `getline` issues
* Clean CLI-based user interaction

---

## 🧱 Project Structure

```
AuthenticationAndSecurity/
│
├── main.cpp
├── AuthManager.h / .cpp
├── User.h / .cpp
├── PasswordUtil.h / .cpp
├── TokenManager.h / .cpp
├── UserRepository.h / .cpp   (optional module)
├── users.txt
```

---

## ⚙️ How It Works

### 🔑 Registration Flow

1. User selects role
2. Inputs details (name, email, etc.)
3. Password is validated
4. Password is hashed with salt
5. User is saved to file

---

### 🔐 Login Flow

1. User enters credentials
2. Password is verified using stored hash
3. If valid:

   * Session token is generated
   * User is logged in

---

### 🎟️ Session Flow

```
Login → Token Generated → Access Allowed → Logout → Token Invalidated
```

---

## 🛠️ How to Run

### 🔧 Compile

```bash
g++ *.cpp -o app
```

### ▶️ Run

```bash
./app
```

---

## ⚠️ Notes

* Delete `users.txt` if switching hashing logic
* Tokens are stored in memory (reset on restart)
* Not using external libraries (pure C++ implementation)

---

## 🔒 Security Highlights

* No plain-text passwords
* Salted hashing implemented
* Session-based authentication
* Input validation enforced

---

## 🚧 Future Improvements

* Full RBAC permission system
* Resource-level access control
* Database integration (instead of file)
* JWT-based authentication
* Multi-session handling
* Admin dashboard

---

## 💡 Learning Outcomes

* Authentication system design
* Secure password handling
* Session/token management
* File-based persistence
* Modular C++ architecture

---

## 👨‍💻 Author

Developed as part of a group project focusing on authentication and security modules.
