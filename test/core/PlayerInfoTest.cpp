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
#include <PlayerInfo.h>
#include <Tiles.h>


namespace openriichi
{
	class PlayerInfoTest : public ::testing::Test {};

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

	/// hand 関数をテストする。
	TEST_F(PlayerInfoTest, testHand)
	{
		PlayerInfo playerInfo;

		ASSERT_EQ(Hand(), playerInfo.hand());

		playerInfo.hand() = { P1, P2, P3, P4, P5, P6, P7, P8, P9, TN, TN, TN, NN, NN };
		ASSERT_EQ((Hand{ P1, P2, P3, P4, P5, P6, P7, P8, P9, TN, TN, TN, NN, NN }), playerInfo.hand());
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

	/// discards 関数をテストする。
	TEST_F(PlayerInfoTest, testDiscards)
	{
		PlayerInfo playerInfo;

		ASSERT_EQ(PlayerInfo::Discards(), playerInfo.discards());

		playerInfo.discards() = { Discard(P1, DiscardSources::DRAWED) };
		ASSERT_EQ((PlayerInfo::Discards{ Discard(P1, DiscardSources::DRAWED) }), playerInfo.discards());
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

	/// riichiStatus 関数をテストする。
	TEST_F(PlayerInfoTest, testRiichiStatus)
	{
		PlayerInfo playerInfo;

		ASSERT_EQ(RiichiStatus(), playerInfo.riichiStatus());

		playerInfo.riichiStatus().setDeclared(true);
		ASSERT_EQ(RiichiStatus(true), playerInfo.riichiStatus());
	}
}
