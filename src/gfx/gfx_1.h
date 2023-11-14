#ifndef plnts_1_appvar_include_file
#define plnts_1_appvar_include_file

#ifdef __cplusplus
extern "C" {
#endif

#define myimages_palette_offset 0
#define mercury_width 130
#define mercury_height 130
#define plnts_1_myimages_mercury_index 1
#define mercury ((gfx_sprite_t*)plnts_1_appvar[1])
#define neptune_width 130
#define neptune_height 130
#define plnts_1_myimages_neptune_index 2
#define neptune ((gfx_sprite_t*)plnts_1_appvar[2])
#define pluto_width 130
#define pluto_height 130
#define plnts_1_myimages_pluto_index 3
#define pluto ((gfx_sprite_t*)plnts_1_appvar[3])
#define plnts_1_entries_num 4
extern unsigned char *plnts_1_appvar[4];
unsigned char plnts_1_init(void);

#ifdef __cplusplus
}
#endif

#endif
