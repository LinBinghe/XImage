//
// Created by 林炳河 on 2019/9/20.
//

#include "XFrameLayer.hpp"
#include "XFrameOutput.hpp"

NS_X_IMAGE_BEGIN
void XFrameLayer::updateSource() {
    if (mLayerSource == nullptr) {
        mLayerSource = new XFrameOutput();
        XFrameOutput *output = dynamic_cast<XFrameOutput *>(mLayerSource);
        output->setPath(mFramePath);
    }
}

void XFrameLayer::setPath(std::string framePath) {
    mFramePath = framePath;
}
NS_X_IMAGE_END