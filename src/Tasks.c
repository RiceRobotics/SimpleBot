/*
 * MotorTask.c
 *
 *  Created on: Oct 27, 2014
 *      Author: Keiko
 */

#include "main.h"

void startIOTask(void *ignore) {
	while(1) {
		setDriveTrainMotors(driveTrainStyle);

		motorSet(ARMLeft.port, ARMLeft.out);
		motorSet(ARMRight.port, ARMRight.out);
		motorSet(ARMTopLeft.port, ARMTopLeft.out);
		motorSet(ARMTopRight.port, ARMTopRight.out);
		motorSet(ARMBottomLeft.port, ARMBottomLeft.out);
		motorSet(ARMBottomRight.port, ARMBottomRight.out);

		if(useIMEs) {
			imeGet(IMELEFT, &encVals[0]);
			imeGet(IMERIGHT, &encVals[1]);
		} else {
			encVals[0] = encoderGet(encLeft);
			encVals[1] = encoderGet(encRight);
		}
		gyroVal = gyroGet(gyro);

		delay(10);
	}
}

void startPidTask(void *ignore) {
	//Manually add each pid loop here

}
