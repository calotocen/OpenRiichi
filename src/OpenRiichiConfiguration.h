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


#if !defined(OPENRIICHI_DEBUG)
#	if defined(_DEBUG)
		/// デバッグフラグ。
#		define OPENRIICHI_DEBUG (1)
#	endif // defined(_DEBUG)
#endif // !defined(OPENRIICHI_DEBUG)


#if !defined(OPENRIICHI_ENABLE_ASSERTION)
#	if defined(OPENRIICHI_DEBUG) && OPENRIICHI_DEBUG != 0
		/// アサーションフラグ。
#		define OPENRIICHI_ENABLE_ASSERTION (1)
#	endif // OPENRIICHI_DEBUG != 0
#endif // !defined(OPENRIICHI_ENABLE_ASSERTION)
