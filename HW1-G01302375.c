/*

Name : Preeti Bhattacharya
G-Number : G01302375

*/

#include <stdio.h>
#include <string.h>
#include<ctype.h>

// Initialized "strings" as a global variable.
 
char strings[10][50];

// Declaration of user defined functions.
int check(char var[50], int n);  //To check the condition of char<=25, null string, duplicate string and special character.
void sorting_strings();  //Taking input as A or D for sorting.
void sorting(int sorting_order);    //Here the sorting operation is performed.
void get_ascii(int sorting_order);   //To print the lowest and the highest ascii value.

// This function includes error checking for the given 10 strings.
int check(char var[50], int n)
{
	int i;
	char special_char[] = "!@#$%^()";

	i = strlen(var); 

  //Empty string checker.
	if(i<=1){
		return 0;
	}

  //String length checker.
	if(i>26){
		return 1;
	}

   //Duplicate String checker.
	for(int i=0;i<n;i++){
		if(strcmp(strings[i],var) == 0){
			return 2;
		}
	}

  //Special characters checker.
	for(int i=0;i<strlen(special_char);i++){
		if(NULL !=  strchr(var,special_char[i])){
			int var_special=i;
			printf("Error: %c is an illegal character - please re-enter\n", special_char[var_special]);
			return 3;
		}
	}

  return -1;
}


// This function asks the user as input for ascending order or descending order.
void sorting_strings()
{
  // random array size for order, and it stores only one character (first char)
  char order[3];

  printf("Print character strings in Ascending(A) and Descending(D) order:");
  scanf("%s", &order[0]);

  if(strcmp(order,"A") == 0){
    printf("Ascending order: \n");
  }else if(strcmp(order,"D") == 0){
    printf("Descending order: \n");
  }else{
      printf("Error - wrong character entered - please re-enter 'A' or 'D'\n\n");
      sorting_strings();
  }
  int sorting_order;
  if (strcmp(order,"A") == 0)
  {
    sorting_order = 0;
    sorting(sorting_order);
  }
  else if (strcmp(order,"D") == 0)
  {
    sorting_order = 1;
    sorting(sorting_order);
  }
  
}

/* This function takes the input of 10 strings and sorts them using ASCII values. 
sorting_order is used to differentiate ascending order and descending order. If sorting order is 0 it does ascending order, if it is 1 it does 
descending order */


void sorting(int sorting_order)  //used bubble sort for sorting.
{
  char temp[50];
  for (int c = 0; c < 10; c++)
  {
    for (int d = 0; d < 10 - c; d++)
    {
      int res = strcmp(strings[d], strings[d + 1]);
      if (sorting_order == 0)
      {
        if (res > 0)
        {
          strcpy(temp, strings[d]);
          strcpy(strings[d], strings[d + 1]);
          strcpy(strings[d + 1], temp);
        }
      }
      else
      {
        if (res < 0)
        {
          strcpy(temp, strings[d]);
          strcpy(strings[d], strings[d + 1]);
          strcpy(strings[d + 1], temp);
        }
      }
    }
  }

  //printing the characters in ascending or descending order
  for (int i = 1; i < 11; i++)
  {
    printf("%s \n",strings[i]);
  }

  get_ascii(sorting_order);
}

// This function finds the lowest and the highest ascii values among all the strings for ascending or descending order.
void get_ascii(int sorting_order){
  if(sorting_order == 0)  //For acsending order.
  {
    printf("String with lowest ascii value: %s \n",strings[1]);
		printf("String with highest ascii value: %s \n",strings[10]);
	}
	else{              //For descending order.
		printf("String with lowest ascii value: %s \n",strings[10]);
    printf("String with highest ascii value: %s \n",strings[1]);
  }
}


int main()
{
  char var[50];
  printf("Enter 10 character strings \n\n\n");
  int n=0;
  //loop for 10 strings
  while (n < 10)
  {

    //get input from user.
    printf("Enter string %d: ", n + 1);

    //reads input from user and fgets() function is used to read a string with spaces included.
    fgets(var, sizeof(var), stdin);

    int ret = check(var, n);
    switch (ret)
    {
    case 0:
      printf("Error: String is empty - please re-enter\n");
      continue;
    case 1:
      printf("Error: String length is more than 25 characters - please re-enter\n");
      continue;
    case 2:
      printf("Error: Duplicate string - please re-enter\n");
      continue;
    case 3:
      // Continuing if Special character found in given string.
      continue;
    
    }

    //if all the conditions are satisfied, copying var to the array of strings.
    strcpy(strings[n], var);

    //increementing while loop variable.
    n++;
  }

  // sorting 10 strings.
  sorting_strings();

  return 1;
}

