#include "Circle.h"
#include <math.h>
#include <stdio.h>
void SetRadius(Circle* circle,float radius){
    circle->r = radius;
}
void PrintCircle(Circle* circle){
    float area,radius;
    radius = circle->r;
    area =  M_PI*radius*radius;
    printf("The area of a circle with %.2f radious is:\nArea = %.2f\n",radius,area);
}