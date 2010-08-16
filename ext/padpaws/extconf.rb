require 'mkmf'

## allow for 
##   ruby extconf.rb --with-padpaws-(lib|include|dir)=...
dir_config('padpaws')

## check system for padpaws header and lib first -- then use the
## one included in this repo
have_header('padpaws.h') || 
  find_header('padpaws.h', '../../extlib/padpaws/include')
have_library('padpaws', 'padpaws_init') || 
  find_library('padpaws', 'padpaws_init', '../../extlib/padpaws')

create_makefile('padpawslib')
