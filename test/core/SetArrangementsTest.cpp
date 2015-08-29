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
#include <SetArrangements.h>


namespace openriichi
{
	class SetArrangementsTest : public ::testing::Test {};

	/// 順子をテストする。
	TEST_F(SetArrangementsTest, testChow)
	{
		const SetArrangement &setArrangement = SetArrangements::CHOW;
		ASSERT_EQ(1, setArrangement.getId());

		ASSERT_TRUE(ChowSetArrangement() == setArrangement);
		ASSERT_FALSE(PairSetArrangement() == setArrangement);
		ASSERT_FALSE(PungSetArrangement() == setArrangement);
		ASSERT_FALSE(KongSetArrangement() == setArrangement);

		ASSERT_FALSE(ChowSetArrangement() != setArrangement);
		ASSERT_TRUE(PairSetArrangement() != setArrangement);
		ASSERT_TRUE(PungSetArrangement() != setArrangement);
		ASSERT_TRUE(KongSetArrangement() != setArrangement);
	}

	/// 対子をテストする。
	TEST_F(SetArrangementsTest, testPair)
	{
		const SetArrangement &setArrangement = SetArrangements::PAIR;
		ASSERT_EQ(2, setArrangement.getId());

		ASSERT_FALSE(ChowSetArrangement() == setArrangement);
		ASSERT_TRUE(PairSetArrangement() == setArrangement);
		ASSERT_FALSE(PungSetArrangement() == setArrangement);
		ASSERT_FALSE(KongSetArrangement() == setArrangement);

		ASSERT_TRUE(ChowSetArrangement() != setArrangement);
		ASSERT_FALSE(PairSetArrangement() != setArrangement);
		ASSERT_TRUE(PungSetArrangement() != setArrangement);
		ASSERT_TRUE(KongSetArrangement() != setArrangement);
	}

	/// 刻子をテストする。
	TEST_F(SetArrangementsTest, testPung)
	{
		const SetArrangement &setArrangement = SetArrangements::PUNG;
		ASSERT_EQ(3, setArrangement.getId());

		ASSERT_FALSE(ChowSetArrangement() == setArrangement);
		ASSERT_FALSE(PairSetArrangement() == setArrangement);
		ASSERT_TRUE(PungSetArrangement() == setArrangement);
		ASSERT_FALSE(KongSetArrangement() == setArrangement);

		ASSERT_TRUE(ChowSetArrangement() != setArrangement);
		ASSERT_TRUE(PairSetArrangement() != setArrangement);
		ASSERT_FALSE(PungSetArrangement() != setArrangement);
		ASSERT_TRUE(KongSetArrangement() != setArrangement);
	}

	/// 槓子をテストする。
	TEST_F(SetArrangementsTest, testKong)
	{
		const SetArrangement &setArrangement = SetArrangements::KONG;
		ASSERT_EQ(4, setArrangement.getId());

		ASSERT_FALSE(ChowSetArrangement() == setArrangement);
		ASSERT_FALSE(PairSetArrangement() == setArrangement);
		ASSERT_FALSE(PungSetArrangement() == setArrangement);
		ASSERT_TRUE(KongSetArrangement() == setArrangement);

		ASSERT_TRUE(ChowSetArrangement() != setArrangement);
		ASSERT_TRUE(PairSetArrangement() != setArrangement);
		ASSERT_TRUE(PungSetArrangement() != setArrangement);
		ASSERT_FALSE(KongSetArrangement() != setArrangement);
	}
}
