/**
 * \file sample.cpp
 * \brief
 *
 * \author Andrew Price
 * \date 5 7, 2014
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

#include <set>
#include "ldraw_ros/LDrawParser.h"

int main(int argc, char *argv[])
{
	std::string filename = "/home/arprice/Dropbox/GTRI/Sears Tower.ldr";
	std::vector<LDrawStep> steps = parseLDrawFile(filename);
	std::map<std::string, unsigned int> parts;

	int numSteps = steps.size();
	for (int i = 0; i < numSteps; ++i)
	{
		std::cout << steps[i] << std::endl;
		int numElements = steps[i].size();
		for (int j = 0; j < numElements; ++j)
		{
			parts[steps[i][j].partReference]++;
		}
	}

	std::map<std::string, unsigned int>::iterator end = parts.end();
	for (std::map<std::string, unsigned int>::iterator iter = parts.begin();
		 iter != end; ++iter)
	{
		std::cout << iter->first << " " << iter->second << std::endl;
	}

	return 0;
}
