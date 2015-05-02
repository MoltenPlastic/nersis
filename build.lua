#!/usr/bin/env lua
CC_EXE="gcc"
CPP_EXE="g++"
function sh(...)
	local err=os.execute(table.concat({...}," "))
	assert(err==0,"Error code "..err)
end
function cc(...)
	sh(CC_EXE,...)
end
function cpp(...)
	sh(CPP_EXE,...)
end
