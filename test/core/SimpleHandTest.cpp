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
#include <SimpleHand.h>


namespace openriichi
{
	class SimpleHandTest : public ::testing::Test {};

	/// インスタンスのサイズをテストする。
	TEST_F(SimpleHandTest, testSizeOfInstance)
	{
		SimpleHand hand;
		ASSERT_EQ(26, sizeof(hand));
	}

	// 牌数の取得，牌の取得，牌の設定，牌の追加，およびイテレータをテストする。
	TEST_F(SimpleHandTest, testCountTilesGetTileAndSetTileAndAddTileAndTilesIteratorAndTilesConstIterator)
	{
		SimpleHand hand;
		SimpleHand::TilesIterator iterator;
		SimpleHand::TilesConstIterator constIterator;

		// 生成直後の手牌は空である。
		ASSERT_EQ(0, hand.countTiles());
		ASSERT_EQ(hand.getHeadTilesIterator(), hand.getTailTilesIterator());

		// 一筒を追加する。
		hand.addTile(Tile(TileDesigns::BAMBOO, 1));
		ASSERT_EQ(1, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *hand.getTile(0));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *hand.getFirstTile());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *hand.getLastTile());
		iterator = hand.getHeadTilesIterator();
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *iterator++);
		ASSERT_EQ(hand.getTailTilesIterator(), iterator);
		constIterator = hand.getHeadTilesConstIterator();
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *constIterator++);
		ASSERT_EQ(hand.getTailTilesConstIterator(), constIterator);

		// 二筒を追加する。
		hand.addTile(Tile(TileDesigns::BAMBOO, 2));
		ASSERT_EQ(2, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *hand.getTile(0));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), *hand.getTile(1));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *hand.getFirstTile());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), *hand.getLastTile());
		iterator = hand.getHeadTilesIterator();
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), *iterator++);
		ASSERT_EQ(hand.getTailTilesIterator(), iterator);
		constIterator = hand.getHeadTilesConstIterator();
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), *constIterator++);
		ASSERT_EQ(hand.getTailTilesConstIterator(), constIterator);

		// 牌を追加する。
		hand.addTile(Tile(TileDesigns::BAMBOO, 3));
		hand.addTile(Tile(TileDesigns::BAMBOO, 4));
		hand.addTile(Tile(TileDesigns::BAMBOO, 5));
		hand.addTile(Tile(TileDesigns::BAMBOO, 6));
		hand.addTile(Tile(TileDesigns::BAMBOO, 7));
		hand.addTile(Tile(TileDesigns::BAMBOO, 8));
		hand.addTile(Tile(TileDesigns::BAMBOO, 9));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 1));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 2));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 3));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 4));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 5));
		ASSERT_EQ(14, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *hand.getTile(0));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), *hand.getTile(1));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *hand.getTile(2));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 4), *hand.getTile(3));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 5), *hand.getTile(4));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 6), *hand.getTile(5));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 7), *hand.getTile(6));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 8), *hand.getTile(7));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), *hand.getTile(8));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 1), *hand.getTile(9));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 2), *hand.getTile(10));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 3), *hand.getTile(11));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 4), *hand.getTile(12));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 5), *hand.getTile(13));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *hand.getFirstTile());
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 5), *hand.getLastTile());
		iterator = hand.getHeadTilesIterator();
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 4), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 5), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 6), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 7), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 8), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 1), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 2), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 3), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 4), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 5), *iterator++);
		ASSERT_EQ(hand.getTailTilesIterator(), iterator);
		constIterator = hand.getHeadTilesConstIterator();
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 4), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 5), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 6), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 7), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 8), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 1), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 2), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 3), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 4), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 5), *constIterator++);
		ASSERT_EQ(hand.getTailTilesConstIterator(), constIterator);

		// 牌を設定する。
		hand.setTile(0, Tile(TileDesigns::CHARACTERS, 6));
		hand.setTile(6, Tile(TileDesigns::CHARACTERS, 7));
		hand.setTile(13, Tile(TileDesigns::CHARACTERS, 8));
		ASSERT_EQ(14, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 6), *hand.getTile(0));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), *hand.getTile(1));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *hand.getTile(2));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 4), *hand.getTile(3));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 5), *hand.getTile(4));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 6), *hand.getTile(5));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 7), *hand.getTile(6));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 8), *hand.getTile(7));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), *hand.getTile(8));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 1), *hand.getTile(9));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 2), *hand.getTile(10));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 3), *hand.getTile(11));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 4), *hand.getTile(12));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 8), *hand.getTile(13));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 6), *hand.getFirstTile());
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 8), *hand.getLastTile());
		iterator = hand.getHeadTilesIterator();
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 6), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 4), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 5), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 6), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 7), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 8), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 1), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 2), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 3), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 4), *iterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 8), *iterator++);
		ASSERT_EQ(hand.getTailTilesIterator(), iterator);
		constIterator = hand.getHeadTilesConstIterator();
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 6), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 4), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 5), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 6), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 7), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 8), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 1), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 2), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 3), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 4), *constIterator++);
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 8), *constIterator++);
		ASSERT_EQ(hand.getTailTilesConstIterator(), constIterator);
	}

	// 牌の挿入 (イテレータ版) をテストする。
	TEST_F(SimpleHandTest, testInsertTilesUsingIterator)
	{
		SimpleHand hand;
		SimpleHand::TilesIterator iterator;

		// 一筒を挿入する。
		iterator = hand.insertTile(hand.getHeadTilesIterator(), Tile(TileDesigns::BAMBOO, 1));
		ASSERT_EQ(hand.getHeadTilesIterator(), iterator);
		ASSERT_EQ(1, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *hand.getTile(0));

		// 二筒を先頭に挿入する。
		iterator = hand.insertTile(hand.getHeadTilesIterator(), Tile(TileDesigns::BAMBOO, 2));
		ASSERT_EQ(hand.getHeadTilesIterator(), iterator);
		ASSERT_EQ(2, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), *hand.getTile(0));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *hand.getTile(1));

		// 三筒を末尾に挿入する。
		iterator = hand.insertTile(hand.getTailTilesIterator(), Tile(TileDesigns::BAMBOO, 3));
		ASSERT_EQ(hand.getTailTilesIterator() - 1, iterator);
		ASSERT_EQ(3, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), *hand.getTile(0));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *hand.getTile(1));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *hand.getTile(2));

		// 牌を間に挿入する。
		iterator = hand.insertTile(hand.getHeadTilesIterator() + 1, Tile(TileDesigns::BAMBOO, 4));
		iterator = hand.insertTile(iterator + 1, Tile(TileDesigns::BAMBOO, 5));
		iterator = hand.insertTile(iterator + 1, Tile(TileDesigns::BAMBOO, 6));
		iterator = hand.insertTile(iterator + 1, Tile(TileDesigns::BAMBOO, 7));
		iterator = hand.insertTile(iterator + 1, Tile(TileDesigns::BAMBOO, 8));
		iterator = hand.insertTile(iterator + 1, Tile(TileDesigns::BAMBOO, 9));
		iterator = hand.insertTile(iterator + 1, Tile(TileDesigns::CHARACTERS, 1));
		iterator = hand.insertTile(iterator + 1, Tile(TileDesigns::CHARACTERS, 2));
		iterator = hand.insertTile(iterator + 1, Tile(TileDesigns::CHARACTERS, 3));
		iterator = hand.insertTile(iterator + 1, Tile(TileDesigns::CHARACTERS, 4));
		iterator = hand.insertTile(iterator + 1, Tile(TileDesigns::CHARACTERS, 5));
		ASSERT_EQ(hand.getHeadTilesIterator() + 11, iterator);
		ASSERT_EQ(14, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), *hand.getTile(0));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 4), *hand.getTile(1));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 5), *hand.getTile(2));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 6), *hand.getTile(3));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 7), *hand.getTile(4));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 8), *hand.getTile(5));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), *hand.getTile(6));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 1), *hand.getTile(7));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 2), *hand.getTile(8));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 3), *hand.getTile(9));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 4), *hand.getTile(10));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 5), *hand.getTile(11));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *hand.getTile(12));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *hand.getTile(13));
	}

	// 牌の挿入 (添え字版) をテストする。
	TEST_F(SimpleHandTest, testInsertTilesUsingIndex)
	{
		SimpleHand hand;

		// 一筒を挿入する。
		hand.insertTile(0, Tile(TileDesigns::BAMBOO, 1));
		ASSERT_EQ(1, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *hand.getTile(0));

		// 二筒を先頭に挿入する。
		hand.insertTile(0, Tile(TileDesigns::BAMBOO, 2));
		ASSERT_EQ(2, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), *hand.getTile(0));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *hand.getTile(1));

		// 三筒を末尾に挿入する。
		hand.insertTile(hand.countTiles(), Tile(TileDesigns::BAMBOO, 3));
		ASSERT_EQ(3, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), *hand.getTile(0));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *hand.getTile(1));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *hand.getTile(2));

		// 牌を間に挿入する。
		hand.insertTile(1, Tile(TileDesigns::BAMBOO, 4));
		hand.insertTile(2, Tile(TileDesigns::BAMBOO, 5));
		hand.insertTile(3, Tile(TileDesigns::BAMBOO, 6));
		hand.insertTile(4, Tile(TileDesigns::BAMBOO, 7));
		hand.insertTile(5, Tile(TileDesigns::BAMBOO, 8));
		hand.insertTile(6, Tile(TileDesigns::BAMBOO, 9));
		hand.insertTile(7, Tile(TileDesigns::CHARACTERS, 1));
		hand.insertTile(8, Tile(TileDesigns::CHARACTERS, 2));
		hand.insertTile(9, Tile(TileDesigns::CHARACTERS, 3));
		hand.insertTile(10, Tile(TileDesigns::CHARACTERS, 4));
		hand.insertTile(11, Tile(TileDesigns::CHARACTERS, 5));
		ASSERT_EQ(14, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 2), *hand.getTile(0));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 4), *hand.getTile(1));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 5), *hand.getTile(2));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 6), *hand.getTile(3));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 7), *hand.getTile(4));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 8), *hand.getTile(5));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), *hand.getTile(6));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 1), *hand.getTile(7));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 2), *hand.getTile(8));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 3), *hand.getTile(9));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 4), *hand.getTile(10));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 5), *hand.getTile(11));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 1), *hand.getTile(12));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *hand.getTile(13));
	}

	// 牌の削除 (イテレータ版) と牌の全削除をテストする。
	TEST_F(SimpleHandTest, testRemoveTilesUsingIndexAndClearTiles)
	{
		SimpleHand hand;
		SimpleHand::TilesIterator iterator;

		// 牌を削除する。
		hand.addTile(Tile(TileDesigns::BAMBOO, 1));
		iterator = hand.removeTile(hand.getHeadTilesIterator());
		ASSERT_EQ(hand.getHeadTilesIterator(), iterator);
		ASSERT_EQ(0, hand.countTiles());

		// 先頭の牌を削除する。
		hand.addTile(Tile(TileDesigns::BAMBOO, 2));
		hand.addTile(Tile(TileDesigns::BAMBOO, 3));
		iterator = hand.removeTile(hand.getHeadTilesIterator());
		ASSERT_EQ(hand.getHeadTilesIterator(), iterator);
		ASSERT_EQ(1, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *hand.getTile(0));

		// 末尾の牌を削除する。
		hand.addTile(Tile(TileDesigns::BAMBOO, 4));
		iterator = hand.removeTile(hand.getTailTilesIterator() - 1);
		ASSERT_EQ(hand.getTailTilesIterator(), iterator);
		ASSERT_EQ(1, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *hand.getTile(0));

		// 間の牌を削除する。
		hand.addTile(Tile(TileDesigns::BAMBOO, 5));
		hand.addTile(Tile(TileDesigns::BAMBOO, 6));
		hand.addTile(Tile(TileDesigns::BAMBOO, 7));
		hand.addTile(Tile(TileDesigns::BAMBOO, 8));
		hand.addTile(Tile(TileDesigns::BAMBOO, 9));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 1));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 2));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 3));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 4));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 5));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 6));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 7));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 8));
		hand.removeTile(hand.getHeadTilesIterator() + 1);
		hand.removeTile(hand.getHeadTilesIterator() + 5);
		hand.removeTile(hand.getHeadTilesIterator() + 10);
		ASSERT_EQ(11, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *hand.getTile(0));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 6), *hand.getTile(1));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 7), *hand.getTile(2));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 8), *hand.getTile(3));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), *hand.getTile(4));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 2), *hand.getTile(5));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 3), *hand.getTile(6));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 4), *hand.getTile(7));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 5), *hand.getTile(8));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 6), *hand.getTile(9));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 8), *hand.getTile(10));

		// 先頭の牌を削除する (牌配列サイズ最大時)
		hand.addTile(Tile(TileDesigns::EAST));
		hand.addTile(Tile(TileDesigns::SOUTH));
		hand.addTile(Tile(TileDesigns::WEST));
		hand.removeTile(hand.getHeadTilesIterator());
		ASSERT_EQ(13, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 6), *hand.getTile(0));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 7), *hand.getTile(1));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 8), *hand.getTile(2));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), *hand.getTile(3));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 2), *hand.getTile(4));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 3), *hand.getTile(5));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 4), *hand.getTile(6));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 5), *hand.getTile(7));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 6), *hand.getTile(8));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 8), *hand.getTile(9));
		ASSERT_EQ(Tile(TileDesigns::EAST), *hand.getTile(10));
		ASSERT_EQ(Tile(TileDesigns::SOUTH), *hand.getTile(11));
		ASSERT_EQ(Tile(TileDesigns::WEST), *hand.getTile(12));

		// 末尾の牌を削除する (牌配列サイズ最大時)
		hand.insertTile(hand.getHeadTilesIterator(), Tile(TileDesigns::NORTH));
		hand.removeTile(hand.getTailTilesIterator() - 1);
		ASSERT_EQ(13, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::NORTH), *hand.getTile(0));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 6), *hand.getTile(1));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 7), *hand.getTile(2));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 8), *hand.getTile(3));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), *hand.getTile(4));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 2), *hand.getTile(5));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 3), *hand.getTile(6));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 4), *hand.getTile(7));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 5), *hand.getTile(8));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 6), *hand.getTile(9));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 8), *hand.getTile(10));
		ASSERT_EQ(Tile(TileDesigns::EAST), *hand.getTile(11));
		ASSERT_EQ(Tile(TileDesigns::SOUTH), *hand.getTile(12));

		// 牌を全削除する。
		hand.clearTiles();
		ASSERT_EQ(0, hand.countTiles());
	}

	// 牌の削除 (添え字版) をテストする。
	TEST_F(SimpleHandTest, testRemoveTilesUsingIndex)
	{
		SimpleHand hand;

		// 牌を削除する。
		hand.addTile(Tile(TileDesigns::BAMBOO, 1));
		hand.removeTile(0);
		ASSERT_EQ(0, hand.countTiles());

		// 先頭の牌を削除する。
		hand.addTile(Tile(TileDesigns::BAMBOO, 2));
		hand.addTile(Tile(TileDesigns::BAMBOO, 3));
		hand.removeTile(0);
		ASSERT_EQ(1, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *hand.getTile(0));

		// 末尾の牌を削除する。
		hand.addTile(Tile(TileDesigns::BAMBOO, 4));
		hand.removeTile(hand.countTiles() - 1);
		ASSERT_EQ(1, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *hand.getTile(0));

		// 間の牌を削除する。
		hand.addTile(Tile(TileDesigns::BAMBOO, 5));
		hand.addTile(Tile(TileDesigns::BAMBOO, 6));
		hand.addTile(Tile(TileDesigns::BAMBOO, 7));
		hand.addTile(Tile(TileDesigns::BAMBOO, 8));
		hand.addTile(Tile(TileDesigns::BAMBOO, 9));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 1));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 2));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 3));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 4));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 5));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 6));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 7));
		hand.addTile(Tile(TileDesigns::CHARACTERS, 8));
		hand.removeTile(1);
		hand.removeTile(5);
		hand.removeTile(10);
		ASSERT_EQ(11, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 3), *hand.getTile(0));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 6), *hand.getTile(1));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 7), *hand.getTile(2));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 8), *hand.getTile(3));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), *hand.getTile(4));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 2), *hand.getTile(5));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 3), *hand.getTile(6));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 4), *hand.getTile(7));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 5), *hand.getTile(8));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 6), *hand.getTile(9));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 8), *hand.getTile(10));

		// 先頭の牌を削除する (牌配列サイズ最大時)
		hand.addTile(Tile(TileDesigns::EAST));
		hand.addTile(Tile(TileDesigns::SOUTH));
		hand.addTile(Tile(TileDesigns::WEST));
		hand.removeTile(0);
		ASSERT_EQ(13, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 6), *hand.getTile(0));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 7), *hand.getTile(1));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 8), *hand.getTile(2));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), *hand.getTile(3));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 2), *hand.getTile(4));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 3), *hand.getTile(5));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 4), *hand.getTile(6));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 5), *hand.getTile(7));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 6), *hand.getTile(8));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 8), *hand.getTile(9));
		ASSERT_EQ(Tile(TileDesigns::EAST), *hand.getTile(10));
		ASSERT_EQ(Tile(TileDesigns::SOUTH), *hand.getTile(11));
		ASSERT_EQ(Tile(TileDesigns::WEST), *hand.getTile(12));

		// 末尾の牌を削除する (牌配列サイズ最大時)
		hand.insertTile(0, Tile(TileDesigns::NORTH));
		hand.removeTile(hand.countTiles() - 1);
		ASSERT_EQ(13, hand.countTiles());
		ASSERT_EQ(Tile(TileDesigns::NORTH), *hand.getTile(0));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 6), *hand.getTile(1));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 7), *hand.getTile(2));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 8), *hand.getTile(3));
		ASSERT_EQ(Tile(TileDesigns::BAMBOO, 9), *hand.getTile(4));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 2), *hand.getTile(5));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 3), *hand.getTile(6));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 4), *hand.getTile(7));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 5), *hand.getTile(8));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 6), *hand.getTile(9));
		ASSERT_EQ(Tile(TileDesigns::CHARACTERS, 8), *hand.getTile(10));
		ASSERT_EQ(Tile(TileDesigns::EAST), *hand.getTile(11));
		ASSERT_EQ(Tile(TileDesigns::SOUTH), *hand.getTile(12));
	}

	// 面子数の取得，面子の取得，面子の設定，面子の追加，およびイテレータをテストする。
	TEST_F(SimpleHandTest, testCountSetsGetSetAndSetSetAndAddSetAndSetsIteratorAndSetsConstIterator)
	{
		SimpleHand hand;
		SimpleHand::SetsIterator iterator;
		SimpleHand::SetsConstIterator constIterator;

		// 生成直後の手牌は空である。
		ASSERT_EQ(0, hand.countSets());
		ASSERT_EQ(hand.getHeadSetsIterator(), hand.getTailSetsIterator());

		// 対子を追加する。
		hand.addSet(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)));
		ASSERT_EQ(1, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *hand.getSet(0));
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *hand.getFirstSet());
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *hand.getLastSet());
		iterator = hand.getHeadSetsIterator();
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *iterator++);
		ASSERT_EQ(hand.getTailSetsIterator(), iterator);
		constIterator = hand.getHeadSetsConstIterator();
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *constIterator++);
		ASSERT_EQ(hand.getTailSetsConstIterator(), constIterator);

		// 暗刻を追加する。
		hand.addSet(Set(SetArrangements::PAIR, Tile(TileDesigns::CHARACTERS, 9)));
		ASSERT_EQ(2, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *hand.getSet(0));
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::CHARACTERS, 9)), *hand.getSet(1));
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *hand.getFirstSet());
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::CHARACTERS, 9)), *hand.getLastSet());
		iterator = hand.getHeadSetsIterator();
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *iterator++);
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::CHARACTERS, 9)), *iterator++);
		ASSERT_EQ(hand.getTailSetsIterator(), iterator);
		constIterator = hand.getHeadSetsConstIterator();
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *constIterator++);
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::CHARACTERS, 9)), *constIterator++);
		ASSERT_EQ(hand.getTailSetsConstIterator(), constIterator);

		// 面子を追加する。
		hand.addSet(Set(SetArrangements::PUNG, Tile(TileDesigns::EAST)));
		hand.addSet(Set(SetArrangements::KONG, Tile(TileDesigns::SOUTH)));
		hand.addSet(Set(SetArrangements::CHOW, MeldTypes::LEFT, Tile(TileDesigns::CIRCLES, 7)));
		ASSERT_EQ(5, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *hand.getSet(0));
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::CHARACTERS, 9)), *hand.getSet(1));
		ASSERT_EQ(Set(SetArrangements::PUNG, Tile(TileDesigns::EAST)), *hand.getSet(2));
		ASSERT_EQ(Set(SetArrangements::KONG, Tile(TileDesigns::SOUTH)), *hand.getSet(3));
		ASSERT_EQ(Set(SetArrangements::CHOW, MeldTypes::LEFT, Tile(TileDesigns::CIRCLES, 7)), *hand.getSet(4));
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *hand.getFirstSet());
		ASSERT_EQ(Set(SetArrangements::CHOW, MeldTypes::LEFT, Tile(TileDesigns::CIRCLES, 7)), *hand.getLastSet());
		iterator = hand.getHeadSetsIterator();
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *iterator++);
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::CHARACTERS, 9)), *iterator++);
		ASSERT_EQ(Set(SetArrangements::PUNG, Tile(TileDesigns::EAST)), *iterator++);
		ASSERT_EQ(Set(SetArrangements::KONG, Tile(TileDesigns::SOUTH)), *iterator++);
		ASSERT_EQ(Set(SetArrangements::CHOW, MeldTypes::LEFT, Tile(TileDesigns::CIRCLES, 7)), *iterator++);
		ASSERT_EQ(hand.getTailSetsIterator(), iterator);
		constIterator = hand.getHeadSetsConstIterator();
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *constIterator++);
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::CHARACTERS, 9)), *constIterator++);
		ASSERT_EQ(Set(SetArrangements::PUNG, Tile(TileDesigns::EAST)), *constIterator++);
		ASSERT_EQ(Set(SetArrangements::KONG, Tile(TileDesigns::SOUTH)), *constIterator++);
		ASSERT_EQ(Set(SetArrangements::CHOW, MeldTypes::LEFT, Tile(TileDesigns::CIRCLES, 7)), *constIterator++);
		ASSERT_EQ(hand.getTailSetsIterator(), constIterator);

		// 面子を設定する。
		hand.setSet(0, Set(SetArrangements::PUNG, MeldTypes::CENTER, Tile(TileDesigns::WEST)));
		hand.setSet(2, Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::LITTLE, Tile(TileDesigns::NORTH)));
		hand.setSet(4, Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::BIG, Tile(TileDesigns::RED)));
		ASSERT_EQ(5, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::PUNG, MeldTypes::CENTER, Tile(TileDesigns::WEST)), *hand.getSet(0));
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::CHARACTERS, 9)), *hand.getSet(1));
		ASSERT_EQ(Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::LITTLE, Tile(TileDesigns::NORTH)), *hand.getSet(2));
		ASSERT_EQ(Set(SetArrangements::KONG, Tile(TileDesigns::SOUTH)), *hand.getSet(3));
		ASSERT_EQ(Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::BIG, Tile(TileDesigns::RED)), *hand.getSet(4));
		iterator = hand.getHeadSetsIterator();
		ASSERT_EQ(Set(SetArrangements::PUNG, MeldTypes::CENTER, Tile(TileDesigns::WEST)), *iterator++);
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::CHARACTERS, 9)), *iterator++);
		ASSERT_EQ(Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::LITTLE, Tile(TileDesigns::NORTH)), *iterator++);
		ASSERT_EQ(Set(SetArrangements::KONG, Tile(TileDesigns::SOUTH)), *iterator++);
		ASSERT_EQ(Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::BIG, Tile(TileDesigns::RED)), *iterator++);
		ASSERT_EQ(hand.getTailSetsIterator(), iterator);
		constIterator = hand.getHeadSetsConstIterator();
		ASSERT_EQ(Set(SetArrangements::PUNG, MeldTypes::CENTER, Tile(TileDesigns::WEST)), *constIterator++);
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::CHARACTERS, 9)), *constIterator++);
		ASSERT_EQ(Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::LITTLE, Tile(TileDesigns::NORTH)), *constIterator++);
		ASSERT_EQ(Set(SetArrangements::KONG, Tile(TileDesigns::SOUTH)), *constIterator++);
		ASSERT_EQ(Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::BIG, Tile(TileDesigns::RED)), *constIterator++);
		ASSERT_EQ(hand.getTailSetsConstIterator(), constIterator);
	}

	// 面子の挿入 (イテレータ版) をテストする。
	TEST_F(SimpleHandTest, testInsertSetsUsingIterator)
	{
		SimpleHand hand;
		SimpleHand::SetsIterator iterator;

		// 暗順を挿入する。
		iterator = hand.insertSet(hand.getHeadSetsIterator(), Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)));
		ASSERT_EQ(hand.getHeadSetsIterator(), iterator);
		ASSERT_EQ(1, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *hand.getSet(0));

		// 対子を先頭に挿入する。
		iterator = hand.insertSet(hand.getHeadSetsIterator(), Set(SetArrangements::PAIR, Tile(TileDesigns::BAMBOO, 2)));
		ASSERT_EQ(hand.getHeadSetsIterator(), iterator);
		ASSERT_EQ(2, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::BAMBOO, 2)), *hand.getSet(0));
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *hand.getSet(1));

		// 暗刻を末尾に挿入する。
		iterator = hand.insertSet(hand.getTailSetsIterator(), Set(SetArrangements::PUNG, Tile(TileDesigns::BAMBOO, 3)));
		ASSERT_EQ(hand.getTailSetsIterator() - 1, iterator);
		ASSERT_EQ(3, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::BAMBOO, 2)), *hand.getSet(0));
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *hand.getSet(1));
		ASSERT_EQ(Set(SetArrangements::PUNG, Tile(TileDesigns::BAMBOO, 3)), *hand.getSet(2));

		// 面子を間に挿入する。
		iterator = hand.insertSet(hand.getHeadSetsIterator() + 1, Set(SetArrangements::KONG, Tile(TileDesigns::BAMBOO, 4)));
		iterator = hand.insertSet(iterator + 1, Set(SetArrangements::CHOW, MeldTypes::LEFT, Tile(TileDesigns::BAMBOO, 5)));
		ASSERT_EQ(hand.getHeadSetsIterator() + 2, iterator);
		ASSERT_EQ(5, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::BAMBOO, 2)), *hand.getSet(0));
		ASSERT_EQ(Set(SetArrangements::KONG, Tile(TileDesigns::BAMBOO, 4)), *hand.getSet(1));
		ASSERT_EQ(Set(SetArrangements::CHOW, MeldTypes::LEFT, Tile(TileDesigns::BAMBOO, 5)), *hand.getSet(2));
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *hand.getSet(3));
		ASSERT_EQ(Set(SetArrangements::PUNG, Tile(TileDesigns::BAMBOO, 3)), *hand.getSet(4));
	}

	// 面子の挿入 (添え字版) をテストする。
	TEST_F(SimpleHandTest, testInsertSetsUsingIndex)
	{
		SimpleHand hand;

		// 暗順を挿入する。
		hand.insertSet(0, Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)));
		ASSERT_EQ(1, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *hand.getSet(0));

		// 対子を先頭に挿入する。
		hand.insertSet(0, Set(SetArrangements::PAIR, Tile(TileDesigns::BAMBOO, 2)));
		ASSERT_EQ(2, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::BAMBOO, 2)), *hand.getSet(0));
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *hand.getSet(1));

		// 暗刻を末尾に挿入する。
		hand.insertSet(hand.countSets(), Set(SetArrangements::PUNG, Tile(TileDesigns::BAMBOO, 3)));
		ASSERT_EQ(3, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::BAMBOO, 2)), *hand.getSet(0));
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *hand.getSet(1));
		ASSERT_EQ(Set(SetArrangements::PUNG, Tile(TileDesigns::BAMBOO, 3)), *hand.getSet(2));

		// 面子を間に挿入する。
		hand.insertSet(1, Set(SetArrangements::KONG, Tile(TileDesigns::BAMBOO, 4)));
		hand.insertSet(2, Set(SetArrangements::CHOW, MeldTypes::LEFT, Tile(TileDesigns::BAMBOO, 5)));
		ASSERT_EQ(5, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::BAMBOO, 2)), *hand.getSet(0));
		ASSERT_EQ(Set(SetArrangements::KONG, Tile(TileDesigns::BAMBOO, 4)), *hand.getSet(1));
		ASSERT_EQ(Set(SetArrangements::CHOW, MeldTypes::LEFT, Tile(TileDesigns::BAMBOO, 5)), *hand.getSet(2));
		ASSERT_EQ(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)), *hand.getSet(3));
		ASSERT_EQ(Set(SetArrangements::PUNG, Tile(TileDesigns::BAMBOO, 3)), *hand.getSet(4));
	}

	// 面子の削除 (イテレータ版) と面子の全削除をテストする。
	TEST_F(SimpleHandTest, testRemoveSetsUsingIndexAndClearSets)
	{
		SimpleHand hand;
		SimpleHand::SetsIterator iterator;

		// 面子を削除する。
		hand.addSet(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)));
		iterator = hand.removeSet(hand.getHeadSetsIterator());
		ASSERT_EQ(hand.getHeadSetsIterator(), iterator);
		ASSERT_EQ(0, hand.countSets());

		// 先頭の面子を削除する。
		hand.addSet(Set(SetArrangements::PAIR, Tile(TileDesigns::BAMBOO, 2)));
		hand.addSet(Set(SetArrangements::PUNG, Tile(TileDesigns::BAMBOO, 3)));
		iterator = hand.removeSet(hand.getHeadSetsIterator());
		ASSERT_EQ(hand.getHeadSetsIterator(), iterator);
		ASSERT_EQ(1, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::PUNG, Tile(TileDesigns::BAMBOO, 3)), *hand.getSet(0));

		// 末尾の面子を削除する。
		hand.addSet(Set(SetArrangements::KONG, Tile(TileDesigns::BAMBOO, 4)));
		iterator = hand.removeSet(hand.getTailSetsIterator() - 1);
		ASSERT_EQ(hand.getTailSetsIterator(), iterator);
		ASSERT_EQ(1, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::PUNG, Tile(TileDesigns::BAMBOO, 3)), *hand.getSet(0));

		// 間の面子を削除する。
		hand.addSet(Set(SetArrangements::CHOW, MeldTypes::LEFT, Tile(TileDesigns::BAMBOO, 5)));
		hand.addSet(Set(SetArrangements::PUNG, MeldTypes::CENTER, Tile(TileDesigns::BAMBOO, 6)));
		hand.addSet(Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::LITTLE, Tile(TileDesigns::BAMBOO, 7)));
		hand.addSet(Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::BIG, Tile(TileDesigns::BAMBOO, 8)));
		hand.removeSet(hand.getHeadSetsIterator() + 3);
		hand.removeSet(hand.getHeadSetsIterator() + 2);
		hand.removeSet(hand.getHeadSetsIterator() + 1);
		ASSERT_EQ(2, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::PUNG, Tile(TileDesigns::BAMBOO, 3)), *hand.getSet(0));
		ASSERT_EQ(Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::BIG, Tile(TileDesigns::BAMBOO, 8)), *hand.getSet(1));

		// 先頭の面子を削除する (面子配列サイズ最大時)
		hand.addSet(Set(SetArrangements::PAIR, Tile(TileDesigns::EAST)));
		hand.addSet(Set(SetArrangements::PAIR, Tile(TileDesigns::SOUTH)));
		hand.addSet(Set(SetArrangements::PAIR, Tile(TileDesigns::WEST)));
		hand.removeSet(hand.getHeadSetsIterator());
		ASSERT_EQ(4, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::BIG, Tile(TileDesigns::BAMBOO, 8)), *hand.getSet(0));
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::EAST)), *hand.getSet(1));
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::SOUTH)), *hand.getSet(2));
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::WEST)), *hand.getSet(3));

		// 末尾の面子を削除する (面子配列サイズ最大時)
		hand.insertSet(hand.getHeadSetsIterator(), Set(SetArrangements::PAIR, Tile(TileDesigns::NORTH)));
		hand.removeSet(hand.getTailSetsIterator() - 1);
		ASSERT_EQ(4, hand.countSets());
		ASSERT_EQ(Set(Set(SetArrangements::PAIR, Tile(TileDesigns::NORTH))), *hand.getSet(0));
		ASSERT_EQ(Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::BIG, Tile(TileDesigns::BAMBOO, 8)), *hand.getSet(1));
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::EAST)), *hand.getSet(2));
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::SOUTH)), *hand.getSet(3));

		// 面子を全削除する。
		hand.clearSets();
		ASSERT_EQ(0, hand.countSets());
	}

	// 面子の削除 (イテレータ版) をテストする。
	TEST_F(SimpleHandTest, testRemoveSetsUsingIndex)
	{
		SimpleHand hand;

		// 面子を削除する。
		hand.addSet(Set(SetArrangements::CHOW, Tile(TileDesigns::BAMBOO, 1)));
		hand.removeSet(0);
		ASSERT_EQ(0, hand.countSets());

		// 先頭の面子を削除する。
		hand.addSet(Set(SetArrangements::PAIR, Tile(TileDesigns::BAMBOO, 2)));
		hand.addSet(Set(SetArrangements::PUNG, Tile(TileDesigns::BAMBOO, 3)));
		hand.removeSet(0);
		ASSERT_EQ(1, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::PUNG, Tile(TileDesigns::BAMBOO, 3)), *hand.getSet(0));

		// 末尾の面子を削除する。
		hand.addSet(Set(SetArrangements::KONG, Tile(TileDesigns::BAMBOO, 4)));
		hand.removeSet(hand.countSets() - 1);
		ASSERT_EQ(1, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::PUNG, Tile(TileDesigns::BAMBOO, 3)), *hand.getSet(0));

		// 間の面子を削除する。
		hand.addSet(Set(SetArrangements::CHOW, MeldTypes::LEFT, Tile(TileDesigns::BAMBOO, 5)));
		hand.addSet(Set(SetArrangements::PUNG, MeldTypes::CENTER, Tile(TileDesigns::BAMBOO, 6)));
		hand.addSet(Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::LITTLE, Tile(TileDesigns::BAMBOO, 7)));
		hand.addSet(Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::BIG, Tile(TileDesigns::BAMBOO, 8)));
		hand.removeSet(3);
		hand.removeSet(2);
		hand.removeSet(1);
		ASSERT_EQ(2, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::PUNG, Tile(TileDesigns::BAMBOO, 3)), *hand.getSet(0));
		ASSERT_EQ(Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::BIG, Tile(TileDesigns::BAMBOO, 8)), *hand.getSet(1));

		// 先頭の面子を削除する (面子配列サイズ最大時)
		hand.addSet(Set(SetArrangements::PAIR, Tile(TileDesigns::EAST)));
		hand.addSet(Set(SetArrangements::PAIR, Tile(TileDesigns::SOUTH)));
		hand.addSet(Set(SetArrangements::PAIR, Tile(TileDesigns::WEST)));
		hand.removeSet(0);
		ASSERT_EQ(4, hand.countSets());
		ASSERT_EQ(Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::BIG, Tile(TileDesigns::BAMBOO, 8)), *hand.getSet(0));
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::EAST)), *hand.getSet(1));
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::SOUTH)), *hand.getSet(2));
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::WEST)), *hand.getSet(3));

		// 末尾の面子を削除する (面子配列サイズ最大時)
		hand.insertSet(0, Set(SetArrangements::PAIR, Tile(TileDesigns::NORTH)));
		hand.removeSet(hand.countSets() - 1);
		ASSERT_EQ(4, hand.countSets());
		ASSERT_EQ(Set(Set(SetArrangements::PAIR, Tile(TileDesigns::NORTH))), *hand.getSet(0));
		ASSERT_EQ(Set(SetArrangements::KONG, MeldTypes::RIGHT, MeldedKongTypes::BIG, Tile(TileDesigns::BAMBOO, 8)), *hand.getSet(1));
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::EAST)), *hand.getSet(2));
		ASSERT_EQ(Set(SetArrangements::PAIR, Tile(TileDesigns::SOUTH)), *hand.getSet(3));
	}
}
