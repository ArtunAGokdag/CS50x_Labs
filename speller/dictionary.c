// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

unsigned int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //case insensitive using strcasecp()
    
    //hash word to obtain value
    unsigned int hash_code = hash(word);

    // access linked list at that value
    node * cursor = table[hash_code];

    // traverse list look for the word
    while(cursor != NULL){
        
        if(strcasecmp(cursor->word, word) == 0)
            return true;
        
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{

    // Open file
    FILE * file = fopen(dictionary, "r");
    if(file == NULL) return false;


    char word[LENGTH +1];
    while (fscanf(file, "%s", word) != EOF) {

        // Create new node for each word
        node * new_node = malloc(sizeof(node));
        if(new_node == NULL) return false;
        
        // Hash word to obtain a hash value
        unsigned int hash_code = hash(word);
        
        // Insert nod into hash table at that location
        strcpy(new_node->word, word);
        new_node->next = table[hash_code];
        table[hash_code] = new_node;

    }
    //close file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node * tmp;
    node * cursor;

    //traverse each list in table
    for (int i = 0; i < N; i++) {
        
        cursor = table[i];
        tmp = cursor;

        while(cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
            
        }
    }
    word_count = 0;
    return true;

}
