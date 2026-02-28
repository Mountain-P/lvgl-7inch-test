# Widgets

每個 widget 放一個獨立資料夾，資料夾內有一個 `.xml` 檔，根元素為 `<widget>`。

## 建立方式（LVGL Editor）

1. 在此目錄建立 `my_widget/my_widget.xml`
2. 根元素：`<widget>`
3. 在 screens 裡用 `<my_widget />` 引用

## 範例結構

```
widgets/
└── sensor_card/
    └── sensor_card.xml
```

```xml
<!-- sensor_card.xml -->
<widget>
  <view style="style_card" flex_flow="column" width="160" height="60">
    <label id="lbl_value" text="--" style="style_text_main" />
    <label id="lbl_unit"  text="unit" style="style_text_muted" />
  </view>
</widget>
```

在 `main.xml` 裡就可以用：

```xml
<sensor_card />
```
