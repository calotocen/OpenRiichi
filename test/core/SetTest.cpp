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
	class SetTest : public ::testing::Test
	{
	protected:
		Set P1P2P3;
		Set P1P2P3R;
		Set P1P2P3_L;
		Set S1S2S3;
		Set S7S8S9;
		Set S8S7S9_L;
		Set M7M8M9;
		Set P1P1;
		Set S1S1;
		Set P1P1P1;
		Set P1P1P1_L;
		Set M1M1M1;
		Set TNTNTN_A;
		Set TNTNTN_R;
		Set P1P1P1P1;
		Set P1P1P1P1_LL;
		Set P1P1P1P1_BL;

	protected:
		SetTest()
			: P1P2P3(P1, P2, P3)
			, P1P2P3R(P1, P2, Tile(TileDesigns::CIRCLES, 3, TileAttributes::RED))
			, P1P2P3_L(P1, P2, P3, MeldTypes::LEFT)
			, S1S2S3(S1, S2, S3)
			, S7S8S9(S7, S8, S9)
			, S8S7S9_L(S8, S7, S9, MeldTypes::LEFT)
			, M7M8M9(M7, M8, M9)
			, P1P1(P1, P1)
			, S1S1(S1, S1)
			, P1P1P1(P1, P1, P1)
			, P1P1P1_L(P1, P1, P1, MeldTypes::LEFT)
			, M1M1M1(M1, M1, M1)
			, TNTNTN_A(TN, TN, TN, MeldTypes::ACROSS)
			, TNTNTN_R(TN, TN, TN, MeldTypes::RIGHT)
			, P1P1P1P1(P1, P1, P1, P1)
			, P1P1P1P1_LL(P1, P1, P1, P1, MeldedKongTypes::LITTLE, MeldTypes::LEFT)
			, P1P1P1P1_BL(P1, P1, P1, P1, MeldedKongTypes::BIG, MeldTypes::LEFT)
		{}
	};

	/// コンストラクタ (対子用) をテストする。
	TEST_F(SetTest, testConstructForPair)
	{
		Set pair(P5, P5R);
		ASSERT_EQ((Set::Tiles{ P5, P5R }), pair.getTiles());

#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		ASSERT_THROW(Set(P1, P2), OpenRiichiAssertion);
		ASSERT_THROW(Set(TN, NN), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	}

	/// コンストラクタ (順子，刻子用) をテストする。
	TEST_F(SetTest, testConstructForChowAndPung)
	{
		Set chow(S4, S5R, S6);
		Set pung(S5, S5R, S5R);

		ASSERT_EQ((Set::Tiles{ S4, S5R, S6 }), chow.getTiles());
		ASSERT_EQ((Set::Tiles{ S5, S5R, S5R }), pung.getTiles());

#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		ASSERT_THROW(Set(P1, P2, S3), OpenRiichiAssertion);
		ASSERT_THROW(Set(P1, P1, S1), OpenRiichiAssertion);
		ASSERT_THROW(Set(P1, P2, P2), OpenRiichiAssertion);
		ASSERT_THROW(Set(P1, P2, P3, MeldType(4)), OpenRiichiAssertion);
		ASSERT_THROW(Set(P1, P2, P3, MeldTypes::ACROSS), OpenRiichiAssertion);
		ASSERT_THROW(Set(P1, P2, P3, MeldTypes::RIGHT), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	}

	/// コンストラクタ (槓子用) をテストする。
	TEST_F(SetTest, testConstructForKong)
	{
		Set kong(M5, M5, M5R, M5R);

		ASSERT_EQ((Set::Tiles{ M5, M5, M5R, M5R }), kong.getTiles());

#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		ASSERT_THROW(Set(TN, TN, TN, NN), OpenRiichiAssertion);
		ASSERT_THROW(Set(P1, P1, P1, P2), OpenRiichiAssertion);
		ASSERT_THROW(Set(P1, P1, P1, P1, MeldedKongType(3), MeldTypes::LEFT), OpenRiichiAssertion);
		ASSERT_THROW(Set(P1, P1, P1, P1, MeldedKongTypes::LITTLE, MeldType(4)), OpenRiichiAssertion);
		ASSERT_THROW(Set(P1, P1, P1, P1, MeldedKongTypes::NO, MeldTypes::LEFT), OpenRiichiAssertion);
		ASSERT_THROW(Set(P1, P1, P1, P1, MeldedKongTypes::BIG, MeldTypes::NONE), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	}

	/// getArrangement 関数をテストする。
	TEST_F(SetTest, testGetArrangement)
	{
		ASSERT_EQ(SetArrangements::CHOW, P1P2P3.getArrangement());
		ASSERT_EQ(SetArrangements::CHOW, P1P2P3R.getArrangement());
		ASSERT_EQ(SetArrangements::CHOW, P1P2P3_L.getArrangement());
		ASSERT_EQ(SetArrangements::CHOW, S1S2S3.getArrangement());
		ASSERT_EQ(SetArrangements::CHOW, S7S8S9.getArrangement());
		ASSERT_EQ(SetArrangements::CHOW, S8S7S9_L.getArrangement());
		ASSERT_EQ(SetArrangements::CHOW, M7M8M9.getArrangement());
		ASSERT_EQ(SetArrangements::PAIR, P1P1.getArrangement());
		ASSERT_EQ(SetArrangements::PAIR, S1S1.getArrangement());
		ASSERT_EQ(SetArrangements::PUNG, P1P1P1.getArrangement());
		ASSERT_EQ(SetArrangements::PUNG, P1P1P1_L.getArrangement());
		ASSERT_EQ(SetArrangements::PUNG, M1M1M1.getArrangement());
		ASSERT_EQ(SetArrangements::PUNG, TNTNTN_A.getArrangement());
		ASSERT_EQ(SetArrangements::PUNG, TNTNTN_R.getArrangement());
		ASSERT_EQ(SetArrangements::KONG, P1P1P1P1.getArrangement());
		ASSERT_EQ(SetArrangements::KONG, P1P1P1P1_LL.getArrangement());
		ASSERT_EQ(SetArrangements::KONG, P1P1P1P1_BL.getArrangement());
	}

	/// getMeldType 関数をテストする。
	TEST_F(SetTest, testGetMeldType)
	{
		ASSERT_EQ(MeldTypes::NONE, P1P2P3.getMeldType());
		ASSERT_EQ(MeldTypes::NONE, P1P2P3R.getMeldType());
		ASSERT_EQ(MeldTypes::LEFT, P1P2P3_L.getMeldType());
		ASSERT_EQ(MeldTypes::NONE, S1S2S3.getMeldType());
		ASSERT_EQ(MeldTypes::NONE, S7S8S9.getMeldType());
		ASSERT_EQ(MeldTypes::LEFT, S8S7S9_L.getMeldType());
		ASSERT_EQ(MeldTypes::NONE, M7M8M9.getMeldType());
		ASSERT_EQ(MeldTypes::NONE, P1P1.getMeldType());
		ASSERT_EQ(MeldTypes::NONE, S1S1.getMeldType());
		ASSERT_EQ(MeldTypes::NONE, P1P1P1.getMeldType());
		ASSERT_EQ(MeldTypes::LEFT, P1P1P1_L.getMeldType());
		ASSERT_EQ(MeldTypes::NONE, M1M1M1.getMeldType());
		ASSERT_EQ(MeldTypes::ACROSS, TNTNTN_A.getMeldType());
		ASSERT_EQ(MeldTypes::RIGHT, TNTNTN_R.getMeldType());
		ASSERT_EQ(MeldTypes::NONE, P1P1P1P1.getMeldType());
		ASSERT_EQ(MeldTypes::LEFT, P1P1P1P1_LL.getMeldType());
		ASSERT_EQ(MeldTypes::LEFT, P1P1P1P1_BL.getMeldType());
	}

	/// getMeldedKongType 関数をテストする。
	TEST_F(SetTest, testGetMeldedKongType)
	{
		ASSERT_EQ(MeldedKongTypes::NO, P1P2P3.getMeldedKongType());
		ASSERT_EQ(MeldedKongTypes::NO, P1P2P3R.getMeldedKongType());
		ASSERT_EQ(MeldedKongTypes::NO, P1P2P3_L.getMeldedKongType());
		ASSERT_EQ(MeldedKongTypes::NO, S1S2S3.getMeldedKongType());
		ASSERT_EQ(MeldedKongTypes::NO, S7S8S9.getMeldedKongType());
		ASSERT_EQ(MeldedKongTypes::NO, S8S7S9_L.getMeldedKongType());
		ASSERT_EQ(MeldedKongTypes::NO, M7M8M9.getMeldedKongType());
		ASSERT_EQ(MeldedKongTypes::NO, P1P1.getMeldedKongType());
		ASSERT_EQ(MeldedKongTypes::NO, S1S1.getMeldedKongType());
		ASSERT_EQ(MeldedKongTypes::NO, P1P1P1.getMeldedKongType());
		ASSERT_EQ(MeldedKongTypes::NO, P1P1P1_L.getMeldedKongType());
		ASSERT_EQ(MeldedKongTypes::NO, M1M1M1.getMeldedKongType());
		ASSERT_EQ(MeldedKongTypes::NO, TNTNTN_A.getMeldedKongType());
		ASSERT_EQ(MeldedKongTypes::NO, TNTNTN_R.getMeldedKongType());
		ASSERT_EQ(MeldedKongTypes::NO, P1P1P1P1.getMeldedKongType());
		ASSERT_EQ(MeldedKongTypes::LITTLE, P1P1P1P1_LL.getMeldedKongType());
		ASSERT_EQ(MeldedKongTypes::BIG, P1P1P1P1_BL.getMeldedKongType());
	}

	/// get(Tiles()) 関数をテストする。
	TEST_F(SetTest, testGetTiles)
	{
		ASSERT_EQ((Set::Tiles{ P1, P2, P3 }), P1P2P3.getTiles());
		ASSERT_EQ((Set::Tiles{ P1, P2, Tile(TileDesigns::CIRCLES, 3, TileAttributes::RED) }), P1P2P3R.getTiles());
		ASSERT_EQ((Set::Tiles{ P1, P2, P3 }), P1P2P3_L.getTiles());
		ASSERT_EQ((Set::Tiles{ S1, S2, S3 }), S1S2S3.getTiles());
		ASSERT_EQ((Set::Tiles{ S7, S8, S9 }), S7S8S9.getTiles());
		ASSERT_EQ((Set::Tiles{ S8, S7, S9 }), S8S7S9_L.getTiles());
		ASSERT_EQ((Set::Tiles{ M7, M8, M9 }), M7M8M9.getTiles());
		ASSERT_EQ((Set::Tiles{ P1, P1 }), P1P1.getTiles());
		ASSERT_EQ((Set::Tiles{ S1, S1 }), S1S1.getTiles());
		ASSERT_EQ((Set::Tiles{ P1, P1, P1 }), P1P1P1.getTiles());
		ASSERT_EQ((Set::Tiles{ P1, P1, P1 }), P1P1P1_L.getTiles());
		ASSERT_EQ((Set::Tiles{ M1, M1, M1 }), M1M1M1.getTiles());
		ASSERT_EQ((Set::Tiles{ TN, TN, TN }), TNTNTN_A.getTiles());
		ASSERT_EQ((Set::Tiles{ TN, TN, TN }), TNTNTN_R.getTiles());
		ASSERT_EQ((Set::Tiles{ P1, P1, P1, P1 }), P1P1P1P1.getTiles());
		ASSERT_EQ((Set::Tiles{ P1, P1, P1, P1 }), P1P1P1P1_LL.getTiles());
		ASSERT_EQ((Set::Tiles{ P1, P1, P1, P1 }), P1P1P1P1_BL.getTiles());
	}

	/// isChow 関数をテストする。
	TEST_F(SetTest, testIsChow)
	{
		ASSERT_TRUE(P1P2P3.isChow());
		ASSERT_TRUE(P1P2P3R.isChow());
		ASSERT_TRUE(P1P2P3_L.isChow());
		ASSERT_TRUE(S1S2S3.isChow());
		ASSERT_TRUE(S7S8S9.isChow());
		ASSERT_TRUE(S8S7S9_L.isChow());
		ASSERT_TRUE(M7M8M9.isChow());
		ASSERT_FALSE(P1P1.isChow());
		ASSERT_FALSE(S1S1.isChow());
		ASSERT_FALSE(P1P1P1.isChow());
		ASSERT_FALSE(P1P1P1_L.isChow());
		ASSERT_FALSE(M1M1M1.isChow());
		ASSERT_FALSE(TNTNTN_A.isChow());
		ASSERT_FALSE(TNTNTN_R.isChow());
		ASSERT_FALSE(P1P1P1P1.isChow());
		ASSERT_FALSE(P1P1P1P1_LL.isChow());
		ASSERT_FALSE(P1P1P1P1_BL.isChow());
	}

	/// isPair 関数をテストする。
	TEST_F(SetTest, testIsPair)
	{
		ASSERT_FALSE(P1P2P3.isPair());
		ASSERT_FALSE(P1P2P3R.isPair());
		ASSERT_FALSE(P1P2P3_L.isPair());
		ASSERT_FALSE(S1S2S3.isPair());
		ASSERT_FALSE(S7S8S9.isPair());
		ASSERT_FALSE(S8S7S9_L.isPair());
		ASSERT_FALSE(M7M8M9.isPair());
		ASSERT_TRUE(P1P1.isPair());
		ASSERT_TRUE(S1S1.isPair());
		ASSERT_FALSE(P1P1P1.isPair());
		ASSERT_FALSE(P1P1P1_L.isPair());
		ASSERT_FALSE(M1M1M1.isPair());
		ASSERT_FALSE(TNTNTN_A.isPair());
		ASSERT_FALSE(TNTNTN_R.isPair());
		ASSERT_FALSE(P1P1P1P1.isPair());
		ASSERT_FALSE(P1P1P1P1_LL.isPair());
		ASSERT_FALSE(P1P1P1P1_BL.isPair());
	}

	/// isPung 関数をテストする。
	TEST_F(SetTest, testIsPung)
	{
		ASSERT_FALSE(P1P2P3.isPung());
		ASSERT_FALSE(P1P2P3R.isPung());
		ASSERT_FALSE(P1P2P3_L.isPung());
		ASSERT_FALSE(S1S2S3.isPung());
		ASSERT_FALSE(S7S8S9.isPung());
		ASSERT_FALSE(S8S7S9_L.isPung());
		ASSERT_FALSE(M7M8M9.isPung());
		ASSERT_FALSE(P1P1.isPung());
		ASSERT_FALSE(S1S1.isPung());
		ASSERT_TRUE(P1P1P1.isPung());
		ASSERT_TRUE(P1P1P1_L.isPung());
		ASSERT_TRUE(M1M1M1.isPung());
		ASSERT_TRUE(TNTNTN_A.isPung());
		ASSERT_TRUE(TNTNTN_R.isPung());
		ASSERT_FALSE(P1P1P1P1.isPung());
		ASSERT_FALSE(P1P1P1P1_LL.isPung());
		ASSERT_FALSE(P1P1P1P1_BL.isPung());
	}

	/// isKong 関数をテストする。
	TEST_F(SetTest, testIsKong)
	{
		ASSERT_FALSE(P1P2P3.isKong());
		ASSERT_FALSE(P1P2P3R.isKong());
		ASSERT_FALSE(P1P2P3_L.isKong());
		ASSERT_FALSE(S1S2S3.isKong());
		ASSERT_FALSE(S7S8S9.isKong());
		ASSERT_FALSE(S8S7S9_L.isKong());
		ASSERT_FALSE(M7M8M9.isKong());
		ASSERT_FALSE(P1P1.isKong());
		ASSERT_FALSE(S1S1.isKong());
		ASSERT_FALSE(P1P1P1.isKong());
		ASSERT_FALSE(P1P1P1_L.isKong());
		ASSERT_FALSE(M1M1M1.isKong());
		ASSERT_FALSE(TNTNTN_A.isKong());
		ASSERT_FALSE(TNTNTN_R.isKong());
		ASSERT_TRUE(P1P1P1P1.isKong());
		ASSERT_TRUE(P1P1P1P1_LL.isKong());
		ASSERT_TRUE(P1P1P1P1_BL.isKong());
	}

	/// isConcealed 関数をテストする。
	TEST_F(SetTest, testIsConcealed)
	{
		ASSERT_TRUE(P1P2P3.isConcealed());
		ASSERT_TRUE(P1P2P3R.isConcealed());
		ASSERT_FALSE(P1P2P3_L.isConcealed());
		ASSERT_TRUE(S1S2S3.isConcealed());
		ASSERT_TRUE(S7S8S9.isConcealed());
		ASSERT_FALSE(S8S7S9_L.isConcealed());
		ASSERT_TRUE(M7M8M9.isConcealed());
		ASSERT_TRUE(P1P1.isConcealed());
		ASSERT_TRUE(S1S1.isConcealed());
		ASSERT_TRUE(P1P1P1.isConcealed());
		ASSERT_FALSE(P1P1P1_L.isConcealed());
		ASSERT_TRUE(M1M1M1.isConcealed());
		ASSERT_FALSE(TNTNTN_A.isConcealed());
		ASSERT_FALSE(TNTNTN_R.isConcealed());
		ASSERT_TRUE(P1P1P1P1.isConcealed());
		ASSERT_FALSE(P1P1P1P1_LL.isConcealed());
		ASSERT_FALSE(P1P1P1P1_BL.isConcealed());
	}

	/// isMelded 関数をテストする。
	TEST_F(SetTest, testIsMelded)
	{
		ASSERT_FALSE(P1P2P3.isMelded());
		ASSERT_FALSE(P1P2P3R.isMelded());
		ASSERT_TRUE(P1P2P3_L.isMelded());
		ASSERT_FALSE(S1S2S3.isMelded());
		ASSERT_FALSE(S7S8S9.isMelded());
		ASSERT_TRUE(S8S7S9_L.isMelded());
		ASSERT_FALSE(M7M8M9.isMelded());
		ASSERT_FALSE(P1P1.isMelded());
		ASSERT_FALSE(S1S1.isMelded());
		ASSERT_FALSE(P1P1P1.isMelded());
		ASSERT_TRUE(P1P1P1_L.isMelded());
		ASSERT_FALSE(M1M1M1.isMelded());
		ASSERT_TRUE(TNTNTN_A.isMelded());
		ASSERT_TRUE(TNTNTN_R.isMelded());
		ASSERT_FALSE(P1P1P1P1.isMelded());
		ASSERT_TRUE(P1P1P1P1_LL.isMelded());
		ASSERT_TRUE(P1P1P1P1_BL.isMelded());
	}

	/// == 演算子をテストする。
	TEST_F(SetTest, testEquals)
	{
		// 自身と比較する。
		ASSERT_TRUE(P1P2P3 == P1P2P3);
		ASSERT_TRUE(P1P2P3R == P1P2P3R);
		ASSERT_TRUE(P1P2P3_L == P1P2P3_L);
		ASSERT_TRUE(S1S2S3 == S1S2S3);
		ASSERT_TRUE(S7S8S9 == S7S8S9);
		ASSERT_TRUE(S8S7S9_L == S8S7S9_L);
		ASSERT_TRUE(M7M8M9 == M7M8M9);
		ASSERT_TRUE(P1P1 == P1P1);
		ASSERT_TRUE(S1S1 == S1S1);
		ASSERT_TRUE(P1P1P1 == P1P1P1);
		ASSERT_TRUE(P1P1P1_L == P1P1P1_L);
		ASSERT_TRUE(M1M1M1 == M1M1M1);
		ASSERT_TRUE(TNTNTN_A == TNTNTN_A);
		ASSERT_TRUE(TNTNTN_R == TNTNTN_R);
		ASSERT_TRUE(P1P1P1P1 == P1P1P1P1);
		ASSERT_TRUE(P1P1P1P1_LL == P1P1P1P1_LL);
		ASSERT_TRUE(P1P1P1P1_BL == P1P1P1P1_BL);

		// 同じ面子と比較する。
		ASSERT_TRUE(P1P2P3 == Set(P1, P2, P3));
		ASSERT_TRUE(P1P2P3R == Set(P1, P2, Tile(TileDesigns::CIRCLES, 3, TileAttributes::RED)));
		ASSERT_TRUE(P1P2P3_L == Set(P1, P2, P3, MeldTypes::LEFT));
		ASSERT_TRUE(S1S2S3 == Set(S1, S2, S3));
		ASSERT_TRUE(S7S8S9 == Set(S7, S8, S9));
		ASSERT_TRUE(S8S7S9_L == Set(S8, S7, S9, MeldTypes::LEFT));
		ASSERT_TRUE(M7M8M9 == Set(M7, M8, M9));
		ASSERT_TRUE(P1P1 == Set(P1, P1));
		ASSERT_TRUE(S1S1 == Set(S1, S1));
		ASSERT_TRUE(P1P1P1 == Set(P1, P1, P1));
		ASSERT_TRUE(P1P1P1_L == Set(P1, P1, P1, MeldTypes::LEFT));
		ASSERT_TRUE(M1M1M1 == Set(M1, M1, M1));
		ASSERT_TRUE(TNTNTN_A == Set(TN, TN, TN, MeldTypes::ACROSS));
		ASSERT_TRUE(TNTNTN_R == Set(TN, TN, TN, MeldTypes::RIGHT));
		ASSERT_TRUE(P1P1P1P1 == Set(P1, P1, P1, P1));
		ASSERT_TRUE(P1P1P1P1_LL == Set(P1, P1, P1, P1, MeldedKongTypes::LITTLE, MeldTypes::LEFT));
		ASSERT_TRUE(P1P1P1P1_BL == Set(P1, P1, P1, P1, MeldedKongTypes::BIG, MeldTypes::LEFT));

		// 異なる面子と比較する。
		vector<Set> sets{ P1P2P3, P1P2P3R, P1P2P3_L, S1S2S3, S7S8S9, S8S7S9_L, M7M8M9, P1P1, S1S1, P1P1P1, P1P1P1_L, M1M1M1, TNTNTN_A, TNTNTN_R, P1P1P1P1, P1P1P1P1_LL, P1P1P1P1_BL };
		for (size_t i = 0; i < sets.size(); ++i) {
			for (size_t j = 0; j < sets.size(); ++j) {
				if (i != j) {
					ASSERT_FALSE(sets[i] == sets[j]);
				}
			}
		}
	}

	/// != 演算子をテストする。
	TEST_F(SetTest, testNotEquals)
	{
		// 自身と比較する。
		ASSERT_FALSE(P1P2P3 != P1P2P3);
		ASSERT_FALSE(P1P2P3R != P1P2P3R);
		ASSERT_FALSE(P1P2P3_L != P1P2P3_L);
		ASSERT_FALSE(S1S2S3 != S1S2S3);
		ASSERT_FALSE(S7S8S9 != S7S8S9);
		ASSERT_FALSE(S8S7S9_L != S8S7S9_L);
		ASSERT_FALSE(M7M8M9 != M7M8M9);
		ASSERT_FALSE(P1P1 != P1P1);
		ASSERT_FALSE(S1S1 != S1S1);
		ASSERT_FALSE(P1P1P1 != P1P1P1);
		ASSERT_FALSE(P1P1P1_L != P1P1P1_L);
		ASSERT_FALSE(M1M1M1 != M1M1M1);
		ASSERT_FALSE(TNTNTN_A != TNTNTN_A);
		ASSERT_FALSE(TNTNTN_R != TNTNTN_R);
		ASSERT_FALSE(P1P1P1P1 != P1P1P1P1);
		ASSERT_FALSE(P1P1P1P1_LL != P1P1P1P1_LL);
		ASSERT_FALSE(P1P1P1P1_BL != P1P1P1P1_BL);

		// 同じ面子と比較する。
		ASSERT_FALSE(P1P2P3 != Set(P1, P2, P3));
		ASSERT_FALSE(P1P2P3R != Set(P1, P2, Tile(TileDesigns::CIRCLES, 3, TileAttributes::RED)));
		ASSERT_FALSE(P1P2P3_L != Set(P1, P2, P3, MeldTypes::LEFT));
		ASSERT_FALSE(S1S2S3 != Set(S1, S2, S3));
		ASSERT_FALSE(S7S8S9 != Set(S7, S8, S9));
		ASSERT_FALSE(S8S7S9_L != Set(S8, S7, S9, MeldTypes::LEFT));
		ASSERT_FALSE(M7M8M9 != Set(M7, M8, M9));
		ASSERT_FALSE(P1P1 != Set(P1, P1));
		ASSERT_FALSE(S1S1 != Set(S1, S1));
		ASSERT_FALSE(P1P1P1 != Set(P1, P1, P1));
		ASSERT_FALSE(P1P1P1_L != Set(P1, P1, P1, MeldTypes::LEFT));
		ASSERT_FALSE(M1M1M1 != Set(M1, M1, M1));
		ASSERT_FALSE(TNTNTN_A != Set(TN, TN, TN, MeldTypes::ACROSS));
		ASSERT_FALSE(TNTNTN_R != Set(TN, TN, TN, MeldTypes::RIGHT));
		ASSERT_FALSE(P1P1P1P1 != Set(P1, P1, P1, P1));
		ASSERT_FALSE(P1P1P1P1_LL != Set(P1, P1, P1, P1, MeldedKongTypes::LITTLE, MeldTypes::LEFT));
		ASSERT_FALSE(P1P1P1P1_BL != Set(P1, P1, P1, P1, MeldedKongTypes::BIG, MeldTypes::LEFT));

		// 異なる面子と比較する。
		vector<Set> sets{ P1P2P3, P1P2P3R, P1P2P3_L, S1S2S3, S7S8S9, S8S7S9_L, M7M8M9, P1P1, S1S1, P1P1P1, P1P1P1_L, M1M1M1, TNTNTN_A, TNTNTN_R, P1P1P1P1, P1P1P1P1_LL, P1P1P1P1_BL };
		for (size_t i = 0; i < sets.size(); ++i) {
			for (size_t j = 0; j < sets.size(); ++j) {
				if (i != j) {
					ASSERT_TRUE(sets[i] != sets[j]);
				}
			}
		}
	}
}
