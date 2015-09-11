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
#include <SimplePlayerInfo.h>


namespace openriichi
{
	class SimplePlayerInfoTest : public ::testing::Test {};

	/// インスタンスのサイズをテストする。
	TEST_F(SimplePlayerInfoTest, testSizeOfInstance)
	{
		SimplePlayerInfo playerInfo;
		ASSERT_EQ(104, sizeof(playerInfo));
	}

	// プレイヤー情報をテストする。
	TEST_F(SimplePlayerInfoTest, testPlayerInfo)
	{
		SimplePlayerInfo playerInfo;

		ASSERT_EQ(Hand(), playerInfo.hand());
		ASSERT_EQ(SimplePlayerInfo::Discards(), playerInfo.discards());
		ASSERT_EQ(0, playerInfo.getPoints());
		ASSERT_EQ(0, playerInfo.getDrawCount());
		ASSERT_EQ(RiichiStatus(), playerInfo.riichiStatus());

		playerInfo.setPoints(1000);
		ASSERT_EQ(1000, playerInfo.getPoints());

		playerInfo.addPoints(2000);
		ASSERT_EQ(3000, playerInfo.getPoints());

		playerInfo.setDrawCount(3);
		ASSERT_EQ(3, playerInfo.getDrawCount());

		playerInfo.increaseDrawCount();
		ASSERT_EQ(4, playerInfo.getDrawCount());
	}
}
