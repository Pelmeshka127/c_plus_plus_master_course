#include <cassert>
#include <print>

class Entity_v1 {
    public:
        virtual int test() {
            return 1;
        }
};

class Entity_v2 {
    public:
        virtual int test() {
            return 2;
    }
};

class Adapter_v1 : public Entity_v1 {
    public:
        int test() override {
            return test_v1();
        }

    protected:
        virtual int test_v1() = 0;
};

class Adapter_v2 : public Entity_v2 {
    public:
        int test() override {
            return test_v2();
        }

    protected:
        virtual int test_v2() = 0;
};

class Client : public Adapter_v1, public Adapter_v2 {
    protected:
        int test_v1() override {
            return 10;
        }

        int test_v2() override {
            return 20;
        }
};

int main() {
    Entity_v1 entity_v1;
    Entity_v2 entity_v2;
    assert(entity_v1.test() == 1);
    assert(entity_v2.test() == 2);

    Client client;
    Entity_v1& first = client;
    Entity_v2& second = client;

    assert(first.test() == 10);
    assert(second.test() == 20);

    std::print("{} {}\n", first.test(), second.test());
}
