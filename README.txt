//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - ReadMe
// README.TXT
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------------------------------------------------------------------|
// Authorship
//-----------------------------------------------------------------------------|
//
// Tim Lum + Matt Gross
// twhlum@gmail.com + mattgrosspersonal@gmail.com
// Created:  2018.03.04
// Modified: 2018.03.14
// For the University of Washington Bothell, CSS 502A
// Winter 2018, Graduate Certificate in Software Design & Development (GCSDD)
//

//-----------------------------------------------------------------------------|
// Acknowledgements
//-----------------------------------------------------------------------------|
//
// Template author:
// Tim Lum (twhlum@gmail.com)
//
// data4commands.txt, data4customers.txt, data4movies.txt
// Min Chen (minchen2@uw.edu)
//
// Assignment specification and coding standards:
// Min Chen (minchen2@uw.edu)
//

//-----------------------------------------------------------------------------|
// License
//-----------------------------------------------------------------------------|
//
// This software is published under the MIT License
// https://en.wikipedia.org/wiki/MIT_License
/*
MIT License
Copyright (c) 2018 Timothy W. Lum (twhlum@gmail.com)
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
//

//-----------------------------------------------------------------------------|
// Abbreviations - Updated 2018.03.14
//-----------------------------------------------------------------------------|
//
// (-)      == (UML) Private
// (#)      == (UML) Protected
// (+)      == (UML) Public
// !        == Not
// @        == At
// #b2c     == #-Bit 2's Complement
// Arg      == Argument
// Alloc    == Allocate(d)
// B-1st    == Breadth-First
// BH       == Binary Heap
// BST      == Binary Search Tree
// BT       == Binary Tree
// Char     == Character
// Coeff    == Coefficient
// Concat   == Concatenation
// Curr     == Current
// D-1st    == Depth-First
// DB       == Database
// Dbl      == Double
// Desc     == Description
// Dest     == Destination
// deQ      == Dequeue
// Dist     == Distance
// enQ      == Enqueue
// EoF      == End of File
// EoL      == End of Line
// EQ       == Equals
// Expon    == Exponent
// Exts     == Extends
// FIFO     == First In, First Out (Queue)
// Gen      == Generic
// GIGO     == Garbage In : Garbage Out
// Info     == Information
// Inhrt    == Inherit
// Int      == Integer
// Invar    == Invariant
// L        == Left
// LIFO     == Last In, First Out (Stack)
// LH       == Left-Hand
// LL       == Linked List
// LSB      == Least Significant Bit
// LSD      == Least Significant Digit
// Malloc   == Memory Allocate(d)
// MetCall  == Method Call
// Mo3      == Median of Three
// MSB      == Most Significant Bit
// MSD      == Most Significant Digit
// NaN      == Not a Number
// NaV      == Not a Value
// Obj      == Object
// Param    == Parameter
// Polynom  == Polynomial
// PosCond  == Postcondition
// PreCond  == Precondition
// Prev     == Previous
// Ptr      == Pointer
// Q        == Queue
// R        == Right
// Ret      == Return
// RetVal   == Return Value
// RGB      == Red Green Blue
// (R)GB    == Red
// R(G)B    == Green
// RG(B)    == Blue
// RH       == Right-Hand
// RnTm     == Runtime
// RtL      == Right to Left
// SOP      == Shortest Open Path
// Src      == Source
// Str      == String
// <T>      == "Of type T"
// Term     == Terminus
// Trav     == Traverse / Traversal
 // PreOrd  == Pre-Order
 // InOrd   == In-Order
 // PostOrd == Post-Order
// TtB      == Top to Bottom
// Ur-      == Originator, foremost (ie. Ur-Node)
// Val      == Value
// Var      == Variable
// Vtx      == Vertex
//

//-----------------------------------------------------------------------------|
// Code Standards
//-----------------------------------------------------------------------------|
//
// Source material from:
// University of Washington Bothell
// CSS 501A Data Structures And Object-Oriented Programming I
// "Design and Coding Standards"
// c. Michael Stiber, 2017
//
// I. Comment at beginning of file (above) stating (at a minimum):
//    A. File Name
//    B. Author Name
//    C. Date
//    D. Description of code purpose 
// II. Indentation:
//    A. 3 whitespaces ("   ")
//    B. May vary depending on language and instructor
// III. Variables:
//    A. Descriptive, legible name
//    B. Comment over any variable declaration describing:
//       0. Its use in the algorithm
//       1. Invariant information such as legal ranges of values
// IV. Class Files:
//    A. Separate *.cpp and *.h files should be used for each class.
//    B. Files names must exactly match class names (case-sensitive)
// V. Includes:
//    A. Calls for content ("#include") from the Standard Template Library (STL) should be formatted as follows:
//       0. DO type:     #include <vector>
//       1. Do NOT type: #include <vector.h>
//    B. You may use the directive "using namespace std;"
//       0. ??? (?CONFIRM?)
// VI. Classes:
//    A. Return values:
//       0. Do NOT return references to internal class structures.
//       1. Do NOT return pointers to internal class structures.
//    B. Do NOT expose any details of the internal implementation.
// VII. Functions + Methods:
//    A. Functions should be used for appropriate operations.
//    B. Reference arguments should be used only when necessary.
//    C. The (return?CONFIRM?) type of each function must be declared
//       0. Use 'void' when necessary
//    D. Declare as 'const' (unalterable) when no modification is made to the object state
//       0. UML 'query' property (?CONFIRM?)
// VIII. Function Comments:
//    A. DO include a comment prior to each function which includes the function's:
//       0. Purpose - Why does the function exist?
//       1. Parameters - What fields does the function contain?
//       2. Preconditions - What conditions must be true prior to the function call?
//       3. Postconditions - What conditions must be true after the function call?
//       4. Return value - What is the nature and range of the value returned by the function?
//       5. Functions called - What other functions are called by this function?
// IX. Loop invariants
//    A. Each loop should be commented with 'invariant' information (?CONFIRM?)
// X. Assertions:
//    A. May be comments or the 'assert()' feature.
//    B. Insert where useful to explain important features or subtle logic.
//    C. What, exactly, is an assertion (?CONFIRM?)
// XI. Prohibited (unless justified):
//    A. Global variables
//    B. "Gotos" (?CONFIRM?)

// Source material from:
// University of Washington Bothell
// CSS 502A Data Structures And Object-Oriented Programming II
// "Coding, Documentation, and Style Guidelines"
// c. Min Chen, 2018
//
// I. Spelling and Capitalization
//    A. Reserved words (ie. "int") shall be all lowercased
//    B. Constants shall be all uppercased (ie. "SOMECONSTANTVARIABLE")
//    C. Other capitalizations do not have a standard, but should be consistent
//    D. Constants and Variables should be declared at the start of a file or function definition
//    E. Variables and Function Names should be descriptive of their use
// II. Punctuation and Whitespace
//    A. Avoid use of trailing or preceding underscores in names ("_someName_")
//    B. Open and Closing braces ("{" and "}") should occupy their own line
//       1. Exception: An open brace may end the line of its calling function
//       2. The above exception must be used consistently (see class lecture, lecture 01, week 01)
//    C. It is recommended that closing braces are commented as to what block they are intended to close.
//    D. It is recommended that operators be framed by spaces ("thing1 + thing2" instead of "thing1+thing2")
//    E. Limit code and comments to 80 characters per line
// III. Documentation and Style
//    A. Every File should have opening documentation including:
//       1. Description of the file function
//       2. How the file operates
//       3. Algorithms the file makes use of
//       4. The file author
//       5. Date of initial creation
//       6. Date of last modification
//    B. Utilize ASCII blocks to improve program legibility
// IV. Functions
//    A. Comments should be included at the start of each function to describe:
//       1. What the function does
//       2. How the function works
//       3. Any special algorithms the function uses
// V. Public vs. Private
//    A. Only interfacing methods should be public
//    B. Data members should almost always be private
//    C. Do not return pointers and references to data members to circumvent privacy
// VI. Global Variables and Constants
//    A. Do not use Global variables
//    B. Global constants are acceptable
//       1. Define these in the .h file
//    C. Use constant identifiers
// VII. Consts
//    A. Use 'const' member functions when possible
//    B. When passing by reference, use const when possible
// IX. Comments
//    A. Use comments to explain:
//       1. Key program segments
//       2. Segments whose purpose or design is not obvious to the reader
//    B. Err on the side of more comments than too few
//    C. Comment #includes to explain why they are included in the program
//    D. Utilize block comments to describe logical sections of code
// X. Industry Conventions
//    A. Avoid 'cute' identifiers
//    B. Prompts at execution time should be self-explanatory
//    C. Aim for quality commenting, rather than quantity
//    D. Readability of code does count, at the very least to the next person reading it.
//    E. Apply parentheses liberally to establish explicit operator precedence
//

//-----------------------------------------------------------------------------|
// Special Instructions
//-----------------------------------------------------------------------------|
//
// To install G++:
// sudo apt install g++

// To update Linux:
// sudo apt-get update && sudo apt-get install
// sudo apt-get update

// To make a new .cpp file in Linux:
// nano <file name>.cpp

// To make a new .h file in Linux:
// nano <file name>.h

// To make a new .txt file in Linux:
// nano <file name>.txt

// To compile in g++:
// g++ -std=c++11 *.cpp

// To run with test input:
// ./a.out < TestInput.txt

// To run Valgrind:
// Install Valgrind:
// sudo apt install valgrind
//
// Run with:
// valgrind --leak-check=full <file folder path>/<file name, usually a.out>
// OR
// valgrind --leak-check=full --show-leak-kinds=all <file path>/a.out
//
// ie.
// valgrind --leak-check=full /home/Teabean/a.out
// OR
// valgrind --leak-check=full --show-leak-kinds=all /home/Teabean/a.out
// OR
// valgrind --leak-check=full --show-leak-kinds=all /home/Teabean/a.out < /Sudoku.txt

// To load a text file as cin input in Visual Studios:
// 1. Go to the top menu bar => Debug => <ProjectName> Properties => Debugging => Command Arguments =>
// 2. "< <Filepath>/<Filename>.txt" ie. "< /Sudoku.txt"
// ie. < /Sudoku.txt

// To pass a command argument:
// 1. Go to the top menu bar => Debug => <ProjectName> Properties => Debugging => Command Arguments =>
// 2. Enter the file address and name
// ie. corpus.txt
// 3. Alter main() method signature as follows: main( int argc, char* argv[] ) {
// 4. The variable "argv[1]" now refers to the first command argument passed
//
// To run in Linux with Valgrind and a command argument
// valgrind --leak-check=full --show-leak-kinds=all ./a.out corpus.txt

// To declare a templated operator overload:
// .h file
// template <class T>
// class someClass
// {
//    template <class T>
//    friend ostream& operator << (ostream& someStream, someClass<T>& someObject);
// };
//
// .cpp file
// template <typename someDataType>
// ostream& operator << (ostream& ostr, BinarySearchTree<someDataType>& treeObject)
// {
//    <Code Implementation Goes Here>
//    return ostr;
// }

// To capture a typescript record of execution:
// $script outputFileDesired
// < Do all the things >
// $exit
//
