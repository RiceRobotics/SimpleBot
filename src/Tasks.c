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

		motorSet(ARMLeft.port, ARMLeft.out * ARMLeft.reflected);
		motorSet(ARMRight.port, ARMRight.out * ARMRight.reflected);
		motorSet(ARMTopLeft.port, ARMTopLeft.out * ARMTopLeft.reflected);
		motorSet(ARMTopRight.port, ARMTopRight.out * ARMTopRight.reflected);
		motorSet(ARMBottomLeft.port, ARMBottomLeft.out * ARMBottomLeft.reflected);
		motorSet(ARMBottomRight.port, ARMBottomRight.out * ARMBottomRight.reflected);

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
