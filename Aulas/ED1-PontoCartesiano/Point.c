#include <stdio.h>
typedef struct {
    float x,y;
}Point;
void SetCoordinates(Point* point,float x,float y){
    point->x = x;
    point->y = y;
}
void PrintPoint(Point* point){
    printf("The point has:\nAbscissa %.2f\nand\nOrdered %.2f\n",point->x,point->y);
}
