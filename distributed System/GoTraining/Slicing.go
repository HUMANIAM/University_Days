package main

import  "golang.org/x/tour/pic"
import 	"math/rand"
import  "math"
import  "time"

func Pic(dx, dy int) [][]uint8 {
	//create 2D slice
	picture := make([][]uint8 , dy)

	for i := 0; i<dy; i++{
		//expand every slice of dy to dx
		picture[i] = make([]uint8, dx)

		//fill the elements in this row with random values
		for j := 0; j<dx; j++{
			picture[i][j] = uint8(rand.Intn(int(math.MaxUint8)))
		}
	}
	return picture
}

func main() {
	/*seed rand to get different values 
	at every time we run the progam*/
	rand.Seed(time.Now().UTC().UnixNano())
	pic.Show(Pic)
}
