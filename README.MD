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
    APC_CMD_NONE                = 0x00,   // 空类型
	APC_CMD_SOCKET_ON			= 0x10,   //控制开关
	APC_CMD_SOCKET_OFF			= 0x11,	
    APC_CMD_COLOR_SET			= 0x20,	// 控制发送串口
 /* ShowHome APP products commands */
    CMD_THEME_SET           = 0x30;     // Change color or theme
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
                       

    CMD_MODE_CHG            = 0x31;     // Change mode
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
                                        
                                        
    CMD_SHOW_MODE           = 0x32;     // Select Show Mode
                                        // len = 1  >> Value (0 ~ 3)
                                        //          >> if Value = 0, change the show mode to next one
                                        //          >> else , select the specific show mode as fallow table
                                        //          >>          0x01 - Show 1
                                        //          >>          0x02 - Show 2
                                        //          >>          0x03 - Show 3
                                        
    CMD_TIMER_SET           = 0x33;     // Set timer
                                        // len = 1  >> Value (2, 4, 6, 8) as set 2/4/6/8 hours timer
	APC_CMD_MAX
}APC_CMD_T;

```

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