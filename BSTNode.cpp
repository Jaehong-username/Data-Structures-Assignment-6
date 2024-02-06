#include "BSTNode.h"

//BSTNode::BSTNode(char inputEnglishChar, string inputMorseCode)
//{
//    this->EnglishCharacter = inputEnglishChar;
//    this->MoresCode = inputMorseCode;
//    this->pLeft = nullptr;
//    this->pRight = nullptr;
//}
//
//char BSTNode::get_EnglishCharacter()
//{
//    return EnglishCharacter;
//}
//
//
//
//string BSTNode::get_MorseCode()
//{
//    return MoresCode;
//}
//
//BSTNode* BSTNode::get_pLeft()
//{
//    return this->pLeft; //this current obj
//}
//
//BSTNode* BSTNode::get_pRight()
//{
//    return this->pRight;
//}
//
//void BSTNode::set_EnglishCharacter(char new_EnglishCharacter)
//{
//    EnglishCharacter = new_EnglishCharacter;
//}
//
//void BSTNode::set_MoreseCode(string new_MorseCode)
//{
//    MoresCode = new_MorseCode;
//}
//
//void BSTNode::set_pLeft(BSTNode* new_pLeft)
//{
//    this->pLeft = new_pLeft;
//}
//
//void BSTNode::set_pRight(BSTNode* new_pRight)
//{
//    this->pRight = new_pRight;
//}
//
//
//
//
//
//
////but provide a label!!! comes handy when it comes to dealing with big data like nodes.
////not copy of an object but provide a label that represent the original
//
////extraction operator overloaded!!!          //passed by ref implicit conversion is not allowed
//ifstream& operator>>(ifstream& fileStream, BSTNode& tree_node)
//{
//    char tempLine[100] = "";
//    fileStream.getline(tempLine, 100); //extracts a line from an input file including the newline in the file
//
//    tree_node.set_EnglishCharacter(*strtok(tempLine, " "));  //array of char string deerefernced get a single char
//    tree_node.set_MoreseCode(strtok(NULL, "\n"));
//   
//    return fileStream; //function chaining is possible!!!!
//}
//
//
////fileStream >> (char) c >> (string) string;
////newline char and a white space fall underbrella  \t  \n whte space
////loop >> insert function