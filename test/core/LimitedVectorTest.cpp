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
#include <LimitedVector.h>
#include <OpenRiichiAssertion.h>


using namespace std;


namespace openriichi
{
	class LimitedVectorTest : public ::testing::Test {};

	/// コンストラクタ (初期化子リスト指定) をテストする。
	TEST_F(LimitedVectorTest, testConstructWithInitializerList)
	{
#if OPENRIICHI_ENABLE_ASSERTION == 1
		ASSERT_THROW((LimitedVector<int, 10>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// size 関数をテストする。
	TEST_F(LimitedVectorTest, testCount)
	{
		LimitedVector<int, 10> limitedVector1;
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4 };
		LimitedVector<int, 10> limitedVector3{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		ASSERT_EQ(0, limitedVector1.size());
		ASSERT_EQ(5, limitedVector2.size());
		ASSERT_EQ(10, limitedVector3.size());
	}

	/// at 関数 (非 const 版) をテストする。
	TEST_F(LimitedVectorTest, testAt)
	{
		LimitedVector<int, 10> limitedVector{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		limitedVector.at(0) = 10;
		limitedVector.at(5) = 11;
		limitedVector.at(9) = 12;
		ASSERT_EQ((LimitedVector<int, 10>{ 10, 1, 2, 3, 4, 11, 6, 7, 8, 12 }), limitedVector);

#if OPENRIICHI_ENABLE_ASSERTION == 1
		ASSERT_THROW(limitedVector.at(10) = 13, OpenRiichiAssertion);
		ASSERT_THROW((LimitedVector<int, 10>().at(0) = 14), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// at 関数 (const 版) をテストする。
	TEST_F(LimitedVectorTest, testAtAsConst)
	{
		const LimitedVector<int, 10> limitedVector{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		ASSERT_EQ(0, limitedVector.at(0));
		ASSERT_EQ(5, limitedVector.at(5));
		ASSERT_EQ(9, limitedVector.at(9));

#if OPENRIICHI_ENABLE_ASSERTION == 1
		ASSERT_THROW(limitedVector.at(10), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// front 関数をテストする。
	TEST_F(LimitedVectorTest, testFront)
	{
		LimitedVector<int, 10> limitedVector1{ 0 };
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		ASSERT_EQ(0, limitedVector1.front());
		ASSERT_EQ(0, limitedVector2.front());

#if OPENRIICHI_ENABLE_ASSERTION == 1
		ASSERT_THROW((LimitedVector<int, 10>().front()), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// back 関数をテストする。
	TEST_F(LimitedVectorTest, testBack)
	{
		LimitedVector<int, 10> limitedVector1{ 0 };
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		ASSERT_EQ(0, limitedVector1.back());
		ASSERT_EQ(9, limitedVector2.back());

#if OPENRIICHI_ENABLE_ASSERTION == 1
		ASSERT_THROW((LimitedVector<int, 10>().back()), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// push_back 関数をテストする。
	TEST_F(LimitedVectorTest, testPushBack)
	{
		LimitedVector<int, 10> limitedVector;

		limitedVector.push_back(0);
		limitedVector.push_back(1);
		limitedVector.push_back(2);
		limitedVector.push_back(3);
		limitedVector.push_back(4);
		limitedVector.push_back(5);
		limitedVector.push_back(6);
		limitedVector.push_back(7);
		limitedVector.push_back(8);
		limitedVector.push_back(9);
		ASSERT_EQ((LimitedVector<int, 10>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }), limitedVector);

#if OPENRIICHI_ENABLE_ASSERTION == 1
		ASSERT_THROW(limitedVector.push_back(10), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// begin 関数 (iterator 返却版) をテストする。
	TEST_F(LimitedVectorTest, testBegin)
	{
		LimitedVector<int, 10> limitedVector1{ 0 };
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		LimitedVector<int, 10>::iterator iterator = limitedVector2.begin();

		ASSERT_EQ(0, *limitedVector1.begin());
		ASSERT_EQ(0, *(iterator + 0));
		ASSERT_EQ(1, *(iterator + 1));
		ASSERT_EQ(2, *(iterator + 2));
		ASSERT_EQ(3, *(iterator + 3));
		ASSERT_EQ(4, *(iterator + 4));
		ASSERT_EQ(5, *(iterator + 5));
		ASSERT_EQ(6, *(iterator + 6));
		ASSERT_EQ(7, *(iterator + 7));
		ASSERT_EQ(8, *(iterator + 8));
		ASSERT_EQ(9, *(iterator + 9));
		ASSERT_EQ(0, *iterator++);
		ASSERT_EQ(1, *iterator++);
		ASSERT_EQ(2, *iterator++);
		ASSERT_EQ(3, *iterator++);
		ASSERT_EQ(4, *iterator++);
		ASSERT_EQ(5, *iterator++);
		ASSERT_EQ(6, *iterator++);
		ASSERT_EQ(7, *iterator++);
		ASSERT_EQ(8, *iterator++);
		ASSERT_EQ(9, *iterator++);
	}

	/// begin 関数 (const_iterator 返却版) をテストする。
	TEST_F(LimitedVectorTest, testBeginAsConst)
	{
		LimitedVector<int, 10> limitedVector1{ 0 };
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		LimitedVector<int, 10>::const_iterator iterator = limitedVector2.begin();

		ASSERT_EQ(0, *limitedVector1.begin());
		ASSERT_EQ(0, *(iterator + 0));
		ASSERT_EQ(1, *(iterator + 1));
		ASSERT_EQ(2, *(iterator + 2));
		ASSERT_EQ(3, *(iterator + 3));
		ASSERT_EQ(4, *(iterator + 4));
		ASSERT_EQ(5, *(iterator + 5));
		ASSERT_EQ(6, *(iterator + 6));
		ASSERT_EQ(7, *(iterator + 7));
		ASSERT_EQ(8, *(iterator + 8));
		ASSERT_EQ(9, *(iterator + 9));
		ASSERT_EQ(0, *iterator++);
		ASSERT_EQ(1, *iterator++);
		ASSERT_EQ(2, *iterator++);
		ASSERT_EQ(3, *iterator++);
		ASSERT_EQ(4, *iterator++);
		ASSERT_EQ(5, *iterator++);
		ASSERT_EQ(6, *iterator++);
		ASSERT_EQ(7, *iterator++);
		ASSERT_EQ(8, *iterator++);
		ASSERT_EQ(9, *iterator++);
	}

	/// end 関数 (iterator 返却版) をテストする。
	TEST_F(LimitedVectorTest, testEnd)
	{
		LimitedVector<int, 10> limitedVector1{ 0 };
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		LimitedVector<int, 10>::iterator iterator = limitedVector2.end();

		ASSERT_EQ(0, *(limitedVector1.end() - 1));
		ASSERT_EQ(9, *(iterator - 1));
		ASSERT_EQ(8, *(iterator - 2));
		ASSERT_EQ(7, *(iterator - 3));
		ASSERT_EQ(6, *(iterator - 4));
		ASSERT_EQ(5, *(iterator - 5));
		ASSERT_EQ(4, *(iterator - 6));
		ASSERT_EQ(3, *(iterator - 7));
		ASSERT_EQ(2, *(iterator - 8));
		ASSERT_EQ(1, *(iterator - 9));
		ASSERT_EQ(0, *(iterator - 10));
		ASSERT_EQ(9, *--iterator);
		ASSERT_EQ(8, *--iterator);
		ASSERT_EQ(7, *--iterator);
		ASSERT_EQ(6, *--iterator);
		ASSERT_EQ(5, *--iterator);
		ASSERT_EQ(4, *--iterator);
		ASSERT_EQ(3, *--iterator);
		ASSERT_EQ(2, *--iterator);
		ASSERT_EQ(1, *--iterator);
		ASSERT_EQ(0, *--iterator);
	}

	/// end 関数 (const_iterator 返却版) をテストする。
	TEST_F(LimitedVectorTest, testEndAsConst)
	{
		LimitedVector<int, 10> limitedVector1{ 0 };
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		LimitedVector<int, 10>::const_iterator iterator = limitedVector2.end();

		ASSERT_EQ(0, *(limitedVector1.end() - 1));
		ASSERT_EQ(9, *(iterator - 1));
		ASSERT_EQ(8, *(iterator - 2));
		ASSERT_EQ(7, *(iterator - 3));
		ASSERT_EQ(6, *(iterator - 4));
		ASSERT_EQ(5, *(iterator - 5));
		ASSERT_EQ(4, *(iterator - 6));
		ASSERT_EQ(3, *(iterator - 7));
		ASSERT_EQ(2, *(iterator - 8));
		ASSERT_EQ(1, *(iterator - 9));
		ASSERT_EQ(0, *(iterator - 10));
		ASSERT_EQ(9, *--iterator);
		ASSERT_EQ(8, *--iterator);
		ASSERT_EQ(7, *--iterator);
		ASSERT_EQ(6, *--iterator);
		ASSERT_EQ(5, *--iterator);
		ASSERT_EQ(4, *--iterator);
		ASSERT_EQ(3, *--iterator);
		ASSERT_EQ(2, *--iterator);
		ASSERT_EQ(1, *--iterator);
		ASSERT_EQ(0, *--iterator);
	}

	/// insert 関数をテストする。
	TEST_F(LimitedVectorTest, testInsert)
	{
		LimitedVector<int, 10> limitedVector;
		LimitedVector<int, 10>::iterator iterator;

		// 要素を挿入する。
		iterator = limitedVector.insert(limitedVector.begin(), 1);
		ASSERT_EQ((LimitedVector<int, 10>{ 1 }), limitedVector);

		// 要素を先頭に挿入する。
		iterator = limitedVector.insert(limitedVector.begin(), 2);
		ASSERT_EQ((LimitedVector<int, 10>{ 2, 1 }), limitedVector);

		// 要素を末尾に挿入する。
		iterator = limitedVector.insert(limitedVector.end(), 3);
		ASSERT_EQ((LimitedVector<int, 10>{ 2, 1, 3 }), limitedVector);

		// 要素を間に挿入する。
		iterator = limitedVector.insert(limitedVector.begin() + 1, 4);
		iterator = limitedVector.insert(iterator + 1, 5);
		iterator = limitedVector.insert(iterator + 1, 6);
		iterator = limitedVector.insert(iterator + 1, 7);
		iterator = limitedVector.insert(iterator + 1, 8);
		iterator = limitedVector.insert(iterator + 1, 9);
		iterator = limitedVector.insert(iterator + 1, 10);
		ASSERT_EQ((LimitedVector<int, 10>{ 2, 4, 5, 6, 7, 8, 9, 10, 1, 3 }), limitedVector);

#if OPENRIICHI_ENABLE_ASSERTION == 1
		LimitedVector<int, 10> limitedVector1;
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		ASSERT_THROW(limitedVector1.insert(limitedVector1.begin() + 1, 10), OpenRiichiAssertion);
		ASSERT_THROW(limitedVector2.insert(limitedVector2.begin(), 10), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// erase 関数をテストする。
	TEST_F(LimitedVectorTest, testErase)
	{
		LimitedVector<int, 10> limitedVector;
		LimitedVector<int, 10>::iterator iterator;

		// 要素を削除する。
		limitedVector.push_back(1);
		iterator = limitedVector.erase(limitedVector.begin());
		ASSERT_EQ((LimitedVector<int, 10>()), limitedVector);

		// 先頭の要素を削除する。
		limitedVector.push_back(2);
		limitedVector.push_back(3);
		iterator = limitedVector.erase(limitedVector.begin());
		ASSERT_EQ((LimitedVector<int, 10>{ 3 }), limitedVector);

		// 末尾の要素を削除する。
		limitedVector.insert(limitedVector.begin(), 4);
		iterator = limitedVector.erase(limitedVector.end() - 1);
		ASSERT_EQ((LimitedVector<int, 10>{ 4 }), limitedVector);

		// 間の要素を削除する。
		limitedVector.push_back(5);
		limitedVector.push_back(6);
		limitedVector.push_back(7);
		limitedVector.push_back(8);
		limitedVector.push_back(9);
		limitedVector.push_back(10);
		limitedVector.push_back(11);
		limitedVector.push_back(12);
		limitedVector.push_back(13);
		limitedVector.erase(limitedVector.begin() + 1);
		limitedVector.erase(limitedVector.begin() + 3);
		limitedVector.erase(limitedVector.begin() + 5);
		ASSERT_EQ((LimitedVector<int, 10>{ 4, 6, 7, 9, 10, 12, 13 }), limitedVector);

		// 先頭の要素を削除する (要素配列サイズ最大時)
		limitedVector.push_back(14);
		limitedVector.push_back(15);
		limitedVector.push_back(16);
		limitedVector.erase(limitedVector.begin());
		ASSERT_EQ((LimitedVector<int, 10>{ 6, 7, 9, 10, 12, 13, 14, 15, 16 }), limitedVector);

		// 末尾の要素を削除する (要素配列サイズ最大時)
		limitedVector.insert(limitedVector.begin(), 17);
		limitedVector.erase(limitedVector.end() - 1);
		ASSERT_EQ((LimitedVector<int, 10>{ 17, 6, 7, 9, 10, 12, 13, 14, 15 }), limitedVector);

#if OPENRIICHI_ENABLE_ASSERTION == 1
		LimitedVector<int, 10> limitedVector1;
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		ASSERT_THROW(limitedVector1.erase(limitedVector1.begin()), OpenRiichiAssertion);
		ASSERT_THROW(limitedVector2.erase(limitedVector2.end()), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// clear 関数をテストする。
	TEST_F(LimitedVectorTest, testClear)
	{
		LimitedVector<int, 10> limitedVector{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		limitedVector.clear();
		ASSERT_EQ((LimitedVector<int, 10>()), limitedVector);
	}

	/// == 演算子をテストする。
	TEST_F(LimitedVectorTest, testEquals)
	{
		LimitedVector<int, 10> limitedVector1;
		LimitedVector<int, 10> limitedVector2{ 0 };
		LimitedVector<int, 10> limitedVector3{ 1 };
		LimitedVector<int, 10> limitedVector4{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		LimitedVector<int, 10> limitedVector5{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 10 };

		// 自身と比較する。
		ASSERT_TRUE(limitedVector1 == limitedVector1);
		ASSERT_TRUE(limitedVector2 == limitedVector2);
		ASSERT_TRUE(limitedVector3 == limitedVector3);
		ASSERT_TRUE(limitedVector4 == limitedVector4);
		ASSERT_TRUE(limitedVector5 == limitedVector5);

		// 同じ有限可変長配列と比較する。
		ASSERT_TRUE(limitedVector1 == (LimitedVector<int, 10>()));
		ASSERT_TRUE(limitedVector2 == (LimitedVector<int, 10>{ 0 }));
		ASSERT_TRUE(limitedVector3 == (LimitedVector<int, 10>{ 1 }));
		ASSERT_TRUE(limitedVector4 == (LimitedVector<int, 10>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }));
		ASSERT_TRUE(limitedVector5 == (LimitedVector<int, 10>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 10 }));

		// 異なる有限可変長配列と比較する。
		vector<LimitedVector<int, 10>> limitedVectors{ limitedVector1, limitedVector2, limitedVector3, limitedVector4, limitedVector5 };
		for (size_t i = 0; i < limitedVectors.size(); ++i) {
			for (size_t j = 0; j < limitedVectors.size(); ++j) {
				if (i != j) {
					ASSERT_FALSE(limitedVectors[i] == limitedVectors[j]);
				}
			}
		}
	}

	/// != 演算子をテストする。
	TEST_F(LimitedVectorTest, testNotEquals)
	{
		LimitedVector<int, 10> limitedVector1;
		LimitedVector<int, 10> limitedVector2{ 0 };
		LimitedVector<int, 10> limitedVector3{ 1 };
		LimitedVector<int, 10> limitedVector4{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		LimitedVector<int, 10> limitedVector5{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 10 };

		// 自身と比較する。
		ASSERT_FALSE(limitedVector1 != limitedVector1);
		ASSERT_FALSE(limitedVector2 != limitedVector2);
		ASSERT_FALSE(limitedVector3 != limitedVector3);
		ASSERT_FALSE(limitedVector4 != limitedVector4);
		ASSERT_FALSE(limitedVector5 != limitedVector5);

		// 同じ有限可変長配列と比較する。
		ASSERT_FALSE(limitedVector1 != (LimitedVector<int, 10>()));
		ASSERT_FALSE(limitedVector2 != (LimitedVector<int, 10>{ 0 }));
		ASSERT_FALSE(limitedVector3 != (LimitedVector<int, 10>{ 1 }));
		ASSERT_FALSE(limitedVector4 != (LimitedVector<int, 10>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }));
		ASSERT_FALSE(limitedVector5 != (LimitedVector<int, 10>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 10 }));

		// 異なる有限可変長配列と比較する。
		vector<LimitedVector<int, 10>> limitedVectors{ limitedVector1, limitedVector2, limitedVector3, limitedVector4, limitedVector5 };
		for (size_t i = 0; i < limitedVectors.size(); ++i) {
			for (size_t j = 0; j < limitedVectors.size(); ++j) {
				if (i != j) {
					ASSERT_TRUE(limitedVectors[i] != limitedVectors[j]);
				}
			}
		}
	}

	/// = 演算子をテストする。
	TEST_F(LimitedVectorTest, testSubstitute)
	{
#if OPENRIICHI_ENABLE_ASSERTION == 1
		LimitedVector<int, 10> limitedVector;
		ASSERT_THROW((limitedVector = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// [] 演算子 (非 const 版) をテストする。
	TEST_F(LimitedVectorTest, testIndex)
	{
		LimitedVector<int, 10> limitedVector{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		limitedVector[0] = 10;
		limitedVector[5] = 11;
		limitedVector[9] = 12;
		ASSERT_EQ((LimitedVector<int, 10>{ 10, 1, 2, 3, 4, 11, 6, 7, 8, 12 }), limitedVector);

#if OPENRIICHI_ENABLE_ASSERTION == 1
		ASSERT_THROW(limitedVector[10] = 13, OpenRiichiAssertion);
		ASSERT_THROW((LimitedVector<int, 10>()[0] = 14), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// at 関数 (const 版) をテストする。
	TEST_F(LimitedVectorTest, testIndexAsConst)
	{
		const LimitedVector<int, 10> limitedVector{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		ASSERT_EQ(0, limitedVector[0]);
		ASSERT_EQ(5, limitedVector[5]);
		ASSERT_EQ(9, limitedVector[9]);

#if OPENRIICHI_ENABLE_ASSERTION == 1
		ASSERT_THROW(limitedVector[10], OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}
}
