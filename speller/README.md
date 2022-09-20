A program that spell-checks a file using a hash table.

**Usage:**
./speller texts/sample.txt (default dictionary)

MISSPELLED WORDS

[...]
AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
[...]
Shangri
[...]
fianc
[...]
Sebastian's
[...]

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL:

The problem consists of implemenation of funcions:

- load
    - loads words from dictionary o memory usin a hash table

- hash
    - hash function ha returns a hash value for a given word

- size
    - returns the number of words in dictionary

- check
    - checks if a word is in the dictionary

- unload
    - clears dictionary from memory