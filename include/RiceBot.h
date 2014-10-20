/*
 * RiceBot.h
 *
 *  Created on: Aug 29, 2014
 *      Author: Keiko
 */

#ifndef RICEBOT_H_
#define RICEBOT_H_

#include "main.h"

//Constants
#define MATH_PI 3.14159265358979323846

//Teams
#define RED -1
#define BLUE 1

//Control Style
#define TANKDRIVE 		0
#define ARCADEDRIVE		1
#define CHEEZYDRIVE		2
#define MECANUMDRIVE	3
#define HDRIVE			4

//Drivetrain Styles
#define FOURWHEELS 		0
#define SIXWHEELS 		1
#define EIGHTWHEELS 	2
#define MECANUM 		3
#define HOLONOMIC 		4
#define DTHDRIVE 		5
#define SWERVE 			6

//Autonomous Instructions
#define AUTODRIVEBASIC	0
#define AUTODRIVEPID 	1
#define AUTOTURNBASIC	2
#define AUTOTURNPID		3
#define AUTOARMPID		4
#define AUTOCOLLECTORS	5


//The basic motor struct
struct motor {
	int port;
	int out;
	int reflected;
};

/*
 * The Motor type serves as a wrapper to keep track of all data for each motor on the robot.
 *
 * @param port The port on the Cortex which the motor is plugged into
 * @param out The power output to the motor, between -127 and 127
 * @param reflected If the output to the motor should be reversed. -1 or 1
 */
typedef struct motor Motor;

extern Motor DTFrontRight;
extern Motor DTFrontMidRight;
extern Motor DTMidRight;
extern Motor DTBackRight;
extern Motor DTFrontLeft;
extern Motor DTFrontMidLeft;
extern Motor DTMidLeft;
extern Motor DTBackLeft;

extern Motor ARMRight;
extern Motor ARMLeft;
extern Motor ARMTopRight;
extern Motor ARMBottomRight;
extern Motor ARMTopLeft;
extern Motor ARMBottomLeft;

#define IMERIGHT 		0
#define IMELEFT			1
//extern Encoder encRight;
//extern Encoder encLeft;
//extern Gyro gyro;
extern int armPot;
//If 1, use imeGet(), else use encoderGet()
extern int useIMEs;
/*
 * 627.2 for the 393 IME in high torque mode (factory default)
 * 392 for the 393 IME in high speed mode
 * 360 for the Quadrature Encoder
 */
extern double encTicksPerRev;

Motor initMotor(Motor m, int port, int out, int reflected);

void riceBotInitializeIO();

void riceBotInitialize();

void getJoystickForDriveTrain(int controlStyle);

void setDriveTrainMotors(int driveTrainStyle);

#endif /* RICEBOT_H_ */
