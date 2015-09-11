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
#include <SimpleHand.h>


namespace openriichi
{
	class SimpleHandTest : public ::testing::Test {};

	/// インスタンスのサイズをテストする。
	TEST_F(SimpleHandTest, testSizeOfInstance)
	{
		SimpleHand hand;
		ASSERT_EQ(46, sizeof(hand));
	}

	// 手牌をテストする。
	TEST_F(SimpleHandTest, testHand)
	{
		SimpleHand hand;

		SimpleHand::Tiles &tiles = hand.tiles();
		ASSERT_EQ(SimpleHand::Tiles(), tiles);

		SimpleHand::Sets &sets = hand.sets();
		ASSERT_EQ(SimpleHand::Sets(), sets);
	}

	// 手牌の比較をテストする。
	TEST_F(SimpleHandTest, testEqualsAndNotEquals)
	{
		SimpleHand hand1;
		SimpleHand hand2;

		ASSERT_TRUE(hand1 == hand1);
		ASSERT_FALSE(hand1 != hand1);
		ASSERT_TRUE(hand1 == hand2);
		ASSERT_FALSE(hand1 != hand2);

		hand1.tiles().add(Tile());
		ASSERT_FALSE(hand1 == hand2);
		ASSERT_TRUE(hand1 != hand2);

		hand2.tiles().add(Tile());
		ASSERT_TRUE(hand1 == hand2);
		ASSERT_FALSE(hand1 != hand2);

		hand1.sets().add(Set());
		ASSERT_FALSE(hand1 == hand2);
		ASSERT_TRUE(hand1 != hand2);

		hand2.sets().add(Set());
		ASSERT_TRUE(hand1 == hand2);
		ASSERT_FALSE(hand1 != hand2);
	}
}
