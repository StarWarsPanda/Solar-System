#ifndef plnts_2_appvar_include_file
#define plnts_2_appvar_include_file

#ifdef __cplusplus
extern "C" {
#endif

#define myimages_palette_offset 0
#define saturn_width 130
#define saturn_height 130
#define plnts_2_myimages_saturn_index 1
#define saturn ((gfx_sprite_t*)plnts_2_appvar[1])
#define sun_width 130
#define sun_height 130
#define plnts_2_myimages_sun_index 2
#define sun ((gfx_sprite_t*)plnts_2_appvar[2])
#define uranus_width 130
#define uranus_height 130
#define plnts_2_myimages_uranus_index 3
#define uranus ((gfx_sprite_t*)plnts_2_appvar[3])
#define plnts_2_entries_num 4
extern unsigned char *plnts_2_appvar[4];
unsigned char plnts_2_init(void);

#ifdef __cplusplus
}
#endif

#endif
