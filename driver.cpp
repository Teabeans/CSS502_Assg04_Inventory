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

void readInv(std::ifstream& data, InvDB& invDB) {

   int filmID = 0;
   while (!data.eof()) {
      // Read the next relevant line of command
      std::string filmData;
      std::getline(data, filmData);

      if (filmData.length() >= 1) {
         // create borrow object and run transaction
         if (filmData.at(0) == 'F') {
            invDB.addFilm(new Comedy(filmData));
         }

         // create return object and run transaction
         else if (filmData.at(0) == 'D') {
            invDB.addFilm(new Drama(filmData));
         }

         // check customer and display history
         else if (filmData.at(0) == 'C') {
            invDB.addFilm(new Classic(filmData));
         }

         // otherwise, this is an invalid film type
         else {
            std::cerr << "Invalid film type: " << filmData.at(0) << std::endl;
         }
      }
   }
} // End readInv

// void readCust(std::ifstream& dataFile) {

// }

// int estimate(std::ifstream& dataFile){
//    int retEstimate = 0;
//    // for (;;) {
//    //    // Exit condition
//    //    if (dataFile.eof()) {
//    //       break;
//    //    }
//    //    //Otherwise, just keep drawing lines
//    //    // TODO
//    //    retEstimate++;
//    // }
//    // retEstimate = retEstimate*2;
//    // Now compare against the list of primes until the prime exceeds retEstimate
//    // TODO
//    // Assign this prime to retEstimate
//    // TODO
//    return(10067);
//    // 2x the number of newline characters
//    // Just make a list of prime numbers
// } // Closing estimate()

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
   
   // Acquire the relevant files

   std::ifstream commandFile("data4commands.txt");
   // std::ifstream customerFile("data4customers.txt");
   std::ifstream inventoryFile("data4movies.txt");
   // std::ifstream sacrificialFile("data4movies.txt");

   // Determine the size of the inventory
   // int entries = estimate(sacrificialFile);

   // Create an InventoryDatabase of size 'entries'
   InvDB invDB(10067);

   // Create a CustomerDatabase of size 10000
   // CustDB custDB(10000);

   // Load the InventoryDatabase using the InventoryFile
   readInv(inventoryFile, invDB);

   // Load the CustomerDatabase using the CustomerFile
   // readCust(customerFile);


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

   return (0);
} // End program
