#include "ListString.h"

NodeStr* ListString::createNewNode()
{
	NodeStr* node = new NodeStr();
	node->size = 0;
	node->next = nullptr;
	node->prev = nullptr;

	for (int i = 0; i < ARRAY_SIZE_STRING; i++)
	{
		node->values[i] = nullptr;
	}

	return node;
}

NodeStr* ListString::createNewNodeAtEnd()
{
	NodeStr* newNode = createNewNode();
	this->list->prev->next = newNode;
	newNode->prev = this->list->prev;
	this->list->prev = newNode;

	return newNode;
}

void ListString::addItemToNode(NodeStr* node, const char* str)
{
	for (int i = ARRAY_SIZE_STRING - 1; i > 0; i--)
	{
		if (node->values[i] == nullptr && node->values[i - 1] != nullptr)
		{
			node->values[i] = new String(str);
			node->size++;
			return;
		}
	}

	node->values[0] = new String(str);
	node->size++;
}

String* ListString::getItemFromNodeAtPosition(NodeStr* node, int index)
{
	if (index >= node->size)
	{
		return nullptr;
	}

	for (int i = 0; i < ARRAY_SIZE_STRING; i++)
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

void ListString::deleteNode(NodeStr* node)
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

	for (int i = 0; i < ARRAY_SIZE_STRING; i++)
	{
		if (node->values[i] != nullptr)
		{
			delete node->values[i];
		}
	}

	delete node;
}

void ListString::deleteItemFromNodeAtPosition(NodeStr* node, int index)
{
	for (int i = 0; i < ARRAY_SIZE_STRING; i++)
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

ListString::ListString()
{
	this->size = 0;
	this->list = createNewNode();
	this->list->prev = this->list;
}

ListString::~ListString()
{
	NodeStr* currentNode = this->list, * toDelete = nullptr;
	while (currentNode != nullptr)
	{
		for (int i = 0; i < ARRAY_SIZE_STRING; i++)
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

int ListString::getSize()
{
	return size;
}

void ListString::pushBack(const char* str)
{
	if (this->list->prev->size == ARRAY_SIZE_STRING)
	{
		NodeStr* newNode = createNewNodeAtEnd();
		addItemToNode(newNode, str);
		this->size++;
	}
	else
	{
		addItemToNode(this->list->prev, str);
		this->size++;
	}
}

String* ListString::getItemAtPosition(int index)
{
	NodeStr* currentNode = this->list;
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

int ListString::getIndexOf(const char* str)
{
	NodeStr* currentNode = this->list;
	int index = 0;
	while (currentNode != nullptr)
	{
		for (int i = 0; i < ARRAY_SIZE_STRING; i++)
		{
			if (currentNode->values[i] != nullptr)
			{
				if (currentNode->values[i]->equal(str))
				{
					return index;
				}

				index++;
			}
		}

		currentNode = currentNode->next;
	}

	return -1;
}

int ListString::getIndexOfFromBack(const char* str)
{
	NodeStr* currentNode = this->list->prev;
	while (true)
	{
		for (int i = currentNode->size - 1; i >= 0; i--)
		{
			if (currentNode->values[i] != nullptr)
			{
				if (currentNode->values[i]->equal(str))
				{
					return i;
				}
			}
		}

		if (currentNode == this->list)
		{
			break;
		}

		currentNode = currentNode->prev;
	}

	return -1;
}

void ListString::replace(int index, const char* newStr)
{
	NodeStr* currentNode = this->list;
	while (currentNode != nullptr)
	{
		if (currentNode->size < index + 1)
		{
			index -= currentNode->size;
		}
		else
		{
			for (int i = 0; i < index + 1; i++)
			{
				if (currentNode->values[i] == nullptr)
				{
					index++;
				}
			}

			*currentNode->values[index] = newStr;
		}

		currentNode = currentNode->next;
	}
}

void ListString::deleteItem(const char* str)
{
	NodeStr* currentNode = this->list;
	while (currentNode != nullptr)
	{
		for (int i = 0; i < ARRAY_SIZE_STRING; i++)
		{
			if (currentNode->values[i] != nullptr)
			{
				if (currentNode->values[i]->equal(str))
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

void ListString::deleteItemAtPosition(int index)
{
	NodeStr* currentNode = this->list;
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
			break;
		}

		currentNode = currentNode->next;
	}
}


