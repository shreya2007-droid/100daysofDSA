/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;
    return c2->position - c1->position; 
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];
    
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }
    
    qsort(cars, n, sizeof(Car), compare);
    
    int fleets = 0;
    double prevTime = 0.0;
    
    for (int i = 0; i < n; i++) {
        double currTime = (double)(target - cars[i].position) / cars[i].speed;
        
        if (currTime > prevTime) {
            fleets++;
            prevTime = currTime;
        }
    }
    
    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = 5;
    
    int result = carFleet(target, position, speed, n);
    printf("Number of Car Fleets: %d\n", result);
    
    return 0;
}