/*
 * Copyright (C) 2022 Kevin Matthes
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/**
 * \author      Kevin Matthes
 * \brief       The main header of this library.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        Rnfpp.hpp
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This file introduces the Rnfpp vector class.
 */

/******************************************************************************/

/**
 * \brief   Prevent this header from being included twice.
 *
 * In case this header file should be included more than just once, unexpected
 * side effects might take place.  This unintended behaviour will be avoided by
 * the definition of this macro.
 */

#pragma once
#ifndef __RNFPP_HPP__
#define __RNFPP_HPP__



/*
 * Includes.
 */

// The C++ standard library.
#include <cmath>
#include <stdexcept>
#include <vector>

// Namespace settings.
using std :: abs;
using std :: invalid_argument;
using std :: vector;



/**
 * \brief   Symbol export settings for compilations on Windows systems.
 *
 * In order to compile a Dynamic Link Libary (DLL) from this source code, the
 * symbols to export need to be tagged accordingly.
 *
 * Since this affects only Windows machines, the settings are implemented as
 * preprocessor instructions such that the actually required setup can be
 * requested during the compilation by additional defines.
 */

#define EXPORT
#ifdef  __WINDOWS__
#undef  EXPORT
#ifdef  __MAKE_DLL__
#define EXPORT __declspec (dllexport)
#else
#define EXPORT __declspec (dllimport)
#endif  // ! __MAKE_DLL__
#endif  // ! __WINDOWS__



/**
 * \brief   The dimension's data type.
 *
 * Since the `std :: vector <float>` has an own data type for its dimension,
 * this type is an abbreviation therefore.
 */

typedef vector <float> :: size_type dimension_t;



/**
 * \brief   The Rnfpp vector class.
 *
 * This class is a wrapper around a `std :: vector <float>` in order to perform
 * mathematical calculations with it.  The name derives from "real vector of n
 * `float` components, written in C++".
 */

class Rnfpp
{
    private:
        vector <float>  components;

    public:
        EXPORT  Rnfpp   (void);
        EXPORT  Rnfpp   (const dimension_t dimension);
        EXPORT  Rnfpp   (const Rnfpp & rnfpp);
        EXPORT  Rnfpp   (const vector <float> & components);

        EXPORT  vector <float> &    get_components  (void)  const noexcept;
        EXPORT  dimension_t         get_dimension   (void)  const noexcept;

        EXPORT  Rnfpp   operator +  (const Rnfpp &  other)  const;
        EXPORT  Rnfpp   operator -  (const Rnfpp &  other)  const;
        EXPORT  Rnfpp   operator *  (const float    other)  const;
        EXPORT  Rnfpp   operator /  (const float    other)  const;
        EXPORT  bool    operator == (const Rnfpp &  other)  const;

        EXPORT  void    assert_non_zero         (const float other)     const;
        EXPORT  void    assert_same_dimension   (const Rnfpp & other)   const;

        EXPORT  bool    same_dimension  (const Rnfpp & other)   const noexcept;
};



/*
 * End of header.
 */

// Tidying up.
#ifndef __RNFPP_INTERNAL__
#undef  EXPORT
#endif  // ! __RNFPP_INTERNAL__

// Leaving the header.
#endif  // ! __RNFPP_HPP__

/******************************************************************************/
