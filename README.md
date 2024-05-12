# Movie Player Project

## Overview
This project aims to implement a movie player that can build a playlist from thousands of available titles based on a multitude of features.

## Project Structure
This project consists of three main classes:

### Class 1: Queue
- Templated linked list data structure for managing data.
- Allows PushBack (add to tail) and PopFront (remove from front) operations.
- Provides functionalities like displaying, returning data in the first node, returning the size, and checking if it is empty.
- Includes a copy constructor and overloaded assignment operator.

### Class 2: MoviePlayer
- Manages the master movie catalog and the user’s playlist.
- Dynamically allocates Movie objects loaded into a vector.
- Allows displaying all movies available based on year and genre.
- Enables adding movies to the playlist, displaying the playlist, and sorting the reading list by year (oldest to newest).

### Class 3: Movie
- Contains all information about each movie, including title, rating, genre, year, director, star, budget, gross, studio, and runtime.
- Overloaded < and > operators for sorting and << for displaying (title by director from year).


