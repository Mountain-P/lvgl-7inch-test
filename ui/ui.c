#include "ui.h"

// ── 全域物件指標 ──────────────────────────────────────────
lv_obj_t * label_temperature   = NULL;
lv_obj_t * btn_light           = NULL;
lv_obj_t * label_light_status  = NULL;

// ESPHome interval 會輪詢這個旗標來觸發 HA action
volatile bool btn_light_pressed = false;

// ── Button 事件 callback ──────────────────────────────────
static void btn_light_event_cb(lv_event_t * e)
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        btn_light_pressed = true;

        // 視覺回饋：按下時切換按鈕顏色
        bool is_on = (lv_obj_get_style_bg_color(btn_light, 0).full == lv_color_hex(0xF59E0B).full);
        lv_obj_set_style_bg_color(btn_light,
            is_on ? lv_color_hex(0x334155) : lv_color_hex(0xF59E0B), 0);
        lv_label_set_text(label_light_status, is_on ? "客廳燈 OFF" : "客廳燈 ON");
    }
}

// ── UI 初始化（ESPHome on_boot 呼叫）─────────────────────
void ui_init(void)
{
    lv_obj_t * scr = lv_scr_act();

    // 背景色
    lv_obj_set_style_bg_color(scr, lv_color_hex(0x0A0E1A), 0);
    lv_obj_set_style_bg_opa(scr, LV_OPA_COVER, 0);

    // ── 溫度 Label ────────────────────────────────────────
    label_temperature = lv_label_create(scr);
    lv_label_set_text(label_temperature, "Temp: --.-°C");
    lv_obj_set_style_text_color(label_temperature, lv_color_hex(0xE0E7FF), 0);
    lv_obj_set_style_text_font(label_temperature, &lv_font_montserrat_28, 0);
    lv_obj_align(label_temperature, LV_ALIGN_TOP_MID, 0, 40);

    // ── 燈光 Button ───────────────────────────────────────
    btn_light = lv_btn_create(scr);
    lv_obj_set_size(btn_light, 220, 80);
    lv_obj_align(btn_light, LV_ALIGN_CENTER, 0, 20);
    lv_obj_set_style_bg_color(btn_light, lv_color_hex(0x334155), 0);
    lv_obj_set_style_radius(btn_light, 16, 0);
    lv_obj_set_style_shadow_width(btn_light, 0, 0);

    // 按鈕文字
    label_light_status = lv_label_create(btn_light);
    lv_label_set_text(label_light_status, "客廳燈 OFF");
    lv_obj_set_style_text_color(label_light_status, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_text_font(label_light_status, &lv_font_montserrat_20, 0);
    lv_obj_center(label_light_status);

    // 綁定事件
    lv_obj_add_event_cb(btn_light, btn_light_event_cb, LV_EVENT_CLICKED, NULL);

    // ── 說明文字 ──────────────────────────────────────────
    lv_obj_t * lbl_hint = lv_label_create(scr);
    lv_label_set_text(lbl_hint, "LVGL Editor Export Test\nESPHome + ESP32-S3");
    lv_obj_set_style_text_color(lbl_hint, lv_color_hex(0x475569), 0);
    lv_obj_set_style_text_font(lbl_hint, &lv_font_montserrat_16, 0);
    lv_obj_set_style_text_align(lbl_hint, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(lbl_hint, LV_ALIGN_BOTTOM_MID, 0, -30);
}
