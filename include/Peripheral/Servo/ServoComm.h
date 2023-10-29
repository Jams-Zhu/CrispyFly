//
// Created by melonjams on 23-10-27.
//

#ifndef CRISPYFLY_SERVOCOMM_H
#define CRISPYFLY_SERVOCOMM_H


# include <Arduino.h>
# include <Servo.h>

/**
 * @brief: 舵机角度设定, 正视舵机轴, 默认舵机正上为0度, 逆时针为正方向, 90度为最左边, -90度为最右边
 * */
class ServoComm {
    // 控制舵机的转动
protected:
    Servo servo_ {};
    int pin_ {};

    // 舵机的最大转动角度
    int angelScaleH_ {};        // deg
    int angelScaleL_ {};        // deg

    // 外部输入的有意义的物理量
    int angelInit_ {};
    int angelFina_ {};
    int angelDivisionDegree_ {}; // 舵机的转动角度的分辨率

    // 内部处理后的舵机控制量
    int angelCurr_ {}; // 记录舵机目目前的转动角度
    bool isClockwise_ {true}; // 记录舵机目前的转动方向

public:
    /**
     * @param: pin: 舵机的引脚
     * @param: angelRangeH: 舵机的最大转动角度
     * @param: angelRangeL: 舵机的最小转动角度
     * @param: angelDivisionDegree: 舵机的转动角度的分辨率, 每次转动的角度 = 范围/分辨率, 以保证即便转动的幅度不同, 转动次数相同, 舵机最终可以同时到达某相位
     * */
    ServoComm (int pin, int angelScaleH, int angelScaleL, int angelDivisionDegree = 100)
    : pin_(pin)
    , angelScaleH_(angelScaleH)
    , angelScaleL_(angelScaleL)
    , angelDivisionDegree_(angelDivisionDegree) {
        // 初始化舵机
        servo_.attach(pin_);
        // 设置舵机的转动角度
        servo_.write(0);
        angelInit_ = 0;
        angelFina_ = 0;
        angelCurr_ = angelInit_;
    }

    virtual ~ServoComm () {
        servo_.write(0);
        servo_.detach();
    }

    void SetAngelInit (int angelInit) {
        // 设置舵机的转动角度
        angelInit_ = angelInit;
    }

    void SetAngelFina (int angelFina) {
        // 设置舵机的转动角度
        angelFina_ = angelFina;
    }

    /**
     * @brief run once
     * */
    virtual void RunOnce ();

    /**
     * @brief: 均匀角速度
     * */
    virtual void CalAngelCurr (int& angelCurr, const int angelPrev, const int angelInit, const int angelFina);

    template <class elem>
    static void EnsureInRange (elem& src_dst, const elem scaleH, const elem scaleL);
};


#endif //CRISPYFLY_SERVOCOMM_H
