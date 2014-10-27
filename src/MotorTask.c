/*
 * MotorTask.c
 *
 *  Created on: Oct 27, 2014
 *      Author: Keiko
 */

#include "main.h"

void startMotorTask(void *ignore) {
	while(1) {
		setDriveTrainMotors(FOURWHEELS);
		delay(20);
	}
}
