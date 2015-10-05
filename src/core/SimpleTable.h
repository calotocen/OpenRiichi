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
#pragma once


namespace openriichi
{
	/**
	 * 卓である。
	 */
	class SimpleTable
	{
	private:
		static const size_t PLAYER_INFOS_SIZE = 4;


	private:
		/// プレイヤー情報。
		PlayerInfo m_playerInfos[PLAYER_INFOS_SIZE];

		/// 山。
		Wall m_wall;
		
		/// 局カウンタ。
		HandCounter m_handCounter;


	public:
		/**
		 * プレイヤー情報を生成する。
		 */
		SimpleTable();


	public:
		/**
		 * 他の卓と等しいか調べる。
		 *
		 * @param[in] other 他の卓。
		 */
		bool operator==(const SimpleTable &other) const;

		/**
		 * 他の卓と等しくないか調べる。
		 *
		 * @param[in] other 他の卓。
		 */
		bool operator!=(const SimpleTable &other) const;


	public:
		/**
		 * プレイヤー情報を返す。
		 *
		 * @param[in] wind 風。
		 * @return プレイヤー情報。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		const PlayerInfo &playerInfo(const Wind &wind) const;

		/**
		 * プレイヤー情報を返す。
		 *
		 * @param[in] wind 風。
		 * @return プレイヤー情報。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数が返す参照の内容は，変更してもよい。
		 *       その場合，変更内容は取得元のインスタンスに反映される。
		 */
		PlayerInfo &playerInfo(const Wind &wind);

		/**
		 * プレイヤー情報を返す。
		 *
		 * @param[in] wind 風。
		 * @return プレイヤー情報。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		const PlayerInfo &getPlayerInfo(const Wind &wind) const;

		/**
		 * プレイヤー情報を設定する。
		 *
		 * @param[in] wind 風。
		 * @param[in] playerInfo プレイヤー情報。
		 */
		void setPlayerInfo(const Wind &wind, const PlayerInfo &playerInfo);

		/**
		 * 山を返す。
		 *
		 * @return 山。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		const Wall &wall() const;

		/**
		 * 山を返す。
		 *
		 * @return 山。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数が返す参照の内容は，変更してもよい。
		 *       その場合，変更内容は取得元のインスタンスに反映される。
		 */
		Wall &wall();

		/**
		 * 山を返す。
		 *
		 * @return 山。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		const Wall &getWall() const;

		/**
		 * 山を設定する。
		 *
		 * @param[in] wall 山。
		 */
		void setWall(const Wall &wall);

		/**
		 * 局カウンタを返す。
		 *
		 * @return 局カウンタ。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		const HandCounter &handCounter() const;

		/**
		 * 局カウンタを返す。
		 *
		 * @return 局カウンタ。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 * @note 本関数が返す参照の内容は，変更してもよい。
		 *       その場合，変更内容は取得元のインスタンスに反映される。
		 */
		HandCounter &handCounter();

		/**
		 * 局カウンタを返す。
		 *
		 * @return 局カウンタ。
		 * @note 本関数の戻り値は，少なくとも本インスタンスが生存している間，有効である。
		 */
		const HandCounter &getHandCounter() const;

		/**
		 * 局カウンタを設定する。
		 *
		 * @param[in] handCounter 局カウンタ。
		 */
		void setHandCounter(const HandCounter &handCounter);
	};
}
