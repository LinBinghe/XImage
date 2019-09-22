//
// Created by 林炳河 on 2019/7/14.
//

#include "XOutput.hpp"
#include "XFrameBufferPool.hpp"

NS_X_IMAGE_BEGIN
XOutput::XOutput() {
    mOutputFrameBuffer = nullptr;
}

XOutput::~XOutput() {
    XFrameBufferPool::recycle(mOutputFrameBuffer);
    mTargets.clear();
}

void XOutput::init() {
}

void XOutput::addTarget(XInput *target) {
    mTargets.push_back(target);
}

void XOutput::clearTargets() {
    mTargets.clear();
}

void XOutput::submit(int index) {
    init();

    auto iter = mTargets.begin();
    while (iter != mTargets.end()) {
        XInput* input = *iter;
        input->setInputFrameBuffer(mOutputFrameBuffer);
        input->submit(index);
        ++iter;
    }
}

NS_X_IMAGE_END