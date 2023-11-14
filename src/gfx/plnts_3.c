#include "gfx_3.h"
#include <fileioc.h>

#define plnts_3_HEADER_SIZE 0

unsigned char *plnts_3_appvar[3] =
{
    (unsigned char*)0,
    (unsigned char*)498,
    (unsigned char*)17400,
};

unsigned char plnts_3_init(void)
{
    unsigned int data, i;
    uint8_t appvar;

    appvar = ti_Open("plnts_3", "r");
    if (appvar == 0)
    {
        return 0;
    }

    data = (unsigned int)ti_GetDataPtr(appvar) - (unsigned int)plnts_3_appvar[0] + plnts_3_HEADER_SIZE;
    for (i = 0; i < 3; i++)
    {
        plnts_3_appvar[i] += data;
    }

    ti_Close(appvar);

    return 1;
}

