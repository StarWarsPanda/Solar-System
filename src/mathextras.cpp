#include "mathextras.h"

int8_t _sin[255] = {
	0,-3,-6,-9,-12,-16,-19,-22,-25,-28,-31,-34,-37,-40,-43,
	-46,-49,-52,-54,-57,-60,-63,-66,-68,-71,-73,-76,-78,-81,
	-83,-86,-88,-90,-92,-94,-96,-98,-100,-102,-104,-106,-108,
	-109,-111,-112,-114,-115,-116,-118,-119,-120,-121,-122,-123,
	-123,-124,-125,-125,-126,-126,-126,-127,-127,-127,-127,-127,
	-127,-127,-126,-126,-125,-125,-124,-124,-123,-122,-121,-120,
	-119,-118,-117,-116,-114,-113,-112,-110,-108,-107,-105,-103,
	-101,-99,-97,-95,-93,-91,-89,-87,-84,-82,-80,-77,-75,-72,-69,
	-67,-64,-61,-59,-56,-53,-50,-47,-44,-41,-39,-36,-32,-29,-26,
	-23,-20,-17,-14,-11,-8,-5,-2,2,5,8,11,14,17,20,23,26,29,32,
	36,39,41,44,47,50,53,56,59,61,64,67,69,72,75,77,80,82,84,87,
	89,91,93,95,97,99,101,103,105,107,108,110,112,113,114,116,117,
	118,119,120,121,122,123,124,124,125,125,126,126,127,127,127,
	127,127,127,127,126,126,126,125,125,124,123,123,122,121,120,119,
	118,116,115,114,112,111,109,108,106,104,102,100,98,96,94,92,90,
	88,86,83,81,78,76,73,71,68,66,63,60,57,54,52,49,46,43,40,37,34,
	31,28,25,22,19,16,12,9,6,3
};

int sin(uint16_t x)
{
	x %= 360;
	x = (x * 17) / 24; // Map from 360 to 255 (255/360 simplifies to 17/24)
	return _sin[x];
}

void intToString(int value, char* str)
{
	real_t tmp_real_ans = os_FloatToReal(value < 0 ? -value : value);
	real_t tmp_real_10f = os_FloatToReal(10.0);
	real_t tmp_real_ln = os_RealLog(&tmp_real_ans);
	real_t tmp_real_ln10 = os_RealLog(&tmp_real_10f);
	tmp_real_ans = os_RealDiv(&tmp_real_ln, &tmp_real_ln10);
	tmp_real_ans = os_RealInt(&tmp_real_ans);

	uint16_t length = os_RealToInt24(&tmp_real_ans);

	for (size_t i = 0; i < length; i++)
	{

	}
}

void floatToString(float value, char* str)
{
	real_t tmp_real = os_FloatToReal(value);
	os_RealToStr(str, &tmp_real, 8, 1, 2);
}
