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
	class MeldedKongTypesTest : public ::testing::Test {};

	/// ID 変数をテストする。
	TEST_F(MeldedKongTypesTest, testId)
	{
		ASSERT_EQ(0, MeldedKongTypes::NO_ID);
		ASSERT_EQ(1, MeldedKongTypes::LITTLE_ID);
		ASSERT_EQ(2, MeldedKongTypes::BIG_ID);
	}

	/// getId 関数をテストする。
	TEST_F(MeldedKongTypesTest, testGetId)
	{
		ASSERT_EQ(0, MeldedKongTypes::NO.getId());
		ASSERT_EQ(1, MeldedKongTypes::LITTLE.getId());
		ASSERT_EQ(2, MeldedKongTypes::BIG.getId());
	}

	/// 同一種類の列挙型を比較可能であるかテストする。
	TEST_F(MeldedKongTypesTest, testComparable)
	{
		ASSERT_FALSE(MeldedKongTypes::NO == MeldedKongTypes::LITTLE);
		ASSERT_FALSE(MeldedKongTypes::NO == MeldedKongTypes::BIG);
	}
}
