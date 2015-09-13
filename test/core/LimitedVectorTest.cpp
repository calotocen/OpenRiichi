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

	/// count 関数をテストする。
	TEST_F(LimitedVectorTest, testCount)
	{
		LimitedVector<int, 10> limitedVector1;
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4 };
		LimitedVector<int, 10> limitedVector3{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		ASSERT_EQ(0, limitedVector1.count());
		ASSERT_EQ(5, limitedVector2.count());
		ASSERT_EQ(10, limitedVector3.count());
	}

	/// get 関数をテストする。
	TEST_F(LimitedVectorTest, testGet)
	{
		LimitedVector<int, 10> limitedVector{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		ASSERT_EQ(0, limitedVector.get(0));
		ASSERT_EQ(5, limitedVector.get(5));
		ASSERT_EQ(9, limitedVector.get(9));

#if OPENRIICHI_ENABLE_ASSERTION == 1
		ASSERT_THROW(limitedVector.get(10), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// getFirst 関数をテストする。
	TEST_F(LimitedVectorTest, testGetFirst)
	{
		LimitedVector<int, 10> limitedVector1{ 0 };
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		ASSERT_EQ(0, limitedVector1.getFirst());
		ASSERT_EQ(0, limitedVector2.getFirst());

#if OPENRIICHI_ENABLE_ASSERTION == 1
		ASSERT_THROW((LimitedVector<int, 10>().getFirst()), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// getLast 関数をテストする。
	TEST_F(LimitedVectorTest, testGetLast)
	{
		LimitedVector<int, 10> limitedVector1{ 0 };
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		ASSERT_EQ(0, limitedVector1.getLast());
		ASSERT_EQ(9, limitedVector2.getLast());

#if OPENRIICHI_ENABLE_ASSERTION == 1
		ASSERT_THROW((LimitedVector<int, 10>().getLast()), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// set 関数をテストする。
	TEST_F(LimitedVectorTest, testSet)
	{
		LimitedVector<int, 10> limitedVector{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		limitedVector.set(0, 10);
		limitedVector.set(5, 11);
		limitedVector.set(9, 12);
		ASSERT_EQ((LimitedVector<int, 10>{ 10, 1, 2, 3, 4, 11, 6, 7, 8, 12 }), limitedVector);

#if OPENRIICHI_ENABLE_ASSERTION == 1
		ASSERT_THROW(limitedVector.get(10), OpenRiichiAssertion);
		ASSERT_THROW((LimitedVector<int, 10>().set(0, 1)), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// add 関数をテストする。
	TEST_F(LimitedVectorTest, testAdd)
	{
		LimitedVector<int, 10> limitedVector;

		limitedVector.add(0);
		limitedVector.add(1);
		limitedVector.add(2);
		limitedVector.add(3);
		limitedVector.add(4);
		limitedVector.add(5);
		limitedVector.add(6);
		limitedVector.add(7);
		limitedVector.add(8);
		limitedVector.add(9);
		ASSERT_EQ((LimitedVector<int, 10>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }), limitedVector);

#if OPENRIICHI_ENABLE_ASSERTION == 1
		ASSERT_THROW(limitedVector.add(10), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// getHeadIterator 関数をテストする。
	TEST_F(LimitedVectorTest, testGetHeadIterator)
	{
		LimitedVector<int, 10> limitedVector1{ 0 };
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		LimitedVector<int, 10>::Iterator iterator = limitedVector2.getHeadIterator();

		ASSERT_EQ(0, *limitedVector1.getHeadIterator());
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

	/// getHeadConstIterator 関数をテストする。
	TEST_F(LimitedVectorTest, testGetHeadConstIterator)
	{
		LimitedVector<int, 10> limitedVector1{ 0 };
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		LimitedVector<int, 10>::ConstIterator iterator = limitedVector2.getHeadConstIterator();

		ASSERT_EQ(0, *limitedVector1.getHeadConstIterator());
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

	/// getTailIterator 関数をテストする。
	TEST_F(LimitedVectorTest, testGetTailIterator)
	{
		LimitedVector<int, 10> limitedVector1{ 0 };
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		LimitedVector<int, 10>::Iterator iterator = limitedVector2.getTailIterator();

		ASSERT_EQ(0, *(limitedVector1.getTailIterator() - 1));
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

	/// getTailConstIterator 関数をテストする。
	TEST_F(LimitedVectorTest, testGetTailConstIterator)
	{
		LimitedVector<int, 10> limitedVector1{ 0 };
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		LimitedVector<int, 10>::ConstIterator iterator = limitedVector2.getTailConstIterator();

		ASSERT_EQ(0, *(limitedVector1.getTailConstIterator() - 1));
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

	/// insert (イテレータ版) 関数をテストする。
	TEST_F(LimitedVectorTest, testInsertUsingIterator)
	{
		LimitedVector<int, 10> limitedVector;
		LimitedVector<int, 10>::Iterator iterator;

		// 要素を挿入する。
		iterator = limitedVector.insert(limitedVector.getHeadIterator(), 1);
		ASSERT_EQ((LimitedVector<int, 10>{ 1 }), limitedVector);

		// 要素を先頭に挿入する。
		iterator = limitedVector.insert(limitedVector.getHeadIterator(), 2);
		ASSERT_EQ((LimitedVector<int, 10>{ 2, 1 }), limitedVector);

		// 要素を末尾に挿入する。
		iterator = limitedVector.insert(limitedVector.getTailIterator(), 3);
		ASSERT_EQ((LimitedVector<int, 10>{ 2, 1, 3 }), limitedVector);

		// 要素を間に挿入する。
		iterator = limitedVector.insert(limitedVector.getHeadIterator() + 1, 4);
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
		ASSERT_THROW(limitedVector1.insert(limitedVector1.getHeadIterator() + 1, 10), OpenRiichiAssertion);
		ASSERT_THROW(limitedVector2.insert(limitedVector2.getHeadIterator(), 10), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// insert (添え字版) をテストする。
	TEST_F(LimitedVectorTest, testInsertUsingIndex)
	{
		LimitedVector<int, 10> limitedVector;

		// 要素を挿入する。
		limitedVector.insert(0, 1);
		ASSERT_EQ((LimitedVector<int, 10>{ 1 }), limitedVector);

		// 要素を先頭に挿入する。
		limitedVector.insert(0, 2);
		ASSERT_EQ((LimitedVector<int, 10>{ 2, 1 }), limitedVector);

		// 要素を末尾に挿入する。
		limitedVector.insert(limitedVector.count(), 3);
		ASSERT_EQ((LimitedVector<int, 10>{ 2, 1, 3 }), limitedVector);

		// 要素を間に挿入する。
		limitedVector.insert(1, 4);
		limitedVector.insert(2, 5);
		limitedVector.insert(3, 6);
		limitedVector.insert(4, 7);
		limitedVector.insert(5, 8);
		limitedVector.insert(6, 9);
		limitedVector.insert(7, 10);
		ASSERT_EQ((LimitedVector<int, 10>{ 2, 4, 5, 6, 7, 8, 9, 10, 1, 3 }), limitedVector);

#if OPENRIICHI_ENABLE_ASSERTION == 1
		LimitedVector<int, 10> limitedVector1;
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		ASSERT_THROW(limitedVector1.insert(1, 10), OpenRiichiAssertion);
		ASSERT_THROW(limitedVector2.insert(0, 10), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	/// remove (イテレータ版) をテストする。
	TEST_F(LimitedVectorTest, testRemoveUsingIndexAndClear)
	{
		LimitedVector<int, 10> limitedVector;
		LimitedVector<int, 10>::Iterator iterator;

		// 要素を削除する。
		limitedVector.add(1);
		iterator = limitedVector.remove(limitedVector.getHeadIterator());
		ASSERT_EQ((LimitedVector<int, 10>()), limitedVector);

		// 先頭の要素を削除する。
		limitedVector.add(2);
		limitedVector.add(3);
		iterator = limitedVector.remove(limitedVector.getHeadIterator());
		ASSERT_EQ((LimitedVector<int, 10>{ 3 }), limitedVector);

		// 末尾の要素を削除する。
		limitedVector.insert(limitedVector.getHeadIterator(), 4);
		iterator = limitedVector.remove(limitedVector.getTailIterator() - 1);
		ASSERT_EQ((LimitedVector<int, 10>{ 4 }), limitedVector);

		// 間の要素を削除する。
		limitedVector.add(5);
		limitedVector.add(6);
		limitedVector.add(7);
		limitedVector.add(8);
		limitedVector.add(9);
		limitedVector.add(10);
		limitedVector.add(11);
		limitedVector.add(12);
		limitedVector.add(13);
		limitedVector.remove(limitedVector.getHeadIterator() + 1);
		limitedVector.remove(limitedVector.getHeadIterator() + 3);
		limitedVector.remove(limitedVector.getHeadIterator() + 5);
		ASSERT_EQ((LimitedVector<int, 10>{ 4, 6, 7, 9, 10, 12, 13 }), limitedVector);

		// 先頭の要素を削除する (要素配列サイズ最大時)
		limitedVector.add(14);
		limitedVector.add(15);
		limitedVector.add(16);
		limitedVector.remove(limitedVector.getHeadIterator());
		ASSERT_EQ((LimitedVector<int, 10>{ 6, 7, 9, 10, 12, 13, 14, 15, 16 }), limitedVector);

		// 末尾の要素を削除する (要素配列サイズ最大時)
		limitedVector.insert(limitedVector.getHeadIterator(), 17);
		limitedVector.remove(limitedVector.getTailIterator() - 1);
		ASSERT_EQ((LimitedVector<int, 10>{ 17, 6, 7, 9, 10, 12, 13, 14, 15 }), limitedVector);

#if OPENRIICHI_ENABLE_ASSERTION == 1
		LimitedVector<int, 10> limitedVector1;
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		ASSERT_THROW(limitedVector1.remove(limitedVector1.getHeadIterator()), OpenRiichiAssertion);
		ASSERT_THROW(limitedVector2.remove(limitedVector2.getTailIterator()), OpenRiichiAssertion);
#endif // OPENRIICHI_ENABLE_ASSERTION == 1
	}

	// remove (添え字版) をテストする。
	TEST_F(LimitedVectorTest, testRemoveUsingIndex)
	{
		LimitedVector<int, 10> limitedVector;

		// 要素を削除する。
		limitedVector.add(1);
		limitedVector.remove(0);
		ASSERT_EQ((LimitedVector<int, 10>()), limitedVector);

		// 先頭の要素を削除する。
		limitedVector.add(2);
		limitedVector.add(3);
		limitedVector.remove(0);
		ASSERT_EQ((LimitedVector<int, 10>{ 3 }), limitedVector);

		// 末尾の要素を削除する。
		limitedVector.insert(0, 4);
		limitedVector.remove(limitedVector.count() - 1);
		ASSERT_EQ((LimitedVector<int, 10>{ 4 }), limitedVector);

		// 間の要素を削除する。
		limitedVector.add(5);
		limitedVector.add(6);
		limitedVector.add(7);
		limitedVector.add(8);
		limitedVector.add(9);
		limitedVector.add(10);
		limitedVector.add(11);
		limitedVector.add(12);
		limitedVector.add(13);
		limitedVector.remove(1);
		limitedVector.remove(3);
		limitedVector.remove(5);
		ASSERT_EQ((LimitedVector<int, 10>{ 4, 6, 7, 9, 10, 12, 13 }), limitedVector);

		// 先頭の要素を削除する (要素配列サイズ最大時)
		limitedVector.add(14);
		limitedVector.add(15);
		limitedVector.add(16);
		limitedVector.remove(0);
		ASSERT_EQ((LimitedVector<int, 10>{ 6, 7, 9, 10, 12, 13, 14, 15, 16 }), limitedVector);

		// 末尾の要素を削除する (要素配列サイズ最大時)
		limitedVector.insert(limitedVector.getHeadIterator(), 17);
		limitedVector.remove(limitedVector.count() - 1);
		ASSERT_EQ((LimitedVector<int, 10>{ 17, 6, 7, 9, 10, 12, 13, 14, 15 }), limitedVector);

#if OPENRIICHI_ENABLE_ASSERTION == 1
		LimitedVector<int, 10> limitedVector1;
		LimitedVector<int, 10> limitedVector2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		ASSERT_THROW(limitedVector1.remove(0), OpenRiichiAssertion);
		ASSERT_THROW(limitedVector2.remove(limitedVector2.count()), OpenRiichiAssertion);
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
		for (auto i = 0; i < limitedVectors.size(); ++i) {
			for (auto j = 0; j < limitedVectors.size(); ++j) {
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
		for (auto i = 0; i < limitedVectors.size(); ++i) {
			for (auto j = 0; j < limitedVectors.size(); ++j) {
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
}
