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
#include "MeldedKongTypes.h"
#include "MeldTypes.h"
#include "SetArrangements.h"
#include "MemorySavedSet.h"


using namespace openriichi;


MemorySavedSet::MemorySavedSet()
	: MemorySavedSet(SetArrangements::CHOW, Tile(TileDesigns::CIRCLES, 1))
{
	// 何もしない。
}


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


bool MemorySavedSet::operator==(const MemorySavedSet &other) const
{
	bool returnValue = m_value == other.m_value && m_keyTile == other.m_keyTile;		// 戻り値。

	return returnValue;
}


bool MemorySavedSet::operator!=(const MemorySavedSet &other) const
{
	bool returnValue = m_value != other.m_value || m_keyTile != other.m_keyTile;		// 戻り値。

	return returnValue;
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

	case MeldTypeValue::CENTER:
		returnValue = &MeldTypes::CENTER;
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


const Tile &MemorySavedSet::getKeyTile() const
{
	return m_keyTile;
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
