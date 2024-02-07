#include "String.h"

String::~String()
{
	if (this->chars != nullptr)
	{
		delete[] this->chars;
	}
}

char* String::get()
{
	return this->chars;
}

int String::getSize()
{
	return this->size;
}

bool String::equal(const char* str)
{
	if (this->size != strlen(str))
	{
		return false;
	}

	for (int i = 0; i < this->size; i++)
	{
		if (this->chars[i] != str[i])
		{
			return false;
		}
	}

	return true;
}

void String::addChar(char c)
{
	this->size++;
	char* newChars = new char[this->size + 1];

	for (int i = 0; i < this->size - 1; i++)
	{
		newChars[i] = chars[i];
	}

	newChars[this->size - 1] = c;
	newChars[this->size] = '\0';

	if (chars != nullptr)
	{
		delete[] this->chars;
	}

	this->chars = newChars;
}

void String::removeWhiteCharacters()
{
	if (this->size == 0)
	{
		return;
	}

	int toDeleteLeft = 0, toDeleteRight = 0;

	for (int i = 0; i < this->size; i++)
	{
		if (isspace(this->chars[i]))
		{
			toDeleteLeft++;
		}
		else
		{
			break;
		}
	}

	if (toDeleteLeft == this->size)
	{
		if (this->chars != nullptr)
		{
			delete[] this->chars;
		}
		
		this->chars = new char[1];
		this->size = 0;
		this->chars[0] = '\0';
		return;
	}

	for (int i = this->size - 1; i >= 0; i--)
	{
		if (isspace(this->chars[i]))
		{
			toDeleteRight++;
		}
		else
		{
			break;
		}
	}

	char* newChars = new char[this->size - toDeleteLeft - toDeleteRight + 1];
	int j = 0;
	for (int i = toDeleteLeft; i < this->size - toDeleteRight; i++)
	{
		newChars[j] = this->chars[i];
		j++;
	}

	this->size = this->size - toDeleteLeft - toDeleteRight;

	if (chars != nullptr)
	{
		delete[] chars;
	}

	newChars[this->size] = '\0';
	this->chars = newChars;
}

void String::replaceString(char* str)
{
	if (this->chars != nullptr)
	{
		delete[] this->chars;
	}

	this->chars = str;
	this->size = strlen(str);
}

char* String::getSubstringTo(char c)
{
	int length = 0;
	for (int i = 0; i < this->size; i++)
	{
		if (this->chars[i] == c)
		{
			break;
		}

		length++;
	}

	char* substring = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		substring[i] = this->chars[i];
	}

	substring[length] = '\0';
	return substring;
}

char* String::getSubstringFrom(char c)
{
	int length = 0;
	for (int i = 0; i < this->size; i++)
	{
		if (this->chars[i] == c)
		{
			length++;
			break;
		}

		length++;
	}

	char* substring = new char[this->size - length + 1];

	int j = 0;
	for (int i = length; i < this->size; i++)
	{
		substring[j] = this->chars[i];
		j++;
	}

	substring[j] = '\0';
	return substring;
}

bool String::isNumber()
{
	for (int i = 0; i < this->size; i++)
	{
		if (!(this->chars[i] >= '0' && this->chars[i] <= '9'))
		{
			return false;
		}
	}

	return true;
}

int String::toInteger()
{
	int integer = 0;
	for (int i = 0; i < this->size; i++)
	{
		integer += (this->chars[this->size - i - 1] - 48) * pow(10, i);
	}

	return integer;
}

String::String()
{
	this->chars = new char[1];
	this->chars[0] = '\0';
	this->size = 0;
}

String::String(const char* str)
{
	this->size = strlen(str);
	this->chars = new char[this->size + 1];

	for (int i = 0; i < this->size; i++)
	{
		this->chars[i] = str[i];
	}

	this->chars[this->size] = '\0';
}

char String::operator[](int index)
{
	return chars[index];
}

char* String::operator=(const char* str)
{
	if (this->chars != nullptr)
	{
		delete[] this->chars;
	}

	this->size = strlen(str);
	this->chars = new char[this->size + 1];

	for (int i = 0; i < this->size; i++)
	{
		this->chars[i] = str[i];
	}

	this->chars[this->size] = '\0';

	return this->chars;
}

char* String::operator=(String str)
{
	if (this->chars != nullptr)
	{
		delete[] this->chars;
	}

	this->chars = str.chars;
	this->size = str.size;

	return this->chars;
}
