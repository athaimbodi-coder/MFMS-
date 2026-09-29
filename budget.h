#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 50

typedef struct
{
    char department[50];
    double allocatedBudget;
    double expenditure;
} Budget;

void budgetMenu(Budget budgets[], int *count);
void addBudget(Budget budgets[], int *count);
void displayBudgets(const Budget budgets[], int count);
double calculateRemaining(const Budget *budget);
int isOverBudget(const Budget *budget);
int searchBudget(const Budget budgets[], int count, const char department[]);

#endif