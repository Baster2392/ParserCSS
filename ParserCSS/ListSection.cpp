#include "ListSection.h"

NodeSection* ListSection::createNewNode()
{
	NodeSection* node = new NodeSection();
	node->size = 0;
	node->next = nullptr;
	node->prev = nullptr;

	for (int i = 0; i < ARRAY_SIZE_SECTION; i++)
	{
		node->values[i] = nullptr;
	}

	return node;
}

NodeSection* ListSection::createNewNodeAtEnd()
{
	NodeSection* newNode = createNewNode();
	this->list->prev->next = newNode;
	newNode->prev = this->list->prev;
	this->list->prev = newNode;

	return newNode;
}

void ListSection::addItemToNode(NodeSection* node, const SectionCSS* section)
{
	for (int i = 0; i < ARRAY_SIZE_SECTION; i++)
	{
		if (node->values[i] == nullptr)
		{
			node->values[i] = new SectionCSS(*section);
			node->size++;
			return;
		}
	}

	node->values[0] = new SectionCSS(*section);
	node->size++;
}

SectionCSS* ListSection::getItemFromNodeAtPosition(NodeSection* node, int index)
{
	if (index >= node->size)
	{
		return nullptr;
	}

	for (int i = 0; i < ARRAY_SIZE_SECTION; i++)
	{
		if (node->values[i] != nullptr)
		{
			index--;
		}

		if (index == -1)
		{
			return node->values[i];
		}
	}

	return nullptr;
}

void ListSection::deleteNode(NodeSection* node)
{
	node->prev->next = node->next;
	if (node->next != nullptr)
	{
		node->next->prev = node->prev;
	}
	else
	{
		this->list->prev = node->prev;
	}

	for (int i = 0; i < ARRAY_SIZE_SECTION; i++)
	{
		if (node->values[i] != nullptr)
		{
			delete node->values[i];
		}
	}

	delete node;
}

void ListSection::deleteItemFromNodeAtPosition(NodeSection* node, int index)
{
	for (int i = 0; i < ARRAY_SIZE_SECTION; i++)
	{
		if (node->values[i] != nullptr)
		{
			index--;
		}

		if (index == -1)
		{
			delete node->values[i];
			node->values[i] = nullptr;
			node->size--;
			break;
		}
	}

	if (node->size == 0 && node != this->list)
	{
		deleteNode(node);
	}
}


ListSection::ListSection()
{
	this->size = 0;
	this->list = createNewNode();
	this->list->prev = this->list;
}

ListSection::~ListSection()
{
	NodeSection* currentNode = this->list, *toDelete = nullptr;
	while (currentNode != nullptr)
	{
		for (int i = 0; i < ARRAY_SIZE_SECTION; i++)
		{
			if (currentNode->values[i] != nullptr)
			{
				delete currentNode->values[i];
			}
		}

		toDelete = currentNode;
		currentNode = currentNode->next;
		delete toDelete;
	}
}

int ListSection::getSize()
{
	return this->size;
}

void ListSection::pushBack(const SectionCSS* section)
{
	if (this->list->prev->size == ARRAY_SIZE_SECTION)
	{
		NodeSection* newNode = createNewNodeAtEnd();
		addItemToNode(newNode, section);
	}
	else
	{
		addItemToNode(this->list->prev, section);
	}

	this->size++;
}

SectionCSS* ListSection::getItemAtPosition(int index)
{
	NodeSection* currentNode = this->list;
	while (currentNode != nullptr)
	{
		if (currentNode->size < index + 1)
		{
			index -= currentNode->size;
		}
		else
		{
			return getItemFromNodeAtPosition(currentNode, index);
		}

		currentNode = currentNode->next;
	}

	return nullptr;
}

void ListSection::deleteItem(const SectionCSS* section)
{
	NodeSection* currentNode = this->list;
	while (currentNode != nullptr)
	{
		for (int i = 0; i < ARRAY_SIZE_SECTION; i++)
		{
			if (currentNode->values[i] != nullptr)
			{
				if (currentNode->values[i]->equal(section))
				{
					deleteItemFromNodeAtPosition(currentNode, i);
					this->size--;
					return;
				}
			}
		}

		currentNode = currentNode->next;
	}
}

void ListSection::deleteItemAtPosition(int index)
{
	NodeSection* currentNode = this->list;
	while (currentNode != nullptr)
	{
		if (currentNode->size < index + 1)
		{
			index -= currentNode->size;
		}
		else
		{
			deleteItemFromNodeAtPosition(currentNode, index);
			this->size--;
			return;
		}

		currentNode = currentNode->next;
	}
}
