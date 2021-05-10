/**
 * \file MusicBoxFactoryActual.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once

#include <memory>

class CActualMusicBox;

/**
 * Machine factory.
 */
class CMusicBoxFactoryActual
{
public:
	CMusicBoxFactoryActual() {}

	/** Create machine
	 * \param machineNumber
	 * \return machine*/
	std::shared_ptr<CActualMusicBox> CreateMachine(int machineNumber);
};