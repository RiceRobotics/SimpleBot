/*
 * Welcome to the RiceBot library!
 *
 * This library was written for use by the Rice University Vex U Robotics team.
 * All are welcome to use and modify the library, so long as due credit is given to the creator.
 * If you have questions/comments/suggestions, email me at Keiko.F.Kaplan@rice.edu
 *
 * This library was written to be used with the Purdue Robotic Operating System.
 *
 * Author: Keiko Kaplan
 */

#include "RiceBot.h"

/*
 * A simple function to set all 3 fields of a Motor.
 *
 * @param m The motor struct to be initialized
 * @param port The port on the Cortex which the motor is plugged into
 * @param out The power output to the motor, between -127 and 127
 * @param reflected If the output to the motor should be reversed. -1 or 1
 *
 * @returns The configured Motor struct
 */
Motor initMotor(Motor m, int port, int out, int reflected) {
	m.port = port;
	m.out = out;
	m.reflected = reflected;
	return m;
}

void riceBotInitializeIO() {

}

/*
 * Call this from the default Initialize function.
 * After, be sure to reinitialize each motor you will be using on your robot.
 */
void riceBotInitialize() {
	Motor DTFrontRight;
	DTFrontRight = initMotor(DTFrontRight, 0, 0, 1);
	Motor DTFrontMidRight;
	DTFrontMidRight = initMotor(DTFrontMidRight, 0, 0, 1);
	Motor DTMidRight;
	DTMidRight = initMotor(DTMidRight, 0, 0, 1);
	Motor DTBackRight;
	DTBackRight = initMotor(DTBackRight, 0, 0, 1);
	Motor DTFrontLeft;
	DTFrontLeft = initMotor(DTFrontLeft, 0, 0, 1);
	Motor DTFrontMidLeft;
	DTFrontMidLeft = initMotor(DTFrontMidLeft, 0, 0, 1);
	Motor DTMidLeft;
	DTMidLeft = initMotor(DTMidLeft, 0, 0, 1);
	Motor DTBackLeft;
	DTBackLeft = initMotor(DTBackLeft, 0, 0, 1);

	Motor ARMRight;
	ARMRight = initMotor(ARMRight, 0, 0, 1);
	Motor ARMLeft;
	ARMLeft = initMotor(ARMLeft, 0, 0, 1);
	Motor ARMTopRight;
	ARMTopRight = initMotor(ARMTopRight, 0, 0, 1);
	Motor ARMBottomRight;
	ARMBottomRight = initMotor(ARMBottomRight, 0, 0, 1);
	Motor ARMTopLeft;
	ARMTopLeft = initMotor(ARMTopLeft, 0, 0, 1);
	Motor ARMBottomLeft;
	ARMBottomLeft = initMotor(ARMBottomLeft, 0, 0, 1);

}

/*
 * Checks joystick input and sets all Motor structs to appropriate output
 * @param controlStyle The format of the joystick input.
 * 			Can be:
 * 		 			TANKDRIVE
 * 	 	 			ARCADEDRIVE
 *	 	 			CHEEZYDRIVE
 *	 	 			MECANUMDRIVE
 *	 	 			HDRIVE
 */
void getJoystickForDriveTrain(int controlStyle) {
	int x1 = joystickGetAnalog(1, 4);
	int y1 = joystickGetAnalog(1, 3);
	int x2 = joystickGetAnalog(1, 1);
	int y2 = joystickGetAnalog(1, 2);

	switch(controlStyle) {
	case TANKDRIVE:
		DTFrontLeft.out = y1;
		DTFrontMidLeft.out = y1;
		DTMidLeft.out = y1;
		DTBackLeft.out = y1;

		DTFrontRight.out = y2;
		DTFrontMidRight.out = y2;
		DTMidRight.out = y2;
		DTBackRight.out = y2;
		break;
	case ARCADEDRIVE:
		DTFrontLeft.out = (y1 + x1) / 2;
		DTFrontMidLeft.out = (y1 + x1) / 2;
		DTMidLeft.out = (y1 + x1) / 2;
		DTBackLeft.out = (y1 + x1) / 2;

		DTFrontRight.out = (y1 - x1) / 2;
		DTFrontMidRight.out = (y1 - x1) / 2;
		DTMidRight.out = (y1 - x1) / 2;
		DTBackRight.out = (y1 - x1) / 2;
		break;
	case CHEEZYDRIVE:
		DTFrontLeft.out = (y1 + x2) / 2;
		DTFrontMidLeft.out = (y1 + x2) / 2;
		DTMidLeft.out = (y1 + x2) / 2;
		DTBackLeft.out = (y1 + x2) / 2;

		DTFrontRight.out = (y1 - x2) / 2;
		DTFrontMidRight.out = (y1 - x2) / 2;
		DTMidRight.out = (y1 - x2) / 2;
		DTBackRight.out = (y1 - x2) / 2;
		break;
	case MECANUMDRIVE:
		DTFrontLeft.out = y1 + x2 + x1;
		DTBackLeft.out = y1 + x2 - x1;

		DTFrontRight.out = y1 - x2 - x1;
		DTBackRight.out = y1 - x2 + x1;
		break;
	case HDRIVE:
	default:
		break;
	}
}

/* Final stage: sets all physical motors based on output set in Motor structs
 * Run in a task?
 * @param driveTrainStyle The configuration of the wheels on the robot.
 * 			Can be:
 * 					FOURWHEELS
 * 					SIXWHEELS
 * 					EIGHTWHEELS
 * 					MECANUM
 * 					HOLONOMIC
 * 					HDRIVE
 * 					SWERVE
 */
void setDriveTrainMotors(int driveTrainStyle) {
	switch(driveTrainStyle) {
	case FOURWHEELS:
		motorSet(DTFrontLeft.port, DTFrontLeft.out * DTFrontLeft.reflected);
		motorSet(DTBackLeft.port, DTBackLeft.out * DTBackLeft.reflected);

		motorSet(DTFrontRight.port, DTFrontRight.out * DTFrontRight.reflected);
		motorSet(DTBackRight.port, DTBackRight.out * DTBackRight.reflected);
		break;
	case SIXWHEELS:
		motorSet(DTFrontLeft.port, DTFrontLeft.out * DTFrontLeft.reflected);
		motorSet(DTMidLeft.port, DTMidLeft.out * DTMidLeft.reflected);
		motorSet(DTBackLeft.port, DTBackLeft.out * DTBackLeft.reflected);

		motorSet(DTFrontRight.port, DTFrontRight.out * DTFrontRight.reflected);
		motorSet(DTMidRight.port, DTMidRight.out * DTMidRight.reflected);
		motorSet(DTBackRight.port, DTBackRight.out * DTBackRight.reflected);
		break;
	case EIGHTWHEELS:
		motorSet(DTFrontLeft.port, DTFrontLeft.out * DTFrontLeft.reflected);
		motorSet(DTFrontMidLeft.port, DTFrontMidLeft.out * DTFrontMidLeft.reflected);
		motorSet(DTMidLeft.port, DTMidLeft.out * DTMidLeft.reflected);
		motorSet(DTBackLeft.port, DTBackLeft.out * DTBackLeft.reflected);

		motorSet(DTFrontRight.port, DTFrontRight.out * DTFrontRight.reflected);
		motorSet(DTFrontMidRight.port, DTFrontMidRight.out * DTFrontMidRight.reflected);
		motorSet(DTMidRight.port, DTMidRight.out * DTMidRight.reflected);
		motorSet(DTBackRight.port, DTBackRight.out * DTBackRight.reflected);
		break;
	case MECANUM:
		break;
	case HOLONOMIC:
		break;
	case HDRIVE:
		break;
	case SWERVE:
		break;
	default:
		break;
	}
}

int autonomousTask(int instruction, int distance, int pow, long timeout) {
	int success = 0;
	long startTime = millis();

	int power[2];
	power[1] = (pow == NULL) ? 127 : pow;
	power[0] = power[1];

	switch(instruction) {
	case AUTODRIVEBASIC:
		int target = encTicksPerRev / (4 * MATH_PI) * distance;
		int power = (pow == NULL) ? 127 : pow;
		int current[2] = getEncoders();

		while(current[1] < target && millis() < startTime + timeout) {
			if(abs(current[1] - current[0]) > 50) {
				if(current[0] > current[1]) {
					power[0] = speedRegulator(power[0] - 2);
				} else if(current[0] < current[1]) {
					power[0] = speedRegulator(power[0] + 2);
				}
			}

			DTFrontRight.out = power[1];
			DTFrontMidRight.out = power[1];
			DTMidRight.out = power[1];
			DTBackRight.out = power[1];
			DTFrontLeft.out = power[0];
			DTFrontMidLeft.out = power[0];
			DTMidLeft.out = power[0];
			DTBackLeft.out = power[0];

			delay(20);
			current = getEncoders();
		}
		break;
	}
	return success;
}

int * getEncoders() {
	int values[2];
	if(useIMEs) {
		imeGet(IMELEFT, &values[0]);
		imeGet(IMERIGHT, &values[1]);
	} else {
		values[0] = encoderGet(encLeft);
		values[1] = encoderGet(encRight);
	}
	return values;
}

int speedRegulator(int speed) {
	if(speed > 127) {
		return 127;
	} else if(speed < -127) {
		return -127;
	} else {
		return speed;
	}
}
