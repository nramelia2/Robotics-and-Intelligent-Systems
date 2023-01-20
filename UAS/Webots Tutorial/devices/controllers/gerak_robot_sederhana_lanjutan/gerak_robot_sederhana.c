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

  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
   
   wb_motor_set_position(right_motor, INFINITY);
   wb_motor_set_position(left_motor, INFINITY);
   /* berfungsi sebagai loop, agar program dijalankan secara berulang-ulang */
  while (wb_robot_step(TIME_STEP) != -1) {
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */

    /* Process sensor data here */

    /*
     * Enter here functions to send actuator commands, like:
     * wb_motor_set_position(my_actuator, 10.0);
     */
     
     wb_motor_set_velocity(right_motor, 5.0);
     wb_motor_set_velocity(left_motor, -5.0);
     
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
