#pragma once
#include "SectionCSS.h"
#define ARRAY_SIZE_SECTION 15

struct NodeSection
{
	int size;
	SectionCSS* values[ARRAY_SIZE_SECTION];
	NodeSection* prev, *next;
};

class ListSection
{
	friend class ListSectionIterator;

protected:
	int size;
	NodeSection* list;

	NodeSection* createNewNode();
	NodeSection* createNewNodeAtEnd();
	void addItemToNode(NodeSection* node, const SectionCSS* section);
	SectionCSS* getItemFromNodeAtPosition(NodeSection* node, int index);
	void deleteNode(NodeSection* node);
	void deleteItemFromNodeAtPosition(NodeSection* node, int index);

public:
	ListSection();
	~ListSection();

	int getSize();

	void pushBack(const SectionCSS* section);
	SectionCSS* getItemAtPosition(int index);
	void deleteItem(const SectionCSS* section);
	void deleteItemAtPosition(int index);
};

