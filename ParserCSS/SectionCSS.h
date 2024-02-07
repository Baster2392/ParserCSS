#pragma once
#include <iostream>
#include "ListString.h"

using namespace std;

class SectionCSS
{
private:
	ListString* selectors;
	ListString* attributes;
	ListString* values;

public:
	SectionCSS();
	SectionCSS(const SectionCSS& section);
	SectionCSS(const SectionCSS&& section);
	~SectionCSS();

	bool equal(const SectionCSS* section);
	void addSelector(const char* str);
	void addAttribute(const char* str);
	void addValue(const char* str);
	void deleteSelector(const char* str);
	void deleteAttribute(const char* str);
	void deleteValue(const char* str);
	void deleteSelectorAtPosition(int index);
	void deleteAttributeAtPosition(int index);
	void deleteValueAtPosition(int index);
	char* getSelectorAtPosition(int i);
	char* getAttributeAtPosition(int i);
	char* getValueAtPosition(int i);
	int getNumberOfSelectors();
	int getNumberOfAttributes();
	int getNumbersOfValues();
	int getIndexOfSelector(const char* str);
	int getIndexOfAttribute(const char* str);
	int getIndexOfValue(const char* str);
	int getIndexOfSelectorFromBack(const char* str);
	void replaceValue(int index, const char* newStr);
	void clearSection();

	ListString* getSelectorsList();
	ListString* getAttributesList();
	ListString* getValuesList();
};

