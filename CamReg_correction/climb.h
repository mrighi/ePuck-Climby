#ifndef CLIMB_H
#define CLIMB_H

#define PROX_FRONT_RIGHT 			0
#define PROX_FRONT_LEFT 			7
#define PROX_DIAG_RIGHT				1
#define PROX_DIAG_LEFT				6
#define PROX_LEFT					5
#define PROX_RIGHT					2

#define X_AXIS						0
#define Y_AXIS						1
#define Z_AXIS						2

#define IMU_SAMPLE_SIZE				50 		//The base functions also use 50 idk
#define IMU_THRESHOLD				0.01	//Determined empirically

#define PROX_THRESHOLD				1000 	//Determined empirically

#define COEFF_IMU					0.6		//Determined empirically
#define COEFF_PROX					0.4		//Determined empirically

/*Thread to:
 *	- Read IMU values
 *	- Read prox values
 *	- Calculate a path
 *	- Set the motors to that path
 */
void set_path_start(void);

#endif /* CLIMB_H */
