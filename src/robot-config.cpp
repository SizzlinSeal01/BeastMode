#include "main.h"
#include "robot-config.h"

using namespace okapi;

/////////////////////////////////////////////////////////////
// okapi constructors
////////////////////////////

// define chasis
std::shared_ptr<ChassisController> okapiChassis = ChassisControllerBuilder()
                        .withMotors({11, 16}, {-19, -17})
                        .withGains(
                            {0.01, 0, 0},
                            {0.1, 0, 0})
                        .withDimensions (okapi::AbstractMotor::gearset::blue, {{4_in, 12_in}, okapi::imev5BlueTPR / 0.6}) // redo this, this is wrong
                        .build();

std::shared_ptr<AsyncMotionProfileController> profileController =
    AsyncMotionProfileControllerBuilder()
        .withLimits({
            1.0, //Maximum linear velocity of the chassis
            1.0, //Maximum linear acceleration
            5.0  //Maximum linear jerk of the chassis
        })
        .withOutput(okapiChassis)
        .buildMotionProfileController();


/////////////////////////////////////////////////////////
// Pros constructors
//////////////////////////////////

// controllers
pros::Controller Master (pros::E_CONTROLLER_MASTER); // master controller

// drivetrain motors
pros::Motor LF (11, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES); // Left Front Port 11
pros::Motor LB (16, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES); // Left Back Port 16
pros::Motor RF (19, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES); // Right Front Port 19
pros::Motor RB (17, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES); // Right Back Port 17

// intakes
pros::Motor lIntake (20, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES); // Left intake Port 20
pros::Motor rIntake (18, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // right intake port 18

// indexers
pros::Motor bIndexer (1, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES); // bottom indexer Port 1
pros::Motor tIndexer (2, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES); // top indexer Port 2
