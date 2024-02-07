#pragma once
#include "ListString.h"

class ListStringIterator
{
private:

	ListString* list;
	NodeStr* currentNode;
	int listSize;
	int currentIndex;
	int currentNodeIndex;

public:

	ListStringIterator(ListString* list, int listSize);
	String* getNextItem();
	String* getCurrentItem();
	int getCurrentIndex();
	bool nextExist();
};

