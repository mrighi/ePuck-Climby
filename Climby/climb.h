#ifndef CLIMB_H_
#define CLIMB_H_

#ifdef __cplusplus
extern "C" {
#endif

#define ATAN_TO_BEARING				64		//approx 100*2/pi

#define BEARING_MAX					100
#define BEARING_I_MAX				300		//Empirical

#define SPEED_BASE					500		//Base movement speed

#define IMU_GO_STRAIGHT_THRESHOLD	200		//Empirical

#define IMU_TOP_MAX_X				400		//Threshold values for top reached detection (empirical)
#define IMU_TOP_MIN_X				-400
#define IMU_TOP_MAX_Y				400
#define IMU_TOP_MIN_Y				-900
#define IMU_TOP_MAX_Z				400
#define IMU_TOP_MIN_Z				-400

#define PROX_DIST_MIN				120		// (mm) Threshold obstacle detection distance (empirical)

#define PROX_DEC_COEFF				1		//Empirical

#define PROX_CORRECTION				65		//Empirical

//PI controller
#define Kp							5
#define Ti							100 	//NEVER SET TO ZERO !!!

/**
* Convention used throughout for bearings: trigonometric direction
* (0,100] = left, 0 = straight, [-100, 0) = right
*/

 /**
 * @brief	Used to find the rotational correction value to maximize climb
 *
 * @param	Accelerometer values from the three axes
 * 			Assumes x,y,z acceleration is zero when the robot is parallel to the ground
 *
 * @return	A bearing value [-100,100] proportional to the angle between
 * 				the robot's direction of movement and the axis of maximal climb
 */
int8_t imu_bearing(int16_t acc_x, int16_t acc_y);

/**
* @brief	Used to find the rotational correction value to avoid obstacles
* 			Chooses an arbitrary direction which is toggled  at every subsequent obstacle
*
* @param	ToF sensor distance value in mm
*
* @return	PROX_CORRECTION if the ToF sees an obstacle at most PROX_DIST_MIN mm away,
* 				zero otherwise
*/
int8_t prox_bearing(uint16_t dist_mm);

/**
* @brief	PI controller
*
* @param	A bearing value [-100,100]
*/
void move(int8_t bearing);

/**
* @brief	Start the movement thread : continually collects accelerometer and ToF sensor
* 				values and sets the motor speeds accordingly
*/
void set_path_start(void);

#endif /* CLIMB_H_ */
