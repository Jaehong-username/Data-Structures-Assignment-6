#include "MorseCodeConversion.h"

//MorseCodeConversion::MorseCodeConversion()
//{
//}
//
//MorseCodeConversion::~MorseCodeConversion()
//{
//}
//
//void MorseCodeConversion::charToMorseCode(BST& sarchingTree, ifstream& fileStream)
//{
//	int i = 0;
//	char tempLine[100];
//	char dummyCharToConvert = NULL;
//	string dummyMorseCodeConverted = "";
//
//	fileStream.open("Convert.txt");
//
//
//	while (!fileStream.eof())
//	{
//		fileStream.getline(tempLine, 100);
//		cout << "An English Sentence (Before Morse code conversion): " << tempLine << endl;
//
//		cout << "Morse code converted: ";
//
//		while (tempLine[i] != '\0')
//		{	
//			dummyCharToConvert = toupper(tempLine[i]);
//			if (dummyCharToConvert == ' ')
//			{
//				do
//				{
//					cout << dummyCharToConvert;
//					i++;
//					dummyCharToConvert = toupper(tempLine[i]); //redefine!!!!
//				} while (dummyCharToConvert == ' ');
//				
//				cout << " ";
//				if (dummyCharToConvert == '\0') break;
//			}
//			dummyMorseCodeConverted = sarchingTree.search(sarchingTree.get_pRoot(), dummyCharToConvert);
//			cout << dummyMorseCodeConverted << " ";
//			i++;
//		} 
//
//		i = 0;
//		cout << endl << endl;
//	}
//
//	fileStream.close();
//}
//
//void MorseCodeConversion::runMorseCodeConversion()
//{
//	BST morseLookupBST(fileStreamMorseTable); //BST constructor is invoked!!!!
//	
//	//fileStreamMorseTable.open("MorseTable.txt"); //open the file  //at least file is opened!!!
//	//morseLookupBST.insert(morseLookupBST.get_pRoot(), fileStreamMorseTable); //make a search tree!!!!
//	//fileStreamMorseTable.close();
//
//  cout << "Welcome to the Conversion To Morse Code Program!!!" << endl << endl;
//	//cout << "pRoot BST tree pointer: " << morseLookupBST.get_pRoot() << endl << endl;
//	cout << "Binary Search Tree English Character - Morse Code " << endl << endl;
//
//	morseLookupBST.print(morseLookupBST.get_pRoot()); //printing the tree!!!
// 
//	cout << endl;
//	charToMorseCode(morseLookupBST, fileStreamConvert);
//
//}

//ifstream& operator>>(ifstream& fileStream, char dummyCharToConvert)
//{
//	//char tempLine[100] = "";
//	//fileStream.get(tempLine, 100);
//	//dummyCharToConvert = toupper(*strtok(tempLine, " ")); //since strtok returns a string which is a ptr to first char of an array.
//	////thatis why you need a * sign infront of strtok to dereference!!!
//	//strtok(NULL, "\n");
//	//fileStream.get(dummyCharToConvert);
//
//}

//ostream& operator<<(ostream& screen, string morseCodeToScreen)
//{
//	//screen << morseCodeToScreen;
//}
