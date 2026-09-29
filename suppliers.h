#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100

typedef struct
{
    int supplierID;
    char name[50];
    char email[80];
    char phone[30];
    char town[50];
} Supplier;

void supplierMenu(Supplier suppliers[], int *count);
void addSupplier(Supplier suppliers[], int *count);
void displaySuppliers(const Supplier suppliers[], int count);
int searchSupplier(const Supplier suppliers[], int count, int supplierID);
int searchSupplierByName(const Supplier suppliers[], int count,
                         const char name[]);

#endif