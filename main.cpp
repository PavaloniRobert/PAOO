#include <iostream>
#include "movie.cpp"

int main()
{
    Movie titanic("Titanic", "James Cameron", 7);
    Movie house("House of wax", "Jaume Collet-Serra", 5);
    Movie pirates("Pirates of the Caribbean", "Gore Verbinski", 8);
    Movie redemption("The Shawshank Redemption", "Frank Darabont", 9);
    Movie house2(house);

    std::cout << "Nume: " << titanic.getTitle() << "      Director: " << titanic.getDirector() << "      Rating: " << titanic.getRating() << std::endl;
    std::cout << "Nume: " << house.getTitle() << "      Director: " << house.getDirector() << "      Rating: " << house.getRating() << std::endl;
    std::cout << "Nume: " << pirates.getTitle() << "      Director: " << pirates.getDirector() << "      Rating: " << pirates.getRating() << std::endl;
    std::cout << "Nume: " << redemption.getTitle() << "      Director: " << redemption.getDirector() << "      Rating: " << redemption.getRating() << std::endl;
    std::cout << "Nume: " << house2.getTitle() << "      Director: " << house2.getDirector() << "      Rating: " << house2.getRating() << std::endl << std::endl;
    pirates = pirates;
    pirates = titanic = redemption = house;
    std::cout << "Nume: " << pirates.getTitle() << "      Director: " << pirates.getDirector() << "      Rating: " << pirates.getRating() << std::endl;
    std::cout << "Nume: " << titanic.getTitle() << "      Director: " << titanic.getDirector() << "      Rating: " << titanic.getRating() << std::endl;
    std::cout << "Nume: " << redemption.getTitle() << "      Director: " << redemption.getDirector() << "      Rating: " << redemption.getRating() << std::endl;
    std::cout << "Nume: " << house.getTitle() << "      Director: " << house.getDirector() << "      Rating: " << house.getRating() << std::endl;

    return 0;
}
