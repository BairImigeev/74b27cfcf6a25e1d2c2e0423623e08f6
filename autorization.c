#include <stdio.h> //to enter the login and password, and output to the console
#include <string.h> //to compare strings
#include <unistd.h> //for a delay of 3 seconds

int main(void)
 {
   char loginadmin[100]="test0";
   char passadmin[100]="test0";
   int i=0;
   int j=0;
   step2: 
   while ((i<3) || (j<5)) // i and j are entry attempts
      {
      char login[100];
      printf("Enter login : ");
      scanf("%s",login);

      char pass[100];
      printf("Enter password : ");
      scanf("%s", pass);
	
      //Login and password verification	 
      if ((strcmp (login, loginadmin)==0) && (strcmp(pass, passadmin)==0))
	  { 
	     puts ("Welcome ADMIN!\n");
	     printf("========\n");
	      return 0;
	  }
      else 
	  {
	      i+=1;
	      j+=1;
              printf("User with such credentials was not found\n"); 
	      
	      if (i==3)
	       { 
	        printf("Waiting 3 secs ...\n");
	        sleep(3);
	        goto step2; // transition after an unsuccessful third login attempt
	       }
  	   } 
       printf("---\n");
       }
   printf("Exit 0\n");       
   return 0;
}
