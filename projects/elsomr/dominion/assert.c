/* -----------------------------------------------------------------------
 * Custom Assert Function
 *
 *
 * To use this function, pass the expected result, the outcome, and a counter variable 
 * that will count the number of failed tests. 
 * -----------------------------------------------------------------------
 */

#include <string.h>
using std::string

char* assert(expected, outcome, failCounter)	{
	
	if {expected == outcome} 	{
		result[] = "PASS";
	}
	else	{
		failCounter++;
		result[] = "FAIL";
	}
	return result;
}