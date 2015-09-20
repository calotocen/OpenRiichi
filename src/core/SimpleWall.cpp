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
#include "OpenRiichiConfiguration.h"
#include "OpenRiichiAssertion.h"
#include "Tile.h"
#include "Tiles.h"
#include "SimpleWall.h"


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
	, m_index(0)
	, m_deadWallIndex(INITIAL_DEAD_WALL_INDEX)
#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	, m_lastRevealedDoraIndex(TILES_SIZE)
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
{
	// 何もしない。
}


bool openriichi::SimpleWall::operator==(const SimpleWall & other) const
{
	if (this == &other) {
		return true;
	}

	return m_tiles == other.m_tiles
		&& m_doras == other.m_doras
		&& m_uraDoras == other.m_uraDoras
		&& m_index == other.m_index
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


void SimpleWall::breaks(int index)
{
	// アサーションが有効である場合のみ，引数をチェックする。
	openriichi_assert(0 <= index && index < TILES_SIZE);

	Tiles tiles;		// 牌。

	// 処理を簡易にするため，区切り位置が配列の先頭となるように牌を並び替える。
	for (auto it = m_tiles.begin() + index; it != m_tiles.end(); ++it) {
		tiles.push_back(*it);
	}
	for (auto it = m_tiles.begin(); it != m_tiles.begin() + index; ++it) {
		tiles.push_back(*it);
	}

	// パラメータを初期化する。
	m_tiles = tiles;
	m_doras.clear();
	m_uraDoras.clear();
	m_index = 0;
	m_deadWallIndex = INITIAL_DEAD_WALL_INDEX;
#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	m_lastRevealedDoraIndex = TILES_SIZE;
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
}


const Tile &SimpleWall::draw()
{
	// アサーションが有効である場合のみ，状態をチェックする。
	openriichi_assert(m_index < TILES_SIZE);

	return m_tiles[m_index++];
}


const Tile &SimpleWall::drawReplacementTile()
{
	// アサーションが有効である場合のみ，状態をチェックする。
	openriichi_assert(0 < m_deadWallIndex);

	int replacementTileIndex;		// 嶺上牌の位置。

	// 嶺上牌の位置を計算する。
	if (m_deadWallIndex % 2 == 0) {
		replacementTileIndex = m_deadWallIndex + 12;
	} else {
		replacementTileIndex = m_deadWallIndex + 14;
	}

	// 王牌の先頭位置をずらす。
	--m_deadWallIndex;

	// 嶺上牌を返す。
	return m_tiles[replacementTileIndex];
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
	m_doras.push_back(m_tiles[currentDoraIndicatorIndex].getNextTile());
	m_uraDoras.push_back(m_tiles[currentDoraIndicatorIndex + 1].getNextTile());
}


size_t SimpleWall::countRemainingTiles()
{
	return m_deadWallIndex - m_index;
}


const SimpleWall::Doras &SimpleWall::getDoras()
{
	return m_doras;
}


const SimpleWall::Doras &SimpleWall::getUraDoras()
{
	return m_uraDoras;
}
