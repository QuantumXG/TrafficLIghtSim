#include <stdio.h>
#include <unistd.h> // For sleep()

// Define the states of the traffic light
typedef enum {
    RED,
    YELLOW,
    GREEN
} TrafficLightState;

// Define the TrafficLight structure
typedef struct {
    TrafficLightState state;
    int duration; // Duration in seconds
} TrafficLight;

// Initialize the traffic light
void initTrafficLight(TrafficLight *light) {
    light->state = RED;
    light->duration = 60;
}

// Update the traffic light state
void updateTrafficLight(TrafficLight *light) {
    switch (light->state) {
        case RED:
            light->state = GREEN;
            light->duration = 40;
            break;

        case GREEN:
            light->state = YELLOW;
            light->duration = 5;
            break;

        case YELLOW:
            light->state = RED;
            light->duration = 60;
            break;
    }
}

// Display the current state of the traffic light
void displayTrafficLight(TrafficLight *light) {
    const char *state_str[] = {"RED", "YELLOW", "GREEN"};
    printf("Light: %s - %d seconds remaining\n", state_str[light->state], light->duration);
}

// Main function to demonstrate the traffic light functionality
int main() {
    TrafficLight light;

    // Initialize the traffic light
    initTrafficLight(&light);

    // Simulate the traffic light cycle
    for (int i = 0; i < 6; i++) { // Run 6 cycles for demonstration
        while (light.duration > 0) {
            displayTrafficLight(&light);
            sleep(1); // Wait for 1 second
            light.duration--; // Decrement the duration
        }
        updateTrafficLight(&light); // Move to the next state
    }

    return 0;
}