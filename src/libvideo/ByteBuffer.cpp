#include "libvideo/ByteBuffer.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <cstring>

using namespace vd;


Buffer::Buffer() 
: data_(NULL)
, length_(0), buffer_size_(0)
{}

Buffer::~Buffer() {
    this->clear();
}

void Buffer::clear() {
    if (this->data_ != NULL) {
        delete[] this->data_;
    }
    this->data_        = NULL;
    this->length_      = 0;
    this->buffer_size_ = 0;
}

void Buffer::allocate(int size) {
    this->clear();

    VIDEO_ALLOC_EXCEPTION(this->data_ = new unsigned char[size]);
    memset(this->data_, 0x00, this->buffer_size_);

    this->buffer_size_ = size;
}

void Buffer::reserve(int size) {
    unsigned char* temp_data = this->data_;
    
    VIDEO_ALLOC_EXCEPTION(this->data_ = new unsigned char[size]);
    memset(this->data_, 0x00, size);
    
    int copy_size = (this->buffer_size_ <= size) ? this->buffer_size_ : size;
    memcpy(this->data_, temp_data, copy_size);
    this->length_      = (this->length_ <= size) ? this->length_ : size;
    this->buffer_size_ = size;

    delete[] temp_data;
}

void Buffer::setData(unsigned char* data, int length) {
    if (this->buffer_size_ >= length) {
        memset(this->data_, 0x00, this->buffer_size_);
    } else {
        this->allocate(length);
    }

    memcpy(this->data_, data, length);
    this->length_ = length;
}

void Buffer::append(unsigned char* data, int length) {
    int total_data_size = this->length_ + length;
    if (this->buffer_size_ >= total_data_size) {
        memcpy(this->data_ + this->length_, (void*)data, length);
        this->length_ += length;
    } else {
        this->reserve(total_data_size);
        this->append(data, length);
    }
}

void Buffer::append(unsigned char data) {
    int total_data_size = this->length_ + 1;
    if (this->buffer_size_ >= total_data_size) {
        this->data_[this->length_] = data;
        this->length_++;
    } else {
        int reserve_size = 0;
        reserve_size = total_data_size + (total_data_size / 2);
        reserve_size = (reserve_size <= 2) ? 10 : reserve_size;

        this->reserve(reserve_size);
        this->append(data);
    }
}

void Buffer::copy(Buffer& buffer) {
    this->clear();
    this->setData(buffer.data_, buffer.length_);
}

ByteBuffer::ByteBuffer() 
: buffer_(new Buffer())
{}

ByteBuffer::ByteBuffer(int buffer_size) 
: buffer_(new Buffer()) {
    this->buffer_->allocate(buffer_size);
}

ByteBuffer::ByteBuffer(ByteBuffer& byte_buffer) 
: buffer_(byte_buffer.buffer_)
{}

ByteBuffer::ByteBuffer(const char* data) {
    this->setData((unsigned char*)data, strlen(data) + 1);
}

ByteBuffer::ByteBuffer(unsigned char* data, int length) {
    this->setData(data, length);
}

ByteBuffer::~ByteBuffer() {
    clear();
}

void ByteBuffer::clear() {
    this->buffer_->clear();
}

bool ByteBuffer::isEmpty() {
    if (this->buffer_->data_ != NULL) {
        return false;
    }
    return true;
}

const unsigned char* ByteBuffer::getData() {
    return this->buffer_->data_;
}

int ByteBuffer::getLength() {
    return this->buffer_->length_;
}

void ByteBuffer::setData(ByteBuffer& byte_buffer) {
    this->setData(byte_buffer.buffer_);
}

void ByteBuffer::append(ByteBuffer& byte_buffer) {
    this->append(byte_buffer.buffer_);
}

void ByteBuffer::append(const char* data) {
    this->append((unsigned char*)data, strlen(data));
}

void ByteBuffer::append(unsigned char* data, int length) {
    this->buffer_->append(data, length);
}

ByteBuffer& ByteBuffer::sub(int start_index, int end_index) {
    int data_size = end_index - start_index;
    
    ByteBuffer buffer(data_size);
    for (int i = start_index; i < end_index; i++) {
        buffer.buffer_->append(this->buffer_->data_[i]);
    }
    return buffer;
}

ByteBuffer& ByteBuffer::clone() {
    ByteBuffer buffer;
    buffer.buffer_->copy(*this->buffer_);
    
    return buffer;
}

unsigned char& ByteBuffer::operator[](int index) {
    return this->buffer_->data_[index];
}

ByteBuffer& ByteBuffer::operator+=(ByteBuffer& buffer) {
    this->append(buffer);

    return *this;
}

void ByteBuffer::operator=(ByteBuffer& buffer) {
    this->setData(buffer);
}

void ByteBuffer::setData(unsigned char* data, int length) {
    this->buffer_->setData(data, length);
}

void ByteBuffer::setData(std::shared_ptr<Buffer> buffer) {
    this->buffer_ = buffer;
}

void  ByteBuffer::append(std::shared_ptr<Buffer> buffer) {
    this->buffer_->append(buffer->data_, buffer_->length_);
}