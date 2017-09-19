#ifndef BITTREX_CPP_CONNECTION_H
#define BITTREX_CPP_CONNECTION_H

#include <iostream>
#include <utility>


namespace bittrex {

    enum {
        PUBLIC, MARKET, ACCOUNT
    };

    /* Connection class to Bittrex API */
    class Connection {
    public:
        Connection(std::string key) : key(std::move(key)){};

        std::string execute_request(std::string endpoint, const char *params, int method);

    private:
        const std::string key;

    };
}
#endif //BITTREX_CPP_CONNECTION_H
