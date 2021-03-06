/********** Function ReadFilename *******************************
 	File: readfilename.c
  	Author: Rob MacLeod
	Last update: Wed Oct 31 14:32:58 MST 1990
    
 A routine to prompt the user for a filename. If no entry, return the 
 default value supplied by the calling routine.

      Input: 
       prompt           char    promptstring
      Input/Output:			
       *filename	char	filename entered by the user
       
      Returns:
       the length of the filename (int)
*/
/***************************************************************/
/* Note if * is removed from next line the program cannot acess the
   value of filename in the subroutine and the printf statement doesn't
   work (core dump) */

#include <stdio.h>
#include <string.h>
#include "cutil.h"
void ReadFilename(const char *prompt, char *filename)
{
/***************************************************************/
    int nchar;
    char *comment;
    char instring[80]=" ";
/***************************************************************/
 /*** Prompt the user for filename entry - return takes the default ***/

    printf("Enter the name of the %s file you want\n"
	   "  [def= %s] ?  ", prompt, filename);
  
 /*** Read the users input; if no characters entered, then assume
  the default is to be taken ***/

    fgets(instring, 79, stdin);

 /*** Get rid of the line feed ***/

    comment = strchr( instring, '\n' );
    if ( comment != NULL )
	strcpy( comment, "\0" );

    nchar = Trulen(instring);
    if (nchar > 0) {
	printf ("\n Filename entered is %s of length %i \n", instring, nchar) ;
	//	filename = strncpy(filename, instring, nchar);
	filename = strcpy(filename, instring);
    }
    else
	printf ("\n Default filename %s is taken \n", filename);
    return;
}




