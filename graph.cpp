#include <stdio.h>
#include <unistd.h>

#define Kp 1
#define Ki 0.1
double Kd=0.5;

#define dt 0.1  // Time step

    double setpoint  = 1.0;

// Function
double computePID(double setpoint, double current_position, double *prev_error, double *integral) {
    double error = setpoint - current_position;
    /*if (error<0.7){
    Kd=1;
    }*/
    double derivative = (error - *prev_error) / dt;

    *integral += error * dt;

    // PID  eq
    double output = Kp * error + Ki * (*integral) + Kd * derivative;

    *prev_error = error;

    return output;
}

//  system dynamics
void simulateSystem(double &position, double &velocity, double force) {
    velocity += force * dt;
    position += velocity * dt;
}

// graph
void displayGraph(double position) {
   printf("\n");
    if(position<setpoint){
    printf("\t\t\t\t\t|");
    int factor = 20;
    int scaled = (int)((position + 1.0) * 0.5 * factor);

    for (int i = factor; ; i--) {
    if ((i-1) != scaled)
            printf(" ");
       else{
            printf("#");
            break;
             }

    }

    printf("\n");
}
if(position>setpoint){
int j;
  int factor = 20;
    int scaled = (int)(((position)) * 0.5 * factor );
    for (j=0;j<(49-scaled);j++){
    printf(" ");
    }
    if(j!=0){
    printf("#");}
    else{
    printf("\t\t\t\t\t|");
    printf("\n");
    return;
    }
    /*for ( i= graphHeight; i > 2; --i) { //wrong code

        if (i == scaledPosition){
            printf("*");
            }
        else
            printf(" ");

    }*/
    for(int j=10;j<(scaled);j++){
    printf(" ");}
    printf("|");

    printf("\n");

  }

}

int main() {
    double position = 5.0;
    double velocity = 0.5;
    //velocity will be decreased ,as motor spped is decreased

     printf("\033[?7l");

    double prev_error = 0.0;
    double integral = 0.0;

    // Simulation loop
    for (int i = 0; i < 1000; ++i) {
        double control_output = computePID(setpoint, position, &prev_error, &integral);
//ballposition=position
        simulateSystem(position, velocity, control_output);

        // Display graph
       displayGraph(position);


       //printf("Time: %.2f, Position: %.2f, Control Output: %.2f\n", i * dt, ball_position, control_output);
        usleep(10000);
    }

    return 0;
}

