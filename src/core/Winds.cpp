/*
 * Copyright 2015 calotocen
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "OpenRiichi.h"


using namespace openriichi;


const Wind Winds::EAST(EAST_ID);
const Wind Winds::SOUTH(SOUTH_ID);
const Wind Winds::WEST(WEST_ID);
const Wind Winds::NORTH(NORTH_ID);


Wind::Wind(int id)
	: Enumeration(id)
{
	// 何もしない。
}


Wind Wind::getPreviousWind() const
{
	const Wind *returnValue = nullptr;		// 戻り値。

	switch (getId()) {
	case Winds::EAST_ID:
		returnValue = &Winds::NORTH;
		break;

	case Winds::SOUTH_ID:
		returnValue = &Winds::EAST;
		break;

	case Winds::WEST_ID:
		returnValue = &Winds::SOUTH;
		break;

	case Winds::NORTH_ID:
		returnValue = &Winds::WEST;
		break;
	}

	return *returnValue;
}


Wind Wind::getNextWind() const
{
	const Wind *returnValue = nullptr;		// 戻り値。

	switch (getId()) {
	case Winds::EAST_ID:
		returnValue = &Winds::SOUTH;
		break;

	case Winds::SOUTH_ID:
		returnValue = &Winds::WEST;
		break;

	case Winds::WEST_ID:
		returnValue = &Winds::NORTH;
		break;

	case Winds::NORTH_ID:
		returnValue = &Winds::EAST;
		break;
	}

	return *returnValue;
}
