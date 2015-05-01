package lua_helper

import (
	"../rendering"                // Our rendering api compat layer
	"github.com/vifino/golua/lua" // Lua C API bindings and small helpers. Binds LuaJIT. Chooses LuaJIT includes via pkgconfig
	"github.com/vifino/luar"      // Bind Go functions, values to Lua and vice-versa
)

// Bindings, state initialization, etc
// Binds rendering to lua functions
// Also includes lua code to catch nil values or values of wrong type, to make sure we don't get the system to crash
