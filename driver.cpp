//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// Driver.cpp
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
// An inventory control system. Utilizes InvDB and CustDB classes to manage a
// database of film objects, generating and directing transactions created from
// a set of bulk command documents.
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

// Necessary for file stream object handling
#include <fstream>

// Necessary for input-output stream operations
#include <iostream>

// Necessary for stream operations
#include <sstream>

// Necessary for stream output manipulations
#include <iomanip>

// Necessary for transaction objects
#include "Trans.h"

// Necessary for film objects
#include "Film.h"
#include "FilmComedy.h"
#include "FilmDrama.h"
#include "FilmClassic.h"

// Necessary for customer objects
#include "Cust.h"

// Necessary for database objects
#include "InvDB.h"
#include "CustDB.h"



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       METHOD DECLARATIONS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Bulk reader - Customers
void bulkReadCust(std::ifstream& custtxt, CustDB& tgtDB);

// Bulk reader - Inventory
void bulkReadInv(std::ifstream& invtxt, InvDB& tgtDB);

// Bulk reader - Transactions
void bulkReadTrans(std::ifstream& transtxt, CustDB& tgtCustDB, InvDB& tgtInvDB);

// Legality check - Customer commands
bool isLegalCustCmd(std::string command, CustDB& tgtDB);

// Legality check - Inventory commands
bool isLegalInvCmd(std::string command, InvDB& tgtDB);

// Legality check - Transaction commands
bool isLegalTransCmd(std::string command, CustDB& tgtDB, InvDB& tgtInvDB);

// Appends missing information to a transaction
void padOut(Trans* transPtr, InvDB& tgtInvDB);


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       MAIN()
//
//-------|---------|---------|---------|---------|---------|---------|---------|

int main() {

   // Acquire the relevant files
   std::ifstream commandFile("data4commands.txt");
   std::ifstream customerFile("data4customers.txt");
   std::ifstream inventoryFile("data4movies.txt");

   // Create a customer database
   CustDB custDB;
   // Read all customer commands into it
   bulkReadCust(customerFile, custDB);

   // Create an inventory database
   InvDB invDB;
   // Read all inventory commands into it
   bulkReadInv(inventoryFile, invDB);

   // Read, parse, verify, and forward all transaction commands to the databases
   bulkReadTrans(commandFile, custDB, invDB);

   return (0);
} // Closing main()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       METHOD IMPLEMENTATIONS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #bulkReadCust(ifstream&, CustDB)
//-------------------------------------|
// Desc:    Bulk reader of a correctly formatted customer command file
// Params:  ifstream& arg1 - The target text file containing customer commands
//          CustDB arg2 - The receiving Customer database
// PreCons: A valid CustDB object must exist.
// PosCons: The ifstream has been consumed
//          All valid commands have been sent to the target CustDB
//          Does not guarantee correct handling of commands at destination DB
//          Does not handle any error reporting
// RetVal:  None
// MetCall: isLegalCustCmd() - Verifies all legality checks of the command
void bulkReadCust(std::ifstream& custFile, CustDB& tgtDB) {
   while (!custFile.eof()) {
      // Get a line of text (one command)

      std::string command;
      std::getline(custFile, command);

      // If the command is legal...
      if (isLegalCustCmd(command, tgtDB)) {
         // Acquire info by...
         // Sample input
         // 1111 Mouse Mickey
         // Prepare variables
         int custID;
         std::string nameL;
         std::string nameF;

         // Encapsulate string in a stringstream
         std::stringstream stream(command);

         // Parse stream to variables
         stream >> custID;
         stream >> nameL;
         stream >> nameF;

         // Make a customer from variables
         Cust* newCust = new Cust(nameF, nameL, custID);

         // Send customer to the Inventory Database
         tgtDB.insertCustomer(newCust);

      } // Closing if - Legal inventory command sent

      // Otherwise, command was not legal, so do nothing
      // Repeat

   } // Closing while - All lines of input consumed
} // Closing bulkReadCust()

// (+) --------------------------------|
// #bulkReadInv(ifstream&, InvDB&)
//-------------------------------------|
// Desc:    Bulk reader of a correctly formatted inventory command file
// Params:  ifstream& arg1 - The target text file containing inventory commands
//          CustDB arg2 - The receiving Inventory database
// PreCons: A valid InvDB object must exist.
// PosCons: The ifstream has been consumed
//          All valid commands have been sent to the target InvDB
//          Does not guarantee correct handling of commands at destination DB
//          Does not handle any error reporting
// RetVal:  None
// MetCall: isLegalInvCmd() - Verifies all legality checks of the command
void bulkReadInv(std::ifstream& invFile, InvDB& tgtDB) {
   // While there is still filestream to read
   while (!invFile.eof()) {
      // Get a line of text (one command)

      std::string command;
      std::getline(invFile, command);

      // If the command is legal...
      if (isLegalInvCmd(command, tgtDB)) {

         // Send it to the Inventory Database
         tgtDB.addFilm(command);

      } // Closing if - Legal inventory command sent
   } // Closing while - All lines of input consumed
} // Closing bulkReadInv()

// (+) --------------------------------|
// #bulkReadTrans(ifstream&, CustDB&, InvDB&)
//-------------------------------------|
// Desc:    Bulk reader of a correctly formatted inventory command file
// Params:  ifstream& arg1 - The target text file containing inventory commands
//          CustDB arg2 - The receiving Inventory database
// PreCons: A valid InvDB object must exist.
// PosCons: The ifstream has been consumed
//          All valid commands have been sent to the target InvDB
//          Does not guarantee correct handling of commands at destination DB
//          Does not handle any error reporting
// RetVal:  None
// MetCall: isLegalInvCmd() - Verifies all legality checks of the command
void bulkReadTrans(std::ifstream& commandFile, CustDB& tgtCustDB, InvDB& tgtInvDB) {
   // Generate Transactions from the CommandFile and send Transaction impacts to the appropriate locations
   int counter = 1;
   while (!commandFile.eof()) {
      // Read the next relevant line of command
      std::string command;
      std::getline(commandFile, command);

      counter++;

      // I and H cases
      // If the command is an 'I'
      if (command[0] == 'I') {
         // Ping invDB for execution
         tgtInvDB.display();
         std::cout << std::endl;
      }

      // If the command is an 'H'
      else if (command[0] == 'H') {
         // Convert the command line to a string stream
         std::stringstream stream;
         stream << command;
         // Discard leading character
         char temp;
         stream >> temp;
         // Capture the int
         int custID;
         stream >> custID;
         // If the custID is out of range, halt
         if (custID < 0 || custID > 9999) {
            std::cout << "History Command error: Customer ID out of range (0-9999)" << std::endl;
         }
         // If the custDB does not have this customer...
         else if (!tgtCustDB.doesContain(custID)) {
            std::cout << "History Command error: No such Customer" << std::endl;
         }
         // Otherwise...
         else {
            // Output the history of the customer at this position
            std::cout << tgtCustDB.getCustomerAt(custID)->getHistory() << std::endl;
         }
      } // Closing if - 'H' condition handled

      else {// Prepare to hold a transaction
         Trans* currTrans = nullptr;
         // If the command is legal (based on the command and DB states)
         if (isLegalTransCmd(command, tgtCustDB, tgtInvDB)) {
            // Create a transaction from it
            currTrans = new Trans(command);
            // Aggregate inventory information from the databases to add needed info to the transaction
            padOut(currTrans, tgtInvDB);
            // currTrans->debug(); // DEBUG
            // Send the Transaction to the Databases for execution
            tgtInvDB.adjustStock(*currTrans);
            tgtCustDB.appendHistory(*currTrans);
         }
         else {
            std::cout << std::endl;
         }


         // deallocate current transaction now that it's been used
         if (currTrans != nullptr) {
            delete currTrans;
         }
         std::cout << ""; // DEBUG
      }
   } // Closing while - All lines of command read from file / filestream
   std::cout << "--- All command lines parsed ---" << std::endl << std::endl;

} // Closing bulkReadTrans()

// (+) --------------------------------|
// #isLegalCustCmd(ifstream&, CustDB&)
//-------------------------------------|
// Desc:    Verifies the legality of a customer command line
// Params:  ifstream& arg1 - The target text file containing inventory commands
//          CustDB arg2 - The database to query
// PreCons: A valid CustDB object must exist.
// PosCons: Both the CustDB and this method have examined the command for legality
//          Does not guarantee correct handling of legality at destination DB
//          All errors have been reported
// RetVal:  bool true - No illegal conditions are reported
//          bool false - At least one illegal condition was detected
// MetCall: CustDB::isValid() - Verifies all legality checks within the database
bool isLegalCustCmd(std::string command, CustDB& tgtDB) {
   // Set flag
   bool isLegal = true;
   // Begin error log
   std::string errorLog = "";

   // Initialize field variables
   int custID = 1234512345;
   std::string nameL = "";
   std::string nameF = "";

   // Parse fields
   std::stringstream stream(command);
   stream >> custID;
   stream >> nameL;
   stream >> nameF;

   // Verify that field1 is within expected value range
   if (custID == 1234512345) {
      // If not, append report
      errorLog = errorLog + "   - No customer ID entered" + "\n";
      // And toggle the flag
      isLegal = false;
   }

   // Verify that the customerID is within range
   if (custID != 1234512345 && (custID < 0 || custID > 9999)) {
      // If not, append report
      errorLog = errorLog + "   - Invalid customer ID entered (out of range)" + "\n";
      // And toggle the flag
      isLegal = false;
   }

   // Check if both the first name and last name were entered
   if (nameF == "" || nameL == "") {
      // If not, append report
      errorLog = errorLog + "   - No first or last name entered" + "\n";
      // And toggle the flag
      isLegal = false;
   }

   // Any other ways a customer command can be invalid?

   // If any test has failed, do not forward to database
   if (isLegal == false) {
      std::cout << "Customer Command error ('" << command << "'):" << std::endl;
      std::cout << errorLog << std::endl;
      return(isLegal);
   }
   // Otherwise, this is a correctly formatted command
   // But it may still be in conflict with the database state, so check that
   isLegal = tgtDB.isValid(command);
   // Note: tgtDB.isLegal() handles its own error reporting to cout
   // Return whether the database confirmed legality or not
   return(isLegal);
} // Closing isLegalCustCmd()

// (+) --------------------------------|
// #isLegalInvCmd(ifstream&, InvDB&)
//-------------------------------------|
// Desc:    Verifies the legality of an inventory command line
// Params:  ifstream& arg1 - The target text file containing inventory commands
//          InvDB arg2 - The database to query
// PreCons: A valid InvDB object must exist.
// PosCons: Both the InvDB and this method have examined the command for legality
//          Does not guarantee correct handling of legality at destination DB
//          All errors have been reported
// RetVal:  bool true - No illegal conditions are reported
//          bool false - At least one illegal condition was detected
// MetCall: InvDB::isValid() - Verifies all legality checks within the database
bool isLegalInvCmd(std::string command, InvDB& tgtDB) {
   std::string origCommand = command;
   // Set flag
   bool isLegal = true;
   // Begin error log
   std::string errorLog = "";
   int currentYear = 2018;

   // Parse command data
   std::string delim = ", ";
   std::string cmdData[5];

   // Get each term from the string
   for (int i = 0; i < 5; i++) {
      cmdData[i] = command.substr(0, command.find(delim));
      command.erase(0, command.find(delim) + delim.length());
   }

   // Test if genre is within range first
   char genre = cmdData[0][0];
   if (genre != 'C' && genre != 'F' && genre != 'D') {
      std::cout << "Inventory Command error ('" << origCommand << "'):" << std::endl;
      std::cout <<"   - Invalid genre: '" << genre << "'" << std::endl << std::endl;
      return(false);
   }

   // Verify that quantity is non-zero
   int stock = std::stoi(cmdData[1]);
   if (stock <= 0) {
      // If not, append report
      errorLog = errorLog + "   - Zero quantity (non-inventory)" + "\n";
      // And toggle the flag
      isLegal = false;
   }

   // Verify that a director is entered
   std::string director = cmdData[2];
   if (director == "") {
      // If not, append report
      errorLog = errorLog + "   - No director specified" + "\n";
      // And toggle the flag
      isLegal = false;
   }

   // Verify that a film name is entered
   std::string title = cmdData[3];
   if (title == "") {
      // If not, append report
      errorLog = errorLog + "   - No film title entered" + "\n";
      // And toggle the flag
      isLegal = false;
   }

   // In the case of classic films only, verify that an actor is specified
   if (genre == 'C') {

      // split the last two items by spaces to incorprate the major actor and date
      delim = " ";

      for (int i = 0; i < 4; i++) {
         cmdData[i] = command.substr(0, command.find(delim));
         command.erase(0, command.find(delim) + delim.length());
      }

      std::string actor = cmdData[0] + " " + cmdData[1]; // strings: firstName lastName
      int releaseMonth = std::stoi(cmdData[2]); // int
      int releaseYear = std::stoi(cmdData[3]); // int

      if (actor == "") {
         // If not, append report
         errorLog = errorLog + "   - No actor/actress specified" + "\n";
         // And toggle the flag
         isLegal = false;
      }

      // In the case of classic films only, verify that a release month is specified
      if (releaseMonth < 1 || releaseMonth > 12) {
         // If not, append report
         errorLog = errorLog + "   - Release month not properly entered" + "\n";
         // And toggle the flag
         isLegal = false;
      }
      if (releaseYear < 1880 || releaseYear > 2018) {
         // If not, append report
         errorLog = errorLog + "   - Release year not properly entered" + "\n";
         // And toggle the flag
         isLegal = false;
      }
   }
   // if this isn't a classic, check the year normally
   else {
      int releaseYear = std::stoi(cmdData[4]);
      if (releaseYear < 1880 || releaseYear > currentYear) {
         // If not, append report
         errorLog = errorLog + "   - Release year not properly entered" + "\n";
         // And toggle the flag
         isLegal = false;
      }
   }

   // If any test has failed, do not forward to database
   if (isLegal == false) {
      std::cout << "Inventory Command error ('" << origCommand << "'):" << std::endl;
      std::cout << errorLog << std::endl << std::endl;
      return(isLegal);
   }
   // Otherwise, this is a correctly formatted command
   // But it may still be in conflict with the database state, so check that
   isLegal = tgtDB.isLegal(origCommand);
   // Note: tgtDB.isLegal() handles its own error reporting to cout
   // Return whether the database confirmed legality or not
   return(isLegal);
} // Closing isLegalInvCmd()

// (+) --------------------------------|
// #trim(std::string)
//-------------------------------------|
// Desc:    Trims whitespace from the end of a string
// Params:  string by reference
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void trim(std::string& str) {
   std::string whitespaces(" \t\f\v\n\r");
   int pos = str.find_last_not_of(whitespaces);
   if (pos != std::string::npos) {
      str.erase(pos + 1);
   }
}

// (+) --------------------------------|
// #isLegalTransCmd(ifstream&, CustDB&, InvDB&)
//-------------------------------------|
// Desc:    Verifies the legality of a transaction command line
// Params:  ifstream& arg1 - The target text file containing inventory commands
//          InvDB arg2 - The customer database to query
//          InvDB arg3 - The inventory database to query
// PreCons: A valid InvDB object must exist
//          A valid CustDB object must exist
// PosCons: Both databases and this method have examined the command for legality
//          Does not guarantee correct handling of legality at destination DBs
//          All errors have been reported
// RetVal:  bool true - No illegal conditions are identified
//          bool false - At least one illegal condition was detected
// MetCall: CustDB::isValid() - Verifies all legality checks within the customer DB
//          InvDB::isValid() - Verifies all legality checks within the inventory DB
bool isLegalTransCmd(std::string command, CustDB& tgtCustDB, InvDB& tgtInvDB) {
   // Set flag
   bool isLegal = true;

   // Begin error log
   std::string errorLog = "";

   // Store command as a stream
   std::stringstream stream;
   stream << command;
   trim(command);

   int currentYear = 2018;

   // Initialize field variables
   char commandType     = ' ';
   int custID           = 1234512345;
   char format          = 'D'; // 'D' for DVD on all titles
   char genre           = ' ';
   int releaseMonth     = 0; // (in case of Classic)
   int releaseYear      = 0;
   std::string director = "";
   std::string title    = "";
   std::string actor    = ""; // (in case of Classic)

   // Sample input: B 1000 D D Barry Levinson, Good Morning Vietnam,
   // Parse command type off string
   stream >> commandType;

   // Test if the commandType is within range first
   if ((commandType != 'I') && (commandType != 'H') && (commandType != 'B') && (commandType != 'R')) {

      std::cout << "Transaction Command error ('" << command << "'):" << std::endl;

      std::cout << "   - Invalid command type: ('" << commandType << "'), discarding..." << std::endl;
      return(false);
   }

   // Finish testing for an 'I' (inventory query) command
   if (commandType == 'I' && command.size() > 2) { // If there's anything after the I...
      std::cout << "Transaction Command error ('" << command << "'):" << std::endl;
      std::cout << "   - Invalid length of 'I' (inventory) command, halting." << std::endl;
      std::cout << "Command length: " << command.size() << std::endl;
      return(false);
   }

   // All legality checks for an 'I' command complete, so exit
   if (commandType == 'I') {
      return(isLegal);
   }

   // Parse customerID
   stream >> custID; // VERIFIED
   // std::cout << custID << "!!!";

   // Test if customerID is within range
   if (custID < 0 || custID > 9999) {
      // Append the error log
      errorLog = errorLog + "   - Customer ID out of range" + "\n";
      // And toggle the flag
      isLegal = false;
   }

   // Test if customer is in the database
   if (!tgtCustDB.doesContain(custID)) {
      // Append the error log
      errorLog = errorLog + "   - Non-existant customer";
      // And toggle the flag
      isLegal = false;
   }

   // Parse format
   stream >> format; // VERIFIED
   // std::cout << format << "!!!";

   // Test if format is within range
   if (format != 'D') {
      // Append the error log
      errorLog = errorLog + "   - Invalid media format.";
      // And toggle the flag
      isLegal = false;
   }

   // Sample input: B 1000 D D Barry Levinson, Good Morning Vietnam,
   // Parse genre
   stream >> genre; // VERIFIED
   // std::cout << "'" << genre << "' !!!";

   // Test if genre is within range
   if ((genre != 'C') && (genre != 'F') && (genre != 'D')) {
      std::cout << "Transaction Command error ('" << command << "'):" << std::endl;
      std::cout << "   - Invalid genre, halting." << std::endl;
      std::cout << errorLog;
      return(false);
   }

   // CLASSIC BEHAVIOR
   if (genre == 'C') {
      // Parse releaseMonth
      stream >> releaseMonth; // VERIFIED
      // Parse releaseYear
      stream >> releaseYear; // VERIFIED
      // Parse actor
      char temp = ' ';
      stream >> temp;
      stream << std::noskipws;
      while (!stream.eof()) {
         actor += temp;
         stream >> temp;
      }
      trim(actor);
      // Actor parsed - VERIFIED

      // std::cout << "(CisLegalCmd):" << actor << ":" << releaseMonth << ":" << releaseYear << ")"; // DEBUG

      // Information in hand, perform all legality checks for Classics

      // Verify that releaseMonth is within range
      if ((releaseMonth < 1) || (releaseMonth > 12)) {
         // Append the error log
         errorLog = errorLog + "   - Invalid month (out of range)" + "\n";
         // And toggle the flag
         isLegal = false;
      }
      // Verify that releaseYear is within range
      if ((releaseYear < 1888) || (releaseYear > currentYear)) {
         // Append the error log
         errorLog = errorLog + "   - Invalid year (out of range)" + "\n";
         // And toggle the flag
         isLegal = false;
      }
      // Verify that an actor is provided
      if (actor == "") {
         // Append the error log
         errorLog = errorLog + "   - No actor provided" + "\n";
         // And toggle the flag
         isLegal = false;
      }


      if (isLegal) {
         // NOTE!!! CLASSIC BEHAVIOR MUST GO TO THE INVDB AND ATTEMPT TO RETRIEVE A TITLE AT THIS POINT
         // Not necessary if any tests were failed here, as the legality calls will terminate
         title = tgtInvDB.getCTitleByTuple(releaseMonth, releaseYear, actor);

         // if this is a Return, check if this customer has 
         // this film currently checked out
         if (commandType == 'R' 
             && !tgtCustDB.getCustomerAt(custID)->isCheckedOut(title)) {
            // Append the error log
            errorLog = errorLog + "   - Customer has not borrowed this film" + "\n";
            // And toggle the flag
            isLegal = false;
         }
      }
   } // Classic legality tests complete


   // DRAMA BEHAVIOR
   if (genre == 'D') {

      // Sample input: B 1000 D D Gus Van Sant, Good Will Hunting,
      // Parse director
      char temp = ' ';
      stream >> temp;
      stream << std::noskipws;
      while (temp != ',') {
         director += temp;
         stream >> temp;
      } // Director parsed

      // Advance
      stream >> temp;
      stream >> temp;
      // Parse title
      while (temp != ',') {
         title += temp;
         stream >> temp;
      } // Title parsed

      if (title == "") {
         // Append the error log
         errorLog = errorLog + "   - No title provided" + "\n";
         // And toggle the flag
         isLegal = false;
      }
      else {
         // if this is a Return, check if this customer has 
         // this film currently checked out
         if (commandType == 'R' 
             && !tgtCustDB.getCustomerAt(custID)->isCheckedOut(title)) {
            // Append the error log
            errorLog = errorLog + "   - Customer has not borrowed this film" + "\n";
            // And toggle the flag
            isLegal = false;
         }
      }

      // Information in hand, perform legality checks for Dramas
      // Verify that a director is provided
      if (director == "") {
         // Append the error log
         errorLog = errorLog + "   - No director provided" + "\n";
         // And toggle the flag
         isLegal = false;
      }
   }

   // COMEDY BEHAVIOR
   if (genre == 'F') {
      // Parse title

      char temp = ' ';
      stream >> temp;
      stream << std::noskipws;
      while (temp != ',') {
         title += temp;
         stream >> temp;
      } // Title parsed

      stream >> temp;

      // Parse releaseYear
      stream >> releaseYear;

      // std::cout << "(" << title << ":" << releaseYear << ")"; // DEBUG

      // Verify that a title is provided
      if (title == "") {
         // Append the error log
         errorLog = errorLog + "   - No title provided" + "\n";
         // And toggle the flag
         isLegal = false;
      }
      else {
         // if this is a Return, check if this customer has 
         // this film currently checked out
         if (commandType == 'R' 
             && !tgtCustDB.getCustomerAt(custID)->isCheckedOut(title)) {
            // Append the error log
            errorLog = errorLog + "   - Customer has not borrowed this film" + "\n";
            // And toggle the flag
            isLegal = false;
         }
      }

      // Verify that releaseYear is within range
      if ((releaseYear < 1888) || (releaseYear > currentYear)) {
         // Append the error log
         errorLog = errorLog + "   - Invalid year (out of range)" + "\n";
         // And toggle the flag
         isLegal = false;
      }
   } // Closing Comedy behavior

   // If any test has failed, do not forward to database
   if (isLegal == false) {
      std::cout << "Transaction Command error ('" << command << "'):" << std::endl;
      std::cout << errorLog << std::endl;
      return(isLegal);
   }
   // Otherwise, this is a correctly formatted command
   // But it may still be in conflict with the database states, so check those
   if (!tgtCustDB.isValidTransCmd(custID, title, commandType) || !tgtInvDB.isValidTransCmd(command)) {
      isLegal = false;
   }
   // Note: Target databases handle their own error reporting to cout
   // Return whether the database confirmed legality or not
   return(isLegal);
} // Closing isLegalTransCmd()

// (+) --------------------------------|
// #padOut(ifstream&, InvDB&)
//-------------------------------------|
// Desc:    Acquires and appends missing information for a transaction
// Params:  transPtr* arg1 - 
//          InvDB arg2 - 
// PreCons: A valid InvDB object must exist
//          A valid transaction constructed from a legal command must exist
// PosCons: Sufficient data has been appended to the transaction to allow for proper output
// RetVal:  None
// MetCall: NULL
void padOut(Trans* transPtr, InvDB& tgtInvDB) {
   // Sample inputs:
   // B 4444 D C 2 1971 Malcolm McDowell
   // B 1000 D D Gus Van Sant, Good Will Hunting,
   // B 8000 D F You've Got Mail, 1998

   // Fields needed:
   // TYPESTRING - Got it
   // GENRESTRING - Got it
   // TITLE - Classics only
   // RELEASEMONTH - Got it, if applicable
   // RELEASEYEAR - Dramas only

   // Classics
   if (transPtr->getGenre() == 'C') {
      // TITLE -  Get the film title out of the InvDB based on director/title
      std::string title = tgtInvDB.getCTitleByTuple(transPtr->getReleaseMonth(), transPtr->getReleaseYear(), transPtr->getActor());
      transPtr->setTitle(title);
   }

   // Drama
   if (transPtr->getGenre() == 'D') {
      // RELEASEYEAR -  Get the release date out of the InvDB based on director/title
      int year = tgtInvDB.getDYearByTuple(transPtr->getDirector(), transPtr->getTitle());
      transPtr->setReleaseYear(year);
   }

   // Transaction holds sufficient data for CustDB to process
}

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of file - driver.cpp
