#include <stdio.h>
#include "reports.h"

void employeeReport(const Employee employees[], int count)
{
    int i;
    double total = 0;
    double highest;
    double lowest;

    if (count == 0)
    {
        printf("\nNo employee data available.\n");
        return;
    }

    highest = calculateSalary(&employees[0]);
    lowest = highest;

    for (i = 0; i < count; i++)
    {
        double salary = calculateSalary(&employees[i]);

        total += salary;

        if (salary > highest)
            highest = salary;

        if (salary < lowest)
            lowest = salary;
    }

    printf("\n========== EMPLOYEE REPORT ==========\n");
    printf("Number of employees: %d\n", count);
    printf("Total salary: N$%.2f\n", total);
    printf("Average salary: N$%.2f\n", total / count);
    printf("Highest salary: N$%.2f\n", highest);
    printf("Lowest salary: N$%.2f\n", lowest);
}

void budgetReport(const Budget budgets[], int count)
{
    int i;
    int exceeding = 0;
    double totalAllocated = 0;
    double totalExpenditure = 0;

    if (count == 0)
    {
        printf("\nNo budget data available.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;

        if (isOverBudget(&budgets[i]))
            exceeding++;
    }

    printf("\n========== BUDGET REPORT ==========\n");
    printf("Total allocated: N$%.2f\n", totalAllocated);
    printf("Total expenditure: N$%.2f\n", totalExpenditure);
    printf("Total remaining: N$%.2f\n",
           totalAllocated - totalExpenditure);
    printf("Departments exceeding budget: %d\n", exceeding);
}

void supplierReport(const Supplier suppliers[], int count)
{
    int i;

    printf("\n========== SUPPLIER REPORT ==========\n");
    printf("Number of suppliers: %d\n", count);

    for (i = 0; i < count; i++)
    {
        printf("%d. %s | %s | %s\n",
               suppliers[i].supplierID,
               suppliers[i].name,
               suppliers[i].town,
               suppliers[i].phone);
    }
}

void assetReport(const Asset assets[], int count)
{
    int i;
    double totalValue = 0;

    printf("\n========== ASSET REPORT ==========\n");
    printf("Number of assets: %d\n", count);

    for (i = 0; i < count; i++)
    {
        totalValue += assets[i].purchaseValue;

        printf("%d. %s | N$%.2f | %s\n",
               assets[i].assetID,
               assets[i].name,
               assets[i].purchaseValue,
               assets[i].condition);
    }

    printf("Total asset value: N$%.2f\n", totalValue);
}

void reportMenu(
    const Employee employees[],
    int employeeCount,
    const Budget budgets[],
    int budgetCount,
    const Supplier suppliers[],
    int supplierCount,
    const Asset assets[],
    int assetCount)
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("               REPORTS\n");
        printf("====================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Return to Main Menu\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                employeeReport(employees, employeeCount);
                break;

            case 2:
                budgetReport(budgets, budgetCount);
                break;

            case 3:
                supplierReport(suppliers, supplierCount);
                break;

            case 4:
                assetReport(assets, assetCount);
                break;

            case 5:
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);
}