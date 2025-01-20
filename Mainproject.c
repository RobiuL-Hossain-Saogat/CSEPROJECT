#include <stdio.h>
#include <string.h>

struct Customer
{
	char name[50];
	char phoneNumber[15];
	double usage;
	double totalBill;
};

FILE *fp;

struct Customer
	customers[100];	   
int customerCount = 0; 
					   
int n;
//Robiul
void addRecord()
{
	if (customerCount < 100)
	{
		fp = fopen("customers.txt", "r");
		fscanf(fp, "%d", &n);
		for (int i = 0; i < n; i++)
		{
			// printf("\nEnter name: ");
			fscanf(fp, " %[^\n]s", customers[customerCount].name);
			// printf("Enter phone number: ");
			fscanf(fp, "%s", customers[customerCount].phoneNumber);
			// printf("Enter usage (in minutes): ");
			fscanf(fp, "%lf", &customers[customerCount].usage);
			customers[customerCount].totalBill = customers[customerCount].usage * 0.1;
			customerCount++;
		}
		printf("\nRecord added successfully!\n");
	}
	else
	{
		printf("\nMaximum number of records reached!\n");
	}
	fclose(fp);
}

//Robiul
void viewRecords()
{
	printf("\nName\tPhone Number\tUsage(min)\tTotal Bill($)\n");
	for (int i = 0; i < customerCount; i++)
	{
		printf("%s\t%s\t%.2lf\t\t%.2lf\n", customers[i].name,
			   customers[i].phoneNumber, customers[i].usage,
			   customers[i].usage * 0.1);
	}
}

//Robiul
void modifyRecord(char phoneNumber[])
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(customers[i].phoneNumber, phoneNumber) == 0)
		{

			printf(
				"\nEnter new usage (in minutes) for %s: ",
				customers[i].name);
			scanf("%lf", &customers[i].usage);
			for (int i = 0; i < n; i++)
			{
				fp = fopen("customers.txt", "w");
				fprintf(fp, "%d\n", n);
				for (int i = 0; i < n; i++)
				{
					fprintf(fp, "%s\n%s\n%.2lf\n", customers[i].name,
							customers[i].phoneNumber,
							customers[i].usage);
				}
			}
			fclose(fp);
			printf("\nRecord modified successfully!\n");
			return;
		}
	}
	printf("\nRecord not found!\n");
}

//Faozan
void viewPayment(char phoneNumber[])
{	
	printf("\nName\tPhone Number\tUsage(min)\tTotal Bill($)\n");
	for (int i = 0; i < customerCount; i++)
	{
		if (strcmp(customers[i].phoneNumber, phoneNumber) == 0)
		{
			printf(
				"%s\t%s\t%.2f\t\t%.2f\n", customers[i].name,
				customers[i].phoneNumber,
				customers[i].usage, customers[i].usage * 0.1);
			return;
		}
	}
	printf("\nRecord not found!\n");
}

//Sajid
void deleteRecord(char phoneNumber[])
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(customers[i].phoneNumber, phoneNumber) == 0)
		{
			for (int i = 0; i < n; i++)
			{
				fp = fopen("customers.txt", "w");
				fprintf(fp, "%d\n", n);
				for (int i = 0; i < n; i++)
				{	
					if (strcmp(customers[i].phoneNumber, phoneNumber) != 0){
						fprintf(fp, "%s\n%s\n%.2lf\n", customers[i].name,
							customers[i].phoneNumber,
							customers[i].usage);
					}
				}
			}
			fclose(fp);
			printf("\nRecord deleted successfully!\n");
			return;
		}
	}
	printf("\nRecord not found!\n");
}

//Saurob
// Function to display menu options
void displayMenu()
{
	printf("\n1. Add New Record\n");
	printf("2. View List of Records\n");
	printf("3. Modify Record\n");
	printf("4. View Payment\n");
	printf("5. Delete Record\n");
	printf("6. Exit\n");
}

//all functions
int main()
{
	int choice;
	char phoneNumber[15];

	while (1)
	{
		displayMenu();
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			addRecord();
			break;
		case 2:
			viewRecords();
			break;
		case 3:
			printf(
				"\nEnter phone number to modify record: ");
			scanf("%s", phoneNumber);
			modifyRecord(phoneNumber);
			break;
		case 4:
			printf(
				"\nEnter phone number to view payment: ");
			scanf("%s", phoneNumber);
			viewPayment(phoneNumber);
			break;
		case 5:
			printf(
				"\nEnter phone number to delete record: ");
			scanf("%s", phoneNumber);
			deleteRecord(phoneNumber);
			break;
		case 6:
			return 0;
		default:
			printf("\nInvalid choice! Please try again.\n");
		}
	}

	return 0;
}
