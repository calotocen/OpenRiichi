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
#include <Winds.h>


namespace openriichi
{
	class WindsTest : public ::testing::Test {};

	/// 東の風をテストする。
	TEST_F(WindsTest, testEast)
	{
		const Wind &wind = Winds::EAST;
		ASSERT_EQ(1, wind.getId());

		ASSERT_TRUE(EastWind() == wind);
		ASSERT_FALSE(SouthWind() == wind);
		ASSERT_FALSE(WestWind() == wind);
		ASSERT_FALSE(NorthWind() == wind);

		ASSERT_FALSE(EastWind() != wind);
		ASSERT_TRUE(SouthWind() != wind);
		ASSERT_TRUE(WestWind() != wind);
		ASSERT_TRUE(NorthWind() != wind);
	}

	/// 南の風をテストする。
	TEST_F(WindsTest, testSouth)
	{
		const Wind &wind = Winds::SOUTH;
		ASSERT_EQ(2, wind.getId());

		ASSERT_FALSE(EastWind() == wind);
		ASSERT_TRUE(SouthWind() == wind);
		ASSERT_FALSE(WestWind() == wind);
		ASSERT_FALSE(NorthWind() == wind);

		ASSERT_TRUE(EastWind() != wind);
		ASSERT_FALSE(SouthWind() != wind);
		ASSERT_TRUE(WestWind() != wind);
		ASSERT_TRUE(NorthWind() != wind);
	}

	/// 西の風をテストする。
	TEST_F(WindsTest, testWest)
	{
		const Wind &wind = Winds::WEST;
		ASSERT_EQ(3, wind.getId());

		ASSERT_FALSE(EastWind() == wind);
		ASSERT_FALSE(SouthWind() == wind);
		ASSERT_TRUE(WestWind() == wind);
		ASSERT_FALSE(NorthWind() == wind);

		ASSERT_TRUE(EastWind() != wind);
		ASSERT_TRUE(SouthWind() != wind);
		ASSERT_FALSE(WestWind() != wind);
		ASSERT_TRUE(NorthWind() != wind);
	}

	/// 南の風をテストする。
	TEST_F(WindsTest, testNorth)
	{
		const Wind &wind = Winds::NORTH;
		ASSERT_EQ(4, wind.getId());

		ASSERT_FALSE(EastWind() == wind);
		ASSERT_FALSE(SouthWind() == wind);
		ASSERT_FALSE(WestWind() == wind);
		ASSERT_TRUE(NorthWind() == wind);

		ASSERT_TRUE(EastWind() != wind);
		ASSERT_TRUE(SouthWind() != wind);
		ASSERT_TRUE(WestWind() != wind);
		ASSERT_FALSE(NorthWind() != wind);
	}
}
