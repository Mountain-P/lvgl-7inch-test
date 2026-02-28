# Screens

每個 `.xml` 檔案對應一個畫面（頁面）。

| 檔案 | 說明 |
|------|------|
| `main.xml` | 主畫面：感測器 + 燈光控制 |

## 新增畫面

1. 在此目錄新增 `xxx.xml`
2. 根元素必須是 `<screen>` 標籤
3. 在 LVGL Editor 裡會自動出現在 Screens 面板

## Export 後要補的東西

每個按鈕的 callback（在 `ui/ui.c` 裡）加旗標：

```c
// 例如客廳燈按鈕
void btn_light_living_event_cb(lv_event_t * e) {
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        btn_light_living_pressed = true;   // ← 加這行
    }
}
```

並在 `ui/ui.h` 裡宣告：

```c
extern volatile bool btn_light_living_pressed;
```
