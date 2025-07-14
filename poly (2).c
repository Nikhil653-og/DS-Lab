#include <stdio.h>
void addpoly(int spm1[][2], int spm2[][2], int terms1, int terms2)
{
    int i = 0, j = 0, k = 0;
    int spm3[20][3];
    while (i < terms1 && j < terms2)
    {
        if (spm1[i][1] == spm2[j][1])
        {
            spm3[k][0] = spm1[i][0] + spm2[j][0];
            spm3[k][1] = spm1[i][1];
            i++, j++, k++;
        }
        else if (spm1[i][1] > spm2[j][1])
        {
            spm3[k][0] = spm1[i][0];
            spm3[k][1] = spm1[i][1];
            i++, k++;
        }
        else
        {
            spm3[k][0] = spm2[j][0];
            spm3[k][1] = spm2[j][1];
            j++, k++;
        }
    }
    while (i < terms1)
    {
        spm3[k][0] = spm1[i][0];
        spm3[k][1] = spm1[i][1];
        i++, k++;
    }
    while (j < terms2)
    {
        spm3[k][0] = spm2[j][0];
        spm3[k][1] = spm2[j][1];
        j++, k++;
    }
    for (i = 0; i < k; i++)
    {
        printf("%dx^%d+", spm3[i][0], spm3[i][1]);
    }
}
int main()
{
    int mat[10][2] = {{1, 3}, {0, 2}, {4, 1}, {2, 0}}, terms = 3, mat2[10][2] = {{3, 2}, {0, 2}, {1, 0}}, terms2 = 2;
    int spm[10][2], spm2[10][2], m = 3, n = 2, i, j, k = 0, k2 = 0;
    // int poly1[][2] = {{1, 3}, {4, 1}, {2, 0}};  // x³ + 4x + 2
    // int poly2[][2] = {{3, 2}, {1, 0}};
    for (i = 0; i < terms + 1; i++)
    {
        if (mat[i][0] != 0)
        {
            spm[k][0] = mat[i][0];
            spm[k][1] = mat[i][1];
            k++;
        }
    }
    for (i = 0; i < terms2 + 1; i++)
    {
        if (mat2[i][0] != 0)
        {
            spm2[k2][0] = mat2[i][0];
            spm2[k2][1] = mat2[i][1];
            k2++;
        }
    }
    // addpoly(mat, mat2, terms, terms2);
    addpoly(spm, spm2, k, k2);
    printf(" poly1: ");
    for (i = 0; i < k; i++)
    {
        printf("%dx^%d+", spm[i][0], spm[i][1]);
    }
    printf(" poly2: ");
    for (i = 0; i < k2; i++)
    {
        printf("%dx^%d+", spm2[i][0], spm2[i][1]);
    }
}