#include "BST.h"


//BST::BST(ifstream& fileStream) //once its called it will make the entire binary search tree based on the input txt file stream passed in
//{
//	pRoot = nullptr;
//
//	fileStream.open("MorseTable.txt"); //open the file first!!!
//	//dummy variable will act as a place holder!!!!
//	BSTNode dummyNode(NULL, "");
//	char dummyEnglishChar = NULL;
//	string dummyMorseCode = "";
//
//	while (!fileStream.eof()) //as long as not reached to the end of file
//	{
//		fileStream >> dummyNode;
//
//		dummyEnglishChar = dummyNode.get_EnglishCharacter();
//		dummyMorseCode = dummyNode.get_MorseCode();
//
//		insert(pRoot, dummyEnglishChar, dummyMorseCode);
//	}
//
//	fileStream.close();//close the file
//}
//
// 
// 
//BST::~BST()
//{
//	destroyBST(pRoot);
//}
//
//
//void BST::destroyBST(BSTNode* pRoot)
//{
//	/*if (pRoot == nullptr)
//	{
//		delete pRoot;
//		cout << "destructor for pRoot!" << endl;
//	}*/
//
//	//else
//	//{
//		if (pRoot->get_pLeft() != nullptr)
//		{
//			destroyBST(pRoot->get_pLeft());
//		}
//
//		/*else
//		{
//			cout << "Destructor for a tree node cotaining: " << pRoot->get_EnglishCharacter() << "  " << pRoot->get_MorseCode() << endl;
//			delete pRoot;
//		}*/
//
//		if (pRoot->get_pRight() != nullptr)
//		{
//			destroyBST(pRoot->get_pRight());
//		}
//
//		/*else
//		{
//			cout << "Destructor for a tree node cotaining: " << pRoot->get_EnglishCharacter() << "  " << pRoot->get_MorseCode() << endl;
//			delete pRoot;
//		}*/
//
//		cout << "Destructor for a tree node cotaining: "<< pRoot->get_EnglishCharacter() << "  " << pRoot->get_MorseCode() << endl;
//		delete pRoot;
//	//}
//}
//
//
//
//BSTNode* BST::get_pRoot()
//{
//	return pRoot;
//}
//
//void BST::insert(char inputEnglishChar, string morseCode)
//{
//	insert(this->pRoot, inputEnglishChar, morseCode);
//}
//
//
//
//
////passing a the whole node as a parameter is a bad practice!! //we dont need the whole node info only need
////an english char and its corresponding morse code string.
//void BST::insert(BSTNode* pRoot, char inputEnglishChar, string morseCode) 
//{
//	/*cout << "Morse Pointer: " << pRoot << endl;
//	fileStream.open("MorseTable.txt");*/
//
//	//Plus a good softerware principle, each function shouldo one task!!!, here insert func should be implemented only
//	// for a new piece of data we get from parameters as arguments.
//	// so in the recursive function do not' use iteration!!!!
//	//while (!fileStream.eof()) //when this func is called recursively, another version of the while loop is called  //
//	
//		//BSTNode* pMem = new BSTNode(fileStream); //should allocate when finding the right targey
//		//if you allocate space here!! when search goes through subtrees, a recursive fucn will be called.
//		//however, we get lose track of the old pMem we createed from the previous call.
//		//we should move the code only when inserting!!!!! that way we never lose track of it.
//
//
//		if (pRoot == nullptr) //base case if root ptr is nullptr!!
//		{
//			//BSTNode* pMem = new BSTNode(fileStream);
//			this->pRoot = new BSTNode(inputEnglishChar, morseCode); //local param  is it or a private member
//			//if get rid of this->  it will confuse!!that is it talking about the private member or a parameter!!!!
//
//		}
//
//		else
//		{
//			if (inputEnglishChar < pRoot->get_EnglishCharacter()) //goes to the left subtree
//			{
//				if (pRoot->get_pLeft() == nullptr)
//				{
//					//allocate the pMe
//					//BSTNode* pMem = new BSTNode(fileStream);
//					pRoot->set_pLeft(new BSTNode(inputEnglishChar, morseCode)); //i can also allocate with and passit without making pMem
//				}
//
//				else
//				{
//					insert(pRoot->get_pLeft(), inputEnglishChar, morseCode);
//				}
//
//			}
//
//			else if (inputEnglishChar > pRoot->get_EnglishCharacter()) //goes to the right subtree
//			{
//				if (pRoot->get_pRight() == nullptr)
//				{
//					pRoot->set_pRight(new BSTNode(inputEnglishChar, morseCode));
//				}
//
//				else
//				{
//					insert(pRoot->get_pRight(), inputEnglishChar, morseCode);
//				}
//
//			}
//
//		}
//
//	
//	//this->pRoot = pRoot;
//	//print(pRoot); //printing the tree!!!
//	//fileStream.close();
//}
//
//
//
//// wanna implement not relaese to the public
////
//
////making the tree!!!
////void BST::insert(BSTNode* pRoot, ifstream& fileStream) //
////{
////	cout << "Morse Pointer: " << pRoot << endl;
////	fileStream.open("MorseTable.txt");
////
////	//Plus a good softerware principle, each function shouldo one task!!!, here insert func should be implemented only
////	// for a new piece of data we get from parameters as arguments.
////	// so in the recursive function do not' use iteration!!!!
////	while (!fileStream.eof()) //when this func is called recursively, another version of the while loop is called  //
////	{
////		//BSTNode* pMem = new BSTNode(fileStream); //should allocate when finding the right targey
////		//if you allocate space here!! when search goes through subtrees, a recursive fucn will be called.
////		//however, we get lose track of the old pMem we createed from the previous call.
////		//we should move the code only when inserting!!!!! that way we never lose track of it.
////
////
////		if (pRoot == nullptr) //base case if root ptr is nullptr!!
////		{
////			this->pRoot = pMem; //local param  is it or a private member
////			//if get rid of this->  it will confuse!!that is it talking about the private member or a parameter!!!!
////
////		}
////
////		else
////		{
////			if (pMem->get_EnglishCharacter() < pRoot->get_EnglishCharacter()) //goes to the left subtree
////			{
////				if (pRoot->get_pLeft() == nullptr)
////				{
////					//allocate the pMe
////					BSTNode* pMem = new BSTNode(fileStream);
////					pRoot->set_pLeft(pMem); //i can also allocate with and passit without making pMem
////				}
////
////				else
////				{
////					insert(pRoot->get_pLeft(), fileStream);
////				}
////
////			}
////
////			else if (pMem->get_EnglishCharacter() > pRoot->get_EnglishCharacter()) //goes to the right subtree
////			{
////				if (pRoot->get_pRight() == nullptr)
////				{
////					pRoot->set_pRight(pMem);
////				}
////
////				else
////				{
////					insert(pRoot->get_pRight(), fileStream);
////				}
////
////			}
////
////		}
////
////	}
////	//this->pRoot = pRoot;
////	
////	//print(pRoot); //printing the tree!!!
////	//fileStream.close();
////}
//
//
////writre a function that will read one line at at item which I did in an overloaded operator!
//
//
//string BST::search(BSTNode* pRoot, char inputEnglishCharacter)
//{
//	string matchMorseCode = "";
//
//
//	if (pRoot->get_EnglishCharacter() != inputEnglishCharacter)
//	{
//		if (pRoot->get_EnglishCharacter() > inputEnglishCharacter)  //go to the left subtree //now we have sort of new updated pRoot
//		{
//			return search(pRoot->get_pLeft(), inputEnglishCharacter);
//		}
//
//		else if (pRoot->get_EnglishCharacter() < inputEnglishCharacter) //go to the right subtree
//		{
//			return search(pRoot->get_pRight(), inputEnglishCharacter);
//		}
//
//	}
//
//	else if (pRoot->get_EnglishCharacter() == inputEnglishCharacter) //base case
//	{
//		matchMorseCode = pRoot->get_MorseCode();
//		//cout << tempMorseCode << "   ";
//		return matchMorseCode;
//	}
//
//}
//
//
//
////in order traversal!!!!
//void BST::print(BSTNode* pRoot) //is it for printing the tree?? for visualization?? yes
//{
//	if (pRoot != nullptr)
//	{
//		print(pRoot->get_pLeft());
//		cout << pRoot->get_EnglishCharacter() << " " << pRoot->get_MorseCode() << endl;
//		print(pRoot->get_pRight());
//	
//	}
//
//}




////for or while loop!!!! << operator insert!!! within the func, we need a dummy variable that will act as a place holder.
////you can even make this in BST constructor!!!
////balanced tree rearrange in a way that not the worst case scenario in logn if its if its placed in alphabetical order
////is almost similart to linear sequence which the worst case scnario is when n