// ArduinoTools.h

#ifndef _ARDUINOTOOLS_h
#define _ARDUINOTOOLS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
namespace AT
{
	const uint32_t TIC_INTERVAL = 5 * 60 * 1000;
	class Tick
	{
	private:
		uint32_t _expiry{ 0 };
		uint32_t _interval{ 0 };
		uint32_t _nextTick{ 0 };
		void(*_tick_cbfun)(void);
	public:
		Tick(void(*tick_cbfun)(void), uint32_t interval = TIC_INTERVAL, uint32_t lifetime = 0);
		bool operator () ();
	};
}

#endif

