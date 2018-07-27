# Wifi Uart  通讯协议
分两类命令：
1、不需要回应，         **(cmd = 0x0xxxxx)**
2、需要接收到马上回应。 **(cmd = 0x1xxxxxx)**

## 串口设置(默认)
波特率=115200；
数据位 8 位，无奇偶校验，1bit 停止位;
wifi 模块无起始位设置，默认是 1bit 起始位。

## 支持的命令
```javascript
#define UART_VERSION	0x55
// 指令类型
typedef enum APC_CMD_T{
    // 不加密命令
    CMD_NONE          = 0x00,   // 空类型
    CMD_SOCKET_ON			= 0x30,   //控制开关
    CMD_SOCKET_OFF		= 0x31,
 /* ShowHome APP products commands */
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



// 错误类型（底层回复，WIFI接收）
typedef enum{
  ERR_NONE                  = 0x0,
  ERR_CMD_INVALID           = 0x30,         //command is invalid
  ERR_COLOR_RANGE           = 0x31,         //theme value overflow maximum
  ERR_MODE_RANGE            = 0x32,         //mode value overflow maximum
  ERR_SHOW_RANGE            = 0x33,         //show mode overflow maximum
  ERR_TIMER_INVALID         = 0x34,         //timer value is invalid
}EN_ERR_NUM;

## 协议格式

```javascript

typedef struct{
    u8 version;          // 验证数,表示协议和协议版本，目前默认是 0x55
    u8 cmd;            // 命令类型
    u8 idx;			// 序号, 预留给 sensor 使用
	u8 len;            // 数据长度
    char payload[0];    // 数据
} UART_PACKET;
```
# 发送端 ( wifi/mcu)
由于没有结束和开始符， 需要以包为单位触发，一旦触发则连续发送知道发送完该包的数据为止，使得包的数据在时序上尽可能连续。
# 接收端 (mcu)
需要设置缓存，一旦缓存溢出或者串口已经有 T0 时间内没有数据时可以解析缓存的数据。

## 对应的封包 接口参考 **uart_pack_alloc** ，解包参考 **uart_parse**
