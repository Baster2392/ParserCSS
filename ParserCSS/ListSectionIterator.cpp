#include "ListSectionIterator.h"

ListSectionIterator::ListSectionIterator(ListSection* list, int listSize)
{
	this->list = list;
	this->listSize = listSize;
	this->currentNode = list->list;
	this->currentIndex = -1;
	this->currentNodeIndex = -1;
}

SectionCSS* ListSectionIterator::getNextItem()
{
	this->currentIndex++;

	if (this->currentIndex >= this->listSize)
	{
		std::cout << "Error" << std::endl;
		return nullptr;
	}

	this->currentNodeIndex++;

	while (true)
	{
		if (this->currentNodeIndex == ARRAY_SIZE_SECTION)
		{
			this->currentNode = this->currentNode->next;
			this->currentNodeIndex = 0;
		}

		if (this->currentNode == nullptr)
		{
			return nullptr;
		}

		if (this->currentNode->values[this->currentNodeIndex] != nullptr)
		{
			break;
		}

		this->currentNodeIndex++;
	}

	return this->currentNode->values[this->currentNodeIndex];
}

SectionCSS* ListSectionIterator::getCurrentItem()
{
	return this->currentNode->values[this->currentNodeIndex];
}

int ListSectionIterator::getCurrentIndex()
{
	return this->currentIndex;
}

bool ListSectionIterator::nextExist()
{
	return false;
}
