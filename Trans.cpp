//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// Trans.cpp
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------------------------------------------------------------------|
// Authorship
//-----------------------------------------------------------------------------|
//
// Matt Gross & Tim Lum
// mattgrosspersonal@gmail.com + twhlum@gmail.com
// Created:  2018.03.03
// Modified: 2018.03.14
// For the University of Washington Bothell, CSS 502A
// Winter 2018, Graduate Certificate in Software Design & Development (GCSDD)
//

//-----------------------------------------------------------------------------|
// File Description
//-----------------------------------------------------------------------------|
//
// This is the implementation file for the Trans.h header, representing a
// transaction class of objects
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

// Necessary for string operations
#include <string>

// Necessary for input-output operations
#include <iostream>

// Necessary for string formatting operations
#include <iomanip>

// Necessary for string stream buffering operations
#include <sstream>

// Field and method declarations for the Trans (Transaction) class
#include "Trans.h"



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CLASS CONSTANTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
//
// Do not redeclare these variables in the .cpp.
// Included here only for reference
// See associated .h file for variable declarations
//
// None for this class
//



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
// #type
// #typeAsString
//-----------------|
// Desc:   The transaction type (borrow or return)
// Invars: Initializes to junk values
///   char type;
///   std::string typeAsString;

//-----------------|
// #genre
// #genreAsString
//-----------------|
// Desc:   Genre of the thing transacted
// Invars: Initializes to junk values
///   char genre;
///   std::string genreAsString;

//-----------------|
// #title
//-----------------|
// Desc:   Identifier of the thing transacted
// Invars: Initializes to junk values
///   std::string title;

//-----------------|
// #director
// #actor
//-----------------|
// Desc:   Unique identifiers of the transaction
// Invars: Initializes to junk values
///   std::string director;
///   std::string actor;

//-----------------|
// #release
//-----------------|
// Desc:   A string representation of the release date
// Invars: Initializes to junk values
///   int releaseMonth = 0;
///   int releaseYear = 0;

//-----------------|
// #customerID
//-----------------|
// Desc:   The transaction type
// Invars: Initializes to junk values
///   int customerID; // To whom it was transacted



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC FIELDS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #display()
//-------------------------------------|
// Desc:    Outputs internal state of transaction to cout
// Params:  None
// PreCons: A valid transaction must exist (call to a nullptr will fail)
// PosCons: Transaction states have been outputted to console
// RetVal:  None
// MetCall: None
void Trans::debug() const {
   std::cout << std::endl;
   std::cout << "Trans::debug() - @ address (" << this << ") - CAPS denote required fields" << std::endl;
   std::cout << "TypeChar:     " << this->type << std::endl;
   std::cout << "TYPESTRING:   " << this->typeAsString << std::endl;
   std::cout << "GenreChar:    " << this->genre << std::endl;
   std::cout << "GENRESTRING:  " << this->genreAsString << std::endl;
   std::cout << "TITLE:        " << this->title << std::endl;
   std::cout << "Director:     " << this->director << std::endl;
   std::cout << "Actor:        " << this->actor << std::endl;
   std::cout << "RELEASEMONTH: " << this->releaseMonth << std::endl;
   std::cout << "RELEASERYEAR: " << this->releaseYear << std::endl;
   std::cout << "CustomerID:   " << this->customerID << std::endl;
   std::cout << std::endl;
} // Closing debug()

// (+) --------------------------------|
// #toString()
//-------------------------------------|
// Desc:    Outputs a string representation of the transaction
// Params:  None
// PreCons: Proper format requires:
//          CustomerID
//          Transaction type as string
//          Film title
//          Film genre
//          Release month (if applicable)
//          Release year
// PosCons: Formatted to match the Customer History requirements
// RetVal:  string - A summary representation of this transaction
// MetCall: None
std::string Trans::toString() const {
   // The string to return
   std::string retString = "";
   // A working stream for formatted outputs
   std::ostringstream tempStream;

   // Sample output:
   // (ID: <customerID>) <type> - '<title>' (<genre>), <release>
   // (ID: 1234) Borrow - 'Jurassic Park' (Drama), 1993

   // Append all values, properly formatted

   // (ID: 1234)
   tempStream << std::setw(4) << std::setfill('0') << this->customerID;
   // Assign the temporary stream to a string
   std::string IDnumString(tempStream.str());

   // (ID: 1234) Borrow - '
   retString += "(ID: " + IDnumString + ") " + this->typeAsString + " - '";

   // (ID: 1234) Borrow - 'Jurassic Park' (Drama), 
   retString += this->title + "' (" + this->genreAsString + "), ";

   // (ID: 1234) Borrow - 'Jurassic Park' (Drama), 
   if (this->releaseMonth != 0) {
      retString += std::to_string(this->releaseMonth) + " ";
   }

   // (ID: 1234) Borrow - 'Jurassic Park' (Drama), 1993
   retString += std::to_string(this->releaseYear);

   return(retString);
} // Closing toString()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #getType()
// #getTypeAsString()
//-------------------------------------|
// Desc:    Gets the Type/TypeAsString
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  char/string - The transaction type (Borrow or Return)
// MetCall: None
char Trans::getType() const {
   return(this->type);
} // Closing getType()
std::string Trans::getTypeAsString() const {
   return(this->typeAsString);
} // Closing getTypeAsString()

// (+) --------------------------------|
// #getGenre()
// #getGenreAsString()
//-------------------------------------|
// Desc:    Gets the customerID
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  int - The Customer ID
// MetCall: None
char Trans::getGenre() const {
   return(this->genre);
}
std::string Trans::getGenreAsString() const {
   return(this->genreAsString);
}

// (+) --------------------------------|
// #getTitle()
//-------------------------------------|
// Desc:    Gets the customerID
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  int - The Customer ID
// MetCall: None
std::string Trans::getTitle() const {
   return(this->title);
}

// (+) --------------------------------|
// #getIdentifier1()
//-------------------------------------|
// Desc:    Gets the customerID
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  int - The Customer ID
// MetCall: None
std::string Trans::getDirector() const {
   return(this->director);
}

// (+) --------------------------------|
// #getIdentifier2()
//-------------------------------------|
// Desc:    Gets the customerID
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  int - The Customer ID
// MetCall: None
std::string Trans::getActor() const {
   return(this->actor);
}

// (+) --------------------------------|
// #getReleaseMonth()
//-------------------------------------|
// Desc:    Gets the customerID
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  int - The Customer ID
// MetCall: None
int Trans::getReleaseMonth() const {
   return(this->releaseMonth);
}

// (+) --------------------------------|
// #getReleaseYear()
//-------------------------------------|
// Desc:    Gets the customerID
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  int - The Customer ID
// MetCall: None
int Trans::getReleaseYear() const {
   return(this->releaseYear);
}

// (+) --------------------------------|
// #getCustID()
//-------------------------------------|
// Desc:    Gets the customerID
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  int - The Customer ID
// MetCall: None
int Trans::getCustID() const {
   return(this->customerID);
} // Closing getCustID()

// (+) --------------------------------|
// #setType(char)
// #setTypeAsString(string)
//-------------------------------------|
// Desc:    Sets the transaction type to a received char/string value
// Params:  char/string arg1 - The transaction type (borrow or return)
// PreCons: GIGO - No error checking is handled by this method.
// PosCons: The transaction type has been set
// RetVal:  None
// MetCall: None
void Trans::setType(char transType) {
   this->type = transType;
} // Closing setType()
void Trans::setTypeAsString(std::string transType) {
   this->typeAsString = transType;
} // Closing setTypeAsString()

// (+) --------------------------------|
// #setGenre(char)
// #setGenreAsString(string)
//-------------------------------------|
// Desc:    Sets the genre to a received char/string value
// Params:  char/string arg1 - The genre of the film being transacted
// PreCons: GIGO - No error checking is handled by this method
// PosCons: The genre has been set
// RetVal:  None
// MetCall: None
void Trans::setGenre(char theGenre) {
   this->genre = theGenre;
} // Closing setGenre()
void Trans::setGenreAsString(std::string theGenre) {
   this->genreAsString = theGenre;
} // Closing setGenreAsString()

// (+) --------------------------------|
// #setTitle(string)
//-------------------------------------|
// Desc:    Sets the title of the film transacted to a received string value
// Params:  string arg1 - The title of the film being transacted
// PreCons: GIGO - No error checking is handled by this method.
// PosCons: The title has been set
// RetVal:  None
// MetCall: None
void Trans::setTitle(std::string theTitle) {
   this->title = theTitle;
} // Closing setTitle()

// (+) --------------------------------|
// #setDirector(string)
//-------------------------------------|
// Desc:    Sets the director to a received stringvalue
// Params:  string arg1 - The director of the film being transacted
// PreCons: GIGO - No error checking is handled by this method.
// PosCons: The director has been set
// RetVal:  None
// MetCall: None
void Trans::setDirector(std::string director) {
   this->director = director;
} // Closing setDirector()

// (+) --------------------------------|
// #setActor(string)
//-------------------------------------|
// Desc:    Sets the actor to a received string value
// Params:  string arg1 - The actor name of the film being transacted
// PreCons: GIGO - No error checking is handled by this method.
// PosCons: The actor has been set
// RetVal:  None
// MetCall: None
void Trans::setActor(std::string actor) {
   this->actor = actor;
} // Closing setActor()

// (+) --------------------------------|
// #setReleaseMonth(int)
//-------------------------------------|
// Desc:    Sets the releaseMonth to a received int value
// Params:  int arg1 - The month release of the film being transacted
// PreCons: GIGO - No error checking is handled by this method.
// PosCons: The ID has been set
// RetVal:  None
// MetCall: None
void Trans::setReleaseMonth(int month) {
   this->releaseMonth = month;
} // Closing setReleaseMonth()

// (+) --------------------------------|
// #setReleaseYear(int)
//-------------------------------------|
// Desc:    Sets the customerID to a received int value
// Params:  int arg1 - The year release of the film being transacted
// PreCons: GIGO - No error checking is handled by this method.
// PosCons: The year has been set
// RetVal:  None
// MetCall: None
void Trans::setReleaseYear(int year) {
   this->releaseYear = year;
} // Closing setReleaseYear()

// (+) --------------------------------|
// #setCustID(int)
//-------------------------------------|
// Desc:    Sets the customerID to a received int value
// Params:  int arg1 - The customerID involved in the transaction
// PreCons: GIGO - No error checking is handled by this method.
// PosCons: The ID has been set
// RetVal:  None
// MetCall: None
void Trans::setCustID(int IDnum) {
   this->customerID = IDnum;
} // Closing setCustID()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #Trans()
//-------------------------------------|
// Desc:    Defaults Transaction constructor
// Params:  None
// PreCons: Should not be called under normal circumstances
// PosCons: All fields have been initialized
// RetVal:  None
// MetCall: None
Trans::Trans() {
   // Initialize all variables
   this->type          = NULL;
   this->typeAsString  = "";
   this->genre         = NULL;
   this->genreAsString = "";
   this->title         = "";
   this->director      = "";
   this->actor         = "";
   this->releaseMonth  = 0;
   this->releaseYear   = 0;
   this->customerID    = 1234512345;
} // Closing Trans()

// (+) --------------------------------|
// #Trans(string)
//-------------------------------------|
// Desc:    Constructor of Transaction object by string
// Params:  string arg1 - The command to construct a transaction out of
// PreCons: GIGO - Command must be correctly formatted and vetted
// PosCons: As many fields as possible of the Transaction are populated
//          Populated fields will be inconsistent depending on genre
//          Certain fields will remain unitialized
//          Filling these fields will require the use of setter methods from outside
// RetVal:  None
// MetCall: None
Trans::Trans(std::string command) {
   // Initialize all variables
   this->type          = NULL;
   this->typeAsString  = "";
   this->genre         = NULL;
   this->genreAsString = "";
   this->title         = "";
   this->director      = "";
   this->actor         = "";
   this->releaseMonth  = 0;
   this->releaseYear   = 0;
   this->customerID    = 1234512345;

   // Sample input:
   // "B 1111 D F Ferries and You: A Primer, 2018"

   // Step 1: Load the command to a stream
   std::stringstream stream;
   stream << command;

   // Step 2: Get the transaction type, assign fields properly
   stream >> this->type;
   if (this->type == 'B') {
      this->typeAsString = "Borrow";
   }
   else if (this->type == 'R') {
      this->typeAsString = "Return";
   }

   // Step 3: Get the customer ID number
   stream >> this->customerID;

   // Step 4: Remove the DVD format
   std::string temp = "";
   stream >> temp;

   // Step 5.1: Get the genre
   stream >> this->genre;

   // Step 5.2: Set the genreAsStrings
   if (this->genre == 'C') {
      this->genreAsString = "Classic";
   }
   else if (this->genre == 'D') {
      this->genreAsString = "Drama";
   }
   else if (this->genre == 'F') {
      this->genreAsString = "Comedy";
   }
   
   // Set the Skip White Space flag to off
   stream >> std::noskipws;

   // Step 6.C: Parse film info (classic)
   if (this->genre == 'C') {
      // Sample input: "B 5000 D C 3 1971 Ruth Gordon"
      // Classic parse strategy goes here
      // NOTE: Classics are always searched for by MM YYYY ACTOR
      stream >> std::skipws;
      stream >> this->releaseMonth;
      stream >> this->releaseYear;
      std::string fname;
      std::string lname;

      stream >> fname; // Gets first name
      stream >> lname; // Gets last name
      this->actor = fname + " " + lname;
   }

   // Step 6.D: Parse film info (drama)
   else if (this->genre == 'D') {
      // Sample input: "B 8888 D D Nancy Savoca, Dogfight,"
      // Drama parse strategies go here
      // NOTE: Dramas are searched for by Director, Title
      char temp = NULL;
      stream >> temp;
      // Load the first valid char from the stream to the director
      stream >> temp;
      // Append characters to the director until a ',' is encountered
      while (temp != ',') {
         this->director += temp;
         stream >> temp;
      } // Closing while - All chars appended, director is complete

      // Remove the ' '
      stream >> temp;

      // Load the first letter of the title
      stream >> temp;
      // And load the next valid string from the stream to the title
      while (temp != ',') {
         this->title += temp;
         stream >> temp;
      } // Closing while - All chars appended, title is complete
   }

   // Step 6.F: Parse film info (comedy)
   else if (this->genre == 'F') {
      // Sample input: "B 8000 D F National Lampoon's Animal House, 1978"
      // Comedy parse strategies go here
      // NOTE: Comedies are searched for by Title, Year
      char temp = NULL;
      stream >> temp;
      stream >> temp;
      // Append characters to the title until a ',' is encountered
      while (temp != ',') {
         this->title += temp;
         stream >> temp;
      } // Closing while - All chars appended, title is complete
      // Remove the ' '
      stream >> temp;
      // And load the next valid int from the stream to the release date
      stream >> this->releaseYear;
   }
} // Closing Trans(string)

// (+) --------------------------------|
// #~Trans()
//-------------------------------------|
// Desc:    Trans deconstructor
// Params:  None
// PreCons: None
// PosCons: All fields have been zeroed
// RetVal:  None
// MetCall: None
Trans::~Trans() {
   // Reset all field states before deallocating
   this->type          = NULL;
   this->typeAsString  = "";
   this->genre         = NULL;
   this->genreAsString = "";
   this->title         = "";
   this->director      = "";
   this->actor         = "";
   this->releaseMonth  = 0;
   this->releaseYear   = 0;
   this->customerID    = 1234512345;
} // Closing ~Trans()

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of file - Trans.cpp
