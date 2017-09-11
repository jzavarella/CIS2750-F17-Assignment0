#include <stdlib.h> 
#include "LinkedListAPI.h"

//Printing a string requires a simple cast
char* printFunc(void *toBePrinted){
  char* buffer = malloc(sizeof(char) * 20);
  sprintf(buffer, "%lu", (unsigned long) toBePrinted);
	return buffer;
}

//Comparing strings is done by strcmp
int compareFunc(const void *first, const void *second){
	return (int) ((unsigned long) first - (unsigned long) second);
}

//Freeing a string is also straightforward
void deleteFunc(void *toBeDeleted){
  for (size_t i = 0; i < sizeof(unsigned long); i++) {
    free(*toBeDeleted[i]);
  }
}

long random_at_most(long max) {
  unsigned long
    // max <= RAND_MAX < ULONG_MAX, so this is okay.
    num_bins = (unsigned long) max + 1,
    num_rand = (unsigned long) RAND_MAX + 1,
    bin_size = num_rand / num_bins,
    defect   = num_rand % num_bins;

  long x;
  do {
   x = random();
  }
  // This is carefully written not to overflow
  while (num_rand - defect <= (unsigned long)x);

  // Truncated division is intentional
  return x/bin_size;
}

int main(int argc, char const *argv[]) {
  /* 
	Create the list.  The list is allocated on the stack, and initializeList returns the list struct.
	*/
	List list = initializeList(&printFunc, &deleteFunc, &compareFunc);
  
  int size = 10;
  long* arr = malloc(sizeof(long)*size);
  for (int i = 0; i < size; i++) {
    arr[i] = random_at_most(100);
    insertSorted(&list, (void*)arr[i]);
  }
  
  char* ts = toString(list);
  printf("%s\n", ts);
  free(ts);
  
  clearList(&list);
  return 0;
}