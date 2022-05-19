<!------------------------------------------------------------------------------
--
-- Copyright (C) 2022 Kevin Matthes
--
-- This program is free software; you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation; either version 2 of the License, or
-- (at your option) any later version.
--
-- This program is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.
--
-- You should have received a copy of the GNU General Public License along
-- with this program; if not, write to the Free Software Foundation, Inc.,
-- 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
--
----
--
--  FILE
--      CHANGELOG.md
--
--  BRIEF
--      The development history of this project.
--
--  AUTHOR
--      Kevin Matthes
--
--  COPYRIGHT
--      (C) 2022 Kevin Matthes.
--      This file is licensed GPL 2 as of June 1991.
--
--  DATE
--      2022
--
--  NOTE
--      See `LICENSE' for full license.
--      See `README.md' for project details.
--
------------------------------------------------------------------------------->

# Changelog

## [Unreleased]

### Added

* create `assert_outer_product.cpp`
* create `outer.cpp`

### Fixed

* invalid return types

## [0.1.2] -- 2022-05-15

### Added

* create `affinise.cpp`
* create `assert_affinisation.cpp`
* create `assert_norm_non_zero.cpp`
* create `homogenise.cpp`
* create `normalise.cpp`

### Changed

* rename `~Rnfpp.cpp` to `destructor.cpp`

### Fixed

* missing documentation for destructor source file

## [0.1.1] -- 2022-05-15

### Added

* add `preferred-citation`
* create `addition_inplace.cpp`
* create `division_inplace.cpp`
* create `multiplication_inplace.cpp`
* create `subtraction_inplace.cpp`
* GitHub Action:  automatic CFF validation
* overloads for methods
* submodule `doxygen.cfg`

### Changed

* update `blank`

## [0.1.0] -- 2022-05-11

### Added

* create `CITATION.cff`
* create `distance.cpp`
* create `~Rnfpp.cpp`
* create `set_components.cpp`
* submodule `blank`
* typedef:  `fvec_t`

### Changed

* optimise repository manual build instruction
* rename `g++-dll.m` to `dll-g++.m`
* unite `authors.yaml` with `project.yaml`
* update `docs-snippets`
* update Doxygen settings to work with version 1.9.1
* update `routines`

### Fixed

* G++ typos
* incorrect variable values in build instructions

### Removed

* `authors.yaml`

## [0.0.5] -- 2022-04-26

### Added

* create `assert_range.cpp`
* create `index.cpp`
* create `inner.cpp`
* create `norm.cpp`
* further docstrings

### Changed

* adjust method implementations

### Fixed

* call index elements only using the `.at ()` method of `std :: vector <float>`
* indentation in header file

## [0.0.4] -- 2022-04-26

### Added

* build instruction:  DLL compilation
* create `assert_non_zero.cpp`
* create `division.cpp`
* create `g++-dll.m`
* create `multiplication.cpp`
* create `same_dimension.cpp`
* create `subtraction.cpp`

### Changed

* qualify all getters as `noexcept`

### Fixed

* enable Windows compilation to DLL
* qualify all methods as `const`

## [0.0.3] -- 2022-04-25

### Added

* build instruction:  library creation
* create `addition.cpp`
* create `assert_same_dimension.cpp`
* create `equality.cpp`
* create `g++-ar.m`

### Changed

* rename `Rnfpp :: dimension ()` to `Rnfpp :: get_dimension ()`
* rename `dimension.cpp` to `get_dimension.cpp`

### Fixed

* discarded qualifiers
* logical errors
* type conflicts

## [0.0.2] -- 2022-04-25

### Added

* build instruction:  Doxygen
* create `dimension.cpp`
* create `get_components.cpp`
* create `Rnfpp.cpp`
* create `Rnfpp.hpp`
* Doxygen settings

### Changed

* adjust README description
* update `docs-snippets`

## [0.0.1] -- 2022-04-25

### Added

* add GPL 2.0 license
* build instruction:  repository manual
* create `.gitignore`
* create list of authors
* create project meta data for repository manual
* create repository README
* create this changelog
* create this repository
* submodule `docs-snippets`
* submodule `routines`

<!----------------------------------------------------------------------------->
