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
		ASSERT_EQ(TileDesigns::CIRCLES, circles1.getDesign());
		ASSERT_EQ(TileAttributes::NONE, circles1.getAttribute());
		ASSERT_TRUE(circles1.isSuits());
		ASSERT_FALSE(circles1.isHonours());
		ASSERT_FALSE(circles1.isWinds());
		ASSERT_FALSE(circles1.isDragons());
		ASSERT_FALSE(circles1.isSimples());
		ASSERT_TRUE(circles1.isTerminals());
		ASSERT_TRUE(circles1.isTerminalsOrHonours());
		ASSERT_TRUE(circles1 == MemorySavedTile(TileDesigns::CIRCLES, 1));
		ASSERT_FALSE(circles1 == MemorySavedTile(TileDesigns::CIRCLES, 2));
		ASSERT_FALSE(circles1 == MemorySavedTile(TileDesigns::BAMBOO, 1));
		ASSERT_FALSE(circles1 == MemorySavedTile(TileDesigns::CHARACTERS, 1));
		ASSERT_FALSE(circles1 == MemorySavedTile(TileDesigns::EAST));
		ASSERT_FALSE(circles1 == MemorySavedTile(TileDesigns::RED));
		ASSERT_FALSE(circles1 != MemorySavedTile(TileDesigns::CIRCLES, 1));
		ASSERT_TRUE(circles1 != MemorySavedTile(TileDesigns::CIRCLES, 2));
		ASSERT_TRUE(circles1 != MemorySavedTile(TileDesigns::BAMBOO, 1));
		ASSERT_TRUE(circles1 != MemorySavedTile(TileDesigns::CHARACTERS, 1));
		ASSERT_TRUE(circles1 != MemorySavedTile(TileDesigns::EAST));
		ASSERT_TRUE(circles1 != MemorySavedTile(TileDesigns::RED));

		const MemorySavedTile circles2(TileDesigns::CIRCLES, 2);
		ASSERT_EQ(2, circles2.getNumber());
		ASSERT_EQ(TileDesigns::CIRCLES, circles2.getDesign());
		ASSERT_EQ(TileAttributes::NONE, circles2.getAttribute());
		ASSERT_TRUE(circles2.isSuits());
		ASSERT_FALSE(circles2.isHonours());
		ASSERT_FALSE(circles2.isWinds());
		ASSERT_FALSE(circles2.isDragons());
		ASSERT_TRUE(circles2.isSimples());
		ASSERT_FALSE(circles2.isTerminals());
		ASSERT_FALSE(circles2.isTerminalsOrHonours());

		const MemorySavedTile circles5(TileDesigns::CIRCLES, 5, TileAttributes::RED);
		ASSERT_EQ(5, circles5.getNumber());
		ASSERT_EQ(TileDesigns::CIRCLES, circles5.getDesign());
		ASSERT_EQ(TileAttributes::RED, circles5.getAttribute());
		ASSERT_TRUE(circles5.isSuits());
		ASSERT_FALSE(circles5.isHonours());
		ASSERT_FALSE(circles5.isWinds());
		ASSERT_FALSE(circles5.isDragons());
		ASSERT_TRUE(circles5.isSimples());
		ASSERT_FALSE(circles5.isTerminals());
		ASSERT_FALSE(circles5.isTerminalsOrHonours());

		const MemorySavedTile circles8(TileDesigns::CIRCLES, 8);
		ASSERT_EQ(8, circles8.getNumber());
		ASSERT_EQ(TileDesigns::CIRCLES, circles8.getDesign());
		ASSERT_EQ(TileAttributes::NONE, circles8.getAttribute());
		ASSERT_TRUE(circles8.isSuits());
		ASSERT_FALSE(circles8.isHonours());
		ASSERT_FALSE(circles8.isWinds());
		ASSERT_FALSE(circles8.isDragons());
		ASSERT_TRUE(circles8.isSimples());
		ASSERT_FALSE(circles8.isTerminals());
		ASSERT_FALSE(circles8.isTerminalsOrHonours());

		const MemorySavedTile circles9(TileDesigns::CIRCLES, 9);
		ASSERT_EQ(9, circles9.getNumber());
		ASSERT_EQ(TileDesigns::CIRCLES, circles9.getDesign());
		ASSERT_EQ(TileAttributes::NONE, circles9.getAttribute());
		ASSERT_TRUE(circles9.isSuits());
		ASSERT_FALSE(circles9.isHonours());
		ASSERT_FALSE(circles9.isWinds());
		ASSERT_FALSE(circles9.isDragons());
		ASSERT_FALSE(circles9.isSimples());
		ASSERT_TRUE(circles9.isTerminals());
		ASSERT_TRUE(circles9.isTerminalsOrHonours());
	}

	/// 索子牌をテストする。
	TEST_F(MemorySavedTileTest, testBambooTile)
	{
		const MemorySavedTile bamboo1(TileDesigns::BAMBOO, 1);
		ASSERT_EQ(1, bamboo1.getNumber());
		ASSERT_EQ(TileDesigns::BAMBOO, bamboo1.getDesign());
		ASSERT_EQ(TileAttributes::NONE, bamboo1.getAttribute());
		ASSERT_TRUE(bamboo1.isSuits());
		ASSERT_FALSE(bamboo1.isHonours());
		ASSERT_FALSE(bamboo1.isWinds());
		ASSERT_FALSE(bamboo1.isDragons());
		ASSERT_FALSE(bamboo1.isSimples());
		ASSERT_TRUE(bamboo1.isTerminals());
		ASSERT_TRUE(bamboo1.isTerminalsOrHonours());
		ASSERT_FALSE(bamboo1 == MemorySavedTile(TileDesigns::CIRCLES, 1));
		ASSERT_TRUE(bamboo1 == MemorySavedTile(TileDesigns::BAMBOO, 1));
		ASSERT_FALSE(bamboo1 == MemorySavedTile(TileDesigns::BAMBOO, 2));
		ASSERT_FALSE(bamboo1 == MemorySavedTile(TileDesigns::CHARACTERS, 1));
		ASSERT_FALSE(bamboo1 == MemorySavedTile(TileDesigns::EAST));
		ASSERT_FALSE(bamboo1 == MemorySavedTile(TileDesigns::RED));
		ASSERT_TRUE(bamboo1 != MemorySavedTile(TileDesigns::CIRCLES, 1));
		ASSERT_FALSE(bamboo1 != MemorySavedTile(TileDesigns::BAMBOO, 1));
		ASSERT_TRUE(bamboo1 != MemorySavedTile(TileDesigns::BAMBOO, 2));
		ASSERT_TRUE(bamboo1 != MemorySavedTile(TileDesigns::CHARACTERS, 1));
		ASSERT_TRUE(bamboo1 != MemorySavedTile(TileDesigns::EAST));
		ASSERT_TRUE(bamboo1 != MemorySavedTile(TileDesigns::RED));

		const MemorySavedTile bamboo2(TileDesigns::BAMBOO, 2);
		ASSERT_EQ(2, bamboo2.getNumber());
		ASSERT_EQ(TileDesigns::BAMBOO, bamboo2.getDesign());
		ASSERT_EQ(TileAttributes::NONE, bamboo2.getAttribute());
		ASSERT_TRUE(bamboo2.isSuits());
		ASSERT_FALSE(bamboo2.isHonours());
		ASSERT_FALSE(bamboo2.isWinds());
		ASSERT_FALSE(bamboo2.isDragons());
		ASSERT_TRUE(bamboo2.isSimples());
		ASSERT_FALSE(bamboo2.isTerminals());
		ASSERT_FALSE(bamboo2.isTerminalsOrHonours());

		const MemorySavedTile bamboo5(TileDesigns::BAMBOO, 5, TileAttributes::RED);
		ASSERT_EQ(5, bamboo5.getNumber());
		ASSERT_EQ(TileDesigns::BAMBOO, bamboo5.getDesign());
		ASSERT_EQ(TileAttributes::RED, bamboo5.getAttribute());
		ASSERT_TRUE(bamboo5.isSuits());
		ASSERT_FALSE(bamboo5.isHonours());
		ASSERT_FALSE(bamboo5.isWinds());
		ASSERT_FALSE(bamboo5.isDragons());
		ASSERT_TRUE(bamboo5.isSimples());
		ASSERT_FALSE(bamboo5.isTerminals());
		ASSERT_FALSE(bamboo5.isTerminalsOrHonours());

		const MemorySavedTile bamboo8(TileDesigns::BAMBOO, 8);
		ASSERT_EQ(8, bamboo8.getNumber());
		ASSERT_EQ(TileDesigns::BAMBOO, bamboo8.getDesign());
		ASSERT_EQ(TileAttributes::NONE, bamboo8.getAttribute());
		ASSERT_TRUE(bamboo8.isSuits());
		ASSERT_FALSE(bamboo8.isHonours());
		ASSERT_FALSE(bamboo8.isWinds());
		ASSERT_FALSE(bamboo8.isDragons());
		ASSERT_TRUE(bamboo8.isSimples());
		ASSERT_FALSE(bamboo8.isTerminals());
		ASSERT_FALSE(bamboo8.isTerminalsOrHonours());

		const MemorySavedTile bamboo9(TileDesigns::BAMBOO, 9);
		ASSERT_EQ(9, bamboo9.getNumber());
		ASSERT_EQ(TileDesigns::BAMBOO, bamboo9.getDesign());
		ASSERT_EQ(TileAttributes::NONE, bamboo9.getAttribute());
		ASSERT_TRUE(bamboo9.isSuits());
		ASSERT_FALSE(bamboo9.isHonours());
		ASSERT_FALSE(bamboo9.isWinds());
		ASSERT_FALSE(bamboo9.isDragons());
		ASSERT_FALSE(bamboo9.isSimples());
		ASSERT_TRUE(bamboo9.isTerminals());
		ASSERT_TRUE(bamboo9.isTerminalsOrHonours());
	}

	/// 萬子牌をテストする。
	TEST_F(MemorySavedTileTest, testCharactersTile)
	{
		const MemorySavedTile characters1(TileDesigns::CHARACTERS, 1);
		ASSERT_EQ(1, characters1.getNumber());
		ASSERT_EQ(TileDesigns::CHARACTERS, characters1.getDesign());
		ASSERT_EQ(TileAttributes::NONE, characters1.getAttribute());
		ASSERT_TRUE(characters1.isSuits());
		ASSERT_FALSE(characters1.isHonours());
		ASSERT_FALSE(characters1.isWinds());
		ASSERT_FALSE(characters1.isDragons());
		ASSERT_FALSE(characters1.isSimples());
		ASSERT_TRUE(characters1.isTerminals());
		ASSERT_TRUE(characters1.isTerminalsOrHonours());
		ASSERT_FALSE(characters1 == MemorySavedTile(TileDesigns::CIRCLES, 1));
		ASSERT_FALSE(characters1 == MemorySavedTile(TileDesigns::BAMBOO, 1));
		ASSERT_TRUE(characters1 == MemorySavedTile(TileDesigns::CHARACTERS, 1));
		ASSERT_FALSE(characters1 == MemorySavedTile(TileDesigns::CHARACTERS, 2));
		ASSERT_FALSE(characters1 == MemorySavedTile(TileDesigns::EAST));
		ASSERT_FALSE(characters1 == MemorySavedTile(TileDesigns::RED));
		ASSERT_TRUE(characters1 != MemorySavedTile(TileDesigns::CIRCLES, 1));
		ASSERT_TRUE(characters1 != MemorySavedTile(TileDesigns::BAMBOO, 1));
		ASSERT_FALSE(characters1 != MemorySavedTile(TileDesigns::CHARACTERS, 1));
		ASSERT_TRUE(characters1 != MemorySavedTile(TileDesigns::CHARACTERS, 2));
		ASSERT_TRUE(characters1 != MemorySavedTile(TileDesigns::EAST));
		ASSERT_TRUE(characters1 != MemorySavedTile(TileDesigns::RED));

		const MemorySavedTile characters2(TileDesigns::CHARACTERS, 2);
		ASSERT_EQ(2, characters2.getNumber());
		ASSERT_EQ(TileDesigns::CHARACTERS, characters2.getDesign());
		ASSERT_EQ(TileAttributes::NONE, characters2.getAttribute());
		ASSERT_TRUE(characters2.isSuits());
		ASSERT_FALSE(characters2.isHonours());
		ASSERT_FALSE(characters2.isWinds());
		ASSERT_FALSE(characters2.isDragons());
		ASSERT_TRUE(characters2.isSimples());
		ASSERT_FALSE(characters2.isTerminals());
		ASSERT_FALSE(characters2.isTerminalsOrHonours());

		const MemorySavedTile characters5(TileDesigns::CHARACTERS, 5, TileAttributes::RED);
		ASSERT_EQ(5, characters5.getNumber());
		ASSERT_EQ(TileDesigns::CHARACTERS, characters5.getDesign());
		ASSERT_EQ(TileAttributes::RED, characters5.getAttribute());
		ASSERT_TRUE(characters5.isSuits());
		ASSERT_FALSE(characters5.isHonours());
		ASSERT_FALSE(characters5.isWinds());
		ASSERT_FALSE(characters5.isDragons());
		ASSERT_TRUE(characters5.isSimples());
		ASSERT_FALSE(characters5.isTerminals());
		ASSERT_FALSE(characters5.isTerminalsOrHonours());

		const MemorySavedTile characters8(TileDesigns::CHARACTERS, 8);
		ASSERT_EQ(8, characters8.getNumber());
		ASSERT_EQ(TileDesigns::CHARACTERS, characters8.getDesign());
		ASSERT_EQ(TileAttributes::NONE, characters8.getAttribute());
		ASSERT_TRUE(characters8.isSuits());
		ASSERT_FALSE(characters8.isHonours());
		ASSERT_FALSE(characters8.isWinds());
		ASSERT_FALSE(characters8.isDragons());
		ASSERT_TRUE(characters8.isSimples());
		ASSERT_FALSE(characters8.isTerminals());
		ASSERT_FALSE(characters8.isTerminalsOrHonours());

		const MemorySavedTile characters9(TileDesigns::CHARACTERS, 9);
		ASSERT_EQ(9, characters9.getNumber());
		ASSERT_EQ(TileDesigns::CHARACTERS, characters9.getDesign());
		ASSERT_EQ(TileAttributes::NONE, characters9.getAttribute());
		ASSERT_TRUE(characters9.isSuits());
		ASSERT_FALSE(characters9.isHonours());
		ASSERT_FALSE(characters9.isWinds());
		ASSERT_FALSE(characters9.isDragons());
		ASSERT_FALSE(characters9.isSimples());
		ASSERT_TRUE(characters9.isTerminals());
		ASSERT_TRUE(characters9.isTerminalsOrHonours());
	}

	/// 風牌をテストする。
	TEST_F(MemorySavedTileTest, testWindsTile)
	{
		const MemorySavedTile east(TileDesigns::EAST);
		ASSERT_EQ(0, east.getNumber());
		ASSERT_EQ(TileDesigns::EAST, east.getDesign());
		ASSERT_EQ(TileAttributes::NONE, east.getAttribute());
		ASSERT_FALSE(east.isSuits());
		ASSERT_TRUE(east.isHonours());
		ASSERT_TRUE(east.isWinds());
		ASSERT_FALSE(east.isDragons());
		ASSERT_FALSE(east.isSimples());
		ASSERT_FALSE(east.isTerminals());
		ASSERT_TRUE(east.isTerminalsOrHonours());
		ASSERT_FALSE(east == MemorySavedTile(TileDesigns::CIRCLES, 1));
		ASSERT_FALSE(east == MemorySavedTile(TileDesigns::BAMBOO, 1));
		ASSERT_FALSE(east == MemorySavedTile(TileDesigns::CHARACTERS, 1));
		ASSERT_TRUE(east == MemorySavedTile(TileDesigns::EAST));
		ASSERT_FALSE(east == MemorySavedTile(TileDesigns::SOUTH));
		ASSERT_FALSE(east == MemorySavedTile(TileDesigns::RED));
		ASSERT_TRUE(east != MemorySavedTile(TileDesigns::CIRCLES, 1));
		ASSERT_TRUE(east != MemorySavedTile(TileDesigns::BAMBOO, 1));
		ASSERT_TRUE(east != MemorySavedTile(TileDesigns::CHARACTERS, 1));
		ASSERT_FALSE(east != MemorySavedTile(TileDesigns::EAST));
		ASSERT_TRUE(east != MemorySavedTile(TileDesigns::SOUTH));
		ASSERT_TRUE(east != MemorySavedTile(TileDesigns::RED));

		const MemorySavedTile south(TileDesigns::SOUTH);
		ASSERT_EQ(0, south.getNumber());
		ASSERT_EQ(TileDesigns::SOUTH, south.getDesign());
		ASSERT_EQ(TileAttributes::NONE, south.getAttribute());
		ASSERT_FALSE(south.isSuits());
		ASSERT_TRUE(south.isHonours());
		ASSERT_TRUE(south.isWinds());
		ASSERT_FALSE(south.isDragons());
		ASSERT_FALSE(south.isSimples());
		ASSERT_FALSE(south.isTerminals());
		ASSERT_TRUE(south.isTerminalsOrHonours());

		const MemorySavedTile west(TileDesigns::WEST);
		ASSERT_EQ(0, west.getNumber());
		ASSERT_EQ(TileDesigns::WEST, west.getDesign());
		ASSERT_EQ(TileAttributes::NONE, west.getAttribute());
		ASSERT_FALSE(west.isSuits());
		ASSERT_TRUE(west.isHonours());
		ASSERT_TRUE(west.isWinds());
		ASSERT_FALSE(west.isDragons());
		ASSERT_FALSE(west.isSimples());
		ASSERT_FALSE(west.isTerminals());
		ASSERT_TRUE(west.isTerminalsOrHonours());

		const MemorySavedTile north(TileDesigns::NORTH);
		ASSERT_EQ(0, north.getNumber());
		ASSERT_EQ(TileDesigns::NORTH, north.getDesign());
		ASSERT_EQ(TileAttributes::NONE, north.getAttribute());
		ASSERT_FALSE(north.isSuits());
		ASSERT_TRUE(north.isHonours());
		ASSERT_TRUE(north.isWinds());
		ASSERT_FALSE(north.isDragons());
		ASSERT_FALSE(north.isSimples());
		ASSERT_FALSE(north.isTerminals());
		ASSERT_TRUE(north.isTerminalsOrHonours());
	}

	/// 三元牌をテストする。
	TEST_F(MemorySavedTileTest, testDragonsTile)
	{
		const MemorySavedTile red(TileDesigns::RED);
		ASSERT_EQ(0, red.getNumber());
		ASSERT_EQ(TileDesigns::RED, red.getDesign());
		ASSERT_EQ(TileAttributes::NONE, red.getAttribute());
		ASSERT_FALSE(red.isSuits());
		ASSERT_TRUE(red.isHonours());
		ASSERT_FALSE(red.isWinds());
		ASSERT_TRUE(red.isDragons());
		ASSERT_FALSE(red.isSimples());
		ASSERT_FALSE(red.isTerminals());
		ASSERT_TRUE(red.isTerminalsOrHonours());
		ASSERT_FALSE(red == MemorySavedTile(TileDesigns::CIRCLES, 1));
		ASSERT_FALSE(red == MemorySavedTile(TileDesigns::BAMBOO, 1));
		ASSERT_FALSE(red == MemorySavedTile(TileDesigns::CHARACTERS, 1));
		ASSERT_FALSE(red == MemorySavedTile(TileDesigns::EAST));
		ASSERT_TRUE(red == MemorySavedTile(TileDesigns::RED));
		ASSERT_FALSE(red == MemorySavedTile(TileDesigns::WHITE));
		ASSERT_TRUE(red != MemorySavedTile(TileDesigns::CIRCLES, 1));
		ASSERT_TRUE(red != MemorySavedTile(TileDesigns::BAMBOO, 1));
		ASSERT_TRUE(red != MemorySavedTile(TileDesigns::CHARACTERS, 1));
		ASSERT_TRUE(red != MemorySavedTile(TileDesigns::EAST));
		ASSERT_FALSE(red != MemorySavedTile(TileDesigns::RED));
		ASSERT_TRUE(red != MemorySavedTile(TileDesigns::WHITE));

		const MemorySavedTile white(TileDesigns::WHITE);
		ASSERT_EQ(0, white.getNumber());
		ASSERT_EQ(TileDesigns::WHITE, white.getDesign());
		ASSERT_EQ(TileAttributes::NONE, white.getAttribute());
		ASSERT_FALSE(white.isSuits());
		ASSERT_TRUE(white.isHonours());
		ASSERT_FALSE(white.isWinds());
		ASSERT_TRUE(white.isDragons());
		ASSERT_FALSE(white.isSimples());
		ASSERT_FALSE(white.isTerminals());
		ASSERT_TRUE(white.isTerminalsOrHonours());

		const MemorySavedTile green(TileDesigns::GREEN);
		ASSERT_EQ(0, green.getNumber());
		ASSERT_EQ(TileDesigns::GREEN, green.getDesign());
		ASSERT_EQ(TileAttributes::NONE, green.getAttribute());
		ASSERT_FALSE(green.isSuits());
		ASSERT_TRUE(green.isHonours());
		ASSERT_FALSE(green.isWinds());
		ASSERT_TRUE(green.isDragons());
		ASSERT_FALSE(green.isSimples());
		ASSERT_FALSE(green.isTerminals());
		ASSERT_TRUE(green.isTerminalsOrHonours());
	}

	/// ID を用いた牌の生成をテストする。
	TEST_F(MemorySavedTileTest, testConstructorWithId)
	{
		ASSERT_EQ(MemorySavedTile(TileDesigns::CIRCLES, 1), MemorySavedTile(1, 1));
		ASSERT_EQ(MemorySavedTile(TileDesigns::BAMBOO, 5, TileAttributes::RED), MemorySavedTile(2, 5, 1));
		ASSERT_EQ(MemorySavedTile(TileDesigns::CHARACTERS, 9), MemorySavedTile(3, 9));
		ASSERT_EQ(MemorySavedTile(TileDesigns::EAST), MemorySavedTile(4, 0));
		ASSERT_EQ(MemorySavedTile(TileDesigns::SOUTH), MemorySavedTile(5, 0));
		ASSERT_EQ(MemorySavedTile(TileDesigns::WEST), MemorySavedTile(6, 0));
		ASSERT_EQ(MemorySavedTile(TileDesigns::NORTH), MemorySavedTile(7, 0));
		ASSERT_EQ(MemorySavedTile(TileDesigns::RED), MemorySavedTile(8, 0));
		ASSERT_EQ(MemorySavedTile(TileDesigns::WHITE), MemorySavedTile(9, 0));
		ASSERT_EQ(MemorySavedTile(TileDesigns::GREEN), MemorySavedTile(10, 0));
	}
}
