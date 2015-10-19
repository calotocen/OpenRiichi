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
	class HandTest : public ::testing::Test {};

	/// コンストラクタ (牌配列，面子配列指定) をテストする。
	TEST_F(HandTest, testConstructorWithTilesAndSets)
	{
		Hand hand(Hand::Tiles{ HK, HK, HK }, Hand::Sets{ Set(HT, HT, HT) });

		ASSERT_EQ((Hand::Tiles{ HK, HK, HK }), hand.tiles());
		ASSERT_EQ((Hand::Sets{ Set(HT, HT, HT) }), hand.sets());
	}

	/// == 演算子をテストする。
	TEST_F(HandTest, testOperatorEqualTo)
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
		for (size_t i = 0; i < hands.size(); ++i) {
			for (size_t j = 0; j < hands.size(); ++j) {
				if (i != j) {
					ASSERT_FALSE(hands[i] == hands[j]);
				}
			}
		}
	}

	/// != 演算子をテストする。
	TEST_F(HandTest, testOperatorNotEqualTo)
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
		for (size_t i = 0; i < hands.size(); ++i) {
			for (size_t j = 0; j < hands.size(); ++j) {
				if (i != j) {
					ASSERT_TRUE(hands[i] != hands[j]);
				}
			}
		}
	}

	/// = 演算子 (牌初期化子リスト用) をテストする。
	TEST_F(HandTest, testOperatorAssignmentWithTiles)
	{
		Hand hand(Hand::Tiles(), Hand::Sets{ Set(P1, P2, P3) });

		hand = { P1, P2, P3 };
		ASSERT_EQ((Hand{ P1, P2, P3 }), hand);
	}

	/// = 演算子 (面子初期化子リスト用) をテストする。
	TEST_F(HandTest, testOperatorAssignmentWithSets)
	{
		Hand hand(Hand::Tiles{ P1 }, Hand::Sets());

		hand = { Set(P1, P2, P3) };
		ASSERT_EQ((Hand{ Set(P1, P2, P3) }), hand);
	}

	/// getTiles 関数をテストする。
	TEST_F(HandTest, testToGetTiles)
	{
		Hand hand;

		ASSERT_EQ(Hand::Tiles(), hand.getTiles());

		hand.tiles() = { P1, P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN };
		ASSERT_EQ((Hand::Tiles{ P1, P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN }), hand.getTiles());

		hand.tiles().push_back(NN);
		ASSERT_EQ((Hand::Tiles{ P1, P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN, NN }), hand.getTiles());

		hand.tiles().erase(hand.tiles().begin());
		ASSERT_EQ((Hand::Tiles{ P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN, NN }), hand.getTiles());
	}

	/// setTiles 関数をテストする。
	TEST_F(HandTest, testToSetTiles)
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
		Hand hand1;
		const Hand hand2;

		ASSERT_EQ(Hand::Tiles(), hand1.tiles());

		hand1.tiles() = { P1, P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN };
		ASSERT_EQ((Hand::Tiles{ P1, P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN }), hand1.tiles());

		hand1.tiles().push_back(NN);
		ASSERT_EQ((Hand::Tiles{ P1, P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN, NN }), hand1.tiles());

		hand1.tiles().erase(hand1.tiles().begin());
		ASSERT_EQ((Hand::Tiles{ P2, P3, S1, S2, S3, M1, M2, M3, TN, TN, TN, NN, NN }), hand1.tiles());

		ASSERT_EQ(Hand::Tiles(), hand2.tiles());
	}

	/// sets 関数をテストする。
	TEST_F(HandTest, testSets)
	{
		Hand hand1;
		const Hand hand2;

		ASSERT_EQ(Hand::Sets(), hand1.sets());

		hand1.sets() = { Set(P1, P2, P3), Set(S1, S2, S3), Set(M1, M2, M3) };
		ASSERT_EQ((Hand::Sets{ Set(P1, P2, P3), Set(S1, S2, S3), Set(M1, M2, M3) }), hand1.sets());

		hand1.sets().push_back(Set(TN, TN, TN, TN));
		ASSERT_EQ((Hand::Sets{ Set(P1, P2, P3), Set(S1, S2, S3), Set(M1, M2, M3), Set(TN, TN, TN, TN) }), hand1.sets());

		hand1.sets().erase(hand1.sets().begin());
		ASSERT_EQ((Hand::Sets{ Set(S1, S2, S3), Set(M1, M2, M3), Set(TN, TN, TN, TN) }), hand1.sets());

		ASSERT_EQ(Hand::Sets(), hand2.sets());
	}

	/// getSets 関数をテストする。
	TEST_F(HandTest, testToGetSets)
	{
		Hand hand;

		ASSERT_EQ(Hand::Sets(), hand.getSets());

		hand.sets() = { Set(P1, P2, P3), Set(S1, S2, S3), Set(M1, M2, M3) };
		ASSERT_EQ((Hand::Sets{ Set(P1, P2, P3), Set(S1, S2, S3), Set(M1, M2, M3) }), hand.getSets());

		hand.sets().push_back(Set(TN, TN, TN, TN));
		ASSERT_EQ((Hand::Sets{ Set(P1, P2, P3), Set(S1, S2, S3), Set(M1, M2, M3), Set(TN, TN, TN, TN) }), hand.getSets());

		hand.sets().erase(hand.sets().begin());
		ASSERT_EQ((Hand::Sets{ Set(S1, S2, S3), Set(M1, M2, M3), Set(TN, TN, TN, TN) }), hand.getSets());
	}

	/// setSets 関数をテストする。
	TEST_F(HandTest, testToSetSets)
	{
		Hand hand;

		hand.setSets(Hand::Sets{ Set(P1, P2, P3), Set(S1, S2, S3), Set(M1, M2, M3), Set(TN, TN, TN, TN) });
		ASSERT_EQ((Hand::Sets{ Set(P1, P2, P3), Set(S1, S2, S3), Set(M1, M2, M3), Set(TN, TN, TN, TN) }), hand.getSets());

		hand.setSets(Hand::Sets());
		ASSERT_EQ(Hand::Sets(), hand.getSets());
	}
}
