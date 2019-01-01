/**
 * Mandelbulber v2, a 3D fractal generator       ,=#MKNmMMKmmßMNWy,
 *                                             ,B" ]L,,p%%%,,,§;, "K
 * Copyright (C) 2018 Mandelbulber Team        §R-==%w["'~5]m%=L.=~5N
 *                                        ,=mm=§M ]=4 yJKA"/-Nsaj  "Bw,==,,
 * This file is part of Mandelbulber.    §R.r= jw",M  Km .mM  FW ",§=ß., ,TN
 *                                     ,4R =%["w[N=7]J '"5=],""]]M,w,-; T=]M
 * Mandelbulber is free software:     §R.ß~-Q/M=,=5"v"]=Qf,'§"M= =,M.§ Rz]M"Kw
 * you can redistribute it and/or     §w "xDY.J ' -"m=====WeC=\ ""%""y=%"]"" §
 * modify it under the terms of the    "§M=M =D=4"N #"%==A%p M§ M6  R' #"=~.4M
 * GNU General Public License as        §W =, ][T"]C  §  § '§ e===~ U  !§[Z ]N
 * published by the                    4M",,Jm=,"=e~  §  §  j]]""N  BmM"py=ßM
 * Free Software Foundation,          ]§ T,M=& 'YmMMpM9MMM%=w=,,=MT]M m§;'§,
 * either version 3 of the License,    TWw [.j"5=~N[=§%=%W,T ]R,"=="Y[LFT ]N
 * or (at your option)                   TW=,-#"%=;[  =Q:["V""  ],,M.m == ]N
 * any later version.                      J§"mr"] ,=,," =="""J]= M"M"]==ß"
 *                                          §= "=C=4 §"eM "=B:m|4"]#F,§~
 * Mandelbulber is distributed in            "9w=,,]w em%wJ '"~" ,=,,ß"
 * the hope that it will be useful,                 . "K=  ,=RMMMßM"""
 * but WITHOUT ANY WARRANTY;                            .'''
 * without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with Mandelbulber. If not, see <http://www.gnu.org/licenses/>.
 *
 * ###########################################################################
 *
 * Authors: Krzysztof Marczak (buddhi1980@gmail.com)
 *
 * fractal based coloring modes
 *       ____                   ________
 *      / __ \____  ___  ____  / ____/ /
 *     / / / / __ \/ _ \/ __ \/ /   / /
 *    / /_/ / /_/ /  __/ / / / /___/ /___
 *    \____/ .___/\___/_/ /_/\____/_____/
 *        /_/
 *
 * This file has been autogenerated by tools/populateOpenCL.php
 * from the file src/fractal_coloring.hpp
 * D O    N O T    E D I T    T H I S    F I L E !
 */

#ifndef MANDELBULBER2_OPENCL_FRACTAL_COLORING_CL_HPP_
#define MANDELBULBER2_OPENCL_FRACTAL_COLORING_CL_HPP_

#ifndef OPENCL_KERNEL_CODE
#include "common_params_cl.hpp"
#include "fractal_cl.h"
#include "image_adjustments_cl.h"
#include "opencl_algebra.h"

#include "src/common_params.hpp"
#include "src/fractal.h"
#include "src/fractal_enums.h"
#include "src/fractparams.hpp"
#include "src/image_adjustments.h"
#endif /* OPENCL_KERNEL_CODE */

typedef enum
{
	fractalColoringCl_None = -1,
	fractalColoringCl_Standard = 0,
	fractalColoringCl_ZDotPoint = 1,
	fractalColoringCl_Sphere = 2,
	fractalColoringCl_Cross = 3,
	fractalColoringCl_Line = 4
} enumFractalColoringCl;

typedef struct
{
	cl_int addEnabledFalse;
	cl_int auxColorFalse;
	cl_int color4dEnabledFalse;
	cl_int colorPreV215False;
	cl_int cosEnabledFalse;
	cl_int extraColorOptionsEnabledFalse;
	cl_int extraColorEnabledFalse;
	cl_int globalPaletteFalse;
	cl_int icFabsFalse;
	cl_int icRadFalse;
	cl_int icXYZFalse;
	cl_int initCondFalse;
	cl_int iterAddScaleTrue;
	cl_int iterGroupFalse;
	cl_int iterScaleFalse;
	cl_int orbitTrapTrue;
	cl_int parabEnabledFalse;
	cl_int radDiv1e13False;
	cl_int radDivDE1e13False;
	cl_int radDivDeFalse;
	cl_int radDivDeSquaredFalse;
	cl_int radFalse;
	cl_int radSquaredFalse;
	cl_int roundEnabledFalse;
	cl_int xyzBiasEnabledFalse;
	cl_int xyzDiv1e13False;
	cl_int xyzFabsFalse;
	cl_int xyzXSqrdFalse;
	cl_int xyzYSqrdFalse;
	cl_int xyzZSqrdFalse;

	cl_int tempLimitFalse; // tempoary

	enumFractalColoringCl coloringAlgorithm;
	cl_int iStartValue;

	cl_float4 lineDirection;
	cl_float3 xyz000;
	cl_float3 xyzC111;

	cl_float addMax;
	cl_float addSpread;
	cl_float addStartValue;
	cl_float auxColorHybridWeight;
	cl_float auxColorWeight;
	cl_float cosAdd;
	cl_float cosPeriod;
	cl_float cosStartValue;
	cl_float icRadWeight;
	cl_float initialColorValue;
	// cl_float initialMinimumR;
	cl_float iterAddScale;
	cl_float iterScale;
	cl_float maxColorValue;
	cl_float minColorValue;
	cl_float orbitTrapWeight;
	cl_float parabScale;
	cl_float parabStartValue;
	cl_float radDivDeWeight;
	cl_float hybridAuxColorScale1;
	cl_float hybridOrbitTrapScale1;
	cl_float hybridRadDivDeScale1;
	cl_float radWeight;
	cl_float roundScale;
	cl_float sphereRadius;
	cl_float xyzIterScale;

} sFractalColoringCl;

#ifndef OPENCL_KERNEL_CODE
inline sFractalColoringCl clCopySFractalColoringCl(const sFractalColoring &source)
{
	sFractalColoringCl target;
	target.addEnabledFalse = source.addEnabledFalse;
	target.auxColorFalse = source.auxColorFalse;
	target.color4dEnabledFalse = source.color4dEnabledFalse;
	target.colorPreV215False = source.colorPreV215False;
	target.cosEnabledFalse = source.cosEnabledFalse;
	target.extraColorOptionsEnabledFalse = source.extraColorOptionsEnabledFalse;
	target.extraColorEnabledFalse = source.extraColorEnabledFalse;
	target.globalPaletteFalse = source.globalPaletteFalse;
	target.icFabsFalse = source.icFabsFalse;
	target.icRadFalse = source.icRadFalse;
	target.icXYZFalse = source.icXYZFalse;
	target.initCondFalse = source.initCondFalse;
	target.iterAddScaleTrue = source.iterAddScaleTrue;
	target.iterGroupFalse = source.iterGroupFalse;
	target.iterScaleFalse = source.iterScaleFalse;
	target.orbitTrapTrue = source.orbitTrapTrue;
	target.parabEnabledFalse = source.parabEnabledFalse;
	target.radDiv1e13False = source.radDiv1e13False;
	target.radDivDE1e13False = source.radDivDE1e13False;
	target.radDivDeFalse = source.radDivDeFalse;
	target.radDivDeSquaredFalse = source.radDivDeSquaredFalse;
	target.radFalse = source.radFalse;
	target.radSquaredFalse = source.radSquaredFalse;
	target.roundEnabledFalse = source.roundEnabledFalse;
	target.xyzBiasEnabledFalse = source.xyzBiasEnabledFalse;
	target.xyzDiv1e13False = source.xyzDiv1e13False;
	target.xyzFabsFalse = source.xyzFabsFalse;
	target.xyzXSqrdFalse = source.xyzXSqrdFalse;
	target.xyzYSqrdFalse = source.xyzYSqrdFalse;
	target.xyzZSqrdFalse = source.xyzZSqrdFalse;
	target.tempLimitFalse = source.tempLimitFalse;
	target.coloringAlgorithm = enumFractalColoringCl(source.coloringAlgorithm);
	target.iStartValue = source.iStartValue;
	target.lineDirection = toClFloat4(source.lineDirection);
	target.xyz000 = toClFloat3(source.xyz000);
	target.xyzC111 = toClFloat3(source.xyzC111);
	target.addMax = source.addMax;
	target.addSpread = source.addSpread;
	target.addStartValue = source.addStartValue;
	target.auxColorHybridWeight = source.auxColorHybridWeight;
	target.auxColorWeight = source.auxColorWeight;
	target.cosAdd = source.cosAdd;
	target.cosPeriod = source.cosPeriod;
	target.cosStartValue = source.cosStartValue;
	target.icRadWeight = source.icRadWeight;
	target.initialColorValue = source.initialColorValue;
	target.iterAddScale = source.iterAddScale;
	target.iterScale = source.iterScale;
	target.maxColorValue = source.maxColorValue;
	target.minColorValue = source.minColorValue;
	target.orbitTrapWeight = source.orbitTrapWeight;
	target.parabScale = source.parabScale;
	target.parabStartValue = source.parabStartValue;
	target.radDivDeWeight = source.radDivDeWeight;
	target.hybridAuxColorScale1 = source.hybridAuxColorScale1;
	target.hybridOrbitTrapScale1 = source.hybridOrbitTrapScale1;
	target.hybridRadDivDeScale1 = source.hybridRadDivDeScale1;
	target.radWeight = source.radWeight;
	target.roundScale = source.roundScale;
	target.sphereRadius = source.sphereRadius;
	target.xyzIterScale = source.xyzIterScale;
	return target;
}
#endif /* OPENCL_KERNEL_CODE */

#endif /* MANDELBULBER2_OPENCL_FRACTAL_COLORING_CL_HPP_ */
