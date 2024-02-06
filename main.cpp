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

#include "MorseCodeConversion.h"


int main(void)
{
	//Non-template
	/*MorseCodeConversion morse_code_conversion_program;
	morse_code_conversion_program.runMorseCodeConversion();*/

	//template
	MorseCodeConversion<char, string, ifstream> morse_code_conversion_program;
	morse_code_conversion_program.runMorseCodeConversion();

	return 0;
}