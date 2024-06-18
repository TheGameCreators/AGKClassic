/*
---------------------------------------------------------------------------
Open Asset Import Library (assimp)
---------------------------------------------------------------------------

Copyright (c) 2006-2012, assimp team

All rights reserved.

Redistribution and use of this software in source and binary forms, 
with or without modification, are permitted provided that the following 
conditions are met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other
  materials provided with the distribution.

* Neither the name of the assimp team, nor the names of its
  contributors may be used to endorse or promote products
  derived from this software without specific prior
  written permission of the assimp team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
---------------------------------------------------------------------------
*/

/** @file AssimpPCH.h
 *  PCH master include. Every unit in Assimp has to include it.
 */

#ifndef ASSIMP_PCH_INCLUDED
#define ASSIMP_PCH_INCLUDED
#define ASSIMP_INTERNAL_BUILD

#include "PlatformDefines.h"

// AGK specific defines
#define ASSIMP_BUILD_NO_OWN_ZLIB

// Remove some exporters and importers to reduce binary size
#define ASSIMP_BUILD_NO_PLY_EXPORTER
#define ASSIMP_BUILD_NO_STL_EXPORTER
#define ASSIMP_BUILD_NO_3DS_EXPORTER
#define ASSIMP_BUILD_NO_ASSBIN_EXPORTER
#define ASSIMP_BUILD_NO_OPENGEX_EXPORTER
#define ASSIMP_BUILD_NO_ASSXML_EXPORTER
#define ASSIMP_BUILD_NO_STEP_EXPORTER
#define ASSIMP_BUILD_NO_GLTF_EXPORTER
#define ASSIMP_BUILD_NO_COLLADA_EXPORTER
#define ASSIMP_BUILD_NO_FBX_EXPORTER

#define ASSIMP_BUILD_NO_IFC_IMPORTER
#define ASSIMP_BUILD_NO_PLY_IMPORTER
#define ASSIMP_BUILD_NO_XGL_IMPORTER
#define ASSIMP_BUILD_NO_DXF_IMPORTER
#define ASSIMP_BUILD_NO_STL_IMPORTER
#define ASSIMP_BUILD_NO_COB_IMPORTER
#define ASSIMP_BUILD_NO_ASE_IMPORTER
#define ASSIMP_BUILD_NO_MDL_IMPORTER
#define ASSIMP_BUILD_NO_MD2_IMPORTER
#define ASSIMP_BUILD_NO_MD3_IMPORTER
#define ASSIMP_BUILD_NO_ASE_IMPORTER
#define ASSIMP_BUILD_NO_HMP_IMPORTER
#define ASSIMP_BUILD_NO_MDC_IMPORTER
#define ASSIMP_BUILD_NO_NFF_IMPORTER
#define ASSIMP_BUILD_NO_RAW_IMPORTER
#define ASSIMP_BUILD_NO_OFF_IMPORTER
#define ASSIMP_BUILD_NO_BVH_IMPORTER
#define ASSIMP_BUILD_NO_IRRMESH_IMPORTER
#define ASSIMP_BUILD_NO_IRR_IMPORTER
#define ASSIMP_BUILD_NO_Q3D_IMPORTER
#define ASSIMP_BUILD_NO_TERRAGEN_IMPORTER
#define ASSIMP_BUILD_NO_CSM_IMPORTER
#define ASSIMP_BUILD_NO_OGRE_IMPORTER
#define ASSIMP_BUILD_NO_Q3BSP_IMPORTER
#define ASSIMP_BUILD_NO_NDO_IMPORTER
#define ASSIMP_BUILD_NO_C4D_IMPORTER
#define ASSIMP_BUILD_NO_3MF_IMPORTER
#define ASSIMP_BUILD_NO_OPENGEX_IMPORTER
#define ASSIMP_BUILD_NO_SIB_IMPORTER
//#define ASSIMP_BUILD_NO_GLTF_IMPORTER
#define ASSIMP_BUILD_NO_SMD_IMPORTER
#define ASSIMP_BUILD_NO_MD5_IMPORTER
#define ASSIMP_BUILD_NO_AC_IMPORTER
#define ASSIMP_BUILD_NO_LWS_IMPORTER
//#define ASSIMP_BUILD_NO_LWO_IMPORTER		LWO works fine in AGK
#define ASSIMP_BUILD_NO_BLEND_IMPORTER
//#define ASSIMP_BUILD_NO_MS3D_IMPORTER		Milkshape doesn't support other formats well


// ----------------------------------------------------------------------------------------
/* General compile config taken from defs.h. It is important that the user compiles
 * using exactly the same settings in defs.h. Settings in AssimpPCH.h may differ,
 * they won't affect the public API.
 */
#include "include/assimp/defs.h"

// Include our stdint.h replacement header for MSVC, take the global header for gcc/mingw
#if defined( _MSC_VER) && (_MSC_VER < 1600)
#	include "include/assimp/Compiler/pstdint.h"
#else
#	include <stdint.h>
#endif

#if defined AGK_BLACKBERRY /*|| defined AGK_LINUX*/
	using namespace std;
#endif

/* Undefine the min/max macros defined by some platform headers (namely Windows.h) to 
 * avoid obvious conflicts with std::min() and std::max(). 
 */
#undef min
#undef max

/* Concatenate two tokens after evaluating them
 */
#define _AI_CONCAT(a,b)  a ## b
#define  AI_CONCAT(a,b)  _AI_CONCAT(a,b)

/* Helper macro to set a pointer to NULL in debug builds
 */
#if (defined ASSIMP_BUILD_DEBUG)
#	define AI_DEBUG_INVALIDATE_PTR(x) x = NULL;
#else
#	define AI_DEBUG_INVALIDATE_PTR(x)
#endif

/* Beginning with MSVC8 some C string manipulation functions are mapped to their _safe_
 * counterparts (e.g. _itoa_s). This avoids a lot of trouble with deprecation warnings.
 */
#if _MSC_VER >= 1400 && !(defined _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES)
#	define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#endif

/* size_t to unsigned int, possible loss of data. The compiler is right with his warning
 * but this loss of data won't be a problem for us. So shut up, little boy.
 */
#ifdef _MSC_VER
#	pragma warning (disable : 4267)
#endif

// ----------------------------------------------------------------------------------------
/* Actually that's not required for MSVC. It is included somewhere in the deeper parts of
 * the MSVC STL but it's necessary for proper build with STLport.
 */
#include <ctype.h>

// Runtime/STL headers
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <new>
#include <cstdio>
#include <limits.h>
#include <memory>

// Boost headers
#include <boost/pointer_cast.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
#include <boost/make_shared.hpp>
#include <boost/format.hpp>
#include <boost/foreach.hpp>
#include <boost/static_assert.hpp>
#include <boost/lexical_cast.hpp>

// Public ASSIMP headers
#include "include/assimp/DefaultLogger.hpp"
#include "include/assimp/IOStream.hpp"
#include "include/assimp/IOSystem.hpp"
#include "include/assimp/scene.h"
#include "include/assimp/importerdesc.h"
#include "include/assimp/postprocess.h"
#include "include/assimp/Importer.hpp"
#include "include/assimp/Exporter.hpp"

// Internal utility headers
#include "BaseImporter.h"
#include "StringComparison.h"
#include "StreamReader.h"
#include "qnan.h"
#include "ScenePrivate.h" 


// We need those constants, workaround for any platforms where nobody defined them yet
#if (!defined SIZE_MAX)
#	define SIZE_MAX (~((size_t)0))
#endif

#if (!defined UINT_MAX)
#	define UINT_MAX (~((unsigned int)0))
#endif


#endif // !! ASSIMP_PCH_INCLUDED
