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