/**
*@file Task2_z_2
*@brief solution (C++ code) of Task2.2 GL 
* (2.З клавіатури ввести послідовність даних, які є координатами протилежних вершин прямокутників. 
* Роздрукувати введені дані у вигляді таблиці, відсортувавши їх за зростанням лівої координати x прямокутника. 
*  Визначити два прямокутники з найбільшою і найменшою площею.)
*
*Copyright 2014 by Roman Bojko
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define N 50
#define _p2(x) (x)*(x)


typedef unsigned long UL;
typedef unsigned int UI;
typedef unsigned char UC;

enum emsg
{
    SUCCESS,
    ERROR
};

typedef struct coords
{
   double x1, y1, x2, y2, S;
} COORDS;


/**
*@brief Функція обчислює площу прямокутника 
*@param [in] rect вказівник COORDS структури
*@return void
*/
void RectS(COORDS * rect);

/**
*@brief Фунуія сортує структуру в масиві (key - left x coordinate)
*@param [in] mas вказівник на першу COORDS структуру в масиві
*@param [in] n кількість структур в масиві
*@return void
*/
void sort(COORDS ** mas, UC n);

int main()
{
    COORDS *mas[N], **maxS = mas, **minS = mas;
    UC i, n;

    puts("\n Enter please coordinates of a rectangle:\n (alpha symbol in first coordinate - end of inputting)\n");

    for(i = 0; i < N; ++i)
    {
        mas[i] = malloc( sizeof(COORDS) );
        if( !mas[i] )
        {
            puts(" Memory error!");
            getch();
            return 1;
        }

        printf("\n\t Rectangle #%d:\n", i + 1);
        printf("\n Left top coordinates (x y): ");

        if ( !scanf("%lf%lf", &mas[i] -> x1, &mas[i] -> y1) ) break;

        printf("\n Right bottom coordinates (x y): ");

         if ( !scanf("%lf%lf", &mas[i] -> x2, &mas[i] -> y2) ) break;

        RectS(mas[i]);
    }
    n = i;

    sort(mas, n);

    for(i = 0; i < n; ++i)
    {
             if(mas[i] -> S > ( *maxS ) -> S) maxS = &mas[i];
       else  if(mas[i] -> S < ( *minS ) -> S) minS = &mas[i];

        printf("\n-------------------------\n\n\t Rectangle #%d:\n", i+1);
        printf("\n Left top coordinates (%.2lf, %.2lf) ", mas[i] -> x1, mas[i] -> y1);
        printf("\n Right bottom coordinates (%.2lf, %.2lf) ", mas[i] -> x2, mas[i] -> y2);
        printf("\n S = %.2lf", mas[i] -> S);
    }


    printf("\n\n Max square: %.2lf", ( *maxS ) -> S);
    printf("\n Min square: %.2lf", ( *minS ) -> S);


    for(i = 0; i < n; ++i)
    {
        free(mas[i]);
    }

    system("pause");
    return SUCCESS;
}

void RectS(COORDS * rect)
{
    if(rect == NULL)
    {
       puts(" ERROR. NULL pointer used");
       _getch();
       exit(ERROR);
    }
   rect -> S = sqrt( _p2( rect -> y2 -  rect -> y1) ) * sqrt( _p2( rect -> x2 - rect -> x1) );  // S = h * w;
}

void sort(COORDS ** mas, UC n)
{
    if(mas == NULL)
    {
       puts(" ERROR. NULL pointer used");
       _getch();
       exit(ERROR);
    }

  UC i, j;
  COORDS *tmp;

  for(j = 0; j < n; ++j)
   {
      for(i = 0; i < n - 1; ++i)
      {
         if (mas[i] -> x1 > mas[i + 1] -> x1)
         {
            tmp = mas[i + 1];
            mas[i + 1] = mas[i];
            mas[i] = tmp;
         }
      }
   }

}
