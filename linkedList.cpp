#include <iostream>
#include "linkedList.h"
//-------------------------------------------->>>node(void )
// constructor function without argument
node::node(void )
{
	next = NULL;
	data = int();
}
//-------------------------------------------->>>node(int )
// constructor function with an element as a parameter
node::node(int element )
{
	data = element;
	next = NULL;
}
//-------------------------------------------->>>node(int, node* )
// constructor function with two parameter one of them as an element
// and the other as a node
node::node(int element, node* node )
{
	data = element;
	next = node;
}
//-------------------------------------------->>>getData(void )
// this function get the value of the node
int node::getData(void )
	{
		return data;
	}
//-------------------------------------------->>>getNext(void )
node* node::getNext(void )
{
	return this->next;
}
//-------------------------------------------->>>linkedList(void )
// constructor function without parameter
linkedList::linkedList(void )
{
	head = NULL;
	size = 0;
}
//-------------------------------------------->>>linkedList(int )
linkedList::linkedList(int recievedElement)
{
	head = new node(recievedElement);
	size = 1;
}
//-------------------------------------------->>>~linkedList(void )
// default destructor used for the improve the memory allocation
linkedList::~linkedList(void )
{
	node *p = head;
	node *q;

	if(head == NULL)
		return;

	while(p != NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}

	size = 0;
}
//-------------------------------------------->>>traverseAndPrint(void )
// this function traverses the nodes in the linked list in order and print
// their data in each step in a good format like a chain
// for example for three nodes A,B and C it print this:
// A ---> B ---> C
void linkedList::traverse(void )
{
	node *p = head;

	// this list is empty?
	if(head == NULL)
		throw "the list is empty.\n";

	// i print the first element here because i don't
	// want to use a condition on while loop which execute
	// several times.
	std::cout<<p->data;
	p = p->next;

	while(p != NULL)
	{
		std::cout<<" ---> ";
		std::cout<<p->data;
		p = p->next;

	}
	std::cout<<std::endl;
}
//-------------------------------------------->>>insert(int )
/* this function add an element at the end of the list.
 * time complexity of this is O(n). */
void linkedList::append(int element)
{
	node *newNode = new node (element);
	node *p = head;

	// if this is the first node
	if(head != NULL)
	{
		while(p->next != NULL)
			p = p->next;

		p->next = newNode;
	}
	else
		head = newNode;
	size++;

}
//-------------------------------------------->>>deleteNode(int )
// it deletes a node with an specific given element as a parameter
void linkedList::deleteNode(int element)
{
	if(head == NULL)
		throw "list is empty.\n";

	node *p = head;
	node *q;

	while(p != NULL && p->data != element)
	{
		q = p;
		p = p->next;
	}

	// if the node we want remove is the first
	if(p == head)
	{
		head = p->next;
		delete p;
	}
	// if there isn't a node with this value
	else if(p == NULL)
		return;
	else
	{
		q->next = p->next;
		delete p;
	}

	size--;
}
//-------------------------------------------->>>deleteAllNodes(void )
void linkedList::clear(void )
{
	if(head != NULL)
		while(head != NULL)
		{
			node *p = head;
			head = head->next;
			delete p;
			size--;
		}
}
//-------------------------------------------->>>deleteFirst(void )
void linkedList::removeFirst(void )
{
	if(head != NULL)
	{
		node* p = head;
		head = head->next;
		delete p;
		size--;
	}
	else
		throw "list is empty.\n";
}
//-------------------------------------------->>>getSize(void )
int linkedList::getSize(void )
{
	return this->size;
}
//-------------------------------------------->>>getFirstData(void )
int linkedList::getFirst(void )
{
	return this->head->data;
}
//-------------------------------------------->>>getLastData(void )
int linkedList::getLast(void )
{
	node *p = head;

	while(p->next != NULL)
		p = p->next;

	return p->data;
}
//-------------------------------------------->>>searchData(int )
/* this function give an element and traverse the list to find
 an element equals. it returns the position of element in the
 list and it counts the list from zero. and if the element is not
 in the list it returns -1.*/
int linkedList::contains(int element )
{
	node *p = head;
	int c = 0;
	while(p != NULL)
	{
		if(p->data == element)
			return c;
		p = p->next;
		c++;
	}
	return -1;
}
//-------------------------------------------->>>insert(int )
/* this function add a node at the beginning of the list.
 * time complexity of insert function is: O(1).
 */
void linkedList::insert(int element)
{
	node *p = new node(element);

	// check memory allocation
	if(!p)
		throw "allocation error.\n";

	if(this->head != NULL)
		p->next = head;

	head = p;
	this->size++;
}
//-------------------------------------------->>>reverseList(void )
// this is an approach for reverse a linked list. time complexity is O(n)
// and the idea is using two pointer rather than three :)
void linkedList::reverse(void )
{
	node *p = head;
	node *q = NULL;

	while(p->next != NULL)
	{
		p = p->next;
		head->next = q;

		q = head;
		head = p;
	}

	head->next = q;
}
//-------------------------------------------->>>deleteAfter(int )
void linkedList::removeAfter(int element)
{
	if(head != NULL)
	{
		node *p = head;


		while(p != NULL && p->data != element)
			p = p->next;

		if(p != NULL)
		{
			node *q;
			q = p->next;
			p->next = q->next;
			delete q;
			this->size--;
		}
	} // end outer if
	else throw "list is empty.\n";

}
//-------------------------------------------->>>removeLast()
void linkedList::removeLast()
{
	if(!this->isEmpty())
	{
		node *p = head;
		node *q;
		while(p->next != NULL)
		{
			q = p;
			p = p->next;
		}


		q->next = p->next;
		delete p;
		this->size--;
	}
	else
		throw "list is empty.\n";
}
//-------------------------------------------->>>addAfter(int, int )
/* this function add an element after a specific key in list
 * and if the key is not in the list it prints an error
 * to user.
 */
void  linkedList::addAfter(int key, int element)
{
	node *p = head;

	while( p != NULL)
	{
		if(p->data == key)
		{
			node *q = new node(element );
			q->next = p->next;
			p->next = q;
			this->size++;
			break;
		}
		p = p->next;
		if(p->next == NULL and p->data != key)
			std::cerr<<"key not founded in this list.\n";
	}

}
//-------------------------------------------->>>sort()
void linkedList::sort(void )
{
	node *q, *p = head;

	while(p != NULL)
	{
		q = p->next;
		while(q != NULL)
		{
			if(q->data < p->data)
				std::swap(p->data, q->data);
			q = q->next;
		}
		p = p->next;
	}
}

//-------------------------------------------->>>toArray(int[] )
void linkedList::toArray(int array[], int length)
{
	if(length == this->getSize())
	{
		node *p = head;
		int index = 0;
		while(p != NULL)
		{
			array[index] = p->data;
			index++;
			p = p->next;
		}
	}
}
//-------------------------------------------->>>isEmpty()
bool linkedList::isEmpty()
{
	if(head == NULL) return true;
	else return false;
}
//-------------------------------------------->>>indexOf(int )
/* this function return the index of an specific element
 * in the list. indexes in list begins from zero. */
int linkedList::indexOf(int element)
{
	int c = 0;
	node *cursor = head;

	while(cursor != NULL && cursor->data != element)
	{
		cursor = cursor->next;
		c++;
	}

	return c;

}
//-------------------------------------------->>>get(int )
/*
 *  this function give an element and return the index of that
 * if it exists in the list. if index is greater than the size
 * of the list it returns nothing.
 * you know, for a computer scientist everything begins from
 * zero.
 */
int linkedList::get(unsigned int index)
{
	if(index > size-1)
		throw "out of list.\n";
	node *p = head;

	while(index > 0)
	{
		p = p->next;
		index--;
	}

	return p->data;
}
//-------------------------------------------->>>unify()
/* this function unifies a list. if you have this list:
 * # 1 ---> 2 ---> 1 #
 *  and then you call the unify(), you will have this:
 * # 1 ---> 2 #
 * cause this function unifies the list.
 */
void linkedList::unify(void )
{
	node *p = head;
	node *q = head;
	node *holder;

	while(p != NULL)
	{
		q = p->next;
		holder = p;

		while(q != NULL)
		{
			if(p->data == q->data)
			{
				node *temp;
				temp = q;
				holder->next = q->next;
				q = holder->next;
				delete temp;
				this->size--;
			}
			else
			{
				holder = q;
				q = q->next;
			}
		} // end of inner while
		p = p->next;
	}
}

//-------------------------------------------->>>addBefore()
void linkedList::addBefore(int key, int element)
{
	node *p = head;
	node *newNode = new node(element);

	if(p->data == key)
	{
		newNode->next = this->head;
		head = newNode;
		this->size++;
	}
	else
	{
		while(p->next->data != key and p->next != NULL)
				p = p->next;

		if(p->next->data == key)
		{
			newNode->next = p->next;
			p->next = newNode;
			this->size++;
		}

	}// end else

}
//-------------------------------------------->>>pop()
/* this function remove the first node in linked list
 * and return it.
 */
int linkedList::pop(void)
{
	if(this->isEmpty())
		throw "list is empty.\n";
	else
	{
		int temp = head->data;
		removeFirst();
		return temp;
	}
}
//-------------------------------------------->>>shuffleMerge(linkedlist )
void linkedList::shuffleMerge(linkedList list)
{
	if(this->isEmpty())
	{
	}
}
//-------------------------------------------->>>shuffleMerge(linkedlist )
void linkedList::sortedInsert(int element)
{
	if(this->isEmpty())
		head = new node(element);
	else
	{

	}
}
