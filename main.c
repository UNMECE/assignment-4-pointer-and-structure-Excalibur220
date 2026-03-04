#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index);
void free_items(Item *item_list, int size);
double average_price(Item *item_list, int size);
void print_items(Item *item_list, int size);

int main(int argc, char *argv[])
{
    int size = 5;
    Item *item_list = malloc(size * sizeof(Item));

    add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0);
    add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
    add_item(item_list, 12.99, "14512", "meat", "chicken breast", 2);
    add_item(item_list, 2.49, "55310", "produce", "bananas", 3);
    add_item(item_list, 7.97, "30001", "snacks", "chips", 4);

    print_items(item_list, size);

    double avg = average_price(item_list, size);
    printf("average price of items = %f\n", avg);

    if (argc == 2)
    {
        char *sku = argv[1];
        int ct = 0;

        while (ct < size && strcmp(item_list[ct].sku, sku) != 0)
        {
            ct++;
        }

        if (ct < size)
        {
            printf("###############\n");
            printf("item name = %s\n", item_list[ct].name);
            printf("item sku = %s\n", item_list[ct].sku);
            printf("item category = %s\n", item_list[ct].category);
            printf("item price = %f\n", item_list[ct].price);
            printf("###############\n");
        }
        else
        {
            printf("item not found\n");
        }
    }

    free_items(item_list, size);
    free(item_list);

    return 0;
}

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
    item_list[index].price = price;

    item_list[index].sku = malloc(strlen(sku) + 1);
    strcpy(item_list[index].sku, sku);

    item_list[index].category = malloc(strlen(category) + 1);
    strcpy(item_list[index].category, category);

    item_list[index].name = malloc(strlen(name) + 1);
    strcpy(item_list[index].name, name);
}

void free_items(Item *item_list, int size)
{
    int i = 0;
    while (i < size)
    {
        free(item_list[i].sku);
        free(item_list[i].category);
        free(item_list[i].name);
        i++;
    }
}

double average_price(Item *item_list, int size)
{
    double sum = 0;
    int i = 0;

    while (i < size)
    {
        sum = sum + item_list[i].price;
        i++;
    }

    return sum / size;
}

void print_items(Item *item_list, int size)
{
    int i = 0;

    while (i < size)
    {
        printf("###############\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %f\n", item_list[i].price);
        printf("###############\n");
        i++;
    }
}