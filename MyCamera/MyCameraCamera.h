/*
 * TI Voxel Lib component.
 *
 * Copyright (c) 2014 Texas Instruments Inc.
 */

#ifndef MYCAMERACAMERA_H
#define MYCAMERACAMERA_H

#include <DepthCamera.h>

namespace Voxel {
    namespace TI {

        class MyCameraCamera : public Voxel::DepthCamera {
        protected:

            bool _init();

            bool _getFieldOfView(float &fovHalfAngle) const;

            bool _getSupportedVideoModes(Vector <SupportedVideoMode> &supportedVideoModes) const;

            bool _setStreamerFrameSize(const FrameSize &s);

            bool _getMaximumVideoMode(VideoMode &videoMode) const;

            bool _getMaximumFrameRate(FrameRate &frameRate, const FrameSize &forFrameSize) const;

            bool _initStartParams();

            bool _start();

            bool _stop();

            bool _captureRawUnprocessedFrame(RawFramePtr &rawFrame);

            bool _processRawFrame(const RawFramePtr &rawFrameInput, RawFramePtr &rawFrameOutput);

            bool _convertToDepthFrame(const RawFramePtr &rawFrame, DepthFramePtr &depthFrame);

            bool _setFrameRate(const FrameRate &r);

            bool _getFrameRate(FrameRate &r) const;

            bool _setFrameSize(const FrameSize &s);

            bool _getFrameSize(FrameSize &s) const;

            bool _getMaximumFrameSize(FrameSize &s) const;

            bool _getBytesPerPixel(uint &bpp) const;

            bool _setBytesPerPixel(const uint &bpp);

            bool _getROI(RegionOfInterest &roi) const;

            bool _setROI(const RegionOfInterest &roi);

            bool _allowedROI(String &message);

            bool _reset();

            bool _onReset();

            bool _saveCurrentProfileID(const int id);

            bool _getCurrentProfileID(int &id);

            bool dummyFunc();

        public:
            MyCameraCamera();// : Voxel::DepthCamera("MyCamera", "", nullptr) {}

            virtual ~MyCameraCamera() {}

        };

    }
}
#endif
