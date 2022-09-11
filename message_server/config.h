#ifndef CONFIG_H
#define CONFIG_H


class CONFIG
{
public:
    CONFIG();
    int message_svr_id();
private:
    int svr_id;
};
CONFIG* cfg_singleton();
#endif // CONFIG_H
