#pragma once

#include <global_include.h>

#include "singleton.h"
#include "infoProgress.h"

#define PORTAL_DETECT_URL "http://detectportal.firefox.com/success.txt" // Note : similar portal detector http://www.apple.com/library/test/success.html
#define PORTAL_DETECT_STR "success"
#define VHBB_UA "VHBB/1.00 libhttp/1.1"
#define MAX_QUEUE_CONN 10

typedef enum {
    INTERNET_STATUS_OK,
    INTERNET_STATUS_NO_INTERNET,
    INTERNET_STATUS_HOTSPOT_PAGE,
} InternetStatus;

class Network: public Singleton<Network> {
friend class Singleton<Network>;
public:
    Network();
    ~Network();
	
    int Download(std::string url, std::string dest, InfoProgress progress);
    int Download(std::string url, std::string dest, InfoProgress *progress = nullptr);

    int DownloadSize(std::string url, uint64_t *size, InfoProgress progress);
    int DownloadSize(std::string url, uint64_t *size, InfoProgress *progress = nullptr);

    InternetStatus TestConnection();
private:
    int templateId_;
};

    /*
class NetworkQueue
{
    public:
    NetworkQueue();
    ~NetworkQueue();

    Add(std::string url, std::string dest);
    Add(std::vector<std::pair<std::string, std::string>>);
};
*/