#pragma config(Sensor, dgtl1,  limitRBS,       sensorDigitalIn)
#pragma config(Sensor, dgtl2,  limitLBS,       sensorDigitalIn)
#pragma config(Sensor, dgtl3,  limitRTS,       sensorDigitalIn)
#pragma config(Sensor, dgtl4,  limitLTS,       sensorDigitalIn)
#pragma config(Sensor, dgtl5,  limitRBE,       sensorDigitalIn)
#pragma config(Sensor, dgtl6,  limitLBE,       sensorDigitalIn)
#pragma config(Sensor, dgtl7,  limitRTE,       sensorDigitalIn)
#pragma config(Sensor, dgtl8,  limitLTE,       sensorDigitalIn)
#pragma config(Motor,  port2,           mpDriveR,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           mpDriveL,      tmotorVex393, openLoop)
#pragma config(Motor,  port6,           mpLiftR,       tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           mpLiftL,       tmotorVex393, openLoop)
#pragma config(Motor,  port8,           mpArmR,        tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           mpArmL,        tmotorVex393, openLoop)
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


#define NO_LIMIT_SWITCHES



#ifdef NO_LIMIT_SWITCHES
#define isPressed(x)	(false)
#else
#define isPressed(x)  (!SensorValue[x])
#endif




void setLiftPart(
	int speed,
	int motorL, int motorR,
	int lLB, int lRB, int lLT, int lRT
){
	int lSpeed = speed, rSpeed = speed;

	if( speed < 0 ){
		if( isPressed(lLB) ){
			lSpeed = 0;
		}
		if( isPressed(lRB) ){
			rSpeed = 0;
		}
	}

	else if( speed > 0 ){
		if( isPressed(lLT) ){
			lSpeed = 0;
		}
		if( isPressed(lRT) ){
			rSpeed = 0;
		}
	}

	motor[motorL] = lSpeed;
	motor[motorR] = rSpeed;
}

void setLift(int speed){
	// Shoulder
	setLiftPart(speed, mpLiftL, mpLiftR, limitLBS, limitRBS, limitLTS, limitRTS);

	// Elbow
	setLiftPart(speed, mpArmL, mpArmR, limitLBE, limitRBE, limitLTE, limitRTE);
}




void drive(int leftSpeed, int rightSpeed) {
	motor[mpDriveL] = leftSpeed;
	motor[mpDriveR] = rightSpeed;
}



/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////


void autonBlue() {
	drive( 127, 127 );
	wait1Msec(3500);
	//go forward 3.5 seconds full speed to puch ball pile 1 into the low goal
	drive( -127, 0 );
	wait1Msec(500);
	//let wheel goes backward .5 a second to aim for ball pile 2
	drive( -127, -127 );
	wait1Msec(3500);
	//go backwards 3.5 seconds and collect ball pile 2
	drive( 0, -127 );
	wait1Msec(500);
	//move the right wheel backwards to face the allied team
	drive( -127, -127 );
	wait1Msec(250);
	//go backward to push balls into competetor's square
	drive( 0, 127 );
	wait1Msec(3000);
	//turn around to correct angle for getting the third ball pile
	drive( -127, -127 );
	wait1Msec(3000);
	//go backwards 3 seconds to get the third ball pile
	drive( 0, -127 );
	wait1Msec(3000);
	//turn around to face allied team
	drive( -127, -127 );
	wait1Msec(3000);
	//drive back to push third ball pile to allies
	drive( 127, 127 );
	wait1Msec(3000);
	//drive forward parallel to wall
	drive( 0, -127 );
	wait1Msec(1500);
	//turn to face fourth ball pile
	drive( -127, -127 );
	wait1Msec(750);
	//go backwards to collect fourth ball pile
	drive( 0, -127 );
	wait1Msec(1000);
	//moves right wheel backwards
	drive( -127, -127 );
	wait1Msec(2000);
	//goes backwards
}


void autonRed() {
	wait1Msec(3500);
	drive( 127, 127 );
	//go forward 3.5 seconds full speed to puch ball pile 1 into the low goal
	drive( 0, -127 );
	wait1Msec(500);
	//right wheel goes backward .5 a second to aim for ball pile 2
	drive( -127, -127 );
	wait1Msec(3500);
	//go backwards 3.5 seconds and collect ball pile 2
	drive( -127, 0 );
	wait1Msec(500);
	//move the left wheel backwards to face the allied team
	drive( -127, -127 );
	wait1Msec(250);
	//go backward to push balls into competetor's square
	drive( 127, 0 );
	wait1Msec(3000);
	//turn around to correct angle for getting the third ball pile
	drive( -127, -127 );
	wait1Msec(3000);
	//go backwards 3 seconds to get the third ball pile
	drive( -127, 0 );
	wait1Msec(3000);
	//turn around to face allied team
	drive( -127, -127 );
	wait1Msec(3000);
	//drive back to push third ball pile to allies
	drive( 127, 127 );
	wait1Msec(3000);
	//drive forward parallel to wall
	drive( -127, 0 );
	wait1Msec(1500);
	//turn to face fourth ball pile
	drive( -127, -127 );
	wait1Msec(750);
	//go backwards to collect fourth ball pile
	drive( -127, 0 );
	wait1Msec(1000);
	//moves left wheel backwards
	drive( -127, -127 );
	wait1Msec(2000);
	//goes backwards
}


task autonomous()
{
	//autonRed();
	autonBlue();

	drive( 0, 0 );
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	int liftSpeed = 0;
	while(true){

		drive( vexRT[Ch3], vexRT[Ch2] );

		if( vexRT[Btn6U] ){
			liftSpeed = 127;
		} else if( vexRT[Btn6D] ){
			liftSpeed = -50;
		} else {
			liftSpeed = 0;
		}

		setLift(liftSpeed);
	}
}
