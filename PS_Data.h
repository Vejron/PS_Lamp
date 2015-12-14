
enum ControllState
{
	NONE,
	DIRECT,
	SMOOTH,
	FX_TWINKLE,
	FX_ALARM1,
	FX_ALARM2,
	FX_RAINBOW
};


//struct KeyFrame
//{
//	ControllState state;
//	CHSV color;
//	int position;
//	uint32_t timeOut;
//};

struct KeyFrame
{
		ControllState state;
		CRGB color;

		uint32_t position;
		uint32_t speed;
		uint32_t acceleration;

		uint32_t timeOut;
		uint32_t rate;
};

CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];