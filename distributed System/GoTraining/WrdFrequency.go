package main

import (
	//"golang.org/x/tour/wc"
	"fmt"
	"strings"
	"io/ioutil"
)

func WordCount(s string) map[string]int {
	//declare and define dictionary
	Word_Count := make(map[string]int)
	//spilit content into words 
	words := strings.Split(s, " ")
	//count occurence of every word
	//_ character to ignore index of the word
	for _, word := range words{
		_, found := Word_Count[word]
		if found {
			Word_Count[word]++
		}else{
			Word_Count[word] = 1
		}
	}
	return Word_Count
}

func GetData() string{
	//get path of the file
	path := ""
	data := ""
	//get the path of the file
	fmt.Print("File Path : ")
	fmt.Scanf("%s\n", &path)

	//open the file
	for true {
		Bdata, errs := ioutil.ReadFile(path)
		if  errs != nil{
			fmt.Printf("This path <%s> is not correct\n", path)
			fmt.Print("File Path : ")
			fmt.Scanf("%s\n", &path)
		}else{
			data = string(Bdata)
			break
		}
	}
	return string(data)
}

//print the every word and its count
func PrintWrdCnt(wrd_cnt map[string]int) {
	for word, count := range wrd_cnt{
		fmt.Printf("%s : %d\n", word, count)
	}	
}

func main() {
	
	//using wc.Test to test the program
	//wc.Test(WordCount)
	PrintWrdCnt( WordCount(GetData()) )
}
