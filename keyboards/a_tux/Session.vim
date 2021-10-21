let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/projects/qmk_firmware/keyboards/a_tux
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
argglobal
%argdel
$argadd ./
edit a_tux.h
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd w
wincmd _ | wincmd |
split
1wincmd k
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
wincmd =
argglobal
balt readme.md
setlocal fdm=syntax
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=1
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 1 - ((0 * winheight(0) + 12) / 25)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists("rules.mk") | buffer rules.mk | else | edit rules.mk | endif
if &buftype ==# 'terminal'
  silent file rules.mk
endif
balt config.h
setlocal fdm=syntax
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal nofen
let s:l = 23 - ((22 * winheight(0) + 13) / 26)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 23
normal! 0
wincmd w
argglobal
if bufexists("../for_science/for_science.h") | buffer ../for_science/for_science.h | else | edit ../for_science/for_science.h | endif
if &buftype ==# 'terminal'
  silent file ../for_science/for_science.h
endif
balt ../for_science/config.h
setlocal fdm=syntax
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal nofen
let s:l = 8 - ((4 * winheight(0) + 12) / 25)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 8
normal! 021|
wincmd w
argglobal
if bufexists("../for_science/config.h") | buffer ../for_science/config.h | else | edit ../for_science/config.h | endif
if &buftype ==# 'terminal'
  silent file ../for_science/config.h
endif
balt ../for_science/keymaps/default/keymap.c
setlocal fdm=syntax
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal nofen
let s:l = 37 - ((0 * winheight(0) + 13) / 26)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 37
normal! 09|
wincmd w
wincmd =
tabnext 1
badd +51 config.h
badd +0 ./
badd +50 info.json
badd +41 ../../keyboards/pinky/3/config.h
badd +32 ../../keyboards/pinky/3/3.h
badd +0 ../../keyboards/splitkb/kyria/rev1//rev1.h
badd +43 a_tux.h
badd +6 rules.mk
badd +1 readme.md
badd +1 ../../keyboards/splitkb/kyria/config.h
badd +58 ../../keyboards/splitkb/kyria/rev1//config.h
badd +1 a_tux.c
badd +14 ../pinky/3/info.json
badd +31 keymaps/default/keymap.c
badd +26 ../pinky/3/keymaps/default/config.h
badd +36 ../pinky/3/keymaps/default/keymap.c
badd +7 ../a_dux/info.json
badd +126 ../a_dux/keymaps/daliusd//keymap.c
badd +27 ../for_science/config.h
badd +25 ../for_science/for_science.h
badd +30 ../for_science/keymaps/default/keymap.c
badd +16 ../for_science/rules.mk
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToOF
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
let g:this_session = v:this_session
let g:this_obsession = v:this_session
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
