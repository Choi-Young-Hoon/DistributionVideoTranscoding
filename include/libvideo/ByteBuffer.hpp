#ifndef __LIB_VIDEO_BYTE_BUFFER_HEADER__
#define __LIB_VIDEO_BYTE_BUFFER_HEADER__

#include <iostream>
#include <vector>
#include <memory>

#include "libvideo/ErrorDefine.hpp"

namespace av {
    
    class Buffer {
    public:
        explicit Buffer();
        virtual ~Buffer();

    public:
        void allocate(int size);
        void reserve (int size);
        void clear();

        void setData(const unsigned char* data, int length);

        void append(const unsigned char* data, int length);
        void append(const unsigned char data); 

        void copy(Buffer& buffer);

    public:
        unsigned char* m_data;
        int            m_length;

        int m_bufferSize;
    };
        


    class ByteBuffer {
    public:
        explicit ByteBuffer();
        explicit ByteBuffer(int bufferSize);
                 ByteBuffer(const ByteBuffer& buffer);
        explicit ByteBuffer(const char* data);
        explicit ByteBuffer(const unsigned char* data, int length);

        virtual ~ByteBuffer();

    public:
        void clear();
        bool isEmpty();

        const unsigned char* getData();
        int                  getLength();

        void setData(const ByteBuffer& buffer);

        void append(const ByteBuffer& buffer);
        void append(const char* data);
        void append(const unsigned char* data, int length);

        ByteBuffer sub(int startIndex, int count);

        ByteBuffer clone();

    public:
        unsigned char& operator[](int index);
        ByteBuffer&    operator+=(const ByteBuffer& buffer);
        ByteBuffer&    operator= (const ByteBuffer& buffer);
        
    private:
        void setData(const unsigned char* data, int length);
        void setData(const std::shared_ptr<Buffer> buffer);

        void append(const std::shared_ptr<Buffer> buffer);
        
    private:
        std::shared_ptr<Buffer> m_buffer;    
    };

};

#endif