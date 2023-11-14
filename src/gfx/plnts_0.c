#include "gfx_0.h"
#include <fileioc.h>

#define plnts_0_HEADER_SIZE 0

unsigned char *plnts_0_appvar[4] =
{
    (unsigned char*)0,
    (unsigned char*)498,
    (unsigned char*)17400,
    (unsigned char*)34302,
};

unsigned char plnts_0_init(void)
{
    unsigned int data, i;
    uint8_t appvar;

    appvar = ti_Open("plnts_0", "r");
    if (appvar == 0)
    {
        return 0;
    }

    data = (unsigned int)ti_GetDataPtr(appvar) - (unsigned int)plnts_0_appvar[0] + plnts_0_HEADER_SIZE;
    for (i = 0; i < 4; i++)
    {
        plnts_0_appvar[i] += data;
    }

    ti_Close(appvar);

    return 1;
}

