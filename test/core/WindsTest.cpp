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
	class WindsTest : public ::testing::Test {};

	/// ID 変数をテストする。
	TEST_F(WindsTest, testId)
	{
		ASSERT_EQ(1, Winds::EAST_ID);
		ASSERT_EQ(2, Winds::SOUTH_ID);
		ASSERT_EQ(3, Winds::WEST_ID);
		ASSERT_EQ(4, Winds::NORTH_ID);
	}

	/// getId 関数をテストする。
	TEST_F(WindsTest, testGetId)
	{
		ASSERT_EQ(1, Winds::EAST.getId());
		ASSERT_EQ(2, Winds::SOUTH.getId());
		ASSERT_EQ(3, Winds::WEST.getId());
		ASSERT_EQ(4, Winds::NORTH.getId());
	}

	/// getPreviousTile 関数をテストする。
	TEST_F(WindsTest, testGetPreviousTile)
	{
		ASSERT_EQ(Winds::NORTH, Winds::EAST.getPreviousWind());
		ASSERT_EQ(Winds::EAST, Winds::SOUTH.getPreviousWind());
		ASSERT_EQ(Winds::SOUTH, Winds::WEST.getPreviousWind());
		ASSERT_EQ(Winds::WEST, Winds::NORTH.getPreviousWind());
	}

	/// getNextTile 関数をテストする。
	TEST_F(WindsTest, testGetNextTile)
	{
		ASSERT_EQ(Winds::SOUTH, Winds::EAST.getNextWind());
		ASSERT_EQ(Winds::WEST, Winds::SOUTH.getNextWind());
		ASSERT_EQ(Winds::NORTH, Winds::WEST.getNextWind());
		ASSERT_EQ(Winds::EAST, Winds::NORTH.getNextWind());
	}

	/// 同一種類の列挙型を比較可能であるかテストする。
	TEST_F(WindsTest, testComparable)
	{
		ASSERT_FALSE(Winds::EAST == Winds::SOUTH);
		ASSERT_FALSE(Winds::EAST == Winds::WEST);
		ASSERT_FALSE(Winds::EAST == Winds::NORTH);
	}
}
