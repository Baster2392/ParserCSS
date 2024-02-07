#include "Commands.h"
#include "ListStringIterator.h"
#include "ListSectionIterator.h"

void Scommand(String* arg1, String* arg3, ListSection* listSection, String* input)
{

    if (arg3->equal("?") && arg1->isNumber())
    {
        int sectionNumber = arg1->toInteger();
        if (listSection->getSize() < sectionNumber)
        {
            return;
        }

        printf("%s == %d\n", input->get(), listSection->getItemAtPosition(sectionNumber - 1)->getNumberOfSelectors());
    }
    else if (arg1->isNumber() && arg3->isNumber())
    {
        int sectionNumber = arg1->toInteger();
        if (listSection->getSize() < sectionNumber)
        {
            return;
        }

        int selectorNumber = arg3->toInteger();
        if (listSection->getItemAtPosition(sectionNumber - 1)->getNumberOfSelectors() < selectorNumber)
        {
            return;
        }

        printf("%s == %s\n", input->get(), listSection->getItemAtPosition(sectionNumber - 1)->getSelectorAtPosition(selectorNumber - 1));
    }
    else if (arg3->equal("?"))
    {
        int selectors = 0;
        SectionCSS* section;
        ListSectionIterator iteratorSection(listSection, listSection->getSize());
        for (int i = 0; i < listSection->getSize(); i++)
        {
            section = iteratorSection.getNextItem();
            ListStringIterator iteratorString(section->getSelectorsList(), section->getNumberOfSelectors());
            for (int j = 0; j < section->getNumberOfSelectors(); j++)
            {
                if (arg1->equal(iteratorString.getNextItem()->get()))
                {
                    selectors++;
                }
            }
        }

        printf("%s == %d\n", input->get(), selectors);
    }
}

void Acommand(String* arg1, String* arg3, ListSection* listSection, String* input)
{
    if (arg1->isNumber() && arg3->equal("?"))
    {
        int sectionNumber = arg1->toInteger();

        if (listSection->getSize() < sectionNumber)
        {
            return;
        }

        printf("%s == %d\n", input->get(), listSection->getItemAtPosition(sectionNumber - 1)->getNumberOfAttributes());
    }
    else if (arg1->isNumber() && !arg3->equal("?"))
    {
        arg1->removeWhiteCharacters();
        if (arg1->getSize() == 0)
        {
            return;
        }

        int sectionNumber = arg1->toInteger();

        if (listSection->getSize() < sectionNumber)
        {
            return;
        }

        SectionCSS* section = listSection->getItemAtPosition(sectionNumber - 1);
        ListStringIterator iteratorString(section->getAttributesList(), section->getNumberOfAttributes());
        for (int i = 0; i < section->getNumberOfAttributes(); i++)
        {
            if (arg3->equal(iteratorString.getNextItem()->get()))
            {
                printf("%s == %s\n", input->get(), section->getValueAtPosition(iteratorString.getCurrentIndex()));
                break;
            }
        }
    }
    else if (arg3->equal("?"))
    {
        int number = 0, index;
        SectionCSS* section;
        ListSectionIterator iteratorSection(listSection, listSection->getSize());
        for (int i = 0; i < listSection->getSize(); i++)
        {
            section = iteratorSection.getNextItem();
            index = section->getIndexOfAttribute(arg1->get());

            if (index != -1)
            {
                number++;
            }
        }

        arg1->removeWhiteCharacters();
        if (arg1->getSize() == 0)
        {
            return;
        }

        printf("%s == %d\n", input->get(), number);
    }
}

void Ecommand(String* arg1, String* arg3, ListSection* listSection, String* input)
{
    SectionCSS* section;
    int index;
    for (int i = listSection->getSize() - 1; i >= 0; i--)
    {
        section = listSection->getItemAtPosition(i);
        index = section->getIndexOfSelector(arg1->get());

        if (index == -1)
        {
            continue;
        }

        index = section->getIndexOfAttribute(arg3->get());

        if (index == -1)
        {
            continue;
        }

        printf("%s == %s\n", input->get(), section->getValueAtPosition(index));
        break;
    }
}

void Dcommand(String* arg1, String* arg3, ListSection* listSection, String* input)
{
    int numberOfSection = arg1->toInteger();
    if (numberOfSection > listSection->getSize())
    {
        return;
    }

    if (arg3->equal("*"))
    {
        listSection->deleteItemAtPosition(numberOfSection - 1);
        printf("%s == deleted\n", input->get());
    }
    else
    {
        SectionCSS* section = listSection->getItemAtPosition(numberOfSection - 1);
        int index = section->getIndexOfAttribute(arg3->get());

        if (index != -1)
        {
            section->deleteAttributeAtPosition(index);
            section->deleteValueAtPosition(index);

            if (section->getNumberOfAttributes() == 0)
            {
                listSection->deleteItemAtPosition(numberOfSection - 1);
            }

            printf("%s == deleted\n", input->get());
        }
    }
}
