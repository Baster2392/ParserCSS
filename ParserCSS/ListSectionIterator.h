#pragma once
#include "ListSection.h"

class ListSectionIterator
{
private:

	ListSection* list;
	NodeSection* currentNode;
	int listSize;
	int currentIndex;
	int currentNodeIndex;

public:

	ListSectionIterator(ListSection* list, int listSize);
	SectionCSS* getNextItem();
	SectionCSS* getCurrentItem();
	int getCurrentIndex();
	bool nextExist();
};

