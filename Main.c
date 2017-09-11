/* 
 * Simple list example - we store strings
 */

#include <stdio.h>
#include <string.h>
#include "LinkedListAPI.h"

//Printing a string requires a simple cast
char* printFunc(void *toBePrinted){
	
	return (char*)toBePrinted;
}

//Comparing strings is done by strcmp
int compareFunc(const void *first, const void *second){
	
	return strcmp((char*)first, (char*)second);
}

//Freeing a string is also straightforward
void deleteFunc(void *toBeDeleted){
	
	free(toBeDeleted);
}

int main(void){
	//Allocate the strings
	char* str[3];
	
	for (int i = 0; i < 3; i++){
		str[i] = (char*)malloc(10*sizeof(char));
	}
	strcpy(str[0], "b");
	strcpy(str[1], "d");
	strcpy(str[2], "a");
	// strcpy(str[3], "c");
	
	/* 
	Create the list.  The list is allocated on the stack, and initializeList returns the list struct.
	*/
	List list = initializeList(&printFunc, &deleteFunc, &compareFunc);

	//Populate the list
	for (int i = 0; i < 3; i++){
		insertSorted(&list, (void*)str[i]);
	}
	
	void* elem;
	
	//Create an iterator - again, the iterator is allocated on the stack
	ListIterator iter = createIterator(list);

	/*
	Traverse the list using an iterator.  
	nextElement() returns NULL ones we reach the end of the list
	*/
	while ((elem = nextElement(&iter)) != NULL){
		char* str = (char*)elem;
		//Since str is the pionter to the stored string, we don't need to free it
		printf("%s", str);
	}
	
	printf("\n");
	
	deleteDataFromList(&list, "b");
	
	char* s = toString(list);
	printf("%s\n", s);
	free(s);
	
	/*
	Crear list contents - free each node, including its contents
	Since the list is created in the stack, we don't need to free it. 
	*/
	clearList(&list);	
	
	return 0;		
}











