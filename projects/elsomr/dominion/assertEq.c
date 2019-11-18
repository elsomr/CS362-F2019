
/* -----------------------------------------------------------------------
 * Custom Assert Function
 *
 *
 * To use this function, pass the expected result, the outcome, and a counter variable 
 * that will count the number of failed tests. 
 * -----------------------------------------------------------------------
 */

#include <string.h>
#include <stdio.h>
#include "assertEq.h"

void assertEq(int expected, int outcome, int* failCounter, char* result)	{
	
	if (expected == outcome) 	{
		result = "PASS";
	}
	else	{
		(*failCounter)++;
		result = "FAIL";
	}
	
	printf("%s\n", result);
}