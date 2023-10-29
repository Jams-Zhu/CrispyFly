//
// Created by melonjams on 23-10-29.
//

#ifndef CRISPYFLY_WINGROOTRIGHT_H
#define CRISPYFLY_WINGROOTRIGHT_H


# include "Peripheral/Servo/ServoDigital.h"


class WingRootR : public DigitalServo {
protected:
    // 在扑翼过程中, 左右翅膀的扑动方向是相反的. 为了保证两侧的舵机在同一时刻扑动, 需要记录当前舵机的扑动方向
    bool isBeatUp_ = false; // true: 向上扑动; false: 向下扑动
    // 在扑翼过程中, 左右翅膀初相位可能不相等. 此时需要保证舵机在中间某一位置后, 左右两侧的舵机需要保持同步
    int angelMid_ {};

public:
    WingRootR (int pin, int angelScaleH, int angelScaleL, int angelDivisionDegree = 100)
    : DigitalServo (pin, angelScaleH, angelScaleL, angelDivisionDegree) {
    // 初始化舵机
    }

    void CalAngelCurr (int& angelCurr, int angelPrev, int angelInit, int angelFina) override;
};


#endif //CRISPYFLY_WINGROOTRIGHT_H
