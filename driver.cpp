/**
 * CSS502 Assignment 4: Matt Gross & Tim Lum - Group 7
 * File: Inventory Controller
 * Description: Holds the core business logic to manage two inventory databases
 * and process a list of transactions
**/

// Necessary for file stream object handling
#include <fstream>

// Necessary for input-output stream operations
#include <iostream>

// Necessary for string operations
#include <string>

// Necessary for database objects
#include "Inv/InvDB.h"
// #include "CustDB.h"

// Necessary for transaction objects
#include "Trans/Trans.h"
#include "Trans/Borrow.h"
#include "Trans/Return.h"

// Necessary for film objects
#include "Inv/Film.h"
#include "Inv/Comedy.h"
#include "Inv/Drama.h"
#include "Inv/Classic.h"

// For testing purposes
#include "Cust/Cust.h"
#include "Cust/CustDB.h"



int main() {

// Begin program

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       START CUSTOMER DATABASE TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   std::cout << "--- START CUSTOMER DATABASE TESTS ---" << std::endl << std::endl;

   // Instantitate a new customer database
   std::cout << "Creating a default CustDB..." << std::endl << std::endl;
   CustDB testCustDB = CustDB();

   std::cout << "Creating a transaction from string 'B 1111 D F Ferries and You: A Primer, 2018'..." << std::endl << std::endl;
   Trans testTransaction = Trans("B 1111 D F Ferries and You: A Primer, 2018");

   // Create two new customers
   std::cout << "Creating two new customers..." << std::endl << std::endl;
   // 1111 Jane Doe
   Cust* testCustomer1 = new Cust("Jane", "Doe", 1111);
   // 9000 Boaty McBoatface
   Cust* testCustomer2 = new Cust("Boaty", "McBoatface", 9000);

   // Check customer instantiation
   std::cout << "Customer 1 & 2 constructor results:" << std::endl;
   std::cout << testCustomer1->toString() << std::endl;
   std::cout << testCustomer2->toString() << std::endl;
   std::cout << std::endl;

   // Check the history of customer 1
   std::cout << "Checking history of customer 1:" << std::endl;
   std::cout << testCustomer1->getHistory() << std::endl << std::endl;

   // Attempt to append history to customer 1
   std::cout << "Testing appendHistory(string)..." << std::endl << std::endl;
   testCustomer1->appendHistory(testTransaction.toString());

   // Check the history of customer 1 again
   std::cout << "Checking the history of customer 1 after append:" << std::endl;
   std::cout << testCustomer1->getHistory() << std::endl;

   // Attempt to insert customers to database
   std::cout << "Inserting customers 1 and 2 to database..." << std::endl << std::endl;
   testCustDB.insertCustomer(testCustomer1);
   testCustDB.insertCustomer(testCustomer2);

   // Check insertion
   std::cout << "Checking insertion results:" << std::endl;
   std::cout << testCustDB.toString() << std::endl << std::endl;

   std::cout << "--- END CUSTOMER DATABASE TESTS ---" << std::endl << std::endl;

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       END CUSTOMER DATABASE TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       INV DATABASE TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   std::cout << "--- START INVENTORY DATABASE TESTS ---" << std::endl << std::endl;

   // Create a new inventory database object
   std::ifstream inventoryFile("data4movies.txt");
   InvDB invDB(inventoryFile);

   // Create three new films
   Film filmAA("C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939");
   Film filmBB("F, 10, Nora Ephron, Sleepless in Seattle, 1993");
   Film filmCC("D, 10, Jonathan Demme, Silence of the Lambs, 1991");

   // Attempt to add these films to the inventory database
   invDB.addFilm(*filmAA);
   invDB.addFilm(*filmBB);
   invDB.addFilm(*filmCC);

   // Query quantities of each film

   // Create borrow transactions
   // Trans BTestC = Trans("B <ID> C <TITLE>, <RELEASE>");
   // Trans BTestD = Trans("B <ID> D <TITLE>, <RELEASE>");
   // Trans BTestF = Trans("B <ID> F <TITLE>, <RELEASE>");

   // // Create return transactions
   // Trans RTestC = Trans("R <ID> C <TITLE>, <RELEASE>");
   // Trans RTestD = Trans("R <ID> D <TITLE>, <RELEASE>");
   // Trans RTestF = Trans("R <ID> F <TITLE>, <RELEASE>");

   // Send a transaction

   // Query film states again

   std::cout << "--- END INVENTORY DATABASE TESTS ---" << std::endl << std::endl;






   // Acquire the relevant files

   std::ifstream commandFile("data4commands.txt");
   // std::ifstream customerFile("data4customers.txt");




   // Generate Transactions from the CommandFile and send Transaction impacts to the appropriate locations
   while (!commandFile.eof()) {
      // Read the next relevant line of command
      std::string command;
      std::getline(commandFile, command);

      // create a transaction and check for transaction legality
      Trans* currTrans = nullptr;

      // make sure the line contains data
      if (command.length() >= 1) {

         // call the factory method to determine type of transaction
         currTrans = currTrans->factory(command);
      }

      // Queries isLegal() in Transactions, invDB, and custDB
      if (invDB.isLegal(command) /* && custDB.isLegal(command)*/ ) {

         // Send the Transaction to the Databases for execution
         invDB.adjustStock(currTrans);
         // custDB.appendHistory(currTrans);
      }

      // deallocate current transaction now that it's been used
      if (currTrans != nullptr) {
         delete currTrans;
      }
   }





//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       FILM CLASS TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   std::cerr << "--- BEGIN FILM CLASS TESTS ---" << std::endl;

   // default constructor
   Film filmA;

   filmA.setTitle("Testing Film");
   filmA.setStock(20);
   filmA.setReleaseDate(1995);
   filmA.setGenre('X');
   filmA.setDirector("Antonio Testing");
   filmA.appendActor("Bob Benson");

   std::cerr << filmA.getTitle() << std::endl;
   std::cerr << filmA.getStock() << std::endl;
   std::cerr << filmA.getReleaseDate() << std::endl;
   std::cerr << filmA.getGenre() << std::endl;
   std::cerr << filmA.getDirector() << std::endl;

   // string constructor
   Film filmB("D, 10, Jonathan Demme, Silence of the Lambs, 1991");

   std::cerr << filmB.getTitle() << std::endl;
   std::cerr << filmB.getStock() << std::endl;
   std::cerr << filmB.getReleaseDate() << std::endl;
   std::cerr << filmB.getGenre() << std::endl;
   std::cerr << filmB.getDirector() << std::endl;

   // operators
   std::cerr << "FilmA == FilmB: " << (filmA == filmB) << std::endl;
   std::cerr << "FilmA >= FilmB: " << (filmA >= filmB) << std::endl;
   std::cerr << "FilmA <= FilmB: " << (filmA <= filmB) << std::endl;


   Film filmC("D, 100, Jonathan Demme, Silence of the Lambs, 1991");
   std::cerr << "FilmA == FilmB: " << (filmC == filmB) << std::endl;
   std::cerr << "FilmA >= FilmB: " << (filmC >= filmB) << std::endl;
   std::cerr << "FilmA <= FilmB: " << (filmC <= filmB) << std::endl;

   std::cerr << "filmA contains actor: Bob Benson: ";
   std::cerr << filmA.hasActor("Bob Benson") << std::endl;

   std::cerr << "filmA contains actor: Bob Johnson: ";
   std::cerr << filmA.hasActor("Bob Johnson") << std::endl;

   std::cerr << "--- END FILM CLASS TESTS ---" << std::endl;




   return (0);
} // End program
