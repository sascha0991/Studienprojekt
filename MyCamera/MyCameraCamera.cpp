/*
 * TI Voxel Lib component.
 *
 * Copyright (c) 2014 Texas Instruments Inc.
 */

#include "MyCameraCamera.h"
#include <Logger.h>

//MyCameraCamera::MyCameraCamera() : DepthCamera("MyCameraCamera", "", nullptr) {}
namespace Voxel
{
    namespace TI {

        MyCameraCamera::MyCameraCamera() : DepthCamera("MyCamera", "", nullptr)
        {
            _init();
        }

        bool MyCameraCamera::_init() {
            //_programmer = Ptr<RegisterProgrammer>(new VoxelXUProgrammer(
            //_streamer = Ptr<Streamer>(new UVCStreamer(controlDevice));
            return true;
        }

        bool MyCameraCamera::_initStartParams() {
            return true;
        }

        bool MyCameraCamera::_getFieldOfView(float &fovHalfAngle) const {
            return true;
        }

        bool MyCameraCamera::_setStreamerFrameSize(const FrameSize &s) {
            return true;
        }

        bool MyCameraCamera::_getSupportedVideoModes(Vector<SupportedVideoMode> &supportedVideoModes) const {
            return true;
        }

        bool MyCameraCamera::_getMaximumVideoMode(VideoMode &videoMode) const {
            return true;
        }

        bool MyCameraCamera::_getMaximumFrameRate(FrameRate &frameRate, const FrameSize &forFrameSize) const {
            return true;
        }


        bool MyCameraCamera::_start() {
            return true; // Falsely accept write
        }

        bool MyCameraCamera::_stop() {
            return true;
        }

        bool MyCameraCamera::_captureRawUnprocessedFrame(RawFramePtr &rawFrame) {
            return true;
        }

        bool MyCameraCamera::_processRawFrame(const RawFramePtr &rawFrameInput, RawFramePtr &rawFrameOutput) {
            return true;
        }

        bool MyCameraCamera::_convertToDepthFrame(const RawFramePtr &rawFrame, DepthFramePtr &depthFrame) {
            return true;
        }

        bool MyCameraCamera::_setFrameRate(const FrameRate &r) {
            return true;
        }

        bool MyCameraCamera::_getFrameRate(FrameRate &r) const {
            return true;
        }

        bool MyCameraCamera::_setFrameSize(const FrameSize &s) {
            return true;
        }

        bool MyCameraCamera::_getFrameSize(FrameSize &s) const {
            return true;
        }

        bool MyCameraCamera::_getMaximumFrameSize(FrameSize &s) const {
            return true;
        }

        bool MyCameraCamera::_getBytesPerPixel(uint &bpp) const {
            return true;
        }

        bool MyCameraCamera::_setBytesPerPixel(const uint &bpp) {
            return true;
        }

        bool MyCameraCamera::_getROI(RegionOfInterest &roi) const {
            return true;
        }

        bool MyCameraCamera::_setROI(const RegionOfInterest &roi) {
            return true;
        }

        bool MyCameraCamera::_allowedROI(String &message) {
            return true;
        }

        bool MyCameraCamera::_reset() {
            return true;
        }

        bool MyCameraCamera::_onReset() {
            return true;
        }

        bool MyCameraCamera::_saveCurrentProfileID(const int id) {
            return true;
        }

        bool MyCameraCamera::_getCurrentProfileID(int &id) {
            return true;
        }

        bool MyCameraCamera::dummyFunc()
        {
            return true;
        }

    }
}