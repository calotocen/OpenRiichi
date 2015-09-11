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

	/// 面前であることを表す鳴き種別をテストする。
	TEST_F(MeldTypesTest, testNone)
	{
		const MeldType &meldType = MeldTypes::NONE;
		ASSERT_EQ(0, meldType.getId());

		ASSERT_TRUE(NoneMeldType() == meldType);
		ASSERT_FALSE(LeftMeldType() == meldType);
		ASSERT_FALSE(CenterMeldType() == meldType);
		ASSERT_FALSE(RightMeldType() == meldType);

		ASSERT_FALSE(NoneMeldType() != meldType);
		ASSERT_TRUE(LeftMeldType() != meldType);
		ASSERT_TRUE(CenterMeldType() != meldType);
		ASSERT_TRUE(RightMeldType() != meldType);
	}

	/// 順子の場合は左の牌，刻子，槓子の場合は上家の牌を鳴いたことを表す鳴き種別をテストする。
	TEST_F(MeldTypesTest, testLeft)
	{
		const MeldType &meldType = MeldTypes::LEFT;
		ASSERT_EQ(1, meldType.getId());

		ASSERT_FALSE(NoneMeldType() == meldType);
		ASSERT_TRUE(LeftMeldType() == meldType);
		ASSERT_FALSE(CenterMeldType() == meldType);
		ASSERT_FALSE(RightMeldType() == meldType);

		ASSERT_TRUE(NoneMeldType() != meldType);
		ASSERT_FALSE(LeftMeldType() != meldType);
		ASSERT_TRUE(CenterMeldType() != meldType);
		ASSERT_TRUE(RightMeldType() != meldType);
	}

	/// 順子の場合は中央の牌，刻子，槓子の場合は対面の牌を鳴いたことを表す鳴き種別をテストする。
	TEST_F(MeldTypesTest, testCenter)
	{
		const MeldType &meldType = MeldTypes::ACROSS;
		ASSERT_EQ(2, meldType.getId());

		ASSERT_FALSE(NoneMeldType() == meldType);
		ASSERT_FALSE(LeftMeldType() == meldType);
		ASSERT_TRUE(CenterMeldType() == meldType);
		ASSERT_FALSE(RightMeldType() == meldType);

		ASSERT_TRUE(NoneMeldType() != meldType);
		ASSERT_TRUE(LeftMeldType() != meldType);
		ASSERT_FALSE(CenterMeldType() != meldType);
		ASSERT_TRUE(RightMeldType() != meldType);
	}

	/// 順子の場合は右の牌，刻子，槓子の場合は下家の牌を鳴いたことを表す鳴き種別をテストする。
	TEST_F(MeldTypesTest, testRight)
	{
		const MeldType &meldType = MeldTypes::RIGHT;
		ASSERT_EQ(3, meldType.getId());

		ASSERT_FALSE(NoneMeldType() == meldType);
		ASSERT_FALSE(LeftMeldType() == meldType);
		ASSERT_FALSE(CenterMeldType() == meldType);
		ASSERT_TRUE(RightMeldType() == meldType);

		ASSERT_TRUE(NoneMeldType() != meldType);
		ASSERT_TRUE(LeftMeldType() != meldType);
		ASSERT_TRUE(CenterMeldType() != meldType);
		ASSERT_FALSE(RightMeldType() != meldType);
	}
}
