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
#include <algorithm>
#include <gtest/gtest.h>
#include <OpenRiichiException.h>


using namespace std;


namespace openriichi
{
	class OpenRiichiExceptionTest : public ::testing::Test {};

	/// getMessage 関数をテストする。
	TEST_F(OpenRiichiExceptionTest, testGetMessage)
	{
		char message3[1024] = { 0 };
		char message4[1025] = { 0 };

		fill(message3, message3 + sizeof(message3) - 1, 'm');
		fill(message4, message4 + sizeof(message4) - 1, 'm');

		OpenRiichiException exception1;
		OpenRiichiException exception2("m");
		OpenRiichiException exception3(message3);
		OpenRiichiException exception4(message4);

		ASSERT_STREQ("", exception1.getMessage());
		ASSERT_STREQ("m", exception2.getMessage());
		ASSERT_STREQ(message3, exception3.getMessage());
		ASSERT_STREQ(message3, exception4.getMessage());
	}
}
