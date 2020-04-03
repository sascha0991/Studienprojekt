/*
 * TI Voxel Lib component.
 *
 * Copyright (c) 2014 Texas Instruments Inc.
 */

#include "MyCameraCameraFactory.h"
#include <Logger.h>

#include "MyCameraCamera.h"

#include "SymbolExports.h"

namespace Voxel
{
  
namespace TI
{


MyCameraCameraFactory::MyCameraCameraFactory(const String &name): ToFCameraFactoryBase(name)
{
  /*_addSupportedDevices({
    DevicePtr(new USBDevice(0, 0, "")),
    DevicePtr(new USBDevice(0, 0, "")),
  });*/
}

DepthCameraPtr MyCameraCameraFactory::getDepthCamera(DevicePtr device)
{
  return 0;
}


extern "C" void SYMBOL_EXPORT getDepthCameraFactory(DepthCameraFactoryPtr &ptr)
{
  ptr = DepthCameraFactoryPtr(new MyCameraCameraFactory("MyCamera"));
}

extern "C" int SYMBOL_EXPORT getABIVersion()
{
  return VOXEL_ABI_VERSION; // Return the Voxel ABI version which was used to compile this DepthCameraFactory
}
  
}
}