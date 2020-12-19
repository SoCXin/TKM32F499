# [YS65F804](https://github.com/SoCXin/YS65F804)

[![sites](http://182.61.61.133/link/resources/SoC.png)](http://www.SoC.Xin)

#### [Vendor](https://github.com/SoCXin/Vendor)：[yspring](http://www.yspringtech.com/)
#### [Core](https://github.com/SoCXin/RISC)：[RISC](https://github.com/SoCXin/RISC)
#### [Level](https://github.com/SoCXin/Level)：16MHz

[YS65F804](https://github.com/SoCXin/YS65F804) 8bit RISC仅需学习35条指令。除跳转指令外的所有指令都是单周期的。

* MTP 空间：2K*14 位。可经受 1000 次写操作
* SRAM 空间：128 字节
* CS SRAM：32 字节

- 高精度内部振荡器，出厂时精度校准为+/-1%。 偏差小于+/-2%

- 可用软件选择的频率范围为250kHz到16MHz。

- 软件可选的31kHz内部振荡器。

- 节能的休眠模式。

- 宽工作电压范围（2.2V到5.5V）。

- 工业级温度范围（--40℃≤Ta≤+85℃）。

- 上电复位。

- 带软件控制选择的LVR低电压侦测选择(侦测电压有2V、2.5V、3.0V 、3.6V可选）。

-带片上振荡器（振荡器频率可由软件选择，当预分频比最大时其标称值为268秒）并且可软件使能 的增强型低电流看门狗定时器。

- 带上拉的主复位，可复用为输入引脚。

- 可编程代码保护。



待机电流：

- 电压为2.2V时，典型值500nA。

工作电流：

- 频率为8MHz、电压为2.2V时，典型值为500uA。
- 频率为31kHz、电压为2.2V时，典型值为20uA。

看门狗定时器电流：

- 电压为2.2V时，典型值为1uA。

YS65F804 主要参数
- ROM Size：MTP2.0K x 14
- RAM Size：128bytes +32bytes
- I/O Pin：4/6
- OperatingVoltage：2.2 ~ 5.5
- Package Type：SOP23-6,SOP8
- 2路10bit PWM
双时钟系统

- 内部高速时钟：16MHz RC（Fcpu支持16MHz、8MHz、4MHZ、 2MHZ、 1MHZ、 500KHz、250KHz ）。
- 内部低速时钟：RC振荡器31KHz。


[![sites](docs/YS65F804.png)](http://www.yspringtech.com/upload/down/YS65F804%20V1.2.pdf)

#### 关键特性

* 低成本
* MDT优于OTP

### [资源收录](https://github.com/SoCXin/YS65F804)

* [参考文档](docs/)
* [参考资源](src/)
* [参考工程](project/)

### [选型建议](https://github.com/SoCXin)

[YS65F804](https://github.com/SoCXin/YS65F804) 是少有的量产低成本MCU


###  [www.SoC.xin(芯)](http://www.SoC.Xin)
