# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de les copiers dans le repertoire `build` avec l'application `bibliotheque`


question 1: constructeur et destructeurs

Dans le code de la Bibliotheque nous avons utiliser le des constructeurs pour initialiser les objets ainsi que des destructeurs. exemple du code : 

class Book {
private:
    string title;
    string author;
    string isbn;
    bool isAvailable;
    string borrowerName;

public:
    // Constructors
    Book();
    Book(const string& title, const string& author, const string& isbn);

}

question 2:  Il faudrait, selon moi, une base de données à plus grande capacité comme MySQL ou encore MongoDB. C’est bien parce qu’on peut créer simplement les tables avec les informations voulues, comme une table book par exemple, avec les attributs de la table : title, author, id, etc. De plus, on peut exécuter des requêtes pour faire tout ce qu’on fait déjà dans ce code, soit le triage, la recherche, etc.

Maintenant, pour interfacer, les livres seront stockés dans la base de données et, au lieu que le C++ gère tout, il s’occuperait simplement de la logique, des menus et de l’interface utilisateur.