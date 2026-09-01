#include "lab.h"
#include <stdio.h>
#include <stdlib.h>

char *get_greeting(const char *restrict name)
{
  if (name == NULL)
  {
    return NULL;
  }

  // Allocate memory for the greeting message
  int length = snprintf(NULL, 0, "Hello, %s!", name);
  if (length < 0) // GCOVR_EXCL_START
  {
    return NULL; // snprintf failed
  } // GCOVR_EXCL_STOP

  //Casting is safe here because we know length is non-negative
  size_t alloc_size = (size_t) length + 1; // +1 for the null terminator
  char *greeting = malloc(alloc_size);


  if (greeting == NULL) // GCOVR_EXCL_START
  {
    return NULL; // Memory allocation failed
  }  // GCOVR_EXCL_STOP


  // Create the greeting message
  snprintf(greeting, alloc_size, "Hello, %s!", name);

  return greeting;
}

int get_product(int a, int b)
{
  return a * b;
}

int bad_sum(int a, int b)
{
  //char *leaked = malloc(64); // Intentional memory leak for task 4
  return a + b + 1; // As the assignment stated, provides an incorrect sum (off-by-one sum)
}


