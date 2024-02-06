/****************************************************************************************************************************
* Programmer: Jaehong Lee
* Class: CPTs 122, Fall 2023; Lab Section 3 (Tuesday 1:30PM - 4:20PM)
* Programming Assignment: PA6
* Date: October 29, 2023
* Description: This PA assignment is creating a Morse Code conversion program from an English sentence in Convert.txt file.
*              Each english alphabet, digit-number, a query, a comma, a fullstop and its corresponding morse code from
*              MorseTable.txt file will be inserted into a tree node and organized in a binary search tree (BST) data structure.
*              Binary Search Tree (BST) is an efficient searching algorithm in general compared to linear search.
*              Also, there are two versions of class and its methods: non-template class with non-template methods and
*              template class with its template-methods. Currently, non-template version of class and functions are
*              commented out. You can always bring non-template version in.
****************************************************************************************************************************/

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <string>

#include <fstream>

using std::cin;
using std::cout;
using std::endl;

using std::string;

using std::fstream;
using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;

//class BSTNode
//{
//public:
//
//	BSTNode(char inputEnglishChar, string inputMorseCode);
//
//	char get_EnglishCharacter();
//	string get_MorseCode();
//
//	BSTNode* get_pLeft();
//	BSTNode* get_pRight();
//
//	void set_EnglishCharacter(char new_EnglishCharacter);
//	void set_MoreseCode(string new_MorseCode);
//
//	void set_pLeft(BSTNode* new_pLeft);
//	void set_pRight(BSTNode* new_pRight);
//
//private:
//	char EnglishCharacter;
//	string MoresCode;
//
//	BSTNode* pLeft;
//	BSTNode* pRight;
//};
//
//ifstream& operator>>(ifstream& fileStream, BSTNode& tree_node);




/********************************************************************************************************************
* Class name: BSTNode template <class T, class U>
* Description: BSTNode class object stores data from MorstTable.txt and BSTNode's left pointer and right pointer for
*              representing a binary search tree. In this program, T refers to char and U refers to string.
*********************************************************************************************************************/
template<class T, class U>
class BSTNode
{
public:

	BSTNode(T inputEnglishChar, U inputMorseCode);

	T get_EnglishCharacter();
	U get_MorseCode();

	BSTNode<T, U>* get_pLeft();
	BSTNode<T, U>* get_pRight();

	void set_EnglishCharacter(T new_EnglishCharacter);
	void set_MoreseCode(U new_MorseCode);

	void set_pLeft(BSTNode<T, U>* new_pLeft);
	void set_pRight(BSTNode<T, U>* new_pRight);

private:
	T EnglishCharacter;
	U MoresCode;

	BSTNode<T, U>* pLeft;
	BSTNode<T, U>* pRight;
};


/********************************************************************************************************************
* Function: BSTNode() template <class T, class U>
* Description: A default constructor for BSTNode class. It initializes its private members
* Input parameters: inputEnglishChar: a character from MorseTable.txt
*                   inputMorseCode: each character's corresponding morse code from MorseTable.txt
* Returns: Nothing
*********************************************************************************************************************/
template<class T, class U>
BSTNode<T,U>::BSTNode(T inputEnglishChar, U inputMorseCode)
{
	this->EnglishCharacter = inputEnglishChar;
	this->MoresCode = inputMorseCode;
	this->pLeft = nullptr;
	this->pRight = nullptr;
}


/********************************************************************************************************************
* Function: get_EnglishCharacter() template <class T, class U>
* Description: A getter function for EnglishCharacter, one of private members in BSTNode<T,U> class. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: EnglishCharacter
*********************************************************************************************************************/
template<class T, class U>
T BSTNode<T,U>::get_EnglishCharacter()
{
	return EnglishCharacter;
}



/********************************************************************************************************************
* Function: get_MorseCode() template <class T, class U>
* Description: A getter function for MorseCode, one of private members in BSTNode<T,U> class. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: MorseCode
*********************************************************************************************************************/
template<class T, class U>
U BSTNode<T,U>::get_MorseCode()
{
	return MoresCode;
}



/********************************************************************************************************************
* Function: get_pLeft() template <class T, class U>
* Description: A getter function for pLeft, one of private members in BSTNode<T,U> class. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: pLeft
*********************************************************************************************************************/
template<class T, class U>
BSTNode<T,U>* BSTNode<T,U>::get_pLeft()
{
	return this->pLeft; //this current obj
}


/********************************************************************************************************************
* Function: get_pRight() template <class T, class U>
* Description: A getter function for pRight, one of private members in BSTNode<T,U> class. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: pRight
*********************************************************************************************************************/
template<class T, class U>
BSTNode<T,U>* BSTNode<T,U>::get_pRight()
{
	return this->pRight;
}



/********************************************************************************************************************
* Function: set_EnglishCharacter() template <class T, class U>
* Description: A setter function for EnglishCharacter, one of private members in BSTNode<T,U> class. Used for updating its
*              data with a differnet value in a different class.
* Input parameters: new_EnglishCharacter
* Returns: Nothing
*********************************************************************************************************************/
template<class T, class U>
void BSTNode<T,U>::set_EnglishCharacter(T new_EnglishCharacter)
{
	EnglishCharacter = new_EnglishCharacter;
}


/********************************************************************************************************************
* Function: set_MorseCode() template <class T, class U>
* Description: A setter function for MorseCode, one of private members in BSTNode<T,U> class. Used for updating its
*              data with a differnet value in a different class.
* Input parameters: new_MorseCode
* Returns: Nothing
*********************************************************************************************************************/
template<class T, class U>
void BSTNode<T,U>::set_MoreseCode(U new_MorseCode)
{
	MoresCode = new_MorseCode;
}


/********************************************************************************************************************
* Function: set_pLeft() template <class T, class U>
* Description: A setter function for pLeft, one of private members in BSTNode<T,U> class. Used for updating its
*              data with a differnet address in a different class.
* Input parameters: new_pLeft
* Returns: Nothing
*********************************************************************************************************************/
template<class T, class U>
void BSTNode<T,U>::set_pLeft(BSTNode<T,U>* new_pLeft)
{
	this->pLeft = new_pLeft;
}


/********************************************************************************************************************
* Function: set_pRight() template <class T, class U>
* Description: A setter function for pRight, one of private members in BSTNode<T,U> class. Used for updating its
*              data with a differnet address in a different class.
* Input parameters: new_pRight
* Returns: Nothing
*********************************************************************************************************************/
template<class T, class U>
void BSTNode<T,U>::set_pRight(BSTNode<T,U>* new_pRight)
{
	this->pRight = new_pRight;
}




/********************************************************************************************************************
* Function: operator>>() template <class T, class U, class I>
* Description: This overloads an insertion operator so that private data members of english character and its
*              corresponding morse code string can be updated with input data from MorseTable.txt file.
* Input parameters: fileStream: an output stream.
*                   tree_node: a BSTNode<T,U> class object passed by referance.
* Returns: fileStream: an output stream to enable operator chaining.
*********************************************************************************************************************/
template<class T, class U, class I>
I& operator>>(I& fileStream, BSTNode<T,U>& tree_node);

template<class T, class U, class I>
I& operator>>(I& fileStream, BSTNode<T,U>& tree_node)
{
	T tempLine[100] = "";
	fileStream.getline(tempLine, 100); //extracts a line from an input file including the newline in the file

	tree_node.set_EnglishCharacter(*strtok(tempLine, " "));  //array of char string deerefernced get a single char
	tree_node.set_MoreseCode(strtok(NULL, "\n"));

	return fileStream; //function chaining is possible!!!!
}

