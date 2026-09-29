#include <stdio.h>
#include <string.h>
#include "assets.h"

void addAsset(Asset assets[], int *count)
{
    Asset *a;

    if (*count >= MAX_ASSETS)
    {
        printf("Asset list is full.\n");
        return;
    }

    a = &assets[*count];

    printf("\n========== ADD ASSET ==========\n");

    printf("Enter Asset ID: ");
    scanf("%d", &a->assetID);

    while (getchar() != '\n');

    printf("Enter asset name: ");
    fgets(a->name, sizeof(a->name), stdin);
    a->name[strcspn(a->name, "\n")] = '\0';

    if (strlen(a->name) == 0)
    {
        printf("Asset name cannot be empty.\n");
        return;
    }

    printf("Enter asset type: ");
    fgets(a->type, sizeof(a->type), stdin);
    a->type[strcspn(a->type, "\n")] = '\0';

    printf("Enter purchase value: ");
    scanf("%lf", &a->purchaseValue);

    while (getchar() != '\n');

    printf("Enter department: ");
    fgets(a->department, sizeof(a->department), stdin);
    a->department[strcspn(a->department, "\n")] = '\0';

    printf("Enter condition: ");
    fgets(a->condition, sizeof(a->condition), stdin);
    a->condition[strcspn(a->condition, "\n")] = '\0';

    (*count)++;

    printf("\nAsset added successfully!\n");
}

void displayAssets(const Asset assets[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo assets registered.\n");
        return;
    }

    printf("\n========== ASSET LIST ==========\n");

    for (i = 0; i < count; i++)
    {
        printf("\nAsset ID: %d\n", assets[i].assetID);
        printf("Name: %s\n", assets[i].name);
        printf("Type: %s\n", assets[i].type);
        printf("Purchase Value: N$%.2f\n",
               assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
    }
}

int searchAsset(const Asset assets[], int count, int assetID)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (assets[i].assetID == assetID)
            return i;
    }

    return -1;
}

void assetMenu(Asset assets[], int *count)
{
    int choice;
    int id;
    int result;

    do
    {
        printf("\n====================================\n");
        printf("          ASSET MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Return to Main Menu\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addAsset(assets, count);
                break;

            case 2:
                displayAssets(assets, *count);
                break;

            case 3:
                printf("Enter Asset ID: ");
                scanf("%d", &id);

                result = searchAsset(
                    assets, *count, id
                );

                if (result == -1)
                    printf("Asset not found.\n");
                else
                {
                    printf("Asset found!\n");
                    printf("Name: %s\n",
                           assets[result].name);
                }
                break;

            case 4:
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);
}