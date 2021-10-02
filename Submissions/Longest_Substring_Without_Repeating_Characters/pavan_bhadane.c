// Longest Substring Without Repeating Characters in C
// Pavankumar Bhadane (Pavan49719)
//
// Approach: 
// Using while loop, whole string is getting traversed. 
// After calculating length for each subtring using index, it's compared with maximum length.
// Maximum length is returned at last.

// Time complexity: O(n)
// Space complexity: O(n)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int length_of_longest_substring(char *str1)
{
   int offset[128];
   int substr_max_len = 0;
   int len = 0;
   int index = 0;
   memset(offset, 0xff, sizeof(offset));
   while (*str1 != '\0') 
   {
   		if (offset[*str1] == -1)
		   len++;
    	else 
		{
			if (index - offset[*str1] > len)
				len++;
            else
                len = index - offset[*str1];
		}
       	if (len > substr_max_len)
	   		substr_max_len = len;
      	offset[*str1++] = index++;
   }
   return substr_max_len;
}

//Driver code
int main()
{
	char *str1 = "xyzxyzyy";
  	printf("%d",length_of_longest_substring(str1));
  	return 0;
}

