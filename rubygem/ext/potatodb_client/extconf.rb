# coding: utf-8
# frozen_string_literal: false

require 'mkmf'

# $LOCAL_LIBS << ' -lclipboard'

if RUBY_PLATFORM =~ /darwin/
  $LDFLAGS << ' -framework AppKit'
end

create_header
create_makefile 'potatodb_client/potatodb_client'
