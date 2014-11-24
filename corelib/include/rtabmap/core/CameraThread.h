/*
Copyright (c) 2010-2014, Mathieu Labbe - IntRoLab - Universite de Sherbrooke
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Universite de Sherbrooke nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include "rtabmap/core/RtabmapExp.h" // DLL export/import defines

#include <rtabmap/utilite/UThread.h>
#include <rtabmap/utilite/UEventsSender.h>

namespace rtabmap
{

class Camera;
class CameraRGBD;

/**
 * Class CameraThread
 *
 */
class RTABMAP_EXP CameraThread :
	public UThread,
	public UEventsSender
{
public:
	// ownership transferred
	CameraThread(Camera * camera);
	CameraThread(CameraRGBD * camera);
	virtual ~CameraThread();

	bool init(); // call camera->init()

	//getters
	bool isPaused() const {return !this->isRunning();}
	bool isCapturing() const {return this->isRunning();}
	void setImageRate(float imageRate);

	Camera * camera() {return _camera;} // return null if not set, valid until CameraThread is deleted
	CameraRGBD * cameraRGBD() {return _cameraRGBD;} // return null if not set, valid until CameraThread is deleted

private:
	virtual void mainLoop();

private:
	Camera * _camera;
	CameraRGBD * _cameraRGBD;
	int _seq;
};

} // namespace rtabmap