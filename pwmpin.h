


class PWMPin {
public:
  PWMPin(int pin);

private:
  _pin;
}


PWMPin::PWMPin(int pin) {
  _pin = pin;
}
