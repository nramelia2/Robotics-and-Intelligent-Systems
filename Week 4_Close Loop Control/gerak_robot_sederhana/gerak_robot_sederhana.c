/*
 * File:          gerak_robot_sederhana.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/motor.h>, etc.
 */
/* library*/
#include <webots/robot.h> 
#include <webots/motor.h> 
#include <webots/distance_sensor.h>
#include <stdio.h>

/*
 * You may want to add macros here.
 */
 /* waktu eksekusi */
#define TIME_STEP 64

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv) {
  /* necessary to initialize webots stuff */
  /* digunakan untuk memulai program robot*/
  wb_robot_init();

  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
   
   WbDeviceTag right_motor = wb_robot_get_device("right wheel motor");
   WbDeviceTag left_motor = wb_robot_get_device("left wheel motor");
   WbDeviceTag sensor0 = wb_robot_get_device("ps0");
   WbDeviceTag sensor7 = wb_robot_get_device("ps7");
   WbDeviceTag sensor1 = wb_robot_get_device("ps1");
   WbDeviceTag sensor6 = wb_robot_get_device("ps6");

  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
   
   wb_motor_set_position(right_motor, INFINITY);
   wb_motor_set_position(left_motor, INFINITY);
   wb_distance_sensor_enable(sensor0, TIME_STEP);
   wb_distance_sensor_enable(sensor7, TIME_STEP);
   wb_distance_sensor_enable(sensor1, TIME_STEP);
   wb_distance_sensor_enable(sensor6, TIME_STEP);
   
   /* berfungsi sebagai loop, agar program dijalankan secara berulang-ulang */
  while (wb_robot_step(TIME_STEP) != -1) {
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */
     
     double nilai_sensor0;
     double nilai_sensor7;
     double nilai_sensor1;
     double nilai_sensor6;
     
     double nilai_right_motor;
     double nilai_left_motor;
     
     nilai_sensor0 = wb_distance_sensor_get_value(sensor0);
     nilai_sensor7 = wb_distance_sensor_get_value(sensor7);
     nilai_sensor1 = wb_distance_sensor_get_value(sensor1);
     nilai_sensor6 = wb_distance_sensor_get_value(sensor6);
     
     printf("sensor0=");
     printf("%f\n", nilai_sensor0);
     printf("sensor7=");
     printf("%f\n", nilai_sensor7);
     
     printf("sensor1=");
     printf("%f\n", nilai_sensor1);
     printf("sensor6=");
     printf("%f\n", nilai_sensor6);

    /* Process sensor data here */
     
     if(nilai_sensor0<90 && nilai_sensor7<90 && nilai_sensor1<90 && nilai_sensor6<90)
     {
       nilai_right_motor = 5;
       nilai_left_motor = 5;
     }
     else
     {
       nilai_right_motor = -5;
       nilai_left_motor = 5;
     }
    /*
     * Enter here functions to send actuator commands, like:
     * wb_motor_set_position(my_actuator, 10.0);
     */
     
     wb_motor_set_velocity(right_motor, nilai_right_motor);
     wb_motor_set_velocity(left_motor, nilai_left_motor);
     
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
