#include <stdio.h>
#include <string.h>
#include "budget.h"

void addBudget(Budget budgets[], int *count)
{
    if (*count >= MAX_BUDGETS)
    {
        printf("Budget list is full.\n");
        return;
    }

    printf("\n========== ADD BUDGET ==========\n");

    while (getchar() != '\n');

    printf("Enter department: ");
    fgets(budgets[*count].department,
          sizeof(budgets[*count].department), stdin);

    budgets[*count].department[
        strcspn(budgets[*count].department, "\n")
    ] = '\0';

    if (strlen(budgets[*count].department) == 0)
    {
        printf("Department cannot be empty.\n");
        return;
    }

    printf("Enter allocated budget: ");
    scanf("%lf", &budgets[*count].allocatedBudget);

    printf("Enter expenditure: ");
    scanf("%lf", &budgets[*count].expenditure);

    (*count)++;

    printf("\nBudget added successfully!\n");
}

double calculateRemaining(const Budget *budget)
{
    return budget->allocatedBudget - budget->expenditure;
}

int isOverBudget(const Budget *budget)
{
    if (budget->expenditure > budget->allocatedBudget)
        return 1;

    return 0;
}

void displayBudgets(const Budget budgets[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo budgets registered.\n");
        return;
    }

    printf("\n========== BUDGET LIST ==========\n");

    for (i = 0; i < count; i++)
    {
        printf("\nDepartment: %s\n", budgets[i].department);
        printf("Allocated Budget: N$%.2f\n",
               budgets[i].allocatedBudget);
        printf("Expenditure: N$%.2f\n",
               budgets[i].expenditure);
        printf("Remaining Budget: N$%.2f\n",
               calculateRemaining(&budgets[i]));

        if (isOverBudget(&budgets[i]))
            printf("Status: OVER BUDGET\n");
        else
            printf("Status: WITHIN BUDGET\n");
    }
}

int searchBudget(const Budget budgets[], int count,
                 const char department[])
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (strcmp(budgets[i].department, department) == 0)
            return i;
    }

    return -1;
}

void budgetMenu(Budget budgets[], int *count)
{
    int choice;
    char department[50];
    int result;

    do
    {
        printf("\n====================================\n");
        printf("          BUDGET MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Enter Department Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Search Department\n");
        printf("4. Show Departments Over Budget\n");
        printf("5. Return to Main Menu\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBudget(budgets, count);
                break;

            case 2:
                displayBudgets(budgets, *count);
                break;

            case 3:
                while (getchar() != '\n');

                printf("Enter department: ");
                fgets(department, sizeof(department), stdin);

                department[
                    strcspn(department, "\n")
                ] = '\0';

                result = searchBudget(
                    budgets, *count, department
                );

                if (result == -1)
                {
                    printf("Department not found.\n");
                }
                else
                {
                    printf("Department found!\n");
                    printf("Remaining Budget: N$%.2f\n",
                           calculateRemaining(&budgets[result]));
                }
                break;

            case 4:
            {
                int i;
                int found = 0;

                printf("\n--- DEPARTMENTS OVER BUDGET ---\n");

                for (i = 0; i < *count; i++)
                {
                    if (isOverBudget(&budgets[i]))
                    {
                        printf("%s is over budget by N$%.2f\n",
                               budgets[i].department,
                               -calculateRemaining(&budgets[i]));

                        found = 1;
                    }
                }

                if (!found)
                    printf("No departments are over budget.\n");

                break;
            }

            case 5:
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);
}