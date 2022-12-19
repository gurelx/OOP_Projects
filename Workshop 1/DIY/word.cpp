/*
*****************************************************************************
                          Workshop - #1 (P2)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

#include "dictionary.h"
#include "word.h"


using namespace std;
using namespace sdds;

// <summary>
/// Search in the dictionary for the word and display all the definitions found.
/// 
/// Print "NOT FOUND: word [X] is not in the dictionary." if
///   the word doesn't exist in dictionary.
/// </summary>
/// <param name="word">The word to search and display.</param>
void sdds::DisplayWord(const char* word)
{
    int i, j;
    int check = EXIT_FAILURE;

    for (i = 0; i < dictionary.wordCount; i++)
    {
        if (!std::strcmp(dictionary.words[i].name, word))
        {
            printf("FOUND: [%s] has [%d] definitions:\n", word, dictionary.words[i].wordInfo.defCount);

            for (j = 0; j < dictionary.words[i].wordInfo.defCount; j++)
            {
                printf("%d. {%s} %s\n", j + 1, dictionary.words[i].wordInfo.type[j], dictionary.words[i].wordInfo.definition[j]);
            }

            check = EXIT_SUCCESS;
            break;
        }
    }

    if (check == EXIT_FAILURE)
    {
        printf("NOT FOUND: word [%s] is not in the dictionary.\n", word);
    }
}

/// <summary>
/// Adds a word to the dictionary.
/// 
/// If the dictionary already contains the word, add a new definition for it.
/// </summary>
/// <param name="word">The word to add to the dictionary.</param>
/// <param name="type">The type of the word (noun, verb, adjective, etc.)</param>
/// <param name="definition">The definition for the word.</param>
void sdds::AddWord(const char* word, const char* type, const char* definition)
{
    int i, j;
    int check = EXIT_FAILURE;

    for (i = 0; i < dictionary.wordCount; i++) // Search the words
    {
        // If there is an existing word
        if (!std::strcmp(dictionary.words[i].name, word))
        {
            j = dictionary.words[i].wordInfo.defCount;

            std::strcpy(dictionary.words[i].wordInfo.type[j], type);
            std::strcpy(dictionary.words[i].wordInfo.definition[j], definition);

            dictionary.words[i].wordInfo.defCount++;
            check = EXIT_SUCCESS;
            break;
        }
    }
    // If there are no matching existing words
    if (check == EXIT_FAILURE)
    {
        i = dictionary.wordCount;

        std::strcpy(dictionary.words[i].name, word);
        std::strcpy(dictionary.words[i].wordInfo.type[0], type);
        std::strcpy(dictionary.words[i].wordInfo.definition[0], definition);

        dictionary.wordCount++;
        dictionary.words[i].wordInfo.defCount++;
    }
}

/// <summary>
/// Searches in the dictionary for a word and update its definition and type.
///   If the word contains multiple definitions, print the message
///   "The word [X] has multiple definitions:" followed by a list of existing
///   definitions, and asks user which one to update.  This function assumes that
///   the user's input is correct and doesn't require validation.
/// 
/// If the word is not in the dictionary, this function does nothing.
/// </summary>
/// <param name="word">The word to update.</param>
/// <param name="type">The new type of the definition.</param>
/// <param name="definition">The new definition.</param>
/// <returns></returns>
int sdds::UpdateDefinition(const char* word, const char* type, const char* definition)
{
    int i, j, updateNum;

    for (i = 0; i < dictionary.wordCount; i++) // Search the words
    {
        if (!strcmp(dictionary.words[i].name, word))
        {
            printf("The word [%s] has ", word);

            if (dictionary.words[i].wordInfo.defCount > 1)
            {
                printf("multiple definitions:\n");
            }
            else
            {
                printf("one definition:\n");
            }

            for (j = 0; j < dictionary.words[i].wordInfo.defCount; j++)
            {
                printf("%d. {%s} %s\n", j + 1, dictionary.words[i].wordInfo.type[j], dictionary.words[i].wordInfo.definition[j]);
            }
        }
    }
    printf("Which one to update? ");
    scanf("%d", &updateNum);

    strcpy(dictionary.words[i - 1].wordInfo.type[updateNum - 1], type);
    strcpy(dictionary.words[i - 1].wordInfo.definition[updateNum - 1], definition);

    return EXIT_SUCCESS;
}