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

Dictionary dictionary; // global dictionary

/// <summary>
/// Load from a file a set of words with their definition.  Any previous
///   existing dictionary is discarded, regardless of the result of the load.
/// </summary>
/// <param name="filename">The name of the file containing the dictionary.</param>
/// <returns>0 if data has been loaded from the file, non-zero otherwise
///   (null parameter, empty parameter, missing file).</returns>
int sdds::LoadDictionary(const char* filename) 
{
    int i = 0, j = 0;
    int check = EXIT_FAILURE;
    char newLine = 'n';
    char isTab = 't';
    FILE* fp = fopen(filename, "r");
    std::memset(&dictionary, 0, sizeof(dictionary)); // Reset the dictionary

    if (!fp) 
    {
        return check;
    }
    else 
    {
        while (!(feof(fp))) {
            
            j = 0;
            fscanf(fp, "%s\n", dictionary.words[i].name); // Store the word
            
            do
            {
                fscanf(fp, "%[^:]: %[^\n]", dictionary.words[i].wordInfo.type[j], dictionary.words[i].wordInfo.definition[j]); // Store the type and definition
                
                newLine = fgetc(fp);
                if (newLine == '\n') {
                    isTab = fgetc(fp); // If there is a new line, check for the tab
                }
                j++;

            } while (isTab == '\t'); // Keep storing type and definition until the line doesn't start with a tab
            
            dictionary.words[i].wordInfo.defCount = j;
            i++;
        }
        dictionary.wordCount = i;
        check = EXIT_SUCCESS;
    }
   
    fclose(fp);

    return check;
}

/// <summary>
/// Save all the words existing in the dictionary into a file.  The functions
///   "LoadDictionary" should be able to load from this after the save finished.
/// </summary>
/// <param name="filename">The name of the file where to save.</param>
void sdds::SaveDictionary(const char* filename) 
{
    int i = 0, j = 0;
    FILE* fp = fopen(filename, "w");

    if (!fp)
    {
        printf("Cannot open the file for saving...\n");
    }
    else
    {
        for(i = 0; i < dictionary.wordCount; i++)
        {
            j = 0;
            fprintf(fp, "%s\n", dictionary.words[i].name); // Write the word

            for (j = 0; j < dictionary.words[i].wordInfo.defCount; j++) // Keep writing type and definition until there is no type left
            {
                fprintf(fp, "\t%s: %s\n", dictionary.words[i].wordInfo.type[j], dictionary.words[i].wordInfo.definition[j]); // Write the type and definition
            }
            fprintf(fp, "\n");
        }
    }

    fclose(fp);
}


