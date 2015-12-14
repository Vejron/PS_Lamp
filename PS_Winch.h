class Winch
{
  private:
    volatile bool _calibrated = false;
    volatile int _target;
    volatile int _current;
    AccelStepper _stepper = AccelStepper(HALFSTEP, MOTORPIN4, MOTORPIN2, MOTORPIN3, MOTORPIN1);
    
  public:
    void begin()
    {
      pinMode(STEPPER_END_PIN, INPUT);
      pinMode(STEPPER_END_PIN, INPUT_PULLUP);
      GoToHomeSynch();
    }

    void GoToHomeSynch()
    {
      _calibrated = false;
	  _stepper.setAcceleration(500.0);
      _stepper.setMaxSpeed(300);
      _stepper.setSpeed(300);           // Not to fast :)
	  DEBUG_PRINTLN("calibration started");
      while(digitalRead(STEPPER_END_PIN)) // at endstop yet?
      {
        _stepper.runSpeed();
      }
      delay(10); // debounce
	  DEBUG_PRINTLN("endstop reached");

      //_stepper.setSpeed(-200);             // the other way
      //while(!digitalRead(STEPPER_END_PIN)) // back down a little
      //{
      //  _stepper.runSpeed();
      //}
	  _stepper.setCurrentPosition(0);
	  _stepper.setSpeed(-300);
	  _stepper.runToNewPosition(-150);
	  DEBUG_PRINTLN("calibrated");
	  DEBUG_PRINT("STEPPER_MIN: "); DEBUG_PRINTLN(STEPPER_MIN);

      // At endstop. Calibrate
      _stepper.setCurrentPosition(0);

      // set default values
      _stepper.setMaxSpeed(800.0);
      _stepper.setAcceleration(500.0);
	  _stepper.disableOutputs();
      
      _calibrated = true; 
    }

	void setTarget(int target)
	{
		int actual = -STEPPER_MIN * (target / 100.0);
		setTargetRaw(actual);
	}

    void setTargetRaw(int target)
    {
      //noInterrupts();
      if(_calibrated && target >= -STEPPER_MIN && target <= 0) // Has to be calibrated and within limits
      {
        _target = target;
		_stepper.enableOutputs();
        _stepper.moveTo(_target);
      }
	  else
	  {
		  DEBUG_PRINTLN("Error: not in range");
	  }
      //interrupts();
    }
        
    /// To be called from interrupt at least ? times per second
    void run() 
    {
      if(!digitalRead(STEPPER_END_PIN))
      {
        _calibrated = false;
        //Todo: out of calibration
		DEBUG_PRINTLN("Error: out of calibration, restart");
      }
   
      if(_calibrated)
      {
		  if (!_stepper.run())
		  {
			  //at target, disable motor to make it less hot
			  _stepper.disableOutputs();
		  }
      }
    }
};

