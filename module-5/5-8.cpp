// Draw Line: A monochrome screen is stored as a single array of bytes, allowing eight consecutive pixels to be stored in one byte. The screen has width w, where w is divisible by 8 (that is, no byte will be split across rows). The height of the screen, of course, can be derived from the length of the array and the width. Implement a function that draws a horizontal line from (xl, y) to (x2, y).


//source http://sw-engineers.com/wiki/index.php/Cracking_The_Coding_Interview/Q_5.8

#include <iostream>
#include <stdint.h>
using namespace std;

class CMonoFrameBuffer {
public:
        enum { COLOR_BLACK, COLOR_WHITE };
private:
        enum {
                c_width = 64,
                c_height = 32,
                c_x_bytes = (c_width / 8),
                c_frame_buffer_size = c_x_bytes * c_height,
        };
        uint8_t m_buffer[c_frame_buffer_size];
public:
        CMonoFrameBuffer() : m_buffer { 0 } {}

        void printBuffer(void);

        void drawPoint(unsigned x, unsigned y, unsigned color = COLOR_WHITE);
        void drawHorizontalLine(unsigned x1, unsigned x2, unsigned y, unsigned color = COLOR_WHITE);
};

void CMonoFrameBuffer::printBuffer(void)
{
        uint8_t *pBuffer = m_buffer;
        unsigned int x, x_byte, y, num;
        unsigned int bitmask;

        std::cout << "Frame buffer (" << c_width << "x" << c_height << ")\n";
        std::cout << " ";

        for (x = 0, num = 0; x < c_width; ++x) {
                std::cout << num;
                if (++num == 10)
                        num = 0;
        }
        std::cout << std::endl;

        for (y = 0, num = 0; y < c_height; ++y) {
                std::cout << num;
                if (++num == 10)
                        num = 0;

                for (x_byte = 0; x_byte < c_x_bytes; ++x_byte) {
                        for (bitmask = 0x80; bitmask != 0; bitmask >>= 1)
                                std::cout << (*pBuffer & bitmask ? "o" : " ");
                        ++pBuffer;
                }
                std::cout << std::endl;
        }
}

void CMonoFrameBuffer::drawPoint(unsigned x, unsigned y, unsigned color)
{
        unsigned int x_byte = x >> 3;
        unsigned int x_bit = x & 7;
        uint8_t bitmask = 0x80 >> x_bit;
        uint8_t *pBuffer = m_buffer + x_byte + (c_x_bytes * y);

        if (color == COLOR_WHITE)
                *pBuffer |= bitmask;
        else
                *pBuffer &= ~bitmask;
}

void CMonoFrameBuffer::drawHorizontalLine(unsigned x1, unsigned x2, unsigned y, unsigned color)
{
        unsigned int x_byte = x1 >> 3;
        unsigned int x_bit = x1 & 7;
        static int count =0;
        unsigned int x_bits = (x2 > x1) ? (x2 - x1 + 1) : (x1 - x2 + 1);
        uint8_t *pBuffer = m_buffer + x_byte + (c_x_bytes * y);
        cout << "pBuffer = " << count << *pBuffer << endl;
        count++;

        while (x_bits > 0) {
                unsigned int curBits;
                uint8_t bitmask;

                curBits = 8 - x_bit;
                if (curBits > x_bits)
                        curBits = x_bits;

                if (curBits == 8) {
                        bitmask = 0xff;
                } else {
                        unsigned int x_msb, x_lsb;
                        x_msb = 8 - x_bit;
                        x_lsb = x_msb - curBits;
                        bitmask = (1 << curBits) - 1;
                        bitmask <<= x_lsb;
                }

                if (color == COLOR_WHITE)
                        *pBuffer |= bitmask;
                else
                        *pBuffer &= ~bitmask;

                x_bits -= curBits;
                x_bit = 0;
                ++pBuffer;
        }
}

int main(void)
{
        CMonoFrameBuffer fb;
        unsigned int x;

        for (x = 0; x < 32; ++x)
                //fb.drawPoint(x, x);

        fb.drawHorizontalLine(0, 19, 3);
        fb.drawHorizontalLine(20, 21, 6);
        fb.drawHorizontalLine(22, 25, 9);
        fb.drawHorizontalLine(26, 44, 12);
        fb.drawHorizontalLine(45, 63, 15);

        fb.printBuffer();

        return 0;
}
 
 
