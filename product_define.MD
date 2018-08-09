# Products
```
    To control the christmas tree or light strings via bluetooth by wifi.
    The protocol is 
```
## General command
```
    "WIFI_STATUS":0x01
```
```
    len = 1
    payload = 0x01    - 待机状态
            = 0x02    - 正在连接中
            = 0x03    - 连接成功
```

## Christmas Tree
### command information
```
    "TurnOn":0x10,
    "TurnOff":0x11,
    "TurnOnTreeTop":0x12,
    "TurnOffTreeTop":0x13,
    "ColorChange":0x14,
    "Twinklen":0x15,
    "TimeSetting":0x16
```    

## Light String
### command summarize
```
    "TurnOn":0x30,
    "TurnOff":0x31,
    "ThemeSet":0X32,
    "Mode":0x33,
    "ShowMode":0x34,
    "TimeSet":0x035
```

### command information
```
typedef enum APC_CMD_T{
    CMD_NONE                = 0x00, 
    CMD_SOCKET_ON           = 0x30, 
    CMD_SOCKET_OFF          = 0x31;
    
    CMD_THEME_SET           = 0x32,     // Change color or theme
                                        // len = 1  >>          Value from 0 to 0x1C
                                        //---------------------------------------------------
                                        //                      0x00 - Red
                                        //                      0x01 - Green
                                        //                      0x02 - Blue
                                        //                      0x03 - Orange
                                        //                      0x04 - Pink
                                        //                      0x05 - Spring Green
                                        //                      0x06 - Gold
                                        //                      0x07 - Deep Pink
                                        //                      0x08 - Lawn Green
                                        //                      0x09 - Magenta
                                        //                      0x0A - Cyan
                                        //                      0x0B - Yellow
                                        //                      0x0C - Purple
                                        //                      0x0D - White
                                        //                      0x0E - Cold White
                                        //                      0x0F - Warm White
                                        //                      0x10 - Spring
                                        //                      0x11 - Summer
                                        //                      0x12 - Autumn
                                        //                      0x13 - Winter
                                        //                      0x14 - Christmas Day
                                        //                      0x15 - Valentines' Day
                                        //                      0x16 - Independence Day
                                        //                      0x17 - Thanksgiving Day
                                        //                      0x18 - St. Patrick's Day
                                        //                      0x19 - Halloween
                                        //                      0x1A - Sun
                                        //                      0x1B - Earth
                                        //                      0x1C - Multi Color


    CMD_NORMAL_MODE         = 0x33,     // Change mode
                                        // len = 1  >>          Value from 0 to 9
                                        //---------------------------------------------------------
                                        //                      0x00 - Steady
                                        //                      0x01 - Blink
                                        //                      0x02 - Sparkle
                                        //                      0x03 - Instead
                                        //                      0x04 - Wave
                                        //                      0x05 - Roll
                                        //                      0x06 - Fade
                                        //                      0x07 - Fireworks
                                        //                      0x08 - Polar
                                        //                      0x09 - Color Show


    CMD_SHOW_MODE           = 0x34,     // Select Show Mode
                                        // len = 1  >>          Value from 0 to 6
                                        // ---------------------------------------------------
                                        //                      0x00 - Christmas Show
                                        //                      0x01 - Valentines Day Show
                                        //                      0x02 - Independence Day Show
                                        //                      0x03 - Thanksgiving Day Show
                                        //                      0x04 - St. Patrick's Day Show
                                        //                      0x05 - Halloween Show
                                        //                      0x06 - MultiColor Show

    CMD_TIMER_SET           = 0x35,     // Set timer
                                        // len = 1              Value from 0 to 8 (even number)
                                        //------------------------------------------------------
                                        //                      0 - timer off
                                        //                      2 - set 2h
                                        //                      4 - set 4h
                                        //                      6 - set 6h
                                        //                      8 - set 8h


    CMD_MSC_EN              = 0x36,     // Music mode enable or disable
                                        // len = 1              Value from 0 to 1
                                        //------------------------------------------------------
                                        //                      0     - disable
                                        //                      other - enable
	APC_CMD_MAX
}APC_CMD_T;
```
