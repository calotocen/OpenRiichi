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
#include <HandCounter.h>
#include <Winds.h>


namespace openriichi
{
	class HandCounterTest : public ::testing::Test {};

	/// getRound 関数をテストする。
	TEST_F(HandCounterTest, testGetRound)
	{
		HandCounter handCounter;

		ASSERT_EQ(Winds::EAST, handCounter.getRound());
	}

	/// setRound 関数をテストする。
	TEST_F(HandCounterTest, testSetRound)
	{
		HandCounter handCounter;

		handCounter.setRound(Winds::SOUTH);
		ASSERT_EQ(Winds::SOUTH, handCounter.getRound());
	}

	/// nextRound 関数をテストする。
	TEST_F(HandCounterTest, testNextRound)
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
	TEST_F(HandCounterTest, testGetMajorCount)
	{
		HandCounter handCounter;

		ASSERT_EQ(1, handCounter.getMajorCount());
	}

	/// setMajorCount 関数をテストする。
	TEST_F(HandCounterTest, testSetMajorCount)
	{
		HandCounter handCounter;

		handCounter.setMajorCount(4);
		ASSERT_EQ(4, handCounter.getMajorCount());
	}

	/// resetMajorCount 関数をテストする。
	TEST_F(HandCounterTest, testResetMajorCount)
	{
		HandCounter handCounter;

		handCounter.setMajorCount(4);
		ASSERT_EQ(4, handCounter.getMajorCount());

		handCounter.resetMajorCount();
		ASSERT_EQ(1, handCounter.getMajorCount());
	}

	/// increaseMajorCount 関数をテストする。
	TEST_F(HandCounterTest, testIncreaseMajorCount)
	{
		HandCounter handCounter;

		handCounter.increaseMajorCount();
		ASSERT_EQ(2, handCounter.getMajorCount());
	}

	/// getMinorCount 関数をテストする。
	TEST_F(HandCounterTest, testGetMinorCount)
	{
		HandCounter handCounter;

		ASSERT_EQ(0, handCounter.getMinorCount());
	}

	/// setMinorCount 関数をテストする。
	TEST_F(HandCounterTest, testSetMinorCount)
	{
		HandCounter handCounter;

		handCounter.setMinorCount(8);
		ASSERT_EQ(8, handCounter.getMinorCount());
	}

	/// resetMinorCount 関数をテストする。
	TEST_F(HandCounterTest, testResetMinorCount)
	{
		HandCounter handCounter;

		handCounter.setMinorCount(8);
		ASSERT_EQ(8, handCounter.getMinorCount());

		handCounter.resetMinorCount();
		ASSERT_EQ(0, handCounter.getMinorCount());
	}

	/// increaseMinorCount 関数をテストする。
	TEST_F(HandCounterTest, testIncreaseMinorCount)
	{
		HandCounter handCounter;

		handCounter.increaseMinorCount();
		ASSERT_EQ(1, handCounter.getMinorCount());
	}
}
