#ifndef __LIB_VIDEO_RATIONAL_HEADER__
#define __LIB_VIDEO_RATIONAL_HEADER__

namespace av {

    class Rational {
    public:
        explicit Rational();
        explicit Rational(int num, int den);
        virtual ~Rational();

    public:
        int num();
        int den();

        void num(int num);
        void den(int den);
        
    private:
        int m_num;
        int m_den;
    };

};

#endif