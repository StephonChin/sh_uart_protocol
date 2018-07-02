# 产品

## 圣诞树
### cmd

```
    "TurnOn":0x10,
    "TurnOff":0x11,
    "TurnOnTreeTop":0x12,
    "TurnOffTreeTop":0x13,
    "ColorChange":0x14,
    "Twinklen":0x15,
    "TimeSetting":0x16
```
## 灯串
### cmd

```
    "TurnOn":0x30,
    "TurnOff":0x31,
    "ThemeSet":0X32,
    "Mode":0x33,
    "ShowMode":0x34,
    "TimeSet":0x035
```
````
 // 不加密命令
    APC_CMD_NONE                = 0x00,   // 空类型
    APC_CMD_SOCKET_ON			= 0x30,   //控制开关
    APC_CMD_SOCKET_OFF			= 0X31,	
    APC_CMD_COLOR_SET			= 0X32,	// 控制发送串口
 /* ShowHome APP products commands */
    CMD_THEME_SET           = 0X32;     // Change color or theme
                                        // len = 1  >> Value(0 ~ 29)
                                        //          >> if Value = 0,   change the color or theme to the next one
                                        //          >> else , select the specific color or theme as fallow table
                                        //                      0x01 - Red (Color)
                                        //                      0x02 - Green (Color)
                                        //                      0x03 - Blue (Color)
                                        //                      0x04 - Orange (Color)
                                        //                      0x05 - Hot pink (Color)
                                        //                      0x06 - Spring Green (Color)
                                        //                      0x07 - Gold (Color)
                                        //                      0x08 - Deep Pink (Color)
                                        //                      0x09 - Lawn Green (Color)
                                        //                      0x0A - Magenta (Color)
                                        //                      0x0B - Cyan (Color)
                                        //                      0x0C - Yellow (Color)
                                        //                      0x0D - Purple (Color)
                                        //                      0x0E - Pure White (Color)
                                        //                      0x0F - Cold White (Color)
                                        //                      0x10 - Warm White (Color)
                                        //                      0x11 - Spring (Theme)
                                        //                      0x12 - Summer (Theme)
                                        //                      0x13 - Autumn (Theme)
                                        //                      0x14 - Winter (Theme)
                                        //                      0x15 - Christmas Day (Theme)
                                        //                      0x16 - Valentines' Day (Theme)
                                        //                      0x17 - Independence Day (Theme)
                                        //                      0x18 - Thanksgiving Day (Theme)
                                        //                      0x19 - St. Patrick's Day (Theme)
                                        //                      0x1A - Halloween (Theme)
                                        //                      0x1B - Sun (Theme)
                                        //                      0x1C - Earth (Theme)
                                        //                      0x1D - Multi Color (Theme)
                       

    CMD_MODE_CHG            = 0x33;     // Change mode
                                        // len = 1  >> Value (0 ~ 11)
                                        //          >> if Value = 0, change the mode to next one
                                        //          // else , select the specific mode as fallow table
                                        //                      0x01 - Steady
                                        //                      0x02 - Blink
                                        //                      0x03 - Sparkle
                                        //                      0x04 - Instead
                                        //                      0x05 - Sea Wave
                                        //                      0x06 - Roll
                                        //                      0x07 - Ripple
                                        //                      0x08 - Flower Bloom
                                        //                      0x09 - Polar Light
                                        //                      0x0A - Color Show
                                        
                                        
    CMD_SHOW_MODE           = 0x34;     // Select Show Mode
                                        // len = 1  >> Value (0 ~ 3)
                                        //          >> if Value = 0, change the show mode to next one
                                        //          >> else , select the specific show mode as fallow table
                                        //          >>          0x01 - Show 1
                                        //          >>          0x02 - Show 2
                                        //          >>          0x03 - Show 3
                                        
    CMD_TIMER_SET           = 0x035;     // Set timer
                                        // len = 1  >> Value (2, 4, 6, 8) as set 2/4/6/8 hours timer
```
