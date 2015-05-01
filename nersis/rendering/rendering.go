package rendering

import (
	"github.com/go-gl/gl/v3.2-core/gl"
	"runtime"
)

// Should provide universal calls for all graphics systems we support, like OGL, SDL, etc..
// Generally focusing on OGL is a good idea. Using stuff from https://github.com/go-gl is probably the best idea.

func Init() {
	runtime.LockOSThread() // Lock current Gorutine to the thread so we don't run into issues with OGL
	if err := gl.Init(); err != nil {
		panic(err)
	}
}
