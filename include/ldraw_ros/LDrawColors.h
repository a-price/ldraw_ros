/**
 * \file LDrawColors.h
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

#ifndef LDRAWCOLORS_H
#define LDRAWCOLORS_H

#include <map>
#include <tuple>
	//{0,std::make_tuple("Black",0x05131D,0x595959)}
const std::map<unsigned int, std::tuple<std::string, unsigned int, unsigned int> >
LDRAW_COLOR_INFO{
	{0,std::make_tuple("Black",0x05131D,0x595959)},
	{1,std::make_tuple("Blue",0x0055BF,0x333333)},
	{2,std::make_tuple("Green",0x257A3E,0x333333)},
	{3,std::make_tuple("Dark_Turquoise",0x00838F,0x333333)},
	{4,std::make_tuple("Red",0xC91A09,0x333333)},
	{5,std::make_tuple("Dark_Pink",0xC870A0,0x333333)},
	{6,std::make_tuple("Brown",0x583927,0x1E1E1E)},
	{7,std::make_tuple("Light_Gray",0x9BA19D,0x333333)},
	{8,std::make_tuple("Dark_Gray",0x6D6E5C,0x333333)},
	{9,std::make_tuple("Light_Blue",0xB4D2E3,0x333333)},
	{10,std::make_tuple("Bright_Green",0x4B9F4A,0x333333)},
	{11,std::make_tuple("Light_Turquoise",0x55A5AF,0x333333)},
	{12,std::make_tuple("Salmon",0xF2705E,0x333333)},
	{13,std::make_tuple("Pink",0xFC97AC,0x333333)},
	{14,std::make_tuple("Yellow",0xF2CD37,0x333333)},
	{15,std::make_tuple("White",0xFFFFFF,0x333333)},
	{17,std::make_tuple("Light_Green",0xC2DAB8,0x333333)},
	{18,std::make_tuple("Light_Yellow",0xFBE696,0x333333)},
	{19,std::make_tuple("Tan",0xE4CD9E,0x333333)},
	{20,std::make_tuple("Light_Violet",0xC9CAE2,0x333333)},
	{22,std::make_tuple("Purple",0x81007B,0x333333)},
	{23,std::make_tuple("Dark_Blue_Violet",0x2032B0,0x1E1E1E)},
	{25,std::make_tuple("Orange",0xFE8A18,0x333333)},
	{26,std::make_tuple("Magenta",0x923978,0x333333)},
	{27,std::make_tuple("Lime",0xBBE90B,0x333333)},
	{28,std::make_tuple("Dark_Tan",0x958A73,0x333333)},
	{29,std::make_tuple("Bright_Pink",0xE4ADC8,0x333333)},
	{30,std::make_tuple("Medium_Lavender",0xAC78BA,0x333333)},
	{31,std::make_tuple("Lavender",0xE1D5ED,0x333333)},
	{68,std::make_tuple("Very_Light_Orange",0xF3CF9B,0x333333)},
	{69,std::make_tuple("Light_Purple",0xCD6298,0x333333)},
	{70,std::make_tuple("Reddish_Brown",0x582A12,0x595959)},
	{71,std::make_tuple("Light_Bluish_Gray",0xA0A5A9,0x333333)},
	{72,std::make_tuple("Dark_Bluish_Gray",0x6C6E68,0x333333)},
	{73,std::make_tuple("Medium_Blue",0x5C9DD1,0x333333)},
	{74,std::make_tuple("Medium_Green",0x73DCA1,0x333333)},
	{77,std::make_tuple("Light_Pink",0xFECCCF,0x333333)},
	{78,std::make_tuple("Light_Flesh",0xF6D7B3,0x333333)},
	{84,std::make_tuple("Medium_Dark_Flesh",0xCC702A,0x333333)},
	{85,std::make_tuple("Dark_Purple",0x3F3691,0x1E1E1E)},
	{86,std::make_tuple("Dark_Flesh",0x7C503A,0x333333)},
	{89,std::make_tuple("Blue_Violet",0x4C61DB,0x333333)},
	{92,std::make_tuple("Flesh",0xD09168,0x333333)},
	{100,std::make_tuple("Light_Salmon",0xFEBABD,0x333333)},
	{110,std::make_tuple("Violet",0x4354A3,0x333333)},
	{112,std::make_tuple("Medium_Violet",0x6874CA,0x333333)},
	{115,std::make_tuple("Medium_Lime",0xC7D23C,0x333333)},
	{118,std::make_tuple("Aqua",0xB3D7D1,0x333333)},
	{120,std::make_tuple("Light_Lime",0xD9E4A7,0x333333)},
	{125,std::make_tuple("Light_Orange",0xF9BA61,0x333333)},
	{151,std::make_tuple("Very_Light_Bluish_Gray",0xE6E3E0,0x333333)},
	{191,std::make_tuple("Bright_Light_Orange",0xF8BB3D,0x333333)},
	{212,std::make_tuple("Bright_Light_Blue",0x86C1E1,0x333333)},
	{216,std::make_tuple("Rust",0xB31004,0x333333)},
	{226,std::make_tuple("Bright_Light_Yellow",0xFFF03A,0x333333)},
	{232,std::make_tuple("Sky_Blue",0x56BED6,0x333333)},
	{272,std::make_tuple("Dark_Blue",0x0D325B,0x1E1E1E)},
	{288,std::make_tuple("Dark_Green",0x184632,0x595959)},
	{308,std::make_tuple("Dark_Brown",0x352100,0x595959)},
	{313,std::make_tuple("Maersk_Blue",0x54A9C8,0x333333)},
	{320,std::make_tuple("Dark_Red",0x720E0F,0x333333)},
	{321,std::make_tuple("Dark_Azure",0x1498D7,0x333333)},
	{322,std::make_tuple("Medium_Azure",0x3EC2DD,0x333333)},
	{323,std::make_tuple("Light_Aqua",0xBDDCD8,0x333333)},
	{326,std::make_tuple("Yellowish_Green",0xDFEEA5,0x333333)},
	{330,std::make_tuple("Olive_Green",0x9B9A5A,0x333333)},
	{335,std::make_tuple("Sand_Red",0xD67572,0x333333)},
	{351,std::make_tuple("Medium_Dark_Pink",0xF785B1,0x333333)},
	{366,std::make_tuple("Earth_Orange",0xFA9C1C,0x333333)},
	{373,std::make_tuple("Sand_Purple",0x845E84,0x333333)},
	{378,std::make_tuple("Sand_Green",0xA0BCAC,0x333333)},
	{379,std::make_tuple("Sand_Blue",0x597184,0x333333)},
	{450,std::make_tuple("Fabuland_Brown",0xB67B50,0x333333)},
	{462,std::make_tuple("Medium_Orange",0xFFA70B,0x333333)},
	{484,std::make_tuple("Dark_Orange",0xA95500,0x333333)},
	{503,std::make_tuple("Very_Light_Gray",0xE6E3DA,0x333333)}
};
	//<unsigned int, unsigned int> >

#endif // LDRAWCOLORS_H
