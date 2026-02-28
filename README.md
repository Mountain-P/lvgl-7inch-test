# LVGL 7inch Test — ESP32-S3 + ESPHome + Home Assistant

ESP32-S3 Waveshare 7" LCD 中控面板測試專案。

## 硬體

| 項目 | 規格 |
|------|------|
| 板子 | Waveshare ESP32-S3-Touch-LCD-7 |
| 解析度 | 800 × 480 |
| Flash | 8MB |
| PSRAM | 8MB Octal |
| 觸控 | GT911 (I2C) |
| IO 擴展 | CH422G |

## 目錄結構

```
.
├── panel.yaml          # ESPHome 主設定檔
├── secrets.yaml        # WiFi / API Key（本地保留，不上傳）
├── ui/
│   ├── ui.h            # LVGL UI header（可由 LVGL Editor export 取代）
│   └── ui.c            # LVGL UI 實作（可由 LVGL Editor export 取代）
└── lvgl/
    ├── panel.spj       # SquareLine Studio 專案檔（直接用 LVGL Editor 打開）
    └── assets/         # 字型 / 圖片資源
```

## 使用 LVGL Editor（SquareLine Studio）

1. 下載 [SquareLine Studio](https://squareline.io/) v1.3.x 或以上
2. 打開 `lvgl/panel.spj`
3. 設計 / 修改 UI
4. Export → `../ui/` 目錄
5. `ui/ui.h` 內補上 ESPHome 旗標：
   ```c
   extern volatile bool btn_light_pressed;
   ```
6. `ui/ui.c` 的 button callback 內加：
   ```c
   btn_light_pressed = true;
   ```

## 燒錄

**第一次（USB）：**
```bash
# ESP32-S3 先按 BOOT+RESET 進入燒錄模式
esphome run panel.yaml
```

**後續 OTA：**
```bash
esphome run panel.yaml
# 選 Over The Air
```

## 架構

```
LVGL Editor (ui.c/ui.h)
        │
        │ ESPHome includes
        ▼
   ui_init()  ←── on_boot priority: -200
        │
   label_temperature  ←── HA sensor (溫度)
   btn_light          ──► btn_light_pressed flag
                               │
                          interval 100ms
                               │
                     ha_light_toggle.press()
                               │
                     light.toggle (HA action)
```

## ESPHome 資訊

| 項目 | 值 |
|------|----|
| 裝置名稱 | `panel` |
| WiFi | `!secret wifi_ssid` |
| API Key | 見本地 secrets.yaml |
| OTA Password | 見本地 secrets.yaml |
