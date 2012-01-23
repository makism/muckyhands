#include "httpserver.hpp"

void HttpHandler::operator() (const HttpServer::request & request,
                              HttpServer::response & response)
{
    response = HttpServer::response::stock_reply(HttpServer::response::ok, body(request));
//         std::string uri_string = "http://localhost:8000" + request.destination;
//         uri::http::uri _uri(uri_string);
//         std::string _query = query(_uri);
//         std::string _path = path(_uri);
        
//         std::cout << request.destination << std::endl;
//         std::cout << uri_string << std::endl;
//         std::cout << _query << std::endl;
//         std::cout << _path << std::endl;
}
    
void HttpHandler::log(HttpServer::string_type const & info)
{
    std::cerr << "ERROR: " << info << '\n';
}
