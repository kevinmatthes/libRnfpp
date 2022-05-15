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
 * \brief       The Rnfpp vector class.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        addition_inplace.cpp
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This file implements the Rnfpp vector class.
 */

/******************************************************************************/

/*
 * Includes.
 */

// This project.
#include "Rnfpp.hpp"



/**
 * \brief   The addition operator.
 * \param   other   The vector to add this one with.
 * \return  The sum vector.
 *
 * This method returns the sum vector.
 */

inline Rnfpp & Rnfpp :: operator += (const float other) noexcept
{
    this -> set_components ((* this) + other);
    return (* this);
}



/**
 * \brief   The addition operator.
 * \param   other   The vector to add this one with.
 * \return  The sum vector.
 * \throws  invalid_argument    In case the vectors are of different dimensions.
 *
 * This method returns the sum vector in case both input vectors, this and the
 * other one, share the same dimension.  In case they should be of different
 * dimensions, an according exception will be thrown.
 */

inline Rnfpp & Rnfpp :: operator += (const fvec_t & other)
{
    this -> assert_same_dimension (other);
    this -> set_components ((* this) + other);
    return (* this);
}



/**
 * \brief   The addition operator.
 * \param   other   The vector to add this one with.
 * \return  The sum vector.
 * \throws  invalid_argument    In case the vectors are of different dimensions.
 *
 * This method returns the sum vector in case both input vectors, this and the
 * other one, share the same dimension.  In case they should be of different
 * dimensions, an according exception will be thrown.
 */

inline Rnfpp & Rnfpp :: operator += (const Rnfpp & other)
{
    this -> assert_same_dimension (other);
    this -> set_components ((*this) + other);
    return (* this);
}

/******************************************************************************/
