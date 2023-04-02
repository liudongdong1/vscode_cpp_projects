#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bzlib.h>

#define BUFFER_SIZE 1024

// 压缩数据
unsigned char* compress(unsigned char* data, int size, int* compressed_size) {
    unsigned char* compressed_data = NULL;
    compressed_data = (unsigned char*) malloc(sizeof(unsigned char) * (size + 1024));
    if (compressed_data == NULL) {
        return NULL;
    }

    bz_stream strm;
    memset(&strm, 0, sizeof(strm));
    int ret = BZ2_bzCompressInit(&strm, 9, 0, 0);
    if (ret != BZ_OK) {
        free(compressed_data);
        return NULL;
    }

    unsigned char in_buf[BUFFER_SIZE];
    unsigned char out_buf[BUFFER_SIZE];
    strm.next_out = out_buf;
    strm.avail_out = BUFFER_SIZE;
    strm.next_in = data;
    strm.avail_in = size;
    do {
        ret = BZ2_bzCompress(&strm, strm.avail_in == 0 ? BZ_FINISH : BZ_RUN);
        if (ret != BZ_OK && ret != BZ_STREAM_END) {
            BZ2_bzCompressEnd(&strm);
            free(compressed_data);
            return NULL;
        }

        if (strm.avail_out < BUFFER_SIZE) {
            int compressed_size = (compressed_size + BUFFER_SIZE - strm.avail_out + 1023) / 1024 * 1024;
            compressed_data = (unsigned char*) realloc(compressed_data, sizeof(unsigned char) * compressed_size);
            if (compressed_data == NULL) {
                BZ2_bzCompressEnd(&strm);
                return NULL;
            }
            memcpy(compressed_data + (size_t)compressed_size, out_buf, BUFFER_SIZE - strm.avail_out);
            compressed_size += BUFFER_SIZE - strm.avail_out;
            strm.next_out = out_buf;
            strm.avail_out = BUFFER_SIZE;
        }
    } while (strm.avail_in > 0);

    BZ2_bzCompressEnd(&strm);
    memcpy(compressed_data + (size_t)compressed_size, out_buf, BUFFER_SIZE - strm.avail_out);
    compressed_size += BUFFER_SIZE - strm.avail_out;
    return compressed_data;
}

// 解压缩数据
unsigned char* decompress(unsigned char* data, int size, int* decompressed_size) {
    unsigned char* decompressed_data = NULL;
    decompressed_data = (unsigned char*) malloc(sizeof(unsigned char) * (size * 4));
    if (decompressed_data == NULL) {
        return NULL;
    }

    bz_stream strm;
    memset(&strm, 0, sizeof(strm));
    int ret = BZ2_bzDecompressInit(&strm, 0, 0);
    if (ret != BZ_OK) {
        free(decompressed_data);
        return NULL;
    }

    unsigned char in_buf[BUFFER_SIZE];
    unsigned char out_buf[BUFFER_SIZE];
    strm.next_out = out_buf;
    strm.avail_out = BUFFER_SIZE;
    strm.next_in = data;
    strm.avail_in = size;
    do {
        ret = BZ2_bzDecompress(&strm);
        if (ret != BZ_OK && ret != BZ_STREAM_END) {
            BZ2_bzDecompressEnd(&strm);
            free(decompressed_data);
            return NULL;
        }

        if (strm.avail_out < BUFFER_SIZE) {
            int decompressed_size = (decompressed_size + BUFFER_SIZE - strm.avail_out + 1023) / 1024 * 1024 * 4;
            decompressed_data = (unsigned char*) realloc(decompressed_data, sizeof(unsigned char) * decompressed_size);
            if (decompressed_data == NULL) {
                BZ2_bzDecompressEnd(&strm);
                return NULL;
            }
            memcpy(decompressed_data + (size_t)decompressed_size, out_buf, BUFFER_SIZE - strm.avail_out);
            decompressed_size += BUFFER_SIZE - strm.avail_out;
            strm.next_out = out_buf;
            strm.avail_out = BUFFER_SIZE;
        }
        //printf("Original ret: %s\n", ret);
    } while (ret != BZ_STREAM_END);

    BZ2_bzDecompressEnd(&strm);
    memcpy(decompressed_data + (size_t)decompressed_size, out_buf, BUFFER_SIZE - strm.avail_out);
    decompressed_size += BUFFER_SIZE - strm.avail_out;
    return decompressed_data;
}

int main() {
    // 原始数据
    unsigned char data[] = "Hello, world! This is a test.";
    int size = strlen((char*) data);
          
    // 压缩数据
    int compressed_size = 0;
    printf("Original data1: %s\n", data);
    unsigned char* compressed_data = compress(data, size, &compressed_size);
    printf("Original data11: %s\n", compressed_data);
    // 解压缩数据
    int decompressed_size = 0;
    unsigned char* decompressed_data = decompress(compressed_data, compressed_size, &decompressed_size);
    printf("Original data111: %s\n", data);
    // 输出结果
    printf("Original data: %s\n", data);
    printf("Compressed data size: %d\n", compressed_size);
    printf("Decompressed data: %s\n", decompressed_data);
    return 0;
}