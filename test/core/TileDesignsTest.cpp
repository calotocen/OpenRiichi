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
#include <TileDesigns.h>


namespace openriichi
{
	class TileDesignsTest : public ::testing::Test {};

	/// 筒子の牌図柄をテストする。
	TEST_F(TileDesignsTest, testCircles)
	{
		const TileDesign &tileDesign = TileDesigns::CIRCLES;
		ASSERT_EQ(1, tileDesign.getId());
		ASSERT_TRUE(tileDesign.isSuit());
		ASSERT_FALSE(tileDesign.isHonour());
		ASSERT_FALSE(tileDesign.isWind());
		ASSERT_FALSE(tileDesign.isDragon());

		ASSERT_TRUE(CirclesTileDesign() == tileDesign);
		ASSERT_FALSE(BambooTileDesign() == tileDesign);
		ASSERT_FALSE(CharactersTileDesign() == tileDesign);
		ASSERT_FALSE(EastTileDesign() == tileDesign);
		ASSERT_FALSE(SouthTileDesign() == tileDesign);
		ASSERT_FALSE(WestTileDesign() == tileDesign);
		ASSERT_FALSE(NorthTileDesign() == tileDesign);
		ASSERT_FALSE(RedTileDesign() == tileDesign);
		ASSERT_FALSE(WhiteTileDesign() == tileDesign);
		ASSERT_FALSE(GreenTileDesign() == tileDesign);
	}

	/// 索子の牌図柄をテストする。
	TEST_F(TileDesignsTest, testBamboo)
	{
		const TileDesign &tileDesign = TileDesigns::BAMBOO;
		ASSERT_EQ(2, tileDesign.getId());
		ASSERT_TRUE(tileDesign.isSuit());
		ASSERT_FALSE(tileDesign.isHonour());
		ASSERT_FALSE(tileDesign.isWind());
		ASSERT_FALSE(tileDesign.isDragon());

		ASSERT_FALSE(CirclesTileDesign() == tileDesign);
		ASSERT_TRUE(BambooTileDesign() == tileDesign);
		ASSERT_FALSE(CharactersTileDesign() == tileDesign);
		ASSERT_FALSE(EastTileDesign() == tileDesign);
		ASSERT_FALSE(SouthTileDesign() == tileDesign);
		ASSERT_FALSE(WestTileDesign() == tileDesign);
		ASSERT_FALSE(NorthTileDesign() == tileDesign);
		ASSERT_FALSE(RedTileDesign() == tileDesign);
		ASSERT_FALSE(WhiteTileDesign() == tileDesign);
		ASSERT_FALSE(GreenTileDesign() == tileDesign);
	}

	/// 萬子の牌図柄をテストする。
	TEST_F(TileDesignsTest, testCharacters)
	{
		const TileDesign &tileDesign = TileDesigns::CHARACTERS;
		ASSERT_EQ(3, tileDesign.getId());
		ASSERT_TRUE(tileDesign.isSuit());
		ASSERT_FALSE(tileDesign.isHonour());
		ASSERT_FALSE(tileDesign.isWind());
		ASSERT_FALSE(tileDesign.isDragon());

		ASSERT_FALSE(CirclesTileDesign() == tileDesign);
		ASSERT_FALSE(BambooTileDesign() == tileDesign);
		ASSERT_TRUE(CharactersTileDesign() == tileDesign);
		ASSERT_FALSE(EastTileDesign() == tileDesign);
		ASSERT_FALSE(SouthTileDesign() == tileDesign);
		ASSERT_FALSE(WestTileDesign() == tileDesign);
		ASSERT_FALSE(NorthTileDesign() == tileDesign);
		ASSERT_FALSE(RedTileDesign() == tileDesign);
		ASSERT_FALSE(WhiteTileDesign() == tileDesign);
		ASSERT_FALSE(GreenTileDesign() == tileDesign);
	}

	/// 東の牌図柄をテストする。
	TEST_F(TileDesignsTest, testEast)
	{
		const TileDesign &tileDesign = TileDesigns::EAST;
		ASSERT_EQ(4, tileDesign.getId());
		ASSERT_FALSE(tileDesign.isSuit());
		ASSERT_TRUE(tileDesign.isHonour());
		ASSERT_TRUE(tileDesign.isWind());
		ASSERT_FALSE(tileDesign.isDragon());

		ASSERT_FALSE(CirclesTileDesign() == tileDesign);
		ASSERT_FALSE(BambooTileDesign() == tileDesign);
		ASSERT_FALSE(CharactersTileDesign() == tileDesign);
		ASSERT_TRUE(EastTileDesign() == tileDesign);
		ASSERT_FALSE(SouthTileDesign() == tileDesign);
		ASSERT_FALSE(WestTileDesign() == tileDesign);
		ASSERT_FALSE(NorthTileDesign() == tileDesign);
		ASSERT_FALSE(RedTileDesign() == tileDesign);
		ASSERT_FALSE(WhiteTileDesign() == tileDesign);
		ASSERT_FALSE(GreenTileDesign() == tileDesign);
	}

	/// 南の牌図柄をテストする。
	TEST_F(TileDesignsTest, testSouth)
	{
		const TileDesign &tileDesign = TileDesigns::SOUTH;
		ASSERT_EQ(5, tileDesign.getId());
		ASSERT_FALSE(tileDesign.isSuit());
		ASSERT_TRUE(tileDesign.isHonour());
		ASSERT_TRUE(tileDesign.isWind());
		ASSERT_FALSE(tileDesign.isDragon());

		ASSERT_FALSE(CirclesTileDesign() == tileDesign);
		ASSERT_FALSE(BambooTileDesign() == tileDesign);
		ASSERT_FALSE(CharactersTileDesign() == tileDesign);
		ASSERT_FALSE(EastTileDesign() == tileDesign);
		ASSERT_TRUE(SouthTileDesign() == tileDesign);
		ASSERT_FALSE(WestTileDesign() == tileDesign);
		ASSERT_FALSE(NorthTileDesign() == tileDesign);
		ASSERT_FALSE(RedTileDesign() == tileDesign);
		ASSERT_FALSE(WhiteTileDesign() == tileDesign);
		ASSERT_FALSE(GreenTileDesign() == tileDesign);
	}

	/// 西の牌図柄をテストする。
	TEST_F(TileDesignsTest, testWest)
	{
		const TileDesign &tileDesign = TileDesigns::WEST;
		ASSERT_EQ(6, tileDesign.getId());
		ASSERT_FALSE(tileDesign.isSuit());
		ASSERT_TRUE(tileDesign.isHonour());
		ASSERT_TRUE(tileDesign.isWind());
		ASSERT_FALSE(tileDesign.isDragon());

		ASSERT_FALSE(CirclesTileDesign() == tileDesign);
		ASSERT_FALSE(BambooTileDesign() == tileDesign);
		ASSERT_FALSE(CharactersTileDesign() == tileDesign);
		ASSERT_FALSE(EastTileDesign() == tileDesign);
		ASSERT_FALSE(SouthTileDesign() == tileDesign);
		ASSERT_TRUE(WestTileDesign() == tileDesign);
		ASSERT_FALSE(NorthTileDesign() == tileDesign);
		ASSERT_FALSE(RedTileDesign() == tileDesign);
		ASSERT_FALSE(WhiteTileDesign() == tileDesign);
		ASSERT_FALSE(GreenTileDesign() == tileDesign);
	}

	/// 北の牌図柄をテストする。
	TEST_F(TileDesignsTest, testNorth)
	{
		const TileDesign &tileDesign = TileDesigns::NORTH;
		ASSERT_EQ(7, tileDesign.getId());
		ASSERT_FALSE(tileDesign.isSuit());
		ASSERT_TRUE(tileDesign.isHonour());
		ASSERT_TRUE(tileDesign.isWind());
		ASSERT_FALSE(tileDesign.isDragon());

		ASSERT_FALSE(CirclesTileDesign() == tileDesign);
		ASSERT_FALSE(BambooTileDesign() == tileDesign);
		ASSERT_FALSE(CharactersTileDesign() == tileDesign);
		ASSERT_FALSE(EastTileDesign() == tileDesign);
		ASSERT_FALSE(SouthTileDesign() == tileDesign);
		ASSERT_FALSE(WestTileDesign() == tileDesign);
		ASSERT_TRUE(NorthTileDesign() == tileDesign);
		ASSERT_FALSE(RedTileDesign() == tileDesign);
		ASSERT_FALSE(WhiteTileDesign() == tileDesign);
		ASSERT_FALSE(GreenTileDesign() == tileDesign);
	}

	/// 中の牌図柄をテストする。
	TEST_F(TileDesignsTest, testRed)
	{
		const TileDesign &tileDesign = TileDesigns::RED;
		ASSERT_EQ(8, tileDesign.getId());
		ASSERT_FALSE(tileDesign.isSuit());
		ASSERT_TRUE(tileDesign.isHonour());
		ASSERT_FALSE(tileDesign.isWind());
		ASSERT_TRUE(tileDesign.isDragon());

		ASSERT_FALSE(CirclesTileDesign() == tileDesign);
		ASSERT_FALSE(BambooTileDesign() == tileDesign);
		ASSERT_FALSE(CharactersTileDesign() == tileDesign);
		ASSERT_FALSE(EastTileDesign() == tileDesign);
		ASSERT_FALSE(SouthTileDesign() == tileDesign);
		ASSERT_FALSE(WestTileDesign() == tileDesign);
		ASSERT_FALSE(NorthTileDesign() == tileDesign);
		ASSERT_TRUE(RedTileDesign() == tileDesign);
		ASSERT_FALSE(WhiteTileDesign() == tileDesign);
		ASSERT_FALSE(GreenTileDesign() == tileDesign);
	}

	/// 白の牌図柄をテストする。
	TEST_F(TileDesignsTest, testWhite)
	{
		const TileDesign &tileDesign = TileDesigns::WHITE;
		ASSERT_EQ(9, tileDesign.getId());
		ASSERT_FALSE(tileDesign.isSuit());
		ASSERT_TRUE(tileDesign.isHonour());
		ASSERT_FALSE(tileDesign.isWind());
		ASSERT_TRUE(tileDesign.isDragon());

		ASSERT_FALSE(CirclesTileDesign() == tileDesign);
		ASSERT_FALSE(BambooTileDesign() == tileDesign);
		ASSERT_FALSE(CharactersTileDesign() == tileDesign);
		ASSERT_FALSE(EastTileDesign() == tileDesign);
		ASSERT_FALSE(SouthTileDesign() == tileDesign);
		ASSERT_FALSE(WestTileDesign() == tileDesign);
		ASSERT_FALSE(NorthTileDesign() == tileDesign);
		ASSERT_FALSE(RedTileDesign() == tileDesign);
		ASSERT_TRUE(WhiteTileDesign() == tileDesign);
		ASSERT_FALSE(GreenTileDesign() == tileDesign);
	}

	/// 發の牌図柄をテストする。
	TEST_F(TileDesignsTest, testGreen)
	{
		const TileDesign &tileDesign = TileDesigns::GREEN;
		ASSERT_EQ(10, tileDesign.getId());
		ASSERT_FALSE(tileDesign.isSuit());
		ASSERT_TRUE(tileDesign.isHonour());
		ASSERT_FALSE(tileDesign.isWind());
		ASSERT_TRUE(tileDesign.isDragon());

		ASSERT_FALSE(CirclesTileDesign() == tileDesign);
		ASSERT_FALSE(BambooTileDesign() == tileDesign);
		ASSERT_FALSE(CharactersTileDesign() == tileDesign);
		ASSERT_FALSE(EastTileDesign() == tileDesign);
		ASSERT_FALSE(SouthTileDesign() == tileDesign);
		ASSERT_FALSE(WestTileDesign() == tileDesign);
		ASSERT_FALSE(NorthTileDesign() == tileDesign);
		ASSERT_FALSE(RedTileDesign() == tileDesign);
		ASSERT_FALSE(WhiteTileDesign() == tileDesign);
		ASSERT_TRUE(GreenTileDesign() == tileDesign);
	}
}
