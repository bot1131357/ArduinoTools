// 
// 
// 

#include "ArduinoTools.h"

AT::Tick::Tick(void(*tick_cbfun)(void), uint32_t interval, uint32_t lifetime) : _interval{ interval }, _nextTick{ millis() }
{
	if (lifetime>0) {
		_expiry = millis() + lifetime;
	}

	if (nullptr != tick_cbfun)
	{
		_tick_cbfun = tick_cbfun;
	}
}

bool AT::Tick::operator()()
{
	if (_expiry > 0 && millis() > _expiry) return false;

	if (millis() > _nextTick)
	{
		if (nullptr != _tick_cbfun)_tick_cbfun();
		_nextTick = millis() + _interval;
	}
	return true;
}