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
#include "DiscardSources.h"
#include "MemorySavedDiscard.h"


using namespace openriichi;


MemorySavedDiscard::MemorySavedDiscard()
	: MemorySavedDiscard(Tile(), DiscardSources::DRAWED)
{
	// 何もしない。
}


MemorySavedDiscard::MemorySavedDiscard(const Tile &tile, const DiscardSource & source, bool riichiDeclared, bool taken)
	: m_value(0)
	, m_tile(tile)
{
	// デバッグ版の場合のみ，引数をチェックする。
	assert(source == DiscardSources::DRAWED || source == DiscardSources::HELD);

	// 捨て元を設定する。
	switch (source.getId()) {
	case DiscardSources::DRAWED.ID:
		m_value = SourceValue::DRAWED;
		break;

	case DiscardSources::HELD.ID:
		m_value = SourceValue::HELD;
		break;
	}

	// 立直宣言牌であるかを設定する。
	if (riichiDeclared) {
		m_value |= RiichiDeclaredValue::RDV_TRUE;
	}

	// 鳴かれた牌であるかを設定する。
	if (taken) {
		m_value |= TakenValue::TV_TRUE;
	}
}


bool MemorySavedDiscard::operator==(const MemorySavedDiscard & other) const
{
	// 自分自身との比較であれば，true を返す。
	if (this == &other)
	{
		return true;
	}

	// 捨て牌属性値と捨て牌を比較して，その結果を返す。
	return m_value == other.m_value && m_tile == other.m_tile;
}


bool MemorySavedDiscard::operator!=(const MemorySavedDiscard & other) const
{
	return !(*this == other);
}


const Tile &MemorySavedDiscard::getTile() const
{
	return m_tile;
}


const DiscardSource &MemorySavedDiscard::getSource() const
{
	uint8_t sourceValue;							// 捨て元を表す値。
	const DiscardSource *returnValue = nullptr;		// 戻り値。

	// 値に応じた捨て元を返す。
	sourceValue = m_value & Mask::SOURCE;
	switch (sourceValue) {
	case SourceValue::DRAWED:
		returnValue = &DiscardSources::DRAWED;
		break;

	case SourceValue::HELD:
		returnValue = &DiscardSources::HELD;
		break;
	}

	return *returnValue;
}


bool MemorySavedDiscard::isRiichiDeclared() const
{
	uint8_t riichiDeclaredValue;		// 立直宣言牌であるかを表す値。
	bool returnValue;					// 戻り値。

	// 値に応じた戻り値を返す。
	riichiDeclaredValue = m_value & Mask::RIICHI_DECLARED;
	returnValue = (riichiDeclaredValue) ? true : false;

	return returnValue;
}


bool MemorySavedDiscard::isTaken() const
{
	uint8_t takenValue;		// 鳴かれた牌であるかを表す値。
	bool returnValue;		// 戻り値。

	// 値に応じた戻り値を返す。
	takenValue = m_value & Mask::TAKEN;
	returnValue = (takenValue) ? true : false;

	return returnValue;
}
