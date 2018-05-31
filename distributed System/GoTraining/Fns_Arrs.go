package main
import(
	"fmt"
	"math"
) 

//Newton's method
//Zn+1 = Zn - (Zn ^ 2 - x) / (2*Zn)
func Netwen_Sqrt(num float64) float64 {
	if num == 0{ return 0}

	res := float64(1) 			//assumed result
	delta := math.MaxFloat32 	//intialize the error
	
	for delta > 0.001{
		cur_res := res
		res = res - ((math.Pow(res, 2) - num) / (2 * res))
		delta = math.Abs(res - cur_res)
	}
	return res
}

func main() {
	//test numbers from 1 to 10
	for times := float64(1); times<=10; times++{
		z := Netwen_Sqrt(times)
		fmt.Printf("number : %f\n", times)
		fmt.Printf("Newt_Sqrt : %f\n", z)
		fmt.Printf("Sqrt      : %f\n", math.Sqrt(times))
		fmt.Printf("Diff : %f\n", math.Abs(z - math.Sqrt(times)))
		fmt.Print("_______________\n")
	}
}