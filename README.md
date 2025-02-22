Here is my full representation of an online library management system in C++. For best experiences, you should use Visual Studio IDE and run it on terminal (Front-end and back-end will be updated soon)

The requirements and features are:
1. User management system
- There are 3 types of user: administrator, member and guest
- Administrator should be able to manage books (add, show, hide, remove, edit, manage book collections)
- Administrator cannot borrow / return books.

- Member should be able to borrow, return books.
- Member should be able to subscribe/unsubscribe to any book collection.
- Member should have start and end year of membership

- Guest can only read a number of pages for each book in the sample book collection.
- Guest does not need to login, require no information but will be given a temporary ID 

- All user should be able to search for book by title, serialnumber
- Every registered user should have ID, userame, password, phone number and full name
- Admin and Member should be able to login and logout of the system
- There is one root administrator account with username/password root/root. but number of administrator accounts should can be increased in the future.  
- Guest should be able to register as a member anytime.

2. Book management system
- Books should have title, unique serialnumber (6 digits), author name, number of pages, number of free to read pages
- Books should be divided into categories (Culture, Science, Fiction)
- Books can be added, removed, edit information, show publicly or hide by administrator
- Books can be added or removed from collections (Trending, Best selling, New ...) by administrator

3. Collection management system
- A collection is a set of books with: collection ID, collection name, list of books
- A collection can only be created, edited by administrator
- A collection also have a list of subscribed users. Only subscribed user can ask for list of book in the collection.
Note: member can still read any book in the library, just cannot see the list of books in unsubscribed     
- All members and guests will be subscribed to the sample book collection automatically

The full project is implemented with a text menu for user to use the software. Classes and a UML class diagram is also included. 
