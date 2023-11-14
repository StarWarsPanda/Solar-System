/*
 *--------------------------------------
 * Program Name:Solar System
 * Author:RedSpacePanda
 * License:N/A
 * Description:A screensaver model of the solar system
 *--------------------------------------
*/

#include <tice.h>
#include <graphx.h>
#include <fileioc.h>
#include <Keys.h>
#include <stdio.h>
#include <sys/rtc.h>

#include "gfx/gfx.h"

#include "mathextras.h"

void moveSpritePlanet(uint16_t x, uint8_t y, uint8_t& size, gfx_sprite_t* sprite, uint16_t radNumerator, uint16_t radDenominator, uint16_t rotNumerator, uint16_t rotDenominator, uint16_t speedNumerator, uint16_t speedDenominator, bool move, uint64_t frame, uint8_t spriteSize);

int main(void)
{
	srandom(rtc_Time());

	uint32_t randPos[50];

	for (size_t i = 0; i < 50; i++)
	{
		randPos[i] = random();
	}

	uint16_t pandaX = 500, pandaY = 500;
	int16_t pandaVx = randInt(-2, 2), pandaVy = randInt(-2, 2);

	gfx_Begin();

	gfx_SetPalette(space_palette, sizeof_space_palette, 0);
	gfx_SetTransparentColor(0);

	gfx_SetDrawBuffer();

	uint64_t frame = 0;

	uint8_t sunSize = sun_width, mercurySize = mercury_width, venusSize = venus_width,
		    earthSize = earth_width, marsSize = mars_width, jupiterSize = jupiter_width,
			saturnSize = saturn_width, uranusSize = uranus_width, neptuneSize = neptune_width;
	
	if (plnts_0_init() == 0)
	{
		return 1;
	}
	
	if (plnts_1_init() == 0)
	{
		return 1;
	}
	
	if (plnts_2_init() == 0)
	{
		return 1;
	}

	if (plnts_3_init() == 0)
	{
		return 1;
	}

	do
	{
		kb_Scan();

		gfx_FillScreen(228);

		for (size_t i = 0; i < 50; i++)
		{
			gfx_SetColor(38);
			gfx_SetPixel((uint16_t)(randPos[i] >> 16) % 320, (uint16_t)(randPos[i] & 0xFFFF) % 240);
		}

		if (pandaX > 0 && pandaX < 320 && pandaY > 0 && pandaY < 240)
		{
			gfx_RotatedScaledTransparentSprite_NoClip(panda, pandaX, pandaY, frame / 4, 24);
		}

		pandaX += pandaVx;
		pandaY += pandaVy;

		moveSpritePlanet(160, 120, sunSize, sun, 1, 1, 1, 25, 1, 1, false, frame, 12);
		moveSpritePlanet(160, 120, mercurySize, mercury, 3, 16, 5, 293, 25, 6, true, frame, 5);
		moveSpritePlanet(160, 120, venusSize, venus, 5, 16, 1, 116, 50, 31, true, frame, 5);
		moveSpritePlanet(160, 120, earthSize, earth, 7, 16, 1, 1, 1, 1, true, frame, 5);
		moveSpritePlanet(160, 120, marsSize, mars, 9, 16, 100, 103, 25, 47, true, frame, 5);
		moveSpritePlanet(160, 120, jupiterSize, jupiter, 11, 16, 100, 41, 50, 593, true, frame, 5);
		moveSpritePlanet(160, 120, saturnSize, saturn, 27, 32, 100, 43, 50, 1473, true, frame, 10);
		moveSpritePlanet(160, 120, uranusSize, uranus, 1, 1, 25, 18, 100, 8401, true, frame, 5);
		moveSpritePlanet(160, 120, neptuneSize, neptune, 9, 8, 100, 67, 5, 824, true, frame, 5);

		gfx_SwapDraw();

		frame++;

	} while (!Key_Clear);

	gfx_End();

    return 0;
}

void moveSpritePlanet(uint16_t x, uint8_t y, uint8_t& size, gfx_sprite_t* sprite, uint16_t radNumerator, uint16_t radDenominator, uint16_t rotNumerator, uint16_t rotDenominator, uint16_t speedNumerator, uint16_t speedDenominator, bool move, uint64_t frame, uint8_t spriteSize)
{
	if (gfx_CheckRectangleHotspot(0, 0, 320, 240, x + move * ((radNumerator * sin((speedNumerator * frame / speedDenominator) + 90)) / radDenominator) - (size / 2),
		y + move * ((radNumerator * sin(speedNumerator * frame / speedDenominator)) / radDenominator) - (size / 2), size, size))
	{
		size = gfx_RotatedScaledTransparentSprite_NoClip(sprite,
			x + move * ((radNumerator * sin((speedNumerator * frame / speedDenominator) + 90)) / radDenominator) - (size / 2),
			y + move * ((radNumerator * sin(speedNumerator * frame / speedDenominator)) / radDenominator) - (size / 2),
			rotNumerator * frame / rotDenominator, spriteSize);
	}
}
