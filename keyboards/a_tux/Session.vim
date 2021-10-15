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
edit keymaps/default/keymap.c
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
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
balt rules.mk
setlocal fdm=syntax
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal nofen
let s:l = 35 - ((34 * winheight(0) + 40) / 80)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 35
normal! 059|
wincmd w
argglobal
if bufexists("../pinky/3/keymaps/default/keymap.c") | buffer ../pinky/3/keymaps/default/keymap.c | else | edit ../pinky/3/keymaps/default/keymap.c | endif
if &buftype ==# 'terminal'
  silent file ../pinky/3/keymaps/default/keymap.c
endif
balt ../pinky/3/keymaps/default/config.h
setlocal fdm=syntax
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal nofen
let s:l = 36 - ((8 * winheight(0) + 40) / 80)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 36
normal! 0
wincmd w
wincmd =
tabnext 1
badd +34 config.h
badd +0 ./
badd +11 info.json
badd +41 ../../keyboards/pinky/3/config.h
badd +32 ../../keyboards/pinky/3/3.h
badd +0 ../../keyboards/splitkb/kyria/rev1//rev1.h
badd +43 a_tux.h
badd +1 rules.mk
badd +1 readme.md
badd +1 ../../keyboards/splitkb/kyria/config.h
badd +58 ../../keyboards/splitkb/kyria/rev1//config.h
badd +1 a_tux.c
badd +14 ../pinky/3/info.json
badd +0 keymaps/default/keymap.c
badd +26 ../pinky/3/keymaps/default/config.h
badd +0 ../pinky/3/keymaps/default/keymap.c
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
