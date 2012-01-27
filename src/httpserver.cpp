#include "httpserver.hpp"

#include <sstream>
// #include "json_spirit_reader_template.h"
#include "json_spirit_writer_template.h"

void HttpHandler::operator() (const HttpServer::request & request,
                              HttpServer::response & response)
{
    json_spirit::Object o;
    o.push_back(json_spirit::Pair("name", "value"));

    std::ostringstream oss(std::ostringstream::out);
    json_spirit::write_stream(json_spirit::Value(o), oss, 0);
    
    response = HttpServer::response::stock_reply(HttpServer::response::ok, oss.str());
    network::add_header(response, "Content-Type", "application/json");
    
//        std::string uri_string = "http://localhost:8000" + request.destination;
//         uri::http::uri _uri(uri_string);
//         std::string _query = query(_uri);
//         std::string _path = path(_uri);
    std::string s = source(request);
}

void HttpHandler::log(HttpServer::string_type const & info)
{
    std::cerr << "ERROR: " << info << '\n';
}
