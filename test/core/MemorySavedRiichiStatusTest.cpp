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
#include <MemorySavedRiichiStatus.h>


namespace openriichi
{
	class MemorySavedRiichiStatusTest : public ::testing::Test {};

	/// インスタンスのサイズをテストする。
	TEST_F(MemorySavedRiichiStatusTest, testSizeOfInstance)
	{
		MemorySavedRiichiStatus riichiStatus;
		ASSERT_EQ(1, sizeof(riichiStatus));
	}

	/// 捨て牌をテストする。
	TEST_F(MemorySavedRiichiStatusTest, testDiscard)
	{
		MemorySavedRiichiStatus riichiStatus1;
		ASSERT_EQ(false, riichiStatus1.isDeclared());
		ASSERT_EQ(false, riichiStatus1.isOpen());
		ASSERT_EQ(false, riichiStatus1.isDouble());
		ASSERT_EQ(false, riichiStatus1.isOneShot());

		MemorySavedRiichiStatus riichiStatus2(true, true, true, true);
		ASSERT_EQ(true, riichiStatus2.isDeclared());
		ASSERT_EQ(true, riichiStatus2.isOpen());
		ASSERT_EQ(true, riichiStatus2.isDouble());
		ASSERT_EQ(true, riichiStatus2.isOneShot());

		riichiStatus2.setDeclared(false);
		ASSERT_EQ(false, riichiStatus2.isDeclared());
		ASSERT_EQ(true, riichiStatus2.isOpen());
		ASSERT_EQ(true, riichiStatus2.isDouble());
		ASSERT_EQ(true, riichiStatus2.isOneShot());

		riichiStatus2.setOpen(false);
		ASSERT_EQ(false, riichiStatus2.isDeclared());
		ASSERT_EQ(false, riichiStatus2.isOpen());
		ASSERT_EQ(true, riichiStatus2.isDouble());
		ASSERT_EQ(true, riichiStatus2.isOneShot());

		riichiStatus2.setDouble(false);
		ASSERT_EQ(false, riichiStatus2.isDeclared());
		ASSERT_EQ(false, riichiStatus2.isOpen());
		ASSERT_EQ(false, riichiStatus2.isDouble());
		ASSERT_EQ(true, riichiStatus2.isOneShot());

		riichiStatus2.setOneShot(false);
		ASSERT_EQ(false, riichiStatus2.isDeclared());
		ASSERT_EQ(false, riichiStatus2.isOpen());
		ASSERT_EQ(false, riichiStatus2.isDouble());
		ASSERT_EQ(false, riichiStatus2.isOneShot());

		riichiStatus2.setOneShot(true);
		ASSERT_EQ(false, riichiStatus2.isDeclared());
		ASSERT_EQ(false, riichiStatus2.isOpen());
		ASSERT_EQ(false, riichiStatus2.isDouble());
		ASSERT_EQ(true, riichiStatus2.isOneShot());

		riichiStatus2.setDouble(true);
		ASSERT_EQ(false, riichiStatus2.isDeclared());
		ASSERT_EQ(false, riichiStatus2.isOpen());
		ASSERT_EQ(true, riichiStatus2.isDouble());
		ASSERT_EQ(true, riichiStatus2.isOneShot());

		riichiStatus2.setOpen(true);
		ASSERT_EQ(false, riichiStatus2.isDeclared());
		ASSERT_EQ(true, riichiStatus2.isOpen());
		ASSERT_EQ(true, riichiStatus2.isDouble());
		ASSERT_EQ(true, riichiStatus2.isOneShot());

		riichiStatus2.setDeclared(true);
		ASSERT_EQ(true, riichiStatus2.isDeclared());
		ASSERT_EQ(true, riichiStatus2.isOpen());
		ASSERT_EQ(true, riichiStatus2.isDouble());
		ASSERT_EQ(true, riichiStatus2.isOneShot());
	}
}
