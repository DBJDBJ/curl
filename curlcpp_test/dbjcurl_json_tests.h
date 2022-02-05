#pragma once



UTEST(RestClientTest, TestRestClientDELETEBody) {
  RestClient::Response res = RestClient::del(RestClient::TestUrl + "/delete");
  Json::Value root;
  std::istringstream str(res.body);
  str >> root;

  EXPECT_EQ(RestClient::TestUrl + "/delete",
            root.get("url", "no url set").asString());
  EXPECT_EQ("restclient-cpp/" RESTCLIENT_VERSION,
            root["headers"].get("User-Agent", "no url set").asString());
}



UTEST(RestClientTest, TestRestClientGETBodyCode) {
  RestClient::Response res = RestClient::get(RestClient::TestUrl + "/get");
  Json::Value root;
  std::istringstream str(res.body);
  str >> root;

  EXPECT_EQ(RestClient::TestUrl + "/get",
            root.get("url", "no url set").asString());
  EXPECT_EQ("restclient-cpp/" RESTCLIENT_VERSION,
            root["headers"].get("User-Agent", "no url set").asString());
}


UTEST(RestClientTest, TestRestClientPOSTBody) {
  RestClient::Response res =
      RestClient::post(RestClient::TestUrl + "/post", "text/text", "data");
  Json::Value root;
  std::istringstream str(res.body);
  str >> root;

  EXPECT_EQ(RestClient::TestUrl + "/post",
            root.get("url", "no url set").asString());
  EXPECT_EQ("restclient-cpp/" RESTCLIENT_VERSION,
            root["headers"].get("User-Agent", "no url set").asString());
}


UTEST(RestClientTest, TestRestClientPATCHBody) {
  RestClient::Response res =
      RestClient::patch(RestClient::TestUrl + "/patch", "text/text", "data");
  Json::Value root;
  std::istringstream str(res.body);
  str >> root;

  EXPECT_EQ(RestClient::TestUrl + "/patch",
            root.get("url", "no url set").asString());
  EXPECT_EQ("restclient-cpp/" RESTCLIENT_VERSION,
            root["headers"].get("User-Agent", "no url set").asString());
}

UTEST(RestClientTest, TestRestClientAuth) {
  RestClient::Response res = RestClient::get(
      "http://foo:bar@" + RestClient::TestServer + "/basic-auth/foo/bar");
  EXPECT_EQ(200, res.code);

  Json::Value root;
  std::istringstream str(res.body);
  str >> root;

  EXPECT_EQ("foo", root.get("user", "no user").asString());
  EXPECT_EQ(true, root.get("authenticated", false).asBool());

  res = RestClient::get("http://" + RestClient::TestServer +
                        "/basic-auth/foo/bar");
  EXPECT_EQ(401, res.code);
}


UTEST(RestClientTest, TestRestClientPUTBody) {
  RestClient::Response res =
      RestClient::put(RestClient::TestUrl + "/put", "text/text", "data");
  Json::Value root;
  std::istringstream str(res.body);
  str >> root;

  EXPECT_EQ(RestClient::TestUrl + "/put",
            root.get("url", "no url set").asString());
  EXPECT_EQ("restclient-cpp/" RESTCLIENT_VERSION,
            root["headers"].get("User-Agent", "no url set").asString());
}

