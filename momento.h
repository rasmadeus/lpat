#ifndef MOMENTO_H
#define MOMENTO_H

namespace Momento
{
    struct Data
    {
        Data(const std::string& data)
            : data{data}
        {
        }

        std::string data;
    };


    class Momento
    {
    public:
        Momento(const Data& data)
            : data{data}
        {
        }

        const Data& getData() const
        {
            return data;
        }

    private:
        Data data;
    };


    class Ordinator
    {
    public:
        void setData(const Data& data)
        {
            this->data = data;
        }

        void show() const
        {
            std::cout << data.data << std::endl;
        }

        Momento save() const
        {
            return { data };
        }

        void read(const Momento& momento)
        {
            data = momento.getData();
        }

    private:
        Data data{{}};
    };

    void test()
    {
        std::vector<Momento> history;
        Ordinator ordinator;

        ordinator.setData({"first"});
        history.emplace_back(ordinator.save());

        ordinator.setData({"second"});
        history.emplace_back(ordinator.save());

        ordinator.show();

        ordinator.read(*history.begin());
        ordinator.show();
    }
}

#endif // MOMENTO_H
