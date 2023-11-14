#ifndef plnts_3_appvar_include_file
#define plnts_3_appvar_include_file

#ifdef __cplusplus
extern "C" {
#endif

#define myimages_palette_offset 0
#define venus_width 130
#define venus_height 130
#define plnts_3_myimages_venus_index 1
#define venus ((gfx_sprite_t*)plnts_3_appvar[1])
#define panda_width 64
#define panda_height 64
#define plnts_3_myimages_panda_index 2
#define panda ((gfx_sprite_t*)plnts_3_appvar[2])
#define plnts_3_entries_num 3
extern unsigned char *plnts_3_appvar[3];
unsigned char plnts_3_init(void);

#ifdef __cplusplus
}
#endif

#endif
