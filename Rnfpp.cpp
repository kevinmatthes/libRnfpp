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
 * \file        Rnfpp.cpp
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
 * \brief   Construct a new Rnfpp object.
 *
 * This is the default constructor which will prepare a new vector.
 */

Rnfpp :: Rnfpp (void)
{
    Rnfpp (0x0);
    return;
}



/**
 * \brief   Construct a new Rnfpp object.
 * \param   dimension   The expected initial dimension.
 *
 * This constructor will prepare a new vector and give it the expected initial
 * dimension.  This benefits the performance in later applications of the
 * resulting object.
 */

Rnfpp :: Rnfpp (const dimension_t dimension)
{
    this -> components = fvec_t (dimension);
    return;
}



/**
 * \brief   Construct a new Rnfpp object from a given component vector.
 * \param   components  The components to hold.
 *
 * This constructor prepares a new vector and initialises it with the components
 * of the given `std :: vector <float>`.
 */

Rnfpp :: Rnfpp (const fvec_t & components)
{
    Rnfpp (components.size ());

    for (dimension_t i = 0x0; i < components.size (); i++)
        (* this)[i] = components.at (i);

    return;
}



/**
 * \brief   Construct a new Rnfpp object from an existing one.
 * \param   rnfpp   The existing object to copy.
 *
 * This constructor will create a deep copy of the given existing object.
 */

Rnfpp :: Rnfpp (const Rnfpp & rnfpp)
{
    Rnfpp (rnfpp.get_components ());
    return;
}

/******************************************************************************/
