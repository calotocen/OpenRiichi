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
#include <algorithm>
#include <cstdint>
#include "OpenRiichiConfiguration.h"
#include "MeldedKongTypes.h"
#include "MeldTypes.h"
#include "OpenRiichiAssertion.h"
#include "SetArrangements.h"
#include "Tile.h"
#include "Tiles.h"
#include "MemorySavedSet.h"


using namespace std;
using namespace openriichi;


MemorySavedSet::MemorySavedSet()
	: MemorySavedSet(P1, P2, P3)
{
	// 何もしない。
}


MemorySavedSet::MemorySavedSet(const Tile & tile1, const Tile & tile2)
	: m_value(0)
	, m_tiles()
{
	// アサーションが有効である場合のみ，引数をチェックする。
	openriichi_assert(tile1.getDesign() == tile2.getDesign() && tile1.getNumber() == tile2.getNumber());

	// 面子属性を設定する。
	setArrangement(SetArrangements::PAIR);

	// 牌を格納する。
	m_tiles.add(tile1);
	m_tiles.add(tile2);
}


MemorySavedSet::MemorySavedSet(const Tile & tile1, const Tile & tile2, const Tile & tile3, const MeldType & meldType)
	: m_value(0)
	, m_tiles()
{
	// アサーションが有効である場合のみ，引数をチェックする。
#if OPENRIICHI_ENABLE_ASSERTION == 1
	int number[3] = { tile1.getNumber(), tile2.getNumber(), tile3.getNumber() };
	sort(number, number + 3);

	openriichi_assert(tile1.getDesign() == tile2.getDesign() && tile1.getDesign() == tile3.getDesign());
	openriichi_assert((number[0] + 1 == number[1] && number[0] + 2 == number[2])
		|| (number[0] == number[1] && number[0] == number[2]));
	openriichi_assert(meldType == MeldTypes::NONE || meldType == MeldTypes::LEFT || meldType == MeldTypes::ACROSS || meldType == MeldTypes::RIGHT);
	openriichi_assert((number[0] == number[1]) || (meldType == MeldTypes::NONE || meldType == MeldTypes::LEFT));
#endif	// !defined(NDEBUG)

	// 面子属性を設定する。
	if (tile1.getNumber() != tile2.getNumber()) {
		setArrangement(SetArrangements::CHOW);
	} else {
		setArrangement(SetArrangements::PUNG);
	}
	setMeldType(meldType);

	// 牌を格納する。
	m_tiles.add(tile1);
	m_tiles.add(tile2);
	m_tiles.add(tile3);
}


MemorySavedSet::MemorySavedSet(const Tile & tile1, const Tile & tile2, const Tile & tile3, const Tile & tile4, const MeldedKongType & meldedKongType, const MeldType & meldType)
	: m_value(0)
	, m_tiles() 
{
	// アサーションが有効である場合のみ，引数をチェックする。
	openriichi_assert(tile1.getDesign() == tile2.getDesign() && tile1.getDesign() == tile3.getDesign() && tile1.getDesign() == tile4.getDesign());
	openriichi_assert(tile1.getNumber() == tile2.getNumber() && tile1.getNumber() == tile3.getNumber() && tile1.getNumber() == tile4.getNumber());
	openriichi_assert(meldType == MeldTypes::NONE || meldType == MeldTypes::LEFT || meldType == MeldTypes::ACROSS || meldType == MeldTypes::RIGHT);
	openriichi_assert(meldedKongType == MeldedKongTypes::NO || meldedKongType == MeldedKongTypes::LITTLE || meldedKongType == MeldedKongTypes::BIG);
	openriichi_assert((meldedKongType == MeldedKongTypes::NO && meldType == MeldTypes::NONE)
		|| (meldedKongType != MeldedKongTypes::NO && meldType != MeldTypes::NONE));

	// 面子属性を設定する。
	setArrangement(SetArrangements::KONG);
	setMeldedKongType(meldedKongType);
	setMeldType(meldType);

	// 牌を格納する。
	m_tiles.add(tile1);
	m_tiles.add(tile2);
	m_tiles.add(tile3);
	m_tiles.add(tile4);
}


bool MemorySavedSet::operator==(const MemorySavedSet &other) const
{
	if (this == &other) {
		return true;
	}

	return m_value == other.m_value && m_tiles == other.m_tiles;
}


bool MemorySavedSet::operator!=(const MemorySavedSet &other) const
{
	return !(*this == other);
}


void MemorySavedSet::setArrangement(const SetArrangement & setArrangement)
{
	// 面子属性値の面子種別をリセットする。
	m_value &= ~Mask::ARRANGEMENT;

	// 面子種別に応じた値を設定する。
	switch (setArrangement.getId()) {
	case SetArrangements::CHOW.ID:
		m_value |= ArrangementValue::CHOW;
		break;

	case SetArrangements::PAIR.ID:
		m_value |= ArrangementValue::PAIR;
		break;

	case SetArrangements::PUNG.ID:
		m_value |= ArrangementValue::PUNG;
		break;

	case SetArrangements::KONG.ID:
		m_value |= ArrangementValue::KONG;
		break;
	}
}


void MemorySavedSet::setMeldType(const MeldType & meldType)
{
	// 面子属性値の鳴き種別をリセットする。
	m_value &= ~Mask::MELD_TYPE;

	// 鳴き種別に応じた値を設定する。
	switch (meldType.getId()) {
	case MeldTypes::LEFT.ID:
		m_value |= MeldTypeValue::LEFT;
		break;

	case MeldTypes::ACROSS.ID:
		m_value |= MeldTypeValue::ACROSS;
		break;

	case MeldTypes::RIGHT.ID:
		m_value |= MeldTypeValue::RIGHT;
		break;
	}
}


void MemorySavedSet::setMeldedKongType(const MeldedKongType & meldedKongType)
{
	// 面子属性値の鳴き槓子種別をリセットする。
	m_value &= ~Mask::MELDED_KONG_TYPE;

	// 鳴き槓子種別に応じた値を設定する。
	switch (meldedKongType.getId()) {
	case MeldedKongTypes::LITTLE.ID:
		m_value |= MeldedKongTypeValue::LITTLE;
		break;

	case MeldedKongTypes::BIG.ID:
		m_value |= MeldedKongTypeValue::BIG;
		break;
	}
}


const SetArrangement &MemorySavedSet::getArrangement() const
{
	const SetArrangement *returnValue = nullptr;		// 戻り値。

	// 値に応じた面子種別を返す。
	switch (m_value & Mask::ARRANGEMENT) {
	case ArrangementValue::CHOW:
		returnValue = &SetArrangements::CHOW;
		break;

	case ArrangementValue::PAIR:
		returnValue = &SetArrangements::PAIR;
		break;

	case ArrangementValue::PUNG:
		returnValue = &SetArrangements::PUNG;
		break;

	case ArrangementValue::KONG:
		returnValue = &SetArrangements::KONG;
		break;
	}

	return *returnValue;
}


const MeldType &MemorySavedSet::getMeldType() const
{
	const MeldType *returnValue = nullptr;		// 戻り値。

	// 値に応じた鳴き種別を返す。
	switch (m_value & Mask::MELD_TYPE) {
	case MeldTypeValue::NONE:
		returnValue = &MeldTypes::NONE;
		break;

	case MeldTypeValue::LEFT:
		returnValue = &MeldTypes::LEFT;
		break;

	case MeldTypeValue::ACROSS:
		returnValue = &MeldTypes::ACROSS;
		break;

	case MeldTypeValue::RIGHT:
		returnValue = &MeldTypes::RIGHT;
		break;
	}

	return *returnValue;
}


const MeldedKongType &MemorySavedSet::getMeldedKongType() const
{
	const MeldedKongType *returnValue = nullptr;		// 戻り値。

	// 値に応じた鳴き槓子種別を返す。
	switch (m_value & Mask::MELDED_KONG_TYPE) {
	case MeldedKongTypeValue::NO:
		returnValue = &MeldedKongTypes::NO;
		break;

	case MeldedKongTypeValue::LITTLE:
		returnValue = &MeldedKongTypes::LITTLE;
		break;

	case MeldedKongTypeValue::BIG:
		returnValue = &MeldedKongTypes::BIG;
		break;
	}

	return *returnValue;
}


const MemorySavedSet::Tiles &MemorySavedSet::getTiles() const
{
	return m_tiles;
}


bool MemorySavedSet::isChow() const
{
	return (m_value & Mask::ARRANGEMENT) == ArrangementValue::CHOW;
}


bool MemorySavedSet::isPair() const
{
	return (m_value & Mask::ARRANGEMENT) == ArrangementValue::PAIR;
}

bool MemorySavedSet::isPung() const
{
	return (m_value & Mask::ARRANGEMENT) == ArrangementValue::PUNG;
}


bool MemorySavedSet::isKong() const
{
	return (m_value & Mask::ARRANGEMENT) == ArrangementValue::KONG;
}


bool MemorySavedSet::isConcealed() const
{
	return (m_value & Mask::MELD_TYPE) == MeldTypeValue::NONE;
}


bool MemorySavedSet::isMelded() const
{
	return (m_value & Mask::MELD_TYPE) != MeldTypeValue::NONE;
}
