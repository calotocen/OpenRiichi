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
#include <cstdint>
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


MemorySavedTile::MemorySavedTile()
	: m_value(DesignValue::CIRCLES | 1)
{
	// 何もしない。
}


MemorySavedTile::MemorySavedTile(const TileDesign &design, int number, const TileAttribute &attribute)
	: m_value(0)
{
	// デバッグ版の場合のみ，引数をチェックする。
	assert(design == TileDesigns::CIRCLES
		|| design == TileDesigns::BAMBOO
		|| design == TileDesigns::CHARACTERS);
	assert(Range::MIN_NUMBER <= number && number <= Range::MAX_NUMBER);
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


MemorySavedTile::MemorySavedTile(int designId, int number, int attributeId)
	: m_value(0)
{
	// グローバル変数，およびクラスのスタティック変数に依存しないように注意して処理を実装する。

	// デバッグ版の場合のみ，引数をチェックする。
	assert(1 <= designId && designId <= 10);
	assert(((1 <= designId && designId <= 3) && (1 <= number && number <= 9)) || number == 0);
	assert(0 <= attributeId && attributeId <= 1);

	// 図柄を設定する。
	switch (designId)
	{
	case 1: // 筒子
		m_value = DesignValue::CIRCLES;
		break;

	case 2: // 索子
		m_value = DesignValue::BAMBOO;
		break;

	case 3: // 萬子
		m_value = DesignValue::CHARACTERS;
		break;

	case 4: // 東
		m_value = DesignValue::EAST;
		break;

	case 5: // 南
		m_value = DesignValue::SOUTH;
		break;

	case 6: // 西
		m_value = DesignValue::WEST;
		break;

	case 7: // 北
		m_value = DesignValue::NORTH;
		break;

	case 8: // 中
		m_value = DesignValue::DV_RED;
		break;

	case 9: // 白
		m_value = DesignValue::WHITE;
		break;

	case 10: // 發
		m_value = DesignValue::GREEN;
		break;
	}

	// 数字を設定する。
	m_value |= number;

	// 属性を設定する。
	switch (attributeId)
	{
	case 1:
		m_value |= AttributeValue::AV_RED;
		break;
	}
}


bool MemorySavedTile::operator==(const MemorySavedTile &other) const
{
	bool returnValue = m_value == other.m_value;		// 戻り値。

	return returnValue;
}


bool MemorySavedTile::operator!=(const MemorySavedTile &other) const
{
	bool returnValue = m_value != other.m_value;		// 戻り値。

	return returnValue;
}


const TileDesign &MemorySavedTile::getDesign() const
{
	uint8_t designValue;							// 図柄値。
	const TileDesign *returnValue = nullptr;		// 戻り値。

	// 図柄値を取得する。
	designValue = m_value & Mask::DESIGN_TYPE;
	if (Range::MIN_DESIGN_TYPE_HONOURS <= designValue && designValue <= Range::MAX_DESIGN_TYPE_HONOURS) {
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

	return *returnValue;
}


int MemorySavedTile::getNumber() const
{
	uint8_t designType;		// 図柄種別。
	int returnValue;		// 戻り値。

	// 図柄に応じて返す値を決める。
	designType = m_value & Mask::DESIGN_TYPE;
	if (Range::MIN_DESIGN_TYPE_SUITS <= designType && designType <= Range::MAX_DESIGN_TYPE_SUITS) {
		returnValue = (m_value & Mask::NUMBER);
	}
	else {
		returnValue = 0;
	}

	return returnValue;
}


const TileAttribute &MemorySavedTile::getAttribute() const
{
	uint8_t attributeValue;							// 属性値。
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

	return *returnValue;
}


bool MemorySavedTile::isSuits() const
{
	uint8_t designType;		// 図柄種別値。
	bool returnValue;		// 戻り値。

	// 図柄が数牌であるかを調べる。
	designType = m_value & Mask::DESIGN_TYPE;
	returnValue = (Range::MIN_DESIGN_TYPE_SUITS <= designType && designType <= Range::MAX_DESIGN_TYPE_SUITS);

	return returnValue;
}


bool MemorySavedTile::isHonours() const
{
	uint8_t designType;		// 図柄種別値。
	bool returnValue;		// 戻り値。

	// 図柄が字牌であるかを調べる。
	designType = m_value & Mask::DESIGN_TYPE;
	returnValue = (Range::MIN_DESIGN_TYPE_HONOURS <= designType && designType <= Range::MAX_DESIGN_TYPE_HONOURS);

	return returnValue;
}


bool MemorySavedTile::isWinds() const
{
	uint8_t designType;		// 図柄種別値。
	bool returnValue;		// 戻り値。

	// 図柄が風牌であるかを調べる。
	designType = m_value & Mask::DESIGN_TYPE;
	returnValue = (Range::MIN_DESIGN_TYPE_WINDS <= designType && designType <= Range::MAX_DESIGN_TYPE_WINDS);

	return returnValue;
}


bool MemorySavedTile::isDragons() const
{
	uint8_t designType;		// 図柄種別値。
	bool returnValue;		// 戻り値。

	// 図柄が三元牌であるかを調べる。
	designType = m_value & Mask::DESIGN_TYPE;
	returnValue = (Range::MIN_DESIGN_TYPE_DRAGONS <= designType && designType <= Range::MAX_DESIGN_TYPE_DRAGONS);

	return returnValue;
}


bool MemorySavedTile::isSimples() const
{
	uint8_t designType;		// 図柄種別値。
	uint8_t number;			// 数字。
	bool returnValue;		// 戻り値。

	// 中張牌であるかを調べる。
	designType = m_value & Mask::DESIGN_TYPE;
	number = m_value & Mask::NUMBER;
	returnValue = ((Range::MIN_DESIGN_TYPE_SUITS <= designType && designType <= Range::MAX_DESIGN_TYPE_SUITS)
		&& (number != Range::MIN_NUMBER && number != Range::MAX_NUMBER));

	return returnValue;
}


bool MemorySavedTile::isTerminals() const
{
	uint8_t designType;		// 図柄種別値。
	uint8_t number;			// 数字。
	bool returnValue;		// 戻り値。

	// 老頭牌であるかを調べる。
	designType = m_value & Mask::DESIGN_TYPE;
	number = m_value & Mask::NUMBER;
	returnValue = ((Range::MIN_DESIGN_TYPE_SUITS <= designType && designType <= Range::MAX_DESIGN_TYPE_SUITS)
		&& (number == Range::MIN_NUMBER || number == Range::MAX_NUMBER));

	return returnValue;
}


bool MemorySavedTile::isTerminalsOrHonours() const
{
	uint8_t designType;		// 図柄種別値。
	uint8_t number;			// 数字。
	bool returnValue;		// 戻り値。

	// 幺九牌であるかを調べる。
	designType = m_value & Mask::DESIGN_TYPE;
	number = m_value & Mask::NUMBER;
	returnValue = ((Range::MIN_DESIGN_TYPE_HONOURS <= designType && designType <= Range::MAX_DESIGN_TYPE_HONOURS)
		|| (number == Range::MIN_NUMBER || number == Range::MAX_NUMBER));

	return returnValue;
}
