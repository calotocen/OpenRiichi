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


namespace openriichi
{
	class RiichiStatusTest : public ::testing::Test
	{
	protected:
		RiichiStatus riichiStatus1;
		RiichiStatus riichiStatus2;

	protected:
		RiichiStatusTest()
			: riichiStatus1()
			, riichiStatus2(true, true, true, true)
		{}
	};

	/// == 演算子をテストする。
	TEST_F(RiichiStatusTest, testOperatorEqualTo)
	{
		// 自身と比較する。
		ASSERT_TRUE(riichiStatus1 == riichiStatus1);
		ASSERT_TRUE(riichiStatus2 == riichiStatus2);

		// 同じ立直状態と比較する。
		ASSERT_TRUE(riichiStatus1 == RiichiStatus());
		ASSERT_TRUE(riichiStatus2 == RiichiStatus(true, true, true, true));

		// 異なる立直状態と比較する。
		ASSERT_FALSE(riichiStatus1 == riichiStatus2);
	}

	/// != 演算子をテストする。
	TEST_F(RiichiStatusTest, testOperatorNotEqualTo)
	{
		// 自身と比較する。
		ASSERT_FALSE(riichiStatus1 != riichiStatus1);
		ASSERT_FALSE(riichiStatus2 != riichiStatus2);

		// 同じ立直状態と比較する。
		ASSERT_FALSE(riichiStatus1 != RiichiStatus());
		ASSERT_FALSE(riichiStatus2 != RiichiStatus(true, true, true, true));

		// 異なる立直状態と比較する。
		ASSERT_TRUE(riichiStatus1 != riichiStatus2);
	}

	/// isDeclared 関数をテストする。
	TEST_F(RiichiStatusTest, testToIsDeclared)
	{
		ASSERT_EQ(false, riichiStatus1.isDeclared());
		ASSERT_EQ(true, riichiStatus2.isDeclared());
	}

	/// isOpen 関数をテストする。
	TEST_F(RiichiStatusTest, testToIsOpen)
	{
		ASSERT_EQ(false, riichiStatus1.isOpen());
		ASSERT_EQ(true, riichiStatus2.isOpen());
	}

	/// isDouble 関数をテストする。
	TEST_F(RiichiStatusTest, testToIsDouble)
	{
		ASSERT_EQ(false, riichiStatus1.isDouble());
		ASSERT_EQ(true, riichiStatus2.isDouble());
	}

	/// isOneShot 関数をテストする。
	TEST_F(RiichiStatusTest, testToIsOneShot)
	{
		ASSERT_EQ(false, riichiStatus1.isOneShot());
		ASSERT_EQ(true, riichiStatus2.isOneShot());
	}

	/// setDeclared 関数をテストする。
	TEST_F(RiichiStatusTest, testToSetDeclared)
	{
		riichiStatus1.setDeclared(true);
		ASSERT_EQ(RiichiStatus(true, false, false, false), riichiStatus1);

		riichiStatus2.setDeclared(false);
		ASSERT_EQ(RiichiStatus(false, true, true, true), riichiStatus2);
	}

	/// setOpen 関数をテストする。
	TEST_F(RiichiStatusTest, testToSetOpen)
	{
		riichiStatus1.setOpen(true);
		ASSERT_EQ(RiichiStatus(false, true, false, false), riichiStatus1);

		riichiStatus2.setOpen(false);
		ASSERT_EQ(RiichiStatus(true, false, true, true), riichiStatus2);
	}

	/// setDouble 関数をテストする。
	TEST_F(RiichiStatusTest, testToSetDouble)
	{
		riichiStatus1.setDouble(true);
		ASSERT_EQ(RiichiStatus(false, false, true, false), riichiStatus1);

		riichiStatus2.setDouble(false);
		ASSERT_EQ(RiichiStatus(true, true, false, true), riichiStatus2);
	}

	/// setOneShot 関数をテストする。
	TEST_F(RiichiStatusTest, testToSetOneShot)
	{
		riichiStatus1.setOneShot(true);
		ASSERT_EQ(RiichiStatus(false, false, false, true), riichiStatus1);

		riichiStatus2.setOneShot(false);
		ASSERT_EQ(RiichiStatus(true, true, true, false), riichiStatus2);
	}
}
