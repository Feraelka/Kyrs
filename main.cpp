#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<locale.h>
#include<time.h>
#include<iostream>
#include<queue>
#include<stack>
#include<windows.h>
#include<fstream>
#include<iostream>
using namespace std;
const int maxV = 100;
int i, j, n, variant;
int GR[maxV][maxV], D[maxV][maxV];
FILE* F;

void printM(int M[][maxV]) {
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}
void copyM(int M[][maxV], int M1[][maxV]) {
    for (char i = 0; i < n; i++)
    {
        for (char j = 0; j < n; j++)
        {
            M1[i][j] = M[i][j];
        }
    }
}

void FU(int R[][maxV], int V)
{
    int k;
    copyM(R, D);
    for (i = 0; i < V; i++) D[i][i] = 0;

    for (k = 0; k < V; k++)
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                if (D[i][k] && D[k][j] && i != j)
                    if (D[i][k] + D[k][j] < D[i][j] || D[i][j] == 0)
                        D[i][j] = D[i][k] + D[k][j];
}
void orgraf(int R[maxV][maxV]) {
    printf("Введите порядок орграфа:");
    cin >> n;
    if (n < 0)
    {
        printf("\n Введен недопустимый символ\n");
        _getch();
        system("cls");
        printf("Введите порядок орграфа:");
        cin >> n;
    }
    if (n > 100)
    {
        printf("\n Введенное число превосходит допустимое значение(100) \n");
        _getch();
        system("cls");
        printf("Введите порядок орграфа:");
        cin >> n;
    }
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                R[i][j] = 0;
            else
                R[i][j] = rand() % 10;
        }
    }
}
void saveorg1(int R[][maxV]) {
    if ((F = fopen("Output.txt", "a")) == 0)
        printf("Невозможно открыть/создать для записи файл 'Output.txt'\n");
    else
    {
        fprintf(F, "Матрица весов ребер: \n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fprintf(F, " %d ", R[i][j]);
            }
            fprintf(F, "\n ");
        }
    }
    fclose(F);
}
void saveorg2(int R[][maxV]) {
    if ((F = fopen("Output.txt", "a")) == 0)
        printf("Невозможно открыть/создать для записи файл 'Output.txt'\n");
    else
    {
        fprintf(F, "Матрица кратчайших путей: \n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fprintf(F, " %d ", R[i][j]);
            }
            fprintf(F, "\n ");
        }
    }
    fclose(F);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    printf("Создание матрицы динамически \n");

    orgraf(GR);
    cout << "Матрица весов ребер:\n";
    printM(GR);

    cout << "Матрица кратчайших путей:" << endl;
    FU(GR, n);
    printM(D);
    printf("Сохранить результаты в файл? Ваш ответ (1 - да, 2 - нет):");
    cin >> variant;
    if (variant != 1 && variant != 2) {
        printf("Введен недопустимый символ. Введите ваш ответ: ");
        cin >> variant;
    }
    else {
        if (variant == 1) {
            saveorg1(GR);
            saveorg2(D);
            cout << "Сохранение выполнено успешно.\n";
        }
    }
    system("pause>>void");
}
