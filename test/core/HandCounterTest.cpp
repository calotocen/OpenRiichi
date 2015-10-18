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
#include <vector>
#include <gtest/gtest.h>
#include <OpenRiichi.h>


using namespace std;


namespace openriichi
{
	class HandCounterTest : public ::testing::Test {};

	/// == 演算子をテストする。
	TEST_F(HandCounterTest, testOperatorEqualTo)
	{
		HandCounter handCounter1a;
		HandCounter handCounter1b;
		HandCounter handCounter2a;
		HandCounter handCounter2b;
		HandCounter handCounter3a;
		HandCounter handCounter3b;
		HandCounter handCounter4a;
		HandCounter handCounter4b;

		handCounter1b.setRound(Winds::EAST);
		handCounter1b.setMajorCount(1);
		handCounter1b.setMinorCount(0);
		handCounter2a.setRound(Winds::SOUTH);
		handCounter2b.setRound(Winds::SOUTH);
		handCounter3a.setMajorCount(4);
		handCounter3b.setMajorCount(4);
		handCounter4a.setMinorCount(8);
		handCounter4b.setMinorCount(8);

		// 自身と比較する。
		ASSERT_TRUE(handCounter1a == handCounter1a);
		ASSERT_TRUE(handCounter1b == handCounter1b);
		ASSERT_TRUE(handCounter2a == handCounter2a);
		ASSERT_TRUE(handCounter2b == handCounter2b);
		ASSERT_TRUE(handCounter3a == handCounter3a);
		ASSERT_TRUE(handCounter3b == handCounter3b);
		ASSERT_TRUE(handCounter4a == handCounter4a);
		ASSERT_TRUE(handCounter4b == handCounter4b);

		// 同じ局カウンタと比較する。
		ASSERT_TRUE(handCounter1a == HandCounter());
		ASSERT_TRUE(handCounter1a == handCounter1b);
		ASSERT_TRUE(handCounter2a == handCounter2b);
		ASSERT_TRUE(handCounter3a == handCounter3b);
		ASSERT_TRUE(handCounter4a == handCounter4b);

		// 異なる局カウンタと比較する。
		vector<HandCounter> handCounters{ handCounter1a, handCounter2a, handCounter3a, handCounter4a };
		for (size_t i = 0; i < handCounters.size(); ++i) {
			for (size_t j = 0; j < handCounters.size(); ++j) {
				if (i != j) {
					ASSERT_FALSE(handCounters[i] == handCounters[j]);
				}
			}
		}
	}

	/// != 演算子をテストする。
	TEST_F(HandCounterTest, testOperatorNotEqualTo)
	{
		HandCounter handCounter1a;
		HandCounter handCounter1b;
		HandCounter handCounter2a;
		HandCounter handCounter2b;
		HandCounter handCounter3a;
		HandCounter handCounter3b;
		HandCounter handCounter4a;
		HandCounter handCounter4b;

		handCounter1b.setRound(Winds::EAST);
		handCounter1b.setMajorCount(1);
		handCounter1b.setMinorCount(0);
		handCounter2a.setRound(Winds::SOUTH);
		handCounter2b.setRound(Winds::SOUTH);
		handCounter3a.setMajorCount(4);
		handCounter3b.setMajorCount(4);
		handCounter4a.setMinorCount(8);
		handCounter4b.setMinorCount(8);

		// 自身と比較する。
		ASSERT_FALSE(handCounter1a != handCounter1a);
		ASSERT_FALSE(handCounter1b != handCounter1b);
		ASSERT_FALSE(handCounter2a != handCounter2a);
		ASSERT_FALSE(handCounter2b != handCounter2b);
		ASSERT_FALSE(handCounter3a != handCounter3a);
		ASSERT_FALSE(handCounter3b != handCounter3b);
		ASSERT_FALSE(handCounter4a != handCounter4a);
		ASSERT_FALSE(handCounter4b != handCounter4b);

		// 同じ局カウンタと比較する。
		ASSERT_FALSE(handCounter1a != HandCounter());
		ASSERT_FALSE(handCounter1a != handCounter1b);
		ASSERT_FALSE(handCounter2a != handCounter2b);
		ASSERT_FALSE(handCounter3a != handCounter3b);
		ASSERT_FALSE(handCounter4a != handCounter4b);

		// 異なる局カウンタと比較する。
		vector<HandCounter> handCounters{ handCounter1a, handCounter2a, handCounter3a, handCounter4a };
		for (size_t i = 0; i < handCounters.size(); ++i) {
			for (size_t j = 0; j < handCounters.size(); ++j) {
				if (i != j) {
					ASSERT_TRUE(handCounters[i] != handCounters[j]);
				}
			}
		}
	}

	/// getRound 関数をテストする。
	TEST_F(HandCounterTest, testToGetRound)
	{
		HandCounter handCounter;

		ASSERT_EQ(Winds::EAST, handCounter.getRound());
	}

	/// setRound 関数をテストする。
	TEST_F(HandCounterTest, testToSetRound)
	{
		HandCounter handCounter;

		handCounter.setRound(Winds::SOUTH);
		ASSERT_EQ(Winds::SOUTH, handCounter.getRound());
	}

	/// nextRound 関数をテストする。
	TEST_F(HandCounterTest, testToNextRound)
	{
		HandCounter handCounter;

		handCounter.nextRound();
		ASSERT_EQ(Winds::SOUTH, handCounter.getRound());

		handCounter.nextRound();
		ASSERT_EQ(Winds::WEST, handCounter.getRound());

		handCounter.nextRound();
		ASSERT_EQ(Winds::NORTH, handCounter.getRound());
	}

	/// getMajorCount 関数をテストする。
	TEST_F(HandCounterTest, testToGetMajorCount)
	{
		HandCounter handCounter;

		ASSERT_EQ(1, handCounter.getMajorCount());
	}

	/// setMajorCount 関数をテストする。
	TEST_F(HandCounterTest, testToSetMajorCount)
	{
		HandCounter handCounter;

		handCounter.setMajorCount(4);
		ASSERT_EQ(4, handCounter.getMajorCount());
	}

	/// resetMajorCount 関数をテストする。
	TEST_F(HandCounterTest, testToResetMajorCount)
	{
		HandCounter handCounter;

		handCounter.setMajorCount(4);
		ASSERT_EQ(4, handCounter.getMajorCount());

		handCounter.resetMajorCount();
		ASSERT_EQ(1, handCounter.getMajorCount());
	}

	/// increaseMajorCount 関数をテストする。
	TEST_F(HandCounterTest, testToIncreaseMajorCount)
	{
		HandCounter handCounter;

		handCounter.increaseMajorCount();
		ASSERT_EQ(2, handCounter.getMajorCount());
	}

	/// getMinorCount 関数をテストする。
	TEST_F(HandCounterTest, testToGetMinorCount)
	{
		HandCounter handCounter;

		ASSERT_EQ(0, handCounter.getMinorCount());
	}

	/// setMinorCount 関数をテストする。
	TEST_F(HandCounterTest, testToSetMinorCount)
	{
		HandCounter handCounter;

		handCounter.setMinorCount(8);
		ASSERT_EQ(8, handCounter.getMinorCount());
	}

	/// resetMinorCount 関数をテストする。
	TEST_F(HandCounterTest, testToResetMinorCount)
	{
		HandCounter handCounter;

		handCounter.setMinorCount(8);
		ASSERT_EQ(8, handCounter.getMinorCount());

		handCounter.resetMinorCount();
		ASSERT_EQ(0, handCounter.getMinorCount());
	}

	/// increaseMinorCount 関数をテストする。
	TEST_F(HandCounterTest, testToIncreaseMinorCount)
	{
		HandCounter handCounter;

		handCounter.increaseMinorCount();
		ASSERT_EQ(1, handCounter.getMinorCount());
	}
}
