//
// Created by melonjams on 23-10-29.
//


# include "Peripheral/WingController.h"

void WingController::RunOnce() {
    int angleInitL = CalAngelInitWingRootL ();
    int angleInitR = CalAngelInitWingRootR ();
    wingRootL_.SetAngelInit (angleInitL);
    wingRootR_.SetAngelInit (angleInitR);
    // delay 等待翅膀扑动完成
    auto interval = int (1000.0 / frequency_ / angelDivisionDegree_);
    delay (interval);
}

int WingController::CalAngelInitWingRootL() const {
    return angleInit_;
}

int WingController::CalAngelInitWingRootR() const {
    return angleInit_;
}
