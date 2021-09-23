# [TKM32F499](https://github.com/SoCXin/TKM32F499)

[![sites](http://182.61.61.133/link/resources/SoC.png)](http://SoC.Xin)

* [Tiky](http://hjrkj.com): [Cortex-M4](https://github.com/SoCXin/Cortex)
* [L5R5](https://github.com/SoCXin/Level): 240 MHz (300 DMIPS)

## [简介](https://github.com/SoCXin/TKM32F499/wiki)

[![sites](docs/TKM32F499.png)](http://hjrkj.com/product/13.html)

### 关键特性

* LTDC 提供了 24 位的并行数字 RGB（红、绿、蓝），传送的所有信号可直接与最高 1024x600 分辨率的 LCD 和 TFT 面板接口。
* VGA 输出, 支持刷新率不低于 20Hz: 640x480, 800x600
* 支持 RGB888 格式，向下兼容 RGB666、RGB565 等

#### 相对短板

* 生态资源


### [资源收录](https://github.com/SoCXin)

* [参考资源](src/)
* [参考文档](docs/)
* [参考工程](project/)
* [入门教程](https://docs.soc.xin/TKM32F499)

### [选型建议](https://github.com/SoCXin)

[TKM32F499](https://github.com/SoCXin/TKM32F499) 封装是0.4pitch的LQFP128，体积跟0.5pitch的LQFP100一样。

根据官方放出的手册，TK499应该是[STM32F429](https://github.com/SoCXin/STM32F429)的Core，外挂了一块8M的32bit sdram，程序存在外置spi flash上，启动时拷贝到sdram执行。TK499相比F429，SIP了sdram，但也同时阉割掉了内置的Flash和SRAM，同时不支持从QSPI XIP启动，所以启动流程跟ARM9和CortexA系列比较相似。

首先TK499的Boot脚固定拉低，此时的启动方式对应STM32的内置Bootloader启动模式，即从内部固化的ROM中启动，随后初始化SDRAM，并将QSPI中的程序拷贝至SDRAM，然后跳转到SDRAM中执行。

官方推荐的下载方式是USB drag-and-drop，为此提供了一个二级bootloader。在复位时按住PA13，此时进入一级Bootloader即内置固化的BL，用来烧录二级BL至QSPI Flash。已经烧录二级BL后在复位时按住PA11将进入二级BL，此时就可以拖拽下载主程序。

### [探索芯世界 www.SoC.xin](http://www.SoC.Xin)
