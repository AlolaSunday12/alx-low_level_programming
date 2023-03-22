#include "3-calc.h"

/**
 * op_add - calculates the sumnof two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - calculates two difference of two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: differenc eof and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - calculates the products of two intergers
 * @a: first interger
 * @b: second integer
 *
 * Return: product of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - calculates the division of two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: result of the division of a and b
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - calculates the reminder of the division of two integer
 * @a: first integer
 * @b: second integer
 *
 * Return: remainder of a division b
 */
int op_mod(int a, int b)
{
	return (a % b);
}
