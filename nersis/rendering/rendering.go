package rendering

import (
	"github.com/go-gl/gl/v3.2-core/gl"
	"github.com/veandco/go-sdl2/sdl"
	"runtime"
	"fmt"
)

// Should provide universal calls for all graphics systems we support, like OGL, SDL, etc..
// Generally focusing on OGL is a good idea. Using stuff from https://github.com/go-gl is probably the best idea.
var event sdl.Event
var window *sdl.Window
var context sdl.GLContext

func Init() {
	var winTitle string = "Go-SDL2 + Go-GL"
	var winWidth, winHeight int = 800, 600
	var err error
	
	runtime.LockOSThread() // Lock current Gorutine to the thread so we don't run into issues with OGL
	sdl.Init(sdl.INIT_EVERYTHING)
	window, err = sdl.CreateWindow(winTitle, sdl.WINDOWPOS_UNDEFINED, sdl.WINDOWPOS_UNDEFINED,
        winWidth, winHeight, sdl.WINDOW_SHOWN|sdl.WINDOW_OPENGL)
	if err != nil {
		panic(err)
	}
	
	if err = gl.Init(); err != nil {
		panic(err)
	}
	fmt.Println("OpenGL 3.2 initialized!")
	
	context, err = sdl.GL_CreateContext(window);
	if err != nil {
		panic(err)
	}
}

func Update() (bool) {
	for event = sdl.PollEvent(); event != nil; event = sdl.PollEvent() {
		switch t := event.(type) {
		case *sdl.QuitEvent:
			return false
		case *sdl.MouseMotionEvent:
			fmt.Printf("[%d ms] MouseMotion\tid:%d\tx:%d\ty:%d\txrel:%d\tyrel:%d\n", t.Timestamp, t.Which, t.X, t.Y, t.XRel, t.YRel)
		}
	}
	gl.ClearColor(1,0,0,1);
	gl.Clear(gl.COLOR_BUFFER_BIT);
	sdl.GL_SwapWindow(window)
	return true
}
