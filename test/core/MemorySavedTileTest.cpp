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
#include <MemorySavedTile.h>
#include <TileDesigns.h>
#include <TileAttributes.h>


namespace openriichi
{
	class MemorySavedTileTest : public ::testing::Test {};

	/// インスタンスのサイズをテストする。
	TEST_F(MemorySavedTileTest, testSizeOfInstance)
	{
		MemorySavedTile circles1(TileDesigns::CIRCLES, 1);
		ASSERT_EQ(1, sizeof(circles1));
	}

	/// 筒子牌をテストする。
	TEST_F(MemorySavedTileTest, testCirclesTile)
	{
		const MemorySavedTile circles1(TileDesigns::CIRCLES, 1);
		ASSERT_EQ(1, circles1.getNumber());
		ASSERT_EQ(TileDesigns::CIRCLES, *circles1.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *circles1.getAttribute());
		ASSERT_TRUE(circles1.isSuit());
		ASSERT_FALSE(circles1.isHonour());
		ASSERT_FALSE(circles1.isWind());
		ASSERT_FALSE(circles1.isDragon());
		ASSERT_FALSE(circles1.isSimple());
		ASSERT_TRUE(circles1.isTerminal());
		ASSERT_TRUE(circles1.isTerminalOrHonour());

		const MemorySavedTile circles2(TileDesigns::CIRCLES, 2);
		ASSERT_EQ(2, circles2.getNumber());
		ASSERT_EQ(TileDesigns::CIRCLES, *circles2.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *circles2.getAttribute());
		ASSERT_TRUE(circles2.isSuit());
		ASSERT_FALSE(circles2.isHonour());
		ASSERT_FALSE(circles2.isWind());
		ASSERT_FALSE(circles2.isDragon());
		ASSERT_TRUE(circles2.isSimple());
		ASSERT_FALSE(circles2.isTerminal());
		ASSERT_FALSE(circles2.isTerminalOrHonour());

		const MemorySavedTile circles5(TileDesigns::CIRCLES, 5, TileAttributes::RED);
		ASSERT_EQ(5, circles5.getNumber());
		ASSERT_EQ(TileDesigns::CIRCLES, *circles5.getDesign());
		ASSERT_EQ(TileAttributes::RED, *circles5.getAttribute());
		ASSERT_TRUE(circles5.isSuit());
		ASSERT_FALSE(circles5.isHonour());
		ASSERT_FALSE(circles5.isWind());
		ASSERT_FALSE(circles5.isDragon());
		ASSERT_TRUE(circles5.isSimple());
		ASSERT_FALSE(circles5.isTerminal());
		ASSERT_FALSE(circles5.isTerminalOrHonour());

		const MemorySavedTile circles8(TileDesigns::CIRCLES, 8);
		ASSERT_EQ(8, circles8.getNumber());
		ASSERT_EQ(TileDesigns::CIRCLES, *circles8.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *circles8.getAttribute());
		ASSERT_TRUE(circles8.isSuit());
		ASSERT_FALSE(circles8.isHonour());
		ASSERT_FALSE(circles8.isWind());
		ASSERT_FALSE(circles8.isDragon());
		ASSERT_TRUE(circles8.isSimple());
		ASSERT_FALSE(circles8.isTerminal());
		ASSERT_FALSE(circles8.isTerminalOrHonour());

		const MemorySavedTile circles9(TileDesigns::CIRCLES, 9);
		ASSERT_EQ(9, circles9.getNumber());
		ASSERT_EQ(TileDesigns::CIRCLES, *circles9.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *circles9.getAttribute());
		ASSERT_TRUE(circles9.isSuit());
		ASSERT_FALSE(circles9.isHonour());
		ASSERT_FALSE(circles9.isWind());
		ASSERT_FALSE(circles9.isDragon());
		ASSERT_FALSE(circles9.isSimple());
		ASSERT_TRUE(circles9.isTerminal());
		ASSERT_TRUE(circles9.isTerminalOrHonour());
	}

	/// 索子牌をテストする。
	TEST_F(MemorySavedTileTest, testBambooTile)
	{
		const MemorySavedTile bamboo1(TileDesigns::BAMBOO, 1);
		ASSERT_EQ(1, bamboo1.getNumber());
		ASSERT_EQ(TileDesigns::BAMBOO, *bamboo1.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *bamboo1.getAttribute());
		ASSERT_TRUE(bamboo1.isSuit());
		ASSERT_FALSE(bamboo1.isHonour());
		ASSERT_FALSE(bamboo1.isWind());
		ASSERT_FALSE(bamboo1.isDragon());
		ASSERT_FALSE(bamboo1.isSimple());
		ASSERT_TRUE(bamboo1.isTerminal());
		ASSERT_TRUE(bamboo1.isTerminalOrHonour());

		const MemorySavedTile bamboo2(TileDesigns::BAMBOO, 2);
		ASSERT_EQ(2, bamboo2.getNumber());
		ASSERT_EQ(TileDesigns::BAMBOO, *bamboo2.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *bamboo2.getAttribute());
		ASSERT_TRUE(bamboo2.isSuit());
		ASSERT_FALSE(bamboo2.isHonour());
		ASSERT_FALSE(bamboo2.isWind());
		ASSERT_FALSE(bamboo2.isDragon());
		ASSERT_TRUE(bamboo2.isSimple());
		ASSERT_FALSE(bamboo2.isTerminal());
		ASSERT_FALSE(bamboo2.isTerminalOrHonour());

		const MemorySavedTile bamboo5(TileDesigns::BAMBOO, 5, TileAttributes::RED);
		ASSERT_EQ(5, bamboo5.getNumber());
		ASSERT_EQ(TileDesigns::BAMBOO, *bamboo5.getDesign());
		ASSERT_EQ(TileAttributes::RED, *bamboo5.getAttribute());
		ASSERT_TRUE(bamboo5.isSuit());
		ASSERT_FALSE(bamboo5.isHonour());
		ASSERT_FALSE(bamboo5.isWind());
		ASSERT_FALSE(bamboo5.isDragon());
		ASSERT_TRUE(bamboo5.isSimple());
		ASSERT_FALSE(bamboo5.isTerminal());
		ASSERT_FALSE(bamboo5.isTerminalOrHonour());

		const MemorySavedTile bamboo8(TileDesigns::BAMBOO, 8);
		ASSERT_EQ(8, bamboo8.getNumber());
		ASSERT_EQ(TileDesigns::BAMBOO, *bamboo8.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *bamboo8.getAttribute());
		ASSERT_TRUE(bamboo8.isSuit());
		ASSERT_FALSE(bamboo8.isHonour());
		ASSERT_FALSE(bamboo8.isWind());
		ASSERT_FALSE(bamboo8.isDragon());
		ASSERT_TRUE(bamboo8.isSimple());
		ASSERT_FALSE(bamboo8.isTerminal());
		ASSERT_FALSE(bamboo8.isTerminalOrHonour());

		const MemorySavedTile bamboo9(TileDesigns::BAMBOO, 9);
		ASSERT_EQ(9, bamboo9.getNumber());
		ASSERT_EQ(TileDesigns::BAMBOO, *bamboo9.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *bamboo9.getAttribute());
		ASSERT_TRUE(bamboo9.isSuit());
		ASSERT_FALSE(bamboo9.isHonour());
		ASSERT_FALSE(bamboo9.isWind());
		ASSERT_FALSE(bamboo9.isDragon());
		ASSERT_FALSE(bamboo9.isSimple());
		ASSERT_TRUE(bamboo9.isTerminal());
		ASSERT_TRUE(bamboo9.isTerminalOrHonour());
	}

	/// 萬子牌をテストする。
	TEST_F(MemorySavedTileTest, testCharactersTile)
	{
		const MemorySavedTile characters1(TileDesigns::CHARACTERS, 1);
		ASSERT_EQ(1, characters1.getNumber());
		ASSERT_EQ(TileDesigns::CHARACTERS, *characters1.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *characters1.getAttribute());
		ASSERT_TRUE(characters1.isSuit());
		ASSERT_FALSE(characters1.isHonour());
		ASSERT_FALSE(characters1.isWind());
		ASSERT_FALSE(characters1.isDragon());
		ASSERT_FALSE(characters1.isSimple());
		ASSERT_TRUE(characters1.isTerminal());
		ASSERT_TRUE(characters1.isTerminalOrHonour());

		const MemorySavedTile characters2(TileDesigns::CHARACTERS, 2);
		ASSERT_EQ(2, characters2.getNumber());
		ASSERT_EQ(TileDesigns::CHARACTERS, *characters2.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *characters2.getAttribute());
		ASSERT_TRUE(characters2.isSuit());
		ASSERT_FALSE(characters2.isHonour());
		ASSERT_FALSE(characters2.isWind());
		ASSERT_FALSE(characters2.isDragon());
		ASSERT_TRUE(characters2.isSimple());
		ASSERT_FALSE(characters2.isTerminal());
		ASSERT_FALSE(characters2.isTerminalOrHonour());

		const MemorySavedTile characters5(TileDesigns::CHARACTERS, 5, TileAttributes::RED);
		ASSERT_EQ(5, characters5.getNumber());
		ASSERT_EQ(TileDesigns::CHARACTERS, *characters5.getDesign());
		ASSERT_EQ(TileAttributes::RED, *characters5.getAttribute());
		ASSERT_TRUE(characters5.isSuit());
		ASSERT_FALSE(characters5.isHonour());
		ASSERT_FALSE(characters5.isWind());
		ASSERT_FALSE(characters5.isDragon());
		ASSERT_TRUE(characters5.isSimple());
		ASSERT_FALSE(characters5.isTerminal());
		ASSERT_FALSE(characters5.isTerminalOrHonour());

		const MemorySavedTile characters8(TileDesigns::CHARACTERS, 8);
		ASSERT_EQ(8, characters8.getNumber());
		ASSERT_EQ(TileDesigns::CHARACTERS, *characters8.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *characters8.getAttribute());
		ASSERT_TRUE(characters8.isSuit());
		ASSERT_FALSE(characters8.isHonour());
		ASSERT_FALSE(characters8.isWind());
		ASSERT_FALSE(characters8.isDragon());
		ASSERT_TRUE(characters8.isSimple());
		ASSERT_FALSE(characters8.isTerminal());
		ASSERT_FALSE(characters8.isTerminalOrHonour());

		const MemorySavedTile characters9(TileDesigns::CHARACTERS, 9);
		ASSERT_EQ(9, characters9.getNumber());
		ASSERT_EQ(TileDesigns::CHARACTERS, *characters9.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *characters9.getAttribute());
		ASSERT_TRUE(characters9.isSuit());
		ASSERT_FALSE(characters9.isHonour());
		ASSERT_FALSE(characters9.isWind());
		ASSERT_FALSE(characters9.isDragon());
		ASSERT_FALSE(characters9.isSimple());
		ASSERT_TRUE(characters9.isTerminal());
		ASSERT_TRUE(characters9.isTerminalOrHonour());
	}

	/// 風牌をテストする。
	TEST_F(MemorySavedTileTest, testWindTile)
	{
		const MemorySavedTile east(TileDesigns::EAST);
		ASSERT_EQ(0, east.getNumber());
		ASSERT_EQ(TileDesigns::EAST, *east.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *east.getAttribute());
		ASSERT_FALSE(east.isSuit());
		ASSERT_TRUE(east.isHonour());
		ASSERT_TRUE(east.isWind());
		ASSERT_FALSE(east.isDragon());
		ASSERT_FALSE(east.isSimple());
		ASSERT_FALSE(east.isTerminal());
		ASSERT_TRUE(east.isTerminalOrHonour());

		const MemorySavedTile south(TileDesigns::SOUTH);
		ASSERT_EQ(0, south.getNumber());
		ASSERT_EQ(TileDesigns::SOUTH, *south.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *south.getAttribute());
		ASSERT_FALSE(south.isSuit());
		ASSERT_TRUE(south.isHonour());
		ASSERT_TRUE(south.isWind());
		ASSERT_FALSE(south.isDragon());
		ASSERT_FALSE(south.isSimple());
		ASSERT_FALSE(south.isTerminal());
		ASSERT_TRUE(south.isTerminalOrHonour());

		const MemorySavedTile west(TileDesigns::WEST);
		ASSERT_EQ(0, west.getNumber());
		ASSERT_EQ(TileDesigns::WEST, *west.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *west.getAttribute());
		ASSERT_FALSE(west.isSuit());
		ASSERT_TRUE(west.isHonour());
		ASSERT_TRUE(west.isWind());
		ASSERT_FALSE(west.isDragon());
		ASSERT_FALSE(west.isSimple());
		ASSERT_FALSE(west.isTerminal());
		ASSERT_TRUE(west.isTerminalOrHonour());

		const MemorySavedTile north(TileDesigns::NORTH);
		ASSERT_EQ(0, north.getNumber());
		ASSERT_EQ(TileDesigns::NORTH, *north.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *north.getAttribute());
		ASSERT_FALSE(north.isSuit());
		ASSERT_TRUE(north.isHonour());
		ASSERT_TRUE(north.isWind());
		ASSERT_FALSE(north.isDragon());
		ASSERT_FALSE(north.isSimple());
		ASSERT_FALSE(north.isTerminal());
		ASSERT_TRUE(north.isTerminalOrHonour());
	}

	/// 三元牌をテストする。
	TEST_F(MemorySavedTileTest, testDragonTile)
	{
		const MemorySavedTile red(TileDesigns::RED);
		ASSERT_EQ(0, red.getNumber());
		ASSERT_EQ(TileDesigns::RED, *red.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *red.getAttribute());
		ASSERT_FALSE(red.isSuit());
		ASSERT_TRUE(red.isHonour());
		ASSERT_FALSE(red.isWind());
		ASSERT_TRUE(red.isDragon());
		ASSERT_FALSE(red.isSimple());
		ASSERT_FALSE(red.isTerminal());
		ASSERT_TRUE(red.isTerminalOrHonour());

		const MemorySavedTile white(TileDesigns::WHITE);
		ASSERT_EQ(0, white.getNumber());
		ASSERT_EQ(TileDesigns::WHITE, *white.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *white.getAttribute());
		ASSERT_FALSE(white.isSuit());
		ASSERT_TRUE(white.isHonour());
		ASSERT_FALSE(white.isWind());
		ASSERT_TRUE(white.isDragon());
		ASSERT_FALSE(white.isSimple());
		ASSERT_FALSE(white.isTerminal());
		ASSERT_TRUE(white.isTerminalOrHonour());

		const MemorySavedTile green(TileDesigns::GREEN);
		ASSERT_EQ(0, green.getNumber());
		ASSERT_EQ(TileDesigns::GREEN, *green.getDesign());
		ASSERT_EQ(TileAttributes::NONE, *green.getAttribute());
		ASSERT_FALSE(green.isSuit());
		ASSERT_TRUE(green.isHonour());
		ASSERT_FALSE(green.isWind());
		ASSERT_TRUE(green.isDragon());
		ASSERT_FALSE(green.isSimple());
		ASSERT_FALSE(green.isTerminal());
		ASSERT_TRUE(green.isTerminalOrHonour());
	}
}
