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

#include "BSTNode.h"

//class BST
//{
//public:
//
//	BST(ifstream& fileStream);
//
//	~BST(); //a destructor for a tree
//
//	void destroyBST(BSTNode* pRoot); //destroys the tree
//
//	BSTNode* get_pRoot();
//	
//	void insert(char inputEnglishCharacter, string morseCode);
//
//	void insert(BSTNode* pRoot, char inputEnglishChar, string morseCode);
//
//	void print(BSTNode* pRoot); //in order traversal!
//	
//	string search(BSTNode* pRoot, char inputEnglishCharacter);
//	
//	//makig changes copy of the root no the original one
//
//private:
//	BSTNode* pRoot;
//};



/********************************************************************************************************************
* Class name: BST tempalte <class T, class U, class I>
* Description: BST class object consturcts a binary search tree from MorseTable.txt. and this class has also has a 
*              printing function that can print the contents of the tree and a searching function from the binary
*              search tree. In this program, T refers to char, U refers to string, and I refers to ifstream.
*********************************************************************************************************************/
template<class T, class U, class I>
class BST
{
public:

	BST(I& fileStream);

	~BST(); //a destructor for a tree

	void destroyBST(BSTNode<T, U>* pRoot); //destroys the tree

	BSTNode<T, U>* get_pRoot();

	void insert(T inputEnglishCharacter, U morseCode);

	void insert(BSTNode<T,U>* pRoot, T inputEnglishChar, U morseCode);

	void print(BSTNode<T,U>* pRoot); //in order traversal!

	U search(BSTNode<T,U>* pRoot, T inputEnglishCharacter);

	//makig changes copy of the root no the original one

private:
	BSTNode<T,U>* pRoot;
};




/********************************************************************************************************************
* Function: BST() template <class T, class U, class I>
* Description: A default constructor for BST class. It initializes its private members
* Input parameters: fileStream: input file stream.
* Returns: Nothing
*********************************************************************************************************************/
template<class T, class U, class I>
BST<T, U, I>::BST(I& fileStream) //once its called it will make the entire binary search tree based on the input txt file stream passed in
{
	pRoot = nullptr;

	fileStream.open("MorseTable.txt"); //open the file first!!!
	//dummy variable will act as a place holder!!!!
	BSTNode<char, string> dummyNode(NULL, "");
	T dummyEnglishChar = NULL;
	U dummyMorseCode = "";

	while (!fileStream.eof()) //as long as not reached to the end of file
	{
		fileStream >> dummyNode; //once initialized I dont need to include <char, string>

		dummyEnglishChar = dummyNode.get_EnglishCharacter();
		dummyMorseCode = dummyNode.get_MorseCode();

		insert(pRoot, dummyEnglishChar, dummyMorseCode);
	}

	fileStream.close();//close the file
}


/********************************************************************************************************************
* Function: ~BST() template <class T, class U, class I>
* Description: a destructor: deallocates an object, implictly invoked when the object goes out of scope.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template<class T, class U, class I>
BST<T, U, I>::~BST()
{
	destroyBST(pRoot);
}



/********************************************************************************************************************
* Function: destroyBST() template <class T, class U, class I>
* Description: This deallocates each tree node in the tree in a recursive order.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template<class T, class U, class I>
void BST<T, U, I>::destroyBST(BSTNode<T,U>* pRoot)
{
	/*if (pRoot == nullptr)
	{
		delete pRoot;
		cout << "destructor for pRoot!" << endl;
	}*/

	//else
	//{
	if (pRoot->get_pLeft() != nullptr)
	{
		destroyBST(pRoot->get_pLeft());
	}

	/*else
	{
		cout << "Destructor for a tree node cotaining: " << pRoot->get_EnglishCharacter() << "  " << pRoot->get_MorseCode() << endl;
		delete pRoot;
	}*/

	if (pRoot->get_pRight() != nullptr)
	{
		destroyBST(pRoot->get_pRight());
	}

	/*else
	{
		cout << "Destructor for a tree node cotaining: " << pRoot->get_EnglishCharacter() << "  " << pRoot->get_MorseCode() << endl;
		delete pRoot;
	}*/

	cout << "Destructor for a tree node cotaining: " << pRoot->get_EnglishCharacter() << "  " << pRoot->get_MorseCode() << endl;
	delete pRoot;
	//}
}



/********************************************************************************************************************
* Function: get_pRoot() template <class T, class U, class I>
* Description: A getter function for pRoot, one of private members in BST<T,U, I> class. Used for accessibility
*              to its data in a different class.
* Input parameters: Nothing
* Returns: pRoot
*********************************************************************************************************************/
template <class T, class U, class I>
BSTNode<T, U>* BST<T, U, I>::get_pRoot()
{
	return pRoot;
}



/********************************************************************************************************************
* Function: insert() template <class T, class U, class I>
* Description: It inserts a tree node that contains data into the binary search search. It does not allow you users to
*              modify pRoot
* Input parameters: inputENglishChar: from MorseTable.txt  morseCode: which corresponds to an english character.
* Returns: Nothing
*********************************************************************************************************************/
template <class T, class U, class I>
void BST<T, U, I>::insert(T inputEnglishChar, U morseCode)
{
	insert(this->pRoot, inputEnglishChar, morseCode);
}




/********************************************************************************************************************
* Function: insert() template <class T, class U, class I>
* Description: It inserts a tree node that contains data into the binary search search. This will be used for constructing
*              a binary search tree.
* Input parameters: pRoot: a root BSTNode pointer.
*                   inputENglishChar: from MorseTable.txt  
*					morseCode: which corresponds to an english character.
* Returns: Nothing
*********************************************************************************************************************/
//passing a the whole node as a parameter is a bad practice!! //we dont need the whole node info only need
//an english char and its corresponding morse code string.
template <class T, class U, class I>
void BST<T, U, I>::insert(BSTNode<T, U>* pRoot, T inputEnglishChar, U morseCode)
{
	/*cout << "Morse Pointer: " << pRoot << endl;
	fileStream.open("MorseTable.txt");*/

	//Plus a good softerware principle, each function shouldo one task!!!, here insert func should be implemented only
	// for a new piece of data we get from parameters as arguments.
	// so in the recursive function do not' use iteration!!!!
	//while (!fileStream.eof()) //when this func is called recursively, another version of the while loop is called  //

		//BSTNode* pMem = new BSTNode(fileStream); //should allocate when finding the right targey
		//if you allocate space here!! when search goes through subtrees, a recursive fucn will be called.
		//however, we get lose track of the old pMem we createed from the previous call.
		//we should move the code only when inserting!!!!! that way we never lose track of it.


	if (pRoot == nullptr) //base case if root ptr is nullptr!!
	{
		//BSTNode* pMem = new BSTNode(fileStream);
		this->pRoot = new BSTNode<T,U>(inputEnglishChar, morseCode); //local param  is it or a private member
		//if get rid of this->  it will confuse!!that is it talking about the private member or a parameter!!!!

	}

	else
	{
		if (inputEnglishChar < pRoot->get_EnglishCharacter()) //goes to the left subtree
		{
			if (pRoot->get_pLeft() == nullptr)
			{
				//allocate the pMe
				//BSTNode* pMem = new BSTNode(fileStream);
				pRoot->set_pLeft(new BSTNode<T,U>(inputEnglishChar, morseCode)); //i can also allocate with and passit without making pMem
			}

			else
			{
				insert(pRoot->get_pLeft(), inputEnglishChar, morseCode);
			}

		}

		else if (inputEnglishChar > pRoot->get_EnglishCharacter()) //goes to the right subtree
		{
			if (pRoot->get_pRight() == nullptr)
			{
				pRoot->set_pRight(new BSTNode<T,U>(inputEnglishChar, morseCode));
			}

			else
			{
				insert(pRoot->get_pRight(), inputEnglishChar, morseCode);
			}

		}

	}
	//this->pRoot = pRoot;
	//print(pRoot); //printing the tree!!!
	//fileStream.close();
}
//writre a function that will read one line at at item which I did in an overloaded operator!
// wanna implement not relaese to the public
//

//making the tree!!!
//void BST::insert(BSTNode* pRoot, ifstream& fileStream) //
//{
//	cout << "Morse Pointer: " << pRoot << endl;
//	fileStream.open("MorseTable.txt");
//
//	//Plus a good softerware principle, each function shouldo one task!!!, here insert func should be implemented only
//	// for a new piece of data we get from parameters as arguments.
//	// so in the recursive function do not' use iteration!!!!
//	while (!fileStream.eof()) //when this func is called recursively, another version of the while loop is called  //
//	{
//		//BSTNode* pMem = new BSTNode(fileStream); //should allocate when finding the right targey
//		//if you allocate space here!! when search goes through subtrees, a recursive fucn will be called.
//		//however, we get lose track of the old pMem we createed from the previous call.
//		//we should move the code only when inserting!!!!! that way we never lose track of it.
//
//
//		if (pRoot == nullptr) //base case if root ptr is nullptr!!
//		{
//			this->pRoot = pMem; //local param  is it or a private member
//			//if get rid of this->  it will confuse!!that is it talking about the private member or a parameter!!!!
//
//		}
//
//		else
//		{
//			if (pMem->get_EnglishCharacter() < pRoot->get_EnglishCharacter()) //goes to the left subtree
//			{
//				if (pRoot->get_pLeft() == nullptr)
//				{
//					//allocate the pMe
//					BSTNode* pMem = new BSTNode(fileStream);
//					pRoot->set_pLeft(pMem); //i can also allocate with and passit without making pMem
//				}
//
//				else
//				{
//					insert(pRoot->get_pLeft(), fileStream);
//				}
//
//			}
//
//			else if (pMem->get_EnglishCharacter() > pRoot->get_EnglishCharacter()) //goes to the right subtree
//			{
//				if (pRoot->get_pRight() == nullptr)
//				{
//					pRoot->set_pRight(pMem);
//				}
//
//				else
//				{
//					insert(pRoot->get_pRight(), fileStream);
//				}
//
//			}
//
//		}
//
//	}
//	//this->pRoot = pRoot;
//	
//	//print(pRoot); //printing the tree!!!
//	//fileStream.close();
//}



/********************************************************************************************************************
* Function: search() template <class T, class U, class I>
* Description: It inserts a tree node that contains data into the binary search search. This will be used for constructing
*              a binary search tree.
* Input parameters: pRoot: a root BSTNode pointer.
*                   inputENglishChar: from MorseTable.txt
* Returns: matchMorseCode: a corresponding morse code from MorseTable.txt
*********************************************************************************************************************/
template <class T, class U, class I>
U BST<T,U,I>::search(BSTNode<T,U>* pRoot, T inputEnglishCharacter)
{
	U matchMorseCode = "";


	if (pRoot->get_EnglishCharacter() != inputEnglishCharacter)
	{
		if (pRoot->get_EnglishCharacter() > inputEnglishCharacter)  //go to the left subtree //now we have sort of new updated pRoot
		{

			return search(pRoot->get_pLeft(), inputEnglishCharacter) /*+ 1*/;
		}

		else if (pRoot->get_EnglishCharacter() < inputEnglishCharacter) //go to the right subtree
		{
			return search(pRoot->get_pRight(), inputEnglishCharacter) /*+ 1*/;
		}

	}

	else if (pRoot->get_EnglishCharacter() == inputEnglishCharacter) //base case
	{
		matchMorseCode = pRoot->get_MorseCode();
		//cout << tempMorseCode << "   ";
		return matchMorseCode;          //base case will return 0;
	}

}




/********************************************************************************************************************
* Function: print() template <class T, class U, class I>
* Description: It prints the contents node of the search binary tree by an inorder traversal.
* Input parameters: pRoot: a root BSTNode pointer.
* Returns: Nothing
*********************************************************************************************************************/
//in order traversal!!!!
template <class T, class U, class I>
void BST<T,U,I>::print(BSTNode<T,U>* pRoot) //is it for printing the tree?? for visualization?? yes
{
	if (pRoot != nullptr)
	{
		print(pRoot->get_pLeft());
		cout << pRoot->get_EnglishCharacter() << " " << pRoot->get_MorseCode() << endl;
		print(pRoot->get_pRight());

	}

}