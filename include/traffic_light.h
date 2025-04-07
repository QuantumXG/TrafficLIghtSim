#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

typedef enum{
    RED,
    YELLOW,
    GREEN
}LightState;

typedef struct{
    LightState state;
    int duration; // in seconds
}TrafficLight;

void initTrafficLight(TrafficLight *light); // Install a new Traffic Light and set it to RED first.
void updateTrafficLight(TrafficLight *light); // After 10s, it turns GREEN automatically.
void displayTrafficLight(TrafficLight *light); // A screen shows drivers what color it is right now.

#endif