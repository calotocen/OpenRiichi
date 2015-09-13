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
#include <Enumeration.h>


namespace openriichi
{
	class EnumerationTest : public ::testing::Test {};

	class DerivedEnumeration : public Enumeration<DerivedEnumeration>
	{
	private:
		int m_id;

	public:
		explicit DerivedEnumeration(int id) : m_id(id) {}
		virtual ~DerivedEnumeration() {}

	public:
		virtual int getId() const override { return m_id; }
	};

	// == 演算子をテストする。
	TEST_F(EnumerationTest, testEquals)
	{
		DerivedEnumeration enumeration(0);

		ASSERT_TRUE(enumeration == enumeration);
		ASSERT_TRUE(DerivedEnumeration(1) == DerivedEnumeration(1));
		ASSERT_FALSE(DerivedEnumeration(1) == DerivedEnumeration(2));
	}

	// != 演算子をテストする。
	TEST_F(EnumerationTest, testNotEquals)
	{
		DerivedEnumeration enumeration(0);

		ASSERT_FALSE(enumeration != enumeration);
		ASSERT_FALSE(DerivedEnumeration(1) != DerivedEnumeration(1));
		ASSERT_TRUE(DerivedEnumeration(1) != DerivedEnumeration(2));
	}
}
