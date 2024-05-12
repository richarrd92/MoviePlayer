
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "MoviePlayer.h"
#include "Movie.h"
#include "Queue.cpp"

using namespace std;
  
  // MoviePlayer
  // Creates a new MoviePlayer with m_filename of "proj5_movies.txt"
  MoviePlayer::MoviePlayer(){
    // MAY NOT NEED IMPLEMENTATION
  }

  // MoviePlayer
  // Creates a new MoviePlayer with passed filename
  MoviePlayer::MoviePlayer(string filename){
    m_filename = filename;
  }

  // ~MoviePlayer  
  // Deallocates movies from m_movieCatalog
  MoviePlayer::~MoviePlayer(){
    // iterates through vector m_movieCatalog
    for(vector<Movie*>::iterator it = m_movieCatalog.begin(); it != m_movieCatalog.end(); it++){
      delete *it; 
    }
  }

  // LoadCatalog 
  // Dynamically allocates each movie and inserts into m_movieCatalog
  void MoviePlayer::LoadCatalog(){
    
    fstream myFile;

    // open file
    myFile.open(m_filename);

    // iterates through file line by line
    string line;

    if (myFile.is_open())
    {
        // reads file line by line
        while (getline(myFile, line))
        {

            // Find the positions of semicolons
            int pos1 = line.find(';');
            int pos2 = line.find(';', pos1 + 1);
            int pos3 = line.find(';', pos2 + 1);
            int pos4 = line.find(';', pos3 + 1);
            int pos5 = line.find(';', pos4 + 1);
            int pos6 = line.find(';', pos5 + 1);
            int pos7 = line.find(';', pos6 + 1);
            int pos8 = line.find(';', pos7 + 1);
            int pos9 = line.find(';', pos8 + 1);


            // Extract substrings based on semicolon positions
            string title = line.substr(0, pos1);
            string rating = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string genre = line.substr(pos2 + 1, pos3 - pos2 - 1);
            int year = stoi(line.substr(pos3 + 1, pos4 - pos3 - 1));
            string director = line.substr(pos4 + 1, pos5 - pos4 - 1);
            string star = line.substr(pos5 + 1, pos6 - pos5 - 1);
            long budget = stol(line.substr(pos6 + 1, pos7 - pos6 - 1));
            long gross = stol(line.substr(pos7 + 1, pos8 - pos7 - 1));
            string studio = line.substr(pos8 + 1, pos8 - pos7 - 1);
            int runtime = stoi(line.substr(pos9 + 1));


           // Dynamically allocates airports
           Movie* movie = new Movie(title, rating, genre, year, director, star, budget, gross, studio, runtime);

           // Add airports to vector of all airports
           m_movieCatalog.push_back(movie);
        }

        // Prompt message
        cout << "5340 movie files loaded." <<endl;
    }

    // Close the file
    myFile.close();
  }

  // MainMenu
  // Manages the menu
  void MoviePlayer::MainMenu(){

    // user menu choice
    int userChoice;
    
    do{

      cout <<endl;
      cout << "What would you like to do?:" <<endl <<endl;
      cout << "1. Display Movie by Type and Year" <<endl;
      cout << "2. Add Movie to Playlist" <<endl;
      cout << "3. Display Playlist" <<endl;
      cout << "4. Sort Playlist by Year" <<endl; 
      cout << "5. Search for Movie" <<endl;
      cout << "6. Exit" <<endl;
      cout << "Option: ";
      cin >> userChoice;

      switch(userChoice){

            case 1:   MoviePlayer::DisplayMovie();          break;
            case 2:   MoviePlayer::AddMovie();              break; 
            case 3:   MoviePlayer::DisplayPlaylist();       break; 
            case 4:   MoviePlayer::SortPlaylist();          break;
            case 5:   MoviePlayer::SearchMovie();           break;

            // Sets userChoice -> 6 
            case 6:   userChoice = 6;                       break; 
      }

    }while(userChoice != 6);

    // Prompt message
    cout << "\nThank you for using the UMBC Movie Player!" <<endl <<endl;

  }

  // DisplayMovie
  // Returns count of movies found matching year and genre else 0
  int MoviePlayer::DisplayMovie(){

    // user movie year choice
    int movieYear;
    cout << "\nWhich year would you like to display? (1980-2020)" <<endl;
    cin >> movieYear;

    // validates the year choice
    while(movieYear < MIN_YEAR || movieYear > MAX_YEAR){
        cout << "\nWhich year would you like to display? (1980-2020)" <<endl;
        cin >> movieYear;
    }

    // Prompt message
    cout << "\n******" << movieYear << "*****" <<endl;

    // user movie genre choice
    string movieGenre;

    // No Validation for genre
    cout << "Which genre would you like?" <<endl;
    cin >> movieGenre;

    // Prompt message
    cout << "\n******" << movieGenre << "*****" <<endl <<endl;
    cout << "MOVIES TOTAL: " << m_movieCatalog.size() <<endl;

    // foundMovies calculates number movies found of similar genre and year
    int foundMovies = 0, counter = 0;

    cout <<endl;

    // use of iterator to display movies in m_movieCatalog
    for(vector<Movie*>::iterator it = m_movieCatalog.begin(); it != m_movieCatalog.end(); it++){
        if((movieGenre == (*it)->GetGenre()) && (movieYear ==  (*it)->GetYear())){
           cout << counter+1 << ". " << *(*it) <<endl; 
           foundMovies++;
        }    

        // incriments counter
        counter++;
    }

    // display message
    cout <<endl << foundMovies << " MOVIES FOUND" <<endl;

    // returns 0 or foundMovies
    return foundMovies;
  }

  // AddMovie
  // Adds pointer from m_catalog and inserts into m_playList
  void MoviePlayer::AddMovie(){

    cout <<endl;
    // prompt message only if playlist empty 
    if(m_playList.IsEmpty() == true){
        cout << "PLAYLIST IS EMPTY !" <<endl;
    } 
    
    // prompt message
    cout << "Choose the movie you would like to ADD to the playlist." <<endl;
    MoviePlayer::DisplayMovie();

    // user movie choice
    int movieChoice;
    cout << "\nEnter the number of the movie you would like to add!" <<endl;
    cout << "Choice: ";
    cin >> movieChoice;

    // validates the choice from user
    while(movieChoice < 1 || movieChoice > int(m_movieCatalog.size())){
        cout << "\nEnter the number of the movie you would like to add!" <<endl;
        cout << "Choice: ";
        cin >> movieChoice;
    }

    // adds movie to playlist using PushBack function
    m_playList.PushBack(m_movieCatalog[movieChoice-1]);
    cout <<endl << *m_movieCatalog[movieChoice-1] << " ADDED TO PLAYLIST!" <<endl;

  }

  // DisplayPlaylist
  // Displays the playlist using the overloaded << operator
  void MoviePlayer::DisplayPlaylist(){

    // playlist is empty
    if(m_playList.IsEmpty() == true){
        cout << "\nPLAYLIST IS EMPTY !" <<endl;
    } 
    
    // playlist contains one or more movies
    else {

        // prompt message
        cout << "\n********** MOVIES IN PLAYLIST **********" <<endl<<endl;

        // iterates until end of playlist 
        for(int i = 0; i < m_playList.GetSize(); i++){
          // uses the At functions to get index specific data
          cout << i+1 << ". " << *m_playList.At(i) <<endl;
        }
    }
  }

  // SortPlaylist
  // Sorts the playlist by year
  void MoviePlayer::SortPlaylist(){

    // playlist is empty 
    if(m_playList.IsEmpty() == true){
        cout << "\nPLAYLIST IS EMPTY !" <<endl;
    } 
    
    // playlist contains one or more movies
    else {

        // case 1: playlist has less than 2 movies
        if(m_playList.GetSize() < 2) {
          cout << "\nMINIMUM OF 2 MOVIES REQUIRED TO SORT PLAYLIST" << endl;
        } 
        
        // case 2: playlist has more 2 or more movies
        else{
            m_playList.Sort();
            cout << "DONE SORTING PLAYLIST BY YEAR" <<endl;
        }
    }
  }

  // StartPlayer
  // Loads file and calls main menu
  void MoviePlayer::StartPlayer(){

    // calls function to Load file and main menu
    MoviePlayer::LoadCatalog();
    MoviePlayer::MainMenu();

  }

  // SearchMovie
  // Sorts the playlist by year, minimum profit, movie title or director
  void MoviePlayer::SearchMovie(){
    cout <<endl;

    // user action choice
    int userChoice;

    cout << "What do you want to search by?" <<endl <<endl;
    cout << "1. Word in Title or Director" <<endl;
    cout << "2. Year" <<endl;
    cout << "3. Earnings" <<endl;
    cout << "Choice: ";
    cin  >> userChoice;

    // validates the choice from user
    while(userChoice < 1 || userChoice > 3){
      cout << "\nWhat do you want to search by?" <<endl <<endl;
      cout << "1. Word in Title or Director" <<endl;
      cout << "2. Year" <<endl;
      cout << "3. Earnings" <<endl;
      cout << "Choice: ";
      cin  >> userChoice;
    }

    // user movie year choice
    int movieYear;

    // gross – budget
    long MovieProfit;

    // word in movie title or director name
    string movieName;

    // number of movies found
    int foundMovies = 1;

    switch(userChoice){

      // Word in Title or Director
      case 1: 
          cout << "\nWhat string would you like to search?" <<endl;
          cin.ignore(); // ignore buffer
          getline(cin, movieName);
          cout << endl;

          // use of iterator to display movies in m_movieCatalog
          for(vector<Movie*>::iterator it = m_movieCatalog.begin(); it != m_movieCatalog.end(); it++){

              // returns -1 if match substring not found
              int foundTitle = int((*it)->GetTitle().find(movieName));
              int foundDirector = int((*it)->GetDirector().find(movieName));

              // prints out only movies that match 
              if((foundTitle != -1) || (foundDirector != -1)){
                cout << foundMovies++ << ". " << *(*it) <<endl;  
              }  
          }

          // display message
          (foundMovies-1 > 0) ? cout << endl << foundMovies-1 << " MOVIES FOUND" : cout << foundMovies-1 << " MOVIES FOUND";   
          cout << endl;
      break;

      // Year
      case 2: 
          cout << "\nWhich year would you like to display? (1980-2020)" <<endl;
          cin >> movieYear;

          // validates the year choice
          while(movieYear < MIN_YEAR || movieYear > MAX_YEAR){
              cout << "\nWhich year would you like to display? (1980-2020)" <<endl;
              cin >> movieYear;
          }

          // Prompt message
          cout << "\n******" << movieYear << "*****" <<endl <<endl;

          // use of iterator to display movies in m_movieCatalog
          for(vector<Movie*>::iterator it = m_movieCatalog.begin(); it != m_movieCatalog.end(); it++){
              if(movieYear ==  (*it)->GetYear()){
                cout << foundMovies++ << ". " << *(*it) <<endl; 
              }    
          }
      break;

      // Earnings
      case 3: 
          cout << "\nWhat is the minimum profit?" <<endl; 
          cin  >> MovieProfit;
          cout <<endl;

          // use of iterator to display movies in m_movieCatalog
          for(vector<Movie*>::iterator it = m_movieCatalog.begin(); it != m_movieCatalog.end(); it++){
              if(MovieProfit  < ((*it)->GetGross() - (*it)->GetBudget())){
                cout << foundMovies++ << ". " << *(*it) <<endl; 
              } 
          } 

          // display message
          (foundMovies-1 > 0) ? cout << endl << foundMovies-1 << " MOVIES FOUND" : cout << foundMovies-1 << " MOVIES FOUND";   
          cout << endl;
      break;
    }

  }
