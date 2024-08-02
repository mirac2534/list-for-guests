#include <stdio.h>
#include <stdlib.h>

struct Contact
{
    char firstName[30];
    char lastName[30];
    char phoneNumber[11];
    char emailAddress[50];
};

int addContact(struct Contact [],int);// in this funciton, addition is made
void displayContacts(struct Contact [],int);// in this function, shows the addition

int main()
{
   struct Contact addressBook[100];//adress book max for 100 people
   int contactCount=0;
   int choice;

do//we use do-while to do menu
{

printf("\n Address Book Menu:  \n");
printf("1. Add Contact\n");
printf("2. Display contact\n");
printf("3. Exit\n");
printf("Enter your choice:");
scanf("%d",&choice);

switch(choice)
{
case 1:
    contactCount=addContact(addressBook,contactCount)==1?contactCount+1:contactCount;
    break;

case 2:
    displayContacts(addressBook,contactCount);
    break;

case 3:
    printf("Exiting the program\n");
    break;
default:
    printf("Invalid choice.Please enter a valid option\n");
}
}while(choice!=3);
return 0;
}

int addContact(struct Contact addressBook[],int contactCount)// this function is useful for addition
{
    if (contactCount<100)
    {
        struct Contact newContact;

        printf("Enter First Name: ");//we enter first name
        scanf("%s",newContact.firstName);
        printf("Enter Last Name: ");//we enter last name
        scanf("%s",newContact.lastName);
        printf("Enter Phone Number: ");//we enter phone number
        scanf("%s",newContact.phoneNumber);
        printf("Enter email Address: ");//we enter e-mail address
        scanf("%s",newContact.emailAddress);

        addressBook[contactCount]=newContact;
        printf("contact added successfully\n");
        return 1;
    }
        else
        {
            printf("Address Book is full.Cannot add more contact\n");

        }
return 0;
}

void displayContacts(struct Contact addressBook[],int contactCount)//this function is useful for show/display addition
{
    if(contactCount>0)
    {
        printf("\n Contacts in the Address Book:\n");
        printf("%-15s %-15s %-15s %-30s","First Name","Last Name","Phone Number","Email Address");
        for(int i=0;i<contactCount;i++)
        {
            printf("%-15s %-15s %-15s %-30s",
                   addressBook[i].firstName,
                   addressBook[i].lastName,
                   addressBook[i].phoneNumber,
                   addressBook[i].emailAddress);

        }
    }
    else
    {
        printf("Address Book is empty . No Contact to display");
    }



}
