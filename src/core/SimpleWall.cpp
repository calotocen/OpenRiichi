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
#include <random>
#include "OpenRiichi.h"


using namespace std;
using namespace openriichi;


SimpleWall::SimpleWall()
	: SimpleWall(Tiles{
		P1, P1, P1, P1, P2, P2, P2, P2, P3, P3, P3, P3, P4, P4, P4, P4, P5, P5, P5, P5, P6, P6, P6, P6, P7, P7, P7, P7, P8, P8, P8, P8, P9, P9, P9, P9,
		S1, S1, S1, S1, S2, S2, S2, S2, S3, S3, S3, S3, S4, S4, S4, S4, S5, S5, S5, S5, S6, S6, S6, S6, S7, S7, S7, S7, S8, S8, S8, S8, S9, S9, S9, S9,
		M1, M1, M1, M1, M2, M2, M2, M2, M3, M3, M3, M3, M4, M4, M4, M4, M5, M5, M5, M5, M6, M6, M6, M6, M7, M7, M7, M7, M8, M8, M8, M8, M9, M9, M9, M9,
		TN, TN, TN, TN, NN, NN, NN, NN, SH, SH, SH, SH, PE, PE, PE, PE,
		CH, CH, CH, CH, HK, HK, HK, HK, HT, HT, HT, HT
	})
{
	// 何もしない。
}


SimpleWall::SimpleWall(const Tiles & tiles)
	: m_tiles(tiles)
	, m_doras()
	, m_uraDoras()
	, m_breakingIndex(3 * 34 + 2 * 2)
	, m_drawingIndex(0)
	, m_deadWallIndex(INITIAL_DEAD_WALL_INDEX)
#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	, m_lastRevealedDoraIndex(TILES_SIZE)
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
{
	// アサーションが有効である場合のみ，引数をチェックする。
	openriichi_assert(tiles.size() == TILES_SIZE);
}


bool openriichi::SimpleWall::operator==(const SimpleWall & other) const
{
	if (this == &other) {
		return true;
	}

	return m_tiles == other.m_tiles
		&& m_doras == other.m_doras
		&& m_uraDoras == other.m_uraDoras
		&& m_breakingIndex == other.m_breakingIndex
		&& m_drawingIndex == other.m_drawingIndex
		&& m_deadWallIndex == other.m_deadWallIndex;
}


bool openriichi::SimpleWall::operator!=(const SimpleWall & other) const
{
	return !(*this == other);
}


void SimpleWall::shuffle(unsigned int seed)
{
	mt19937 random(seed);

	// (TILES_SIZE * 10) 回だけループすると，各要素を平均 20 回入れ替えることになる。
	// 20 回も入れ替えれば，十分に撹拌されるだろう。
	// なお，十分に撹拌されるという数学的な根拠はない。
	for (int i = 0; i < TILES_SIZE * 10; ++i) {
		size_t index1 = random() % TILES_SIZE;
		size_t index2 = random() % TILES_SIZE;

		swap(m_tiles[index1], m_tiles[index2]);
	}
}


void SimpleWall::breaks(const Dice &dice1, const Dice &dice2)
{
	size_t sum;
	size_t index;

	// 開門位置を計算する。
	sum = dice1.getNumber() + dice2.getNumber();
	switch (sum % 4) {
	case 1: // 東家の前の山が開門地点である。
		index = 0 * 34 + sum * 2;
		break;

	case 2: // 南家の前の山が開門地点である。
		index = 3 * 34 + sum * 2;
		break;

	case 3: // 西家の前の山が開門地点である。
		index = 2 * 34 + sum * 2;
		break;

	case 0: // 北家の前の山が開門地点である。
		index = 1 * 34 + sum * 2;
		break;
	}

	// パラメータを初期化する。
	m_doras.clear();
	m_uraDoras.clear();
	m_breakingIndex = static_cast<uint8_t>(index);
	m_drawingIndex = 0;
	m_deadWallIndex = INITIAL_DEAD_WALL_INDEX;
#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	m_lastRevealedDoraIndex = TILES_SIZE;
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
}


const Tile &SimpleWall::draw()
{
	// アサーションが有効である場合のみ，状態をチェックする。
	openriichi_assert(m_drawingIndex < TILES_SIZE);

	return m_tiles[(m_drawingIndex++ + m_breakingIndex) % TILES_SIZE];
}


const Tile &SimpleWall::drawReplacementTile()
{
	// アサーションが有効である場合のみ，状態をチェックする。
	openriichi_assert(0 < m_deadWallIndex && m_deadWallIndex < TILES_SIZE);

	size_t replacementTileIndex;		// 嶺上牌の位置。

	// 嶺上牌の位置を計算する。
	if (m_deadWallIndex % 2 == 0) {
		replacementTileIndex = m_deadWallIndex + 12;
	} else {
		replacementTileIndex = m_deadWallIndex + 14;
	}

	// 王牌の先頭位置をずらす。
	--m_deadWallIndex;

	// 嶺上牌を返す。
	return m_tiles[(replacementTileIndex + m_breakingIndex) % TILES_SIZE];
}


void SimpleWall::revealNewDora()
{
	// アサーションが有効である場合のみ，状態をチェックする。
	openriichi_assert((3 + INITIAL_DEAD_WALL_INDEX - m_deadWallIndex) * 2 <= TILES_SIZE);

	// 現在のドラ表示牌の位置を計算する。
	uint8_t currentDoraIndicatorIndex = TILES_SIZE - (3 + INITIAL_DEAD_WALL_INDEX - m_deadWallIndex) * 2;

#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	// アサーションが有効である場合のみ，状態をチェック・更新する。
	openriichi_assert(currentDoraIndicatorIndex < m_lastRevealedDoraIndex);
	m_lastRevealedDoraIndex = currentDoraIndicatorIndex;
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0

	// ドラをめくる。
	m_doras.push_back(m_tiles[(currentDoraIndicatorIndex + m_breakingIndex) % TILES_SIZE].getNextTile());
	m_uraDoras.push_back(m_tiles[(currentDoraIndicatorIndex + 1 + m_breakingIndex) % TILES_SIZE].getNextTile());
}


size_t SimpleWall::countRemainingTiles()
{
	return m_deadWallIndex - m_drawingIndex;
}


const SimpleWall::Doras &SimpleWall::getDoras()
{
	return m_doras;
}


const SimpleWall::Doras &SimpleWall::getUraDoras()
{
	return m_uraDoras;
}


const Tile &SimpleWall::getTile(size_t index) const
{
	// アサーションが有効である場合のみ，引数をチェックする。
	openriichi_assert(index < TILES_SIZE);

	return m_tiles[index];
}


bool SimpleWall::isDrawed(size_t index) const
{
	// アサーションが有効である場合のみ，引数をチェックする。
	openriichi_assert(index < TILES_SIZE);

	uint8_t head = m_breakingIndex;
	uint8_t tail = (m_drawingIndex + m_breakingIndex) % TILES_SIZE;

	if (head < tail) {
		return (head <= index && index < tail);
	} else {
		return (head <= index && index < TILES_SIZE) || (0 <= index && index < tail);
	}
}
