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

#include "BST.h"

#include "BSTNode.h"

//class MorseCodeConversion
//{
//public:
//
//	MorseCodeConversion(); //a constructor!!!
//	~MorseCodeConversion(); //a destructor!!
//
//	void charToMorseCode(BST& searchingTree, ifstream& fileStream);
//
//	void runMorseCodeConversion();
//	
//private:
//	//BST MorseLookupBST;
//	ifstream fileStreamMorseTable;
//	ifstream fileStreamConvert;
//};

//ifstream& operator>>(ifstream& fileStream, char dummyCharToConvert);
//ostream& operator<< (ostream& screen, string morseCodeToString);




/********************************************************************************************************************
* Class name: MorseCodeConversion tempalte <class T, class U, class I>
* Description: This MorseCodeConversion class helps run the morse code program by converting each letter into
*              its corresponding morse code. In this program, each of T, U and I refer to char, string and ifstream.
*********************************************************************************************************************/
template <class T, class U, class I>
class MorseCodeConversion
{
public:

	MorseCodeConversion(); //a constructor!!!
	~MorseCodeConversion(); //a destructor!!

	void charToMorseCode(BST<T,U,I>& searchingTree, I& fileStream);

	void runMorseCodeConversion();

private:
	//BST MorseLookupBST;
	I fileStreamMorseTable;
	I fileStreamConvert;
};


/********************************************************************************************************************
* Function: MorseCodeConversion() <template>
* Description: A default constructor for MorseCodeConversion class. It initializes its private members
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <class T, class U, class I>
MorseCodeConversion<T,U,I>::MorseCodeConversion()
{
}

/********************************************************************************************************************
* Function: ~MorseCodeConversion() template <class T, class U, class I>
* Description: a destructor: deallocates an object, implictly invoked when the object goes out of scope.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <class T, class U, class I>
MorseCodeConversion<T,U,I>::~MorseCodeConversion()
{
}



/********************************************************************************************************************
* Function: charToMorseCode() template <class T, class U, class I>
* Description: This function converts from an ENglish sentence found in Conver.txt file into its corresponding
*              morse code and outputs it to the console screen. T here refers to char, U refers to string, and 
*              I refers to a input file stream.
* Input parameters: searchingTree: an object from BST<T,U,I> class passed by referance.
*                   fileStream: an input file stream.
* Returns: Nothing
*********************************************************************************************************************/
template <class T, class U, class I>
void MorseCodeConversion<T,U,I>::charToMorseCode(BST<T,U,I>& sarchingTree, I& fileStream)
{
	int i = 0;
	T tempLine[100];
	T dummyCharToConvert = NULL;
	U dummyMorseCodeConverted = "";

	fileStream.open("Convert.txt");


	while (!fileStream.eof())
	{
		fileStream.getline(tempLine, 100);
		cout << "An English Sentence (Before Morse code conversion): " << tempLine << endl;

		cout << "Morse code converted: ";

		while (tempLine[i] != '\0')
		{
			dummyCharToConvert = toupper(tempLine[i]);
			if (dummyCharToConvert == ' ')
			{
				do
				{
					cout << dummyCharToConvert;
					i++;
					dummyCharToConvert = toupper(tempLine[i]); //redefine!!!!
				} while (dummyCharToConvert == ' ');

				cout << " ";
				if (dummyCharToConvert == '\0') break;
			}
			dummyMorseCodeConverted = sarchingTree.search(sarchingTree.get_pRoot(), dummyCharToConvert);
			cout << dummyMorseCodeConverted << " ";
			i++;
		}

		i = 0;
		cout << endl << endl;
	}

	fileStream.close();
}



/********************************************************************************************************************
* Function: runMorseCodeConversion() template <class T, class U, class I>
* Description: This function runs the Morse code conversion program from Convert.txt file into the console output
*              in the form of a morse code.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <class T, class U, class I>
void MorseCodeConversion<T,U,I>::runMorseCodeConversion()
{
	//<data type> only when initializing a variable!!!!!!
	BST<char,string,ifstream> morseLookupBST(fileStreamMorseTable); //BST constructor is invoked!!!!

	//fileStreamMorseTable.open("MorseTable.txt"); //open the file  //at least file is opened!!!
	//morseLookupBST.insert(morseLookupBST.get_pRoot(), fileStreamMorseTable); //make a search tree!!!!
	//fileStreamMorseTable.close();

	cout << "Welcome to the Conversion To Morse Code Program!!!" << endl << endl;
	//cout << "pRoot BST tree pointer: " << morseLookupBST.get_pRoot() << endl << endl;
	cout << "Binary Search Tree English Character - Morse Code " << endl << endl;

	morseLookupBST.print(morseLookupBST.get_pRoot()); //printing the tree!!!

	cout << endl;
	charToMorseCode(morseLookupBST, fileStreamConvert);

}