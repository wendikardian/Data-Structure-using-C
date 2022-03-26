#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct titik{
    int x;
    int y;
}Titik;

float checkDistance(int x1, int y1, int x2, int y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main() {
    int total,i,j;
    scanf("%d", &total);
    Titik pointGroup[total];
    for(i=0; i<total; i++){
        scanf("%d %d", &pointGroup[i].x,&pointGroup[i].y);
    }
    float highestDistance = 0;
    Titik selectedPoint[2];
    selectedPoint[0].x = pointGroup[0].x;
    selectedPoint[0].y = pointGroup[0].y;
    selectedPoint[1].x = pointGroup[1].x;
    selectedPoint[1].y = pointGroup[1].y;
    
    float distance;
    for(i=0; i<total; i++){
        for(j = 0; j<total; j++){
            distance = checkDistance(pointGroup[i].x, pointGroup[i].y, pointGroup[j].x, pointGroup[j].y);
            if(distance>highestDistance){
                selectedPoint[0].x = pointGroup[i].x;
                selectedPoint[0].y = pointGroup[i].y;
                selectedPoint[1].x = pointGroup[j].x;
                selectedPoint[1].y = pointGroup[j].y;
                highestDistance = distance;
            }
        }
    }

    printf("%d %d\n%d %d", selectedPoint[0].x, selectedPoint[0].y, selectedPoint[1].x, selectedPoint[1].y);
    return 0;
}
