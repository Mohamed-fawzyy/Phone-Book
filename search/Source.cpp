#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

void DisplayPhoneBook(char name[100][50], char number[100][50], int* counter)  // this func to show u the list of contacts which is save in file
{
	//t3
	FILE* PhoneBook = fopen("PhoneBook.txt", "r");
	if (PhoneBook == NULL)
	{
		printf("ERROR !! The PhoneBook File Not Found\n\n");
	}
	else
	{
		printf("\n\n\t\t\t\t\t* CONTACTS NAME *\t             * PHONE NUMBERS *\n\n");

		while (!feof(PhoneBook))
		{

			fscanf(PhoneBook, "\n");
			fscanf(PhoneBook, "%[^\t]s", name[*counter]);   // scan the name as written in file
			fscanf(PhoneBook, "%s", number[*counter]);

			printf("\t\t\t\t\t%s\t\t\t%s\n", name[*counter], number[*counter]);
		}
		printf("\n * Your numbers contacts are --> %d\n", *counter);
		printf("\n");
	}

	fclose(PhoneBook);
}

void DeletePhoneNumber(char name[100][50], char number[100][50], int* counter)  // this func to delete the contacts from files and array
{
	char Delete[30];  // save the data of user 
	int i, j, x;

	printf(" * These Are All Contacts You Have: \n");

	while (getchar() != '\n');
	for (int i = 0; i < *counter; i++)
	{
		printf("\n%s\t%s", name[i], number[i]);
	}
		
		printf("\n\n * Enter The Name You Want To Delete--> ");
		scanf("%[^\n]s", Delete);
		int flag = 0;
		for (i = 0; i < *counter; i++)
		{
			for (j = 0; j < strlen(Delete); j++) // string length of user will compared wz the name array 
			{
				x = strcmp(name[i], Delete); // but the result in X 
				if (x == 0)
				{
					name[i][0] = 0;  // then the array of name and  number and file will be empty from this name 
					number[i][0] = 0;
					*counter -= 1;
					flag = 1;
					printf("\n ** The Contact Deleted Successfully **\n");
				}
			}
		}
		if (flag != 1)
		{
			printf("\n ** This Contact Not at File **\n");
		}
	/*	if (x == 0)
		{
			*counter -= 1;
		}
		else
		{
			printf("\n ** This Contact Not at File **\n");
		}*/
		
		/*for ( i = 0; i < *counter; i++)
		{
			if (name[i][0] != 0 && number[i][0] != 0)
			{
				printf("after deelte");
				printf("%s\t", name[i]);       just for testing
				printf("%s", number[i]);
			}
		}*/

		FILE* PhoneBook = fopen("PhoneBook.txt", "w");
		if (PhoneBook == NULL)
		{
			printf("ERROR !! The PhoneBook File Not Found\n\n");
		}
		else
		{
			for (int i = 0; i < *counter; i++)
			{
				if (name[i][0] != 0 && number[i][0] != 0)  // print in the file the changes
				{
					fprintf(PhoneBook, "\n%s\t", name[i]);
					fprintf(PhoneBook, "%s", number[i]);
				}
			}
			//t3
		}

		fclose(PhoneBook);
	/*rewind(PhoneBook);
	while (getchar() != '\n');
	printf("\n Enter the name which u want to Delete --> ");
	scanf("%[^\n]s", Delete);
	if (*counter == Delete[30]);
	{
		printf("\n contacts left \n");      OLD WAY  (ams7 mn file w a7to f file tany)
		for (int i = 0; i < *counter; i--)
		{
			printf("%s: %s\n", name[i], number[i]);
		}
	}*/
}

void SearchPhoneNumber(char name[100][50], char number[100][50], int *counter)  // this func for searching the contacts with similar beging of litr
{
	int searchcounter;  // to count and compare it wz the length of str which the user entered
	char search[50];  // save the data from user 
	int i, j, Finder = 0;  // to find the which user search for it

	/*for (int i = 0; i < *counter; i++) 
	{
		printf("%s %s\n", name[i], number[i]);    just for testing
	}*/

	while (getchar() != '\n');
	printf("\n * Enter The Name You Want To Search --> ");
	scanf("%[^\n]s", search);
	

		for ( i = 0; i < *counter; i++ )
		{
			searchcounter = 0;  // reset every time for each sigle search 
			for (j = 0; j < strlen(search); j++)  // string length of user will compared wz the name array 
			{
				if (name[i][j] == search[j]) // litter wz litter compare
				{
					searchcounter++; // count the similar ltr
				}
			}

			if (searchcounter == strlen(search)) // if no of count == to search of user will print the name from array
			{
				printf("%s %s\n", name[i], number[i]); 
				Finder = 1;  // to check there is a name found
			}
		}

		if (Finder == 0)
		{
			printf("\n ** Ops, This Contact Is Not Found **\n");
		}
}

void AddPhoneNumber(int *counter, char name[100][50], char number[100][50])  // this func for adding a new contact and print it in the file
{
	//strcat(space, name);
	//strcat(space, " --> ");
	//strcat(space, number);  // old way
	//printf("\n");
	//puts(space);

	FILE* PhoneBook = fopen("PhoneBook.txt", "a");
	if (PhoneBook == NULL)
	{
		printf("ERROR !! The PhoneBook File Not Found\n\n");
	}
	else
	{
	
		while (getchar() != '\n');  // cleaning the buffer
		puts("\n * The User Name --> ");
		scanf("%[^\n]s", name[*counter]);   // scan from user both no and name and print with same way of scanning in the file 

		puts("\n * User Phone Number --> ");
		scanf("%s", &number[*counter]);
		
		fprintf(PhoneBook, "\n%s\t",name[*counter]);
		fprintf(PhoneBook, "%s", number[*counter]);
		
		/*printf("%s\t",name[*counter]);     just for testing
		printf("%s", number[*counter]);*/
		printf("\n ** The Contact Has been Saved **\n");
		*counter += 1;  // working for counting how many contacts were added to the array
	}

	fclose(PhoneBook);
}

void MainMenu(int* counter,  char name[100][50], char number[100][50] )  // this func to show u wich op u want to do in ur phonebook
{
	char C = 'C', E = 'E', e = 'e';  


	while (C != E && C != e)
	{

		printf("\n");
		printf("                                          ********WELCOME TO PHONEBOOK******** \n\n\n");  // the menu in console
		printf("          (A)- To AddContact                                                     (S)- To Search for a Number\n");
		printf("\n          (D)- if you want to Delete a Number                                   (L)- To Show The List Of PhoneBook\n");
		printf("\n                                                  (E)- To Exit\n");
		printf("\n You choose --> ");
		scanf("%c", &C);

		switch (C) 
		{
		case 'A':
		case 'a':
			AddPhoneNumber(counter, name, number);
			while (getchar() != '\n');
			break;

		case 'S':
		case 's':
			SearchPhoneNumber(name, number, counter);
			while (getchar() != '\n');
			break;

		case 'D':
		case 'd':
			DeletePhoneNumber(name, number, counter);
			while (getchar() != '\n');
			break;

		case 'L':
		case 'l':
			DisplayPhoneBook(name, number, counter);
			while (getchar() != '\n');
			break;

		default:
			if (C != E && C != e && C != '\n')  // this \n to prevent printing the next line
			{
				printf("\n Enter the letter which mention before only\n\n");
				//getchar();
				while (getchar() != '\n');
			}
		}
	}
}

int main()
{
	int counter=0;  // counter for counting the name in each of array and file
	
	char name[100][50],search[50]; // array name for save the name of contacts 
	char number[100][50];  // array number for save the contacts numer

	FILE* PhoneBook = fopen("PhoneBook.txt", "r");
	if (PhoneBook == NULL)
	{
		printf("ERROR !! The PhoneBook File Not Found\n");
		printf("But We created a New One for You\n");
		PhoneBook = fopen("PhoneBook.txt", "a");
	}
	else
	{
		while (!feof(PhoneBook))
		{
			fscanf(PhoneBook, "\n");
			fscanf(PhoneBook, "%[^\t]s", name[counter]);   // scan the name as written in file
			fscanf(PhoneBook, "%s", number[counter]);
			counter++;
		}
	}

	fclose(PhoneBook);
	MainMenu(&counter, name, number);
}
