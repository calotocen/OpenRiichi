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
#include <Discard.h>
#include <Tiles.h>


using namespace std;


namespace openriichi
{
	class DiscardTest : public ::testing::Test
	{
	protected:
		Discard discard1;
		Discard discard2;
		Discard discard3;
		Discard discard4;
		Discard discard5;

	protected:
		DiscardTest()
			: discard1()
			, discard2(S3, DiscardSources::HELD, false, false)
			, discard3(M7, DiscardSources::DRAWED, false, true)
			, discard4(TN, DiscardSources::HELD, true, false)
			, discard5(CH, DiscardSources::DRAWED, true, true)
		{}
	};

	/// getTile 関数をテストする。
	TEST_F(DiscardTest, testGetTile)
	{
		ASSERT_EQ(P1, discard1.getTile());
		ASSERT_EQ(S3, discard2.getTile());
		ASSERT_EQ(M7, discard3.getTile());
		ASSERT_EQ(TN, discard4.getTile());
		ASSERT_EQ(CH, discard5.getTile());
	}

	/// getSource 関数をテストする。
	TEST_F(DiscardTest, testGetSource)
	{
		ASSERT_EQ(DiscardSources::DRAWED, discard1.getSource());
		ASSERT_EQ(DiscardSources::HELD, discard2.getSource());
		ASSERT_EQ(DiscardSources::DRAWED, discard3.getSource());
		ASSERT_EQ(DiscardSources::HELD, discard4.getSource());
		ASSERT_EQ(DiscardSources::DRAWED, discard5.getSource());
	}

	/// isRiichiDeclared 関数をテストする。
	TEST_F(DiscardTest, testIsRiichiDeclared)
	{
		ASSERT_EQ(false, discard1.isRiichiDeclared());
		ASSERT_EQ(false, discard2.isRiichiDeclared());
		ASSERT_EQ(false, discard3.isRiichiDeclared());
		ASSERT_EQ(true, discard4.isRiichiDeclared());
		ASSERT_EQ(true, discard5.isRiichiDeclared());
	}

	/// isTaken 関数をテストする。
	TEST_F(DiscardTest, testIsTaken)
	{
		ASSERT_EQ(false, discard1.isTaken());
		ASSERT_EQ(false, discard2.isTaken());
		ASSERT_EQ(true, discard3.isTaken());
		ASSERT_EQ(false, discard4.isTaken());
		ASSERT_EQ(true, discard5.isTaken());
	}


	/// 捨て牌をテストする。
	TEST_F(DiscardTest, testDiscard)
	{
		Discard discard1;
		ASSERT_EQ(Tile(), discard1.getTile());
		ASSERT_EQ(DiscardSources::DRAWED, discard1.getSource());
		ASSERT_EQ(false, discard1.isRiichiDeclared());
		ASSERT_EQ(false, discard1.isTaken());

		Discard discard2(Tile(TileDesigns::BAMBOO, 3), DiscardSources::HELD, false, false);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), discard2.getTile());
		ASSERT_EQ(DiscardSources::HELD, discard2.getSource());
		ASSERT_EQ(false, discard2.isRiichiDeclared());
		ASSERT_EQ(false, discard2.isTaken());

		Discard discard3(Tile(TileDesigns::CHARACTERS, 7), DiscardSources::DRAWED, false, true);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 7), discard3.getTile());
		ASSERT_EQ(DiscardSources::DRAWED, discard3.getSource());
		ASSERT_EQ(false, discard3.isRiichiDeclared());
		ASSERT_EQ(true, discard3.isTaken());

		Discard discard4(Tile(TileDesigns::EAST), DiscardSources::HELD, true, false);
		ASSERT_EQ(Tile(TileDesigns::EAST), discard4.getTile());
		ASSERT_EQ(DiscardSources::HELD, discard4.getSource());
		ASSERT_EQ(true, discard4.isRiichiDeclared());
		ASSERT_EQ(false, discard4.isTaken());

		Discard discard5(Tile(TileDesigns::RED), DiscardSources::DRAWED, true, true);
		ASSERT_EQ(Tile(TileDesigns::RED), discard5.getTile());
		ASSERT_EQ(DiscardSources::DRAWED, discard5.getSource());
		ASSERT_EQ(true, discard5.isRiichiDeclared());
		ASSERT_EQ(true, discard5.isTaken());
	}

	/// == 演算子をテストする。
	TEST_F(DiscardTest, testEquals)
	{
		// 自身と比較する。
		ASSERT_TRUE(discard1 == discard1);
		ASSERT_TRUE(discard2 == discard2);
		ASSERT_TRUE(discard3 == discard3);
		ASSERT_TRUE(discard4 == discard4);
		ASSERT_TRUE(discard5 == discard5);

		// 同じ捨て牌と比較する。
		ASSERT_TRUE(discard1 == Discard());
		ASSERT_TRUE(discard2 == Discard(S3, DiscardSources::HELD, false, false));
		ASSERT_TRUE(discard3 == Discard(M7, DiscardSources::DRAWED, false, true));
		ASSERT_TRUE(discard4 == Discard(TN, DiscardSources::HELD, true, false));
		ASSERT_TRUE(discard5 == Discard(CH, DiscardSources::DRAWED, true, true));

		// 異なる捨て牌と比較する。
		vector<Discard> discards{ discard1, discard2, discard3, discard4, discard5 };
		for (auto i = 0; i < discards.size(); ++i) {
			for (auto j = 0; j < discards.size(); ++j) {
				if (i != j) {
					ASSERT_FALSE(discards[i] == discards[j]);
				}
			}
		}
	}

	/// != 演算子をテストする。
	TEST_F(DiscardTest, testNotEquals)
	{
		// 自身と比較する。
		ASSERT_FALSE(discard1 != discard1);
		ASSERT_FALSE(discard2 != discard2);
		ASSERT_FALSE(discard3 != discard3);
		ASSERT_FALSE(discard4 != discard4);
		ASSERT_FALSE(discard5 != discard5);

		// 同じ捨て牌と比較する。
		ASSERT_FALSE(discard1 != Discard());
		ASSERT_FALSE(discard2 != Discard(S3, DiscardSources::HELD, false, false));
		ASSERT_FALSE(discard3 != Discard(M7, DiscardSources::DRAWED, false, true));
		ASSERT_FALSE(discard4 != Discard(TN, DiscardSources::HELD, true, false));
		ASSERT_FALSE(discard5 != Discard(CH, DiscardSources::DRAWED, true, true));

		// 異なる捨て牌と比較する。
		vector<Discard> discards{ discard1, discard2, discard3, discard4, discard5 };
		for (auto i = 0; i < discards.size(); ++i) {
			for (auto j = 0; j < discards.size(); ++j) {
				if (i != j) {
					ASSERT_TRUE(discards[i] != discards[j]);
				}
			}
		}
	}
}
