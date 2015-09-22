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
#include <OpenRiichi.h>


namespace openriichi
{
	class TilesTest : public ::testing::Test {};

	/// 牌をテストする。
	TEST_F(TilesTest, test)
	{
		// 筒子をテストする。
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 1), P1);
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 2), P2);
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 3), P3);
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 4), P4);
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 5), P5);
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 6), P6);
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 7), P7);
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 8), P8);
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 9), P9);
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 5, TileAttributes::RED), P5R);

		// 索子をテストする。
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), S1);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), S2);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), S3);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 4), S4);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 5), S5);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 6), S6);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 7), S7);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 8), S8);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), S9);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 5, TileAttributes::RED), S5R);

		// 萬子をテストする。
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 1), M1);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 2), M2);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 3), M3);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 4), M4);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 5), M5);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 6), M6);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 7), M7);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 8), M8);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 9), M9);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 5, TileAttributes::RED), M5R);

		// 風牌をテストする。
		ASSERT_EQ(Tile(TileDesigns::EAST), TN);
		ASSERT_EQ(Tile(TileDesigns::SOUTH), NN);
		ASSERT_EQ(Tile(TileDesigns::WEST), SH);
		ASSERT_EQ(Tile(TileDesigns::NORTH), PE);

		// 三元牌をテストする。
		ASSERT_EQ(Tile(TileDesigns::RED), CH);
		ASSERT_EQ(Tile(TileDesigns::WHITE), HK);
		ASSERT_EQ(Tile(TileDesigns::GREEN), HT);
	}
}
