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
#include <Dice.h>
#include <OpenRiichiAssertion.h>


using namespace std;


namespace openriichi
{
	class DiceTest : public ::testing::Test {};

	/// roll 関数をテストする。
	TEST_F(DiceTest, testRoll)
	{
		Dice dice;

		for (auto i = 0; i < 100; ++i) {
			dice.roll();
			ASSERT_LE(1, dice.getNumber());
			ASSERT_GE(6, dice.getNumber());
		}
	}

	/// getNumber 関数をテストする。
	TEST_F(DiceTest, testGetNumber)
	{
		ASSERT_EQ(1, Dice().getNumber());
	}

	/// setNumber 関数をテストする。
	TEST_F(DiceTest, testSetNumber)
	{
		Dice dice;

		dice.setNumber(6);
		ASSERT_EQ(6, dice.getNumber());

		dice.setNumber(3);
		ASSERT_EQ(3, dice.getNumber());

		dice.setNumber(1);
		ASSERT_EQ(1, dice.getNumber());

#if OPENRIICHI_ENABLE_ASSERTION == 1
		ASSERT_THROW(dice.setNumber(0), OpenRiichiAssertion);
		ASSERT_THROW(dice.setNumber(7), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}
}
