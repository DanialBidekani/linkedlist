/*
 * this code is written by ---> danial bidekani :)
 * it implements linked list and all of the function
 * which user may need to use.
 * i wrote this code last year and i add a little
 * modification on it on Aug 22 2016
 *
 */

#include <iostream>

class node{
	friend class linkedList;
private:
	int data; // it preserve data in node
	node *next; // it refers to next node

// functions declaration area
public:
	node(void );
	node(int element );
	node(int element, node* next );
	int getData(void );
	node* getNext(void );
};


class linkedList{
private:
	node *head; // it refers to the first node in linked list
	unsigned int size; // it keeps the size of the linked list

// functions declaration area
public:
	linkedList(void);
	linkedList(int);
	~linkedList(void);
	void traverse(void);
	void append(int);
	void insert(int);
	void addBefore(int, int);
	void addAfter(int, int);
	void clear(void);
	void deleteNode(int );
	void removeFirst(void );
	void removeLast(void );
	void removeAfter(int );
	void removeBefore(int ); // not implemented yet
	void reverse(void );
	void toArray(int[], int );
	void set(int, int); // not implemented yet
	void sort();
	void unify();
	void sortedInsert(int ); // not implemented yet
	void shuffleMerge(linkedList ); // not implemented yet
	void sortedMerge(linkedList ); // not implemented yet
	int indexOf(int );
	int get(unsigned int );
	int getSize(void );
	int getFirst(void );
	int getLast(void );
	int contains(int );
	int pop(void );
	bool isEmpty(void );
};
