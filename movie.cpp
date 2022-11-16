#ifndef MOVIE_CPP
#define MOVIE_CPP

#include <iostream>

/*
class Uncopyable 
{
    protected:
        Uncopyable() {}
        ~Uncopyable() {}

    private:
        Uncopyable(const Uncopyable&);
        Uncopyable& operator=(const Uncopyable&);
};  // ITEM 6
*/
class Movie//: private Uncopyable
{
    public: 
        Movie(std::string Title, std::string Director, int Rating);
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
{} //ITEM 4

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