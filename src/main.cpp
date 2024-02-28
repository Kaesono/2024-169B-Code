// "main.h" houses some functions like handleIntake and handleCatapult
#include "main.h"



// Set left wheel ports (true indicates reversed)
pros::Motor left_wheel_front (17, true);
pros::Motor left_wheel_middle (18, true);
pros::Motor left_wheel_back (20, true);

// Set right wheel ports (true indicates reversed)
pros::Motor right_wheel_front (12);
pros::Motor right_wheel_middle (14);
pros::Motor right_wheel_back (15);

// Set intake motor port
pros::Motor intake (5);

// Set catapult motor port
pros::Motor catapult (8);

// Set hang pneumatic port
pros::ADIDigitalOut hang ('A', false);

// Set wings pneumatic port
pros::ADIDigitalOut wings ('C', false);


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "169B!");

	pros::lcd::register_btn1_cb(on_center_button);

	left_wheel_back.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	left_wheel_front.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	left_wheel_middle.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	right_wheel_back.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	right_wheel_front.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	right_wheel_middle.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
/*
Basic Field Setup in Normal Matches

||||||||||||||||||||||||||||||||||||||
|-----|-----|-----||-----|-----|-----|
|-----|-----|----|OO|----|-----|-----|
|-----|-----|-----||-----|-----|-----|
||||||||||||||||||||||||||||||||||||||
|-----|-----|-----||-----|-----|-----|
|-----|-----|-----||-----|-----|-----|
|-----|-----|-----||-----|-----|-----|
|_____\||||||||||||||||||||||||/=====|
|-----|-----|-----||-----|-----||----|
|-----|-----|-----||-----|-----||----|
|-----|-----|-----||-----|-----||----|
||||||||||||||||||||||||||||||||||||||
|-----|-----|-----||-----|-----||----|
|-----|-----|-----||-----|-----||----|
|-----|-----|-----||-----|-----||----|
|_____/||||||||||||||||||||||||\=====|
|-----|-----|-----||-----|-----|-----|
|-----|-----|-----||-----|-----|-----|
|-----|-----|-----||-----|-----|-----|
||||||||||||||||||||||||||||||||||||||
|-----|-----|-----||-----|-----|-----|
|-----|-----|----|OO|----|-----|-----|
|-----|-----|-----||-----|-----|-----|
||||||||||||||||||||||||||||||||||||||

*/



//Set offensive or defensive autonomous

// ONLY call 'prog' if you are doing Skills autonomous
//prog();

// This doesn't really work
// JK it works, I just wasn't putting '=='
bool offensive = true;

if (offensive == true){ //Double == for checking value instead of writing value
	pros::lcd::set_text(2, "Start autonomous code");

	move(127, 127, 150);
	pros::delay(500);
	move(127, -127, 190);
	pros::delay(500);
	move(127, 127, 550);
	pros::delay(500);
	move(-127, 127, 180);
	pros::delay(500);
	intake.move(-127);
	pros::delay(500);
	move(127, 127, 300);
	pros::delay(500);
	move(-127, -127, 250);
	pros::delay(500);
	move(127, 127, 350);
	pros::delay(500);
	intake.move(0);
	pros::delay(500);
	move(-127, -127, 200);
	pros::delay(500);
	move(-127, 127, 270);
	pros::delay(500);
	move(127, 127, 1000);
	pros::delay(500);
	wings.set_value(true);
	pros::delay(500);
	move(50, -50, 100);

	pros::delay(500);
}
else if (offensive == false){ //Double == for checking value instead of writing value

	move(127, 127, 150);
	pros::delay(500);
	move(-127, 127, 200);
	pros::delay(500);
	move(127, 127, 550);
	pros::delay(500);
	move(127, -127, 180);
	pros::delay(500);
	intake.move(-127);
	pros::delay(500);
	move(127, 127, 300);
	pros::delay(500);
	move(-127, -127, 250);
	pros::delay(500);
	move(127, 127, 350);
	pros::delay(500);
	intake.move(0);
	pros::delay(500);
	move(-127, -127, 200);
	pros::delay(500);
	move(127, -127, 270);
	pros::delay(500);
	move(127, 127, 1000);
	pros::delay(500);
	wings.set_value(true);
	pros::delay(500);
	move(-50, 50, 100);

	pros::delay(500);
}

}

void prog(){

	move(-50, -50, 300);
	catapult.move(100);

//pros::delay(999999999999);
}

// Move function:
// The value "seconds" is in centiseconds
void move(int left, int right, double seconds) {
	// Move motors
	left_wheel_front.move(left);
	left_wheel_middle.move(left);
	left_wheel_back.move(left);

	right_wheel_front.move(right);
	right_wheel_middle.move(right);
	right_wheel_back.move(right);
	
	pros::delay(seconds);

	left_wheel_front.brake();
	left_wheel_middle.brake();
	left_wheel_back.brake();

	right_wheel_front.brake();
	right_wheel_middle.brake();
	right_wheel_back.brake();
	
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

	// Set controller
	pros::Controller master (CONTROLLER_MASTER);

	// Set initial states
	int intakeState = 0;
	bool hangValue =  false;
	bool wingsValue = false;

while (true) {

	// Drive code left
	left_wheel_front.move(master.get_analog(ANALOG_LEFT_Y));
	left_wheel_middle.move(master.get_analog(ANALOG_LEFT_Y));
	left_wheel_back.move(master.get_analog(ANALOG_LEFT_Y));

	// Drive code right
	right_wheel_front.move(master.get_analog(ANALOG_RIGHT_Y));
	right_wheel_middle.move(master.get_analog(ANALOG_RIGHT_Y));
	right_wheel_back.move(master.get_analog(ANALOG_RIGHT_Y));



	// Handle intake
	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
		intakeState = -1;
	}
	else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
		intakeState = 1;
	}
	else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)){
		intakeState = 0;
	}

	double intakeValue = intakeState * 127;
	intake.move(intakeValue);



	// Handle catapult
	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
		catapult.move(-80);
	}

	else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
		catapult.move(80);
	}

	else {
		catapult.move(0);
	}
	

	// Handle hang	
	if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){
		hangValue = !hangValue;
	}

	// Handle wings
	if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
		wingsValue = !wingsValue;
	}

	hang.set_value(hangValue);
	wings.set_value(wingsValue);


// Delay (this is necessary for some reason)
pros::delay(20);
}
}