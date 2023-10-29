//
// Created by melonjams on 23-10-29.
//


# include "Peripheral/Servo/WingRootR.h"


void WingRootR::CalAngelCurr (int& angelCurr, const int angelPrev, const int angelInit, const int angelFina) {
    auto angelDiff = int((angelFina - angelInit) / 100.0);
    auto angelTmpH = angelPrev + angelDiff;
    auto angelTmpL = angelPrev - angelDiff;
    if (isBeatUp_) {
        if (angelTmpH > angelFina) {
            // 舵机已经转动到了最终位置, 需要改变扑动方向, 开始向下扑动
            isBeatUp_ = true;
            angelCurr = angelTmpL;
        } else {
            angelCurr = angelTmpH;
        }
    } else {
        if (angelTmpL<angelInit) {
            // 舵机已经转动到了初始位置, 需要改变扑动方向, 开始向上扑动
            isBeatUp_ = false;
            angelCurr = angelTmpH;
        } else {
            angelCurr = angelTmpL;
        }
    }
}