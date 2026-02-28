/**
 * @file panel_gen.h
 */

#ifndef PANEL_GEN_H
#define PANEL_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

/*----------------
 * Subjects
 *----------------*/
extern lv_subject_t light_living;
extern lv_subject_t light_entry;
extern lv_subject_t light_toilet;
extern lv_subject_t indoor_temp_x10;
extern lv_subject_t indoor_humidity;
extern lv_subject_t total_power;

void panel_init_gen(const char * asset_path);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*PANEL_GEN_H*/
