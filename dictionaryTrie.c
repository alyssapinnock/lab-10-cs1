/*

Instructions: 
In this lab, you are going to implement a trie data structure to 
count the number of occurrences of a word if it exists in the dictionary. 
Words will always be in lowercase. Please modify the following code template:

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Trie structure
struct Trie{
	int count;
	struct Trie* next[26]; // children in the tree
};


// Inserts the word to the trie structure
void insert(struct Trie *pTrie, char *word){

}

// computes the number of occurances of the word
int numberOfOccurances(struct Trie *pTrie, char *word){

}

// deallocate the trie structure
struct Trie *deallocateTrie(struct Trie *pTrie){
	int i;
	for(i = 0; i < 26; i++){
		if (pTrie->next != NULL){
			deallocateTrie(pTrie->next[i]);
		}
	}
	free(pTrie);
}

// Initializes a trie structure
struct Trie *createTrie(){
	struct Trie *dictionary = malloc(sizeof(struct Trie));
	dictionary->count = 0;

	for (int i = 0; i < 26; i++){
		dictionary->next[i] = NULL; // Set to NULL so that the spaces are empty
	}

	return dictionary;
}

// this function will return number of words in the dictionary,
// and read all the words in the dictionary to the structure words
int readDictionary(char *filename, char **pInWords)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL){
        printf("\nThere was an error opening the file. \n");
    }

	int n; 
	fscanf(file, "%d", &n); // Number of words in the dictionary

	for (int i = 0; i < n; i++){
		pInWords[i] = malloc(sizeof(char*)*n);
		fscanf(file, "%s", pInWords[i]);
	}
	
	fclose(file);
	return n;

}

int main(void)
{
	char *inWords[256];
	
	//read the number of the words in the dictionary
	int numWords = readDictionary("dictionary.txt", inWords);
	
	for (int i=0;i<numWords;++i)
	{
		printf("%s\n", inWords[i]);
	}
	
	struct Trie *pTrie = createTrie();
	for (int i=0;i<numWords;i++)
	{
		insert(pTrie, inWords[i]);
	}
	// parse lineby line, and insert each word to the trie data structure
	char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
	for (int i=0;i<5;i++)
	{
		printf("\t%s : %d\n", pWords[i], numberOfOccurances(pTrie, pWords[i]));
	}
	pTrie = deallocateTrie(pTrie);
	if (pTrie != NULL)
		printf("There is an error in this program\n");
	return 0;
}
