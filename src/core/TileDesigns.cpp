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
#include "OpenRiichiConfiguration.h"
#include "OpenRiichiAssertion.h"
#include "TileDesigns.h"


using namespace openriichi;


const TileDesign TileDesigns::CIRCLES(CIRCLES_ID, TileDesign::SUITS_TYPE);
const TileDesign TileDesigns::BAMBOO(BAMBOO_ID, TileDesign::SUITS_TYPE);
const TileDesign TileDesigns::CHARACTERS(CHARACTERS_ID, TileDesign::SUITS_TYPE);
const TileDesign TileDesigns::EAST(EAST_ID, TileDesign::WINDS_TYPE);
const TileDesign TileDesigns::SOUTH(SOUTH_ID, TileDesign::WINDS_TYPE);
const TileDesign TileDesigns::WEST(WEST_ID, TileDesign::WINDS_TYPE);
const TileDesign TileDesigns::NORTH(NORTH_ID, TileDesign::WINDS_TYPE);
const TileDesign TileDesigns::RED(RED_ID, TileDesign::DRAGONS_TYPE);
const TileDesign TileDesigns::WHITE(WHITE_ID, TileDesign::DRAGONS_TYPE);
const TileDesign TileDesigns::GREEN(GREEN_ID, TileDesign::DRAGONS_TYPE);


TileDesign::TileDesign(int id, int type)
	: Enumeration(id)
	, m_type(type)
{
	// アサーションが有効である場合のみ，引数をチェックする。
	openriichi_assert(type == SUITS_TYPE || type == WINDS_TYPE || type == DRAGONS_TYPE);
}


bool TileDesign::isSuits() const
{
	return (m_type == SUITS_TYPE);
}


bool TileDesign::isHonours() const
{
	return (m_type != SUITS_TYPE);
}


bool TileDesign::isWinds() const
{
	return (m_type == WINDS_TYPE);
}


bool TileDesign::isDragons() const
{
	return (m_type == DRAGONS_TYPE);
}
