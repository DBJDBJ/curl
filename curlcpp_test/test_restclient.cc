#include "../curlcpp/dbj_common.h"

// until not including dbj json solution, will not test against json
#undef DBJ_CURL_JSON_TESTS

#ifdef DBJ_CURL_JSON_TESTS
#include "dbjcurl_json_tests.h"
#endif DBJ_CURL_JSON_TESTS

#include <string>

#include "../utest/utest.h"
//
// Define shared constants
namespace RestClient {
std::string TestNonExistantUrl;
std::string TestServer;
std::string TestUrl;
std::string TestProxyUrl;
};  // namespace RestClient

// DELETE Tests
// check return code
UTEST(RestClientTest, TestRestClientDELETECode) {
  RestClient::Response res = RestClient::del(RestClient::TestUrl + "/delete");
  EXPECT_EQ(200, res.code);
}

// check for failure
UTEST(RestClientTest, TestRestClientDELETEFailureCode) {
  std::string u = RestClient::TestNonExistantUrl;
  RestClient::Response res = RestClient::del(u);
  // 6 = CURLE_COULDNT_RESOLVE_HOST
  EXPECT_EQ(6, res.code);
}

UTEST(RestClientTest, TestRestClientDELETEHeaders) {
  RestClient::Response res = RestClient::del(RestClient::TestUrl + "/delete");
  EXPECT_EQ("keep-alive", res.headers["Connection"]);
}

// GET Tests
UTEST(RestClientTest, TestRestClientGETCode) {
  RestClient::Response res = RestClient::get(RestClient::TestUrl + "/get");
  EXPECT_EQ(200, res.code);
}

UTEST(RestClientTest, TestRestClientGETHTTP2Code) {
  RestClient::Response res =
      RestClient::get("https://http2.golang.org/reqinfo");
  EXPECT_EQ(200, res.code);
}

// check for failure
UTEST(RestClientTest, TestRestClientGETFailureCode) {
  std::string u = RestClient::TestNonExistantUrl;
  RestClient::Response res = RestClient::get(u);
  EXPECT_EQ("Couldn't resolve host name", res.body);
  // 6 = CURLE_COULDNT_RESOLVE_HOST
  EXPECT_EQ(6, res.code);
}

UTEST(RestClientTest, TestRestClientGETHeaders) {
  RestClient::Response res = RestClient::get(RestClient::TestUrl + "/get");
  EXPECT_EQ("keep-alive", res.headers["Connection"]);
}

// POST Tests
// check return code
UTEST(RestClientTest, TestRestClientPOSTCode) {
  RestClient::Response res =
      RestClient::post(RestClient::TestUrl + "/post", "text/text", "data");
  EXPECT_EQ(200, res.code);
}

// check for failure
UTEST(RestClientTest, TestRestClientPOSTFailureCode) {
  std::string u = RestClient::TestNonExistantUrl;
  RestClient::Response res = RestClient::post(u, "text/text", "data");
  // 6 = CURLE_COULDNT_RESOLVE_HOST
  EXPECT_EQ(6, res.code);
}

UTEST(RestClientTest, TestRestClientPOSTHeaders) {
  RestClient::Response res =
      RestClient::post(RestClient::TestUrl + "/post", "text/text", "data");
  EXPECT_EQ("keep-alive", res.headers["Connection"]);
}

// PUT Tests
// check return code
UTEST(RestClientTest, TestRestClientPUTCode) {
  RestClient::Response res =
      RestClient::put(RestClient::TestUrl + "/put", "text/text", "data");
  EXPECT_EQ(200, res.code);
}

// check for failure
UTEST(RestClientTest, TestRestClientPUTFailureCode) {
  std::string u = RestClient::TestNonExistantUrl;
  RestClient::Response res = RestClient::put(u, "text/text", "data");
  // 6 = CURLE_COULDNT_RESOLVE_HOST
  EXPECT_EQ(6, res.code);
}

UTEST(RestClientTest, TestRestClientPUTHeaders) {
  RestClient::Response res =
      RestClient::put(RestClient::TestUrl + "/put", "text/text", "data");
  EXPECT_EQ("keep-alive", res.headers["Connection"]);
}

// PATCH Tests
// check return code
UTEST(RestClientTest, TestRestClientPATCHCode) {
  RestClient::Response res =
      RestClient::patch(RestClient::TestUrl + "/patch", "text/text", "data");
  EXPECT_EQ(200, res.code);
}

// check for failure
UTEST(RestClientTest, TestRestClientPATCHFailureCode) {
  std::string u = RestClient::TestNonExistantUrl;
  RestClient::Response res = RestClient::patch(u, "text/text", "data");
  // 6 = CURLE_COULDNT_RESOLVE_HOST
  EXPECT_EQ(6, res.code);
}

UTEST(RestClientTest, TestRestClientPATCHHeaders) {
  RestClient::Response res =
      RestClient::patch(RestClient::TestUrl + "/put", "text/text", "data");
  EXPECT_EQ("keep-alive", res.headers["Connection"]);
}

// OPTIONS Tests
// check return code
// Disabled as httpbin does not support options requests for now
UTEST(RestClientTest, TestRestClientOPTIONSCode) {
  RestClient::Response res =
      RestClient::options("https://api.reqbin.com/api/v1/requests");
  EXPECT_EQ(200, res.code);
}

// check for failure
UTEST(RestClientTest, TestRestClientOPTIONSFailureCode) {
  std::string u = RestClient::TestNonExistantUrl;
  RestClient::Response res = RestClient::options(u);
  // 6 = CURLE_COULDNT_RESOLVE_HOST
  EXPECT_EQ(6, res.code);
}

UTEST(RestClientTest, TestRestClientOPTIONSHeaders) {
  RestClient::Response res =
      RestClient::options(RestClient::TestUrl + "/options");
  EXPECT_EQ("keep-alive", res.headers["Connection"]);
}

UTEST(RestClientTest, TestRestClientHeadCode) {
  RestClient::Response res = RestClient::head(RestClient::TestUrl + "/get");
  EXPECT_EQ(200, res.code);
  EXPECT_EQ("", res.body);
}

UTEST_STATE();
int main(int argc, const char *const argv[]) {
#ifdef WIN32
    // needed to kickstart the win10 cmd.exe vt100 
    // sadly this is true
  system(" ");
#endif  // WIN32
  // Initialize shared constants
  RestClient::TestNonExistantUrl = "http://nonexistent";
  RestClient::TestServer = "127.0.0.1:8998";
  RestClient::TestUrl = "http://" + RestClient::TestServer;
  RestClient::TestProxyUrl = "http://127.0.0.1:3128";

  RestClient::init();

  utest_main(argc, argv);
  RestClient::disable();

  return 42;
}
