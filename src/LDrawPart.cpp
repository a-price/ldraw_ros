/**
 * \file LDrawPart.cpp
 * \brief
 *
 * \author Andrew Price
 * \date 5 6, 2014
 *
 * \copyright
 *
 * Copyright (c) 2014, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * Humanoid Robotics Lab Georgia Institute of Technology
 * Director: Mike Stilman http://www.golems.org
 *
 * This file is provided under the following "BSD-style" License:
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following
 *   disclaimer in the documentation and/or other materials provided
 *   with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "ldraw_ros/LDrawPart.h"

LDrawPartReference::LDrawPartReference()
{
}


Eigen::Isometry3f LDrawPartReference::getTransform()
{
	Eigen::Isometry3f tf = Eigen::Isometry3f::Identity();
	for (int i = 0; i < 3; ++i)
	{
		tf.translation()[i] = position[i] * LDRAW_UNITS_TO_M;
	}
	Eigen::Matrix3f rot;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			rot(i,j) = rotation[i][j];
		}
	}
	tf.rotate(rot);

	return tf;
}

std::ostream& operator <<(std::ostream& s, LDrawStep step)
{
	s << "Step:  " << std::endl;
	int numElements = step.size();
	for (int i = 0; i < numElements; ++i)
	{
		const unsigned int color = step[i].color;
		std::map<unsigned int, std::tuple<std::string, unsigned int, unsigned int> >::const_iterator iter = LDRAW_COLOR_INFO.find(color);
		if (LDRAW_COLOR_INFO.end() != iter)
		{
			s << std::get<0>(iter->second) << " ";
		}
		s << step[i].partReference << std::endl << step[i].getTransform().matrix() << std::endl;
	}

	return s;
}
