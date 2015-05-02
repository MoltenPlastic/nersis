#!/usr/bin/env lua
CC_EXE="gcc"
CPP_EXE="g++"
function sh(...)
	local s = ""
	for _,v in pairs({...}) do
		s=s.." "..v
	end
	return os.execute(s)
end
function cc(...)
	sh(CC_EXE,...)
end
function cpp(...)
	sh(CPP_EXE,...)
end
