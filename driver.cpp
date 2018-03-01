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
#include "InvDB.h"
#include "CustDB.h"

// Necessary for transaction objects
#include "Borrow.h"
#include "Return.h"

#include "Parent.h"
#include "Child.h"

void readInv(std::ifstream& dataFile) {

}

void readCust(std::ifstream& dataFile) {

}

int estimate(std::ifstream& dataFile){
   int retEstimate = 0;
   for (;;) {
      // Exit condition
      if (dataFile.eof()) {
         break;
      }
      //Otherwise, just keep drawing lines
      // TODO
      retEstimate++;
   }
   retEstimate = retEstimate*2;
   // Now compare against the list of primes until the prime exceeds retEstimate
   // TODO
   // Assign this prime to retEstimate
   // TODO
   return(10067);
   // 2x the number of newline characters
   // Just make a list of prime numbers
} // Closing estimate()

int main() {
   std::cout << "Hello, World!" << std::endl;
   Parent someParent;
   Child someChild;
   std::cout << "Parent tests:" << std::endl;
   std::cout << someParent.toString() << std::endl;
   std::cout << someParent.toStringParent() << std::endl;
   std::cout << std::endl;
   std::cout << "Child tests:" << std::endl;
   std::cout << someChild.toString() << std::endl;
   std::cout << someChild.toStringParent() << std::endl;

// Begin program
   // Acquire the relevant files

   std::ifstream commandFile("data4commands.txt");
   std::ifstream customerFile("data4customers.txt");
   std::ifstream inventoryFile("data4movies.txt");
   std::ifstream sacrificialFile("data4movies.txt");

   // Determine the size of the inventory
   int entries = estimate(sacrificialFile);

   // Create an InventoryDatabase of size 'entries'
   InvDB invDB(entries);

   // Create a CustomerDatabase of size 10000
   CustDB custDB(10000);

   // Load the InventoryDatabase using the InventoryFile
   readInv(inventoryFile);

   // Load the CustomerDatabase using the CustomerFile
   readCust(customerFile);


   // Generate Transactions from the CommandFile and send Transaction impacts to the appropriate locations
   while (!commandFile.eof()) {
      // Read the next relevant line of command
      std::string command;
      std::getline(commandFile, command);


      // create a transaction and check for transaction legality
      Trans* currTrans;

      // create borrow object and run transaction
      if (command.at(0) == 'B') {
         currTrans = new Borrow(command);
      }

      // create return object and run transaction
      else if (command.at(0) == 'R') {
         currTrans = new Return(command);
      }

      // check customer and display history
      else if (command.at(0) == 'H') {
         // TODO check whether customer is valid
         // TODO output customer history
      }

      // otherwise, this is an invalid command
      else {
         cerr << "Error, invalid command: " << command.at(0) << endl;
      }

      // Queries isLegal() in Transactions, invDB, and custDB
      if (invDB.isLegal(command) && custDB.isLegal(command) {

         // Send the Transaction to the Databases for execution
         invDB.adjustStock(currTrans);
         custDB.appendHistory(currTrans);
      }

      // deallocate current transaction now that it's been used
      delete currTrans;
   }

// End program

   return (0);
}

