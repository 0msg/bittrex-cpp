#ifndef BITTREX_CURL_WRAPPER_H
#define BITTREX_CURL_WRAPPER_H

#include <string>
#include <curl/curl.h>
#include <vector>

static size_t write_callback(char *contents, size_t size, size_t nmemb, void *userdata);

namespace curl {
    namespace options {

        /**
         * Base class for libcurl options
         */
        class OptionBase {
        public:
            virtual ~OptionBase() = default;
            virtual void setOpt() = 0;
            CURL *m_curlHandle = nullptr;

        };

        /**
         * Libcurl Http header Option
         */
        class HttpHeader : public OptionBase {
        public:
            HttpHeader(const std::string &header);
            ~HttpHeader();
            void setOpt();

        private:
            struct curl_slist *m_chunk = nullptr;
        };

        /**
         * Libcurl WriteData Option
         */
        class WriteData : public OptionBase {
        public:
            WriteData(std::string &buf) : m_buf(buf) {};
            void setOpt();

        private:
            std::string &m_buf;
        };

        /**
         * Libcurl Url Option
         */
        class Url : public OptionBase {
        public:
            Url(std::string &url) : m_url(url) {};
            void setOpt();

        private:
            std::string &m_url;
        };

    }
}
namespace bittrex {
    namespace lib {
        /**
         * Wrapper class for libcurl
         */
        class Curl {
        public:
            Curl();
            ~Curl();
            void perform();
            void setOpt(curl::options::OptionBase *opt);

        private:
            CURL *m_curl;
            CURLcode m_res;
            std::vector<curl::options::OptionBase*> m_optionList;
        };

    }
}


#endif //BITTREX_CURL_WRAPPER_H
