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
// Modified: 2018.03.--
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
void bulkReadCust(std::ifstream& custtxt, CustDB tgtDB);

// Bulk reader - Inventory
void bulkReadInv(std::ifstream& invtxt, InvDB tgtDB);

// Bulk reader - Transactions
void bulkReadTrans(std::ifstream& transtxt, CustDB tgtCustDB, InvDB tgtInvDB);

// Legality check - Customer commands
bool isLegalCustCmd(std::string command, CustDB tgtDB);

// Legality check - Inventory commands
bool isLegalInvCmd(std::string command, InvDB tgtDB);

// Legality check - Transaction commands
bool isLegalTransCmd(std::string command, CustDB tgtDB, InvDB tgtInvDB);

// Appends missing information to a transaction
void padOut(Trans* transPtr, InvDB tgtInvDB);


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       MAIN()
//
//-------|---------|---------|---------|---------|---------|---------|---------|

int main() {



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       TRANS CLASS TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (false) {

      std::cout << "--- (1.0) BEGIN FILM CLASS TESTS ---" << std::endl << std::endl;

      std::cout << "--- (1.1) Creating a default Transaction... ---" << std::endl << std::endl;
      Trans testTrans;

      std::cout << "--- (1.2) Test of Trans::debug() and Trans::toString(): ---" << std::endl << std::endl;
      std::cout << "toString(): " << testTrans.toString() << std::endl;
      std::cout << "debug():" << std::endl;
      testTrans.debug();

      std::cout << "--- (1.3) Partially create a Drama transaction by string... ---" << std::endl << std::endl;
      Trans testTrans2("B 1111 D D Phillippe De Broca, King of Hearts,");
      std::cout << "toString(): " << testTrans2.toString() << std::endl;
      std::cout << "debug():" << std::endl;
      testTrans2.debug();

      std::cout << "--- (1.4) Partially create a Comedy transaction by string... ---" << std::endl << std::endl;
      Trans testTrans3("R 2222 D F You've Got Mail, 1998");
      std::cout << "toString(): " << testTrans3.toString() << std::endl;
      std::cout << "debug():" << std::endl;
      testTrans3.debug();

      std::cout << "--- (1.5) Partially create a Classic transaction by string... ---" << std::endl << std::endl;
      Trans testTrans4("B 3333 D C 3 1971 Ruth Gordon");
      std::cout << "toString(): " << testTrans4.toString() << std::endl;
      std::cout << "debug():" << std::endl;
      testTrans4.debug();

      std::cout << "--- (1.6) Append title to transaction: ---" << std::endl << std::endl;
      testTrans4.setTitle("<Title pulled from database>");
      std::cout << "toString(): " << testTrans4.toString() << std::endl;
      std::cout << "debug():" << std::endl;
      testTrans4.debug();

      std::cout << "--- (1.7) Append year to transaction: ---" << std::endl << std::endl;
      testTrans2.setReleaseYear(2000);
      std::cout << "toString(): " << testTrans4.toString() << std::endl;
      std::cout << "debug():" << std::endl;
      testTrans4.debug();

      std::cout << "--- (1.8) Final transaction states: ---" << std::endl << std::endl;
      std::cout << testTrans4.toString() << std::endl;
      std::cout << testTrans2.toString() << std::endl;
      std::cout << testTrans3.toString() << std::endl;
      std::cout << std::endl;

      std::cout << "--- END FILM CLASS TESTS ---" << std::endl << std::endl;

   } // END TRANS CLASS TESTS

   
   
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       FILM CLASS TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (false) {

      std::cout << "--- (2.0) BEGIN FILM CLASS TESTS ---" << std::endl << std::endl;

      std::cout << "--- (2.1) Creating a default Film... ---" << std::endl << std::endl;
      // default constructor
      Film filmA;

      std::cout << "--- (2.2) Test of Film Setters/Getters... ---" << std::endl << std::endl;

      filmA.setTitle("Testing Film");
      filmA.setStock(20);
      filmA.setReleaseYear(1995);
      filmA.setGenre('X');
      filmA.setDirector("Antonio Testing");
      filmA.setActor("Bob Benson");

      std::cout << "Title:       " << filmA.getTitle() << std::endl;
      std::cout << "Stock:       " << filmA.getStock() << std::endl;
      std::cout << "ReleaseYear: " << filmA.getReleaseYear() << std::endl;
      std::cout << "Genre:       " << filmA.getGenre() << std::endl;
      std::cout << "Director:    " << filmA.getDirector() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (2.3) Creating a Film from string ('D, 10, Jonathan Demme, Silence of the Lambs, 1991')... ---" << std::endl << std::endl;
      // string constructor
      Film filmB("D, 10, Jonathan Demme, Silence of the Lambs, 1991");

      std::cout << "Title:       " << filmB.getTitle() << std::endl;
      std::cout << "Stock:       " << filmB.getStock() << std::endl;
      std::cout << "ReleaseYear: " << filmB.getReleaseYear() << std::endl;
      std::cout << "Genre:       " << filmB.getGenre() << std::endl;
      std::cout << "Director:    " << filmB.getDirector() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (2.4) Test of Film comparison operators (by title, then year) ---" << std::endl << std::endl;
      // operators
      std::cout << "(" << filmA.getTitle() << ":" << filmA.getReleaseYear() << ") vs (" << filmB.getTitle() << ":" << filmB.getReleaseYear() << ")" << std::endl;
      std::cout << "FilmA == FilmB: " << (filmA == filmB) << " (0 expected)" << std::endl;
      std::cout << "FilmA >  FilmB: " << (filmA >  filmB) << " (1 expected)" << std::endl;
      std::cout << "FilmA <  FilmB: " << (filmA <  filmB) << " (0 expected)" << std::endl;
      std::cout << std::endl;

      std::cout << "--- (2.5) Test of Film comparison operators (by title, then year) ---" << std::endl << std::endl;

      Film filmC("D, 100, Jonathan Demme, Silence of the Lambs, 1991");
      std::cout << "(" << filmC.getTitle() << ":" << filmC.getReleaseYear() << ") vs (" << filmB.getTitle() << ":" << filmB.getReleaseYear() << ")" << std::endl;
      std::cout << "FilmC == FilmB: " << (filmC == filmB) <<  " (1 expected)" << std::endl;
      std::cout << "FilmC >  FilmB: " << (filmC >  filmB) <<  " (0 expected)" << std::endl;
      std::cout << "FilmC <  FilmB: " << (filmC <  filmB) <<  " (0 expected)" << std::endl;
      
      std::cout << std::endl;

      std::cout << "--- END FILM CLASS TESTS ---" << std::endl << std::endl;

   } // END FILM CLASS TESTS

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CLASSIC FILM SUBCLASS TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (true) {
      std::cout << "--- (3.0) BEGIN CLASSIC FILM CLASS TESTS ---" << std::endl << std::endl;

      std::cout << "--- (3.1) Creating a Classic Film by string ('C, 10, Michael Curtiz, Casablanca, Langrid Bergman 11 1942') ---" << std::endl << std::endl;
      Film* cTestFilm1 = new Classic("C, 10, Michael Curtiz, Casablanca, Langrid Bergman 11 1942");
      std::cout << "Title:        " << cTestFilm1->getTitle() << std::endl;
      std::cout << "Stock:        " << cTestFilm1->getStock() << std::endl;
      std::cout << "ReleaseMonth: " << cTestFilm1->getReleaseMonth() << std::endl;
      std::cout << "ReleaseYear:  " << cTestFilm1->getReleaseYear() << std::endl;
      std::cout << "Genre:        " << cTestFilm1->getGenre() << std::endl;
      std::cout << "Director:     " << cTestFilm1->getDirector() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (3.2) Creating a Classic Film by string ('C, 10, Michael Curtiz, Casablanca, Bonna Beed 11 1942') ---" << std::endl << std::endl;

      Film* cTestFilm2 = new Classic("C, 10, Michael Curtiz, Casablanca, Bonna Beed 11 1942");
      std::cout << "Title:        " << cTestFilm2->getTitle() << std::endl;
      std::cout << "Stock:        " << cTestFilm2->getStock() << std::endl;
      std::cout << "ReleaseMonth: " << cTestFilm2->getReleaseMonth() << std::endl;
      std::cout << "ReleaseYear:  " << cTestFilm2->getReleaseYear() << std::endl;
      std::cout << "Genre:        " << cTestFilm2->getGenre() << std::endl;
      std::cout << "Director:     " << cTestFilm2->getDirector() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (3.3) Test of Classic Film comparison operators (by year, then month, then actor) ---" << std::endl << std::endl;

      std::cout << "(" << cTestFilm1->getReleaseYear() << ":" << cTestFilm1->getReleaseMonth() << ":" << cTestFilm1->getActor() <<
              ") vs (" << cTestFilm2->getReleaseYear() << ":" << cTestFilm2->getReleaseMonth() << ":" << cTestFilm2->getActor() <<
              ")" << std::endl;
      std::cout << "CFilm1 == CFilm2: " << (*cTestFilm1 == *cTestFilm2) <<  " (0 expected)" << std::endl;
      std::cout << "CFilm1 >  CFilm2: " << (*cTestFilm1 >  *cTestFilm2) <<  " (0 expected)" << std::endl;
      std::cout << "CFilm1 <  CFilm2: " << (*cTestFilm1 <  *cTestFilm2) <<  " (1 expected)" << std::endl;
      std::cout << std::endl;

      std::cout << "--- (3.4) Creating a Classic Film by string ('C, 10, Michael Curtiz, Casablanca, Dangrid Bergman 8 1942') ---" << std::endl << std::endl;
      Film* cTestFilm3 = new Classic("C, 10, Michael Curtiz, Casablanca, Dangrid Bergman 8 1942");

      std::cout << "--- (3.5) Creating a Classic Film by string ('C, 10, Michael Curtiz, Casablanca, Bonna Beed 8 1942') ---" << std::endl << std::endl;
      Film* cTestFilm4 = new Classic("C, 10, Michael Curtiz, Casablanca, Bonna Beed 8 1942");

      std::cout << "--- (3.6) Creating a Classic Film by string ('C, 10, Michael Curtiz, Casablanca, Cangrid Bergman 11 1940') ---" << std::endl << std::endl;
      Film* cTestFilm5 = new Classic("C, 10, Michael Curtiz, Casablanca, Cangrid Bergman 11 1940");

      std::cout << "--- (3.7) Creating a Classic Film by string ('C, 10, Michael Curtiz, Casablanca, Bonna Beed 11 1940') ---" << std::endl << std::endl;
      Film* cTestFilm6 = new Classic("C, 10, Michael Curtiz, Casablanca, Bonna Beed 11 1940");

      std::cout << "--- (3.8) Test of Classic Film comparison operators (by year, then month, then actor) ---" << std::endl << std::endl;

      std::cout << "CFilm6 <  CFilm5: " << (*cTestFilm6 <  *cTestFilm5) <<  " (1 expected - Year==, Month==, 'Bonna' < 'Cangrid')" << std::endl;
      std::cout << "CFilm5 <  CFilm4: " << (*cTestFilm5 <  *cTestFilm4) <<  " (1 expected - 1940 < 1942)" << std::endl;
      std::cout << "CFilm4 <  CFilm3: " << (*cTestFilm4 <  *cTestFilm3) <<  " (1 expected - Year==, Month==, 'Bonna' < 'Dangrid')" << std::endl;
      std::cout << "CFilm3 <  CFilm2: " << (*cTestFilm3 <  *cTestFilm2) <<  " (1 expected - Year==, 8 < 11)" << std::endl;
      std::cout << "CFilm2 <  CFilm1: " << (*cTestFilm2 <  *cTestFilm1) <<  " (1 expected - Year==, Month==, 'Bonna' < 'Langrid')" << std::endl;
      std::cout << "CFilm1 <  CFilm6: " << (*cTestFilm1 <  *cTestFilm6) <<  " (0 expected - 1940 !< 1942)" << std::endl;
      std::cout << std::endl;

      delete cTestFilm1;
      delete cTestFilm2;
      delete cTestFilm3;
      delete cTestFilm4;
      delete cTestFilm5;
      delete cTestFilm6;

      std::cout << "--- (3.9) Test of Classic Film factory construction ---" << std::endl << std::endl;

      // TODO: High chance of memory leak in this area of code
      Film* cTestFilm7 = nullptr;
      cTestFilm7 = cTestFilm7->makeFilm("C, 10, Michael Curtiz, Casablanca, Bonna Beed 11 1940");
      std::cout << "Title:        " << cTestFilm7->getTitle() << std::endl;
      std::cout << "Stock:        " << cTestFilm7->getStock() << std::endl;
      std::cout << "ReleaseMonth: " << cTestFilm7->getReleaseMonth() << std::endl;
      std::cout << "ReleaseYear:  " << cTestFilm7->getReleaseYear() << std::endl;
      std::cout << "Genre:        " << cTestFilm7->getGenre() << std::endl;
      std::cout << "Director:     " << cTestFilm7->getDirector() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (3.10) Test of factory-built method calls ---" << std::endl << std::endl;

      std::cout << "CFilm7 == CFilm7: " << (*cTestFilm7 ==  *cTestFilm7) <<  " (1 expected - should utilize Classic::operator==() )" << std::endl;

      delete cTestFilm7;

      std::cout << std::endl;

      std::cout << std::endl;

      std::cout << "--- END CLASSIC FILM CLASS TESTS ---" << std::endl << std::endl;
   } // END CLASSIC FILM SUBCLASS TESTS


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       DRAMA FILM SUBCLASS TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (true) {
      std::cout << "--- (4.0) BEGIN DRAMA FILM CLASS TESTS ---" << std::endl << std::endl;
   } // END DRAMA FILM SUBCLASS TESTS



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       COMEDY FILM SUBCLASS TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (true) {
      std::cout << "--- (5.0) BEGIN COMEDY FILM CLASS TESTS ---" << std::endl << std::endl;
   } // END COMEDY FILM SUBCLASS TESTS



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CUSTOMER DATABASE TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (false) {

      std::cout << "--- START CUSTOMER DATABASE TESTS ---" << std::endl << std::endl;

      // Instantitate a new customer database
      std::cout << "--- Creating a default CustDB... ---" << std::endl << std::endl;
      CustDB testCustDB = CustDB();

      std::cout << "--- Creating a transaction from string 'B 1111 D F Ferries and You: A Primer, 2018'... ---" << std::endl << std::endl;
      Trans testBorrow = Trans("B 1111 D F Ferries and You: A Primer, 2018");
      Trans testReturn = Trans("R 1111 D F Ferries and You: A Primer, 2018");

      // Create two new customers
      std::cout << "--- Creating two new customers... ---" << std::endl << std::endl;
      // 1111 Jane Doe
      // 9000 Boaty McBoatface
      Cust* testCustomer1 = new Cust("Jane", "Doe", 1111);
      Cust* testCustomer2 = new Cust("Boaty", "McBoatface", 9000);

      // Check customer instantiation
      std::cout << "--- Customer 1 & 2 constructor results: ---" << std::endl;
      std::cout << testCustomer1->toString() << std::endl;
      std::cout << testCustomer2->toString() << std::endl;
      std::cout << std::endl;

      // Attempt to process Borrow on Cust1
      std::cout << "--- Testing appendHistory(string)... ---" << std::endl << std::endl;
      testCustomer1->appendHistory(testBorrow.toString(), testBorrow.getType(), testBorrow.getTitle());
      std::cout << "testBorrow.toString(): " << testBorrow.toString() << std::endl;
      std::cout << "testBorrow.getType() : " << testBorrow.getType() << std::endl;
      std::cout << "testBorrow.getTitle(): " << testBorrow.getTitle() << std::endl;
      std::cout << std::endl;

      // Check the history of Cust1 again
      std::cout << "--- Checking the history of Cust1 after appendHistory(): ---" << std::endl;
      std::cout << testCustomer1->getHistory() << std::endl;

      // Check the outstanding rentals of customer 1
      std::cout << "--- Test if Cust1 has a copy of 'Ferries and You: A Primer': ---" << std::endl;
      std::cout << testCustomer1->isCheckedOut("Ferries and You: A Primer") << " ('1' expected)" << std::endl << std::endl;

      std::cout << "--- Test if Cust1 has a copy of 'Jurassic Park': ---" << std::endl;
      std::cout << testCustomer1->isCheckedOut("Jurassic Park") << " ('0' expected)" << std::endl << std::endl;

      std::cout << "--- Execute a return transaction via Cust::appendHistory()... ---" << std::endl << std::endl;
      // Attempt to process return on Cust1
      testCustomer1->appendHistory(testReturn.toString(), testReturn.getType(), testReturn.getTitle());

      // Check the outstanding rentals of customer 1
      std::cout << "--- Test if Cust1 has a copy of 'Ferries and You: A Primer': ---" << std::endl;
      std::cout << testCustomer1->isCheckedOut("Ferries and You: A Primer") << " ('0' expected)" << std::endl << std::endl;

      std::cout << "--- Test if Cust1 has a copy of 'Jurassic Park': ---" << std::endl;
      std::cout << testCustomer1->isCheckedOut("Jurassic Park") << " ('0' expected)" << std::endl << std::endl;

      // Attempt to insert customers to database
      std::cout << "--- Inserting Cust1 and Cust2 to database... ---" << std::endl << std::endl;
      testCustDB.insertCustomer(testCustomer1);
      testCustDB.insertCustomer(testCustomer2);

      // Check insertion
      std::cout << "--- Checking insertion results: ---" << std::endl;
      std::cout << testCustDB.toString() << std::endl << std::endl;

      std::cout << "--- END CUSTOMER DATABASE TESTS ---" << std::endl << std::endl;

   } // END CUSTOMER DATABASE TESTS



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       INV DATABASE TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (true) {

      std::cout << "--- START INVENTORY DATABASE TESTS ---" << std::endl << std::endl;

      // Create a new inventory database object
      std::cout << "Creating an empty InvDB object..." << std::endl << std::endl;
      InvDB testInvDB;

      std::cout << "Create an InvDB object from bulk input..." << std::endl << std::endl;
      std::ifstream inventoryFile("data4movies.txt");
      InvDB testInvDBBulk(inventoryFile);


      // Create three new films
      std::cout << "Creating three new films..." << std::endl << std::endl;
      // Should sort by Title, then year
      Comedy filmBB("F, 10, Nora Ephron, Sleepless in Seattle, 1993");
      Comedy filmBB2("F, 10, Parody-Man, Sleepless in Seattle, 1997");
      // Should sort by Director, then Title
      Drama filmCC("D, 10, Jonathan Demme, Silence of the Lambs, 1991");
      Drama filmCC2("D, 10, Jonathan Demme, Something Different, 1991");
      // Should sort by Release Date, then major actor
      Classic filmAA("C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939");
      Classic filmAA2("C, 10, Victor Fleming, The Wizard of Oz, Bob Barker 7 1939");

      // Attempt to add these films to the inventory database
      std::cout << "Adding films to the testInvDB..." << std::endl << std::endl;
      testInvDB.addFilm(&filmAA);
      testInvDB.addFilm(&filmAA2);
      testInvDB.addFilm(&filmBB);
      testInvDB.addFilm(&filmBB2);
      testInvDB.addFilm(&filmCC2);
   
      // Test Display method
      std::cout << std::endl;
      std::cout << "State of testInvDB:" << std::endl;
      std::cout << testInvDB.toString() << std::endl << std::endl;

      std::cout << "State of testInvDBBulk:" << std::endl;
      std::cout << testInvDBBulk.toString() << std::endl << std::endl;

      // Query quantities of each film
      std::cout << "testinvDB contains Oz: " << testInvDB.contains(&filmAA) << std::endl;
      std::cout << "testinvDB contains Seattle: " << testInvDB.contains(&filmBB) << std::endl;
      std::cout << "testinvDB contains Lambs: " << testInvDB.contains(&filmCC) << std::endl;

      testInvDB.addFilm(&filmCC);
      std::cout << "Oz Qty: " << testInvDB.retrieve(&filmAA)->getStock() << std::endl;
      std::cout << "Seattle Qty: " << testInvDB.retrieve(&filmBB)->getStock() << std::endl;
      std::cout << "Lambs Qty: " << testInvDB.retrieve(&filmCC)->getStock() << std::endl;
   
      // Create borrow transactions
      std::cout << "Creating borrow transactions..." << std::endl << std::endl;
      Trans BTestC = Trans("B 1234 C The Wizard of Oz, 7 1939");
      Trans BTestD = Trans("B 1234 D Silence of the Lambs, 1991");
      Trans BTestF = Trans("B 1234 F Sleepless in Seattle, 1993");

      // Create return transactions
      std::cout << "Creating return transactions..." << std::endl << std::endl;
      Trans RTestC = Trans("R 1234 C The Wizard of Oz, 7 1939");
      Trans RTestD = Trans("R 1234 D Silence of the Lambs, 1991");
      Trans RTestF = Trans("R 1234 F Sleepless in Seattle, 1993");

      // Create an invalid return (one that has no borrow)
      std::cout << "Creating an erroneous return (no corresponding borrow)";
      Trans RTestErr = Trans("R 1234 C Guardians of te Galaxy, 2016");

      // Send a transaction
      // TODO: Finish Transaction class constructor string parsing
      // testInvDB.adjustStock(BTestF);
      // testInvDB.adjustStock(RTestD);
      // testInvDB.adjustStock(BTestF);

      // Test Display method
      std::cout << std::endl;
      std::cout << "Post-Transaction State of testInvDB:" << std::endl;
      std::cout << testInvDB.toString() << std::endl << std::endl;

      // Query film states again

      // test operators
      std::cout << "Test filmAA == filmAA2 using Film::operator==, Film::equals()" << std::endl;
      if (filmAA == filmAA2) {
         std::cout << "filmAA == filmAA2: true" << std::endl;
      }

      std::cout << "Test filmAA.equals(filmAA2) using Classic::equals()" << std::endl;
      if (filmAA.equals(filmAA2)) {
         std::cout << "filmAA.equals(filmAA2): true" << std::endl;
      }




      std::cout << "--- END INVENTORY DATABASE TESTS ---" << std::endl << std::endl;

   } // END INVENTORY DATABASE TESTS



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       BULK CUSTOMERDB INPUT TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (false) {

      std::cout << "--- START BULK CUSTOMERDB INPUT TESTS ---" << std::endl << std::endl;

      // Test the customerDB bulk inputs
      std::cout << "Testing customerDB bulk inputs..." << std::endl << std::endl;

      // Test the customerDB bulk inputs
      std::cout << "Creating an empty CustDB object..." << std::endl << std::endl;

      // Capture command file to filestream
      std::cout << "Capture bulk input to fileStream..." << std::endl << std::endl;

      // Have the Inventory Controller (main()) parse the file and perform insertion actions
      std::cout << "Sending bulk commands to CustDB object..." << std::endl << std::endl;

      // Test isLegalCust() logic
      std::cout << "The first command isLegal(): " << "<isLegal() result goes here>" << " (0 expected, plus error report)" << std::endl << std::endl;

      // Check if the commands were SUPER EFFECTIVE!
      std::cout << "Check state of CustDB after bulk input:" << std::endl << std::endl;

      std::cout << "--- END BULK CUSTOMERDB INPUT TESTS ---" << std::endl << std::endl;

   } // END BULK CUSTOMERDB INPUT TESTS 



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       BULK INVENTORYDB INPUT TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (false) {

      std::cout << "--- START BULK INVENTORYDB INPUT TESTS ---" << std::endl << std::endl;
   
      // Test the inventoryDB bulk inputs
      std::cout << "Testing inventoryDB bulk inputs..." << std::endl << std::endl;

      // Test the inventoryDB bulk inputs
      std::cout << "Creating an empty InvDB object..." << std::endl << std::endl;

      // Capture command file to filestream
      std::cout << "Capture bulk input to fileStream..." << std::endl << std::endl;
   
      // Have the Inventory Controller (main()) parse the file and perform insertion actions
      std::cout << "Sending bulk commands to InvDB object..." << std::endl << std::endl;
   
      // Test isLegalInv() logic
      std::cout << "The first command isLegal(): " << "<isLegal() result goes here>" << " (0 expected, plus error report)" << std::endl << std::endl;

      // Check if the commands were SUPER EFFECTIVE!
      std::cout << "Check state of InvDB after bulk input:" << std::endl << std::endl;
   
      std::cout << "--- END BULK INVENTORYDB INPUT TESTS ---" << std::endl << std::endl;

   } // END BULK CUSTOMERDB INPUT TESTS
   

   
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       BULK COMMAND INPUT TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (false) {

      std::cout << "--- START BULK COMMAND INPUT TESTS ---" << std::endl << std::endl;

      // Generate a test InvDB and CustDB
      std::cout << "Generating empty InvDB and CustDB objects..." << std::endl << std::endl;
      InvDB BulkInvDB = InvDB();
      CustDB BulkCustDB = CustDB();

      // Minimally populate these two DBs
      std::cout << "Populating the two databases..." << std::endl << std::endl;

      // Capture the command file to a stream
      std::cout << "Loading the command file..." << std::endl << std::endl;

      // Parse the stream
      std::cout << "Parsing the command stream..." << std::endl << std::endl;

      // Test isLegal() logic
      std::cout << "Testing isLegal() logic:" << std::endl;
      std::cout << std::endl;

      // Generate transaction objects from legal commands
      // Send these transactions to both the InvDB and CustDB
      std::cout << "Generating and sending test transactions..." << std::endl << std::endl;
      // call bulkProcess()

      // Check results
      std::cout << "Results of bulk processing" << std::endl;
      std::cout << "InvDB status:" << std::endl << BulkInvDB.toString() << std::endl << std::endl;
      std::cout << "CustDB status:" << std::endl << BulkCustDB.toString() << std::endl << std::endl;
      std::cout << std::endl;

      std::cout << "--- END BULK COMMAND INPUT TESTS ---" << std::endl << std::endl;

   } // END BULK COMMAND INPUT TESTS



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       FOR REALSIES EXECUTION
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (false) {

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

   } // Closing if - End of for realsies execution "unit test"

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
void bulkReadCust(std::ifstream& custFile, CustDB tgtDB) {
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
// #bulkReadInv(ifstream&, InvDB)
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
void bulkReadInv(std::ifstream& invFile, InvDB tgtDB) {
   // While there is still filestream to read
   while (!invFile.eof()) {
      // Get a line of text (one command)

      std::string command;
      std::getline(invFile, command);

      // If the command is legal...
      if (isLegalInvCmd(command, tgtDB)) {

         // Send it to the Inventory Database
         tgtDB.runCmd(command);

      } // Closing if - Legal inventory command sent
   } // Closing while - All lines of input consumed
} // Closing bulkReadInv()

// (+) --------------------------------|
// #bulkReadTrans(ifstream&, InvDB)
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
void bulkReadTrans(std::ifstream& commandFile, CustDB tgtCustDB, InvDB tgtInvDB) {
   // Generate Transactions from the CommandFile and send Transaction impacts to the appropriate locations
   while (!commandFile.eof()) {
      // Read the next relevant line of command
      std::string command;
      std::getline(commandFile, command);

      // TODO: I and H cases
      // If the command is an 'I'
      if (command == "I") {
         // Ping invDB for execution
         tgtInvDB.display();
      }

      // If the command is an 'H'
      if (command[0] == 'H') {
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
            std::cout << "Error @ bulkReadTrans(): Customer ID out of range (0-9999)" << std::endl;
         }
         // If the custDB does not have this customer...
         else if (!tgtCustDB.doesContain(custID)) {
            std::cout << "Error @ history (H) command: No such customer" << std::endl;
         }
         // Otherwise...
         else {
            // Output the history of the customer at this position
            std::cout << tgtCustDB.getCustomerAt(custID)->getHistory() << std::endl;
         }
      } // Closing if - 'H' condition handled

      // Prepare to hold a transaction
      Trans* currTrans = nullptr;
      // If the command is legal (based on the command and DB states
      if (isLegalTransCmd(command, tgtCustDB, tgtInvDB)) {
         // Create a transaction from it
         currTrans = new Trans(command);
         // Aggregate inventory information from the databases to add needed info to the transaction
         padOut(currTrans, tgtInvDB);

      }


      // Send the Transaction to the Databases for execution
      tgtInvDB.adjustStock(*currTrans);
      tgtCustDB.appendHistory(*currTrans);

      // deallocate current transaction now that it's been used
      if (currTrans != nullptr) {
         delete currTrans;
      }
   } // Closing while - All lines of command read from file / filestream
   std::cout << "--- All command lines parsed ---" << std::endl << std::endl;

} // Closing bulkReadTrans()

// (+) --------------------------------|
// #isLegalCustCmd(ifstream&, CustDB)
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
bool isLegalCustCmd(std::string command, CustDB tgtDB) {
   // Set flag
   bool isLegal = true;
   // Begin error log
   std::string errorLog = "";

   // Initialize field variables
   int custID = 1234512345;
   std::string nameF = "";
   std::string nameL = "";

   // Parse fields
   // TODO: Load string command to string stream object

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

   // TODO: Any other ways a customer command can be invalid?

   // If any test has failed, do not forward to database
   if (isLegal == false) {
   std::cout << "Customer command error:" << std::endl;
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
// #isLegalInvCmd(ifstream&, InvDB)
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
bool isLegalInvCmd(std::string command, InvDB tgtDB) {
   // Set flag
   bool isLegal = true;
   // Begin error log
   std::string errorLog = "";
   int currentYear = 2018;

   // Initialize field variables
   char genre = NULL;
   int qty = 0;
   std::string field1 = ""; // Director
   std::string field2 = ""; // Title
   std::string field3 = ""; // Actor (in case of Classic)
   int releaseMonth = 0;
   int releaseYear = 0;

   // TODO: Parse fields

   // Test if genre is within range first
   if ((genre != 'C') || (genre != 'F') || (genre != 'D')) {
   std::cout << "Inventory command error:" << std::endl;
   std::cout << "   - Invalid genre, halting." << std::endl;
   return(false);
   }

   // Verify that quantity is non-zero
   if (qty == 0) {
   // If not, append report
   errorLog = errorLog + "   - Zero quantity (non-inventory)" + "\n";
   // And toggle the flag
   isLegal = false;
   }

   // TODO: Other tests on quantity? Negative values?

   // Verify that a director is entered
   if (field1 == "") {
   // If not, append report
   errorLog = errorLog + "   - No director specified" + "\n";
   // And toggle the flag
   isLegal = false;
   }

   // Verify that a film name is entered
   if (field2 == "") {
   // If not, append report
   errorLog = errorLog + "   - No film title entered" + "\n";
   // And toggle the flag
   isLegal = false;
   }

   // In the case of classic films only, verify that an actor is specified
   if (genre == 'C' && field3 == "") {
   // If not, append report
   errorLog = errorLog + "   - No actor/actress specified" + "\n";
   // And toggle the flag
   isLegal = false;
   }

   // In the case of classic films only, verify that a release month is specified
   if (genre == 'C' && (releaseMonth < 1 || releaseMonth > 12)) {
   // If not, append report
   errorLog = errorLog + "   - Release month not properly entered" + "\n";
   // And toggle the flag
   isLegal = false;
   }

   // Verify that a release year was entered
   if (releaseYear == 0 || releaseYear > currentYear) {
   // If not, append report
   errorLog = errorLog + "   - Release year not properly specified" + "\n";
   // And toggle the flag
   isLegal = false;
   }

   // If any test has failed, do not forward to database
   if (isLegal == false) {
   std::cout << "Customer command error:" << std::endl;
   std::cout << errorLog << std::endl;
   return(isLegal);
   }
   // Otherwise, this is a correctly formatted command
   // But it may still be in conflict with the database state, so check that
   isLegal = tgtDB.isLegal(command);
   // Note: tgtDB.isLegal() handles its own error reporting to cout
   // Return whether the database confirmed legality or not
   return(isLegal);
} // Closing isLegalInvCmd()

// (+) --------------------------------|
// #isLegalTransCmd(ifstream&, CustDB, InvDB)
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
bool isLegalTransCmd(std::string command, CustDB tgtCustDB, InvDB tgtInvDB) {
   // Set flag
   bool isLegal = true;
   // Begin error log
   std::string errorLog = "";

   int currentYear = 2018;

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

   // TODO: Parse command type off string

   // Test if the commandType is within range first
   if ((commandType != 'I') || (commandType != 'H') || (commandType != 'B') || (commandType != 'R')) {
   std::cout << "Transaction command error:" << std::endl;
   std::cout << "   - Invalid command type, halting." << std::endl;
   return(false);
   }

   // Finish testing for an 'I' (inventory query) command
   if (commandType == 'I' /*&& there's anything else in the string*/) { // TODO
   std::cout << "Transaction command error:" << std::endl;
   std::cout << "   - Invalid entry of 'I' (inventory) command, halting." << std::endl;
   return(false);
   }

   // All legality checks for an 'I' command complete, so exit
   if (commandType == 'I') {
   return(isLegal);
   }

   // TODO: Parse customerID

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
   errorLog = errorLog + "   - Non-existent customer" + "\n";
   // And toggle the flag
   isLegal = false;
   }

   // Check validity of a 'H' (history) command
   if (commandType == 'H'/*&& there's anything else in the string*/) { // TODO
   std::cout << "Transaction command error:" << std::endl;
   std::cout << "   - Invalid entry of 'H' (history) command, halting." << std::endl;
   std::cout << errorLog << std::endl;
   return(false);
   }

   // TODO: Parse format

   // Test if format is within range
   if (format != 'D') {
   // Append the error log
   errorLog = errorLog + "   - Invalid media format." + "\n";
   // And toggle the flag
   isLegal = false;
   }

   // TODO: Parse genre

   // Test if genre is within range
   if ((genre != 'C') || (genre != 'F') || (genre != 'D')) {
   std::cout << "Inventory command error:" << std::endl;
   std::cout << "   - Invalid genre, halting." << std::endl;
   std::cout << errorLog << std::endl;
   return(false);
   }

   // Legality tests for classics only
   if (genre == 'C') {
   // TODO: Parse releaseMonth
   // TODO: Parse releaseYear
   // TODO: Parse actor

   // TODO: Perform all legality checks for Classics
   // Verify that releaseMonth is within range
   // Verify that releaseYear is within range
   // Verify that an actor is provided
   }

   if (genre == 'D') {
   // TODO: Parse director
   // TODO: Parse title

   // TODO: Perform all legality checks for Dramas
   // Verify that a director is provided
   // Verify that a title is provided
   }

   if (genre == 'F') {
   // TODO: Parse title
   // TODO: Parse releaseYear

   // TODO: Perform all legality checks for Comedies
   // Verify that a title is provided
   // Verify that releaseYear is within range
   }


   // If any test has failed, do not forward to database
   if (isLegal == false) {
   std::cout << "Customer command error:" << std::endl;
   std::cout << errorLog << std::endl;
   return(isLegal);
   }
   // Otherwise, this is a correctly formatted command
   // But it may still be in conflict with the database state, so check that
   isLegal = (tgtCustDB.isValid(command));
   // Note: Target databases handle their own error reporting to cout
   // Return whether the database confirmed legality or not
   return(isLegal);
} // Closing isLegalTransCmd()

// (+) --------------------------------|
// #padOut(ifstream&, CustDB, InvDB)
//-------------------------------------|
// Desc:    Acquires and appends missing information for a transaction
// Params:  transPtr* arg1 - 
//          InvDB arg2 - 
// PreCons: A valid InvDB object must exist
//          A valid transaction constructed from a legal command must exist
// PosCons: Sufficient data has been appended to the transaction to allow for proper output
// RetVal:  None
// MetCall: NULL
void padOut(Trans* transPtr, InvDB tgtInvDB) {
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
      // TITLE
      std::string title = tgtInvDB.getCTitleByTuple(transPtr->getReleaseMonth(), transPtr->getReleaseYear(), transPtr->getActor());
      transPtr->setTitle(title);
   }

   // Drama
   else if (transPtr->getGenre() == 'D') {
      // RELEASEYEAR
      int year = tgtInvDB.getDYearByTuple(transPtr->getDirector(), transPtr->getTitle()); // TODO: Get the release date out of the InvDB based on director/title
      transPtr->setReleaseYear(year);
   }

   // Comedy, missing fields:
   else if (transPtr->getGenre() == 'F') {
      // All necessary data is acquired
      // So do nothing
   }

   // Transaction holds sufficient data for CustDB to process
}

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of file - driver.cpp
