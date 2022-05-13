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
 * \file        same_dimension.cpp
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
 * \brief   Check whether two vectors share their dimension.
 * \param   other   The vector to test against.
 * \return  Whether the given vectors share their dimension.
 *
 * This method tests whether this vector is of the same dimension as the given
 * other one.
 */

inline bool Rnfpp :: same_dimension (const fvec_t & other) const noexcept
{
    return this -> get_dimension () == other.size ();
}



/**
 * \brief   Check whether two vectors share their dimension.
 * \param   other   The vector to test against.
 * \return  Whether the given vectors share their dimension.
 *
 * This method tests whether this vector is of the same dimension as the given
 * other one.
 */

inline bool Rnfpp :: same_dimension (const Rnfpp & other) const noexcept
{
    return this -> get_dimension () == other.get_dimension ();
}

/******************************************************************************/
