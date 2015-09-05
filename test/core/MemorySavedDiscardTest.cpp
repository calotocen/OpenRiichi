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
#include <DiscardSources.h>
#include <MemorySavedDiscard.h>
#include <Tile.h>


namespace openriichi
{
	class MemorySavedDiscardTest : public ::testing::Test {};

	/// インスタンスのサイズをテストする。
	TEST_F(MemorySavedDiscardTest, testSizeOfInstance)
	{
		MemorySavedDiscard discard(Tile(), DiscardSources::DRAWED);
		ASSERT_EQ(2, sizeof(discard));
	}

	/// 捨て牌をテストする。
	TEST_F(MemorySavedDiscardTest, testDiscard)
	{
		MemorySavedDiscard discard1(Tile(), DiscardSources::DRAWED);
		ASSERT_EQ(Tile(), *discard1.getTile());
		ASSERT_EQ(DiscardSources::DRAWED, *discard1.getSource());
		ASSERT_EQ(false, discard1.isRiichiDeclared());
		ASSERT_EQ(false, discard1.isTaken());

		MemorySavedDiscard discard2(Tile(TileDesigns::BAMBOO, 3), DiscardSources::HELD, false, false);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *discard2.getTile());
		ASSERT_EQ(DiscardSources::HELD, *discard2.getSource());
		ASSERT_EQ(false, discard2.isRiichiDeclared());
		ASSERT_EQ(false, discard2.isTaken());

		MemorySavedDiscard discard3(Tile(TileDesigns::CHARACTERS, 7), DiscardSources::DRAWED, false, true);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 7), *discard3.getTile());
		ASSERT_EQ(DiscardSources::DRAWED, *discard3.getSource());
		ASSERT_EQ(false, discard3.isRiichiDeclared());
		ASSERT_EQ(true, discard3.isTaken());

		MemorySavedDiscard discard4(Tile(TileDesigns::EAST), DiscardSources::HELD, true, false);
		ASSERT_EQ(Tile(TileDesigns::EAST), *discard4.getTile());
		ASSERT_EQ(DiscardSources::HELD, *discard4.getSource());
		ASSERT_EQ(true, discard4.isRiichiDeclared());
		ASSERT_EQ(false, discard4.isTaken());

		MemorySavedDiscard discard5(Tile(TileDesigns::RED), DiscardSources::DRAWED, true, true);
		ASSERT_EQ(Tile(TileDesigns::RED), *discard5.getTile());
		ASSERT_EQ(DiscardSources::DRAWED, *discard5.getSource());
		ASSERT_EQ(true, discard5.isRiichiDeclared());
		ASSERT_EQ(true, discard5.isTaken());
	}
}
