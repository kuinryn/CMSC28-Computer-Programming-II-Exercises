#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>
#include "Person.h"
using namespace std;

class Movie {
private:
    string title; //title of the movie
    string synopsis; //synopsis of the movie
    string mpaa_rating; //rating of the movie
    vector<string> genres; //genres of the movie
    vector<Person> directors; //directors of the movie
    vector<Person> actors; //actor of the movie

public:
    //constructors
    Movie() : title(""), synopsis(""), mpaa_rating("") {}
    Movie(string t, string s, string m) : title(t), synopsis(s), mpaa_rating(m) {}

    //set methods
    void setTitle(string t) { title = t; }
    void setSynopsis(string s) { synopsis = s; }
    void setMPAARating(string m) { mpaa_rating = m; }
    void setGenres(const vector<string>& g) { genres = g; }

    //additional methods to add elements to vectors
    void addGenre(string g) { genres.push_back(g); }
    void addDirector(Person d) { directors.push_back(d); }
    void addActor(Person a) { actors.push_back(a); }

    //get methods
    string getTitle() const { return title; }
    string getSynopsis() const { return synopsis; }
    string getMPAARating() const { return mpaa_rating; }
    vector<string> getGenres() const { return genres; }
    vector<Person> getDirectors() const { return directors; }
    vector<Person> getActors() const { return actors; }
};

#endif // MOVIE_H
