#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Book details as global arrays
int bookIds[MAX_BOOKS];
char bookTitles[MAX_BOOKS][50];
char bookAuthors[MAX_BOOKS][50];
int bookStatus[MAX_BOOKS]; // 1 for available, 0 for borrowed
int bookCount = 0;

// Function prototypes
void addBook();
void displayBooks();
void borrowBook();
void returnBook();

// Function to add a book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter book ID: ");
    scanf("%d", &bookIds[bookCount]);
    printf("Enter book title: ");
    getchar(); // Consume leftover newline character
    fgets(bookTitles[bookCount], sizeof(bookTitles[bookCount]), stdin);
    bookTitles[bookCount][strcspn(bookTitles[bookCount], "\n")] = '\0'; // Remove newline
    printf("Enter author name: ");
    fgets(bookAuthors[bookCount], sizeof(bookAuthors[bookCount]), stdin);
    bookAuthors[bookCount][strcspn(bookAuthors[bookCount], "\n")] = '\0'; // Remove newline
    bookStatus[bookCount] = 1; // Book is available by default
    bookCount++;

    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nID\tTitle\t\t\tAuthor\t\t\tStatus\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d\t%-20s\t%-20s\t%s\n", bookIds[i], bookTitles[i], bookAuthors[i],
               bookStatus[i] ? "Available" : "Borrowed");
    }
}

// Function to borrow a book
void borrowBook() {
    int id, found = 0;
    printf("Enter the ID of the book to borrow: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (bookIds[i] == id) {
            found = 1;
            if (bookStatus[i] == 1) {
                bookStatus[i] = 0; // Mark as borrowed
                printf("You have successfully borrowed the book: %s\n", bookTitles[i]);
            } else {
                printf("Sorry, the book is already borrowed.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}

// Function to return a book
void returnBook() {
    int id, found = 0;
    printf("Enter the ID of the book to return: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (bookIds[i] == id) {
            found = 1;
            if (bookStatus[i] == 0) {
                bookStatus[i] = 1; // Mark as available
                printf("You have successfully returned the book: %s\n", bookTitles[i]);
            } else {
                printf("The book is already marked as available.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}

// Main function
int main() {
    int choice;

    do {
        // Display menu
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}