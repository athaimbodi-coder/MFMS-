#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

typedef struct
{
    int assetID;
    char name[50];
    char type[50];
    double purchaseValue;
    char department[50];
    char condition[30];
} Asset;

void assetMenu(Asset assets[], int *count);
void addAsset(Asset assets[], int *count);
void displayAssets(const Asset assets[], int count);
int searchAsset(const Asset assets[], int count, int assetID);

#endif