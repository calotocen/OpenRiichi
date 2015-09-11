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
#include <cassert>
#include <cstdint>
#include "MeldedKongTypes.h"
#include "MeldTypes.h"
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


#if 0
MemorySavedSet::MemorySavedSet(const SetArrangement & setArrangement, const Tile & keyTile)
	: MemorySavedSet(setArrangement, MeldTypes::NONE, keyTile)
{
	// 何もしない。
}


MemorySavedSet::MemorySavedSet(const SetArrangement & setArrangement, const MeldType & meldType, const Tile & keyTile)
	: MemorySavedSet(setArrangement, meldType, MeldedKongTypes::NO, keyTile)
{
	// 何もしない。
}


MemorySavedSet::MemorySavedSet(const SetArrangement & setArrangement, const MeldType & meldType, const MeldedKongType & meldedKongType, const Tile & keyTile)
	: m_value(0)
	, m_keyTile(keyTile)
{
	// デバッグ版の場合のみ，引数をチェックする。
	assert(setArrangement == SetArrangements::CHOW || setArrangement == SetArrangements::PAIR ||
		setArrangement == SetArrangements::PUNG || setArrangement == SetArrangements::KONG);
	assert(meldType == MeldTypes::NONE || meldType == MeldTypes::LEFT || meldType == MeldTypes::CENTER || meldType == MeldTypes::RIGHT);
	assert(meldedKongType == MeldedKongTypes::NO || meldedKongType == MeldedKongTypes::LITTLE || meldedKongType == MeldedKongTypes::BIG);
	assert((setArrangement == SetArrangements::CHOW && (keyTile.isSuits() || keyTile.getNumber() <= 7))
		|| (setArrangement == SetArrangements::PAIR && meldType == MeldTypes::NONE)
		|| (setArrangement != SetArrangements::KONG && meldedKongType == MeldedKongTypes::NO)
		|| (setArrangement == SetArrangements::KONG
			&& ((meldType == MeldTypes::NONE && meldedKongType == MeldedKongTypes::NO)
				|| (meldType != MeldTypes::NONE && meldedKongType != MeldedKongTypes::NO))));

	// 面子種別に応じた値を設定する。
	switch (setArrangement.getId()) {
	case SetArrangements::CHOW.ID:
		m_value = ArrangementValue::CHOW;
		break;

	case SetArrangements::PAIR.ID:
		m_value = ArrangementValue::PAIR;
		break;

	case SetArrangements::PUNG.ID:
		m_value = ArrangementValue::PUNG;
		break;

	case SetArrangements::KONG.ID:
		m_value = ArrangementValue::KONG;
		break;
	}

	// 鳴き種別に応じた値を設定する。
	switch (meldType.getId()) {
	case MeldTypes::LEFT.ID:
		m_value |= MeldTypeValue::LEFT;
		break;

	case MeldTypes::CENTER.ID:
		m_value |= MeldTypeValue::CENTER;
		break;

	case MeldTypes::RIGHT.ID:
		m_value |= MeldTypeValue::RIGHT;
		break;
	}

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
#endif


MemorySavedSet::MemorySavedSet(const Tile & tile1, const Tile & tile2)
	: m_value(0)
	, m_tiles()
{
	// デバッグ版の場合のみ，引数をチェックする。
	assert(tile1.getDesign() == tile2.getDesign() && tile1.getNumber() == tile2.getNumber());

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
	// デバッグ版の場合のみ，引数をチェックする。
#if !defined(NDEBUG)
	int number[3] = { tile1.getNumber(), tile2.getNumber(), tile3.getNumber() };
	sort(number, number + 3);

	assert(tile1.getDesign() == tile2.getDesign() && tile1.getDesign() == tile3.getDesign());
	assert((number[0] + 1 == number[1] && number[0] + 2 == number[2])
		|| (number[0] == number[1] && number[0] == number[2]));
	assert((number[0] == number[1]) || (meldType == MeldTypes::NONE || meldType == MeldTypes::LEFT));
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
	// デバッグ版の場合のみ，引数をチェックする。
	assert(tile1.getDesign() == tile2.getDesign() && tile1.getDesign() == tile3.getDesign() && tile1.getDesign() == tile4.getDesign());
	assert(tile1.getNumber() == tile2.getNumber() && tile1.getNumber() == tile3.getNumber() && tile1.getNumber() == tile4.getNumber());

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
	m_value &= ~Mask::SET_ARRANGEMENT;

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
	uint8_t arrangementValue;							// 面子種別値。
	const SetArrangement *returnValue = nullptr;		// 戻り値。

	// 値に応じた面子種別を返す。
	arrangementValue = m_value & Mask::SET_ARRANGEMENT;
	switch (arrangementValue) {
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
	uint8_t meldTypeValue;						// 鳴き種別値。
	const MeldType *returnValue = nullptr;		// 戻り値。

	// 値に応じた鳴き種別を返す。
	meldTypeValue = m_value & Mask::MELD_TYPE;
	switch (meldTypeValue) {
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
	uint8_t meldedKongValue;							// 鳴き槓子種別値。
	const MeldedKongType *returnValue = nullptr;		// 戻り値。

	// 値に応じた鳴き槓子種別を返す。
	meldedKongValue = m_value & Mask::MELDED_KONG_TYPE;
	switch (meldedKongValue) {
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
	uint8_t arrangementValue;		// 面子種別値。
	bool returnValue;				// 戻り値。

	// 面子種別が順子であるかを調べる。
	arrangementValue = m_value & Mask::SET_ARRANGEMENT;
	returnValue = arrangementValue == ArrangementValue::CHOW;

	return returnValue;
}


bool MemorySavedSet::isPair() const
{
	uint8_t arrangementValue;		// 面子種別値。
	bool returnValue;				// 戻り値。

	// 面子種別が対子であるかを調べる。
	arrangementValue = m_value & Mask::SET_ARRANGEMENT;
	returnValue = arrangementValue == ArrangementValue::PAIR;

	return returnValue;
}

bool MemorySavedSet::isPung() const
{
	uint8_t arrangementValue;		// 面子種別値。
	bool returnValue;				// 戻り値。

	// 面子種別が刻子であるかを調べる。
	arrangementValue = m_value & Mask::SET_ARRANGEMENT;
	returnValue = arrangementValue == ArrangementValue::PUNG;

	return returnValue;
}


bool MemorySavedSet::isKong() const
{
	uint8_t arrangementValue;		// 面子種別値。
	bool returnValue;				// 戻り値。

	// 面子種別が槓子であるかを調べる。
	arrangementValue = m_value & Mask::SET_ARRANGEMENT;
	returnValue = arrangementValue == ArrangementValue::KONG;

	return returnValue;
}


bool MemorySavedSet::isConcealed() const
{
	uint8_t meldTypeValue;		// 鳴き種別値。
	bool returnValue;			// 戻り値。

	// 面前面子であるかを調べる。
	meldTypeValue = m_value & Mask::MELD_TYPE;
	returnValue = meldTypeValue == MeldTypeValue::NONE;

	return returnValue;
}


bool MemorySavedSet::isMelded() const
{
	uint8_t meldTypeValue;		// 鳴き種別値。
	bool returnValue;			// 戻り値。

	// 鳴き面子であるかを調べる。
	meldTypeValue = m_value & Mask::MELD_TYPE;
	returnValue = meldTypeValue != MeldTypeValue::NONE;

	return returnValue;
}
