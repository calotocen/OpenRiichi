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
#include <MeldTypes.h>


namespace openriichi
{
	class MeldTypesTest : public ::testing::Test {};

	/// ID 変数をテストする。
	TEST_F(MeldTypesTest, testId)
	{
		ASSERT_EQ(0, MeldTypes::NONE.ID);
		ASSERT_EQ(1, MeldTypes::LEFT.ID);
		ASSERT_EQ(2, MeldTypes::ACROSS.ID);
		ASSERT_EQ(3, MeldTypes::RIGHT.ID);
	}

	/// getId 関数をテストする。
	TEST_F(MeldTypesTest, testGetId)
	{
		ASSERT_EQ(0, MeldTypes::NONE.getId());
		ASSERT_EQ(1, MeldTypes::LEFT.getId());
		ASSERT_EQ(2, MeldTypes::ACROSS.getId());
		ASSERT_EQ(3, MeldTypes::RIGHT.getId());
	}

	/// 同一種類の列挙型を比較可能であるかテストする。
	TEST_F(MeldTypesTest, testComparable)
	{
		ASSERT_FALSE(MeldTypes::NONE == MeldTypes::LEFT);
		ASSERT_FALSE(MeldTypes::NONE == MeldTypes::ACROSS);
		ASSERT_FALSE(MeldTypes::NONE == MeldTypes::RIGHT);
	}
}
