#ifndef plnts_0_appvar_include_file
#define plnts_0_appvar_include_file

#ifdef __cplusplus
extern "C" {
#endif

#define myimages_palette_offset 0
#define earth_width 130
#define earth_height 130
#define plnts_0_myimages_earth_index 1
#define earth ((gfx_sprite_t*)plnts_0_appvar[1])
#define jupiter_width 130
#define jupiter_height 130
#define plnts_0_myimages_jupiter_index 2
#define jupiter ((gfx_sprite_t*)plnts_0_appvar[2])
#define mars_width 130
#define mars_height 130
#define plnts_0_myimages_mars_index 3
#define mars ((gfx_sprite_t*)plnts_0_appvar[3])
#define plnts_0_entries_num 4
extern unsigned char *plnts_0_appvar[4];
unsigned char plnts_0_init(void);

#ifdef __cplusplus
}
#endif

#endif
