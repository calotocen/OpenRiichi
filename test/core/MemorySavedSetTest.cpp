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
#include <gtest/gtest.h>
#include <MeldedKongTypes.h>
#include <MeldTypes.h>
#include <MemorySavedSet.h>
#include <SetArrangements.h>
#include <Tile.h>


namespace openriichi
{
	class MemorySavedSetTest : public ::testing::Test {};

	/// インスタンスのサイズをテストする。
	TEST_F(MemorySavedSetTest, testSizeOfInstance)
	{
		MemorySavedSet chow(SetArrangements::CHOW, Tile(TileDesigns::CIRCLES, 1));
		ASSERT_EQ(2, sizeof(chow));
	}

	/// 順子をテストする。
	TEST_F(MemorySavedSetTest, testChow)
	{
		MemorySavedSet concealedChow(SetArrangements::CHOW, Tile(TileDesigns::CIRCLES, 1));
		ASSERT_EQ(SetArrangements::CHOW, *concealedChow.getArrangement());
		ASSERT_EQ(MeldTypes::NONE, *concealedChow.getMeldType());
		ASSERT_EQ(MeldedKongTypes::NO, *concealedChow.getMeldedKongType());
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 1), *concealedChow.getKeyTile());
		ASSERT_TRUE(concealedChow.isChow());
		ASSERT_FALSE(concealedChow.isPair());
		ASSERT_FALSE(concealedChow.isPung());
		ASSERT_FALSE(concealedChow.isKong());
		ASSERT_TRUE(concealedChow.isConcealed());
		ASSERT_FALSE(concealedChow.isMelded());
		ASSERT_TRUE(concealedChow == MemorySavedSet(SetArrangements::CHOW, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_FALSE(concealedChow == MemorySavedSet(SetArrangements::PAIR, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_FALSE(concealedChow == MemorySavedSet(SetArrangements::CHOW, MeldTypes::LEFT, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_FALSE(concealedChow == MemorySavedSet(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)));
		ASSERT_FALSE(concealedChow != MemorySavedSet(SetArrangements::CHOW, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_TRUE(concealedChow != MemorySavedSet(SetArrangements::PAIR, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_TRUE(concealedChow != MemorySavedSet(SetArrangements::CHOW, MeldTypes::LEFT, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_TRUE(concealedChow != MemorySavedSet(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)));

		MemorySavedSet meldedChow(SetArrangements::CHOW, MeldTypes::LEFT, Tile(TileDesigns::BAMBOO, 7));
		ASSERT_EQ(SetArrangements::CHOW, *meldedChow.getArrangement());
		ASSERT_EQ(MeldTypes::LEFT, *meldedChow.getMeldType());
		ASSERT_EQ(MeldedKongTypes::NO, *meldedChow.getMeldedKongType());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 7), *meldedChow.getKeyTile());
		ASSERT_TRUE(meldedChow.isChow());
		ASSERT_FALSE(meldedChow.isPair());
		ASSERT_FALSE(meldedChow.isPung());
		ASSERT_FALSE(meldedChow.isKong());
		ASSERT_FALSE(meldedChow.isConcealed());
		ASSERT_TRUE(meldedChow.isMelded());
	}

	/// 対子をテストする。
	TEST_F(MemorySavedSetTest, testPair)
	{
		MemorySavedSet concealedPair(SetArrangements::PAIR, Tile(TileDesigns::CIRCLES, 1));
		ASSERT_EQ(SetArrangements::PAIR, *concealedPair.getArrangement());
		ASSERT_EQ(MeldTypes::NONE, *concealedPair.getMeldType());
		ASSERT_EQ(MeldedKongTypes::NO, *concealedPair.getMeldedKongType());
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 1), *concealedPair.getKeyTile());
		ASSERT_FALSE(concealedPair.isChow());
		ASSERT_TRUE(concealedPair.isPair());
		ASSERT_FALSE(concealedPair.isPung());
		ASSERT_FALSE(concealedPair.isKong());
		ASSERT_TRUE(concealedPair.isConcealed());
		ASSERT_FALSE(concealedPair.isMelded());
		ASSERT_TRUE(concealedPair == MemorySavedSet(SetArrangements::PAIR, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_FALSE(concealedPair == MemorySavedSet(SetArrangements::PUNG, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_FALSE(concealedPair == MemorySavedSet(SetArrangements::PAIR, MeldTypes::LEFT, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_FALSE(concealedPair == MemorySavedSet(SetArrangements::PAIR, Tile(TileDesigns::BAMBOO, 1)));
		ASSERT_FALSE(concealedPair != MemorySavedSet(SetArrangements::PAIR, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_TRUE(concealedPair != MemorySavedSet(SetArrangements::PUNG, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_TRUE(concealedPair != MemorySavedSet(SetArrangements::PAIR, MeldTypes::LEFT, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_TRUE(concealedPair != MemorySavedSet(SetArrangements::PAIR, Tile(TileDesigns::BAMBOO, 1)));
	}

	/// 刻子をテストする。
	TEST_F(MemorySavedSetTest, testPung)
	{
		MemorySavedSet concealedPung(SetArrangements::PUNG, Tile(TileDesigns::CIRCLES, 1));
		ASSERT_EQ(SetArrangements::PUNG, *concealedPung.getArrangement());
		ASSERT_EQ(MeldTypes::NONE, *concealedPung.getMeldType());
		ASSERT_EQ(MeldedKongTypes::NO, *concealedPung.getMeldedKongType());
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 1), *concealedPung.getKeyTile());
		ASSERT_FALSE(concealedPung.isChow());
		ASSERT_FALSE(concealedPung.isPair());
		ASSERT_TRUE(concealedPung.isPung());
		ASSERT_FALSE(concealedPung.isKong());
		ASSERT_TRUE(concealedPung.isConcealed());
		ASSERT_FALSE(concealedPung.isMelded());
		ASSERT_TRUE(concealedPung == MemorySavedSet(SetArrangements::PUNG, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_FALSE(concealedPung == MemorySavedSet(SetArrangements::KONG, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_FALSE(concealedPung == MemorySavedSet(SetArrangements::PUNG, MeldTypes::LEFT, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_FALSE(concealedPung == MemorySavedSet(SetArrangements::PUNG, Tile(TileDesigns::BAMBOO, 1)));
		ASSERT_FALSE(concealedPung != MemorySavedSet(SetArrangements::PUNG, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_TRUE(concealedPung != MemorySavedSet(SetArrangements::KONG, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_TRUE(concealedPung != MemorySavedSet(SetArrangements::PUNG, MeldTypes::LEFT, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_TRUE(concealedPung != MemorySavedSet(SetArrangements::PUNG, Tile(TileDesigns::BAMBOO, 1)));

		MemorySavedSet meldedPung(SetArrangements::PUNG, MeldTypes::LEFT, Tile(TileDesigns::BAMBOO, 9							));
		ASSERT_EQ(SetArrangements::PUNG, *meldedPung.getArrangement());
		ASSERT_EQ(MeldTypes::LEFT, *meldedPung.getMeldType());
		ASSERT_EQ(MeldedKongTypes::NO, *meldedPung.getMeldedKongType());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), *meldedPung.getKeyTile());
		ASSERT_FALSE(meldedPung.isChow());
		ASSERT_FALSE(meldedPung.isPair());
		ASSERT_TRUE(meldedPung.isPung());
		ASSERT_FALSE(meldedPung.isKong());
		ASSERT_FALSE(meldedPung.isConcealed());
		ASSERT_TRUE(meldedPung.isMelded());
	}

	/// 槓子をテストする。
	TEST_F(MemorySavedSetTest, testKong)
	{
		MemorySavedSet concealedKong(SetArrangements::KONG, Tile(TileDesigns::CIRCLES, 1));
		ASSERT_EQ(SetArrangements::KONG, *concealedKong.getArrangement());
		ASSERT_EQ(MeldTypes::NONE, *concealedKong.getMeldType());
		ASSERT_EQ(MeldedKongTypes::NO, *concealedKong.getMeldedKongType());
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 1), *concealedKong.getKeyTile());
		ASSERT_FALSE(concealedKong.isChow());
		ASSERT_FALSE(concealedKong.isPair());
		ASSERT_FALSE(concealedKong.isPung());
		ASSERT_TRUE(concealedKong.isKong());
		ASSERT_TRUE(concealedKong.isConcealed());
		ASSERT_FALSE(concealedKong.isMelded());
		ASSERT_TRUE(concealedKong == MemorySavedSet(SetArrangements::KONG, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_FALSE(concealedKong == MemorySavedSet(SetArrangements::CHOW, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_FALSE(concealedKong == MemorySavedSet(SetArrangements::KONG, MeldTypes::LEFT, MeldedKongTypes::LITTLE, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_FALSE(concealedKong == MemorySavedSet(SetArrangements::KONG, Tile(TileDesigns::BAMBOO, 1)));
		ASSERT_FALSE(concealedKong != MemorySavedSet(SetArrangements::KONG, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_TRUE(concealedKong != MemorySavedSet(SetArrangements::CHOW, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_TRUE(concealedKong != MemorySavedSet(SetArrangements::KONG, MeldTypes::LEFT, MeldedKongTypes::LITTLE, Tile(TileDesigns::CIRCLES, 1)));
		ASSERT_TRUE(concealedKong != MemorySavedSet(SetArrangements::KONG, Tile(TileDesigns::BAMBOO, 1)));

		MemorySavedSet littleMeldedKong(SetArrangements::KONG, MeldTypes::CENTER, MeldedKongTypes::LITTLE, Tile(TileDesigns::BAMBOO, 5));
		ASSERT_EQ(SetArrangements::KONG, *littleMeldedKong.getArrangement());
		ASSERT_EQ(MeldTypes::CENTER, *littleMeldedKong.getMeldType());
		ASSERT_EQ(MeldedKongTypes::LITTLE, *littleMeldedKong.getMeldedKongType());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 5), *littleMeldedKong.getKeyTile());
		ASSERT_FALSE(littleMeldedKong.isChow());
		ASSERT_FALSE(littleMeldedKong.isPair());
		ASSERT_FALSE(littleMeldedKong.isPung());
		ASSERT_TRUE(littleMeldedKong.isKong());
		ASSERT_FALSE(littleMeldedKong.isConcealed());
		ASSERT_TRUE(littleMeldedKong.isMelded());

		MemorySavedSet bigMeldedKong(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::BIG, Tile(TileDesigns::CHARACTERS, 9));
		ASSERT_EQ(SetArrangements::KONG, *bigMeldedKong.getArrangement());
		ASSERT_EQ(MeldTypes::RIGHT, *bigMeldedKong.getMeldType());
		ASSERT_EQ(MeldedKongTypes::BIG, *bigMeldedKong.getMeldedKongType());
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 9), *bigMeldedKong.getKeyTile());
		ASSERT_FALSE(bigMeldedKong.isChow());
		ASSERT_FALSE(bigMeldedKong.isPair());
		ASSERT_FALSE(bigMeldedKong.isPung());
		ASSERT_TRUE(bigMeldedKong.isKong());
		ASSERT_FALSE(bigMeldedKong.isConcealed());
		ASSERT_TRUE(bigMeldedKong.isMelded());
	}
}
