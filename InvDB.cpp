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
#include <sstream>
#include <string>
#include <iomanip>



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

      Comedy film(filmData);

      // find the appropriate position in the comedies vector
      auto iterator = comedies.begin();
      for (unsigned int i = 0; i < comedies.size(); i++) {
         if (comedies.at(i) > film) break;
         iterator++;
      }
      comedies.insert(iterator, film);
   }

   // if Drama, add to dramas
   else if (filmData.at(0) == 'D') {

      Drama film(filmData);

      // find the appropriate position in the dramas vector
      auto iterator = dramas.begin();
      for (unsigned int i = 0; i < dramas.size(); i++) {
         if (dramas.at(i) > film) break;
         iterator++;
      }
      dramas.insert(iterator, film);
   }

   // if Classic, add to classics
   else if (filmData.at(0) == 'C') {

      Classic film(filmData);

      // find the appropriate position in the classics vector
      auto iterator = classics.begin();
      for (unsigned int i = 0; i < classics.size(); i++) {
         if (classics.at(i) > film) break;
         iterator++;
      }
      classics.insert(iterator, film);
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
bool InvDB::adjustStock(const Trans& trans) {

   bool foundFilm = false;
   bool noStock = false;
   bool anyErrors = false;

   // Retrieve film
   // Search the table for the film being added to see if it's already present

   // If this film is a comedy
   if (trans.getGenre() == 'F') {

      // Look through the comedies vector for a Comedy that matches the transaction
      for (unsigned int i = 0; i < comedies.size(); i++) {
         if (comedies.at(i).getTitle() == trans.getTitle()
             && comedies.at(i).getReleaseYear() == trans.getReleaseYear()) {

            // Once it's found, adjust the film's stock value
            if (trans.getType() == 'B') {
               if (comedies.at(i).getStock() > 0) {
                  comedies.at(i).setStock(comedies.at(i).getStock() - 1);
               }
               else {
                  noStock = true;
               }
            }
            else if (trans.getType() == 'R') {
               comedies.at(i).setStock(comedies.at(i).getStock() + 1);
            }
            foundFilm = true;
            break;
         }
      }
   }
   // If this film is a drama
   else if (trans.getGenre() == 'D') {

      // Look through the dramas vector for a Drama that matches the transaction
      for (unsigned int i = 0; i < dramas.size(); i++) {
         if (dramas.at(i).getDirector() == trans.getDirector()
             && dramas.at(i).getTitle() == trans.getTitle()) {

            // Once it's found, adjust the film's stock value
            if (trans.getType() == 'B') {
               if (dramas.at(i).getStock() > 0) {
                  dramas.at(i).setStock(dramas.at(i).getStock() - 1);
               }
               else {
                  noStock = true;
               }
            }
            else if (trans.getType() == 'R') {
               dramas.at(i).setStock(dramas.at(i).getStock() + 1);
            }
            foundFilm = true;
            break;
         }
      }
   }
   // If this film is a classic
   else if (trans.getGenre() == 'C') {
      int year;
      std::string title;

      // Look through the classics vector for a Classic that matches the transaction
      for (unsigned int i = 0; i < classics.size(); i++) {
         if (classics.at(i).getReleaseYear() == trans.getReleaseYear()
             && classics.at(i).getReleaseMonth() == trans.getReleaseMonth()
             && classics.at(i).getActor() == trans.getActor()) {

            // Once it's found, adjust the film's stock value
            if (trans.getType() == 'B') {
               if (classics.at(i).getStock() > 0) {
                  classics.at(i).setStock(classics.at(i).getStock() - 1);
               }
               else {
                  noStock = true;
                  // Save the year and title for looking at alternate classics
                  year = classics.at(i).getReleaseYear();
                  title = classics.at(i).getTitle();
               }
            }
            else if (trans.getType() == 'R') {
               classics.at(i).setStock(classics.at(i).getStock() + 1);
            }
            foundFilm = true;
            break;
         }
      }
      // Special condition for sharing stock between classics with the same title but different actors
      if (noStock == true) {
         for (unsigned int i = 0; i < classics.size(); i++) {

            // if classic matches title and year, and has some available stock
            if (classics.at(i).getTitle() == title
                && classics.at(i).getReleaseYear() == year
                && classics.at(i).getStock() > 0) {

               // adjust the film's stock value
               classics.at(i).setStock(classics.at(i).getStock() - 1);
               noStock = false;
               break;
            }
         }
      }
   }

   // Report any errors
   if (foundFilm == false) {
      trans.debug();
      std::cout << "Invalid " << trans.getType() << ", film does not exist in database" << std::endl;
      anyErrors = true;
   }
   if (noStock == true) {
      trans.debug();
      std::cout << "No stock available for this film" << std::endl;
      anyErrors = true;
   }
   
   // If no errors, return success
   return(!anyErrors);
}

// (+) --------------------------------|
// #isLegal()
//-------------------------------------|
// Desc:    Tests the legality of a received inventory command
//          Outputs an error to cout for illegal conditions
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
bool InvDB::isLegal(std::string command) {
   // TODO: Implement
   // Sample inputs
   // C, 10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942
   // D, 10, Barry Levinson, Good Morning Vietnam, 1988
   // F, 10, Nora Ephron, Sleepless in Seattle, 1993

   bool isLegal = true;

   // Things to check:
   // Is the correct position in the vector already occupied (duplicate sort criteria)?
   // Do not implement - Assignment specification guarantees this not to happen

   // Does the seed value place the stock into the net negatives? (0 is okay where alternate criteria )
   // Do not implement - Establishing negative starting inventory values is nonsensical

   return (isLegal);
} // Closing isLegal()

// (+) --------------------------------|
// #isValidTransCmd()
//-------------------------------------|
// Desc:    Tests the legality of a received transaction command
//          Outputs an error to cout for illegal conditions
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
bool InvDB::isValidTransCmd(std::string command) {
   // TODO: Implement
   // Sample inputs
   // B 1000 D C 5 1940 Katherine Hepburn
   // B 1000 D D Barry Levinson, Good Morning Vietnam,
   // B 8000 D F You've Got Mail, 1998
   bool isValid = false;
   std::string errLog = "";
   // Things to check:
   // Can a matching film be found in the database (does the film exist)?
   // Are there enough movies in stock to fulfill the transaction?

   // Initialize field variables
   char commandType = NULL;
   int custID = 1234512345;
   char format = NULL; // 'D' for DVD on all titles
   char genre = NULL;
   int releaseMonth = 0; // (in case of Classic)
   int releaseYear = 0;
   std::string director = "";
   std::string title = "";
   std::string actor = ""; // (in case of Classic)

   std::stringstream stream;
   stream << command;

   // Step 2: Get the transaction type, assign fields properly
   stream >> commandType;

   // Step 3: Get the customer ID number
   stream >> custID;

   // Step 4: Remove the DVD format
   stream >> format;

   // Step 5.1: Get the genre
   stream >> genre;

   // Set the Skip White Space flag to off
   stream >> std::noskipws;


   // CLASSIC CASE
   if (genre == 'C') {
      // Parse fields
      stream >> std::skipws;
      stream >> releaseMonth;
      stream >> releaseYear;
      std::string fname;
      std::string lname;

      stream >> fname; // Gets first name
      stream >> lname; // Gets last name
      actor = fname + " " + lname;

      // Check things with them
      // Assuming the film will not be found:
      errLog = "   - Film not found in Classics table";

      // Iterate over vector<Classic> classics
      for (unsigned int i = 0; i < classics.size(); i++) {
         // Search for the year
         if (classics.at(i).getReleaseYear() == releaseYear) {
            // Search for the month
            if (classics.at(i).getReleaseMonth() == releaseMonth) {
               // Search for the actor
               if (classics.at(i).getActor() == actor) {
                  // All fields are a match! It's looking like this is legal!
                  isValid = true;
                  // Unless the stock check fails
                  if (classics.at(i).getStock() < 1) {
                     isValid = false;
                     errLog = "   - Insufficient stock to fulfill order";
                  }
               } // Closing actor match
            } // Closing month match
         } // Closing year match
      } // Closing for - All classic entries examined
      if (isValid == false) {
         std::cout << "Transaction Command error @ InvDatabase ('" << command << "'):" << std::endl;
         std::cout << errLog << std::endl;
      }
   } // Closing if - Classic case handled


   // DRAMA CASE
   // Sample input: B 1000 D D Barry Levinson, Good Morning Vietnam,
   if (genre == 'D') {
      // Sample input: "B 8888 D D Nancy Savoca, Dogfight,"
      // Drama parse strategies go here
      // NOTE: Dramas are searched for by Director, Title
      char temp = NULL;
      stream >> temp;
      // Load the first valid char from the stream to the director
      stream >> temp;
      // Append characters to the director until a ',' is encountered
      while (temp != ',') {
         director += temp;
         stream >> temp;
      } // Closing while - All chars appended, director is complete - VERIFIED

      // Remove the ' '
      stream >> temp;

      // Load the first letter of the title
      stream >> temp;
      // And load the next valid string from the stream to the title
      while (temp != ',') {
         title += temp;
         stream >> temp;
      } // Closing while - All chars appended, title is complete - VERIFIED

      // Check things with them
      // Assuming the film will not be found:
      errLog = "   - Film not found in Dramas table";
      // Iterate over vector<Drama> dramas
      for (unsigned int i = 0; i < dramas.size(); i++) {
         // Search for the director
         if (dramas.at(i).getDirector() == director) {
            // Search for the title
            if (dramas.at(i).getTitle() == title) {
               // All fields are a match! It's looking like this is legal!
               isValid = true;
               // Unless the stock check fails
               if (dramas.at(i).getStock() < 1) {
                  isValid = false;
                  errLog = "   - Insufficient stock to fulfill order";
               }
            } // Closing title match
         } // Closing director match
      } // Closing for - All drama entries examined

      if (isValid == false) {
         std::cout << "Transaction Command error @ InvDatabase ('" << command << "'):" << std::endl;
         std::cout << errLog << std::endl;
      }
   }


   // COMEDY CASE
   // Sample input: B 8000 D F You've Got Mail, 1998
   if (genre == 'F') {
      // Sample input: "B 8000 D F National Lampoon's Animal House, 1978"
      // Comedy parse strategies go here
      // NOTE: Comedies are searched for by Title, Year
      char temp = NULL;
      stream >> temp;
      stream >> temp;
      // Append characters to the title until a ',' is encountered
      while (temp != ',') {
         title += temp;
         stream >> temp;
      } // Closing while - All chars appended, title is complete
      // Remove the ' '
      stream >> temp;
      // And load the next valid int from the stream to the release date
      stream >> releaseYear;

      // Check things with them
      // Assuming the film will not be found:
      errLog = "   - Film not found in Comedies table";

      // Iterate over vector<Comedy> comedies
      for (unsigned int i = 0; i < comedies.size(); i++) {
         // Search for the director
         if (comedies.at(i).getTitle() == title) {
            // Search for the title
            if (comedies.at(i).getReleaseYear() == releaseYear) {
               // All fields are a match! It's looking like this is legal!
               isValid = true;
               // Unless the stock check fails
               if (comedies.at(i).getStock() < 1) {
                  isValid = false;
                  errLog = "   - Insufficient stock to fulfill order";
               }
            } // Closing title match
         } // Closing director match
      } // Closing for - All comedy entries examined

      if (isValid == false) {
         std::cout << "Transaction Command error @ InvDatabase ('" << command << "'):" << std::endl;
         std::cout << errLog << std::endl;
      }
   } // Closing comedy case

   return (isValid);
} // Closing isValidTransCmd

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
   retString += "Comedy films: \n";
   retString += "(Qty) 'Title'                             Director             Released \n";
   retString += "----- ----------------------------------- -------------------- ---------\n";
   //            ( 10) 'Annie Hall'                        Woody Allen          1977

   for (unsigned int i = 0; i < comedies.size(); i++) {
      std::stringstream stream;
      stream << "(" << std::setw(3) << comedies.at(i).getStock() << ") ";
      stream << "'" << std::setw(35) << std::left << (comedies.at(i).getTitle()+"'") ;
      stream << std::setw(20) << comedies.at(i).getDirector() << " " <<comedies.at(i).getReleaseYear();
      retString += stream.str() + "\n";
   }

   retString += "\n";
   retString += "Drama films: \n";
   retString += "(Qty) 'Title'                             Director             Released \n";
   retString += "----- ----------------------------------- -------------------- ---------\n";

   for (unsigned int i = 0; i < dramas.size(); i++) {
      std::stringstream stream;
      stream << "(" << std::setw(3) << dramas.at(i).getStock() << ") ";
      stream << "'" << std::setw(35) << std::left << (dramas.at(i).getTitle()+"'") ;
      stream << std::setw(20) << dramas.at(i).getDirector() << " " <<dramas.at(i).getReleaseYear();
      retString += stream.str() + "\n";
   }

   retString += "\n";
   retString += "Classic films: \n";
   retString += "(Qty) 'Title'                             Director             Featuring            Released \n";
   retString += "----- ----------------------------------- -------------------- -------------------- ---------\n";
                 //-------|---------|---------|---------|---------|---------|---------|---------|

   for (unsigned int i = 0; i < classics.size(); i++) {
            std::stringstream stream;
      stream << "(" << std::setw(3) << classics.at(i).getStock() << ") ";
      stream << "'" << std::setw(35) << std::left << (classics.at(i).getTitle()+"'") ;
      stream << std::setw(21) << classics.at(i).getDirector() << std::setw(21) << classics.at(i).getActor();
      stream << std::setw(1) << classics.at(i).getReleaseYear() << "." << std::setw(2) << std::right << classics.at(i).getReleaseMonth();
      retString += stream.str() + "\n";
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
// Desc:    Attempts to return a title by Classic search criteria
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
std::string InvDB::getCTitleByTuple(int month, int year, std::string actor) {
   std::string retTitle= "";
   // Iterate over vector<Classic> classics
   for (unsigned int i = 0; i < classics.size(); i++) {
      // Search for the year
      if (classics.at(i).getReleaseYear() == year) {
         // Search for the month
         if (classics.at(i).getReleaseMonth() == month) {
            // Search for the actor
            if (classics.at(i).getActor() == actor) {
               // All fields are a match! Assign the title to the returnString
               retTitle = classics.at(i).getTitle();
            } // Closing actor match
         } // Closing month match
      } // Closing year match
   } // Closing for - All classic entries examined
   return(retTitle);
} // Closing getCTitleByTuple()

// (+) --------------------------------|
// #getDYearByTuple()
//-------------------------------------|
// Desc:    Attempts to return a year by 
// Params:  NULL
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
int InvDB::getDYearByTuple(std::string director, std::string title) {
   // TODO: Implement
   int retYear = 0;

   // Iterate over vector<Drama> classics
   for (unsigned int i = 0; i < dramas.size(); i++) {
      // Search for the director
      if (dramas.at(i).getDirector() == director) {
         // Search for the title
         if (dramas.at(i).getTitle() == title) {
            // At the resultant film, assign the year to the returnInt
            retYear = dramas.at(i).getReleaseYear();
         } // Closing title match
      } // Closing director match
   } // Closing for - All drama entries examined
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

   auto iterator = comedies.begin();
   for (unsigned int i = 0; i < comedies.size(); i++) {
      
      // delete *iterator;

      iterator++;
   }


   // comedies.erase(comedies.begin());
   // dramas.erase(dramas.begin());
   // classics.erase(classics.begin());

   // std::cerr << "end destruct invDB" << std::endl;
}

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of file - InvDB.cpp
