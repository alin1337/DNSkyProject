#include <Windows.h>
#include "Crypto.h"
#include "Memory.h"
#include "vlizer.h"
#include <VMProtectSDK.h>

#ifdef RU
//BYTE cheimagice[512] = { 0xfb, 0x11, 0x9f, 0xdc, 0x26, 0x3e, 0x42, 0x2d, 0x8a, 0xa2, 0xa3, 0x28, 0x18, 0xc7, 0x4c, 0x4a, 0xa1, 0xc5, 0xe3, 0x77, 0x29, 0x19, 0x7f, 0xa5, 0xf1, 0x46, 0xe1, 0xba, 0x15, 0x76, 0x34, 0x84, 0x37, 0x66, 0xed, 0x87, 0x92, 0x80, 0x91, 0x3e, 0x4d, 0xe7, 0xb7, 0x6b, 0xb5, 0xe2, 0x76, 0x73, 0x0d, 0x9b, 0x66, 0x8a, 0x15, 0x02, 0x50, 0xa7, 0x61, 0xc3, 0x95, 0x54, 0xcb, 0xf0, 0x01, 0x3e, 0xe7, 0xec, 0x83, 0xdf, 0x80, 0x23, 0x5c, 0x89, 0x4a, 0x87, 0x73, 0xdf, 0x87, 0xf2, 0x52, 0x5c, 0x78, 0x16, 0xf4, 0x82, 0xf3, 0xee, 0x60, 0x18, 0xe9, 0x95, 0x50, 0x12, 0x99, 0x1e, 0x2d, 0x50, 0x9e, 0xab, 0xbe, 0xe8, 0xb2, 0x97, 0x98, 0xf8, 0x37, 0xbd, 0x82, 0x27, 0xbb, 0xf5, 0x90, 0xc0, 0x1e, 0x5c, 0xd5, 0x07, 0xd7, 0xd5, 0x57, 0x4f, 0x42, 0x8a, 0xf5, 0xd5, 0xf9, 0xca, 0x2b, 0x6a, 0xf4, 0x5e, 0x2c, 0x35, 0xa7, 0xfb, 0x3a, 0xd3, 0x85, 0x4a, 0x57, 0x6c, 0x07, 0x38, 0xbc, 0x6c, 0xf5, 0xc7, 0x8b, 0x46, 0x8b, 0x20, 0x5a, 0x59, 0xd1, 0x40, 0xb1, 0xaa, 0xdc, 0x8a, 0x3c, 0x56, 0x91, 0xaa, 0x0a, 0x2e, 0xa0, 0xaf, 0x1a, 0x4d, 0x5b, 0xbd, 0xa0, 0x16, 0x63, 0x0a, 0x1c, 0xc7, 0x3a, 0xad, 0x27, 0x3a, 0x7a, 0xf5, 0xee, 0x39, 0xbf, 0x80, 0xc8, 0x52, 0x80, 0x80, 0x34, 0x60, 0xe6, 0xb0, 0xab, 0x83, 0x21, 0xdc, 0x8c, 0xd5, 0x43, 0x49, 0x79, 0xae, 0x5a, 0x1a, 0x4d, 0x11, 0xec, 0xf0, 0x5b, 0x7e, 0xa0, 0x52, 0x19, 0x91, 0x9f, 0x22, 0xca, 0x61, 0x9d, 0x16, 0x86, 0x91, 0x82, 0xbc, 0xa2, 0xc7, 0xfb, 0x36, 0x26, 0xc6, 0xb1, 0xb2, 0x25, 0xef, 0x74, 0xff, 0x61, 0x71, 0x61, 0x99, 0x72, 0x42, 0xc1, 0x9a, 0x29, 0x3c, 0xa4, 0x0d, 0x26, 0xcf, 0xf4, 0x5a, 0x8a, 0xec, 0x69, 0xba, 0xe9, 0x46, 0xe3, 0xc4, 0xb9, 0xc1, 0x06, 0x81, 0x74, 0xe5, 0x17, 0x2f, 0xc6, 0x34, 0x82, 0x08, 0x39, 0x27, 0x6c, 0x21, 0xd4, 0x5d, 0x08, 0xbe, 0x61, 0x7c, 0x75, 0x0b, 0x46, 0xad, 0x96, 0x65, 0xd3, 0x0f, 0x63, 0x50, 0xb1, 0xad, 0xbb, 0x94, 0xcc, 0xdd, 0xab, 0x0e, 0xf6, 0x46, 0x86, 0xde, 0x8a, 0x13, 0x24, 0x19, 0x26, 0x6f, 0xfc, 0x30, 0xe9, 0x8c, 0xad, 0x1b, 0x0e, 0x88, 0x23, 0x7b, 0x8a, 0x12, 0xa4, 0xeb, 0xd8, 0xc3, 0x18, 0x15, 0x5e, 0xcf, 0x37, 0x55, 0x0e, 0x83, 0xbe, 0x11, 0x59, 0x98, 0x48, 0x7e, 0xa2, 0x20, 0x08, 0x15, 0xd1, 0x12, 0x8e, 0x2d, 0xa9, 0x8a, 0x01, 0x33, 0x53, 0x13, 0x65, 0x70, 0x80, 0xb5, 0x1d, 0x10, 0x3c, 0x6c, 0x9b, 0x41, 0x36, 0x13, 0x03, 0x4c, 0xaf, 0x6a, 0x6b, 0xb8, 0x14, 0xff, 0x03, 0xf0, 0x5e, 0x0c, 0x1f, 0x8a, 0xf7, 0xd7, 0x2a, 0x87, 0xdc, 0xf7, 0xa9, 0x4b, 0xd4, 0x62, 0x81, 0x43, 0x6e, 0x3c, 0xa2, 0x07, 0x97, 0x5f, 0x8b, 0xbc, 0x8f, 0x0a, 0xaf, 0xf2, 0x80, 0x5f, 0x51, 0x20, 0xaf, 0x48, 0xa9, 0x84, 0x52, 0xfa, 0x46, 0xe9, 0x2f, 0xf3, 0x57, 0xd9, 0xb4, 0x31, 0xbd, 0x52, 0xfb, 0x0c, 0x66, 0xef, 0xc7, 0x98, 0x78, 0x2d, 0xc6, 0x8c, 0x0e, 0xea, 0x3a, 0x9e, 0x76, 0x23, 0x5a, 0x34, 0xd2, 0xd2, 0x08, 0xce, 0x1c, 0x30, 0x62, 0x49, 0x80, 0x66, 0xaa, 0x1d, 0x86, 0xf0, 0xe0, 0xc2, 0xec, 0x06, 0xe4, 0xd4, 0x01, 0x64, 0xee, 0xc8, 0xc2, 0x6c, 0x7e, 0xab, 0x4c, 0xc9, 0xb8, 0xd7, 0xfb, 0xcd, 0x2a, 0xb1, 0x1a, 0xbb, 0xee, 0xe1, 0x06, 0x5e, 0xd3, 0x01, 0x5f, 0x2b, 0x9f, 0xaf, 0xed, 0xea, 0x9f, 0xe4, 0x9c, 0x73, 0xb2, 0x60, 0x55, 0xe7, 0xd2, 0x8d, 0x50, 0xb4, 0xbf, 0x05, 0x63, 0x3e, 0xd2, 0x4b };
BYTE cheimagice[512] = { 0x88, 0x91, 0xc3, 0xf4, 0x4c, 0xa2, 0x61, 0xe1, 0xc2, 0x8f, 0xf9, 0x3c, 0x04, 0xd6, 0x80, 0x27, 0xda, 0x8f, 0x8f, 0x1d, 0x44, 0x23, 0x30, 0xad, 0x7b, 0x15, 0x5a, 0xd9, 0x1e, 0x9d, 0x40, 0xf1, 0x4f, 0x78, 0x9e, 0x88, 0xea, 0x47, 0x83, 0xb1, 0xc0, 0x13, 0xac, 0x1e, 0x54, 0x78, 0xc9, 0x37, 0x27, 0x57, 0x41, 0x61, 0x91, 0xfe, 0xdf, 0x17, 0x04, 0xc9, 0xbf, 0xe4, 0x72, 0x05, 0x75, 0x40, 0x28, 0xa3, 0x8a, 0x8f, 0x55, 0xa6, 0xba, 0xbc, 0xf5, 0x94, 0xa7, 0x7b, 0xbc, 0x1a, 0xb9, 0x92, 0xb6, 0xee, 0x8e, 0x46, 0x81, 0x49, 0xa9, 0xab, 0xe4, 0x2f, 0x1d, 0x85, 0xa6, 0xd0, 0x62, 0xa6, 0x8a, 0x54, 0x9a, 0xfb, 0xff, 0xb1, 0xdf, 0x74, 0xee, 0xd4, 0xb3, 0x0a, 0xac, 0x95, 0x1b, 0x54, 0xfd, 0xb5, 0xaa, 0xd6, 0xf7, 0xe0, 0xc6, 0xda, 0x66, 0x35, 0x7e, 0xa7, 0xdb, 0xde, 0xa3, 0x95, 0x79, 0x73, 0xbd, 0xb2, 0x99, 0xa9, 0x26, 0xf4, 0xd1, 0xeb, 0xe6, 0x01, 0x78, 0x6f, 0x35, 0x6b, 0x67, 0x70, 0x12, 0x8e, 0xa2, 0x60, 0xfc, 0x16, 0xb5, 0xc6, 0xcd, 0x91, 0xda, 0xcd, 0x35, 0x58, 0xbc, 0xd5, 0xd3, 0xbc, 0x33, 0x04, 0x9c, 0x85, 0x04, 0xac, 0x57, 0xda, 0x5e, 0xdc, 0x53, 0xb1, 0x8e, 0xbd, 0x3f, 0x97, 0x79, 0xb9, 0x06, 0x57, 0x3e, 0x05, 0xdc, 0xd3, 0x9a, 0x90, 0x4e, 0x7b, 0xba, 0xc7, 0x89, 0xc0, 0xca, 0x5d, 0x62, 0xc5, 0xf9, 0xec, 0xbf, 0x43, 0xed, 0xcb, 0xa5, 0x51, 0x5a, 0xcd, 0x87, 0x1b, 0xed, 0xd6, 0xa9, 0x1f, 0x7b, 0xaf, 0xff, 0xa4, 0xbc, 0x47, 0xa2, 0x11, 0xe9, 0x9b, 0x10, 0xca, 0x15, 0x60, 0x53, 0x18, 0x69, 0xcc, 0x2a, 0xf0, 0x24, 0x36, 0xfd, 0x9f, 0x09, 0x8f, 0x35, 0xbf, 0x92, 0xb6, 0xa5, 0x24, 0x4d, 0x6b, 0xf4, 0x4f, 0xa8, 0x6e, 0xd7, 0xed, 0x11, 0x8c, 0x01, 0x6f, 0x65, 0xb3, 0xcc, 0x27, 0x26, 0xd1, 0xf3, 0xbc, 0xd1, 0x40, 0xac, 0xaf, 0xc8, 0x95, 0x30, 0xbc, 0x0b, 0x6c, 0x55, 0xd5, 0xb1, 0xcd, 0x57, 0x09, 0x0e, 0x99, 0xff, 0x5a, 0xce, 0x2a, 0x12, 0x94, 0xf4, 0x17, 0xb5, 0x77, 0x69, 0x5e, 0x08, 0x99, 0xb6, 0x94, 0xc1, 0x9f, 0x37, 0xe4, 0xef, 0x1b, 0x85, 0x5c, 0x73, 0xca, 0x36, 0x2a, 0xcb, 0x61, 0xfe, 0xbe, 0xfd, 0xad, 0x95, 0xdc, 0x9d, 0xfb, 0x0b, 0x0a, 0x7b, 0xa6, 0x37, 0x8d, 0x18, 0x38, 0x76, 0x3a, 0x57, 0x77, 0xde, 0xf7, 0x7b, 0x74, 0xc6, 0xdd, 0x22, 0xa8, 0xa1, 0xd3, 0x65, 0x36, 0x56, 0xd7, 0xac, 0x1e, 0x56, 0x26, 0x46, 0xce, 0xcd, 0x32, 0x7c, 0x2a, 0xa2, 0xaf, 0x73, 0xb6, 0x0a, 0x8c, 0x78, 0x86, 0x6c, 0x47, 0x16, 0x8e, 0x54, 0x9e, 0x41, 0x22, 0xdb, 0x96, 0x97, 0x7d, 0xef, 0x0d, 0x6c, 0xa6, 0x85, 0x7e, 0xef, 0xf4, 0xfc, 0xd4, 0x3b, 0x14, 0x29, 0x57, 0x8c, 0x48, 0x00, 0x65, 0x34, 0x75, 0x24, 0x44, 0xd0, 0x7b, 0x3a, 0x81, 0xf2, 0x1a, 0xd8, 0xf7, 0x37, 0xfc, 0x2f, 0xe7, 0xf5, 0x29, 0x20, 0xd7, 0x38, 0x70, 0xce, 0x3f, 0x56, 0xde, 0x8c, 0xd9, 0x70, 0xec, 0xb6, 0x8d, 0xcf, 0xc2, 0x68, 0xef, 0xed, 0x08, 0x9b, 0x24, 0x3f, 0x7b, 0xce, 0xfc, 0xff, 0x37, 0xfd, 0x7c, 0xfd, 0x09, 0xdb, 0x61, 0x7e, 0x8b, 0xb6, 0xe9, 0xb1, 0xdb, 0x36, 0x57, 0x87, 0x5c, 0x78, 0xb7, 0xe7, 0x4a, 0x6b, 0x4e, 0xc5, 0xeb, 0x10, 0xba, 0x7d, 0x75, 0x63, 0x1d, 0x0a, 0x31, 0x10, 0xf1, 0xdc, 0x1d, 0xff, 0x09, 0x69, 0xcb, 0x1a, 0x85, 0xa0, 0xcf, 0xcd, 0xef, 0xf2, 0x59, 0x25, 0x4e, 0xfd, 0x06, 0xff, 0x7c, 0x3a, 0xe9, 0x9a, 0x94, 0x84, 0x5d, 0xaf, 0x03, 0x7b, 0x8d, 0x5a, 0x7f, 0xc3, 0x12 };
#endif

#ifdef RO
BYTE cheimagice[512] = { 0x33, 0x04, 0xea, 0xce, 0x16, 0x53, 0xa1, 0xe3, 0x68, 0xb4, 0x86, 0xff, 0x31, 0x13, 0x5e, 0x4c, 0x44, 0xe5, 0x7e, 0x20, 0xd7, 0xb7, 0xb3, 0x4a, 0xb7, 0x21, 0x87, 0x0f, 0x24, 0xac, 0x7f, 0x96, 0x13, 0x19, 0x31, 0x7c, 0x83, 0xc2, 0x42, 0x5b, 0xc0, 0x7b, 0x78, 0x5d, 0x0e, 0x6e, 0xc2, 0x12, 0x5c, 0x3f, 0xfb, 0x23, 0x56, 0x09, 0x8e, 0xd6, 0xd4, 0xbf, 0x69, 0xa5, 0x4c, 0x87, 0x0d, 0x72, 0xf0, 0x27, 0x42, 0x77, 0x75, 0xf8, 0x79, 0xb1, 0x86, 0x30, 0x48, 0xed, 0x7b, 0xf7, 0x83, 0xf0, 0x23, 0x67, 0x55, 0xcc, 0xe7, 0x02, 0xde, 0xc9, 0x98, 0x57, 0xd1, 0xc6, 0x47, 0xb9, 0x4c, 0xec, 0x18, 0x4a, 0x0b, 0x69, 0xc4, 0x30, 0xea, 0xef, 0x18, 0xc7, 0x39, 0x27, 0x67, 0x5f, 0x81, 0x34, 0xa4, 0x78, 0xce, 0x94, 0x4e, 0xb7, 0xd8, 0x1d, 0x57, 0xbc, 0xa7, 0x37, 0x9c, 0x18, 0xa8, 0x0b, 0x9e, 0x96, 0xdf, 0x15, 0x91, 0xd3, 0xa9, 0xeb, 0x5f, 0x28, 0x67, 0xda, 0x14, 0x93, 0xc3, 0xb6, 0xd3, 0xdf, 0x73, 0x47, 0xd2, 0xb0, 0xe3, 0xd3, 0xa8, 0x67, 0x33, 0xb8, 0x74, 0xde, 0x4b, 0xac, 0x15, 0xfe, 0x6b, 0x2d, 0x05, 0x8e, 0xd6, 0x98, 0xac, 0x87, 0xf6, 0xe1, 0x12, 0x5e, 0x12, 0x38, 0x3f, 0x94, 0xa9, 0x41, 0x8c, 0x8e, 0x55, 0x4d, 0x3e, 0x1f, 0xfd, 0x2e, 0x56, 0xb0, 0x7d, 0xc3, 0x91, 0xc3, 0xca, 0x0b, 0x6b, 0xb6, 0xf3, 0x99, 0xa1, 0xdc, 0xc1, 0xb0, 0x91, 0x6e, 0xbf, 0xc7, 0x69, 0x59, 0xc0, 0x86, 0xde, 0x5e, 0xe5, 0xd1, 0xdd, 0xe1, 0x9b, 0xdc, 0x49, 0x68, 0xcc, 0x20, 0xb1, 0x2b, 0x6a, 0xb9, 0xb3, 0x57, 0xc3, 0xa1, 0x90, 0x5e, 0x17, 0xc5, 0x1a, 0x84, 0x87, 0xf5, 0xda, 0xbf, 0xf0, 0x67, 0xe8, 0x7b, 0xa9, 0x2d, 0x91, 0x5f, 0xfd, 0x11, 0xa9, 0x57, 0xf3, 0xb6, 0xa4, 0x65, 0xf6, 0xed, 0x82, 0x26, 0x67, 0x42, 0x4f, 0x14, 0x57, 0xb5, 0xc4, 0xf8, 0x2f, 0x09, 0x22, 0x46, 0x4a, 0x6f, 0x52, 0x3f, 0x41, 0xe9, 0xd9, 0x9a, 0x79, 0x62, 0x99, 0xe8, 0x7c, 0x8e, 0x7a, 0x4b, 0x88, 0x7c, 0xb3, 0x83, 0x39, 0x99, 0x5d, 0x37, 0xdc, 0xbe, 0xbe, 0x3f, 0xd8, 0xb0, 0x51, 0xde, 0x3f, 0x6e, 0xfb, 0x68, 0xf7, 0x2d, 0x6c, 0x97, 0xf1, 0x73, 0xf7, 0x70, 0xb0, 0x62, 0xba, 0x76, 0xae, 0xe2, 0x16, 0x9f, 0x17, 0x45, 0x96, 0x34, 0xd2, 0xe3, 0x3a, 0x7e, 0xd1, 0x18, 0xf4, 0x66, 0x8c, 0xb3, 0xbf, 0x6f, 0xa2, 0xa8, 0x5c, 0xd5, 0x8a, 0x71, 0x78, 0xdf, 0x63, 0xd9, 0xde, 0x1c, 0xc3, 0xd1, 0x2a, 0xab, 0xbb, 0xfa, 0xd0, 0xb5, 0x78, 0x80, 0x37, 0x44, 0x79, 0x45, 0x30, 0x13, 0x41, 0x1e, 0x03, 0x19, 0x28, 0x3b, 0xfb, 0x59, 0xcd, 0x91, 0x11, 0x38, 0x73, 0x2d, 0x16, 0xee, 0xed, 0x79, 0x25, 0x2b, 0x21, 0xc6, 0x09, 0x2d, 0xdc, 0xdd, 0xc6, 0xbf, 0x23, 0x72, 0x4d, 0x3d, 0x78, 0x43, 0x06, 0xb8, 0x9c, 0x6c, 0x76, 0x46, 0x0f, 0x56, 0x20, 0x74, 0x7d, 0xe4, 0x45, 0x07, 0xd8, 0x70, 0xa7, 0xe4, 0x5c, 0xef, 0xfa, 0x59, 0x8a, 0x43, 0x1d, 0xcb, 0xde, 0xcc, 0xa7, 0x40, 0x7a, 0x08, 0x2f, 0xca, 0x3c, 0xac, 0x3b, 0xa7, 0xfd, 0x05, 0x63, 0xc1, 0xf0, 0xc3, 0xb4, 0xf7, 0xd0, 0x2b, 0xf8, 0xed, 0xe7, 0x7f, 0xdd, 0x92, 0x30, 0x7b, 0x6e, 0x1c, 0x06, 0x48, 0x0c, 0x6c, 0xbf, 0x5e, 0x1c, 0xbf, 0xe3, 0xc7, 0x76, 0x9d, 0x8e, 0xca, 0xbf, 0xf1, 0xb3, 0xea, 0xf9, 0x27, 0xc1, 0x6f, 0x5e, 0x15, 0x35, 0x59, 0x91, 0x8f, 0x4f, 0x32, 0x5c, 0x5a, 0xde, 0x45, 0x19, 0x5d, 0x15, 0x9d, 0x45, 0xb8, 0x3e, 0x85, 0x7f, 0xfe, 0x81, 0x4d, 0x27, 0x93, 0x5e, 0xc5 };
#endif

#ifdef AR
BYTE cheimagice[512] = { 0xfb, 0x11, 0x9f, 0xdc, 0x26, 0x3e, 0x42, 0x2d, 0x8a, 0xa2, 0xa3, 0x28, 0x18, 0xc7, 0x4c, 0x4a, 0xa1, 0xc5, 0xe3, 0x77, 0x29, 0x19, 0x7f, 0xa5, 0xf1, 0x46, 0xe1, 0xba, 0x15, 0x76, 0x34, 0x84, 0x37, 0x66, 0xed, 0x87, 0x92, 0x80, 0x91, 0x3e, 0x4d, 0xe7, 0xb7, 0x6b, 0xb5, 0xe2, 0x76, 0x73, 0x0d, 0x9b, 0x66, 0x8a, 0x15, 0x02, 0x50, 0xa7, 0x61, 0xc3, 0x95, 0x54, 0xcb, 0xf0, 0x01, 0x3e, 0xe7, 0xec, 0x83, 0xdf, 0x80, 0x23, 0x5c, 0x89, 0x4a, 0x87, 0x73, 0xdf, 0x87, 0xf2, 0x52, 0x5c, 0x78, 0x16, 0xf4, 0x82, 0xf3, 0xee, 0x60, 0x18, 0xe9, 0x95, 0x50, 0x12, 0x99, 0x1e, 0x2d, 0x50, 0x9e, 0xab, 0xbe, 0xe8, 0xb2, 0x97, 0x98, 0xf8, 0x37, 0xbd, 0x82, 0x27, 0xbb, 0xf5, 0x90, 0xc0, 0x1e, 0x5c, 0xd5, 0x07, 0xd7, 0xd5, 0x57, 0x4f, 0x42, 0x8a, 0xf5, 0xd5, 0xf9, 0xca, 0x2b, 0x6a, 0xf4, 0x5e, 0x2c, 0x35, 0xa7, 0xfb, 0x3a, 0xd3, 0x85, 0x4a, 0x57, 0x6c, 0x07, 0x38, 0xbc, 0x6c, 0xf5, 0xc7, 0x8b, 0x46, 0x8b, 0x20, 0x5a, 0x59, 0xd1, 0x40, 0xb1, 0xaa, 0xdc, 0x8a, 0x3c, 0x56, 0x91, 0xaa, 0x0a, 0x2e, 0xa0, 0xaf, 0x1a, 0x4d, 0x5b, 0xbd, 0xa0, 0x16, 0x63, 0x0a, 0x1c, 0xc7, 0x3a, 0xad, 0x27, 0x3a, 0x7a, 0xf5, 0xee, 0x39, 0xbf, 0x80, 0xc8, 0x52, 0x80, 0x80, 0x34, 0x60, 0xe6, 0xb0, 0xab, 0x83, 0x21, 0xdc, 0x8c, 0xd5, 0x43, 0x49, 0x79, 0xae, 0x5a, 0x1a, 0x4d, 0x11, 0xec, 0xf0, 0x5b, 0x7e, 0xa0, 0x52, 0x19, 0x91, 0x9f, 0x22, 0xca, 0x61, 0x9d, 0x16, 0x86, 0x91, 0x82, 0xbc, 0xa2, 0xc7, 0xfb, 0x36, 0x26, 0xc6, 0xb1, 0xb2, 0x25, 0xef, 0x74, 0xff, 0x61, 0x71, 0x61, 0x99, 0x72, 0x42, 0xc1, 0x9a, 0x29, 0x3c, 0xa4, 0x0d, 0x26, 0xcf, 0xf4, 0x5a, 0x8a, 0xec, 0x69, 0xba, 0xe9, 0x46, 0xe3, 0xc4, 0xb9, 0xc1, 0x06, 0x81, 0x74, 0xe5, 0x17, 0x2f, 0xc6, 0x34, 0x82, 0x08, 0x39, 0x27, 0x6c, 0x21, 0xd4, 0x5d, 0x08, 0xbe, 0x61, 0x7c, 0x75, 0x0b, 0x46, 0xad, 0x96, 0x65, 0xd3, 0x0f, 0x63, 0x50, 0xb1, 0xad, 0xbb, 0x94, 0xcc, 0xdd, 0xab, 0x0e, 0xf6, 0x46, 0x86, 0xde, 0x8a, 0x13, 0x24, 0x19, 0x26, 0x6f, 0xfc, 0x30, 0xe9, 0x8c, 0xad, 0x1b, 0x0e, 0x88, 0x23, 0x7b, 0x8a, 0x12, 0xa4, 0xeb, 0xd8, 0xc3, 0x18, 0x15, 0x5e, 0xcf, 0x37, 0x55, 0x0e, 0x83, 0xbe, 0x11, 0x59, 0x98, 0x48, 0x7e, 0xa2, 0x20, 0x08, 0x15, 0xd1, 0x12, 0x8e, 0x2d, 0xa9, 0x8a, 0x01, 0x33, 0x53, 0x13, 0x65, 0x70, 0x80, 0xb5, 0x1d, 0x10, 0x3c, 0x6c, 0x9b, 0x41, 0x36, 0x13, 0x03, 0x4c, 0xaf, 0x6a, 0x6b, 0xb8, 0x14, 0xff, 0x03, 0xf0, 0x5e, 0x0c, 0x1f, 0x8a, 0xf7, 0xd7, 0x2a, 0x87, 0xdc, 0xf7, 0xa9, 0x4b, 0xd4, 0x62, 0x81, 0x43, 0x6e, 0x3c, 0xa2, 0x07, 0x97, 0x5f, 0x8b, 0xbc, 0x8f, 0x0a, 0xaf, 0xf2, 0x80, 0x5f, 0x51, 0x20, 0xaf, 0x48, 0xa9, 0x84, 0x52, 0xfa, 0x46, 0xe9, 0x2f, 0xf3, 0x57, 0xd9, 0xb4, 0x31, 0xbd, 0x52, 0xfb, 0x0c, 0x66, 0xef, 0xc7, 0x98, 0x78, 0x2d, 0xc6, 0x8c, 0x0e, 0xea, 0x3a, 0x9e, 0x76, 0x23, 0x5a, 0x34, 0xd2, 0xd2, 0x08, 0xce, 0x1c, 0x30, 0x62, 0x49, 0x80, 0x66, 0xaa, 0x1d, 0x86, 0xf0, 0xe0, 0xc2, 0xec, 0x06, 0xe4, 0xd4, 0x01, 0x64, 0xee, 0xc8, 0xc2, 0x6c, 0x7e, 0xab, 0x4c, 0xc9, 0xb8, 0xd7, 0xfb, 0xcd, 0x2a, 0xb1, 0x1a, 0xbb, 0xee, 0xe1, 0x06, 0x5e, 0xd3, 0x01, 0x5f, 0x2b, 0x9f, 0xaf, 0xed, 0xea, 0x9f, 0xe4, 0x9c, 0x73, 0xb2, 0x60, 0x55, 0xe7, 0xd2, 0x8d, 0x50, 0xb4, 0xbf, 0x05, 0x63, 0x3e, 0xd2, 0x4b };
#endif

#ifdef VTM
BYTE cheimagice[512] = { 0x52, 0x8b, 0x5f, 0xcd, 0x63, 0x55, 0xa8, 0x8c, 0xf3, 0x78, 0x26, 0xf4, 0xcb, 0x39, 0x46, 0xa7, 0x8f, 0x84, 0x1c, 0xb0, 0x00, 0x60, 0xe5, 0x70, 0xc5, 0xd4, 0x72, 0x08, 0x69, 0xe7, 0x44, 0x14, 0xd2, 0x95, 0x48, 0x00, 0x7f, 0xfa, 0x8e, 0xad, 0x5f, 0xf2, 0x32, 0x94, 0x18, 0x96, 0xed, 0xe1, 0xea, 0x1d, 0x19, 0xce, 0x5c, 0x24, 0x4f, 0xc3, 0x12, 0x40, 0xed, 0xae, 0x76, 0x13, 0x9d, 0xee, 0xbf, 0xe8, 0x19, 0xc8, 0xb6, 0xb3, 0xeb, 0x1c, 0x57, 0x01, 0x74, 0x64, 0x1c, 0x48, 0xd5, 0xf1, 0x4f, 0x9d, 0xee, 0x7f, 0x19, 0x16, 0x1d, 0x3e, 0xab, 0xb9, 0xb0, 0x6d, 0x0b, 0xe6, 0x44, 0xb2, 0x3d, 0xba, 0xe0, 0xc3, 0xba, 0xe8, 0x2b, 0x59, 0xc7, 0xa7, 0x3d, 0xd1, 0x6e, 0x2d, 0x48, 0x67, 0x80, 0x58, 0x7c, 0xe0, 0x9d, 0x38, 0xf0, 0x83, 0x28, 0x42, 0x47, 0x1a, 0x92, 0x69, 0x29, 0x95, 0x40, 0x62, 0xcd, 0xc2, 0x34, 0x99, 0x17, 0xc2, 0x8f, 0x00, 0x61, 0x5e, 0x79, 0x21, 0x51, 0x38, 0x93, 0x67, 0xf4, 0xb1, 0x8d, 0xf0, 0x03, 0x63, 0x55, 0x9f, 0xe6, 0x89, 0x95, 0xdc, 0x05, 0x6b, 0x3b, 0xb7, 0x60, 0xd0, 0xed, 0x09, 0x5c, 0x03, 0x5d, 0x35, 0x50, 0x3e, 0x05, 0xdd, 0x49, 0xea, 0x24, 0xc4, 0xa3, 0x9e, 0x2a, 0x9a, 0xf1, 0x2e, 0x5a, 0xec, 0x9b, 0x5f, 0x66, 0x30, 0xee, 0xa7, 0x3d, 0xe0, 0xef, 0x51, 0x15, 0x26, 0x4d, 0x4a, 0x92, 0xf5, 0xd7, 0x20, 0x1d, 0xca, 0xac, 0xa1, 0x0e, 0xf3, 0x0c, 0x4d, 0x53, 0x39, 0x20, 0x55, 0xe4, 0x27, 0x89, 0x8f, 0x0a, 0xc5, 0x6f, 0x18, 0xb9, 0x57, 0xf7, 0x28, 0x93, 0x8b, 0xee, 0x11, 0x83, 0x52, 0xfa, 0x72, 0x87, 0xce, 0xab, 0x7c, 0x75, 0x82, 0x9c, 0xb3, 0xb0, 0x95, 0x6f, 0x83, 0x38, 0xab, 0xde, 0xab, 0xe2, 0xfd, 0x8e, 0x6e, 0x7b, 0x8e, 0xf9, 0xa5, 0x05, 0xb8, 0x00, 0x42, 0x08, 0xd3, 0x53, 0x5b, 0xb6, 0xf9, 0x64, 0x68, 0x0e, 0x71, 0x62, 0x70, 0x53, 0x2c, 0xb0, 0x1d, 0xca, 0x6c, 0x40, 0xa5, 0xf3, 0x58, 0x56, 0x22, 0x4b, 0xa8, 0x97, 0x27, 0xd2, 0x58, 0x1c, 0x5a, 0x09, 0x9c, 0xe5, 0xea, 0x0a, 0xf4, 0xdb, 0x5a, 0xef, 0x4a, 0xbe, 0x68, 0x70, 0xd0, 0xc5, 0x70, 0x69, 0xb5, 0xac, 0x90, 0xac, 0xe6, 0x5b, 0xb2, 0x4f, 0x74, 0x8f, 0x8c, 0x70, 0x98, 0x7c, 0xfc, 0x9d, 0x23, 0x4b, 0xca, 0x59, 0xcf, 0x0f, 0x9c, 0x47, 0xe9, 0xd2, 0x2b, 0x87, 0x19, 0x3a, 0xf1, 0x99, 0xe8, 0xe1, 0x51, 0xad, 0xcd, 0x87, 0x7a, 0x24, 0x37, 0xd0, 0xf3, 0x89, 0x84, 0xaf, 0xcc, 0x52, 0x57, 0x83, 0x41, 0xda, 0xc0, 0xf8, 0xd3, 0x78, 0xf5, 0xce, 0x07, 0x13, 0xf3, 0x6c, 0x72, 0x6f, 0x41, 0x71, 0x74, 0xb1, 0xc9, 0x19, 0x3a, 0x92, 0xe1, 0xae, 0x56, 0x63, 0xf0, 0x5d, 0xcd, 0xb2, 0x2e, 0x80, 0x3e, 0x17, 0x3d, 0x4e, 0x45, 0x95, 0xfe, 0x57, 0x1e, 0xb3, 0xfc, 0x93, 0xa1, 0xa8, 0x43, 0x04, 0x18, 0xbb, 0xc2, 0x81, 0xa8, 0xf4, 0x00, 0xec, 0x07, 0xcf, 0x04, 0xd1, 0x0f, 0x6e, 0x17, 0x5a, 0x7c, 0x92, 0xf2, 0x6c, 0xc6, 0xd6, 0xf3, 0x1c, 0xd5, 0x0b, 0x07, 0x2d, 0x11, 0xbb, 0xf8, 0xb7, 0x56, 0xe5, 0xd8, 0x70, 0x1a, 0x6a, 0xa6, 0xc7, 0x57, 0x1d, 0xa8, 0xad, 0xfc, 0x3f, 0x75, 0xdb, 0x57, 0xb3, 0x15, 0x80, 0xeb, 0x7d, 0x96, 0xfc, 0x46, 0x29, 0x8e, 0x2e, 0xbf, 0x72, 0xfb, 0xcc, 0xc1, 0x68, 0x15, 0xab, 0x31, 0x84, 0x7a, 0xef, 0xf8, 0x67, 0x7f, 0x59, 0x1b, 0x5f, 0x65, 0xd0, 0xe2, 0x78, 0x75, 0x76, 0x2c, 0xf3, 0xdd, 0xc1, 0xac, 0x00, 0xc6, 0x2f, 0x2e, 0x88, 0xba, 0x88, 0xc6, 0x33, 0xe4, 0xc3, 0xf1 };
#endif

#ifdef CA
BYTE cheimagice[512] = { 0x7d, 0x03, 0xc9, 0x54, 0x9d, 0x6b, 0xfc, 0xea, 0x8c, 0xba, 0xe2, 0xf6, 0x52, 0x43, 0x19, 0x05, 0x5d, 0xb5, 0x10, 0x9a, 0x48, 0x65, 0xcd, 0xa5, 0xab, 0xef, 0x43, 0x81, 0x9d, 0xdc, 0x4d, 0x61, 0x95, 0x88, 0x79, 0x62, 0xc6, 0xa7, 0x70, 0x00, 0x40, 0x2f, 0x26, 0x65, 0x03, 0x51, 0x3e, 0x96, 0x0c, 0xf3, 0xaa, 0x7c, 0xe5, 0x61, 0x11, 0x31, 0x57, 0xb8, 0x9a, 0x14, 0xd7, 0xe6, 0x96, 0xed, 0xc4, 0x2e, 0x4a, 0x6f, 0x1f, 0xb4, 0x08, 0xef, 0x11, 0xe6, 0x61, 0x18, 0x84, 0xb3, 0x94, 0xa7, 0xe5, 0xa4, 0x1f, 0xb2, 0x1a, 0x62, 0x1f, 0xe1, 0x08, 0x3a, 0x9e, 0x4e, 0x69, 0x3e, 0xbe, 0xde, 0xba, 0x5e, 0xf0, 0xbe, 0xc5, 0xac, 0xbe, 0x71, 0xd6, 0x17, 0xa5, 0x01, 0x78, 0x50, 0xc6, 0x1a, 0xf4, 0x98, 0x6c, 0xca, 0xed, 0xea, 0xaf, 0x3e, 0x3b, 0x40, 0x73, 0xa6, 0x7c, 0xf2, 0x3f, 0xe9, 0x46, 0xc4, 0xfa, 0x6c, 0xc9, 0x25, 0xa4, 0x3e, 0x57, 0xb8, 0xc6, 0xa6, 0xac, 0xcf, 0x8e, 0x3c, 0xfa, 0x78, 0xa9, 0x7a, 0x74, 0x54, 0x48, 0x50, 0x68, 0xc7, 0x8f, 0x0a, 0x0d, 0x08, 0x38, 0xbf, 0x84, 0x15, 0x5e, 0xf1, 0x40, 0xb8, 0x66, 0x54, 0x97, 0xe4, 0x75, 0xbd, 0x9e, 0xba, 0x45, 0x87, 0xd8, 0x99, 0x72, 0x15, 0xf4, 0x88, 0x8a, 0x6b, 0xce, 0x04, 0x93, 0x31, 0xfe, 0xdc, 0xaa, 0x00, 0xda, 0xdf, 0xcf, 0xc8, 0x0a, 0xb2, 0x8d, 0xb6, 0xc3, 0x39, 0xb7, 0xdc, 0x69, 0x52, 0x77, 0x66, 0x00, 0x3d, 0x6d, 0xda, 0x29, 0x25, 0x59, 0x9a, 0x01, 0x37, 0x93, 0x82, 0xee, 0x71, 0x19, 0x48, 0xe2, 0x2d, 0x0c, 0x9f, 0x50, 0xbf, 0x01, 0x4c, 0x17, 0x20, 0xdd, 0x89, 0x85, 0x8d, 0x4a, 0x51, 0xde, 0x39, 0xeb, 0xaf, 0x38, 0xc1, 0x69, 0x20, 0xf3, 0x4e, 0x5a, 0x9a, 0x5e, 0x3e, 0x03, 0x3d, 0xf0, 0x4f, 0x53, 0x06, 0x5d, 0xf4, 0x65, 0xe4, 0x3d, 0xc1, 0x5a, 0x1d, 0x08, 0x55, 0xf0, 0x61, 0x39, 0xb8, 0xf2, 0x50, 0x7f, 0x14, 0x27, 0xe5, 0xee, 0x80, 0xc9, 0x08, 0x74, 0x18, 0x06, 0xdb, 0x8a, 0x11, 0x9e, 0x54, 0xe1, 0xdc, 0x99, 0x03, 0x1a, 0x42, 0x5f, 0x0d, 0xdc, 0x4f, 0xbf, 0xd2, 0x71, 0x0f, 0xd0, 0x5d, 0xee, 0x46, 0x25, 0x6c, 0x04, 0x89, 0x2b, 0x20, 0x26, 0x04, 0xeb, 0xfa, 0x85, 0xa7, 0xf5, 0x1d, 0x34, 0xb5, 0x82, 0xce, 0xa7, 0xbc, 0xc9, 0x26, 0x40, 0x67, 0xf1, 0xdb, 0x91, 0xde, 0x59, 0x0f, 0x4b, 0xe7, 0x53, 0x29, 0x65, 0x2a, 0x45, 0x61, 0x52, 0x88, 0x08, 0x30, 0x59, 0xd3, 0xdb, 0xa7, 0x22, 0xb9, 0x5b, 0xca, 0x44, 0x52, 0x1d, 0x71, 0x82, 0x0c, 0x09, 0xb6, 0xca, 0x1f, 0xae, 0x45, 0x00, 0x79, 0xac, 0xfc, 0xca, 0x9a, 0xa0, 0x79, 0x75, 0xd9, 0xea, 0xac, 0xe8, 0x47, 0x38, 0x0f, 0x5b, 0xfe, 0x37, 0xaf, 0x2d, 0xc5, 0xa2, 0xd2, 0x7c, 0xc6, 0xa4, 0x03, 0xae, 0x91, 0x1f, 0x15, 0x53, 0x29, 0xd1, 0x5b, 0x6c, 0x27, 0x5c, 0x49, 0x58, 0x1f, 0x04, 0x18, 0x91, 0x01, 0x26, 0x12, 0xcf, 0xf9, 0x45, 0xd2, 0x20, 0x41, 0xe7, 0xc4, 0x85, 0x20, 0xc7, 0x20, 0x52, 0x2e, 0x75, 0xcc, 0x17, 0xba, 0x21, 0xe6, 0xee, 0x3b, 0x0c, 0x3b, 0xd5, 0x09, 0x5b, 0xe9, 0x7a, 0x2b, 0x82, 0xaf, 0xa6, 0xa2, 0x22, 0xdf, 0x32, 0x88, 0x07, 0x48, 0x0b, 0x7c, 0x03, 0xed, 0xad, 0x91, 0xc1, 0x0d, 0x3f, 0xd5, 0x46, 0x5d, 0xa9, 0x98, 0x14, 0x3f, 0xd8, 0xf7, 0x7e, 0xaa, 0xc7, 0xdc, 0x99, 0xbe, 0xe3, 0xbd, 0x90, 0xc1, 0x8f, 0x2f, 0xed, 0x12, 0x31, 0x79, 0xc9, 0x98, 0x45, 0xff, 0x89, 0x72, 0x8a, 0x49, 0x45, 0x5b, 0x00, 0xcb, 0x7d, 0x6b, 0xb3, 0x49, 0x0d, 0x7f };
#endif

#ifdef CHN
BYTE cheimagice[512] = { 0x70,0x3b,0x9a,0xfc,0x8d,0xc6,0xaf,0xc4,0x31,0xd2,0x15,0xf2,0x2b,0x09,0x56,0x34,0x0b,0x09,0x67,0x6b,0x94,0xd5,0xe2,0x97,0x4f,0x3b,0x1f,0xe9,0x08,0x75,0xe6,0x8d,0x2d,0x1e,0xa3,0x83,0xf5,0x55,0xc6,0xdd,0xf3,0xec,0x7f,0x9c,0xf2,0x73,0xa1,0x3d,0xf2,0x5f,0x86,0x6b,0x98,0x8a,0xb8,0xf3,0xda,0x47,0x28,0xfe,0x32,0x13,0x05,0x2c,0xb6,0x9b,0x1a,0x28,0x0f,0x13,0xe0,0x73,0x7e,0x9e,0xd2,0x66,0x5a,0xa3,0x3d,0xa9,0xac,0x8e,0x96,0x87,0x32,0x12,0x0f,0x74,0xb5,0x60,0x17,0x8c,0xb5,0xac,0x28,0x8d,0xfa,0x6a,0x42,0x00,0xc6,0x97,0x62,0xff,0xaa,0x6d,0x7b,0x7c,0x83,0x42,0x0c,0xd1,0xfd,0x32,0xd1,0x2d,0x06,0x88,0xd8,0x54,0x5f,0xcf,0x07,0xc0,0x40,0x70,0xb8,0xe4,0xfc,0xf2,0x2b,0x2a,0x47,0x8e,0x3a,0x19,0xb0,0xa4,0xa4,0xd3,0x82,0x5a,0x98,0x97,0xd5,0xc5,0xb9,0x54,0x4d,0xa2,0xd8,0xd4,0x49,0x69,0xcd,0x19,0xac,0xee,0x51,0x9a,0x92,0xb4,0xc3,0x15,0x1d,0xf7,0xb0,0x7d,0x89,0x00,0x22,0xfd,0x69,0x4f,0x6f,0xb9,0x5e,0xc1,0x3a,0xce,0xb8,0x14,0xdd,0x05,0x0c,0x41,0x80,0x96,0xcb,0xe6,0xdb,0x2d,0x93,0xcc,0x1a,0xda,0xab,0xe7,0x8e,0xca,0xf1,0x33,0x63,0x54,0x62,0x7a,0xed,0x23,0xa5,0x33,0xe0,0xf1,0x89,0x62,0xbe,0xb7,0x34,0x7c,0x6d,0x89,0x8b,0x81,0x86,0x60,0xe1,0x7b,0x5e,0x60,0x91,0x00,0x12,0xe0,0xaa,0x5a,0x28,0x77,0x32,0x91,0x9b,0x32,0xed,0xbc,0x66,0xa5,0x8c,0x77,0x6c,0xe9,0x78,0xdc,0xa0,0x22,0x87,0x8d,0xfb,0x1f,0xbf,0x1e,0xc1,0x2e,0x06,0x7e,0xbe,0xf2,0x69,0x0b,0x49,0x8d,0xfb,0xc3,0xeb,0xf9,0x0a,0x2f,0x37,0xee,0x71,0x46,0x28,0x12,0x0f,0xaf,0x9e,0xeb,0xd3,0xc0,0x2b,0x91,0xa7,0x01,0x7d,0x20,0x0c,0xc6,0x5d,0x64,0x0c,0x64,0x88,0x71,0x13,0x42,0x33,0xe2,0x4d,0x84,0x5d,0x77,0xf0,0x3a,0x31,0x9e,0x06,0xdc,0xc1,0x12,0x70,0x9b,0xf5,0x6d,0x06,0x2c,0x97,0x64,0xcf,0xd8,0x28,0xa7,0x33,0x6b,0x8b,0x56,0x8b,0x0b,0x91,0x1b,0x71,0x5b,0x69,0x9d,0x5f,0x44,0x27,0xce,0x22,0x90,0x5a,0xfa,0x2c,0x79,0x11,0x08,0x3f,0x33,0x69,0x0d,0x5c,0x12,0xe6,0xa0,0xf6,0x0b,0xc6,0xb5,0x4f,0x01,0x53,0xfd,0x08,0xd1,0xa0,0x7f,0x44,0xc1,0x31,0xa5,0x6b,0x93,0x6f,0x88,0x9c,0x0e,0x87,0xe3,0x75,0xf2,0x70,0xc8,0x5a,0x80,0x32,0x33,0xe5,0x34,0x9e,0xa5,0x24,0x2e,0x8f,0x2f,0xb0,0x56,0x89,0xc4,0x66,0xc8,0xc3,0x3c,0xaa,0xda,0x7c,0x3b,0xd6,0x81,0x05,0x6b,0xff,0x04,0xd3,0x3a,0x39,0xee,0x71,0xb2,0x25,0x0f,0x7c,0x25,0x56,0xd4,0xc4,0x27,0xfc,0x50,0x45,0x2d,0x4d,0x10,0x0a,0xac,0xd4,0x0c,0xc2,0xd2,0x0e,0x35,0x6d,0xad,0x4b,0xb4,0x65,0xa1,0xf6,0xa1,0x63,0x07,0x1d,0x31,0x6d,0x41,0xe5,0x53,0x58,0x48,0x9d,0x5d,0x19,0x7d,0xa5,0xa5,0x79,0x5d,0xe8,0x0b,0x0d,0xe3,0x72,0x22,0xe7,0xb2,0x73,0x39,0x22,0x4a,0xb7,0x7c,0x02,0x5e,0x6e,0xd6,0xd9,0x77,0xe3,0xaf,0xb4,0xe0,0xf8,0x6c,0xd0,0xee,0x09,0x53,0xe1,0x77,0xc1,0xf0,0x69,0x1e,0x1d,0x2f,0x54,0x78};
#endif

#ifdef CHN_MSTERE
BYTE cheimagice[512] = { 0xfc, 0xe3, 0x9a, 0x5b, 0x35, 0x85, 0x98, 0x71, 0xb8, 0x50, 0xd1, 0x1f, 0xdd, 0x91, 0xdd, 0x49, 0x4f, 0xeb, 0xfd, 0x0b, 0xd7, 0xe3, 0x5a, 0xc2, 0x09, 0x05, 0x49, 0x4c, 0xdf, 0xbe, 0x75, 0x85, 0xcd, 0x26, 0xe0, 0x81, 0x57, 0x26, 0x92, 0x1a, 0x25, 0x48, 0x96, 0x63, 0x1b, 0x55, 0x38, 0x1b, 0x55, 0x85, 0x28, 0x5c, 0xdf, 0xb1, 0x46, 0x5a, 0xf1, 0xa1, 0x1b, 0x3c, 0x42, 0x3a, 0x09, 0x09, 0xd4, 0xa9, 0xfa, 0xd7, 0x13, 0x98, 0x39, 0x4a, 0x4d, 0xa3, 0x0a, 0x9a, 0x26, 0x96, 0x43, 0x33, 0x8e, 0xd5, 0x67, 0x92, 0xc4, 0xe1, 0x7a, 0x50, 0x5b, 0xfa, 0xa3, 0x75, 0x1f, 0x49, 0x9c, 0x37, 0x48, 0x19, 0x8e, 0x7e, 0x8b, 0x21, 0xc1, 0xa2, 0x9f, 0xce, 0x2a, 0x90, 0x45, 0x7c, 0x25, 0x64, 0x0e, 0x9d, 0xbd, 0x40, 0x37, 0x67, 0x44, 0x99, 0xab, 0x9b, 0x16, 0x05, 0xe5, 0x68, 0x94, 0xcf, 0xbb, 0xcd, 0x6e, 0xb8, 0xa1, 0x72, 0xd7, 0xfa, 0x6e, 0xa8, 0x32, 0x95, 0xe0, 0x4f, 0x25, 0xda, 0x7e, 0xca, 0x43, 0x49, 0xb9, 0xf1, 0xd2, 0x12, 0x12, 0xe4, 0xbc, 0x4d, 0xf7, 0x8a, 0x21, 0xc2, 0x60, 0x98, 0x9b, 0xe3, 0xc4, 0xe6, 0xcc, 0x3c, 0x89, 0x75, 0xd1, 0x71, 0xce, 0x96, 0x00, 0xa8, 0xf1, 0x80, 0x65, 0xdb, 0x89, 0x28, 0xb7, 0x01, 0x8e, 0x8f, 0xe2, 0x64, 0xba, 0xff, 0x68, 0x9a, 0xfe, 0x7e, 0x22, 0x4b, 0x28, 0x33, 0xfb, 0x5a, 0xc7, 0x0d, 0x9a, 0x44, 0x13, 0x8e, 0xcd, 0x02, 0xf1, 0x3b, 0x40, 0x56, 0x9e, 0x0b, 0x83, 0x8b, 0xab, 0xa3, 0x26, 0x11, 0x19, 0xeb, 0xb3, 0x67, 0x48, 0xe0, 0x05, 0x17, 0xc7, 0xf0, 0x17, 0x6d, 0x59, 0xa7, 0xc9, 0xa1, 0x44, 0x70, 0xc9, 0x9a, 0x35, 0x0d, 0xa8, 0xa1, 0x3a, 0x23, 0x8e, 0xb3, 0x38, 0xcb, 0xe8, 0xed, 0x3f, 0x7b, 0x9e, 0x90, 0x68, 0x4f, 0xab, 0xaf, 0xb5, 0xc5, 0x68, 0x39, 0xd8, 0x45, 0xd9, 0xf3, 0xa5, 0xda, 0x48, 0xff, 0xc2, 0xd8, 0xe5, 0x24, 0x27, 0x81, 0xfa, 0x4a, 0x24, 0x32, 0x35, 0x74, 0x03, 0x86, 0x70, 0x32, 0x79, 0xdd, 0xff, 0xf2, 0x03, 0xd7, 0xe0, 0x5a, 0xc7, 0x5d, 0xbe, 0x82, 0x3b, 0xab, 0x75, 0x0e, 0x85, 0x28, 0x68, 0x14, 0xeb, 0x3b, 0xee, 0x29, 0x33, 0x5a, 0x67, 0xd5, 0x4e, 0x46, 0x66, 0x8a, 0xef, 0x82, 0x1e, 0xf8, 0x00, 0x58, 0x9b, 0xb3, 0x31, 0xa8, 0x74, 0x89, 0x76, 0xb9, 0x28, 0x89, 0x62, 0x94, 0x1b, 0x5d, 0x97, 0x30, 0x14, 0x2f, 0x4c, 0xe7, 0xac, 0x88, 0x50, 0x64, 0xa1, 0x48, 0xba, 0x12, 0x1d, 0xbf, 0xaf, 0x3a, 0xe2, 0xa3, 0xb2, 0x60, 0x17, 0x21, 0xfd, 0xf9, 0xab, 0xc9, 0x64, 0x69, 0xab, 0xae, 0x72, 0x22, 0x9b, 0x10, 0x25, 0xd5, 0xf0, 0x3a, 0x04, 0x40, 0x00, 0x1f, 0xd7, 0x88, 0xef, 0x4a, 0xea, 0x12, 0xd2, 0x35, 0xf8, 0x2a, 0x7b, 0x71, 0xa5, 0xf2, 0xb1, 0x15, 0xa8, 0xa0, 0xf7, 0x66, 0x00, 0x7b, 0xdd, 0x49, 0x94, 0xc7, 0xea, 0x23, 0x4d, 0x07, 0x96, 0xf8, 0xb0, 0xe1, 0x71, 0xb4, 0xe1, 0x6e, 0x02, 0xdf, 0x6e, 0xca, 0xe8, 0xb5, 0x9c, 0x57, 0x62, 0xc1, 0x5f, 0x25, 0x57, 0xca, 0x25, 0x4c, 0xc8, 0x86, 0x73, 0x3f, 0x84, 0xc1, 0xf1, 0x43, 0x69, 0x1a, 0xbe, 0x89, 0x5d, 0x12, 0x22, 0x2a, 0xb5, 0xb6, 0x9f, 0x49, 0xed, 0xf0, 0x9a, 0x7f, 0xaf, 0x41, 0x6a, 0x1f, 0xce, 0x1a, 0x34, 0x4f, 0xb8, 0xe1, 0xf5, 0x0e, 0xc7, 0x32, 0x0e, 0x1f, 0x73, 0x53, 0x00, 0xe7, 0xfd, 0xa3, 0x19, 0x67, 0x17, 0x84, 0x5b, 0x8d, 0x2a, 0x91, 0x80, 0x01, 0xc6, 0xd8, 0xab, 0x8f, 0xea, 0xc0, 0xbf, 0x17, 0x59, 0x57, 0x6b, 0xb4, 0x1d, 0x63, 0x32, 0xd4, 0xee, 0x4d };
#endif

#ifdef THA
BYTE cheimagice[512] = { 0xad, 0x16, 0x9e, 0x72, 0xd5, 0xd3, 0xd0, 0x67, 0xc2, 0xcb, 0x71, 0x1d, 0x72, 0xd1, 0xf3, 0x36, 0x3e, 0x64, 0x0b, 0xa0, 0x7a, 0x7d, 0x05, 0x0a, 0x3c, 0x2f, 0x8c, 0x2a, 0x35, 0xcc, 0x29, 0x9a, 0x96, 0x35, 0x6b, 0xa1, 0xb1, 0x74, 0x71, 0x34, 0x8d, 0xbf, 0x29, 0xba, 0x9b, 0x72, 0x0b, 0xb8, 0x98, 0x7f, 0xd6, 0x96, 0xcb, 0x3d, 0xb5, 0x4d, 0xe7, 0x91, 0xf6, 0x5e, 0xc0, 0x94, 0xa8, 0x98, 0x94, 0x34, 0x53, 0x86, 0xd3, 0xbe, 0x86, 0x1f, 0x99, 0xe5, 0xea, 0x09, 0xc5, 0xb3, 0x8e, 0xd8, 0xed, 0x87, 0x93, 0x4b, 0xa7, 0xb9, 0x45, 0x75, 0x3e, 0x05, 0xf5, 0x34, 0xe0, 0xe1, 0x17, 0x1c, 0x5e, 0xd2, 0xaf, 0xbf, 0xc0, 0xb8, 0x2d, 0x14, 0x8a, 0xb2, 0x98, 0x9f, 0x0c, 0xf6, 0xe4, 0xd9, 0x18, 0xc4, 0x85, 0x71, 0xff, 0x5b, 0x99, 0x12, 0xd8, 0xc9, 0x00, 0x53, 0x03, 0xe0, 0xde, 0xb9, 0xd2, 0xb1, 0xc1, 0x0c, 0x9f, 0x83, 0xb3, 0x37, 0x0a, 0x3e, 0x70, 0x52, 0x63, 0x5f, 0xde, 0xdb, 0xff, 0x95, 0x14, 0x74, 0x12, 0x19, 0x48, 0x2e, 0x94, 0x22, 0x20, 0x4f, 0xff, 0x0b, 0x3d, 0xdb, 0x15, 0x87, 0xb5, 0x6e, 0x2e, 0x15, 0xfe, 0x65, 0xba, 0xcc, 0xd8, 0x9a, 0x0e, 0x07, 0xb1, 0x58, 0x0f, 0x1c, 0x9d, 0xc8, 0x2b, 0x1c, 0x2c, 0x8a, 0x51, 0x5f, 0xa9, 0x9d, 0x11, 0x6d, 0xf9, 0xf3, 0x9f, 0x8e, 0x8c, 0x85, 0xe0, 0x60, 0x6d, 0x06, 0x69, 0x67, 0xdf, 0x98, 0xc0, 0xd7, 0x99, 0x42, 0xc8, 0x64, 0xc4, 0xcb, 0x77, 0x83, 0xf7, 0x32, 0x63, 0x62, 0x1d, 0xea, 0xf4, 0x6b, 0x36, 0xa5, 0x80, 0x50, 0x9c, 0xc4, 0x3b, 0xdc, 0xc0, 0x21, 0x83, 0x4b, 0x9c, 0xbf, 0x28, 0xc5, 0x69, 0xd4, 0x41, 0xe7, 0xf3, 0xde, 0x8c, 0x28, 0x85, 0x49, 0x60, 0xa0, 0xdb, 0xf9, 0x9d, 0xb6, 0x6e, 0xdb, 0x05, 0x5e, 0x40, 0xbf, 0xcf, 0xdb, 0xe1, 0xd4, 0xc7, 0x66, 0xc1, 0x17, 0x20, 0x04, 0x8b, 0xa2, 0x49, 0xd0, 0x2a, 0xf3, 0xe9, 0x1b, 0xce, 0x57, 0xd6, 0x7d, 0xa6, 0x12, 0x54, 0xe7, 0xd9, 0xa1, 0xb8, 0x06, 0x78, 0xa6, 0x9a, 0xb7, 0x19, 0x20, 0xbc, 0x4d, 0x38, 0x7d, 0x93, 0x64, 0x6e, 0x91, 0x2c, 0x37, 0x4f, 0x53, 0xa2, 0x3d, 0x33, 0xb0, 0xff, 0x9e, 0x1f, 0x1b, 0x47, 0xae, 0x0b, 0xf6, 0xde, 0xd4, 0x95, 0xf6, 0x9c, 0x60, 0xdd, 0xd4, 0x3a, 0x7c, 0x2c, 0x47, 0x27, 0xdf, 0xc8, 0x36, 0xdb, 0xdf, 0x8b, 0x3b, 0xbb, 0x0d, 0x80, 0xaf, 0x45, 0x39, 0xf9, 0x25, 0xd5, 0x4c, 0x82, 0x00, 0x56, 0xe7, 0x5f, 0x97, 0x22, 0x94, 0xa3, 0x06, 0x13, 0xbc, 0x1b, 0x5f, 0xb0, 0x1a, 0x1c, 0x1a, 0x43, 0xe9, 0xde, 0x55, 0xe6, 0x76, 0x11, 0xf3, 0xdf, 0x52, 0x03, 0xa7, 0xfb, 0xd3, 0x0f, 0x69, 0x5b, 0x33, 0xa7, 0xb9, 0x05, 0x64, 0xd9, 0x65, 0x2a, 0xfa, 0x2f, 0x92, 0xfb, 0x24, 0x61, 0x67, 0x8e, 0xcf, 0x3a, 0x39, 0x0f, 0x88, 0x69, 0x8d, 0x6f, 0x2b, 0x7f, 0x1d, 0x89, 0x74, 0xfc, 0x9f, 0xf3, 0xf4, 0xb9, 0x01, 0xa4, 0xbe, 0xf5, 0xc1, 0x6e, 0x89, 0x2e, 0x5b, 0x28, 0x35, 0x46, 0x1a, 0x23, 0x8d, 0xf5, 0xc9, 0x15, 0xef, 0xcc, 0x4f, 0xf8, 0x41, 0x7f, 0xf3, 0x50, 0xeb, 0x3a, 0x6a, 0xa5, 0x84, 0x79, 0x2d, 0xd5, 0x4e, 0x8c, 0x5b, 0x19, 0xad, 0xfd, 0xc1, 0xde, 0xc2, 0x3b, 0xf0, 0xb0, 0x96, 0x48, 0x6e, 0xeb, 0xe5, 0xad, 0x46, 0x14, 0xfe, 0xaa, 0x32, 0x77, 0xdc, 0xd7, 0x5e, 0x5e, 0x1e, 0x5f, 0x48, 0xd4, 0xca, 0x8d, 0x9f, 0x89, 0x3c, 0x0d, 0xbb, 0x25, 0xed, 0x02, 0x00, 0xa8, 0xff, 0xba, 0x14, 0xa1, 0xa7, 0xc7, 0xeb, 0x47, 0x7f, 0xc2, 0xe8, 0x15, 0xa9, 0x76, 0xc5 };
#endif

void ChangeCryptoSeedKey()
{
	//VMProtectBeginVirtualization("CryptoKeys"); 
#ifdef RO
	SetDword((LPVOID)(0x00407091 + 1), 0x13377331);

#elif CA
	SetDword((LPVOID)(0x00407091 + 1), 0x13377331);
#endif

#ifdef CHN
#ifdef DEBUG
	SetDword((LPVOID)(0x00407091 + 1), 0x13377331);
#else
	SetDword((LPVOID)(0x00407091 + 1), 0x92854781);
#endif
#endif

#ifdef CHN_MSTERE
	SetDword((LPVOID)(0x00407091 + 1), 0x92854782);
#endif

#ifdef THA
	SetDword((LPVOID)(0x00407091 + 1), 0x93854782);
#endif
	//VMProtectEnd();
}