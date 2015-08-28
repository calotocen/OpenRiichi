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
#include <TileAttributes.h>


namespace openriichi
{
	class TileAttributesTest : public ::testing::Test {};

	/// 属性なしの牌属性をテストする。
	TEST_F(TileAttributesTest, testNone)
	{
		const TileAttribute &tileAttribute = TileAttributes::NONE;
		ASSERT_EQ(0, tileAttribute.getId());

		ASSERT_TRUE(NoneTileAttribute() == tileAttribute);
		ASSERT_FALSE(RedTileAttribute() == tileAttribute);
	}

	/// 赤の牌属性をテストする。
	TEST_F(TileAttributesTest, testRed)
	{
		const TileAttribute &tileAttribute = TileAttributes::RED;
		ASSERT_EQ(1, tileAttribute.getId());

		ASSERT_FALSE(NoneTileAttribute() == tileAttribute);
		ASSERT_TRUE(RedTileAttribute() == tileAttribute);
	}
}
