//Author : Ibrahim saad
//Task   : Crawler
/*This WebCrawler progrem get the URL of the site you want to
  start crawling from it and height and depth of urls
 */

 package main
 import(
  	"fmt"
    "os"
    "strconv"
    "net/http"
    "golang.org/x/net/html"
    "time"
    //"io/ioutil"
    "strings"
  ) 

 //start crawling 
 func UrlCrawler(url string, h int ,w int, c chan string, done chan bool){
    defer func () {done<-true} ()
     //read html content of the url as utf-8 encoded
 	 resp, err := http.Get(url)
 	// check errors
     if err != nil{
        fmt.Println(url, " not crawled")
     }else{
    	//parse the body of the response to get tag tokens
    	//create new tokenizer with resp as ioreader
    	tokenizer := html.NewTokenizer(resp.Body)
    	//start tokenization
    	for {
    		tokenType := tokenizer.Next()

    	switch {
    	//search for StartTags and then find Atag then href

    		case tokenType == html.ErrorToken:
    		// End of the document
    			return

    		case tokenType == html.StartTagToken:

    			token := tokenizer.Token()
        		if token.Data == "a" {

        			//find the href of Atag then push it into the channel
        			if  h > 0{
        				for _, atag := range token.Attr {
    						if atag.Key == "href" {
        						//push it to the urls channel
        						http  := strings.HasPrefix(atag.Val, "http")
        						https := strings.HasPrefix(atag.Val, "https")
        						http_https :=  https || http
        						if(http_https){
        							h--
        							c<-atag.Val
        						}
        						break
    						}
						}
        			}else{
        				return
        			}
				}
			}
    	}
	}
}

 //this function crawle level by level of pages
 func Crawler(h int , w int, c chan string, done chan bool){
 	L := len(c)
 	if w != 0 && L != 0{
 		fmt.Println("Level ", w)
 		fmt.Println("____________")

 		//newch holds new urls from urls in current channel c
 	    newch := make(chan string, L*h)
 	    //used to make sure all urls finished their crawling
 	    Done  := make(chan bool, L)

 		for i:=0; i<L; i++ {
 			url := <-c
 			fmt.Println(url)
 			go UrlCrawler(url, h, w, newch, Done)
 		}

 		//wait till all childs done
 		time.Sleep(10000* time.Millisecond )
 		//for ;len(Done) != L; {}
 		close(c)
 		Crawler(h, w-1, newch, done)

 	}else{
 		//print URLs in the channel
 		fmt.Println("Level ", w)
 		fmt.Println("____________")
 		L := len(c)
 		for i:=0; i<L; i++ {
 			fmt.Println(<-c)
 		}
 	}
 	done<-true
 }

  //Get Arguments (URL, HEIGHT, WIDTH)
 func GetArgs(Args []string)(string, int, int){
 	if len(Args) < 4 {
 		fmt.Println("passed arguments is not enough")
 		os.Exit(1)
 	}

 	height, err1 := strconv.Atoi(Args[2])
 	width, err2 := strconv.Atoi(Args[3])

 	if err1 == nil && err2 == nil {
 		return Args[1], height, width
 	}else{
 		return "error", -1, -1
 	}
 }


//main function
 func main() {
  	//Get Arguments
 	URL, h, w := GetArgs(os.Args)

 	//start crawling
 	if URL != "error"{
 		c := make(chan string, 1)
 		done := make(chan bool)
        go Crawler(h, w, c, done)
        c<- URL   //put root url in the channel
        <-done    //wait till child routine done
 	}else{
 		fmt.Println("pass correct arguments to the program.")
 		os.Exit(1)
 	}
 }