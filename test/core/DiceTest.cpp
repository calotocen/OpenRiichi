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


namespace openriichi
{
	class DiceTest : public ::testing::Test {};

	/// == 演算子をテストする。
	TEST_F(DiceTest, testEquals)
	{
		Dice dice1;
		Dice dice2(6);

		// 自身と比較する。
		ASSERT_TRUE(dice1 == dice1);
		ASSERT_TRUE(dice2 == dice2);

		// 同じさいころと比較する。
		ASSERT_TRUE(dice1 == Dice());
		ASSERT_TRUE(dice2 == Dice(6));

		// 異なるさいころと比較する。
		ASSERT_FALSE(dice1 == dice2);
	}

	/// != 演算子をテストする。
	TEST_F(DiceTest, testNotEquals)
	{
		Dice dice1;
		Dice dice2(6);

		// 自身と比較する。
		ASSERT_FALSE(dice1 != dice1);
		ASSERT_FALSE(dice2 != dice2);

		// 同じさいころと比較する。
		ASSERT_FALSE(dice1 != Dice());
		ASSERT_FALSE(dice2 != Dice(6));

		// 異なるさいころと比較する。
		ASSERT_TRUE(dice1 != dice2);
	}

	/// roll 関数をテストする。
	TEST_F(DiceTest, testRoll)
	{
		Dice dice;

		for (auto i = 0; i < 100; ++i) {
			dice.roll();
			ASSERT_LE(1U, dice.getNumber());
			ASSERT_GE(6U, dice.getNumber());
		}
	}

	/// getNumber 関数をテストする。
	TEST_F(DiceTest, testGetNumber)
	{
		ASSERT_EQ(1, Dice().getNumber());
		ASSERT_EQ(6, Dice(6).getNumber());
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

#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		ASSERT_THROW(dice.setNumber(0), OpenRiichiAssertion);
		ASSERT_THROW(dice.setNumber(7), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	}
}
