#include <cassert>

class Entity {
    private:
        friend class Attorney_v1;
        friend class Attorney_v2;

        int test_v1(int value) {
            return value * value;
        }

        bool test_v2(int value) {
            return value % 2 == 0;
        }
};

class Attorney_v1 {
    private:
        friend class Tester_v1;

        static int call(Entity& entity, int value) {
            return entity.test_v1(value);
        }
};

class Attorney_v2 {
    private:
        friend class Tester_v2;

        static bool call(Entity& entity, int value) {
            return entity.test_v2(value);
        }
};

class Tester_v1 {
    public:
        static void run(Entity& entity) {
            assert(Attorney_v1::call(entity, 4) == 16);
            assert(Attorney_v1::call(entity, -3) == 9);
        }
};

class Tester_v2 {
    public:
        static void run(Entity& entity) {
            assert(Attorney_v2::call(entity, 4));
            assert(!Attorney_v2::call(entity, 3));
        }
};

int main() {
    Entity entity;
    Tester_v1::run(entity);
    Tester_v2::run(entity);
}
