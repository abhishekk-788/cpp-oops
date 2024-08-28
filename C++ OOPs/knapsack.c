#include <stdio.h>
#include <stdlib.h>

typedef struct object
{
    int weight, profit;
    float ratio, weight_taken;
} object;

int id_compare(const void *obj1, const void *obj2)
{
    int l = ((object *)obj1)->profit;
    int r = ((object *)obj2)->profit;
    return r - l;
}

int comp2(const void *obj1, const void *obj2)
{
    int l = ((object *)obj1)->weight;
    int r = ((object *)obj2)->weight;
    return l - r;
}

int comp3(const void *obj1, const void *obj2)
{
    float l = ((object *)obj1)->ratio;
    float r = ((object *)obj2)->ratio;

    if (l < r)
        return 1;
    else if (l > r)
        return -1;
    else
        return 0;
}

void byProfit(object obj[], int n, int w)
{
    for (int i = 0; i < n; i++)
        obj[i].weight_taken = 0;
    
    qsort(obj, n, sizeof(struct object), id_compare);

    int weight = 0;
    float profit = 0;

    for (int i = 0; i < n; i++)
    {
        if (weight + obj[i].weight < w)
        {
            profit += obj[i].profit;
            weight += obj[i].weight;
            obj[i].weight_taken = 1;
        }
        else
        {
            int rem = w - weight;

            profit += obj[i].ratio * rem;
            weight += rem;
            obj[i].weight_taken = ((float)rem) / obj[i].weight;

            break;
        }
    }

    printf("%.2f\n", profit);
}

void byWeight(object obj[], int n, int w)
{
    for (int i = 0; i < n; i++)
        obj[i].weight_taken = 0;
    
    qsort(obj, n, sizeof(struct object), comp2);

    int weight = 0;
    float profit = 0;

    for (int i = 0; i < n; i++)
    {
        if (weight + obj[i].weight < w)
        {
            profit += obj[i].profit;
            weight += obj[i].weight;
            obj[i].weight_taken = 1;
        }
        else
        {
            int rem = w - weight;

            profit += obj[i].ratio * rem;
            weight += rem;
            obj[i].weight_taken = ((float)rem) / obj[i].weight;

            break;
        }
    }

    printf("%.2f\n", profit);
}

void byRatio(object obj[], int n, int w)
{
    for (int i = 0; i < n; i++)
        obj[i].weight_taken = 0;
    
    qsort(obj, n, sizeof(struct object), comp3);

    int weight = 0;
    float profit = 0;

    for (int i = 0; i < n; i++)
    {
        if (weight + obj[i].weight < w)
        {
            profit += obj[i].profit;
            weight += obj[i].weight;
            obj[i].weight_taken = 1;
        }
        else
        {
            int rem = w - weight;

            profit += obj[i].ratio * rem;
            weight += rem;
            obj[i].weight_taken = ((float)rem) / obj[i].weight;

            break;
        }
    }

    printf("%.2f\n", profit);
}

void main()
{
    int n = 3, w = 20, choice = 1;
    object obj[n];

    obj[0].weight = 18;
    obj[0].profit = 25;
    obj[0].weight_taken = 0;

    obj[1].weight = 15;
    obj[1].profit = 24;
    obj[1].weight_taken = 0;

    obj[2].weight = 10;
    obj[2].profit = 15;
    obj[2].weight_taken = 0;

    for (int i = 0; i < n; i++)
        obj[i].ratio = obj[i].profit / ((float)obj[i].weight);

    while(choice)
    {
        printf("\n\n1. MAX PROFIT\n");
        printf("2. MINIMUM WEIGHT\n");
        printf("3. With respect to P/W");
        printf("4. EXIT\n");

        printf("\nEnter you choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            byProfit(obj, n, w);
            break;
        case 2:
            byWeight(obj, n, w);
            break;
        case 3:
            byRatio(obj, n, w);
            break;
        case 4:
            choice = 0;
            break;
        default:
            printf("\nWRONG CHOICE\n");
            break;
        }
    }
}
