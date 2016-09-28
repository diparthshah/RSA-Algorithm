/* 
    File : rsa.c 
    Desc : Implementation of RSA algorithm in C
    Author : Diparth Shah <diparths@gmail.com> 
*/
    
#include<stdio.h>
#include<stdbool.h> 
#include<stdlib.h> 

/* include our own header code "thug.h" which completely handles prime input operations */ 

#include"thug.h" 

/* compute() function is used to generate private and public key */ 

void encrypt();
void decrypt();
void compute();
void display();

/*  here p and q are two large prime numbers ,
    d is decrypter private key and e is encrypter public key , n and fn is used for
    computation , pt is entered plain text and ct is cipher text 
*/ 
int p,q,n,fn,d,e,temp,dt; 
int pt=1,ct=1;
bool x;

int main()
{
	
	printf("\n ENTER FIRST PRIME NUMBER : ");
	scanf("%d",&p);
/* using isPrime() function to check prime input , which is defined in our own header file "thug.h" */ 
	x=isPrime(p);

	if (x==false)
	{
		printf("\n Wrong input \n");
		exit(0);
	}

	printf("\n ENTER SECOND PRIME NUMBER : "); 
	scanf("%d",&q);
    x=isPrime(q);

    if(x==false)
    {
    	printf("\n Wrong input \n ");
    	exit(0);
    }

    compute(); 

    printf("\n\n ENTER YOUR TEXT : "); 
    scanf("%d",&pt);
    
    encrypt(); 
    decrypt();
    display();

 return 0; 

}

void compute()
{
 n=p*q;
 fn=(p-1)*(q-1);

 /* generate encrypter(e) public key */ 

 TryAgain:
 printf("\n ENTER PUBLIC KEY WHICH MUST BE PRIME NUMBER AND LESS THAN %d : ",fn);
 scanf("%d",&e);
 x=isPrime(e);

 if(x==false || e>=fn)
  
  {
  	printf("\n INVALID INPUT \n"); 
    goto TryAgain; 
  }
    


/* generate decrypter(d) private key */ 

d = 1;

do
{

temp = (d*e)%fn;
d++;

} while(temp!=1);

d = d-1;

printf("\n RIVEST-SHAMIR-ADLEMAN \n");
printf("\n PUBLIC KEY : %d , %d ",e,n);
printf("\n Generating PRIVATE KEY...............");
printf("\n PRIVATE KEY : %d , %d ",d,n); 

}

void encrypt()
{
    int k;

	k=pow(pt,e);
    ct=(k%n);
}

void decrypt()
{
  long int l;
  

  l=pow(ct,d);
  dt=(l%n);
}

void display()
{
  printf("\n -------------------------------------------------");
  printf("\n PLAIN TEXT : %d ",pt);
  printf("\n ENCRYPTED TEXT : %d ",ct);
  printf("\n DECRYPTED TEXT : %d ",dt);
  printf("\n -------------------------------------------------\n");
}

