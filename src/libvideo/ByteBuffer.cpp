#include "libvideo/ByteBuffer.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <cstring>

using namespace vd;


Buffer::Buffer() 
: m_data(NULL)
, m_length(0), m_bufferSize(0)
{}

Buffer::~Buffer() {
    this->clear();
}

void Buffer::clear() {
    if (this->m_data != NULL) {
        delete[] this->m_data;
    }
    this->m_data       = NULL;
    this->m_length     = 0;
    this->m_bufferSize = 0;
}

void Buffer::allocate(int size) {
    this->clear();

    VIDEO_ALLOC_EXCEPTION(this->m_data = new unsigned char[size]);
    memset(this->m_data, 0x00, this->m_bufferSize);

    this->m_bufferSize = size;
}

void Buffer::reserve(int size) {
    unsigned char* tempData = this->m_data;
    
    VIDEO_ALLOC_EXCEPTION(this->m_data = new unsigned char[size]);
    memset(this->m_data, 0x00, size);
    
    int copySize = (this->m_bufferSize <= size) ? this->m_bufferSize : size;
    memcpy(this->m_data, tempData, copySize);
    this->m_length     = (this->m_length <= size) ? this->m_length : size;
    this->m_bufferSize = size;

    delete[] tempData;
}

void Buffer::setData(const unsigned char* data, int length) {
    if (this->m_bufferSize >= length) {
        memset(this->m_data, 0x00, this->m_bufferSize);
    } else {
        this->allocate(length);
    }

    memcpy(this->m_data, data, length);
    this->m_length = length;
}

void Buffer::append(const unsigned char* data, int length) {
    int totalDataSize = this->m_length + length;
    if (this->m_bufferSize >= totalDataSize) {
        memcpy(this->m_data + this->m_length, (void*)data, length);
        this->m_length += length;
    } else {
        this->reserve(totalDataSize);
        this->append(data, length);
    }
}

void Buffer::append(const unsigned char data) {
    int totalDataSize = this->m_length + 1;
    if (this->m_bufferSize >= totalDataSize) {
        this->m_data[this->m_length] = data;
        this->m_length++;
    } else {
        int reserveSize = 0;
        reserveSize = totalDataSize + (totalDataSize / 2);
        reserveSize = (reserveSize <= 2) ? 10 : reserveSize;

        this->reserve(reserveSize);
        this->append(data);
    }
}

void Buffer::copy(Buffer& buffer) {
    this->clear();
    this->setData(buffer.m_data, buffer.m_length);
}

ByteBuffer::ByteBuffer() 
: m_buffer(new Buffer())
{}

ByteBuffer::ByteBuffer(int bufferSize) 
: m_buffer(new Buffer()) {
    this->m_buffer->allocate(bufferSize);
}

ByteBuffer::ByteBuffer(const ByteBuffer& buffer) 
: m_buffer(buffer.m_buffer)
{}

ByteBuffer::ByteBuffer(const char* data) 
: m_buffer(new Buffer()) {
    this->setData((unsigned char*)data, strlen(data) + 1);
}

ByteBuffer::ByteBuffer(const unsigned char* data, int length) 
: m_buffer(new Buffer()) {
    this->setData(data, length);
}

ByteBuffer::~ByteBuffer() 
{}

void ByteBuffer::clear() {
    this->m_buffer->clear();
}

bool ByteBuffer::isEmpty() {
    if (this->m_buffer->m_data != NULL) {
        return false;
    }
    return true;
}

const unsigned char* ByteBuffer::getData() {
    return this->m_buffer->m_data;
}

int ByteBuffer::getLength() {
    return this->m_buffer->m_length;
}

void ByteBuffer::setData(const ByteBuffer& buffer) {
    this->setData(buffer.m_buffer);
}

void ByteBuffer::append(const ByteBuffer& buffer) {
    this->append(buffer.m_buffer);
}

void ByteBuffer::append(const char* data) {
    this->append((unsigned char*)data, strlen(data));
}

void ByteBuffer::append(const unsigned char* data, int length) {
    this->m_buffer->append(data, length);
}

ByteBuffer ByteBuffer::sub(int startIndex, int count) {
    ByteBuffer buffer(count);
    for (int i = startIndex; i < startIndex + count; i++) {
        buffer.m_buffer->append(this->m_buffer->m_data[i]);
    }
    
    return buffer;
}

ByteBuffer ByteBuffer::clone() {
    ByteBuffer buffer;
    buffer.m_buffer->copy(*this->m_buffer);
    
    return buffer;
}

unsigned char& ByteBuffer::operator[](int index) {
    return this->m_buffer->m_data[index];
}

ByteBuffer& ByteBuffer::operator+=(const ByteBuffer& buffer) {
    this->append(buffer);

    return *this;
}

ByteBuffer& ByteBuffer::operator=(const ByteBuffer& buffer) {
    this->setData(buffer);

    return *this;
}

void ByteBuffer::setData(const unsigned char* data, int length) {
    this->m_buffer->setData(data, length);
}

void ByteBuffer::setData(const std::shared_ptr<Buffer> buffer) {
    this->m_buffer = buffer;
}

void  ByteBuffer::append(const std::shared_ptr<Buffer> buffer) {
    this->m_buffer->append(buffer->m_data, buffer->m_length);
}