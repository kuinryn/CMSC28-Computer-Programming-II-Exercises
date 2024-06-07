#include <iostream>
#include <sstream>
#include "Movie.h"
#include "Person.h"
using namespace std;

int main() {
    //declare variables for movie details
    string title, synopsis, mpaa_rating, genre, director_fname, director_lname, director_gender;
    string actor_fname, actor_lname, actor_gender;

    cout << "This program will collect and display detailed information about a movie." << endl;
    cout << "Programmed by: Quennie A. Nebria" << endl;

    cout << "Enter Movie Title: "; //prompt the user to enter the movie title
    getline(cin, title);

    cout << "Enter Synopsis: "; //prompt the user to enter the movie synopsis
    getline(cin, synopsis);

    cout << "What is its MPAA Rating: "; //prompt the user to enter the movie MPAA rating
    getline(cin, mpaa_rating);

    //collect multiple genres
    cout << "Enter Genre(s) (type 'done' when finished): ";
    vector<string> genres; //store genres
    while (true) {
        getline(cin, genre); //read genre input
        if (genre == "done") break; //break loop if 'done' is entered
        genres.push_back(genre); //add genre to the vector
    }

    //collect multiple directors
    vector<Person> directors; //store directors
    while (true) {
        cout << "Enter Director (type 'done' to finish): " << endl;
        cout << "First Name: ";
        getline(cin, director_fname); //read director's first name
        if (director_fname == "done") break; //break loop if 'done' is entered
        cout << "Last Name: ";
        getline(cin, director_lname); //read director's last name
        cout << "Gender: ";
        getline(cin, director_gender); //read director's gender
        directors.push_back(Person(director_fname, director_lname, director_gender)); //add director to the vector
    }

    //collect multiple actors/actresses
    vector<Person> actors; //store actors/actresses
    while (true) {
        cout << "Enter Actor/Actress (type 'done' to finish): " << endl;
        cout << "First Name: ";
        getline(cin, actor_fname); //read actor's first name
        if (actor_fname == "done") break;
        cout << "Last Name: ";
        getline(cin, actor_lname); //read actor's last name
        cout << "Gender: ";
        getline(cin, actor_gender);
        actors.push_back(Person(actor_fname, actor_lname, actor_gender)); //add actor to the vector
    }

    Movie movie; 
    movie.setTitle(title); //set title
    movie.setSynopsis(synopsis); //set synopsis
    movie.setMPAARating(mpaa_rating); //set mpaa rating
    for (const auto& g : genres) {
        movie.addGenre(g); //add each genre to the movie
    }
    for (const auto& d : directors) {
        movie.addDirector(d); //add each director to the movie
    }
    for (const auto& a : actors) {
        movie.addActor(a); //add each actor to the movie
    }

    // Display movie details
    cout << "\nMOVIE DETAILS\n" << endl;
    cout << "Movie Title: " << movie.getTitle() << endl;
    cout << "Synopsis: " << movie.getSynopsis() << endl;
    cout << "MPAA Rating: " << movie.getMPAARating() << endl;
    cout << "Genre: ";
    vector<string> movie_genres = movie.getGenres(); //get the list of genres
    for (const auto& g : movie_genres) { //iterate over the genres and output each one
        cout << g << ", ";
    }
    cout << endl;

    cout << "Director(s): ";
    vector<Person> movie_directors = movie.getDirectors(); //get the list of directors
    for (const auto& d : movie_directors) { //iterate over the directors and output each one
        cout << d.getFname() << " " << d.getLname() << ", ";
    }
    cout << endl;

    cout << "Actor(s)/Actress(es): ";
    vector<Person> movie_actors = movie.getActors(); //get the list of actors/actresses
    for (const auto& a : movie_actors) { //iterate over the actors/actresses and output each one
        cout << a.getFname() << " " << a.getLname() << ", ";
    }
    cout << endl;

    return 0;
}
