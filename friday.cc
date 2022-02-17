template <bool>
struct static_check {
};

template <>
struct static_check<false> {
    static_check();
};

int main()
{
    static_check<(__TIMESTAMP__[0]) == 'F'>();
}
