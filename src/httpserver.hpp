#ifndef HTTPSERVER_HPP_
#define HTPPSERVER_HPP_

#include <boost/network/protocol/http/server.hpp>
#include <boost/network/uri.hpp>
#include <string>
#include <iostream>

namespace http = boost::network::http;
namespace uri = boost::network::uri;


struct HttpHandler;
typedef http::server<HttpHandler> HttpServer;

class HttpHandler {
public:
//     HttpHandler(const char* &hostname, int port);
//     ~HttpHandler();
    
    void operator() (const HttpServer::request & request, HttpServer::response & response);
    
    void log(HttpServer::string_type const & info);
};

#endif
