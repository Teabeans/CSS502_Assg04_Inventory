//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// InvDB.cpp
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------------------------------------------------------------------|
// Authorship
//-----------------------------------------------------------------------------|
//
// Matt Gross & Tim Lum
// mattgrosspersonal@gmail.com + twhlum@gmail.com
// Created:  2018.03.03
// Modified: 2018.03.--
// For the University of Washington Bothell, CSS 502A
// Winter 2018, Graduate Certificate in Software Design & Development (GCSDD)
//

//-----------------------------------------------------------------------------|
// File Description
//-----------------------------------------------------------------------------|
//
// This is the implementation file for the InvDB.h header, representing a
// database of film objects
//

//-----------------------------------------------------------------------------|
// Package Files
//-----------------------------------------------------------------------------|
//
// See Github repository
// https://github.com/Teabeans/CSS502_Assg04_Inventory
//

//-------------------------------------|
// Begin Student Code
//-------------------------------------|

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       INCLUDE STATEMENTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|



// Necessary for film objects
#include "Film.h"
#include "FilmClassic.h"
#include "FilmDrama.h"
#include "FilmComedy.h"

// Necessary for transaction objects
#include "Trans.h"

#include "InvDB.h"

// Necessary for file stream object handling
#include <fstream>
#include <string>



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|
//
// Do not redeclare these variables in the .cpp.
// Included here only for reference
// See associated .h file for variable declarations

//-----------------|
// #comedies
//-----------------|
// Desc:   NULL
// Invars: NULL
/// std::vector<Comedy> comedies;

//-----------------|
// #dramas
//-----------------|
// Desc:   NULL
// Invars: NULL
/// std::vector<Drama> dramas;

//-----------------|
// #classics
//-----------------|
// Desc:   NULL
// Invars: NULL
/// std::vector<Classic> classics;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC FIELDS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #runCmd(string)
//-------------------------------------|
// Desc:    Accepts a command string and executes it
// Note:    For establishing inventory only, not for transactions afterwards
// Params:  string arg1 - The line of command (sourced from data4movies.txt)
// PreCons: All error checks have been performed prior to command receival
//          arg1 is verified to be a syntactically and logically valid command
// PosCons: The inventory database holds the film and data provided by the command
// RetVal:  None
// MetCall: NULL
// void InvDB::runCmd(std::string command) {

//    addFilm(command);
// }

// (+) --------------------------------|
// #addFilm(Film*)
//-------------------------------------|
// Desc:    Adds a new generic film object to the list
// Note:    Sorted by title
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
bool InvDB::addFilm(std::string filmData) {
   int index = 0;

   // if Comedy, add to comedies
   if (filmData.at(0) == 'F') {

      Comedy* film = new Comedy(filmData);

      // find the appropriate position in the comedies vector
      auto iterator = comedies.begin();
      for (int i = 0; i < comedies.size(); i++) {
         if (comedies.at(i) > *film) break;
         iterator++;
      }
      comedies.insert(iterator, *film);
   }

   // if Drama, add to dramas
   else if (filmData.at(0) == 'D') {

      Drama* film = new Drama(filmData);

      // find the appropriate position in the dramas vector
      auto iterator = dramas.begin();
      for (int i = 0; i < dramas.size(); i++) {
         if (dramas.at(i) > *film) break;
         iterator++;
      }
      dramas.insert(iterator, *film);
   }

   // if Classic, add to classics
   else if (filmData.at(0) == 'C') {

      Classic* film = new Classic(filmData);

      // find the appropriate position in the classics vector
      auto iterator = classics.begin();
      for (int i = 0; i < classics.size(); i++) {
         if (classics.at(i) > *film) break;
         iterator++;
      }
      classics.insert(iterator, *film);
   }

   else {
      std::cout << "Invalid film type: " << filmData.at(0) << ". Ignoring..." << std::endl;
   }

   return true;
} // Closing addFilm()

// (+) --------------------------------|
// #adjustStock(Trans&)
//-------------------------------------|
// Desc:    Updates the stock value of a film based on the arg transaction
// Params:  transaction object
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void InvDB::adjustStock(Trans& trans) { // TODO: Add const to Trans& argument?

   // std::cerr << "Trans Data: " << trans.getTitle() << " : " << trans.getReleaseYear() << std::endl;

   // if (trans.getGenre() == 'F') {
   //    Comedy film;
   //    film.setTitle(trans.getTitle());

   //    film.setReleaseYear(std::stoi(trans.getRelease()));

   //    film.setReleaseDate(trans.getReleaseYear());


   //    if (trans.getType() == 'B') {
   //       retrieve(&film)->setStock(retrieve(&film)->getStock() + 1);
   //    }
   //    else {
   //       retrieve(&film)->setStock(retrieve(&film)->getStock() - 1);
   //    }
   // }

   // else if (trans.getGenre() == 'D') {
      
   // }

   // else if (trans.getGenre() == 'C') {
   //    Classic filmAA("C, 0, , , ");
      
   // }

}

// (+) --------------------------------|
// #contains(Film*)
//-------------------------------------|
// Desc:    Checks the DB for a particular film
// Params:  Ptr to film object
// PreCons: NULL
// PosCons: NULL
// RetVal:  True if the film is present, False otherwise
// MetCall: NULL
// bool InvDB::contains(Film* film) {

//    // search the table for the film being added to see if it's already present
//    bool alreadyContainsFilm = false;
//    int index = 0; 

//    // if this film is a comedy
//    if (film->getGenre() == 'F') {
//       while (index < comedies.size()) {
//          if (comedies.at(index) == *film) {
//             alreadyContainsFilm = true;
//             break;
//          }
//          else {
//             index++;
//          }
//       }
//    }
//    // if this film is a drama
//    else if (film->getGenre() == 'D') {
//       while (index < dramas.size()) {
//          if (dramas.at(index) == *film) {
//             alreadyContainsFilm = true;
//             break;
//          }
//          else {
//             index++;
//          }
//       }
//    }
//    // if this film is a classic
//    else if (film->getGenre() == 'C') {
//       while (index < classics.size()) {
//          if (classics.at(index) == *film) {
//             alreadyContainsFilm = true;
//             break;
//          }
//          else {
//             index++;
//          }
//       }
//    }
//    return alreadyContainsFilm;

// }

// (+) --------------------------------|
// #isLegal()
//-------------------------------------|
// Desc:    Tests the legality of a received command string
//          Outputs an error to cout for illegal conditions
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
bool InvDB::isLegal(std::string command) {
   // TODO: Implement
   return true;
}

// (+) --------------------------------|
// #retrieve(Film*)
//-------------------------------------|
// Desc:    Searches for a film object and returns it instead of a bool
// Params:  Film object to be found
// PreCons: NULL
// PosCons: NULL
// RetVal:  Pointer to the film object
// MetCall: NULL
// Film* InvDB::retrieve(Film* film) {

//    // search the table for the film being added to see if it's already present
//    int i = 0; 

//    // if this film is a comedy
//    if (film->getGenre() == 'F') {
//       while (i < comedies.size()) {
//          if (comedies.at(i) == *film) {
//             break;
//          }
//          else {
//             i++;
//          }
//       }

//       return &comedies.at(i);
//    }

//    else if (film->getGenre() == 'D') {
//       while (i < dramas.size()) {
//          if (dramas.at(i) == *film) {
//             break;
//          }
//          else {
//             i++;
//          }
//       }

//       return &dramas.at(i);
//    }

//    else if (film->getGenre() == 'C') {
//       while (i < classics.size()) {
//          if (classics.at(i) == *film) {
//             break;
//          }
//          else {
//             i++;
//          }
//       }

//       return &classics.at(i);
//    }
//    else {
//       return NULL;
//    }
// }

// (+) --------------------------------|
// #display()
//-------------------------------------|
// Desc:    Displays to cout the status of the InvDB
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void const InvDB::display() {
   std::cout << toString();
}

// (+) --------------------------------|
// #toString()
//-------------------------------------|
// Desc:    Outputs a string representation of the InvDB
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  string
// MetCall: NULL
std::string const InvDB::toString() {
   std::string retString = "";
   retString += "\n";
   retString += "Comedy films: \n";

   for (int i = 0; i < comedies.size(); i++) {
      retString += std::to_string(comedies.at(i).getStock());
      retString += ", ";
      retString += comedies.at(i).getTitle();
      retString += ", ";
      retString += comedies.at(i).getDirector();
      retString += ", ";
      retString += std::to_string(comedies.at(i).getReleaseYear());
      retString += "\n";
   }

   retString += "\n";
   retString += "Drama films: \n";

   for (int i = 0; i < dramas.size(); i++) {
      retString += std::to_string(dramas.at(i).getStock());
      retString += ", ";
      retString += dramas.at(i).getTitle();
      retString += ", ";
      retString += dramas.at(i).getDirector();
      retString += ", ";
      retString += std::to_string(dramas.at(i).getReleaseYear());
      retString += "\n";
   }

   retString += "\n";
   retString += "Classic films: \n";

   for (int i = 0; i < classics.size(); i++) {
      retString += std::to_string(classics.at(i).getStock());
      retString += ", ";
      retString += classics.at(i).getTitle();
      retString += ", ";
      retString += classics.at(i).getDirector();
      retString += ", ";
      retString += classics.at(i).getActor();
      retString += ", ";
      retString += std::to_string(classics.at(i).getReleaseMonth()) + " ";
      retString += std::to_string(classics.at(i).getReleaseYear());
      retString += "\n";
   }

   return (retString);
} // Closing toString()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #getCTitleByTuple()
//-------------------------------------|
// Desc:    Default InvDB constructor
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string InvDB::getCTitleByTuple(int month, int year, std::string actor) {

   return("<InvDB::getCTitleByTuple() placeholder>");
} // Closing getCTitleByTuple()

// (+) --------------------------------|
// #getDYearByTuple()
//-------------------------------------|
// Desc:    NULL
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
int InvDB::getDYearByTuple(std::string director, std::string title) {
   int retYear = 2002;

   return(retYear);
} // Closing getDYearByTuple()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS/DESTRUCTOR
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #InvDB()
//-------------------------------------|
// Desc:    Default InvDB constructor
// Params:  NULL
// PreCons: NULL
// PosCons: An empty InvDB object has been created
// RetVal:  None
// MetCall: NULL
InvDB::InvDB() {
   // TODO: Initialize all fields (to keep g++ happy)
} // Closing InvDB()

// (+) --------------------------------|
// #InvDB(ifstream&)
//-------------------------------------|
// Desc:    InvDB constructor by bulk command set
// Params:  ifstream& arg1 - The bulk set of inventory commands
// PreCons: NULL
// PosCons: NULL
// RetVal:  None
// MetCall: NULL
InvDB::InvDB(std::ifstream& data) {

   while (!data.eof()) {
      // Read the next relevant line of command
      std::string filmData;
      std::getline(data, filmData);

      // add this film to the database from it's data-string
      addFilm(filmData);
   }
} // Closing InvDB(ifstream)

// (+) --------------------------------|
// #~InvDB()
//-------------------------------------|
// Desc:    InvDB deconstructor
// Params:  None
// PreCons: NULL
// PosCons: NULL
// RetVal:  None
// MetCall: NULL
InvDB::~InvDB() {
   // std::cerr << "destruct invDB" << std::endl;

   // std::cerr << "end destruct invDB" << std::endl;
}

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of file - InvDB.cpp
