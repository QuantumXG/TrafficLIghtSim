#include <stdio.h>
#include "traffic_light.h"

void initTrafficLight(TrafficLight *light){
    light -> state = RED;
    light -> duration = 60;
}

void updateTrafficLight(TrafficLight *light){
    switch(light-> state){

    case RED:
        light -> state = GREEN;
        light -> duration = 40;
        break;
    
    case GREEN:
        light -> state = YELLOW;
        light -> duration = 5;
        break;

    case YELLOW:
        light -> state = RED;
        light -> duration = 60;
        break;
    }
}
void displayTrafficLight(TrafficLight *light){
    const char *state_str[] = {"RED", "YELLOW", "GREEN"};
    printf("Light: %s - %d seconds remaining\n", state_str[light->state], light -> duration);
}