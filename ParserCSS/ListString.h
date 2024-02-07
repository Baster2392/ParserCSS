#pragma once
#include "String.h"
#define ARRAY_SIZE_STRING 4

struct NodeStr
{
	int size;
	String* values[ARRAY_SIZE_STRING];
	NodeStr* prev, *next;
};

class ListString
{
	friend class ListStringIterator;

protected:
	int size;
	NodeStr* list;

	NodeStr* createNewNode();
	NodeStr* createNewNodeAtEnd();
	void addItemToNode(NodeStr* node, const char* str);
	String* getItemFromNodeAtPosition(NodeStr* node, int index);
	void deleteNode(NodeStr* node);
	void deleteItemFromNodeAtPosition(NodeStr* node, int index);

public:
	ListString();
	~ListString();

	int getSize();

	void pushBack(const char* str);
	String* getItemAtPosition(int index);
	int getIndexOf(const char* str);
	int getIndexOfFromBack(const char* str);
	void replace(int index, const char* newStr);
	void deleteItem(const char* str);
	void deleteItemAtPosition(int index);
};

