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
 * \file        division.cpp
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
 * \brief   The division operator.
 * \param   other   The scalar to divide this vector by.
 * \return  The scaled vector.
 * \throws  invalid_argument    In case the scalar should be zero.
 *
 * This method will scale this vector by the given scalar by division.
 */

Rnfpp Rnfpp :: operator / (const float other) const
{
    this -> assert_non_zero (other);

    vector <float> ret = vector <float> (this -> components.size ());

    for (dimension_t i = 0x0; i < this -> components.size (); i++)
        ret[i] = this -> components[i] / other;

    return Rnfpp (ret);
}

/******************************************************************************/
