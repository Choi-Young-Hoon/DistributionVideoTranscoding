#ifndef __LIB_VIDEO_BYTE_BUFFER_HEADER__
#define __LIB_VIDEO_BYTE_BUFFER_HEADER__

#include <iostream>
#include <vector>
#include <memory>

#include "libvideo/VideoErrorDefine.hpp"

namespace vd {
    
    class Buffer {
    public:
        explicit Buffer();
        virtual ~Buffer();

    public:
        void allocate(int size);
        void reserve (int size);
        void clear();

        void setData(unsigned char* data, int length);

        void append(unsigned char* data, int length);
        void append(unsigned char data); 

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
        explicit ByteBuffer(ByteBuffer& buffer);
        explicit ByteBuffer(const char* data);
        explicit ByteBuffer(unsigned char* data, int length);

        virtual ~ByteBuffer();

    public:
        void clear();
        bool isEmpty();

        const unsigned char* getData();
        int                  getLength();

        void setData(ByteBuffer& buffer);

        void append(ByteBuffer& buffer);
        void append(const char* data);
        void append(unsigned char* data, int length);

        ByteBuffer& sub(int startIndex, int endIndex);

        ByteBuffer& clone();

    public:
        unsigned char& operator[](int index);
        ByteBuffer&    operator+=(ByteBuffer& buffer);
        void           operator= (ByteBuffer& buffer);
        
    private:
        void setData(unsigned char* data, int length);
        void setData(std::shared_ptr<Buffer> buffer);

        void append(std::shared_ptr<Buffer> buffer);
        
    private:
        std::shared_ptr<Buffer> m_buffer;    
    };

};

#endif