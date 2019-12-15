#include <stdio.h>
#include <time.h>
#include <clocale>
#include <cstdlib>
#include "MyRandom.h"
#include "TreeNode.h"

void fillArrInMonual(unsigned int *arr, int size);
void fillArrInRnd(unsigned int *arr, int size);

int main()
{
    setlocale(LC_ALL, "Russian");
    MyRandom *RAND = new MyRandom(time(NULL));
    TreeNode *TREE = NULL;

    int count = 0;
    printf("Введите колическво элементов :>");
    scanf("%d", &count);
    unsigned int *arr = new unsigned int[count];

    printf("\nВведите 1: задать значения вручную");
    printf("\nВведите 2: задать значения случайными числами");
    printf("\nПо умолчанию, произойдёт заполнение случайными числами");
    printf("\nОжидание команды :>");
    int answer = 1;
    scanf("%d", &answer);
    switch(answer){
        case 1:
            fillArrInMonual(arr, count);
            break;
        case 2:
            fillArrInRnd(arr, count);
            break;
        default:
            fillArrInRnd(arr, count);
    }
    for(int i=0; i<count; i++){
       push(arr[i], &TREE);
    }

    printf("\n\nДерево имеет вид (TREE):\n");
    printTree(TREE,0);
    printf("\n\n..............................\n");
    printf("\nОбход дерева методом:\n");
    printf("Симметричный (L->Node->R) :> ");
    inorderPrint(TREE);
    printf("\nПрямой обход (Node->L->R) :> ");
    preorderPrint(TREE);

    printf("\n\n=========================================\n");
    printf("Вставка элемента в корень дерева:\n");
    unsigned int rndNum = RAND->getNextRnd(15);

    insertInRoot(&TREE,rndNum);
    printTree(TREE,0);

    printf("\n");
    system("pause");
    return 0;
}


void fillArrInMonual(unsigned int *arr, int size){
    for(int i=0; i<size; i++){
        printf("Введите элемент %d:>", i);
        scanf("%d", (arr+i));
    }
}

void fillArrInRnd(unsigned int *arr, int size){
    MyRandom *RND = new MyRandom(time(NULL));
    unsigned int maxValue = size*2;
    for(int i=0; i<size; i++){
        *(arr+i) = RND->getNextRnd(maxValue);
    }
}


