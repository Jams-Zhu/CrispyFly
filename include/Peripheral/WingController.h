//
// Created by melonjams on 23-10-29.
//

#ifndef CRISPYFLY_WINGCONTROLLER_H
#define CRISPYFLY_WINGCONTROLLER_H


# include "Peripheral/Servo/WingRootL.h"
# include "Peripheral/Servo/WingRootR.h"


class WingController {
protected:
    WingRootL wingRootL_;
    WingRootR wingRootR_;

    float frequency_{};    // Hz
    int angleInit_{};  // deg
    int angelDivisionDegree_{};  // deg

public:
    WingController (int pinWingRootL, int pinWingRootR, int angelScaleH, int angelScaleL, int angelDivisionDegree = 100)
    : wingRootL_(pinWingRootL, angelScaleH, + angelScaleL, angelDivisionDegree)
    , wingRootR_(pinWingRootR, angelScaleH, - angelScaleL, angelDivisionDegree)
    , angelDivisionDegree_(angelDivisionDegree) {
    }


    // 遥控器前后推杆 或者 是串口数据
    // 前推: frequency 增加
    // 后推: frequency 减小
    void SetFrequency (float frequency) {
        frequency_ = frequency;
    }

    // 遥控器左右推杆 或者 是串口数据
    // 左推: angleInit 减小
    // 右推: angleInit 增加
    void SetAngelInit (int angelInit) {
        angleInit_ = angelInit;
    }

    void RunOnce ();

private:
    // todo: 可以微调
    int CalAngelInitWingRootL () const;

    int CalAngelInitWingRootR () const;
};

#endif //CRISPYFLY_WINGCONTROLLER_H
