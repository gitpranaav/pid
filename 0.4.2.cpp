#include <stdio.h>
#include <unistd.h>

double Kp=2;
double Ki=0.1;
double Kd=0.3;
double tempKd=0.3;

#define dt 0.1  // Time step

    double setpoint  = 1.0;

// Function
double computePID(double setpoint, double current_position, double *prev_error, double *integral) {
    double error = setpoint - current_position;
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
    int scaledPosition = (int)((position + 1.0) * 0.5 * factor);

    for (int i = factor; ; i--) {
    if ((i-1) != scaledPosition)
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
    int scaledPosition = (int)(((position)) * 0.5 * factor );
    for (j=0;j<(49-scaledPosition);j++){
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
    for(int j=10;j<(scaledPosition);j++){
    printf(" ");}
    printf("|");

    printf("\n");

  }

}

int main() {
 double am;
  printf("Enter the amount of time you want to reach the set point:");
   scanf("%lf",&am);
  Kd=(tempKd*51.3)/am;

    double ball_position = 5.0;
    double ball_velocity = 0.5;

    double prev_error = 0.0;
    double integral = 0.0;

    // Simulation loop
    for (int i = 0,dump=1; i < (10*am)+50; i++) {
        double control_output = computePID(setpoint, ball_position, &prev_error, &integral);

        simulateSystem(ball_position, ball_velocity, control_output);


       printf("Time: %.2f, Position: %.2f, Control Output: %.2f\n", i * dt, ball_position, control_output);
      if((dump==1)&&((am-(i * dt))<=2.00)){
       Kp-=1;
       dump++;
       }
       usleep(10000);
    }
    printf("\nEnter the Kp,Ki,Kd values for displaying the graph :");
    scanf("%lf",&Kp);
    scanf("%lf",&Ki);
    scanf("%lf",&Kd);
     ball_position = 5.0;
     ball_velocity = 0.5;
     prev_error = 0.0;
     integral = 0.0;
     for (int i = 0,dump=1; i < 1000; i++) {
        double control_output = computePID(setpoint, ball_position, &prev_error, &integral);

        simulateSystem(ball_position, ball_velocity, control_output);
           // Display graph
       displayGraph(ball_position);

       //printf("Time: %.2f, Position: %.2f, Control Output: %.2f\n", i * dt, ball_position, control_output);
      if((dump==1)&&((am-(i * dt))<=2.00)){
       Kp-=1;
       dump++;
       }
       usleep(10000);
    }

    return 0;
}
