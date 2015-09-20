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
#include <OpenRiichiAssertion.h>
#include <Tile.h>


using namespace std;


namespace openriichi
{
	class TileTest : public ::testing::Test
	{
	protected:
		Tile P1;
		Tile P1R;
		Tile P3;
		Tile P9;
		Tile S1;
		Tile S5;
		Tile S5R;
		Tile S9;
		Tile M1;
		Tile M7;
		Tile M9;
		Tile M9R;
		Tile TN;
		Tile TNR;
		Tile NN;
		Tile SH;
		Tile PE;
		Tile CH;
		Tile CHR;
		Tile HK;
		Tile HT;

	protected:
		TileTest()
			: P1(TileDesigns::CIRCLES, 1)
			, P1R(TileDesigns::CIRCLES, 1, TileAttributes::RED)
			, P3(TileDesigns::CIRCLES, 3)
			, P9(TileDesigns::CIRCLES, 9)
			, S1(TileDesigns::BAMBOO, 1)
			, S5(TileDesigns::BAMBOO, 5)
			, S5R(TileDesigns::BAMBOO, 5, TileAttributes::RED)
			, S9(TileDesigns::BAMBOO, 9)
			, M1(TileDesigns::CHARACTERS, 1)
			, M7(TileDesigns::CHARACTERS, 7)
			, M9(TileDesigns::CHARACTERS, 9)
			, M9R(TileDesigns::CHARACTERS, 9, TileAttributes::RED)
			, TN(TileDesigns::EAST)
			, TNR(TileDesigns::EAST, TileAttributes::RED)
			, NN(TileDesigns::SOUTH)
			, SH(TileDesigns::WEST)
			, PE(TileDesigns::NORTH)
			, CH(TileDesigns::RED)
			, CHR(TileDesigns::RED, TileAttributes::RED)
			, HK(TileDesigns::WHITE)
			, HT(TileDesigns::GREEN)
		{}
	};

	/// コンストラクタ (字牌用) をテストする。
	TEST_F(TileTest, testConstructForHonours)
	{
#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		ASSERT_THROW((Tile(TileDesigns::CIRCLES)), OpenRiichiAssertion);
		// ASSERT_THROW((Tile(TileDesigns::EAST, TileAttributeTemplate<2>())), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	}

	/// コンストラクタ (数牌用) をテストする。
	TEST_F(TileTest, testConstructForSuits)
	{
#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		ASSERT_THROW(Tile(TileDesigns::EAST, 1), OpenRiichiAssertion);
		ASSERT_THROW(Tile(TileDesigns::CIRCLES, 0), OpenRiichiAssertion);
		ASSERT_THROW(Tile(TileDesigns::CIRCLES, 10), OpenRiichiAssertion);
		// ASSERT_THROW((Tile(TileDesigns::CIRCLES, 1, TileAttributeTemplate<2>())), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	}

	/// ID を用いた牌の生成をテストする。
	TEST_F(TileTest, testConstructWithId)
	{
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 1), Tile(1, 1));
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 1, TileAttributes::RED), Tile(1, 1, 1));
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 3), Tile(1, 3));
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 9), Tile(1, 9));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), Tile(2, 1));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 5), Tile(2, 5));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 5, TileAttributes::RED), Tile(2, 5, 1));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), Tile(2, 9));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 1), Tile(3, 1));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 7), Tile(3, 7));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 9), Tile(3, 9));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 9, TileAttributes::RED), Tile(3, 9, 1));
		ASSERT_EQ(Tile(TileDesigns::EAST), Tile(4, 0));
		ASSERT_EQ(Tile(TileDesigns::EAST, TileAttributes::RED), Tile(4, 0, 1));
		ASSERT_EQ(Tile(TileDesigns::SOUTH), Tile(5, 0));
		ASSERT_EQ(Tile(TileDesigns::WEST), Tile(6, 0));
		ASSERT_EQ(Tile(TileDesigns::NORTH), Tile(7, 0));
		ASSERT_EQ(Tile(TileDesigns::RED), Tile(8, 0));
		ASSERT_EQ(Tile(TileDesigns::RED, TileAttributes::RED), Tile(8, 0, 1));
		ASSERT_EQ(Tile(TileDesigns::WHITE), Tile(9, 0));
		ASSERT_EQ(Tile(TileDesigns::GREEN), Tile(10, 0));

#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		ASSERT_THROW(Tile(0, 0, 0), OpenRiichiAssertion);
		ASSERT_THROW(Tile(11, 0, 0), OpenRiichiAssertion);
		ASSERT_THROW(Tile(1, 0, 0), OpenRiichiAssertion);
		ASSERT_THROW(Tile(3, 0, 0), OpenRiichiAssertion);
		ASSERT_THROW(Tile(4, 1, 0), OpenRiichiAssertion);
		ASSERT_THROW(Tile(10, 1, 0), OpenRiichiAssertion);
		ASSERT_THROW(Tile(1, 1, -1), OpenRiichiAssertion);
		ASSERT_THROW(Tile(1, 1, 2), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	}

	/// getDesign 関数をテストする。
	TEST_F(TileTest, testGetDesign)
	{
		ASSERT_EQ(TileDesigns::CIRCLES, P1R.getDesign());
		ASSERT_EQ(TileDesigns::CIRCLES, P3.getDesign());
		ASSERT_EQ(TileDesigns::CIRCLES, P9.getDesign());
		ASSERT_EQ(TileDesigns::BAMBOO, S1.getDesign());
		ASSERT_EQ(TileDesigns::BAMBOO, S5R.getDesign());
		ASSERT_EQ(TileDesigns::BAMBOO, S9.getDesign());
		ASSERT_EQ(TileDesigns::CHARACTERS, M1.getDesign());
		ASSERT_EQ(TileDesigns::CHARACTERS, M7.getDesign());
		ASSERT_EQ(TileDesigns::CHARACTERS, M9R.getDesign());
		ASSERT_EQ(TileDesigns::EAST, TNR.getDesign());
		ASSERT_EQ(TileDesigns::SOUTH, NN.getDesign());
		ASSERT_EQ(TileDesigns::WEST, SH.getDesign());
		ASSERT_EQ(TileDesigns::NORTH, PE.getDesign());
		ASSERT_EQ(TileDesigns::RED, CHR.getDesign());
		ASSERT_EQ(TileDesigns::WHITE, HK.getDesign());
		ASSERT_EQ(TileDesigns::GREEN, HT.getDesign());
	}

	/// getNumber 関数をテストする。
	TEST_F(TileTest, testGetNumber)
	{
		ASSERT_EQ(1, P1R.getNumber());
		ASSERT_EQ(3, P3.getNumber());
		ASSERT_EQ(9, P9.getNumber());
		ASSERT_EQ(1, S1.getNumber());
		ASSERT_EQ(5, S5R.getNumber());
		ASSERT_EQ(9, S9.getNumber());
		ASSERT_EQ(1, M1.getNumber());
		ASSERT_EQ(7, M7.getNumber());
		ASSERT_EQ(9, M9R.getNumber());
		ASSERT_EQ(0, TNR.getNumber());
		ASSERT_EQ(0, NN.getNumber());
		ASSERT_EQ(0, SH.getNumber());
		ASSERT_EQ(0, PE.getNumber());
		ASSERT_EQ(0, CHR.getNumber());
		ASSERT_EQ(0, HK.getNumber());
		ASSERT_EQ(0, HT.getNumber());
	}

	/// getAttribute 関数をテストする。
	TEST_F(TileTest, testGetAttribute)
	{
		ASSERT_EQ(TileAttributes::RED, P1R.getAttribute());
		ASSERT_EQ(TileAttributes::NONE, P3.getAttribute());
		ASSERT_EQ(TileAttributes::NONE, P9.getAttribute());
		ASSERT_EQ(TileAttributes::NONE, S1.getAttribute());
		ASSERT_EQ(TileAttributes::RED, S5R.getAttribute());
		ASSERT_EQ(TileAttributes::NONE, S9.getAttribute());
		ASSERT_EQ(TileAttributes::NONE, M1.getAttribute());
		ASSERT_EQ(TileAttributes::NONE, M7.getAttribute());
		ASSERT_EQ(TileAttributes::RED, M9R.getAttribute());
		ASSERT_EQ(TileAttributes::RED, TNR.getAttribute());
		ASSERT_EQ(TileAttributes::NONE, NN.getAttribute());
		ASSERT_EQ(TileAttributes::NONE, SH.getAttribute());
		ASSERT_EQ(TileAttributes::NONE, PE.getAttribute());
		ASSERT_EQ(TileAttributes::RED, CHR.getAttribute());
		ASSERT_EQ(TileAttributes::NONE, HK.getAttribute());
		ASSERT_EQ(TileAttributes::NONE, HT.getAttribute());
	}

	/// isSuits 関数をテストする。
	TEST_F(TileTest, testIsSuits)
	{
		ASSERT_TRUE(P1R.isSuits());
		ASSERT_TRUE(P3.isSuits());
		ASSERT_TRUE(P9.isSuits());
		ASSERT_TRUE(S1.isSuits());
		ASSERT_TRUE(S5R.isSuits());
		ASSERT_TRUE(S9.isSuits());
		ASSERT_TRUE(M1.isSuits());
		ASSERT_TRUE(M7.isSuits());
		ASSERT_TRUE(M9R.isSuits());
		ASSERT_FALSE(TNR.isSuits());
		ASSERT_FALSE(NN.isSuits());
		ASSERT_FALSE(SH.isSuits());
		ASSERT_FALSE(PE.isSuits());
		ASSERT_FALSE(CHR.isSuits());
		ASSERT_FALSE(HK.isSuits());
		ASSERT_FALSE(HT.isSuits());
	}

	/// isHonours 関数をテストする。
	TEST_F(TileTest, testIsHonours)
	{
		ASSERT_FALSE(P1R.isHonours());
		ASSERT_FALSE(P3.isHonours());
		ASSERT_FALSE(P9.isHonours());
		ASSERT_FALSE(S1.isHonours());
		ASSERT_FALSE(S5R.isHonours());
		ASSERT_FALSE(S9.isHonours());
		ASSERT_FALSE(M1.isHonours());
		ASSERT_FALSE(M7.isHonours());
		ASSERT_FALSE(M9R.isHonours());
		ASSERT_TRUE(TNR.isHonours());
		ASSERT_TRUE(NN.isHonours());
		ASSERT_TRUE(SH.isHonours());
		ASSERT_TRUE(PE.isHonours());
		ASSERT_TRUE(CHR.isHonours());
		ASSERT_TRUE(HK.isHonours());
		ASSERT_TRUE(HT.isHonours());
	}

	/// isWinds 関数をテストする。
	TEST_F(TileTest, testIsWinds)
	{
		ASSERT_FALSE(P1R.isWinds());
		ASSERT_FALSE(P3.isWinds());
		ASSERT_FALSE(P9.isWinds());
		ASSERT_FALSE(S1.isWinds());
		ASSERT_FALSE(S5R.isWinds());
		ASSERT_FALSE(S9.isWinds());
		ASSERT_FALSE(M1.isWinds());
		ASSERT_FALSE(M7.isWinds());
		ASSERT_FALSE(M9R.isWinds());
		ASSERT_TRUE(TNR.isWinds());
		ASSERT_TRUE(NN.isWinds());
		ASSERT_TRUE(SH.isWinds());
		ASSERT_TRUE(PE.isWinds());
		ASSERT_FALSE(CHR.isWinds());
		ASSERT_FALSE(HK.isWinds());
		ASSERT_FALSE(HT.isWinds());
	}

	/// isDragons 関数をテストする。
	TEST_F(TileTest, testIsDragons)
	{
		ASSERT_FALSE(P1R.isDragons());
		ASSERT_FALSE(P3.isDragons());
		ASSERT_FALSE(P9.isDragons());
		ASSERT_FALSE(S1.isDragons());
		ASSERT_FALSE(S5R.isDragons());
		ASSERT_FALSE(S9.isDragons());
		ASSERT_FALSE(M1.isDragons());
		ASSERT_FALSE(M7.isDragons());
		ASSERT_FALSE(M9R.isDragons());
		ASSERT_FALSE(TNR.isDragons());
		ASSERT_FALSE(NN.isDragons());
		ASSERT_FALSE(SH.isDragons());
		ASSERT_FALSE(PE.isDragons());
		ASSERT_TRUE(CHR.isDragons());
		ASSERT_TRUE(HK.isDragons());
		ASSERT_TRUE(HT.isDragons());
	}

	/// isSimples 関数をテストする。
	TEST_F(TileTest, testIsSimples)
	{
		ASSERT_FALSE(P1R.isSimples());
		ASSERT_TRUE(P3.isSimples());
		ASSERT_FALSE(P9.isSimples());
		ASSERT_FALSE(S1.isSimples());
		ASSERT_TRUE(S5R.isSimples());
		ASSERT_FALSE(S9.isSimples());
		ASSERT_FALSE(M1.isSimples());
		ASSERT_TRUE(M7.isSimples());
		ASSERT_FALSE(M9R.isSimples());
		ASSERT_FALSE(TNR.isSimples());
		ASSERT_FALSE(NN.isSimples());
		ASSERT_FALSE(SH.isSimples());
		ASSERT_FALSE(PE.isSimples());
		ASSERT_FALSE(CHR.isSimples());
		ASSERT_FALSE(HK.isSimples());
		ASSERT_FALSE(HT.isSimples());
	}

	/// isTerminals 関数をテストする。
	TEST_F(TileTest, testIsTerminals)
	{
		ASSERT_TRUE(P1R.isTerminals());
		ASSERT_FALSE(P3.isTerminals());
		ASSERT_TRUE(P9.isTerminals());
		ASSERT_TRUE(S1.isTerminals());
		ASSERT_FALSE(S5R.isTerminals());
		ASSERT_TRUE(S9.isTerminals());
		ASSERT_TRUE(M1.isTerminals());
		ASSERT_FALSE(M7.isTerminals());
		ASSERT_TRUE(M9R.isTerminals());
		ASSERT_FALSE(TNR.isTerminals());
		ASSERT_FALSE(NN.isTerminals());
		ASSERT_FALSE(SH.isTerminals());
		ASSERT_FALSE(PE.isTerminals());
		ASSERT_FALSE(CHR.isTerminals());
		ASSERT_FALSE(HK.isTerminals());
		ASSERT_FALSE(HT.isTerminals());
	}

	/// isTerminalsOrHonours 関数をテストする。
	TEST_F(TileTest, testIsTerminalsOrHonours)
	{
		ASSERT_TRUE(P1R.isTerminalsOrHonours());
		ASSERT_FALSE(P3.isTerminalsOrHonours());
		ASSERT_TRUE(P9.isTerminalsOrHonours());
		ASSERT_TRUE(S1.isTerminalsOrHonours());
		ASSERT_FALSE(S5R.isTerminalsOrHonours());
		ASSERT_TRUE(S9.isTerminalsOrHonours());
		ASSERT_TRUE(M1.isTerminalsOrHonours());
		ASSERT_FALSE(M7.isTerminalsOrHonours());
		ASSERT_TRUE(M9R.isTerminalsOrHonours());
		ASSERT_TRUE(TNR.isTerminalsOrHonours());
		ASSERT_TRUE(NN.isTerminalsOrHonours());
		ASSERT_TRUE(SH.isTerminalsOrHonours());
		ASSERT_TRUE(PE.isTerminalsOrHonours());
		ASSERT_TRUE(CHR.isTerminalsOrHonours());
		ASSERT_TRUE(HK.isTerminalsOrHonours());
		ASSERT_TRUE(HT.isTerminalsOrHonours());
	}

	/// getPreviousTile 関数をテストする。
	TEST_F(TileTest, testGetPreviousTile)
	{
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 9), P1R.getPreviousTile());
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 2), P3.getPreviousTile());
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 8), P9.getPreviousTile());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), S1.getPreviousTile());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 4), S5R.getPreviousTile());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 8), S9.getPreviousTile());
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 9), M1.getPreviousTile());
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 6), M7.getPreviousTile());
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 8), M9.getPreviousTile());
		ASSERT_EQ(Tile(TileDesigns::NORTH), TNR.getPreviousTile());
		ASSERT_EQ(Tile(TileDesigns::EAST), NN.getPreviousTile());
		ASSERT_EQ(Tile(TileDesigns::SOUTH), SH.getPreviousTile());
		ASSERT_EQ(Tile(TileDesigns::WEST), PE.getPreviousTile());
		ASSERT_EQ(Tile(TileDesigns::GREEN), CHR.getPreviousTile());
		ASSERT_EQ(Tile(TileDesigns::RED), HK.getPreviousTile());
		ASSERT_EQ(Tile(TileDesigns::WHITE), HT.getPreviousTile());
	}

	/// getNextTile 関数をテストする。
	TEST_F(TileTest, testGetNextTile)
	{
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 2), P1R.getNextTile());
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 4), P3.getNextTile());
		ASSERT_EQ(Tile(TileDesigns::CIRCLES, 1), P9.getNextTile());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), S1.getNextTile());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 6), S5R.getNextTile());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), S9.getNextTile());
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 2), M1.getNextTile());
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 8), M7.getNextTile());
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 1), M9.getNextTile());
		ASSERT_EQ(Tile(TileDesigns::SOUTH), TNR.getNextTile());
		ASSERT_EQ(Tile(TileDesigns::WEST), NN.getNextTile());
		ASSERT_EQ(Tile(TileDesigns::NORTH), SH.getNextTile());
		ASSERT_EQ(Tile(TileDesigns::EAST), PE.getNextTile());
		ASSERT_EQ(Tile(TileDesigns::WHITE), CHR.getNextTile());
		ASSERT_EQ(Tile(TileDesigns::GREEN), HK.getNextTile());
		ASSERT_EQ(Tile(TileDesigns::RED), HT.getNextTile());
	}

	/// == 演算子をテストする。
	TEST_F(TileTest, testEquals)
	{
		// 自身と比較する。
		ASSERT_TRUE(P1R == P1R);
		ASSERT_TRUE(P3 == P3);
		ASSERT_TRUE(P9 == P9);
		ASSERT_TRUE(S1 == S1);
		ASSERT_TRUE(S5R == S5R);
		ASSERT_TRUE(S9 == S9);
		ASSERT_TRUE(M1 == M1);
		ASSERT_TRUE(M7 == M7);
		ASSERT_TRUE(M9R == M9R);
		ASSERT_TRUE(TNR == TNR);
		ASSERT_TRUE(NN == NN);
		ASSERT_TRUE(SH == SH);
		ASSERT_TRUE(PE == PE);
		ASSERT_TRUE(CHR == CHR);
		ASSERT_TRUE(HK == HK);
		ASSERT_TRUE(HT == HT);

		// 同じ牌と比較する。
		ASSERT_TRUE(P1R == Tile(TileDesigns::CIRCLES, 1, TileAttributes::RED));
		ASSERT_TRUE(P3 == Tile(TileDesigns::CIRCLES, 3));
		ASSERT_TRUE(P9 == Tile(TileDesigns::CIRCLES, 9));
		ASSERT_TRUE(S1 == Tile(TileDesigns::BAMBOO, 1));
		ASSERT_TRUE(S5R == Tile(TileDesigns::BAMBOO, 5, TileAttributes::RED));
		ASSERT_TRUE(S9 == Tile(TileDesigns::BAMBOO, 9));
		ASSERT_TRUE(M1 == Tile(TileDesigns::CHARACTERS, 1));
		ASSERT_TRUE(M7 == Tile(TileDesigns::CHARACTERS, 7));
		ASSERT_TRUE(M9R == Tile(TileDesigns::CHARACTERS, 9, TileAttributes::RED));
		ASSERT_TRUE(TNR == Tile(TileDesigns::EAST, TileAttributes::RED));
		ASSERT_TRUE(NN == Tile(TileDesigns::SOUTH));
		ASSERT_TRUE(SH == Tile(TileDesigns::WEST));
		ASSERT_TRUE(PE == Tile(TileDesigns::NORTH));
		ASSERT_TRUE(CHR == Tile(TileDesigns::RED, TileAttributes::RED));
		ASSERT_TRUE(HK == Tile(TileDesigns::WHITE));
		ASSERT_TRUE(HT == Tile(TileDesigns::GREEN));

		// 異なる牌と比較する。
		vector<Tile> tiles{ P1, P1R, P3, P9, S1, S5, S5R, S9, M1, M7, M9, M9R, TN, TNR, NN, SH, PE, CH, CHR, HK, HT };
		for (size_t i = 0; i < tiles.size(); ++i) {
			for (size_t j = 0; j < tiles.size(); ++j) {
				if (i != j) {
					ASSERT_FALSE(tiles[i] == tiles[j]);
				}
			}
		}
	}

	/// != 演算子をテストする。
	TEST_F(TileTest, testNotEquals)
	{
		// 自身と比較する。
		ASSERT_FALSE(P1R != P1R);
		ASSERT_FALSE(P3 != P3);
		ASSERT_FALSE(P9 != P9);
		ASSERT_FALSE(S1 != S1);
		ASSERT_FALSE(S5R != S5R);
		ASSERT_FALSE(S9 != S9);
		ASSERT_FALSE(M1 != M1);
		ASSERT_FALSE(M7 != M7);
		ASSERT_FALSE(M9R != M9R);
		ASSERT_FALSE(TNR != TNR);
		ASSERT_FALSE(NN != NN);
		ASSERT_FALSE(SH != SH);
		ASSERT_FALSE(PE != PE);
		ASSERT_FALSE(CHR != CHR);
		ASSERT_FALSE(HK != HK);
		ASSERT_FALSE(HT != HT);

		// 同じ牌と比較する。
		ASSERT_FALSE(P1R != Tile(TileDesigns::CIRCLES, 1, TileAttributes::RED));
		ASSERT_FALSE(P3 != Tile(TileDesigns::CIRCLES, 3));
		ASSERT_FALSE(P9 != Tile(TileDesigns::CIRCLES, 9));
		ASSERT_FALSE(S1 != Tile(TileDesigns::BAMBOO, 1));
		ASSERT_FALSE(S5R != Tile(TileDesigns::BAMBOO, 5, TileAttributes::RED));
		ASSERT_FALSE(S9 != Tile(TileDesigns::BAMBOO, 9));
		ASSERT_FALSE(M1 != Tile(TileDesigns::CHARACTERS, 1));
		ASSERT_FALSE(M7 != Tile(TileDesigns::CHARACTERS, 7));
		ASSERT_FALSE(M9R != Tile(TileDesigns::CHARACTERS, 9, TileAttributes::RED));
		ASSERT_FALSE(TNR != Tile(TileDesigns::EAST, TileAttributes::RED));
		ASSERT_FALSE(NN != Tile(TileDesigns::SOUTH));
		ASSERT_FALSE(SH != Tile(TileDesigns::WEST));
		ASSERT_FALSE(PE != Tile(TileDesigns::NORTH));
		ASSERT_FALSE(CHR != Tile(TileDesigns::RED, TileAttributes::RED));
		ASSERT_FALSE(HK != Tile(TileDesigns::WHITE));
		ASSERT_FALSE(HT != Tile(TileDesigns::GREEN));

		// 異なる牌と比較する。
		vector<Tile> tiles{ P1, P1R, P3, P9, S1, S5, S5R, S9, M1, M7, M9, M9R, TN, TNR, NN, SH, PE, CH, CHR, HK, HT };
		for (size_t i = 0; i < tiles.size(); ++i) {
			for (size_t j = 0; j < tiles.size(); ++j) {
				if (i != j) {
					ASSERT_TRUE(tiles[i] != tiles[j]);
				}
			}
		}
	}
}
