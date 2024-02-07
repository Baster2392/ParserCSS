#include "SectionCSS.h"

SectionCSS::SectionCSS()
{
	this->selectors = new ListString();
	this->attributes = new ListString();
	this->values = new ListString();
}

SectionCSS::SectionCSS(const SectionCSS& section)
{
	this->selectors = new ListString();
	this->attributes = new ListString();
	this->values = new ListString();

	for (int i = 0; i < section.selectors->getSize(); i++)
	{
		this->selectors->pushBack(section.selectors->getItemAtPosition(i)->get());
	}

	for (int i = 0; i < section.attributes->getSize(); i++)
	{
		this->attributes->pushBack(section.attributes->getItemAtPosition(i)->get());
	}

	for (int i = 0; i < section.values->getSize(); i++)
	{
		this->values->pushBack(section.values->getItemAtPosition(i)->get());
	}
}

SectionCSS::SectionCSS(const SectionCSS&& section)
{
	this->selectors = new ListString();
	this->attributes = new ListString();
	this->values = new ListString();

	for (int i = 0; i < section.selectors->getSize(); i++)
	{
		this->selectors->pushBack(section.selectors->getItemAtPosition(i)->get());
	}

	for (int i = 0; i < section.attributes->getSize(); i++)
	{
		this->attributes->pushBack(section.attributes->getItemAtPosition(i)->get());
	}

	for (int i = 0; i < section.values->getSize(); i++)
	{
		this->values->pushBack(section.values->getItemAtPosition(i)->get());
	}
}

SectionCSS::~SectionCSS()
{
	delete selectors;
	delete attributes;
	delete values;
}

bool SectionCSS::equal(const SectionCSS* section)
{
	return this->selectors == section->selectors && this->attributes == section->attributes && this->values == values;
}

void SectionCSS::addSelector(const char* str)
{
	this->selectors->pushBack(str);
}

void SectionCSS::addAttribute(const char* str)
{
	this->attributes->pushBack(str);
}

void SectionCSS::addValue(const char* str)
{
	this->values->pushBack(str);
}

void SectionCSS::deleteSelector(const char* str)
{
	this->selectors->deleteItem(str);
}

void SectionCSS::deleteAttribute(const char* str)
{
	this->attributes->deleteItem(str);
}

void SectionCSS::deleteValue(const char* str)
{
	this->values->deleteItem(str);
}

void SectionCSS::deleteSelectorAtPosition(int index)
{
	this->selectors->deleteItemAtPosition(index);
}

void SectionCSS::deleteAttributeAtPosition(int index)
{
	this->attributes->deleteItemAtPosition(index);
}

void SectionCSS::deleteValueAtPosition(int index)
{
	this->values->deleteItemAtPosition(index);
}

char* SectionCSS::getSelectorAtPosition(int i)
{
	return this->selectors->getItemAtPosition(i)->get();
}

char* SectionCSS::getAttributeAtPosition(int i)
{
	return this->attributes->getItemAtPosition(i)->get();
}

char* SectionCSS::getValueAtPosition(int i)
{
	return this->values->getItemAtPosition(i)->get();
}

int SectionCSS::getNumberOfSelectors()
{
	return this->selectors->getSize();
}

int SectionCSS::getNumberOfAttributes()
{
	return this->attributes->getSize();
}

int SectionCSS::getNumbersOfValues()
{
	return this->values->getSize();
}

int SectionCSS::getIndexOfSelector(const char* str)
{
	return this->selectors->getIndexOf(str);
}

int SectionCSS::getIndexOfAttribute(const char* str)
{
	return this->attributes->getIndexOf(str);
}

int SectionCSS::getIndexOfValue(const char* str)
{
	return this->values->getIndexOf(str);
}

int SectionCSS::getIndexOfSelectorFromBack(const char* str)
{
	return this->selectors->getIndexOfFromBack(str);
}

void SectionCSS::replaceValue(int index, const char* newStr)
{
	this->values->replace(index, newStr);
}

void SectionCSS::clearSection()
{
	delete this->attributes;
	delete this->selectors;
	delete this->values;

	this->selectors = new ListString();
	this->attributes = new ListString();
	this->values = new ListString();
}

ListString* SectionCSS::getSelectorsList()
{
	return this->selectors;
}

ListString* SectionCSS::getAttributesList()
{
	return this->attributes;
}

ListString* SectionCSS::getValuesList()
{
	return this->values;
}
