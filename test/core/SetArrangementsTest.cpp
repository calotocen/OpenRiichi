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
	class SetArrangementsTest : public ::testing::Test {};

	/// 同一種類の列挙型を比較可能であるかテストする。
	TEST_F(SetArrangementsTest, testOperatorEqualTo)
	{
		ASSERT_FALSE(SetArrangements::CHOW == SetArrangements::PAIR);
		ASSERT_FALSE(SetArrangements::CHOW == SetArrangements::PUNG);
		ASSERT_FALSE(SetArrangements::CHOW == SetArrangements::KONG);
	}

	/// ID 変数をテストする。
	TEST_F(SetArrangementsTest, testId)
	{
		ASSERT_EQ(1, SetArrangements::CHOW_ID);
		ASSERT_EQ(2, SetArrangements::PAIR_ID);
		ASSERT_EQ(3, SetArrangements::PUNG_ID);
		ASSERT_EQ(4, SetArrangements::KONG_ID);
	}

	/// getId 関数をテストする。
	TEST_F(SetArrangementsTest, testGetId)
	{
		ASSERT_EQ(1, SetArrangements::CHOW.getId());
		ASSERT_EQ(2, SetArrangements::PAIR.getId());
		ASSERT_EQ(3, SetArrangements::PUNG.getId());
		ASSERT_EQ(4, SetArrangements::KONG.getId());
	}
}
