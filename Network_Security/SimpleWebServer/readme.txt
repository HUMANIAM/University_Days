This very simple web server support only <Get> command by using socket programming what happen is 
when you write in the url bar <localhost:port/path> (in this program will be <localhost:8088/path>)
the server
1-wait to connect with client
2-when connects with client it take the request then
3-parse it to get the path and deterimine the request type
4-read the data in the path and concatenate it with the header
5-then send the response to the client
6-close the client connection then go to 1