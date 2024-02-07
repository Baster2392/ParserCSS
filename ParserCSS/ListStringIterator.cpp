#include "ListStringIterator.h"

ListStringIterator::ListStringIterator(ListString* list, int listSize)
{
	this->list = list;
	this->listSize = listSize;
	this->currentNode = list->list;
	this->currentIndex = -1;
	this->currentNodeIndex = -1;
}

String* ListStringIterator::getNextItem()
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
		if (this->currentNodeIndex == ARRAY_SIZE_STRING)
		{
			this->currentNode = this->currentNode->next;
			this->currentNodeIndex = 0;
		}

		if (this->currentNode == nullptr)
		{
			std::cout << "Error" << std::endl;
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

String* ListStringIterator::getCurrentItem()
{
	return this->currentNode->values[this->currentNodeIndex];
}

int ListStringIterator::getCurrentIndex()
{
	return this->currentIndex;
}

bool ListStringIterator::nextExist()
{
	return false;
}
