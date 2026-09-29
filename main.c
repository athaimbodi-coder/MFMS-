#include <stdio.h>

#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

void displayMenu(void);

int main(void)
{
    Employee employees[MAX_EMPLOYEES];
    Budget budgets[MAX_BUDGETS];
    Supplier suppliers[MAX_SUPPLIERS];
    Asset assets[MAX_ASSETS];

    int employeeCount = 0;
    int budgetCount = 0;
    int supplierCount = 0;
    int assetCount = 0;

    int choice;

    do
    {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                employeeMenu(employees, &employeeCount);
                break;

            case 2:
                budgetMenu(budgets, &budgetCount);
                break;

            case 3:
                supplierMenu(suppliers, &supplierCount);
                break;

            case 4:
                assetMenu(assets, &assetCount);
                break;

            case 5:
                reportMenu(
                    employees,
                    employeeCount,
                    budgets,
                    budgetCount,
                    suppliers,
                    supplierCount,
                    assets,
                    assetCount
                );
                break;

            case 6:
                printf("\n====================================\n");
                printf("    Thank you for using MFMS!\n");
                printf("====================================\n");
                break;

            default:
                printf("\nInvalid choice.\n");
                printf("Please choose a number from 1 to 6.\n");
        }

    } while (choice != 6);

    return 0;
}

void displayMenu(void)
{
    printf("\n");
    printf("============================================\n");
    printf("   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("============================================\n");
}