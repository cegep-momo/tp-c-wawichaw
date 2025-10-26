#include <iostream>
#include "book.h"

// Default constructor
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerName("") {
    // Constructeur vide avec liste d'initialisation
}  

//Constructeur avec paramètres
Book:: Book(const std::string& title, const std:: string& author, const std::string& isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerName("") {

}



//Méthodes d'accès (getters)
std::string Book ::getTitle() const {
    return title;
}

std::string Book ::getAuthor() const {
    return author;
}
std::string Book ::getISBN() const {
    return isbn;
}
bool Book ::getAvailability() const {
    return isAvailable;
}
std::string Book ::getBorrowerName() const {
    return borrowerName;
}

//Méthodes de modification (setters)

void Book ::setTitle(const std::string& title) {
    this->title = title;
}
void Book ::setAuthor(const std::string& author) {
    this->author = author;
}

void Book ::setISBN(const std::string& isbn) {
    this->isbn = isbn;
}       

void Book ::setAvailability(bool available) {
    isAvailable = available;
}

void Book ::setBorrowerName(const std::string& name) {
    borrowerName = name;
}

//Methodes checkOut et returnBook
void Book ::checkOut(const std::string& borrower) {
    if (isAvailable) {
        isAvailable = false;
        borrowerName = borrower;
    } else {
        std::cout << "Ce livre est déjà emprunté par " << borrowerName << std::endl;
    }
}

void Book ::returnBook() {
    if (!isAvailable) {
        isAvailable = true;
        borrowerName = "";
    } else {
        std::cout << "Ce livre n'est pas emprunté." << std::endl;
    }
}

// Méthode toString 
std::string Book ::toString() const {
    std::string status = isAvailable ? "Disponible" : "Emprunté par " + borrowerName;
    return "Titre: " + title + ", Auteur: " + author + ", ISBN: " + isbn + ", Statut: " + status;
}

// Méthode toFileFormat
std::string Book ::toFileFormat() const {
    return title + ";" + author + ";" + isbn + ";" + (isAvailable ? "1" : "0") + ";" + borrowerName;
}

// Méthode fromFileFormat
// Remplit les attributs d'un objet Book à partir d'une ligne de texte formatée.
void Book ::fromFileFormat(const std::string& line) {
    size_t pos = 0;
    size_t prevPos = 0;
    int fieldIndex = 0;
    std::string token;

    while ((pos = line.find(';', prevPos)) != std::string::npos) {
        token = line.substr(prevPos, pos - prevPos);
        switch (fieldIndex) {
            case 0: title = token; break;
            case 1: author = token; break;
            case 2: isbn = token; break;
            case 3: isAvailable = (token == "1"); break;
            case 4: borrowerName = token; break;
        }
        prevPos = pos + 1;
        fieldIndex++;
    }
}