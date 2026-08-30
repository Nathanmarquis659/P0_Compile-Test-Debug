#include <stdlib.h>
#include <stdio.h>
#include "harness/unity.h"
#include "../src/lab.h"


void setUp(void) {
  printf("Setting up tests...\n");
}

void tearDown(void) {
  printf("Tearing down tests...\n");
}

void test_get_greeting(void) {
  char *greeting = get_greeting("Alice");
  TEST_ASSERT_NOT_NULL(greeting);
  TEST_ASSERT_EQUAL_STRING("Hello, Alice!", greeting);
  free(greeting); // Free the allocated memory for the greeting

  greeting = get_greeting(NULL);
  TEST_ASSERT_NULL(greeting);

  greeting = get_greeting("");
  TEST_ASSERT_NOT_NULL(greeting);
  TEST_ASSERT_EQUAL_STRING("Hello, !", greeting);
  free(greeting);
}

void test_get_product(void)
{
  TEST_ASSERT_EQUAL_INT(2 * 2, get_product(2, 2));
}

void test_bad_sum(void)
{
  TEST_ASSERT_NOT_EQUAL_INT(2 + 2, bad_sum(2, 2));
  TEST_ASSERT_EQUAL_INT(2 + 2 + 1, bad_sum(2, 2));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_get_greeting);
  RUN_TEST(test_get_product);
  RUN_TEST(test_bad_sum);
  return UNITY_END();
}
