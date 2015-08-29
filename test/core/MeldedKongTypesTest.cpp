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
#include <MeldedKongTypes.h>


namespace openriichi
{
	class MeldedKongTypesTest : public ::testing::Test {};

	/// 鳴き槓子でないことを表す鳴き槓子種別をテストする。
	TEST_F(MeldedKongTypesTest, testNo)
	{
		const MeldedKongType &meldedKongType = MeldedKongTypes::NO;
		ASSERT_EQ(0, meldedKongType.getId());

		ASSERT_TRUE(NoMeldedKongType() == meldedKongType);
		ASSERT_FALSE(LittleMeldedKongType() == meldedKongType);
		ASSERT_FALSE(BigMeldedKongType() == meldedKongType);

		ASSERT_FALSE(NoMeldedKongType() != meldedKongType);
		ASSERT_TRUE(LittleMeldedKongType() != meldedKongType);
		ASSERT_TRUE(BigMeldedKongType() != meldedKongType);
	}

	/// 小明槓 (加槓) を表す鳴き槓子種別をテストする。
	TEST_F(MeldedKongTypesTest, testLittle)
	{
		const MeldedKongType &meldedKongType = MeldedKongTypes::LITTLE;
		ASSERT_EQ(1, meldedKongType.getId());

		ASSERT_FALSE(NoMeldedKongType() == meldedKongType);
		ASSERT_TRUE(LittleMeldedKongType() == meldedKongType);
		ASSERT_FALSE(BigMeldedKongType() == meldedKongType);

		ASSERT_TRUE(NoMeldedKongType() != meldedKongType);
		ASSERT_FALSE(LittleMeldedKongType() != meldedKongType);
		ASSERT_TRUE(BigMeldedKongType() != meldedKongType);
	}

	/// 大明槓を表す鳴き槓子種別をテストする。
	TEST_F(MeldedKongTypesTest, testBig)
	{
		const MeldedKongType &meldedKongType = MeldedKongTypes::BIG;
		ASSERT_EQ(2, meldedKongType.getId());

		ASSERT_FALSE(NoMeldedKongType() == meldedKongType);
		ASSERT_FALSE(LittleMeldedKongType() == meldedKongType);
		ASSERT_TRUE(BigMeldedKongType() == meldedKongType);

		ASSERT_TRUE(NoMeldedKongType() != meldedKongType);
		ASSERT_TRUE(LittleMeldedKongType() != meldedKongType);
		ASSERT_FALSE(BigMeldedKongType() != meldedKongType);
	}
}
