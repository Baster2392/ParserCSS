#include "String.h"
#include "ListString.h"
#include "SectionCSS.h"
#include "ListSection.h"
#include "Commands.h"
#include "ListStringIterator.h"
#include "ListSectionIterator.h"

#define SELECTORS 1
#define ATTRIBUTES 2
#define COMMENDS 3

using namespace std;

void inputCommand(String* input, ListSection* listSection)
{
    if (input->equal("?"))
    {
        printf("? == %d\n", listSection->getSize());
        return;
    }

    String arg1, arg3;
    char arg2;
    int i = 0;
    while ((*input)[i] != ',')
    {
        arg1.addChar((*input)[i]);
        i++;
    }
    i++;
    arg2 = (*input)[i];
    i += 2;

    while (i < input->getSize())
    {
        arg3.addChar((*input)[i]);
        i++;
    }

    switch (arg2)
    {
    case 'S':
        Scommand(&arg1, &arg3, listSection, input);
        break;

    case 'A':
        Acommand(&arg1, &arg3, listSection, input);
        break;

    case 'E':
        Ecommand(&arg1, &arg3, listSection, input);
        break;

    case 'D':
        Dcommand(&arg1, &arg3, listSection, input);
        break;
    }
}

void addAttribute(String* newItem, SectionCSS* section)
{
    String str;
    str = newItem->get();
    str.removeWhiteCharacters();

    if (str.getSize() == 0)
    {
        return;
    }

    str.replaceString(newItem->getSubstringTo(':'));
    str.removeWhiteCharacters();

    int index = section->getIndexOfAttribute(str.get());

    if (index != -1)
    {
        section->deleteAttributeAtPosition(index);
        section->deleteValueAtPosition(index);
    }

    section->addAttribute(str.get());
    str.replaceString(newItem->getSubstringFrom(':'));
    str.removeWhiteCharacters();
    section->addValue(str.get());
}

void addSelector(String* newItem, SectionCSS* section)
{
    newItem->removeWhiteCharacters();

    if (newItem->getSize() == 0)
    {
        return;
    }

    int index = section->getIndexOfSelector(newItem->get());
    if (index != -1)
    {
        return;
    }

    section->addSelector(newItem->get());
}

void input()
{
    int size = 0, index = 0;
    int inputState = SELECTORS;
    ListSection listSection;
    SectionCSS section;
    String line, newItem;
    char input[1024];
    while (cin.getline(input, 1024))
    {
        line = input;
        size = line.getSize();

       if (line.getSize() == 0)
       {
           continue;
       }

        if (line.equal("????"))
        {
            inputState = COMMENDS;
            continue;
        }
        else if (inputState == COMMENDS && line.equal("****"))
        {
            inputState = SELECTORS;
            continue;
        }
        else if (inputState == COMMENDS)
        {
            inputCommand(&line, &listSection);
        }

        for (int i = 0; i < size; i++)
        {
            if (inputState == SELECTORS)
            {
                if (line[i] == '{')
                {
                    inputState = ATTRIBUTES;
                    if (newItem.getSize() != 0)
                    {
                        addSelector(&newItem, &section);
                        newItem = "";
                        continue;
                    }
                }
                else if (line[i] == ',')
                {
                    if (newItem.getSize() != 0)
                    {
                        addSelector(&newItem, &section);
                        newItem = "";
                    }
                }
                else if (i == size - 1)
                {
                    newItem.addChar(line[i]);
                    addSelector(&newItem, &section);
                    newItem = "";
                }
                else
                {
                    newItem.addChar(line[i]);
                }
            }

            if (inputState == ATTRIBUTES)
            {
                if (line[i] == '}')
                {
                    inputState = SELECTORS;
                    if (newItem.getSize() != 0)
                    {
                        addAttribute(&newItem, &section);
                    }

                    listSection.pushBack(&section);
                    section.clearSection();
                    newItem = "";
                }
                else if (line[i] == ';')
                {
                    if (newItem.getSize() != 0)
                    {
                        addAttribute(&newItem, &section);
                        newItem = "";
                        continue;
                    }
                }
                else if (i == size - 1 && line[i] != '{')
                {
                    newItem.addChar(line[i]);
                    addAttribute(&newItem, &section);
                    newItem = "";
                }
                else if (line[i] != '{')
                {
                    newItem.addChar(line[i]);
                }
            }
        }
    }
}

int main()
{
    input();
    return 0;
}
