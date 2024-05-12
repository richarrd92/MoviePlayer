
#include <iostream>
#include <string>
#include "Movie.h"
using namespace std;


  // Movie 
  // Creates a default movie
  Movie::Movie(){
    // MAY NOT NEED IMPLEMENTATION
  }


  // Movie - Overloaded Constructor
  // Creates a movie entry based on passed parameters
  Movie::Movie(string title, string rating, string genre, int year, string director,
        string star, long budget, long gross, string studio, int runtime){

    m_title = title; 
    m_rating = rating; 
    m_genre = genre; 
    m_year = year; 
    m_director = director; 
    m_star = star; 
    m_budget = budget;
    m_gross = gross; 
    m_studio = studio; 
    m_runtime = runtime;

  }


  //Name: Mutators and Accessors
  //Precondition: None
  //Postcondition: Sets and Gets private member variables

  // return title
  string Movie::GetTitle()const{
    return m_title;
  }

  // returns rating
  string Movie::GetRating()const{
    return m_rating;
  }

  // returns genre
  string Movie::GetGenre()const{
    return m_genre;
  }

  // returns year
  int Movie::GetYear()const{
    return m_year;
  }

  // returns director 
  string Movie::GetDirector()const{
    return m_director;
  }

  // returns star
  string Movie::GetStar() const{
    return m_star;
  } 

  // returns budget
  long Movie::GetBudget() const{
    return m_budget;
  } 

  // returns total box office returns (gross)
  long Movie::GetGross() const{
    return m_gross;
  } 

  // returns studio
  string Movie::GetStudio() const{
    return m_studio;
  } 

  // returns runtime of movie (in minutes)
  int Movie::GetRuntime() const{
    return m_runtime;
  } 

  void Movie::SetTitle(string title){
    m_title = title;
  }

  void Movie::SetRating(string rating){
    m_rating = rating;
  }

  void Movie::SetGenre(string genre){
    m_genre = genre;
  }

  void Movie::SetYear(int year){
    m_year = year;
  }

  void Movie::SetDirector(string director){
    m_director = director;
  }

  void Movie::SetStar(string star){
    m_star = star;
  }

  void Movie::SetBudget(long budget){
    m_budget = budget;
  }

  void Movie::SetGross(long gross){
    m_gross = gross;
  }

  void Movie::SetStudio(string studio){
    m_studio = studio;
  }

  void Movie::SetRuntime(int runtime){
    m_runtime = runtime;
  }

  // Overloaded << operator
  // Returns output stream including title by director from year
  ostream& operator<<(ostream& out, Movie& m){
    out << m.GetTitle() << " by " << m.GetDirector() << " from " << m.GetYear();
    return out;
  }

  // Overloaded Relational Operator (<)
  // if passed movie's year is less than first, return true else false
  bool operator<(const Movie& m1, const Movie& m2){
   return m1.GetYear() < m2.GetYear();
  }

  // Overloaded Relational Operator (>)
  // if passed movie's year is greater than first, return true else false
  bool operator>(const Movie& m1, const Movie& m2){
    return m1.GetYear() > m2.GetYear();
  }
