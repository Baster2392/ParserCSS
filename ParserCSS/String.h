#pragma once
#include <string.h>
#include <iostream>
#include <ctype.h>
#include <math.h>

class String
{
private:
	char* chars;
	size_t size;

public:
	String();
	String(const char* str);
	~String();

	char* get();
	int getSize();
	bool equal(const char* str);
	void addChar(char c);
	void removeWhiteCharacters();
	void replaceString(char* str);
	char* getSubstringTo(char c);
	char* getSubstringFrom(char c);
	bool isNumber();
	int toInteger();

	char operator[](int index);
	char* operator=(const char* str);
	char* operator=(String str);
};

