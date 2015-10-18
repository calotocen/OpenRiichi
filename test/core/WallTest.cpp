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
#include <OpenRiichi.h>


using namespace std;


namespace openriichi
{
	class WallTest : public ::testing::Test
	{
	protected:
		Wall::Tiles TILES1;
		Wall::Tiles TILES2;

	protected:
		WallTest()
			: TILES1()
			, TILES2()
		{
			TILES1 = {
				P1, P1, P1, P1, P2, P2, P2, P2, P3, P3, P3, P3, P4, P4, P4, P4, P5, P5, P5, P5, P6, P6, P6, P6, P7, P7, P7, P7, P8, P8, P8, P8, P9, P9, P9, P9,
				S1, S1, S1, S1, S2, S2, S2, S2, S3, S3, S3, S3, S4, S4, S4, S4, S5, S5, S5, S5, S6, S6, S6, S6, S7, S7, S7, S7, S8, S8, S8, S8, S9, S9, S9, S9,
				M1, M1, M1, M1, M2, M2, M2, M2, M3, M3, M3, M3, M4, M4, M4, M4, M5, M5, M5, M5, M6, M6, M6, M6, M7, M7, M7, M7, M8, M8, M8, M8, M9, M9, M9, M9,
				TN, TN, TN, TN, NN, NN, NN, NN, SH, SH, SH, SH, PE, PE, PE, PE,
				CH, CH, CH, CH, HK, HK, HK, HK, HT, HT, HT, HT,
			};

			TILES2 = {
				CH, CH, CH, CH, HK, HK, HK, HK, HT, HT, HT, HT,
				TN, TN, TN, TN, NN, NN, NN, NN, SH, SH, SH, SH, PE, PE, PE, PE,
				M1, M1, M1, M1, M2, M2, M2, M2, M3, M3, M3, M3, M4, M4, M4, M4, M5, M5, M5, M5, M6, M6, M6, M6, M7, M7, M7, M7, M8, M8, M8, M8, M9, M9, M9, M9,
				S1, S1, S1, S1, S2, S2, S2, S2, S3, S3, S3, S3, S4, S4, S4, S4, S5, S5, S5, S5, S6, S6, S6, S6, S7, S7, S7, S7, S8, S8, S8, S8, S9, S9, S9, S9,
				P1, P1, P1, P1, P2, P2, P2, P2, P3, P3, P3, P3, P4, P4, P4, P4, P5, P5, P5, P5, P6, P6, P6, P6, P7, P7, P7, P7, P8, P8, P8, P8, P9, P9, P9, P9,
			};
		}
	};

	/// コンストラクタ (牌指定) をテストする。
	TEST_F(WallTest, testConstructorWithTiles)
	{
#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		ASSERT_THROW(SimpleWall(SimpleWall::Tiles{
			P1, P1, P1, P1, P2, P2, P2, P2, P3, P3, P3, P3, P4, P4, P4, P4, P5, P5, P5, P5, P6, P6, P6, P6, P7, P7, P7, P7, P8, P8, P8, P8, P9, P9, P9, P9,
			S1, S1, S1, S1, S2, S2, S2, S2, S3, S3, S3, S3, S4, S4, S4, S4, S5, S5, S5, S5, S6, S6, S6, S6, S7, S7, S7, S7, S8, S8, S8, S8, S9, S9, S9, S9,
			M1, M1, M1, M1, M2, M2, M2, M2, M3, M3, M3, M3, M4, M4, M4, M4, M5, M5, M5, M5, M6, M6, M6, M6, M7, M7, M7, M7, M8, M8, M8, M8, M9, M9, M9, M9,
			TN, TN, TN, TN, NN, NN, NN, NN, SH, SH, SH, SH, PE, PE, PE, PE,
			CH, CH, CH, CH, HK, HK, HK, HK, HT, HT, HT
		}), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	}

	/// == 演算子をテストする。
	TEST_F(WallTest, testEquals)
	{
		Wall wall1a;
		Wall wall1b(TILES1);
		Wall wall2a(TILES2);
		Wall wall2b(TILES2);
		Wall wall3a(TILES2);
		Wall wall3b(TILES2);
		Wall wall4a(TILES2);
		Wall wall4b(TILES2);
		Wall wall5a(TILES2);
		Wall wall5b(TILES2);

		wall3a.revealNewDora();
		wall3b.revealNewDora();
		wall4a.draw();
		wall4b.draw();
		wall5a.drawReplacementTile();
		wall5b.drawReplacementTile();

		// 自身と比較する。
		ASSERT_TRUE(wall1a == wall1a);
		ASSERT_TRUE(wall1b == wall1b);
		ASSERT_TRUE(wall2a == wall2a);
		ASSERT_TRUE(wall3a == wall3a);
		ASSERT_TRUE(wall4a == wall4a);
		ASSERT_TRUE(wall5a == wall5a);

		// 同じ山と比較する。
		ASSERT_TRUE(wall1a == Wall());
		ASSERT_TRUE(wall1a == wall1b);
		ASSERT_TRUE(wall2a == wall2b);
		ASSERT_TRUE(wall3a == wall3b);
		ASSERT_TRUE(wall4a == wall4b);
		ASSERT_TRUE(wall5a == wall5b);

		// 異なる山と比較する。
		vector<Wall> walls{ wall1a, wall2a, wall3a, wall4a, wall5a };
		for (size_t i = 0; i < walls.size(); ++i) {
			for (size_t j = 0; j < walls.size(); ++j) {
				if (i != j) {
					ASSERT_TRUE(walls[i] != walls[j]);
				}
			}
		}
	}

	/// != 演算子をテストする。
	TEST_F(WallTest, testNotEquals)
	{
		Wall wall1a;
		Wall wall1b(TILES1);
		Wall wall2a(TILES2);
		Wall wall2b(TILES2);
		Wall wall3a(TILES2);
		Wall wall3b(TILES2);
		Wall wall4a(TILES2);
		Wall wall4b(TILES2);
		Wall wall5a(TILES2);
		Wall wall5b(TILES2);

		wall3a.revealNewDora();
		wall3b.revealNewDora();
		wall4a.draw();
		wall4b.draw();
		wall5a.drawReplacementTile();
		wall5b.drawReplacementTile();

		// 自身と比較する。
		ASSERT_FALSE(wall1a != wall1a);
		ASSERT_FALSE(wall1b != wall1b);
		ASSERT_FALSE(wall2a != wall2a);
		ASSERT_FALSE(wall3a != wall3a);
		ASSERT_FALSE(wall4a != wall4a);
		ASSERT_FALSE(wall5a != wall5a);

		// 同じ山と比較する。
		ASSERT_FALSE(wall1a != Wall());
		ASSERT_FALSE(wall1a != wall1b);
		ASSERT_FALSE(wall2a != wall2b);
		ASSERT_FALSE(wall3a != wall3b);
		ASSERT_FALSE(wall4a != wall4b);
		ASSERT_FALSE(wall5a != wall5b);

		// 異なる山と比較する。
		vector<Wall> walls{ wall1a, wall2a, wall3a, wall4a, wall5a };
		for (size_t i = 0; i < walls.size(); ++i) {
			for (size_t j = 0; j < walls.size(); ++j) {
				if (i != j) {
					ASSERT_TRUE(walls[i] != walls[j]);
				}
			}
		}
	}

	/// shuffle 関数をテストする。
	TEST_F(WallTest, testShuffle)
	{
		Wall wall1;
		Wall wall2;
		Wall wall3;

		wall2.shuffle(23);
		ASSERT_NE(wall1, wall2);

		wall1.shuffle(23);
		ASSERT_EQ(wall1, wall2);

		wall3.shuffle(24);
		ASSERT_NE(wall1, wall3);
	}

	/// breaks 関数をテストする。
	TEST_F(WallTest, testBreaks)
	{
		Dice dice1;
		Dice dice2;
		Wall wall1a;
		Wall wall1b;
		Wall wall2;
		Wall wall3;

		dice1.setNumber(2);
		dice2.setNumber(3);
		wall1a.breaks(dice1, dice2);
		ASSERT_EQ(P3, wall1a.draw());
		ASSERT_EQ(P3, wall1a.draw());
		ASSERT_EQ(P4, wall1a.draw());
		ASSERT_EQ(P4, wall1a.draw());
		ASSERT_EQ(P3, wall1a.drawReplacementTile());
		ASSERT_EQ(P3, wall1a.drawReplacementTile());
		ASSERT_EQ(P2, wall1a.drawReplacementTile());
		ASSERT_EQ(P2, wall1a.drawReplacementTile());

		wall1a.breaks(dice1, dice2);
		wall1b.breaks(dice1, dice2);
		ASSERT_EQ(wall1a, wall1b);

		dice1.setNumber(1);
		dice2.setNumber(1);
		wall2.breaks(dice1, dice2);
		ASSERT_EQ(M9, wall2.draw());
		ASSERT_EQ(M9, wall2.draw());
		ASSERT_EQ(TN, wall2.draw());
		ASSERT_EQ(TN, wall2.draw());
		ASSERT_EQ(M9, wall2.drawReplacementTile());
		ASSERT_EQ(M9, wall2.drawReplacementTile());
		ASSERT_EQ(M8, wall2.drawReplacementTile());
		ASSERT_EQ(M8, wall2.drawReplacementTile());

		dice1.setNumber(5);
		dice2.setNumber(6);
		wall3.breaks(dice1, dice2);
		ASSERT_EQ(M5, wall3.draw());
		ASSERT_EQ(M5, wall3.draw());
		ASSERT_EQ(M6, wall3.draw());
		ASSERT_EQ(M6, wall3.draw());
		ASSERT_EQ(M5, wall3.drawReplacementTile());
		ASSERT_EQ(M5, wall3.drawReplacementTile());
		ASSERT_EQ(M4, wall3.drawReplacementTile());
		ASSERT_EQ(M4, wall3.drawReplacementTile());

		dice1.setNumber(5);
		dice2.setNumber(6);
		wall3.breaks(dice1, dice2);
		ASSERT_EQ(M5, wall3.draw());
		ASSERT_EQ(M5, wall3.draw());
		ASSERT_EQ(M6, wall3.draw());
		ASSERT_EQ(M6, wall3.draw());
		ASSERT_EQ(M5, wall3.drawReplacementTile());
		ASSERT_EQ(M5, wall3.drawReplacementTile());
		ASSERT_EQ(M4, wall3.drawReplacementTile());
		ASSERT_EQ(M4, wall3.drawReplacementTile());

		dice1.setNumber(6);
		dice2.setNumber(6);
		wall3.breaks(dice1, dice2);
		ASSERT_EQ(S6, wall3.draw());
		ASSERT_EQ(S6, wall3.draw());
		ASSERT_EQ(S7, wall3.draw());
		ASSERT_EQ(S7, wall3.draw());
		ASSERT_EQ(S6, wall3.drawReplacementTile());
		ASSERT_EQ(S6, wall3.drawReplacementTile());
		ASSERT_EQ(S5, wall3.drawReplacementTile());
		ASSERT_EQ(S5, wall3.drawReplacementTile());
	}

	/// draw 関数をテストする。
	TEST_F(WallTest, testDraw)
	{
		Wall wall1;
		Wall wall2(TILES2);

		for (auto it = TILES1.begin() + (3 * 34 + 2 * 2); it != TILES1.end(); ++it) {
			ASSERT_EQ(*it, wall1.draw());
		}
		for (auto it = TILES1.begin(); it != TILES1.begin() + (3 * 34 + 2 * 2); ++it) {
			ASSERT_EQ(*it, wall1.draw());
		}

		for (auto it = TILES2.begin() + (3 * 34 + 2 * 2); it != TILES2.end(); ++it) {
			ASSERT_EQ(*it, wall2.draw());
		}
		for (auto it = TILES2.begin(); it != TILES2.begin() + (3 * 34 + 2 * 2); ++it) {
			ASSERT_EQ(*it, wall2.draw());
		}

#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		ASSERT_THROW(wall1.draw(), OpenRiichiAssertion);
		ASSERT_THROW(wall2.draw(), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	}

	/// drawReplacementTile 関数をテストする。
	TEST_F(WallTest, testDrawReplacementTile)
	{
		Wall wall1;
		Wall wall2(TILES2);

		for (auto n = wall1.countRemainingTiles(); n > 0; --n) {
			ASSERT_EQ(TILES1[((3 * 34 + 2 * 2) + (n + (((n % 2) == 0) ? 12 : 14))) % 136], wall1.drawReplacementTile());
		}
		for (auto n = wall2.countRemainingTiles(); n > 0; --n) {
			ASSERT_EQ(TILES2[((3 * 34 + 2 * 2) + (n + (((n % 2) == 0) ? 12 : 14))) % 136], wall2.drawReplacementTile());
		}

#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		ASSERT_THROW(wall1.drawReplacementTile(), OpenRiichiAssertion);
		ASSERT_THROW(wall2.drawReplacementTile(), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	}

	/// revealNewDora 関数をテストする。
	TEST_F(WallTest, testRevealNewDora)
	{
		Wall wall;	

		wall.revealNewDora();
		ASSERT_EQ(Wall::Doras{ M9 }, wall.getDoras());
		ASSERT_EQ(Wall::Doras{ M9 }, wall.getUraDoras());

#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		ASSERT_THROW(wall.revealNewDora(), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0

		wall.drawReplacementTile();
		wall.revealNewDora();
		ASSERT_EQ((Wall::Doras{ M9, M8 }), wall.getDoras());
		ASSERT_EQ((Wall::Doras{ M9, M8 }), wall.getUraDoras());

#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		ASSERT_THROW(wall.revealNewDora(), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0

		wall.drawReplacementTile();
		wall.revealNewDora();
		ASSERT_EQ((Wall::Doras{ M9, M8, M8 }), wall.getDoras());
		ASSERT_EQ((Wall::Doras{ M9, M8, M8 }), wall.getUraDoras());

#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		ASSERT_THROW(wall.revealNewDora(), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0

		wall.drawReplacementTile();
		wall.revealNewDora();
		ASSERT_EQ((Wall::Doras{ M9, M8, M8, M7 }), wall.getDoras());
		ASSERT_EQ((Wall::Doras{ M9, M8, M8, M7 }), wall.getUraDoras());

#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		ASSERT_THROW(wall.revealNewDora(), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0

		for (auto n = 4; n <= 65; ++n) {
			wall.drawReplacementTile();
			wall.revealNewDora();
			ASSERT_EQ(n + 1, wall.getDoras().size());

#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
			ASSERT_THROW(wall.revealNewDora(), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		}

#if defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
		wall.drawReplacementTile();
		ASSERT_THROW(wall.revealNewDora(), OpenRiichiAssertion);
#endif // defined(OPENRIICHI_ENABLE_ASSERTION) && OPENRIICHI_ENABLE_ASSERTION != 0
	}

	/// countRemainingTiles 関数をテストする。
	TEST_F(WallTest, testCountRemainingTiles)
	{
		Wall wall;

		ASSERT_EQ(122, wall.countRemainingTiles());

		wall.draw();
		ASSERT_EQ(121, wall.countRemainingTiles());

		wall.drawReplacementTile();
		ASSERT_EQ(120, wall.countRemainingTiles());

		for (auto i = 119; i >= 0; --i) {
			wall.draw();
			ASSERT_EQ(i, wall.countRemainingTiles());
		}
	}

	/// getDoras 関数をテストする。
	TEST_F(WallTest, testGetDoras)
	{
		Wall::Doras doras;
		Wall wall;

		ASSERT_EQ(doras, wall.getDoras());

		doras.push_back(TILES1[100].getNextTile());
		wall.revealNewDora();
		ASSERT_EQ(doras, wall.getDoras());

		for (auto i = 0; i < 65; ++i) {
			doras.push_back(TILES1[(100 - (1 + i) * 2 + 136) % 136].getNextTile());
			wall.drawReplacementTile();
			wall.revealNewDora();
			ASSERT_EQ(doras, wall.getDoras());
		}
	}

	/// getUraDoras 関数をテストする。
	TEST_F(WallTest, testGetUraDoras)
	{
		Wall::Doras uraDoras;
		Wall wall;

		ASSERT_EQ(uraDoras, wall.getDoras());

		uraDoras.push_back(TILES1[101].getNextTile());
		wall.revealNewDora();
		ASSERT_EQ(uraDoras, wall.getDoras());

		for (auto i = 0; i < 65; ++i) {
			uraDoras.push_back(TILES1[(101 - (1 + i) * 2 + 136) % 136].getNextTile());
			wall.drawReplacementTile();
			wall.revealNewDora();
			ASSERT_EQ(uraDoras, wall.getDoras());
		}
	}
}
