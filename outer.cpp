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
 * \file        outer.cpp
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
 * \brief   The outer product of two vectors.
 * \param   other   The vector to calculate the outer product with.
 * \return  The outer product.
 * \throws  invalid_argument    In case the vectors are of different dimensions.
 *
 * This method determines the outer product of this vector with the other one.
 */

inline Rnfpp Rnfpp :: outer (const fvec_t & other) const
{
    this -> assert_outer_product (other);
    return this -> outer (Rnfpp (other));
}



/**
 * \brief   The outer product of two vectors.
 * \param   other   The vector to calculate the outer product with.
 * \return  The outer product.
 * \throws  invalid_argument    In case the vectors are of different dimensions.
 *
 * This method determines the outer product of this vector with the other one.
 */

Rnfpp Rnfpp :: outer (const Rnfpp & other) const
{
    this -> assert_outer_product (other);

    const float ox  = other[0x0];
    const float oy  = other[0x1];
    const float tx  = (* this)[0x0];
    const float ty  = (* this)[0x1];
    fvec_t      ret = fvec_t (0x3);

    if (this -> get_dimension () == 0x2)
    {
        ret.at (0x0) = 0x0;
        ret.at (0x1) = 0x0;
        ret.at (0x2) = tx * oy - ty * ox;
    }
    else
    {
        const float oz  = other[0x2];
        const float tz  = (* this)[0x2];

        ret.at (0x0) = ty * oz - tz * oy;
        ret.at (0x1) = tz * ox - tx * oz;
        ret.at (0x2) = tx * oy - ty * ox;
    };

    return Rnfpp (ret);
}

/******************************************************************************/
