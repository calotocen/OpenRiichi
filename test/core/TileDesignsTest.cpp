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
#include <OpenRiichiAssertion.h>
#include <TileDesigns.h>


namespace openriichi
{
	class TileDesignsTest : public ::testing::Test {};

	/// ID 変数をテストする。
	TEST_F(TileDesignsTest, testId)
	{
		ASSERT_EQ(1, TileDesigns::CIRCLES_ID);
		ASSERT_EQ(2, TileDesigns::BAMBOO_ID);
		ASSERT_EQ(3, TileDesigns::CHARACTERS_ID);
		ASSERT_EQ(4, TileDesigns::EAST_ID);
		ASSERT_EQ(5, TileDesigns::SOUTH_ID);
		ASSERT_EQ(6, TileDesigns::WEST_ID);
		ASSERT_EQ(7, TileDesigns::NORTH_ID);
		ASSERT_EQ(8, TileDesigns::RED_ID);
		ASSERT_EQ(9, TileDesigns::WHITE_ID);
		ASSERT_EQ(10, TileDesigns::GREEN_ID);
	}

	/// コンストラクタ (全パラメータ指定版) をテストする。
	TEST_F(TileDesignsTest, testConstructUsingAllParameters)
	{
#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		ASSERT_THROW(TileDesign(11, 0), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	}

	/// getId 関数をテストする。
	TEST_F(TileDesignsTest, testGetId)
	{
		ASSERT_EQ(1, TileDesigns::CIRCLES.getId());
		ASSERT_EQ(2, TileDesigns::BAMBOO.getId());
		ASSERT_EQ(3, TileDesigns::CHARACTERS.getId());
		ASSERT_EQ(4, TileDesigns::EAST.getId());
		ASSERT_EQ(5, TileDesigns::SOUTH.getId());
		ASSERT_EQ(6, TileDesigns::WEST.getId());
		ASSERT_EQ(7, TileDesigns::NORTH.getId());
		ASSERT_EQ(8, TileDesigns::RED.getId());
		ASSERT_EQ(9, TileDesigns::WHITE.getId());
		ASSERT_EQ(10, TileDesigns::GREEN.getId());
	}

	/// 同一種類の列挙型を比較可能であるかテストする。
	TEST_F(TileDesignsTest, testComparable)
	{
		ASSERT_FALSE(TileDesigns::CIRCLES == TileDesigns::BAMBOO);
		ASSERT_FALSE(TileDesigns::CIRCLES == TileDesigns::CHARACTERS);
		ASSERT_FALSE(TileDesigns::CIRCLES == TileDesigns::EAST);
		ASSERT_FALSE(TileDesigns::CIRCLES == TileDesigns::SOUTH);
		ASSERT_FALSE(TileDesigns::CIRCLES == TileDesigns::WEST);
		ASSERT_FALSE(TileDesigns::CIRCLES == TileDesigns::NORTH);
		ASSERT_FALSE(TileDesigns::CIRCLES == TileDesigns::RED);
		ASSERT_FALSE(TileDesigns::CIRCLES == TileDesigns::WHITE);
		ASSERT_FALSE(TileDesigns::CIRCLES == TileDesigns::GREEN);
	}
}
