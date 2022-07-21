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
 * \file        assert_outer_product.cpp
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
 * \brief   Ensure the outer product to be calculatable.
 * \param   other   The vector to calculate the outer product with.
 * \throws  invalid_argument    In case it is not.
 *
 * This method tests whether an outer product can be determined from this vector
 * and the other one.  If not so, an exception will be thrown.
 */

void Rnfpp :: assert_outer_product (const fvec_t & other) const
{
    this -> assert_same_dimension (other);

    const dimension_t dimension = this -> get_dimension ();

    if (dimension != 0x2 && dimension != 0x3)
        throw invalid_argument ("The outer product requires dimension 2 or 3!");

    return;
}



/**
 * \brief   Ensure the outer product to be calculatable.
 * \param   other   The vector to calculate the outer product with.
 * \throws  invalid_argument    In case it is not.
 *
 * This method tests whether an outer product can be determined from this vector
 * and the other one.  If not so, an exception will be thrown.
 */

void Rnfpp :: assert_outer_product (const Rnfpp & other) const
{
    this -> assert_same_dimension (other);

    const dimension_t dimension = this -> get_dimension ();

    if (dimension != 0x2 && dimension != 0x3)
        throw invalid_argument ("The outer product requires dimension 2 or 3!");

    return;
}

/******************************************************************************/
