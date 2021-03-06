%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%% Copyright (C) 2022 Kevin Matthes
%%
%% This program is free software; you can redistribute it and/or modify
%% it under the terms of the GNU General Public License as published by
%% the Free Software Foundation; either version 2 of the License, or
%% (at your option) any later version.
%%
%% This program is distributed in the hope that it will be useful,
%% but WITHOUT ANY WARRANTY; without even the implied warranty of
%% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%% GNU General Public License for more details.
%%
%% You should have received a copy of the GNU General Public License along
%% with this program; if not, write to the Free Software Foundation, Inc.,
%% 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
%%
%%%%
%%
%%  FILE
%%      g++-ar.m
%%
%%  BRIEF
%%      Create a static library from C++ source code using `g++` and `ar`.
%%
%%  AUTHOR
%%      Kevin Matthes
%%
%%  COPYRIGHT
%%      (C) 2022 Kevin Matthes.
%%      This file is licensed GPL 2 as of June 1991.
%%
%%  DATE
%%      2022
%%
%%  NOTE
%%      See `LICENSE' for full license.
%%      See `README.md' for project details.
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%
%%
%% Variables.
%%
%%%%

% Software.
archiver.args   = 'rsv';
archiver.in     = '*.o';
archiver.out    = ['lib' 'Rnfpp' '.a'];
archiver.self   = 'ar';
archiver.call   = [ archiver.self ' ' archiver.args ' ' archiver.out ' '     ...
                    archiver.in                                              ...
                  ];

compiler.args   = [ ' -std=c++11 -Wall -Werror -Wextra -Wpedantic -c '       ...
                    ' -D__RNFPP_INTERNAL__ '                                 ...
                  ];
compiler.in     = '*.cpp';
compiler.out    = '*.o';
compiler.self   = 'g++';
compiler.call   = [compiler.self ' ' compiler.args ' ' compiler.in];



% Miscellaneous.
misc.self   = 'g++-ar.m';
misc.banner = ['[ ' misc.self ' ] '];



%%%%
%%
%% Build steps.
%%
%%%%

% Begin build instruction.
disp ([misc.banner 'Begin build instruction.']);



% Clean outdated library.
fprintf ([misc.banner 'Remove outdated version of ' archiver.out ' ... ']);

if length (glob (archiver.out));
    delete (archiver.out);
end;

disp ('Done.');



% Call C++ compiler.
disp ([misc.banner 'Compile object files ...']);

disp (compiler.call);
system (compiler.call);

disp ([misc.banner 'Done.']);



% Call library creation tool.
if length (glob (archiver.in));
    disp ([misc.banner 'Create library ' archiver.out ' ...']);

    disp (archiver.call);
    system (archiver.call);

    disp ([misc.banner 'Done.']);
end;



% Clean artifacts.
fprintf ([misc.banner 'Remove build artifacts ... ']);

if length (glob (compiler.out));
    delete (compiler.out);
end;

disp ('Done.');



% End build instruction.
disp ([misc.banner 'End build instruction.']);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
