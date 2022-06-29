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
%%      dll-g++.m
%%
%%  BRIEF
%%      Create a DLL from C++ source code using `g++`.
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
                    ' -D__WINDOWS__ -D__MAKE_DLL__ '                         ...
                  ];
compiler.in     = glob ('*.cpp');
compiler.out    = '*.o';
compiler.self   = 'g++';
compiler.call   = [compiler.self ' ' compiler.args ' '];

linker.args = [ ' -shared -Wl,--out-implib,' archiver.out                    ...
                ' -Wl,--enable-auto-image-base '    ...
              ];
%' -W1,--export-all-symbols
linker.in   = glob ('*.o');
linker.out  = ['Rnfpp' '.dll'];
linker.self = 'g++';
linker.call = [linker.self ' -o ' linker.out  ' ' linker.args ' '];



% Miscellaneous.
misc.self   = 'dll-g++.m';
misc.banner = ['[ ' misc.self ' ] '];



%%%%
%%
%% Build steps.
%%
%%%%

% Begin build instruction.
disp ([misc.banner 'Begin build instruction.']);



% Clean outdated library.
fprintf ([misc.banner 'Remove outdated version of ' linker.out ' ... ']);

if length (glob (linker.out));
    delete (linker.out);
end;

disp ('Done.');



% Call C++ compiler.
disp ([misc.banner 'Compile object files ...']);

input = '';

for cpp = 1 : length (compiler.in);
    input = [input ' ' compiler.in{cpp}];
end;

disp ([compiler.call ' ' input]);
system ([compiler.call ' ' input]);

disp ([misc.banner 'Done.']);



% Call library creation tool.
if length (glob (archiver.in));
    disp ([misc.banner 'Create library ' archiver.out ' ...']);

    disp (archiver.call);
    system (archiver.call);

    disp ([misc.banner 'Done.']);
end;



% Call linker for DLL linking
if length (glob (archiver.out));
    disp ([misc.banner 'Create DLL ' linker.out ' ...']);

    input = '';

    for o = 1 : length (linker.in);
        input = [input ' ' linker.in{o}];
    end;

    disp ([linker.call ' ' input]);
    system ([linker.call ' ' input]);

    disp ([misc.banner 'Done.']);
end;



% Clean artifacts.
fprintf ([misc.banner 'Remove build artifacts ... ']);

if length (glob (compiler.out));
    delete (compiler.out);
end;

if length (glob (archiver.out));
    delete (archiver.out);
end;

disp ('Done.');



% End build instruction.
disp ([misc.banner 'End build instruction.']);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
