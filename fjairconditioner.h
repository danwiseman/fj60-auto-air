

/**

Defines the air conditioner class for the Automatic air conditioner project


**/

#require "pwmpin.h"

namespace FJAirConditionerNamespace {
  // Fan Speeds to send to the class
  static const int FANOFF = 0;
  static const int FANLOW = 1;
  static const int FANMID = 2;
  static const int FANHIGH = 3;
  static const int FANMAX = 4;

  // direction choices
  static const int DEFROSTDIRECTION = 0;
  static const int FEETDIRECTION = 1
  static const int BODYDIRECTION = 2;

  // Temperature choices
  static const int MAXHEAT = 0;
  static const int MEDIUMHEAT = 1;
  static const int NEUTRALTEMP = 2;
  static const int MEDIUMCOOL = 3;
  static const int MAXCOOL = 4;

}


class FJAirConditioner
{

public:
  FJAirConditioner();

  // Temperature Settings
  void setTemperature(int temp);
  int getTemperature();

  // Fan Related Settings
  void setFanSpeed(int speed); // send one of the const from above
  int getFanSpeed();

  void setInternalAirCirculation(bool useInternalAir);
  bool usingInternalAirCirculation();

  void setAirDirection(int direction); // possible values 0, 1, 2. ?
  int getAirDirection();

  void setMaxDefrost();

  // AC settings
  void turnOnAC();
  void turnOffAC();
  bool acCurrentlyRunning();

private:
  int _desiredTemp;
  int _fanSpeed;
  bool _internalAir;
  int _airDirection;
  bool _acIsOn;

  PWMPin _tempServo;
  PWMPin _fanServo;
  PWMPin _directionServo;

};


// Constructor. Define Defaults
FJAirConditioner::FJAirConditioner() {
  _desiredTemp = NEUTRALTEMP;
  _fanSpeed = FANMID;
  _internalAir = false;
  _airDirection = BODYDIRECTION;
  _acIsOn = false;
}


void FJAirConditioner::setTemperature(int temp) {
  //
}

int FJAirConditioner::getTemperature() {
  return _desiredTemp;
}


void FJAirConditioner::setFanSpeed(int speed) {
  //
}

int FJAirConditioner::getFanSpeed() {
  return _fanSpeed;
}


void FJAirConditioner::setInternalAirCirculation(bool useInternalAir) {
  //
}

bool FJAirConditioner::usingInternalAirCirculation() {
  return _internalAir;
}

void FJAirConditioner::setAirDirection(int direction) {
  //
}

int FJAirConditioner::getAirDirection() {
  return _airDirection;
}

// Sets Max heat and turns on the AC to get rid of internal fogging
void FJAirConditioner::setMaxDefrost() {
  this.setTemperature(MAXHEAT);
  this.turnOnAC();
  this.setAirDirection(DEFROSTDIRECTION);
}


void FJAirConditioner::turnOnAC() {
  //
}

void FJAirConditioner::turnOffAC() {
  //
}

bool FJAirConditioner::acCurrentlyRunning() {
  return _acIsOn;
}
