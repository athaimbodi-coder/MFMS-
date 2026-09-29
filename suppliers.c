#include <stdio.h>
#include <string.h>
#include "suppliers.h"

void addSupplier(Supplier suppliers[], int *count)
{
    Supplier *s;

    if (*count >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full.\n");
        return;
    }

    s = &suppliers[*count];

    printf("\n========== ADD SUPPLIER ==========\n");

    printf("Enter Supplier ID: ");
    scanf("%d", &s->supplierID);

    while (getchar() != '\n');

    printf("Enter supplier name: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0';

    if (strlen(s->name) == 0)
    {
        printf("Supplier name cannot be empty.\n");
        return;
    }

    printf("Enter email: ");
    fgets(s->email, sizeof(s->email), stdin);
    s->email[strcspn(s->email, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(s->phone, sizeof(s->phone), stdin);
    s->phone[strcspn(s->phone, "\n")] = '\0';

    printf("Enter town/location: ");
    fgets(s->town, sizeof(s->town), stdin);
    s->town[strcspn(s->town, "\n")] = '\0';

    (*count)++;

    printf("\nSupplier added successfully!\n");
}

void displaySuppliers(const Supplier suppliers[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo suppliers registered.\n");
        return;
    }

    printf("\n========== SUPPLIER LIST ==========\n");

    for (i = 0; i < count; i++)
    {
        printf("\nSupplier ID: %d\n", suppliers[i].supplierID);
        printf("Name: %s\n", suppliers[i].name);
        printf("Email: %s\n", suppliers[i].email);
        printf("Phone: %s\n", suppliers[i].phone);
        printf("Town/Location: %s\n", suppliers[i].town);
    }
}

int searchSupplier(const Supplier suppliers[], int count, int supplierID)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (suppliers[i].supplierID == supplierID)
            return i;
    }

    return -1;
}

int searchSupplierByName(const Supplier suppliers[], int count,
                         const char name[])
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (strcmp(suppliers[i].name, name) == 0)
            return i;
    }

    return -1;
}

void supplierMenu(Supplier suppliers[], int *count)
{
    int choice;
    int id;
    int result;
    char name[50];

    do
    {
        printf("\n====================================\n");
        printf("         SUPPLIER MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier by ID\n");
        printf("4. Search Supplier by Name\n");
        printf("5. Return to Main Menu\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addSupplier(suppliers, count);
                break;

            case 2:
                displaySuppliers(suppliers, *count);
                break;

            case 3:
                printf("Enter Supplier ID: ");
                scanf("%d", &id);

                result = searchSupplier(
                    suppliers, *count, id
                );

                if (result == -1)
                    printf("Supplier not found.\n");
                else
                {
                    printf("Supplier found!\n");
                    printf("Name: %s\n",
                           suppliers[result].name);
                }
                break;

            case 4:
                while (getchar() != '\n');

                printf("Enter supplier name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                result = searchSupplierByName(
                    suppliers, *count, name
                );

                if (result == -1)
                    printf("Supplier not found.\n");
                else
                {
                    printf("Supplier found!\n");
                    printf("Name: %s\n",
                           suppliers[result].name);
                }
                break;

            case 5:
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);
}