
#include "main.h"

struct pid {bool running;
	float setPoint;
	float current;
	float error;
	int output;
	bool done;
};


//#include "pidHeaderSmall.h"
//
//static bool  pidDriveRunning = false;
//static bool  pidTurnRunning = false;
//static bool  pidArmRunning = false;
//
//static float pidDriveRRequestedValue;
//static float pidDriveROut;
//static float pidDriveRCurrentValue;
//static bool  pidDriveDone = false;
//static int	 pidDriveMaxSpeed = PID_DRIVE_MAX;
//
//static float pidDriveLRequestedValue;
//static float pidDriveLOut;
//static float pidDriveLCurrentValue;
//
//static float pidTurnRequestedValue;
//static float pidTurnOut;
//static float pidTurnCurrentValue;
//static bool  pidTurnDone = false;
//
//static float pidArmRequestedValue;
//static float pidArmOut;
//static float pidArmCurrentValue;
//static bool  pidArmDone = false;
//
//void setPidDriveTarget(int inches)	{
//	//392 ticks per revolution
//	int target = inches * (392 / (4 * PI)) * -1;
//	pidDriveRCurrentValue = nMotorEncoder[DTBackRight];
//	pidDriveLCurrentValue = nMotorEncoder[DTBackLeft];
//	pidDriveRRequestedValue = pidDriveRCurrentValue + target;
//	pidDriveLRequestedValue = pidDriveLCurrentValue + target;
//
//	//if(abs(pidDriveLRequestedValue) > maxSpeed){
//	//	pidDriveLRequestedValue = maxSpeed;
//	//}
//	//if(abs(pidDriveRRequestedValue) > maxSpeed){
//	//	pidDriveRRequestedValue = maxSpeed;
//	//}
//
//}
//
//void setPidTurnTarget(int degrees)	{
//	int target = degrees;
//
//	if(target > PID_TURN_MAX)
//		target = PID_TURN_MAX;
//	if(target < PID_TURN_MIN)
//		target = PID_TURN_MIN;
//
//	pidTurnRequestedValue = target;
//}
//
//void setPidArmTarget(int degrees)	{
//	int target = degrees;// + PID_POT_OFFSET;
//
//	if(target > PID_POT_MAX)
//		target = PID_POT_MAX;
//	if(target < PID_POT_MIN)
//		target = PID_POT_MIN;
//
//	pidArmRequestedValue = target;
//}
//
//task pidDrive()	{
//	float	 pidDriveRError;
//	float	 pidDriveRLastError;
//	float	 pidDriveRIntegral;
//	float	 pidDriveRDerivative;
//	float	 pidDriveLError;
//	float	 pidDriveLLastError;
//	float	 pidDriveLIntegral;
//	float	 pidDriveLDerivative;
//
//	pidDriveRLastError	= 0;
//	pidDriveRIntegral		= 0;
//	pidDriveLLastError	= 0;
//	pidDriveLIntegral		= 0;
//
//	while(true) {
//		// Is PID control active ?
//		if(pidDriveRunning) {
//			// Read the sensor value and scale
//			pidDriveRCurrentValue = nMotorEncoder[DTBackRight];
//			pidDriveLCurrentValue = nMotorEncoder[DTBackLeft];
//
//			// calculate error
//			pidDriveRError = pidDriveRRequestedValue - pidDriveRCurrentValue; //500
//			pidDriveLError = pidDriveLRequestedValue - pidDriveLCurrentValue; //500
//			pidDriveRIntegral += pidDriveRError;
//			pidDriveLIntegral += pidDriveLError;
//			if(abs(pidDriveRIntegral) > PID_INTEGRAL_LIMIT){
//				pidDriveRIntegral = PID_INTEGRAL_LIMIT * (pidDriveRIntegral/abs(pidDriveRIntegral));
//			}
//			if(abs(pidDriveLIntegral) > PID_INTEGRAL_LIMIT){
//				pidDriveLIntegral = PID_INTEGRAL_LIMIT * (pidDriveLIntegral/abs(pidDriveLIntegral));
//			}
//			pidDriveRDerivative = pidDriveRLastError - pidDriveRError;
//      pidDriveLDerivative = pidDriveLLastError - pidDriveLError;
//
//			pidDriveROut = ((pidDriveRError * pidDrive_Kp) + (pidDriveRIntegral * pidDrive_Ki) + (pidDriveRDerivative * pidDrive_Kd));
//      pidDriveLOut = ((pidDriveLError * pidDrive_Kp) + (pidDriveLIntegral * pidDrive_Ki) + (pidDriveLDerivative * pidDrive_Kd));
//
//			if(abs(pidDriveROut) < PID_DRIVE2_MIN){
//				pidDriveROut = 0;
//				pidDriveDone = true;
//				pidDriveLOut = 0;
//			}
//			else if(abs(pidDriveROut) > PID_DRIVE_MAX){
//				pidDriveROut = PID_DRIVE_MAX * (pidDriveROut/abs(pidDriveROut));
//				pidDriveDone = false;
//				pidDriveLOut = PID_DRIVE_MAX * (pidDriveLOut/abs(pidDriveLOut));
//			}
//
//			pidDriveRLastError	= pidDriveRError;
//			motor[DTFrontRight] = pidDriveROut;
//			motor[DTBackRight] = pidDriveROut;
//			pidDriveLLastError	= pidDriveLError;
//			motor[DTFrontLeft] = pidDriveLOut;
//			motor[DTBackLeft] = pidDriveLOut;
//		}
//		else	{
//			// clear all
//			pidDriveRError			= 0;
//			pidDriveRLastError	= 0;
//			pidDriveRIntegral		= 0;
//			pidDriveRDerivative = 0;
//			pidDriveROut = 0;
//			motor[DTFrontRight] = pidDriveROut;
//			motor[DTBackRight] = pidDriveROut;
//			pidDriveLError			= 0;
//			pidDriveLLastError	= 0;
//			pidDriveLIntegral		= 0;
//			pidDriveLDerivative = 0;
//			pidDriveLOut = 0;
//			motor[DTFrontLeft] = pidDriveLOut;
//			motor[DTBackLeft] = pidDriveLOut;
//		}
//
//		// Run at 50Hz
//		wait1Msec( 25 );
//	}
//}
//
//task pidTurn()	{
//	float	 pidTurnError;
//	float	 pidTurnLastError;
//	float	 pidTurnIntegral;
//	float	 pidTurnDerivative;
//
//	pidTurnLastError	= 0;
//	pidTurnIntegral		= 0;
//
//	while(true) {
//		// Is PID control active ?
//		if(pidTurnRunning)	{
//			// Read the sensor value and scale
//			pidTurnCurrentValue = SensorValue[Gyro]; //900
//
//			// calculate error
//			pidTurnError = pidTurnRequestedValue - pidTurnCurrentValue;
//			pidTurnIntegral += pidTurnError;
//			if(abs(pidTurnIntegral) > PID_INTEGRAL_LIMIT){
//				pidTurnIntegral = PID_INTEGRAL_LIMIT * (pidTurnIntegral/abs(pidTurnIntegral));
//			}
//			pidTurnDerivative = pidTurnLastError - pidTurnError;
//
//			pidTurnOut = ((pidTurnError * pidTurn_Kp) + (pidTurnIntegral * pidTurn_Ki) + (pidTurnDerivative * pidTurn_Kd));
//
//			if(abs(pidTurnOut) < PID_TURN_MIN){
//				pidTurnOut = 0;
//				pidTurnDone = true;
//			}
//			else if(abs(pidTurnOut) > PID_TURN_MAX){
//				pidTurnOut = PID_DRIVE_MAX * (pidTurnOut/abs(pidTurnOut));
//				pidTurnDone = false;
//			}
//
//			pidTurnLastError	= pidTurnError;
//			motor[DTFrontLeft] = -pidTurnOut;
//			motor[DTBackLeft] = -pidTurnOut;
//			motor[DTFrontRight] = pidTurnOut;
//			motor[DTBackRight] = pidTurnOut;
//
//		}
//		else	{
//			// clear all
//			pidTurnError			= 0;
//			pidTurnLastError	= 0;
//			pidTurnIntegral		= 0;
//			pidTurnDerivative = 0;
//			pidTurnOut = 0;
//			motor[DTFrontLeft] = -pidTurnOut;
//			motor[DTBackLeft] = -pidTurnOut;
//			motor[DTFrontRight] = pidTurnOut;
//			motor[DTBackRight] = pidTurnOut;
//		}
//
//		// Run at 50Hz
//		wait1Msec( 25 );
//	}
//}
//
//task pidArm()	{
//	float	 pidArmError;
//	float	 pidArmLastError;
//	float	 pidArmIntegral;
//	float	 pidArmDerivative;
//
//	pidArmLastError	= 0;
//	pidArmIntegral		= 0;
//
//	while(true) {
//		// Is PID control active ?
//		if(pidArmRunning)	{
//			// Read the sensor value and scale
//			pidArmCurrentValue = SensorValue[ARMPot];
//
//			// calculate error
//			pidArmError = pidArmRequestedValue - pidArmCurrentValue;
//			pidArmIntegral += pidArmError;
//			if(abs(pidArmIntegral) > PID_INTEGRAL_LIMIT){
//				pidArmIntegral = PID_INTEGRAL_LIMIT * (pidArmIntegral/abs(pidArmIntegral));
//			}
//			pidArmDerivative = pidArmLastError - pidArmError;
//
//			pidArmOut = ((pidArmError * pidArm_Kp) + (pidArmIntegral * pidArm_Ki) + (pidArmDerivative * pidArm_Kd));
//
//			if(abs(pidArmOut) < PID_ARM_MIN){
//				pidArmOut = 0;
//				pidArmDone = true;
//			}
//			else if(abs(pidArmOut) > PID_ARM_MAX){
//				pidArmOut = PID_ARM_MAX * (pidArmOut/abs(pidArmOut));
//				pidArmDone = false;
//			}
//
//			pidArmLastError	= pidArmError;
//			motor[ARMLeftTop] = pidArmOut;
//			motor[ARMLeftBottom] = pidArmOut;
//			motor[ARMRightTop] = pidArmOut;
//			motor[ARMRightBottom] = pidArmOut;
//
//		}
//		else	{
//			// clear all
//			pidArmError			= 0;
//			pidArmLastError	= 0;
//			pidArmIntegral		= 0;
//			pidArmDerivative = 0;
//			pidArmOut = 0;
//			motor[ARMLeftTop] = pidArmOut;
//			motor[ARMLeftBottom] = pidArmOut;
//			motor[ARMRightTop] = pidArmOut;
//			motor[ARMRightBottom] = pidArmOut;
//		}
//
//		//// Run at 50Hz
//		wait1Msec( 25 );
//	}
//}
//
//int autoDrive(int target, int instruction){
//	return autoDrive(target, instruction, PID_DRIVE_MAX);
//}
//
//int autoDrive(int target, int instruction, int maxSpeed){
//	if(!pidDriveRunning) {
//		pidDriveRunning = true;
//		pidDriveMaxSpeed = maxSpeed;
//		setPidDriveTarget(-target);
//		pidDriveDone = false;
//	}
//	if(pidDriveDone) {
//		instruction++;
//		pidDriveRunning = false;
//		autoDelay(AUTON_WAIT,1);
//	}
//	else {
//		wait1Msec(50);
//	}
//	return instruction;
//}
//
//int autoDriveTouch(int speed, int instruction){
//	if(SensorValue[GoalTouch] == false){
//		pidDriveRunning = false;
//		pidTurnRunning = false;
//		setDriveMotors(speed, speed);
//	}
//	else{
//		stopDriveMotors();
//		instruction++;
//		autoDelay(AUTON_WAIT,1);
//	}
//	return instruction;
//}
//
//int autoTurn(int target, int instruction) {
//	if(!pidTurnRunning) {
//		pidTurnRunning = true;
//		setPidTurnTarget(SensorValue[Gyro] + target);
//		pidTurnDone = false;
//	}
//	if(pidTurnDone) {
//		instruction++;
//		pidTurnRunning = false;
//		autoDelay(AUTON_WAIT,1);
//	}
//	else {
//		wait1Msec(150);
//	}
//	return instruction;
//}
//
//int autoArm(int target, int instruction) {
//	if(!pidArmRunning) {
//		pidArmRunning = true;
//		setPidArmTarget(target);
//		pidArmDone = false;
//	}
//	if(pidArmDone) {
//		instruction++;
//		pidArmRunning = false;
//		autoDelay(AUTON_WAIT,1);
//	}
//	else {
//		wait1Msec(100);
//	}
//	return instruction;
//}
//
//int autoCol(int speed, int instruction) {
//	motor[COLLeft] = speed;
//	motor[COLRight] = speed;
//	instruction++;
//	return instruction;
//}
//
//int autoColStop(int instruction) {
//	motor[COLLeft] = 0;
//	motor[COLRight] = 0;
//	instruction++;
//	return instruction;
//}
//int autoDelay(int mSec, int instruction) {
//	wait1Msec(mSec);
//	instruction++;
//	return instruction;
//}
//
//void stopDriveMotors(){
//	motor[DTBackLeft] = 0;
//	motor[DTBackRight] = 0;
//	motor[DTFrontLeft] = 0;
//	motor[DTFrontRight] = 0;
//}
//
//void setDriveMotors(int LSpeed, int RSpeed){
//	pidDriveRunning = false;
//	pidTurnRunning = false;
//	motor[DTBackLeft] = LSpeed;
//	motor[DTBackRight] = RSpeed;
//	motor[DTFrontLeft] = LSpeed;
//	motor[DTFrontRight] = RSpeed;
//}
//
//
//
