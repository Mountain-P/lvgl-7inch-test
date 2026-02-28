/**
 * @file panel_gen.c
 */

#include "panel_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

/*----------------
 * Subjects
 *----------------*/
lv_subject_t light_living;
lv_subject_t light_entry;
lv_subject_t light_toilet;
lv_subject_t indoor_temp_x10;
lv_subject_t indoor_humidity;
lv_subject_t total_power;

void panel_init_gen(const char * asset_path)
{
    char buf[256];

    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&light_living,    0);
    lv_subject_set_min_value_int(&light_living, 0);
    lv_subject_set_max_value_int(&light_living, 1);

    lv_subject_init_int(&light_entry,     0);
    lv_subject_set_min_value_int(&light_entry, 0);
    lv_subject_set_max_value_int(&light_entry, 1);

    lv_subject_init_int(&light_toilet,    0);
    lv_subject_set_min_value_int(&light_toilet, 0);
    lv_subject_set_max_value_int(&light_toilet, 1);

    lv_subject_init_int(&indoor_temp_x10, 250);
    lv_subject_init_int(&indoor_humidity, 60);
    lv_subject_init_int(&total_power,     0);

#if LV_USE_XML
    /* Register subjects */
    lv_xml_register_subject(NULL, "light_living",    &light_living);
    lv_xml_register_subject(NULL, "light_entry",     &light_entry);
    lv_xml_register_subject(NULL, "light_toilet",    &light_toilet);
    lv_xml_register_subject(NULL, "indoor_temp_x10", &indoor_temp_x10);
    lv_xml_register_subject(NULL, "indoor_humidity", &indoor_humidity);
    lv_xml_register_subject(NULL, "total_power",     &total_power);
#endif
}
