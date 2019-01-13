

/**

Defines the air conditioner class for the Automatic air conditioner project


**/



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



};


// Constructor. Define Defaults
FJAirConditioner::FJAirConditioner() {
  _desiredTemp = NEUTRALTEMP;
  _fanSpeed = FANMID;
  _internalAir = false;
  _airDirection = BODYDIRECTION;
  _acIsOn = false;

  // private methods
  void _moveTemperature(_desiredTemp);
  void _turnOnFanRelays(_fanSpeed);
  void _moveAirCirculation(_internalAir);
  void _moveAirDirection(_airDirection);


}

// Moves the servo to the Temperature requested
// requires: int temp with value between 0-4
void FJAirConditioner::setTemperature(int temp) {
  // verify correct temp settings, then move it if valid
  if(temp >= 0 && temp <= 4) {
    this->_moveTemperature(temp);
  }
}

// returns the Temperature that is currently set
int FJAirConditioner::getTemperature() {
  return _desiredTemp;
}

// uses the relays to set the fan speed.
// requires an int speed in the range 0-4
void FJAirConditioner::setFanSpeed(int speed) {
  // check for valid speed, then send it to the private methods
  if(speed >= 0 && speed <= 4) {
    this->_turnOnFanRelays(speed);
  }
}

// returns the fan speed that is currently set
int FJAirConditioner::getFanSpeed() {
  return _fanSpeed;
}

// Takes a bool to determine if to turn on or off the internal air
// Moves the servo to the proper position
void FJAirConditioner::setInternalAirCirculation(bool useInternalAir) {
  _internalAir = useInternalAir;
  this->_moveAirCirculation();
}

// reutns the current setting for the internal air setting
bool FJAirConditioner::usingInternalAirCirculation() {
  return _internalAir;
}

// Moves the servo to the request air direction, Face, Feet or Defrost
// Takes an int direction in the range of 0-2
void FJAirConditioner::setAirDirection(int direction) {
  // check for valid direction, then send it
  if (direction >= 0 && direction <= 2) {
    _moveAirDirection(direction);
  }
}

// returns the current air direction
int FJAirConditioner::getAirDirection() {
  return _airDirection;
}

// Sets Max heat and turns on the AC to get rid of internal fogging
void FJAirConditioner::setMaxDefrost() {
  this->setTemperature(MAXHEAT);
  this->turnOnAC();
  this->setAirDirection(DEFROSTDIRECTION);
  this->setFanSpeed(FANMAX);
}

// Turns on the AC by activating a switch
void FJAirConditioner::turnOnAC() {
  // turn on the switch
}

// Turns off the AC by activating the switch
void FJAirConditioner::turnOffAC() {
  // turn off the seitch
}

// returns if the AC is currently on
bool FJAirConditioner::acCurrentlyRunning() {
  return _acIsOn;
}

// private methods
// Moves the servo to the selected temp
void FJAirConditioner::_moveTemperature(int temp) {

}

// calls on the different relays required for the fan speed
void FJAirConditioner::_turnOnFanRelays(int speed) {

}

// moves the servo to the slected air circulation
void FJAirConditioner::_moveAirCirculation() {

}

// moves the servo to the selected air direction, face/feet/defrest.
void FJAirConditioner::_moveAirDirection(int direction) {

}
