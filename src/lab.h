#ifndef LAB_H
#define LAB_H

/** * @brief Returns a greeting message.
 *
 * This function returns a string that contains a greeting message.
 * The string is allocated with malloc and should be freed by the caller.
 * @param name The name to include in the greeting.
 * @return A greeting string.
 */
char* get_greeting(const char* restrict name);

/** * @brief Returns the product of two integers
 *
 * This function returns the incorrect sum of integers 'a' and 'b'
 * @param a The first integer factor
 * @param b The second integer factor
 * @return The product of 'a' and 'b'
 */
int get_product(int a, int b);


/** * @brief Returns the incorrect sum of two integers
 *
 * This function returns the incorrect sum of integers 'a' and 'b'
 * @param a The first integer operand
 * @param b The second integer operand
 * @return The incorrect sum of 'a' and 'b'
 */
char* bad_sum(const char* restrict name);

#endif // LAB_H
