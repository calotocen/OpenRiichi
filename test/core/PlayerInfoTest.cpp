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
	class PlayerInfoTest : public ::testing::Test {};

	/// hand 関数をテストする。
	TEST_F(PlayerInfoTest, testHand)
	{
		PlayerInfo playerInfo1;
		const PlayerInfo playerInfo2;

		ASSERT_EQ(Hand(), playerInfo1.hand());

		playerInfo1.hand() = { P1, P2, P3, P4, P5, P6, P7, P8, P9, TN, TN, TN, NN, NN };
		ASSERT_EQ((Hand{ P1, P2, P3, P4, P5, P6, P7, P8, P9, TN, TN, TN, NN, NN }), playerInfo1.hand());

		ASSERT_EQ(Hand(), playerInfo2.hand());
	}

	/// getHand 関数をテストする。
	TEST_F(PlayerInfoTest, testGetHand)
	{
		PlayerInfo playerInfo;

		ASSERT_EQ(Hand(), playerInfo.getHand());

		playerInfo.hand() = { P1, P2, P3, P4, P5, P6, P7, P8, P9, TN, TN, TN, NN, NN };
		ASSERT_EQ((Hand{ P1, P2, P3, P4, P5, P6, P7, P8, P9, TN, TN, TN, NN, NN }), playerInfo.getHand());
	}

	/// setHand 関数をテストする。
	TEST_F(PlayerInfoTest, testSetHand)
	{
		PlayerInfo playerInfo;

		playerInfo.setHand(Hand{ P1, P2, P3, P4, P5, P6, P7, P8, P9, TN, TN, TN, NN, NN });
		ASSERT_EQ((Hand{ P1, P2, P3, P4, P5, P6, P7, P8, P9, TN, TN, TN, NN, NN }), playerInfo.getHand());
	}

	/// discards 関数をテストする。
	TEST_F(PlayerInfoTest, testDiscards)
	{
		PlayerInfo playerInfo1;
		const PlayerInfo playerInfo2;

		ASSERT_EQ(PlayerInfo::Discards(), playerInfo1.discards());

		playerInfo1.discards() = { Discard(P1, DiscardSources::DRAWED) };
		ASSERT_EQ((PlayerInfo::Discards{ Discard(P1, DiscardSources::DRAWED) }), playerInfo1.discards());

		ASSERT_EQ(PlayerInfo::Discards(), playerInfo2.discards());
	}

	/// getDiscards 関数をテストする。
	TEST_F(PlayerInfoTest, testGetDiscards)
	{
		PlayerInfo playerInfo;

		ASSERT_EQ(PlayerInfo::Discards(), playerInfo.getDiscards());

		playerInfo.discards() = { Discard(P1, DiscardSources::DRAWED) };
		ASSERT_EQ((PlayerInfo::Discards{ Discard(P1, DiscardSources::DRAWED) }), playerInfo.getDiscards());
	}

	/// setDiscards 関数をテストする。
	TEST_F(PlayerInfoTest, testSetDiscards)
	{
		PlayerInfo playerInfo;

		playerInfo.setDiscards(PlayerInfo::Discards{ Discard(P1, DiscardSources::DRAWED) });
		ASSERT_EQ((PlayerInfo::Discards{ Discard(P1, DiscardSources::DRAWED) }), playerInfo.getDiscards());
	}

	/// getPoints 関数をテストする。
	TEST_F(PlayerInfoTest, testGetPoints)
	{
		PlayerInfo playerInfo;

		ASSERT_EQ(0, playerInfo.getPoints());
	}

	/// setPoints 関数をテストする。
	TEST_F(PlayerInfoTest, testSetPoints)
	{
		PlayerInfo playerInfo;

		playerInfo.setPoints(1000);
		ASSERT_EQ(1000, playerInfo.getPoints());
	}

	/// addPoints 関数をテストする。
	TEST_F(PlayerInfoTest, testAddPoints)
	{
		PlayerInfo playerInfo;

		playerInfo.setPoints(1000);
		playerInfo.addPoints(2000);
		ASSERT_EQ(3000, playerInfo.getPoints());
	}

	/// getDrawCount 関数をテストする。
	TEST_F(PlayerInfoTest, testGetDrawCount)
	{
		PlayerInfo playerInfo;

		ASSERT_EQ(0, playerInfo.getDrawCount());
	}

	/// setDrawCount 関数をテストする。
	TEST_F(PlayerInfoTest, testSetDrawCount)
	{
		PlayerInfo playerInfo;

		playerInfo.setDrawCount(3);
		ASSERT_EQ(3, playerInfo.getDrawCount());
	}

	/// increaseDrawCount 関数をテストする。
	TEST_F(PlayerInfoTest, testIncreaseDrawCount)
	{
		PlayerInfo playerInfo;

		playerInfo.setDrawCount(3);
		playerInfo.increaseDrawCount();
		ASSERT_EQ(4, playerInfo.getDrawCount());
	}

	/// riichiStatus 関数をテストする。
	TEST_F(PlayerInfoTest, testRiichiStatus)
	{
		PlayerInfo playerInfo1;
		const PlayerInfo playerInfo2;

		ASSERT_EQ(RiichiStatus(), playerInfo1.riichiStatus());

		playerInfo1.riichiStatus().setDeclared(true);
		ASSERT_EQ(RiichiStatus(true), playerInfo1.riichiStatus());

		ASSERT_EQ(RiichiStatus(), playerInfo2.riichiStatus());
	}

	/// getRiichiStatus 関数をテストする。
	TEST_F(PlayerInfoTest, testGetRiichiStatus)
	{
		PlayerInfo playerInfo;

		ASSERT_EQ(RiichiStatus(), playerInfo.getRiichiStatus());

		playerInfo.riichiStatus().setDeclared(true);
		ASSERT_EQ(RiichiStatus(true), playerInfo.getRiichiStatus());
	}

	/// setRiichiStatus 関数をテストする。
	TEST_F(PlayerInfoTest, testSetRiichiStatus)
	{
		PlayerInfo playerInfo;

		playerInfo.setRiichiStatus(RiichiStatus(true));
		ASSERT_EQ(RiichiStatus(true), playerInfo.getRiichiStatus());
	}

	/// == 演算子をテストする。
	TEST_F(PlayerInfoTest, testEquals)
	{
		PlayerInfo playerInfo1A;
		PlayerInfo playerInfo1B;
		PlayerInfo playerInfo2A;
		PlayerInfo playerInfo2B;
		PlayerInfo playerInfo3A;
		PlayerInfo playerInfo3B;
		PlayerInfo playerInfo4A;
		PlayerInfo playerInfo4B;
		PlayerInfo playerInfo5A;
		PlayerInfo playerInfo5B;

		playerInfo1A.hand() = { P1 };
		playerInfo1B.hand() = { P1 };
		playerInfo2A.discards() = { Discard(P1, DiscardSources::DRAWED) };
		playerInfo2B.discards() = { Discard(P1, DiscardSources::DRAWED) };
		playerInfo3A.setPoints(1000);
		playerInfo3B.setPoints(1000);
		playerInfo4A.setDrawCount(1);
		playerInfo4B.setDrawCount(1);
		playerInfo5A.riichiStatus().setDeclared(true);
		playerInfo5B.riichiStatus().setDeclared(true);

		// 自身と比較する。
		ASSERT_TRUE(playerInfo1A == playerInfo1A);
		ASSERT_TRUE(playerInfo2A == playerInfo2A);
		ASSERT_TRUE(playerInfo3A == playerInfo3A);
		ASSERT_TRUE(playerInfo4A == playerInfo4A);
		ASSERT_TRUE(playerInfo5A == playerInfo5A);

		// 同じプレイヤー情報と比較する。
		ASSERT_TRUE(playerInfo1A == playerInfo1B);
		ASSERT_TRUE(playerInfo2A == playerInfo2B);
		ASSERT_TRUE(playerInfo3A == playerInfo3B);
		ASSERT_TRUE(playerInfo4A == playerInfo4B);
		ASSERT_TRUE(playerInfo5A == playerInfo5B);

		// 異なるプレイヤー情報と比較する。
		vector<PlayerInfo> playerInfos{ playerInfo1A, playerInfo2A, playerInfo3A, playerInfo4A, playerInfo5A };
		for (size_t i = 0; i < playerInfos.size(); ++i) {
			for (size_t j = 0; j < playerInfos.size(); ++j) {
				if (i != j) {
					ASSERT_FALSE(playerInfos[i] == playerInfos[j]);
				}
			}
		}
	}

	/// != 演算子をテストする。
	TEST_F(PlayerInfoTest, testNotEquals)
	{
		PlayerInfo playerInfo1A;
		PlayerInfo playerInfo1B;
		PlayerInfo playerInfo2A;
		PlayerInfo playerInfo2B;
		PlayerInfo playerInfo3A;
		PlayerInfo playerInfo3B;
		PlayerInfo playerInfo4A;
		PlayerInfo playerInfo4B;
		PlayerInfo playerInfo5A;
		PlayerInfo playerInfo5B;

		playerInfo1A.hand() = { P1 };
		playerInfo1B.hand() = { P1 };
		playerInfo2A.discards() = { Discard(P1, DiscardSources::DRAWED) };
		playerInfo2B.discards() = { Discard(P1, DiscardSources::DRAWED) };
		playerInfo3A.setPoints(1000);
		playerInfo3B.setPoints(1000);
		playerInfo4A.setDrawCount(1);
		playerInfo4B.setDrawCount(1);
		playerInfo5A.riichiStatus().setDeclared(true);
		playerInfo5B.riichiStatus().setDeclared(true);

		// 自身と比較する。
		ASSERT_FALSE(playerInfo1A != playerInfo1A);
		ASSERT_FALSE(playerInfo2A != playerInfo2A);
		ASSERT_FALSE(playerInfo3A != playerInfo3A);
		ASSERT_FALSE(playerInfo4A != playerInfo4A);
		ASSERT_FALSE(playerInfo5A != playerInfo5A);

		// 同じプレイヤー情報と比較する。
		ASSERT_FALSE(playerInfo1A != playerInfo1B);
		ASSERT_FALSE(playerInfo2A != playerInfo2B);
		ASSERT_FALSE(playerInfo3A != playerInfo3B);
		ASSERT_FALSE(playerInfo4A != playerInfo4B);
		ASSERT_FALSE(playerInfo5A != playerInfo5B);

		// 異なるプレイヤー情報と比較する。
		vector<PlayerInfo> playerInfos{ playerInfo1A, playerInfo2A, playerInfo3A, playerInfo4A, playerInfo5A };
		for (size_t i = 0; i < playerInfos.size(); ++i) {
			for (size_t j = 0; j < playerInfos.size(); ++j) {
				if (i != j) {
					ASSERT_TRUE(playerInfos[i] != playerInfos[j]);
				}
			}
		}
	}
}
