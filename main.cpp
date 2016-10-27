/*
*  this program is written by ---> danial bidekani
* and implements one of the famous algorithm called
* binary search in a unrecursive approach
* Fri Aug 19 2016, and it's gonna be legendary
*/
#include <iostream>
#include <iomanip>
#include "linkedList.h"

using namespace std;

// functions

int main()
{

try{
	linkedList me;

	cout<<me.getSize()<<endl;

	me.append(1);

	me.append(2);

	me.append(5);

	me.insert(3);

	me.addAfter(1, 4);

	me.traverse();

	me.sort();

	me.traverse();


	cout<<me.get(4)<<endl;

} catch(const char* msg)
{
	cout<<msg<<endl;
}



} // end main

// implementation functions area

