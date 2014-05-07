/**
 * \file LDrawParser.cpp
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

#include "ldraw_ros/LDrawParser.h"
#include <ap_robot_utils/SimpleCSVReader.h>

enum LDRAW_INSTRUCTION_TYPE
{
	LDRAW_COMMENT_INSTRUCTION = 0,
	LDRAW_PART_INSTRUCTION,
	LDRAW_LINE_INSTRUCTION,
	LDRAW_TRIANGLE_INSTRUCTION,
	LDRAW_QUADRILATERAL_INSTRUCTION,
	LDRAW_OPTIONAL_INSTRUCTION
};

std::vector<LDrawStep> parseLDrawFile(std::string& filename)
{
	ap::SimpleCSVReader reader(filename, false, ' ');
	const unsigned int dataSize = reader.data.size();

	std::vector<LDrawStep> steps;
	LDrawStep currentStep;
	LDrawPartReference currentPart;

	for (int r = 0; r < dataSize; ++r)
	{
		ap::CSVRow& row = reader.data[r];
		const unsigned int rowSize = row.size();

		LDRAW_INSTRUCTION_TYPE instruction = LDRAW_COMMENT_INSTRUCTION;

		for (int c = 0; c < rowSize; ++c)
		{
			// Instruction Type
			if (0 == c)
			{
				instruction = (LDRAW_INSTRUCTION_TYPE)atoi(row[c].c_str());
				continue;
			}

			if (LDRAW_COMMENT_INSTRUCTION == instruction)
			{
				if (1 == c)
				{
					// Right Trim...
					std::string inst = row[c];
					inst.erase(inst.find_last_not_of(" \n\r\t")+1);
					// Step
					if ("STEP" == inst)
					{
						steps.push_back(currentStep);
						currentStep.clear();
					}
				}
				else
				{
					break;
				}
			}
			else if (LDRAW_PART_INSTRUCTION == instruction)
			{
				if (1 == c)
				{
					// Color
					currentPart.color = atof(row[c].c_str());
				}
				else if (2 <= c && 4 >= c)
				{
					currentPart.position[c-2] = atof(row[c].c_str());
				}
				else if (5 <= c && 13 >= c)
				{
					(&currentPart.rotation[0][0])[c-5] = atof(row[c].c_str());
				}
				else if (14 == c)
				{
					currentPart.partReference = row[c];
					currentPart.partReference.erase(currentPart.partReference.find_last_not_of(" \n\r\t")+1);
					currentStep.push_back(currentPart);
				}
				else
				{
					// TODO: Throw Error
				}
			}
			else
			{
				// Stop parsing row
				break;
			}
		}
	}

	steps.push_back(currentStep);

	return steps;
}
