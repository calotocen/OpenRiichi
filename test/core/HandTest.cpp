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
#include <Hand.h>
#include <Tiles.h>


using namespace std;


namespace openriichi
{
	class HandTest : public ::testing::Test {};

	/// コンストラクタ (牌配列，面子配列指定) をテストする。
	TEST_F(HandTest, testConstructorWithTilesAndSets)
	{
		Hand hand(Hand::Tiles{ HK, HK, HK }, Hand::Sets{ Set(HT, HT, HT) });

		ASSERT_EQ((Hand::Tiles{ HK, HK, HK }), hand.tiles());
		ASSERT_EQ((Hand::Sets{ Set(HT, HT, HT) }), hand.sets());
	}

	/// getTiles 関数をテストする。
	TEST_F(HandTest, testGetTiles)
	{
		Hand hand;

		ASSERT_EQ(Hand::Tiles(), hand.getTiles());

		hand.tiles() = { P1, P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN };
		ASSERT_EQ((Hand::Tiles{ P1, P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN }), hand.getTiles());

		hand.tiles().add(NN);
		ASSERT_EQ((Hand::Tiles{ P1, P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN, NN }), hand.getTiles());

		hand.tiles().remove(0);
		ASSERT_EQ((Hand::Tiles{ P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN, NN }), hand.getTiles());
	}

	/// setTiles 関数をテストする。
	TEST_F(HandTest, testSetTiles)
	{
		Hand hand;

		hand.setTiles(Hand::Tiles{ P1, P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN, NN });
		ASSERT_EQ((Hand::Tiles{ P1, P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN, NN }), hand.getTiles());

		hand.setTiles(Hand::Tiles());
		ASSERT_EQ(Hand::Tiles(), hand.getTiles());
	}

	/// tiles 関数をテストする。
	TEST_F(HandTest, testTiles)
	{
		Hand hand;

		ASSERT_EQ(Hand::Tiles(), hand.tiles());

		hand.tiles() = { P1, P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN };
		ASSERT_EQ((Hand::Tiles{ P1, P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN }), hand.tiles());

		hand.tiles().add(NN);
		ASSERT_EQ((Hand::Tiles{ P1, P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN, NN }), hand.tiles());

		hand.tiles().remove(0);
		ASSERT_EQ((Hand::Tiles{ P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN, NN }), hand.tiles());
	}

	/// getSets 関数をテストする。
	TEST_F(HandTest, testGetSets)
	{
		Hand hand;

		ASSERT_EQ(Hand::Sets(), hand.getSets());

		hand.sets() = { Set(P1, P2, P3), Set(S1, S2, S3), Set(M1, M2, M3), Set(TN, TN, TN, TN) };
		ASSERT_EQ((Hand::Sets{ Set(P1, P2, P3), Set(S1, S2, S3), Set(M1, M2, M3), Set(TN, TN, TN, TN) }), hand.getSets());

		hand.sets().add(Set(NN, NN));
		ASSERT_EQ((Hand::Sets{ Set(P1, P2, P3), Set(S1, S2, S3), Set(M1, M2, M3), Set(TN, TN, TN, TN), Set(NN, NN) }), hand.getSets());

		hand.sets().remove(0);
		ASSERT_EQ((Hand::Sets{ Set(S1, S2, S3), Set(M1, M2, M3), Set(TN, TN, TN, TN), Set(NN, NN) }), hand.getSets());
	}

	/// setSets 関数をテストする。
	TEST_F(HandTest, testSetSets)
	{
		Hand hand;

		hand.setSets(Hand::Sets{ Set(P1, P2, P3), Set(S1, S2, S3), Set(M1, M2, M3), Set(TN, TN, TN, TN) });
		ASSERT_EQ((Hand::Sets{ Set(P1, P2, P3), Set(S1, S2, S3), Set(M1, M2, M3), Set(TN, TN, TN, TN) }), hand.getSets());

		hand.setSets(Hand::Sets());
		ASSERT_EQ(Hand::Sets(), hand.getSets());
	}

	/// sets 関数をテストする。
	TEST_F(HandTest, testSets)
	{
		Hand hand;

		ASSERT_EQ(Hand::Sets(), hand.sets());

		hand.sets() = { Set(P1, P2, P3), Set(S1, S2, S3), Set(M1, M2, M3), Set(TN, TN, TN, TN) };
		ASSERT_EQ((Hand::Sets{ Set(P1, P2, P3), Set(S1, S2, S3), Set(M1, M2, M3), Set(TN, TN, TN, TN) }), hand.sets());

		hand.sets().add(Set(NN, NN));
		ASSERT_EQ((Hand::Sets{ Set(P1, P2, P3), Set(S1, S2, S3), Set(M1, M2, M3), Set(TN, TN, TN, TN), Set(NN, NN) }), hand.sets());

		hand.sets().remove(0);
		ASSERT_EQ((Hand::Sets{ Set(S1, S2, S3), Set(M1, M2, M3), Set(TN, TN, TN, TN), Set(NN, NN) }), hand.sets());
	}

	/// == 演算子をテストする。
	TEST_F(HandTest, testEquals)
	{
		Hand hand1;
		Hand hand2{ CH, CH, CH };
		Hand hand3{ Set(CH, CH, CH) };
		Hand hand4(Hand::Tiles{ CH, CH, CH }, Hand::Sets{ Set(CH, CH, CH) });

		// 自身と比較する。
		ASSERT_TRUE(hand1 == hand1);
		ASSERT_TRUE(hand2 == hand2);
		ASSERT_TRUE(hand3 == hand3);
		ASSERT_TRUE(hand4 == hand4);

		// 同じ手牌と比較する。
		ASSERT_TRUE(Hand() == hand1);
		ASSERT_TRUE((Hand{ CH, CH, CH }) == hand2);
		ASSERT_TRUE((Hand{ Set(CH, CH, CH) }) == hand3);
		ASSERT_TRUE(Hand(Hand::Tiles{ CH, CH, CH }, Hand::Sets{ Set(CH, CH, CH) }) == hand4);

		// 異なる手牌と比較する。
		vector<Hand> hands{ hand1, hand2, hand3, hand4 };
		for (auto i = 0; i < hands.size(); ++i) {
			for (auto j = 0; j < hands.size(); ++j) {
				if (i != j) {
					ASSERT_FALSE(hands[i] == hands[j]);
				}
			}
		}
	}

	/// != 演算子をテストする。
	TEST_F(HandTest, testNotEquals)
	{
		Hand hand1;
		Hand hand2{ CH, CH, CH };
		Hand hand3{ Set(CH, CH, CH) };
		Hand hand4(Hand::Tiles{ CH, CH, CH }, Hand::Sets{ Set(CH, CH, CH) });

		// 自身と比較する。
		ASSERT_FALSE(hand1 != hand1);
		ASSERT_FALSE(hand2 != hand2);
		ASSERT_FALSE(hand3 != hand3);
		ASSERT_FALSE(hand4 != hand4);

		// 同じ手牌と比較する。
		ASSERT_FALSE(Hand() != hand1);
		ASSERT_FALSE((Hand{ CH, CH, CH }) != hand2);
		ASSERT_FALSE((Hand{ Set(CH, CH, CH) }) != hand3);
		ASSERT_FALSE(Hand(Hand::Tiles{ CH, CH, CH }, Hand::Sets{ Set(CH, CH, CH) }) != hand4);

		// 異なる手牌と比較する。
		vector<Hand> hands{ hand1, hand2, hand3, hand4 };
		for (auto i = 0; i < hands.size(); ++i) {
			for (auto j = 0; j < hands.size(); ++j) {
				if (i != j) {
					ASSERT_TRUE(hands[i] != hands[j]);
				}
			}
		}
	}

	/// = 演算子 (牌配列用) をテストする。
	TEST_F(HandTest, testSubstituteTiles)
	{
		Hand hand;

		hand = { P1, P2, P3 };
		ASSERT_EQ((Hand{ P1, P2, P3 }), hand);
	}

	/// = 演算子 (面子配列用) をテストする。
	TEST_F(HandTest, testSubstituteSets)
	{
		Hand hand;

		hand = { Set(P1, P2, P3) };
		ASSERT_EQ((Hand{ Set(P1, P2, P3) }), hand);
	}
}
