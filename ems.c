// Include header files
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Structure for details of the employee
struct employees

{
    char name[50];
    float ctc;
    int age;
    int rc_no; 
};
struct emp e;

// Size of the structure
long int size = sizeof(e);

// Start from origin
COORD cord = { 0,0 }

// Function to get co-ordinates
void gotoxy(int x, int y)
{
    cord.X = x;
    cord.Y = y;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        cord);
}
  
FILE *fp, *ft;

// Function to add information of employees
void addinfo()
{
    system("cls");
    fseek(fp, 0, SEEK_END);
    char another = 'y';

    while (another == y)
    {
        printf("Name of the Employee: ");
        scanf("%c\n," &e.name);

        printf("CTC of the Employee (IN LPA): ");
        scanf("%f\n", &.ctc);

        printf("Age of the Employee: ")
        scanf("%d\n" &e.age)

        printf("Recruitment Number of the Employee: ")
        scanf("%d\n", &e.rc_no)

        fwrite(&e, size, 1, fp);

        printf("Do you want to add more information? (Yes/No)")
        
        fflush(stdin);
  
        scanf("%c", &another);
    }
}

// Function to delete information of employees
void deleteinfo()
{
    system("cls");
    char empname[50];
    char another = 'y';

    while (another == y)
    {
        printf("Name of the Employee: ")
        scanf("%c\n", &e.empname)

        ft = fopen("temp.txt", "wb");
        rewind(fp);
  
        while (fread(&e, size,
                     1, fp)
               == 1) {
            if (strcmp(e.name,
                       empname)
                != 0)
                fwrite(&e, size, 1, ft);
        }
  
        fclose(fp);
        fclose(ft);
        remove("data.txt");
        rename("temp.txt", "data.txt");
        fp = fopen("data.txt", "rb+");

        printf("Do you want to delete more records? (Yes/No)")
        fflush(stdin);
        another = getche();
    }
}

// Function to display information of the employees
void dispinfo()
{
    system("cls");

    rewind(fp);

    printf("\n==========================================================");
    printf("\nNAME\t\tCTC (IN LPA)\t\tAGE\t\tRECRUITMENT NO.\n",e.name, e.ctc, e.age, e.rc_no);
    printf("==========================================================\n");
     while (fread(&e, size, 1, fp) == 1)
        printf("\n%c\t\t%f\t\t%.2d\t%10d", e.name, e.ctc, e.age, e.rc_no);
  
    printf("\n\n\n\t");
    system("pause");
}

// Function to modify the information of the employee
 void modinfo()
 {
    system("cls");
    char empname[50];
    char another = 'y';
  
    while (another == 'y') {
        printf("Enter name of the employee to modify: ");
        scanf("%s\n", empname);

        rewind(fp);

        while (fread(&e, size, 1, fp) == 1)
        {

            if (strcmp(e.name, empname) == 0)
            {
                printf("\nEnter new name:");
                scanf("%s", e.name);
                printf("\nEnter new CTC (in LPA)");
                scanf("%d", &e.ctc);
                printf("\nEnter new age:");
                scanf("%f", &e.age);
                printf("\nEnter new recruitment number:");
                scanf("%d", &e.rc_no);
  
                fseek(fp, -size, SEEK_CUR);
                fwrite(&e, size, 1, fp);
                break;
            }
        }
    
        printf("\nWant to modify more information? (Yes/No");
        fflush(stdin);
        scanf("%c", &another);
    }
}

// Driver code
int main()
{
    int choice;
  
    // opening the file
    fp = fopen("data.txt", "rb+");
  
    // showing error if file is unable to open.
    if (fp == NULL) {
        fp = fopen("data.txt", "wb+");
        if (fp == NULL) {
            printf("\nCannot open file...");
            exit(1);
        }
    }
  
    system("Color 3F");
    printf("\n\n\n\n\t\t\t\t=====================================================");
    printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t\t\t\t=====================================================");
    printf("\n\t\t\t\t[|:::>:::>:::>::>EMPLOYEE RECORD<::<:::<:::<:::|]\t");
    printf("\n\t\t\t\t=====================================================");
    printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t\t\t\t===================================================\n");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tDeveloper: TechWiz007\n\n\t\t\t\t");
  
    system("pause");

    while (1)
    {
        // Clearing console and asking the user for input
        system("cls");
        gotoxy(30, 10);
        printf("\n1. ADD INFORMATIOn\n");
        gotoxy(30, 12);
        printf("\n2. DELETE INFORMATION\n");
        gotoxy(30, 14);
        printf("\n3. DISPLAY INFORMATION\n");
        gotoxy(30, 16);
        printf("\n4. MODIFY INFORMATION\n");
        gotoxy(30, 18);
        printf("\n5. EXIT\n");
        gotoxy(30, 20);
        printf("\nENTER YOUR CHOICE...\n");
        fflush(stdin);
        scanf("%d", &choice);

        // Switch Case
        switch (choice) {
        case 1:
  
            // Add information
            addinfo();
            break;
  
        case 2:
  
            // Delete information
            deleteinfo();
            break;
  
        case 3:
  
            // Display information
            dispinfo();
            break;
  
        case 4:
  
            // Modify information
            modinfo();
            break;
  
        case 5:

            // Exit out
            fclose(fp);
            exit(0);
            break;
  
        default:
            printf("\nINVALID CHOICE...\n");
        }
    }

return 0;
}
