//
// Created by melonjams on 23-10-27.
//


# include "Peripheral/Servo/ServoComm.h"

void ServoComm::CalAngelCurr(int &angelCurr, const int angelPrev, const int angelInit, const int angelFina) {
    auto angelDiff = int ((angelFina - angelInit) / float (angelDivisionDegree_));
    auto angelTmpH = angelPrev + angelDiff;
    auto angelTmpL = angelPrev - angelDiff;
    if (isClockwise_) {
        if (angelTmpH > angelFina) {
            isClockwise_ = false;
            angelCurr = angelTmpL;
        } else {
            angelCurr = angelTmpH;
        }
    } else {
        if (angelTmpL < angelInit) {
            isClockwise_ = true;
            angelCurr = angelTmpH;
        } else {
            angelCurr = angelTmpL;
        }
    }
}


template<class elem>
void ServoComm::EnsureInRange(elem &src_dst, const elem scaleH, const elem scaleL)  {
    if (src_dst > scaleH) {
        src_dst = scaleH;
        Serial.println ("Out of range");
    } else if (src_dst < scaleL) {
        src_dst = scaleL;
        Serial.println ("Out of range");
    } else {
        // pass
    }
}


void ServoComm::RunOnce() {
    // 1. 设置舵机的转动频率
    // 2. 设置舵机的转动角度
    // 3. 等待舵机转动到位
    // 4. 设置舵机的转动角度
    // 5. 等待舵机转动到位
    int angelInitNext_ = angelInit_;
    int angelFinaNext_ = angelFina_;
    EnsureInRange (angelInitNext_, angelRangeH_, angelRangeL_);
    EnsureInRange (angelFinaNext_, angelRangeH_, angelRangeL_);

    int angelCurr = angelCurr_; // 记录舵机目目前的转动角度
    CalAngelCurr (angelCurr_, angelCurr, angelInit_, angelFina_);
    servo_.write(angelCurr_);
}
