/**
 * 从遥控器接收信号，控制两个舵机的对称的转动, 转动角度为 0 ~ 180 度, 90 度为中间位置, 0 度为最左边, 180 度为最右边, 保证两个舵机的周期相同, 转动角度由遥控器控制
 * @Author: melonjams
 * @Date: 2020-10-22 16:00:00
 * */


# include <Arduino.h>
# include "Peripheral/WingController.h"
# include "Peripheral/Servo/WingRootL.h"
# include "Peripheral/Servo/WingRootR.h"
# include "Peripheral/Remote/JoyStick.h"


/** 中断中
 * 1> 读取遥控器的信号, 处理为物理量信息
 * 2> 保存到Controller中, 由FlyParam中的函数进行处理, 处理为舵机的控制信号
 * 3> 保存到ServoDigital中, 对舵机进行控制, 接收舵机的回传信号
 * */


WingController controller (9, 10, 0, 120);
// WingRootL wingRootLeft (9, 0, 120);
// WingRootR wingRootRight (10, 0, -120);
JoyStick joyStick (A0, A1, 0, 1023);

void Setup() {
    Serial.begin(9600);
    Serial.println("Start");

    // 串口触发中断
//    attachInterrupt (0, []() {
//        // 读取遥控器的信号, 处理为非物理量信息
//        joyStick.SetInfo();
//        // 保存到Controller中, 处理翅膀的振动周期
//        controller.SetFrequency(joyStick.Get1());
//        controller.SetAngelInit(joyStick.Get2());
//    }, CHANGE);

    // 串口触发中断, COM口
    // todo: pass
}

void Loop() {
    controller.RunOnce ();
}

