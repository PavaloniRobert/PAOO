#include <iostream>
#include "movie.cpp"

int main()
{
    Movie titanic("Titanic", "James Cameron", 8);
    Movie house("House of wax", "Jaume Collet-Serra", 5);
    Movie pirates("Pirates of the Caribbean", "Gore Verbinski", 8);
    Movie redemption("The Shawshank Redemption", "Frank Darabont", 9);
    Movie house2(house); // ITEM 5

    std::cout << "Nume: " << titanic.getTitle() << "Director: " << titanic.getDirector() << "ating: " << titanic.getRating() << std::endl;
    std::cout << "Nume: " << house.getTitle() << "Director: " << house.getDirector() << "Rating: " << house.getRating() << std::endl;
    std::cout << "Nume: " << pirates.getTitle() << "Director: " << pirates.getDirector() << "Rating: " << pirates.getRating() << std::endl;
    std::cout << "Nume: " << redemption.getTitle() << "Director: " << redemption.getDirector() << "Rating: " << redemption.getRating() << std::endl;
    std::cout << "Nume: " << house2.getTitle() << "Director: " << house2.getDirector() << "Rating: " << house2.getRating() << std::endl;
    pirates = titanic;
    std::cout << "Nume: " << pirates.getTitle() << "Director: " << pirates.getDirector() << "Rating: " << pirates.getRating() << std::endl;

    return 0;
}