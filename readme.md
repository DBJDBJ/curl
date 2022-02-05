# DBJ CURL

Currently this is a [CURL](https://en.wikipedia.org/wiki/CURL) based code playground.

cpp in here is atrocious and I have a burning desire to refactor it into C11. And indeed I will. Time permitting.

In any case I remember this code being a good starting point with libcurl.

## Some unavoidable prose first

First of all [libcurl is old](https://curl.se/docs/history.html). in 2015 it was 17 years old.

It is written in C and that is a good thing, I would do he same in 2022. But the whole project ethos is unmistakably "different"

Further to that, for some reason https://github.com/curl/ has no `curl` and `libcurl` in two clearly divided projects aka "repos". I remember looking around in disbelief trying to found just a `libcurl`. Just a libcurl source code without curl, cmake, docs, circleci, plan9, zuul etc. 

Truth to be told there is [pretty extensive web site](https://curl.se/), downloads page, downloads wizard (no windows), and all the other XX century paraphernalia. But, no `libcurl` github repo.

Finally I downloaded binaries from [one site](https://skanthak.homepage.t-online.de/curl.html) and header from the official repo. And that worketh.

After a few years of usage, that is now refreshed with the latest curl and made available in this repo.

In any case Curl is by now a part of Windows 10. Before copy pasting code in here, definitely have a long play with it, from a cmd.exe,using many (many) [examples one can google out](https://rapidapi.com/blog/best-stock-api/).

I tend to use [YH Finance](https://rapidapi.com/apidojo/api/yh-finance). No affiliation.

In the mean time next is the libcurl "step 0":

<h1>CURL Most Basic Use-cases</h1>

> By Chandan Kumar on April 5, 2021; Posted in [GeekFlare](https://geekflare.com/curl-command-usage-with-example/) 

<h2>cURL is a command-line tool to get or send data using (almost) URL syntax.</h2>

If you are working as a developer or in the support function, you must be aware of cURL command usage to troubleshoot web applications. cURL is a cross-platform utility means you can use on Windows, MAC, and UNIX.

The following are some of the most used syntaxes with an example to help you.

## 1. Verify if you can connect to the URL
If you are working on a UNIX system and trying to connect the external URL, the first thing you wish to do is to check if you can access the URL through curl.
```
curl yoururl.com
```
It will not throw any output. However, if the server can’t connect, then you will get errors such as: "could not resolve the host".

## 2. Save URL/URI output to file
If you have to save the URL or URI contents to a specific file, you can use the following syntax
```
curl https://yoururl.com > yoururl.html
curl https://gf.dev > /tmp/gfhtml
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100 18557    0 18557    0     0  72565      0 --:--:-- --:--:-- --:--:-- 72772
```

Above example will save all the contents from gf.dev to /tmp/gf.html

## 3. Show request and response header
If you are having issues and would like to validate, you are getting the expected request and response header.

curl -v yoururl.com
Ex:
```
 curl -v https://geekflare.com
* About to connect() to geekflare.com port 443 (#0)
*   Trying 104.25.134.107...
* Connected to geekflare.com (104.25.134.107) port 443 (#0)
* Initializing NSS with certpath: sql:/etc/pki/nssdb
*   CAfile: /etc/pki/tls/certs/ca-bundle.crt
  CApath: none
* SSL connection using TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256
* Server certificate:
* 	subject: CN=ssl371609.cloudflaressl.com,OU=PositiveSSL Multi-Domain,OU=Domain Control Validated
* 	start date: Nov 07 00:00:00 2019 GMT
* 	expire date: May 15 23:59:59 2020 GMT
* 	common name: ssl371609.cloudflaressl.com
* 	issuer: CN=COMODO ECC Domain Validation Secure Server CA 2,O=COMODO CA Limited,L=Salford,ST=Greater Manchester,C=GB
> GET / HTTP/1.1
> User-Agent: curl/7.29.0
> Host: geekflare.com
> Accept: */*
> 
< HTTP/1.1 200 OK
< Date: Sat, 09 Nov 2019 19:41:37 GMT
< Content-Type: text/html; charset=UTF-8
< Transfer-Encoding: chunked
< Connection: keep-alive
< Set-Cookie: __cfduid=d2ce6cd359ebc0b6eb5ff3a454ed042021573328497; expires=Sun, 08-Nov-20 19:41:37 GMT; path=/; domain=.geekflare.com; HttpOnly; Secure
< Vary: Accept-Encoding
< Link: <https://geekflare.com/wp-json/>; rel="https://api.w.org/"
< Link: <https://geekflare.com/>; rel=shortlink
< X-SRCache-Fetch-Status: HIT
< X-SRCache-Store-Status: BYPASS
< X-Frame-Options: SAMEORIGIN
< X-Powered-By: EasyEngine v4.0.12
< Via: 1.1 google
< CF-Cache-Status: DYNAMIC
< Strict-Transport-Security: max-age=15552000; preload
< X-Content-Type-Options: nosniff
< Alt-Svc: h3-23=":443"; ma=86400
< Expect-CT: max-age=604800, report-uri="https://report-uri.cloudflare.com/cdn-cgi/beacon/expect-ct"
< Server: cloudflare
< CF-RAY: 533243e4bcd4bbf4-LHR
<
```
## 4. Download at a limit rate
If you are working on optimization and would like to see how much time does it take to download at a particular speed, you can:-
```
curl –-limit-rate 2000B
```
Ex:
```
curl –-limit-rate 2000B https://gf.dev
```
## 5. Using a proxy to connect
Very handy if you are working on the DMZ server where you need to connect to the external world using a proxy.
```
curl --proxy yourproxy:port https://yoururl.com
```
## 6. Test URL with injecting header
You can use curl by inserting a header with your data to test or troubleshoot the particular issue. Let’s see the following example to request with Content-Type.
```
curl --header 'Content-Type: application/json' http://yoururl.com
```
By doing above, you are asking curl to pass Content-Type as application/json in the request header.

## 7. Display only response header
If you are doing some troubleshooting and quickly want to check the response header, you can use the following syntax.
```
curl --head http://yoururl.com
```
Ex:
```
 curl --head https://chandan.io
HTTP/1.1 200 OK
Date: Sat, 09 Nov 2019 19:51:23 GMT
Content-Type: text/html
Connection: keep-alive
Set-Cookie: __cfduid=d3cb2c7b8e566ad99c870b0af12b0f1eb1573329083; expires=Sun, 08-Nov-20 19:51:23 GMT; path=/; domain=.chandan.io; HttpOnly
X-GUploader-UploadID: AEnB2Uo96JhvJmR2zYUL-Ndh2ta3UD_ykQAB5C7O8cjZQhCf-GxHQ0MsodSzRnl3guSN3ywAYNjtWcPXfwDXjLg3bQ-P5vQMOA
Expires: Sat, 09 Nov 2019 20:51:23 GMT
Cache-Control: public, max-age=3600
Last-Modified: Mon, 06 Aug 2018 10:45:47 GMT
x-goog-generation: 1533552347482034
x-goog-metageneration: 1
x-goog-stored-content-encoding: identity
x-goog-stored-content-length: 24620
x-goog-hash: crc32c=DpDPAQ==
x-goog-hash: md5=cIP/3rusdUx12Zla1kf1yA==
x-goog-storage-class: MULTI_REGIONAL
Accept-Ranges: bytes
CF-Cache-Status: DYNAMIC
Expect-CT: max-age=604800, report-uri="https://report-uri.cloudflare.com/cdn-cgi/beacon/expect-ct"
Server: cloudflare
CF-RAY: 53325234dc2fbb9a-LHR
```
## 8. Connect HTTPS/SSL URL and ignore any SSL certificate error

When you try to access SSL/TLS cert secured URL and if that is having the wrong cert or CN doesn’t match, then you will get the following error.
```
curl: (51) Unable to communicate securely with peer: requested domain name does not match the server's certificate.
```
Good news, you can instruct cURL to ignore the cert error with the `--insecure` flag.
```
curl --insecure https://yoururl.com
```
## 9. Connect using a specific protocol (SSL/TLS)
Very handy to test if a particular URL can handshake over specific SSL/TLS protocol.

### 9.1. To connect using SSL v3
```
curl --sslv3 https://yoururl.com
```
and for different TLS versions
```
curl --tlsv1 https://example.com
curl --tlsv1.0 https://example.com
curl --tlsv1.1 https://example.com
curl --tlsv1.2 https://example.com
curl --tlsv1.3 https://example.com
```
## 10. Download file from FTP Server
You can use curl to download the file as well by specifying username and password.
```
curl -u user:password -O ftp://ftpurl/style.css
```
You can always use “-v” with any syntax to print in verbose mode.

## 11. Using Host Header
The host header is useful to test the target URL over IP when the requested content is only available when host header matches. Or, if you want to test application using load balancer IP/URL.
```
curl --header 'Host: targetapplication.com' https://192.0.0.1:8080/
```
## 12. How about using cURL online?
Yes, that’s possible with the following tools. You can execute cURL remotely.

### 12.1. [Online CURL](https://onlinecurl.com/)
A lightweight tool to fetch the URL online and the possibility to add the following options.
```
--connect-timeout
--cookie
--data
--header
--head
--location
--max-time
--proxy
--request
--user
--url
--user-agent
```
### 12.2. [cURL command line builder](https://curlbuilder.com/) 
This one is different. It helps you to build the curl command where you can enter information in nice UI, and at the bottom, you will get the cURL command.

## 13. Conclusion

cURL is a useful utility to troubleshoot a real-time connectivity issue, and I hope the above helps you.