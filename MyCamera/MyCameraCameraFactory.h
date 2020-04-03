/*
 * TI Voxel Lib component.
 *
 * Copyright (c) 2014 Texas Instruments Inc.
 */

#ifndef VOXEL_TI_TINTIN_CDK_CAMERAFACTORY_H
#define VOXEL_TI_TINTIN_CDK_CAMERAFACTORY_H

#include <DepthCameraFactory.h>
#include <ToFCameraFactoryBase.h>

namespace Voxel
{
  
namespace TI
{
  
class MyCameraCameraFactory: public ToFCameraFactoryBase
{
public:
    MyCameraCameraFactory(const String &name);
  
  virtual DepthCameraPtr getDepthCamera(DevicePtr device);
  
  virtual ~MyCameraCameraFactory() {}
};
  
}
}

#endif // VOXEL_TI_TOFCAMERAFACTORY_H
