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
#include <cassert>
#include "TileAttributes.h"
#include "TileDesigns.h"
#include "MemorySavedTile.h"


using namespace openriichi;


MemorySavedTile::MemorySavedTile(const TileDesign &design, const TileAttribute &attribute)
	: m_value(0)
{
	// デバッグ版の場合のみ，引数をチェックする。
	assert(design == TileDesigns::EAST
		|| design == TileDesigns::SOUTH
		|| design == TileDesigns::WEST
		|| design == TileDesigns::NORTH
		|| design == TileDesigns::RED
		|| design == TileDesigns::WHITE
		|| design == TileDesigns::GREEN);
	assert(attribute == TileAttributes::NONE);
		
	// 図柄に応じた値を設定する。
	switch (design.getId()) {
		case TileDesigns::EAST.ID:
			m_value = DesignValue::EAST;
			break;

		case TileDesigns::SOUTH.ID:
			m_value = DesignValue::SOUTH;
			break;

		case TileDesigns::WEST.ID:
			m_value = DesignValue::WEST;
			break;

		case TileDesigns::NORTH.ID:
			m_value = DesignValue::NORTH;
			break;

		case TileDesigns::RED.ID:
			m_value = DesignValue::DV_RED;
			break;

		case TileDesigns::GREEN.ID:
			m_value = DesignValue::GREEN;
			break;

		case TileDesigns::WHITE.ID:
			m_value = DesignValue::WHITE;
			break;
	}
}


MemorySavedTile::MemorySavedTile(const TileDesign &design, int number, const TileAttribute &attribute)
	: m_value(0)
{
	// デバッグ版の場合のみ，引数をチェックする。
	assert(design == TileDesigns::CIRCLES
		|| design == TileDesigns::BAMBOO
		|| design == TileDesigns::CHARACTERS);
	assert(Range::MINIMUM_NUMBER <= number && number <= Range::MAXIMUM_NUMBER);
	assert(attribute == TileAttributes::NONE
		|| attribute == TileAttributes::RED);

	// 属性に応じた値を設定する。
	switch (attribute.getId()) {
	case TileAttributes::RED.ID:
		m_value = AttributeValue::AV_RED;
		break;
	}

	// 図柄に応じた値を設定する。
	switch (design.getId()) {
	case TileDesigns::CIRCLES.ID:
		m_value |= DesignValue::CIRCLES;
		break;

	case TileDesigns::BAMBOO.ID:
		m_value |= DesignValue::BAMBOO;
		break;

	case TileDesigns::CHARACTERS.ID:
		m_value |= DesignValue::CHARACTERS;
		break;
	}

	// 数字に応じた値を設定する。
	m_value |= number;
}


const TileDesign *MemorySavedTile::getDesign() const
{
	unsigned char designValue;						// 図柄値。
	const TileDesign *returnValue = nullptr;		// 戻り値。

	// 図柄値を取得する。
	designValue = m_value & Mask::DESIGN_TYPE;
	if (Range::MINIMUM_DESIGN_TYPE_HONOUR <= designValue && designValue <= Range::MAXIMUM_DESIGN_TYPE_HONOUR) {
		designValue = m_value & (Mask::DESIGN_TYPE | Mask::NUMBER);
	}

	// 図柄値に対応する図柄を返す。
	switch (designValue) {
	case DesignValue::CIRCLES:
		returnValue = &TileDesigns::CIRCLES;
		break;

	case DesignValue::BAMBOO:
		returnValue = &TileDesigns::BAMBOO;
		break;

	case DesignValue::CHARACTERS:
		returnValue = &TileDesigns::CHARACTERS;
		break;

	case DesignValue::EAST:
		returnValue = &TileDesigns::EAST;
		break;

	case DesignValue::SOUTH:
		returnValue = &TileDesigns::SOUTH;
		break;

	case DesignValue::WEST:
		returnValue = &TileDesigns::WEST;
		break;

	case DesignValue::NORTH:
		returnValue = &TileDesigns::NORTH;
		break;

	case DesignValue::DV_RED:
		returnValue = &TileDesigns::RED;
		break;

	case DesignValue::WHITE:
		returnValue = &TileDesigns::WHITE;
		break;

	case DesignValue::GREEN:
		returnValue = &TileDesigns::GREEN;
		break;
	}

	return returnValue;
}


int MemorySavedTile::getNumber() const
{
	unsigned char designType;		// 図柄種別。
	int returnValue;				// 戻り値。

	// 図柄に応じて返す値を決める。
	designType = m_value & Mask::DESIGN_TYPE;
	if (Range::MINIMUM_DESIGN_TYPE_SUIT <= designType && designType <= Range::MAXIMUM_DESIGN_TYPE_SUIT) {
		returnValue = (m_value & Mask::NUMBER);
	}
	else {
		returnValue = 0;
	}

	return returnValue;
}


const TileAttribute *MemorySavedTile::getAttribute() const
{
	unsigned char attributeValue;					// 属性値。
	const TileAttribute *returnValue = nullptr;		// 戻り値。

	// 値に応じた属性を返す。
	attributeValue = m_value & Mask::ATTRIBUTE;
	switch (attributeValue) {
	case AttributeValue::NONE:
		returnValue = &TileAttributes::NONE;
		break;

	case AttributeValue::AV_RED:
		returnValue = &TileAttributes::RED;
		break;
	}

	return returnValue;
}


bool MemorySavedTile::isSuit() const
{
	unsigned char designType;		// 図柄種別値。
	bool returnValue;				// 戻り値。

	// 図柄が数牌であるかを調べる。
	designType = m_value & Mask::DESIGN_TYPE;
	returnValue = (Range::MINIMUM_DESIGN_TYPE_SUIT <= designType && designType <= Range::MAXIMUM_DESIGN_TYPE_SUIT);

	return returnValue;
}


bool MemorySavedTile::isHonour() const
{
	unsigned char designType;		// 図柄種別値。
	bool returnValue;				// 戻り値。

	// 図柄が字牌であるかを調べる。
	designType = m_value & Mask::DESIGN_TYPE;
	returnValue = (Range::MINIMUM_DESIGN_TYPE_HONOUR <= designType && designType <= Range::MAXIMUM_DESIGN_TYPE_HONOUR);

	return returnValue;
}


bool MemorySavedTile::isWind() const
{
	unsigned char designType;		// 図柄種別値。
	bool returnValue;				// 戻り値。

	// 図柄が風牌であるかを調べる。
	designType = m_value & Mask::DESIGN_TYPE;
	returnValue = (Range::MINIMUM_DESIGN_TYPE_WIND <= designType && designType <= Range::MAXIMUM_DESIGN_TYPE_WIND);

	return returnValue;
}


bool MemorySavedTile::isDragon() const
{
	unsigned char designType;		// 図柄種別値。
	bool returnValue;				// 戻り値。

	// 図柄が三元牌であるかを調べる。
	designType = m_value & Mask::DESIGN_TYPE;
	returnValue = (Range::MINIMUM_DESIGN_TYPE_DRAGON <= designType && designType <= Range::MAXIMUM_DESIGN_TYPE_DRAGON);

	return returnValue;
}


bool MemorySavedTile::isSimple() const
{
	unsigned char designType;		// 図柄種別値。
	unsigned char number;			// 数字。
	bool returnValue;				// 戻り値。

	// 中張牌であるかを調べる。
	designType = m_value & Mask::DESIGN_TYPE;
	number = m_value & Mask::NUMBER;
	returnValue = ((Range::MINIMUM_DESIGN_TYPE_SUIT <= designType && designType <= Range::MAXIMUM_DESIGN_TYPE_SUIT)
		&& (number != Range::MINIMUM_NUMBER && number != Range::MAXIMUM_NUMBER));

	return returnValue;
}


bool MemorySavedTile::isTerminal() const
{
	unsigned char designType;		// 図柄種別値。
	unsigned char number;			// 数字。
	bool returnValue;				// 戻り値。

	// 老頭牌であるかを調べる。
	designType = m_value & Mask::DESIGN_TYPE;
	number = m_value & Mask::NUMBER;
	returnValue = ((Range::MINIMUM_DESIGN_TYPE_SUIT <= designType && designType <= Range::MAXIMUM_DESIGN_TYPE_SUIT)
		&& (number == Range::MINIMUM_NUMBER || number == Range::MAXIMUM_NUMBER));

	return returnValue;
}


bool MemorySavedTile::isTerminalOrHonour() const
{
	unsigned char designType;		// 図柄種別値。
	unsigned char number;			// 数字。
	bool returnValue;				// 戻り値。

	// 幺九牌であるかを調べる。
	designType = m_value & Mask::DESIGN_TYPE;
	number = m_value & Mask::NUMBER;
	returnValue = ((Range::MINIMUM_DESIGN_TYPE_HONOUR <= designType && designType <= Range::MAXIMUM_DESIGN_TYPE_HONOUR)
		|| (number == Range::MINIMUM_NUMBER || number == Range::MAXIMUM_NUMBER));

	return returnValue;
}
