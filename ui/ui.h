#pragma once
#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

// ── 全域 LVGL 物件指標（供 ESPHome Lambda 使用）──────────
extern lv_obj_t * label_temperature;   // 溫度顯示
extern lv_obj_t * btn_light;           // 燈光切換按鈕
extern lv_obj_t * label_light_status;  // 按鈕上的文字

// ── Button 觸發旗標（供 ESPHome interval 輪詢）────────────
extern volatile bool btn_light_pressed;

// ── 初始化函數（在 ESPHome on_boot lambda 裡呼叫）─────────
void ui_init(void);

#ifdef __cplusplus
}
#endif
