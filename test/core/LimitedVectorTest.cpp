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
#include <LimitedVector.h>


namespace openriichi
{
	class LimitedVectorTest : public ::testing::Test {};


	// 要素数の取得，要素の取得，要素の設定，要素の追加，およびイテレータをテストする。
	TEST_F(LimitedVectorTest, testCountAndGetAndSetAndAddAndIteratorAndConstIterator)
	{
		LimitedVector<int, 10> limitedVector;
		LimitedVector<int, 10>::Iterator iterator;
		LimitedVector<int, 10>::ConstIterator constIterator;

		// 生成直後の配列は空である。
		ASSERT_EQ(0, limitedVector.count());
		ASSERT_EQ(limitedVector.getHeadIterator(), limitedVector.getTailIterator());
		ASSERT_EQ(limitedVector.getHeadConstIterator(), limitedVector.getTailConstIterator());

		// 要素を追加する。
		limitedVector.add(1);
		ASSERT_EQ(1, limitedVector.count());
		ASSERT_EQ(1, limitedVector.get(0));
		ASSERT_EQ(1, limitedVector.getFirst());
		ASSERT_EQ(1, limitedVector.getLast());
		iterator = limitedVector.getHeadIterator();
		ASSERT_EQ(1, *iterator++);
		ASSERT_EQ(limitedVector.getTailIterator(), iterator);
		constIterator = limitedVector.getHeadConstIterator();
		ASSERT_EQ(1, *constIterator++);
		ASSERT_EQ(limitedVector.getTailConstIterator(), constIterator);

		// 要素を追加する。
		limitedVector.add(2);
		ASSERT_EQ(2, limitedVector.count());
		ASSERT_EQ(1, limitedVector.get(0));
		ASSERT_EQ(2, limitedVector.get(1));
		ASSERT_EQ(1, limitedVector.getFirst());
		ASSERT_EQ(2, limitedVector.getLast());
		iterator = limitedVector.getHeadIterator();
		ASSERT_EQ(1, *iterator++);
		ASSERT_EQ(2, *iterator++);
		ASSERT_EQ(limitedVector.getTailIterator(), iterator);
		constIterator = limitedVector.getHeadConstIterator();
		ASSERT_EQ(1, *constIterator++);
		ASSERT_EQ(2, *constIterator++);
		ASSERT_EQ(limitedVector.getTailConstIterator(), constIterator);

		// 要素を追加する。
		limitedVector.add(3);
		limitedVector.add(4);
		limitedVector.add(5);
		limitedVector.add(6);
		limitedVector.add(7);
		limitedVector.add(8);
		limitedVector.add(9);
		limitedVector.add(10);
		ASSERT_EQ(10, limitedVector.count());
		ASSERT_EQ(1, limitedVector.get(0));
		ASSERT_EQ(2, limitedVector.get(1));
		ASSERT_EQ(3, limitedVector.get(2));
		ASSERT_EQ(4, limitedVector.get(3));
		ASSERT_EQ(5, limitedVector.get(4));
		ASSERT_EQ(6, limitedVector.get(5));
		ASSERT_EQ(7, limitedVector.get(6));
		ASSERT_EQ(8, limitedVector.get(7));
		ASSERT_EQ(9, limitedVector.get(8));
		ASSERT_EQ(10, limitedVector.get(9));
		ASSERT_EQ(1, limitedVector.getFirst());
		ASSERT_EQ(10, limitedVector.getLast());
		iterator = limitedVector.getHeadIterator();
		ASSERT_EQ(1, *iterator++);
		ASSERT_EQ(2, *iterator++);
		ASSERT_EQ(3, *iterator++);
		ASSERT_EQ(4, *iterator++);
		ASSERT_EQ(5, *iterator++);
		ASSERT_EQ(6, *iterator++);
		ASSERT_EQ(7, *iterator++);
		ASSERT_EQ(8, *iterator++);
		ASSERT_EQ(9, *iterator++);
		ASSERT_EQ(10, *iterator++);
		ASSERT_EQ(limitedVector.getTailIterator(), iterator);
		constIterator = limitedVector.getHeadConstIterator();
		ASSERT_EQ(1, *constIterator++);
		ASSERT_EQ(2, *constIterator++);
		ASSERT_EQ(3, *constIterator++);
		ASSERT_EQ(4, *constIterator++);
		ASSERT_EQ(5, *constIterator++);
		ASSERT_EQ(6, *constIterator++);
		ASSERT_EQ(7, *constIterator++);
		ASSERT_EQ(8, *constIterator++);
		ASSERT_EQ(9, *constIterator++);
		ASSERT_EQ(10, *constIterator++);
		ASSERT_EQ(limitedVector.getTailConstIterator(), constIterator);

		// 要素を設定する。
		limitedVector.set(0, 11);
		limitedVector.set(5, 12);
		limitedVector.set(9, 13);
		ASSERT_EQ(10, limitedVector.count());
		ASSERT_EQ(11, limitedVector.get(0));
		ASSERT_EQ(2, limitedVector.get(1));
		ASSERT_EQ(3, limitedVector.get(2));
		ASSERT_EQ(4, limitedVector.get(3));
		ASSERT_EQ(5, limitedVector.get(4));
		ASSERT_EQ(12, limitedVector.get(5));
		ASSERT_EQ(7, limitedVector.get(6));
		ASSERT_EQ(8, limitedVector.get(7));
		ASSERT_EQ(9, limitedVector.get(8));
		ASSERT_EQ(13, limitedVector.get(9));
		iterator = limitedVector.getHeadIterator();
		ASSERT_EQ(11, *iterator++);
		ASSERT_EQ(2, *iterator++);
		ASSERT_EQ(3, *iterator++);
		ASSERT_EQ(4, *iterator++);
		ASSERT_EQ(5, *iterator++);
		ASSERT_EQ(12, *iterator++);
		ASSERT_EQ(7, *iterator++);
		ASSERT_EQ(8, *iterator++);
		ASSERT_EQ(9, *iterator++);
		ASSERT_EQ(13, *iterator++);
		ASSERT_EQ(limitedVector.getTailIterator(), iterator);
		constIterator = limitedVector.getHeadConstIterator();
		ASSERT_EQ(11, *constIterator++);
		ASSERT_EQ(2, *constIterator++);
		ASSERT_EQ(3, *constIterator++);
		ASSERT_EQ(4, *constIterator++);
		ASSERT_EQ(5, *constIterator++);
		ASSERT_EQ(12, *constIterator++);
		ASSERT_EQ(7, *constIterator++);
		ASSERT_EQ(8, *constIterator++);
		ASSERT_EQ(9, *constIterator++);
		ASSERT_EQ(13, *constIterator++);
		ASSERT_EQ(limitedVector.getTailConstIterator(), constIterator);
	}

	// 要素の挿入 (イテレータ版) をテストする。
	TEST_F(LimitedVectorTest, testInsertUsingIterator)
	{
		LimitedVector<int, 10> limitedVector;
		LimitedVector<int, 10>::Iterator iterator;

		// 要素を挿入する。
		iterator = limitedVector.insert(limitedVector.getHeadIterator(), 1);
		ASSERT_EQ(limitedVector.getHeadIterator(), iterator);
		ASSERT_EQ(1, limitedVector.count());
		ASSERT_EQ(1, limitedVector.get(0));

		// 要素を先頭に挿入する。
		iterator = limitedVector.insert(limitedVector.getHeadIterator(), 2);
		ASSERT_EQ(limitedVector.getHeadIterator(), iterator);
		ASSERT_EQ(2, limitedVector.count());
		ASSERT_EQ(2, limitedVector.get(0));
		ASSERT_EQ(1, limitedVector.get(1));

		// 要素を末尾に挿入する。
		iterator = limitedVector.insert(limitedVector.getTailIterator(), 3);
		ASSERT_EQ(limitedVector.getTailIterator() - 1, iterator);
		ASSERT_EQ(3, limitedVector.count());
		ASSERT_EQ(2, limitedVector.get(0));
		ASSERT_EQ(1, limitedVector.get(1));
		ASSERT_EQ(3, limitedVector.get(2));

		// 要素を間に挿入する。
		iterator = limitedVector.insert(limitedVector.getHeadIterator() + 1, 4);
		iterator = limitedVector.insert(iterator + 1, 5);
		iterator = limitedVector.insert(iterator + 1, 6);
		iterator = limitedVector.insert(iterator + 1, 7);
		iterator = limitedVector.insert(iterator + 1, 8);
		iterator = limitedVector.insert(iterator + 1, 9);
		iterator = limitedVector.insert(iterator + 1, 10);
		ASSERT_EQ(limitedVector.getHeadIterator() + 7, iterator);
		ASSERT_EQ(10, limitedVector.count());
		ASSERT_EQ(2, limitedVector.get(0));
		ASSERT_EQ(4, limitedVector.get(1));
		ASSERT_EQ(5, limitedVector.get(2));
		ASSERT_EQ(6, limitedVector.get(3));
		ASSERT_EQ(7, limitedVector.get(4));
		ASSERT_EQ(8, limitedVector.get(5));
		ASSERT_EQ(9, limitedVector.get(6));
		ASSERT_EQ(10, limitedVector.get(7));
		ASSERT_EQ(1, limitedVector.get(8));
		ASSERT_EQ(3, limitedVector.get(9));
	}

	// 要素の挿入 (添え字版) をテストする。
	TEST_F(LimitedVectorTest, testInsertUsingIndex)
	{
		LimitedVector<int, 10> limitedVector;

		// 要素を挿入する。
		limitedVector.insert(0, 1);
		ASSERT_EQ(1, limitedVector.count());
		ASSERT_EQ(1, limitedVector.get(0));

		// 要素を先頭に挿入する。
		limitedVector.insert(0, 2);
		ASSERT_EQ(2, limitedVector.count());
		ASSERT_EQ(2, limitedVector.get(0));
		ASSERT_EQ(1, limitedVector.get(1));

		// 要素を末尾に挿入する。
		limitedVector.insert(limitedVector.count(), 3);
		ASSERT_EQ(3, limitedVector.count());
		ASSERT_EQ(2, limitedVector.get(0));
		ASSERT_EQ(1, limitedVector.get(1));
		ASSERT_EQ(3, limitedVector.get(2));

		// 要素を間に挿入する。
		limitedVector.insert(1, 4);
		limitedVector.insert(2, 5);
		limitedVector.insert(3, 6);
		limitedVector.insert(4, 7);
		limitedVector.insert(5, 8);
		limitedVector.insert(6, 9);
		limitedVector.insert(7, 10);
		ASSERT_EQ(10, limitedVector.count());
		ASSERT_EQ(2, limitedVector.get(0));
		ASSERT_EQ(4, limitedVector.get(1));
		ASSERT_EQ(5, limitedVector.get(2));
		ASSERT_EQ(6, limitedVector.get(3));
		ASSERT_EQ(7, limitedVector.get(4));
		ASSERT_EQ(8, limitedVector.get(5));
		ASSERT_EQ(9, limitedVector.get(6));
		ASSERT_EQ(10, limitedVector.get(7));
		ASSERT_EQ(1, limitedVector.get(8));
		ASSERT_EQ(3, limitedVector.get(9));
	}

	// 要素の削除 (イテレータ版) と要素の全削除をテストする。
	TEST_F(LimitedVectorTest, testRemoveUsingIndexAndClear)
	{
		LimitedVector<int, 10> limitedVector;
		LimitedVector<int, 10>::Iterator iterator;

		// 要素を削除する。
		limitedVector.add(1);
		iterator = limitedVector.remove(limitedVector.getHeadIterator());
		ASSERT_EQ(limitedVector.getHeadIterator(), iterator);
		ASSERT_EQ(0, limitedVector.count());

		// 先頭の要素を削除する。
		limitedVector.add(2);
		limitedVector.add(3);
		iterator = limitedVector.remove(limitedVector.getHeadIterator());
		ASSERT_EQ(limitedVector.getHeadIterator(), iterator);
		ASSERT_EQ(1, limitedVector.count());
		ASSERT_EQ(3, limitedVector.get(0));

		// 末尾の要素を削除する。
		limitedVector.insert(limitedVector.getHeadIterator(), 4);
		iterator = limitedVector.remove(limitedVector.getTailIterator() - 1);
		ASSERT_EQ(limitedVector.getTailIterator(), iterator);
		ASSERT_EQ(1, limitedVector.count());
		ASSERT_EQ(4, limitedVector.get(0));

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
		ASSERT_EQ(7, limitedVector.count());
		ASSERT_EQ(4, limitedVector.get(0));
		ASSERT_EQ(6, limitedVector.get(1));
		ASSERT_EQ(7, limitedVector.get(2));
		ASSERT_EQ(9, limitedVector.get(3));
		ASSERT_EQ(10, limitedVector.get(4));
		ASSERT_EQ(12, limitedVector.get(5));
		ASSERT_EQ(13, limitedVector.get(6));

		// 先頭の要素を削除する (要素配列サイズ最大時)
		limitedVector.add(14);
		limitedVector.add(15);
		limitedVector.add(16);
		limitedVector.remove(limitedVector.getHeadIterator());
		ASSERT_EQ(9, limitedVector.count());
		ASSERT_EQ(6, limitedVector.get(0));
		ASSERT_EQ(7, limitedVector.get(1));
		ASSERT_EQ(9, limitedVector.get(2));
		ASSERT_EQ(10, limitedVector.get(3));
		ASSERT_EQ(12, limitedVector.get(4));
		ASSERT_EQ(13, limitedVector.get(5));
		ASSERT_EQ(14, limitedVector.get(6));
		ASSERT_EQ(15, limitedVector.get(7));
		ASSERT_EQ(16, limitedVector.get(8));

		// 末尾の要素を削除する (要素配列サイズ最大時)
		limitedVector.insert(limitedVector.getHeadIterator(), 17);
		limitedVector.remove(limitedVector.getTailIterator() - 1);
		ASSERT_EQ(9, limitedVector.count());
		ASSERT_EQ(17, limitedVector.get(0));
		ASSERT_EQ(6, limitedVector.get(1));
		ASSERT_EQ(7, limitedVector.get(2));
		ASSERT_EQ(9, limitedVector.get(3));
		ASSERT_EQ(10, limitedVector.get(4));
		ASSERT_EQ(12, limitedVector.get(5));
		ASSERT_EQ(13, limitedVector.get(6));
		ASSERT_EQ(14, limitedVector.get(7));
		ASSERT_EQ(15, limitedVector.get(8));

		// 要素を全削除する。
		limitedVector.clear();
		ASSERT_EQ(0, limitedVector.count());
	}

	// 要素の削除 (添え字版) をテストする。
	TEST_F(LimitedVectorTest, testRemoveUsingIndex)
	{
		LimitedVector<int, 10> limitedVector;

		// 要素を削除する。
		limitedVector.add(1);
		limitedVector.remove(0);
		ASSERT_EQ(0, limitedVector.count());

		// 先頭の要素を削除する。
		limitedVector.add(2);
		limitedVector.add(3);
		limitedVector.remove(0);
		ASSERT_EQ(1, limitedVector.count());
		ASSERT_EQ(3, limitedVector.get(0));

		// 末尾の要素を削除する。
		limitedVector.insert(0, 4);
		limitedVector.remove(limitedVector.count() - 1);
		ASSERT_EQ(1, limitedVector.count());
		ASSERT_EQ(4, limitedVector.get(0));

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
		ASSERT_EQ(7, limitedVector.count());
		ASSERT_EQ(7, limitedVector.count());
		ASSERT_EQ(4, limitedVector.get(0));
		ASSERT_EQ(6, limitedVector.get(1));
		ASSERT_EQ(7, limitedVector.get(2));
		ASSERT_EQ(9, limitedVector.get(3));
		ASSERT_EQ(10, limitedVector.get(4));
		ASSERT_EQ(12, limitedVector.get(5));
		ASSERT_EQ(13, limitedVector.get(6));

		// 先頭の要素を削除する (要素配列サイズ最大時)
		limitedVector.add(14);
		limitedVector.add(15);
		limitedVector.add(16);
		limitedVector.remove(0);
		ASSERT_EQ(9, limitedVector.count());
		ASSERT_EQ(6, limitedVector.get(0));
		ASSERT_EQ(7, limitedVector.get(1));
		ASSERT_EQ(9, limitedVector.get(2));
		ASSERT_EQ(10, limitedVector.get(3));
		ASSERT_EQ(12, limitedVector.get(4));
		ASSERT_EQ(13, limitedVector.get(5));
		ASSERT_EQ(14, limitedVector.get(6));
		ASSERT_EQ(15, limitedVector.get(7));
		ASSERT_EQ(16, limitedVector.get(8));

		// 末尾の要素を削除する (要素配列サイズ最大時)
		limitedVector.insert(limitedVector.getHeadIterator(), 17);
		limitedVector.remove(limitedVector.count() - 1);
		ASSERT_EQ(9, limitedVector.count());
		ASSERT_EQ(17, limitedVector.get(0));
		ASSERT_EQ(6, limitedVector.get(1));
		ASSERT_EQ(7, limitedVector.get(2));
		ASSERT_EQ(9, limitedVector.get(3));
		ASSERT_EQ(10, limitedVector.get(4));
		ASSERT_EQ(12, limitedVector.get(5));
		ASSERT_EQ(13, limitedVector.get(6));
		ASSERT_EQ(14, limitedVector.get(7));
		ASSERT_EQ(15, limitedVector.get(8));
	}

	// 配列の比較をテストする。
	TEST_F(LimitedVectorTest, testEqualsAndNotEquals)
	{
		LimitedVector<int, 10> limitedVector1;
		LimitedVector<int, 10> limitedVector2;

		ASSERT_TRUE(limitedVector1 == limitedVector1);
		ASSERT_FALSE(limitedVector1 != limitedVector1);
		ASSERT_TRUE(limitedVector1 == limitedVector2);
		ASSERT_FALSE(limitedVector1 != limitedVector2);

		limitedVector1.add(1);
		ASSERT_FALSE(limitedVector1 == limitedVector2);
		ASSERT_TRUE(limitedVector1 != limitedVector2);

		limitedVector2.add(2);
		ASSERT_FALSE(limitedVector1 == limitedVector2);
		ASSERT_TRUE(limitedVector1 != limitedVector2);

		limitedVector1.add(3);
		limitedVector1.add(4);
		limitedVector1.add(5);
		limitedVector1.add(6);
		limitedVector1.add(7);
		limitedVector1.add(8);
		limitedVector1.add(9);
		limitedVector2.add(3);
		limitedVector2.add(4);
		limitedVector2.add(5);
		limitedVector2.add(6);
		limitedVector2.add(7);
		limitedVector2.add(8);
		limitedVector2.add(9);
		ASSERT_FALSE(limitedVector1 == limitedVector2);
		ASSERT_TRUE(limitedVector1 != limitedVector2);

		limitedVector2.set(0, 1);
		ASSERT_TRUE(limitedVector1 == limitedVector2);
		ASSERT_FALSE(limitedVector1 != limitedVector2);
	}

	// 初期化子を用いた生成／代入をテストする。
	TEST_F(LimitedVectorTest, testUsingInitializerList)
	{
		LimitedVector<int, 10> limitedVector1{ 1, 2, 3 };
		LimitedVector<int, 10> limitedVector2;

		ASSERT_EQ(3, limitedVector1.count());
		ASSERT_EQ(1, limitedVector1.get(0));
		ASSERT_EQ(2, limitedVector1.get(1));
		ASSERT_EQ(3, limitedVector1.get(2));

		limitedVector2 = { 1, 2, 3 };
		ASSERT_EQ(limitedVector1, limitedVector2);
	}
}
