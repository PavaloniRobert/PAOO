#ifndef MOVIE_CPP
#define MOVIE_CPP

#include <iostream>
#include <memory>
#include <mutex>
#include "person.cpp"

std::mutex mtx; 

class Movie
{
    public: 
        Movie(std::string Title, std::string Director, int Rating);
        Movie& operator = (Movie &movie); //copy assignment operator
        std::string getTitle();
        std::string getDirector();
        int getRating();
        void setRating(int newRating);
        void recommendation(std::string Name, int Age);

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

    void Movie::setRating(int newRating)
    {
        this->rating = newRating;
    }

    void Movie::recommendation(std::string Name, int Age)
    {
        std::shared_ptr<Person> person(new Person(Name, Age));// ITEM 13 - using objects to manage resources
        std::shared_ptr<Person> person2(person);

        mtx.lock();// ITEM 14 - think carefully about copying behavior in resource-managing classes

        std::cout <<"Adresa primului obiect: "<<person.get()<< std::endl;
        std::cout <<"Adresa celui de-al doilea obiect: "<<person2.get()<< std::endl;
        std::cout <<"Nr de obiecte referite de shared_pointer: "<<person2.use_count()<< std::endl;
        std::cout <<"Current '"<<this->getTitle()<<"' rating: "<<this->getRating()<< std::endl;
        std::cout <<"I'm "<<person->getName()<<"."<< std::endl;
        std::cout <<"I'm "<<person->getAge()<<" years old."<< std::endl;
        std::cout <<"I want to recommend the movie '"<<this->getTitle()<<"'! It's extraordinary."<< std::endl;
        person2.reset();
        std::cout <<"Nr de obiecte referite de shared_pointer: "<<person.use_count()<< std::endl;
        person.reset();
        std::cout <<"Nr de obiecte referite de shared_pointer: "<<person.use_count()<< std::endl;

        this->setRating(this->getRating() + 1);

        std::cout <<"New '"<<this->getTitle()<<"' rating: "<<this->getRating()<< std::endl << std::endl;

        mtx.unlock();
    }

#endif