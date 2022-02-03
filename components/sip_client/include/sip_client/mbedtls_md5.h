/*
   Copyright Beatific Angel
   
 */

#pragma once

#include "mbedtls/md5.h"

class MbedtlsMd5
{
public:
    MbedtlsMd5()
    {
        mbedtls_md5_init(&m_ctx);
    }

    ~MbedtlsMd5()
    {
        mbedtls_md5_free(&m_ctx);
    }

    MbedtlsMd5(const MbedtlsMd5&) = delete;
    MbedtlsMd5& operator=(const MbedtlsMd5&) = delete;
    MbedtlsMd5(const MbedtlsMd5&&) = delete;
    MbedtlsMd5& operator=(const MbedtlsMd5&&) = delete;

    void start()
    {
        mbedtls_md5_starts_ret(&m_ctx);
    }

    void update(const std::string& input)
    {
        mbedtls_md5_update_ret(&m_ctx, reinterpret_cast<const unsigned char*>(input.c_str()), input.size());
    }

    void finish(unsigned char hash[16])
    {
        mbedtls_md5_finish_ret(&m_ctx, hash);
    }

private:
    mbedtls_md5_context m_ctx {};
};
