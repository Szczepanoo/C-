#include <stdio.h>

typedef struct{
    float x;
    float y;
} Point;

void zmienWspolrzedne(Point *p,float nowy_x, float nowy_y){
    p->x=nowy_x;
    p->y=nowy_y;
}

typedef struct {
    Point *p1;
    Point *p2;
    Point *p3;
    Point *p4;
} Rectangle;


float obliczPole(Rectangle *p_r1){

    float bok1 = p_r1->p2->y - p_r1->p1->y;
    float bok2 = p_r1->p3->x - p_r1->p1->x;

    return bok1 * bok2;
}

float obliczObwod(Rectangle  *p_r1){
    float bok1 = p_r1->p2->y - p_r1->p1->y;
    float bok2 = p_r1->p3->x - p_r1->p1->x;

    return 2 * bok1 + 2 * bok2;
}


int main(){
    Point p1 = {1.5,7.8};
    Point *p_p1 = &p1;

    zmienWspolrzedne(p_p1, 2.0,3.0);
    printf("Wsp x dla p1 po modyfikacji: %.2f \n",p1.x);
    printf("Wsp y dla p1 po modyfikacji: %.2f \n",p1.y);

    Point p2 = {2.0,8.0};
    Point p3 = {6.0,3.0};
    Point p4 = {6.0,8.0};
    Point *p_p2 = &p2;
    Point *p_p3 = &p3;
    Point *p_p4 = &p4;

    Rectangle r1 = {p_p1,p_p2,p_p3,p_p4};
    Rectangle *p_r1 = &r1;
    printf("Pole prostokata: %.2f \n",obliczPole(p_r1));
    printf("Obwod prostokata: %.2f \n",obliczObwod(p_r1));

    return 0;
}