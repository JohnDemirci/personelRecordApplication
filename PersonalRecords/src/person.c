#include "person.h"

LIST *head = NULL, *tail = NULL;

void inputPersonalData(PERSON *person)
{
    // TODO Implement the function

    // adding person to the list
    printf("\nplease enter the person's name\n");
    scanf("%s", person->name);
    printf("\nplease enter the person's age");
    scanf("%d", &person->age);
    printf("\nenter the person's height");
    scanf("%f", &person->height);

    printf("\nenter the person's birthdate");
    scanf("%d / %d / %d", &person->bday.month, &person->bday.day, &person->bday.year);

    printf("\n%s %d %0.1f %d / %d / %d", person->name, person->age, person->height, person->bday.month,
            person->bday.day, person->bday.year);

}

void addPersonalDataToDatabase(PERSON *person)
{
    // TODO Implement the function
    add(&head, &tail, person);
}

void displayDatabase()
{
    // TODO Implement the function
    LIST *temp = head;

    while (temp != NULL) {
        // display the database
        displayPerson(temp->data);
        temp = temp->next;
    }
}

void displayPerson(PERSON *person)
{
    // TODO Implement the function
    printf("\n%s %d %0.1f %d / %d / %d", person->name, person->age, person->height, person->bday.month,
           person->bday.day, person->bday.year);
}

PERSON *findPersonInDatabase(char *name)
{
    // TODO Implement the function

    LIST *temp = head;
    while (temp->next != NULL) {
        int true = strcmp(temp->data, name);
        if (true == 0) {
            return temp->data;
        }
        temp = temp->next;
    }
    return NULL; // if not found
}

void removePersonFromDatabase(char *name)
{
    // TODO Implement the function
    printf("does it work");
    LIST *temp = head;
    while (temp->next != NULL) {
        int true = strcmp(temp->data, name);
        if (true == 0) {
            delete(&head, &tail, temp->data);
        }
        temp = temp->next;
    }
}

void clearDatabase()
{
    // TODO Implement the function
    clearRecursively(&head, &tail);
}
