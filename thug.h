/* 
    File : thug.h 
    Desc : Header file containing function for checking prime input
    Author : Diparth Shah <diparths@gmail.com> 
*/

#include<stdio.h>
#include<math.h> 
#include<stdbool.h>

bool isPrime(long int mynum);

bool isPrime(long int mynum)
{
	int checkmynum;
	int mycount;

	checkmynum=sqrt(mynum);
    
    for (mycount=2; mycount<=checkmynum; mycount++)
    {
    	if(mynum%mycount==0)

    		return false;
    }

    
    return true; 

}