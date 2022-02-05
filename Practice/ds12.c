#include <stdio.h>
#define size 100
typedef struct polynomial poly;

struct polynomial
{
    float coeff;
    int exp;
};

void readPoly(poly p[], int n)
{
    printf("Enter coefficient and power:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &p[i].coeff);
        scanf("%d", &p[i].exp);
    }
}

int addPoly(poly p1[], poly p2[], poly ans[], int n1, int n2)
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (p1[i].exp == p2[j].exp)
        {
            ans[k].coeff = p1[i].coeff + p2[j].coeff;
            ans[k].exp = p1[i].exp;
            k++;
            i++;
            j++;
        }
        else if (p1[i].exp > p2[j].exp)
        {
            ans[k].coeff = p1[i].coeff;
            ans[k].exp = p1[i].exp;
            k++;
            i++;
        }
        else
        {
            ans[k].coeff = p2[j].coeff;
            ans[k].exp = p2[j].exp;
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        ans[k].coeff = p1[i].coeff;
        ans[k].exp = p1[i].exp;
        k++;
        i++;
    }
    while (j < n2)
    {
        ans[k].coeff = p2[j].coeff;
        ans[k].exp = p2[j].exp;
        k++;
        j++;
    }
    return k;
}

int multiplyPoly(poly p1[], poly p2[], poly ans[], int n1, int n2)
{
    int i, j, k, count[size] = {0}, pos[size] = {0};
    for (k = 0; k < size; k++)
    {
        ans[k].coeff = 0;
        ans[k].exp = 0;
    }
    k = 0;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            if (p1[i].coeff != 0 && p2[j].coeff != 0)
            {
                ans[k].exp = p1[i].exp + p2[j].exp;
                if (count[ans[k].exp] >= 1)
                {
                    ans[pos[ans[k].exp]].coeff += (p1[i].coeff * p2[j].coeff);
                }
                else
                {
                    ans[k].coeff += (p1[i].coeff * p2[j].coeff);
                    count[ans[k].exp]++;
                    pos[ans[k].exp] = k;
                }
                k++;
            }
        }
    }
    return k;
}

void printPoly(poly p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i].coeff != 0)
        {
            printf("(%.2f) x^%d ", p[i].coeff, p[i].exp);
            if (i != n - 1)
                printf("+ ");
        }
    }
    printf("\n");
}

int main()
{
    poly p1[size], p2[size], ans1[size], ans2[size];
    int n1, n2;
    printf("Enter no. of distinct exponential terms for polynomial 1:");
    scanf("%d", &n1);
    readPoly(p1, n1);
    printPoly(p1, n1);
    printf("Enter no. of distinct exponential terms for polynomial 2:");
    scanf("%d", &n2);
    readPoly(p2, n2);
    printPoly(p2, n2);

    int ans1Size = addPoly(p1, p2, ans1, n1, n2);
    printf("Addition of polynomials P1 and P2:\n");
    printPoly(ans1, ans1Size);

    int ans2Size = multiplyPoly(p1, p2, ans2, n1, n2);
    printf("Multiplication of polynomials P1 and P2:\n");
    printPoly(ans2, ans2Size);

    return 0;
}