#ifndef MOVIE_CPP
#define MOVIE_CPP

#include <iostream>
 
class Movie
{
    public: 
        Movie(std::string Title, std::string Director, int Rating);
        Movie& operator = (Movie &movie); //copy assignment operator
        std::string getTitle();
        std::string getDirector();
        int getRating();

        ~Movie() = default;

    private:
        std::string title;
        std::string director;
        int rating;
};

Movie::Movie(std::string Title, std::string Director, int Rating):
    title(Title),
    director(Director),
    rating(Rating)
{}

// Movie& Movie::operator=(Movie &movie)
// {
//     if( this == &movie)
//     {
//         std::cout << "Same objects!" << std::endl;
//         return *this;
//     }//ITEM 11

//     swap(movie);
//     return *this; //ITEM 10
// }

Movie& Movie::operator=(Movie &movie)
{
    if( this == &movie)
    {
        std::cout << "Same objects!" << std::endl << std::endl;
        return *this;
    }//ITEM 11

    this->title = movie.title;
    this->director = movie.director;
    this->rating = movie.rating;//ITEM 12
    //De asemenea, daca aceasta clasa ar extinde o alta clasa, atunci ar trebui sa ne asiguram ca si membrii clasei extinse sunt copiati aici:
    //ClasaExtinsa::operator=(movie);
    
    return *this; //ITEM 10
}

std::string Movie::getTitle()
{
    return this->title;
}

std::string Movie::getDirector()
{
    return this->director;
}

int Movie::getRating()
{
    return this->rating;
}

#endif
