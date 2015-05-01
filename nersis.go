package main

import (
	"./nersis"
	"./nersis/rendering"
	"fmt"
)

func main() {
	fmt.Println("Nersis shall murder you.")
	fmt.Print("Nersis sais: ")
	nersis.Hello()
	rendering.Init()
	for rendering.Update() {
		
	}
}
