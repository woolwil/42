// unsigned char   reverse_bits(unsigned char octet)
// {
//     int i = 8;
//     unsigned char res = 0;

//     while (i > 0)
//     {
//         res = (res * 2) + (octet % 2);
//         octet = octet / 2;
//         i--;
//     }
//     return res;
// }

unsigned char   reverse_bits(unsigned char octet)
{
    int i = 8;
    unsigned char res = 0;

    while (i-- > 0)
    {
        res = (res << 1) | (octet & 1);
        octet >>= 1;
    }
    return res;
}