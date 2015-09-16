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


#include <cstdint>


namespace openriichi
{
	/**
	 * 省メモリの立直状態である。
	 */
	class MemorySavedRiichiStatus
	{
	private:
		/**
		 * フラグである。
		 */
		enum Flag
		{
			/// 立直宣言あり。
			DECLARED = 0x01,

			/// オープン。
			OPEN = 0x02,

			/// ダブル。
			DOUBLE = 0x04,

			/// 一発。
			ONE_SHOT = 0x08,
		};


	private:
		/**
		 * 立直状態を表す値。
		 * 値の構成は次の通りである (ビットの番号は最上位を 1 番目，最下位を 8 番目とする)。
		 *     - 1 ～ 4 ビット目 ... 予約 (常に 0)。
		 *     - 5 ビット目      ... 一発該非。
		 *     - 6 ビット目      ... ダブル該非。
		 *     - 7 ビット目      ... オープン該非。
		 *     - 8 ビット目      ... 立直宣言有無。
		 */
		uint8_t m_value;


	public:
		/**
		 * 立直宣言なしの立直状態を生成する。
		 */
		MemorySavedRiichiStatus();

		/**
		 * 立直状態を生成する。
		 *
		 * @param[in] declared 立直宣言有無。
		 *                     立直宣言ありである場合は true，それ以外は false を指定する。
		 * @param[in] open オープン該非。
		 *                 オープンである場合は true，それ以外は false を指定する。
		 * @param[in] doubl ダブル該非。
		 *                  ダブル該当である場合は true，それ以外は false を指定する。
		 * @param[in] oneShot 一発該非。
		 *                    一発該当である場合は true，それ以外は false を指定する。
		 */
		MemorySavedRiichiStatus(bool declared, bool open = false, bool doubl = false, bool oneShot = false);


	public:
		/**
		 * 他の立直状態と等しいか調べる。
		 *
		 * @param[in] other 他の立直状態。
		 */
		bool operator==(const MemorySavedRiichiStatus &other) const;

		/**
		 * 他の立直状態と等しくないか調べる。
		 *
		 * @param[in] other 他の立直状態。
		 */
		bool operator!=(const MemorySavedRiichiStatus &other) const;


	public:
		/**
		 * 立直宣言有無を返す。
		 *
		 * @retval true 立直宣言あり。
		 * @retval false 立直宣言なし。
		 */
		bool isDeclared() const;

		/**
		 * 立直宣言有無を設定する。
		 *
		 * @param[in] declared 立直宣言有無。
		 *                     立直宣言ありである場合は true，それ以外は false を指定する。
		 */
		void setDeclared(bool declared);

		/**
		 * オープン該非を返す。
		 *
		 * @retval true オープン。
		 * @retval false 非オープン。
		 */
		bool isOpen() const;

		/**
		 * オープン該非を設定する。
		 *
		 * @param[in] open オープン該非。
		 *                 オープンである場合は true，それ以外は false を指定する。
		 */
		void setOpen(bool open);

		/**
		 * ダブル該非を返す。
		 *
		 * @retval true ダブル。
		 * @retval false 非ダブル。
		 */
		bool isDouble() const;

		/**
		 * ダブル該非を設定する。
		 *
		 * @param[in] doubl ダブル該非。
		 *                  ダブル該当である場合は true，それ以外は false を指定する。
		 */
		void setDouble(bool doubl);

		/**
		 * 一発該非を返す。
		 *
		 * @retval true 一発。
		 * @retval false 非一発。
		 */
		bool isOneShot() const;

		/**
		 * 一発該非を設定する。
		 *
		 * @param[in] oneShot 一発該非。
		 *                    一発該当である場合は true，それ以外は false を指定する。
		 */
		void setOneShot(bool oneShot);
	};
}
