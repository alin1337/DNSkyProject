﻿#include "MemoryScanner.h"
#include <tlhelp32.h>
#include <windows.h>
#include <stdlib.h>
#include "security.h"
#include "vlizer.h"
#include "HTTPGuard.h"


int last_Hack = 0;

#ifdef _MANAGED
#pragma managed(push, off)
#endif


ANITHACK_PROCDUMP g_ProcessesDumps[MAX_PROCESS_DUMP] =
{
	{ 0x4C8259, { 0xA1, 0x38, 0xBD, 0x4C, 0x00, 0x8B, 0x00, 0x8B, 0x4D, 0xFC, 0xBA, 0xC0, 0x82, 0x4C, 0x00, 0xE8, 0x1F, 0xF1, 0xFF, 0xFF, 0x33, 0xDB, 0xE8, 0xF8, 0xBE, 0xF3, 0xFF, 0x33, 0xC0, 0x5A, 0x59, 0x59 }, "NaN" },   // Catastrophe v0.1
	{ 0x4C5F31, { 0x7C, 0x23, 0x8B, 0x45, 0xFC, 0x80, 0x38, 0xC1, 0x75, 0x1B, 0x8B, 0x45, 0xFC, 0x80, 0x78, 0x02, 0xF3, 0x75, 0x12, 0x8B, 0x45, 0xFC, 0x80, 0x78, 0x03, 0x00, 0x75, 0x09, 0x8B, 0x45, 0xFC, 0x80 }, "NaN" },   // Catastrophe v0.1
	{ 0x4CCB71, { 0xA1, 0x40, 0xFD, 0x4C, 0x00, 0x8B, 0x00, 0x8B, 0x4D, 0xFC, 0xBA, 0xD8, 0xCB, 0x4C, 0x00, 0xE8, 0xAB, 0xF2, 0xFF, 0xFF, 0x33, 0xDB, 0xE8, 0xE0, 0x75, 0xF3, 0xFF, 0x33, 0xC0, 0x5A, 0x59, 0x59 }, "NaN" },   // Catastrophe v1.2
	{ 0x4CA831, { 0x89, 0x55, 0xFC, 0x8B, 0x45, 0xFC, 0xE8, 0xC8, 0xA3, 0xF3, 0xFF, 0x33, 0xC0, 0x55, 0x68, 0x96, 0xA8, 0x4C, 0x00, 0x64, 0xFF, 0x30, 0x64, 0x89, 0x20, 0x8B, 0x45, 0xFC, 0xE8, 0xC2, 0xA1, 0xF3 }, "NaN" },   // Catastrophe v1.2
#if !defined(CHN_MSTERE)
	{ 0x44E08C, { 0x64, 0x89, 0x25, 0x00, 0x00, 0x00, 0x00, 0x83, 0xEC, 0x58, 0x53, 0x56, 0x57, 0x89, 0x65, 0xE8, 0xFF, 0x15, 0x04, 0xF4, 0x48, 0x00, 0x33, 0xD2, 0x8A, 0xD4, 0x89, 0x15, 0xD8, 0x0A, 0x4D, 0x00 }, "NaN" },   // WPePro 0.9a
	{ 0x4851C2, { 0x75, 0x1C, 0x53, 0x8B, 0xCE, 0xFF, 0x75, 0xE4, 0xFF, 0x75, 0xE0, 0x57, 0xE8, 0x90, 0x01, 0xFE, 0xFF, 0xEB, 0x0B, 0x53, 0x57, 0xFF, 0x76, 0x1C, 0xFF, 0x15, 0x9C, 0xF5, 0x48, 0x00, 0x8B, 0x86 }, "NaN" },   // WPePro 0.9a
	{ 0x4307BE, { 0x75, 0x0A, 0x6A, 0x1C, 0xE8, 0x49, 0x01, 0x00, 0x00, 0x83, 0xC4, 0x04, 0xE8, 0xB1, 0x30, 0x00, 0x00, 0x85, 0xC0, 0x75, 0x0A, 0x6A, 0x10, 0xE8, 0x36, 0x01, 0x00, 0x00, 0x83, 0xC4, 0x04, 0xC7 }, "NaN" },   // WPePro 1.3
	{ 0x44397B, { 0x75, 0x07, 0x8B, 0xCF, 0xE8, 0xF8, 0xF2, 0xFF, 0xFF, 0x5F, 0x5E, 0xC2, 0x08, 0x00, 0x53, 0x56, 0x8B, 0x74, 0x24, 0x0C, 0x57, 0xFF, 0x76, 0x04, 0xFF, 0x15, 0xC4, 0x9B, 0x49, 0x00, 0x8B, 0xD8 }, "NaN" },   // WPePro 1.3
#endif
	{ 0x402190, { 0x55, 0x8B, 0xEC, 0x53, 0x56, 0x57, 0xBB, 0x00, 0x60, 0x40, 0x00, 0x66, 0x2E, 0xF7, 0x05, 0x1E, 0x28, 0x40, 0x00, 0x04, 0x00, 0x0F, 0x85, 0xDB, 0x00, 0x00, 0x00, 0x6A, 0x00, 0xFF, 0x15, 0x18 }, "NaN" },   // Permit
	{ 0x402230, { 0xE8, 0x07, 0x01, 0x00, 0x00, 0xB8, 0xFF, 0x00, 0x00, 0x00, 0x72, 0x36, 0xE8, 0x5E, 0x02, 0x00, 0x00, 0xE8, 0x3B, 0x04, 0x00, 0x00, 0xB8, 0xFF, 0x00, 0x00, 0x00, 0x72, 0x07, 0x53, 0xE8, 0x57 }, "NaN" },   // Permit
	{ 0x48F5AE, { 0x55, 0x8B, 0xEC, 0x6A, 0xFF, 0x68, 0x90, 0x8A, 0x4E, 0x00, 0x68, 0x8C, 0x44, 0x49, 0x00, 0x64, 0xA1, 0x00, 0x00, 0x00, 0x00, 0x50, 0x64, 0x89, 0x25, 0x00, 0x00, 0x00, 0x00, 0x83, 0xEC, 0x58 }, "NaN" },   // T Search
	{ 0x48F619, { 0xE8, 0xCE, 0x2D, 0x00, 0x00, 0x85, 0xC0, 0x75, 0x08, 0x6A, 0x10, 0xE8, 0xB2, 0x00, 0x00, 0x00, 0x59, 0x33, 0xF6, 0x89, 0x75, 0xFC, 0xE8, 0x63, 0x7A, 0x00, 0x00, 0xFF, 0x15, 0x68, 0x44, 0x4D }, "NaN" },   // T Search
	{ 0x40970E, { 0x68, 0xB4, 0x98, 0x40, 0x00, 0x64, 0xA1, 0x00, 0x00, 0x00, 0x00, 0x50, 0x64, 0x89, 0x25, 0x00, 0x00, 0x00, 0x00, 0x83, 0xEC, 0x68, 0x53, 0x56, 0x57, 0x89, 0x65, 0xE8, 0x33, 0xDB, 0x89, 0x5D }, "NaN" },   // Speed Gear 5
	{ 0x568E9A, { 0x68, 0xB8, 0xF9, 0x85, 0x13, 0xE8, 0x9D, 0x53, 0x01, 0x00, 0xB6, 0x94, 0x70, 0x4B, 0xE8, 0x87, 0xE5, 0x43, 0xE4, 0x43, 0x21, 0x7B, 0x18, 0xB7, 0xBB, 0x79, 0x6D, 0x3E, 0xF9, 0x1E, 0x5C, 0x7F }, "NaN" },   // Speed Gear 6
	{ 0x512134, { 0x75, 0x05, 0x8A, 0x16, 0x46, 0x12, 0xD2, 0x73, 0xEA, 0x02, 0xD2, 0x75, 0x05, 0x8A, 0x16, 0x46, 0x12, 0xD2, 0x73, 0x4F, 0x33, 0xC0, 0x02, 0xD2, 0x75, 0x05, 0x8A, 0x16, 0x46, 0x12, 0xD2, 0x0F }, "NaN" },   // WildProxy v1.0 Public
	{ 0x512014, { 0xB8, 0x00, 0x00, 0x00, 0x00, 0x60, 0x0B, 0xC0, 0x74, 0x68, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x58, 0x05, 0x53, 0x00, 0x00, 0x00, 0x80, 0x38, 0xE9, 0x75, 0x13, 0x61, 0xEB, 0x45, 0xDB, 0x2D, 0x37 }, "NaN" },   // WildProxy v1.0 Public
	{ 0x401320, { 0xEB, 0x10, 0x66, 0x62, 0x3A, 0x43, 0x2B, 0x2B, 0x48, 0x4F, 0x4F, 0x4B, 0x90, 0xE9, 0x98, 0x90, 0x46, 0x00, 0xA1, 0x8B, 0x90, 0x46, 0x00, 0xC1, 0xE0, 0x02, 0xA3, 0x8F, 0x90, 0x46, 0x00, 0x52 }, "NaN" },   // WildProxy v0.1
	{ 0x4013F9, { 0xE8, 0x1A, 0x21, 0x06, 0x00, 0xA3, 0x8B, 0x90, 0x46, 0x00, 0x83, 0xF8, 0x00, 0x73, 0x91, 0xB8, 0xFC, 0x00, 0x00, 0x00, 0xE8, 0x7A, 0xFF, 0xFF, 0xFF, 0xC3, 0x83, 0x3D, 0x8B, 0x90, 0x46, 0x00 }, "NaN" },   // WildProxy v0.1
	{ 0x401320, { 0xEB, 0x10, 0x66, 0x62, 0x3A, 0x43, 0x2B, 0x2B, 0x48, 0x4F, 0x4F, 0x4B, 0x90, 0xE9, 0x98, 0x20, 0x47, 0x00, 0xA1, 0x8B, 0x20, 0x47, 0x00, 0xC1, 0xE0, 0x02, 0xA3, 0x8F, 0x20, 0x47, 0x00, 0x52 }, "NaN" },   // WildProxy v0.2
	{ 0x4013B0, { 0xE8, 0xD7, 0xFF, 0xFF, 0xFF, 0xB9, 0xB4, 0x00, 0x00, 0x00, 0x51, 0x6A, 0x08, 0xE8, 0xF4, 0x00, 0x07, 0x00, 0x50, 0xE8, 0x60, 0x01, 0x07, 0x00, 0x0B, 0xC0, 0x75, 0x0A, 0xB8, 0xFD, 0x00, 0x00 }, "NaN" },   // WildProxy v0.2
	{ 0x401350, { 0xEB, 0x10, 0x66, 0x62, 0x3A, 0x43, 0x2B, 0x2B, 0x48, 0x4F, 0x4F, 0x4B, 0x90, 0xE9, 0x98, 0xC0, 0x47, 0x00, 0xA1, 0x8B, 0xC0, 0x47, 0x00, 0xC1, 0xE0, 0x02, 0xA3, 0x8F, 0xC0, 0x47, 0x00, 0x52 }, "NaN" },   // WildProxy v0.3
	{ 0x401401, { 0xE8, 0xB6, 0xFF, 0xFF, 0xFF, 0x50, 0x50, 0xFF, 0x35, 0x8B, 0xC0, 0x47, 0x00, 0xE8, 0xAD, 0x54, 0x07, 0x00, 0xFF, 0x35, 0x8B, 0xC0, 0x47, 0x00, 0xE8, 0xB6, 0x54, 0x07, 0x00, 0x5F, 0xC3, 0xB9 }, "NaN" },   // WildProxy v0.3
	{ 0x40C0B0, { 0x70, 0x6C, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x31, 0x5C, 0x6F, 0x62, 0x6A, 0x5C, 0x52, 0x65, 0x6C, 0x65, 0x61, 0x73, 0x65, 0x5C, 0x53, 0x70, 0x65, 0x65, 0x64, 0x20, 0x48, 0x61, 0x63 }, "NaN" },   // Speed Hack Simplifier 1.0
	{ 0x40C0B0, { 0x70, 0x6C, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x31, 0x5C, 0x6F, 0x62, 0x6A, 0x5C, 0x52, 0x65, 0x6C, 0x65, 0x61, 0x73, 0x65, 0x5C, 0x53, 0x70, 0x65, 0x65, 0x64, 0x20, 0x48, 0x61, 0x63 }, "NaN" },   // Speed Hack Simplifier 1.1
	{ 0x40C0B0, { 0x70, 0x6C, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x31, 0x5C, 0x6F, 0x62, 0x6A, 0x5C, 0x52, 0x65, 0x6C, 0x65, 0x61, 0x73, 0x65, 0x5C, 0x53, 0x70, 0x65, 0x65, 0x64, 0x20, 0x48, 0x61, 0x63 }, "NaN" },   // Speed Hack Simplifier 1.2
	{ 0x40E04E, { 0x53, 0x68, 0x61, 0x64, 0x6F, 0x77, 0x42, 0x65, 0x61, 0x73, 0x74, 0x2E, 0x41, 0x53, 0x41, 0x46, 0x2D, 0x46, 0x32, 0x31, 0x34, 0x39, 0x42, 0x33, 0x31, 0x35, 0x35, 0x5C, 0x4D, 0x79, 0x20, 0x44 }, "NaN" },   // Speed Hack Simplifier 1.3 Test
	{ 0x4320F0, { 0x53, 0x00, 0x5F, 0x00, 0x56, 0x00, 0x45, 0x00, 0x52, 0x00, 0x53, 0x00, 0x49, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x5F, 0x00, 0x49, 0x00, 0x4E, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x00, 0x00, 0x00, 0x00 }, "NaN" },   // Cheat Happens v3.9b1
	{ 0x4340F0, { 0x53, 0x00, 0x5F, 0x00, 0x56, 0x00, 0x45, 0x00, 0x52, 0x00, 0x53, 0x00, 0x49, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x5F, 0x00, 0x49, 0x00, 0x4E, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x00, 0x00, 0x00, 0x00 }, "NaN" },   // Cheat Happens v3.95b1/b2
	{ 0x4360F0, { 0x53, 0x00, 0x5F, 0x00, 0x56, 0x00, 0x45, 0x00, 0x52, 0x00, 0x53, 0x00, 0x49, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x5F, 0x00, 0x49, 0x00, 0x4E, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x00, 0x00, 0x00, 0x00 }, "NaN" },   // Cheat Happens v3.95b3
	{ 0x440020, { 0x5F, 0xE4, 0xAD, 0x60, 0x36, 0x56, 0x43, 0x4D, 0x92, 0xBD, 0xC8, 0x6F, 0xF8, 0xDE, 0xE1, 0xBD, 0x01, 0x00, 0x00, 0x00, 0x46, 0x3A, 0x5C, 0x44, 0x6F, 0x63, 0x75, 0x6D, 0x65, 0x6E, 0x74, 0x73 }, "NaN" },   // Cheat Happens v3.96b2
	{ 0x41F001, { 0x60, 0xE8, 0x03, 0x00, 0x00, 0x00, 0xE9, 0xEB, 0x04, 0x5D, 0x45, 0x55, 0xC3, 0xE8, 0x01, 0x00, 0x00, 0x00, 0xEB, 0x5D, 0xBB, 0xED, 0xFF, 0xFF, 0xFF, 0x03, 0xDD, 0x81, 0xEB, 0x00, 0xF0, 0x01 }, "NaN" },   // !xSpeed.net 2
	{ 0x4217E0, { 0x60, 0xBE, 0x00, 0xD0, 0x41, 0x00, 0x8D, 0xBE, 0x00, 0x40, 0xFE, 0xFF, 0x57, 0xEB, 0x0B, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB, 0x75, 0x07, 0x8B, 0x1E, 0x83, 0xEE, 0xFC, 0x11 }, "NaN" },   // !xSpeed.net 3
	{ 0x420630, { 0x60, 0xBE, 0x00, 0xC0, 0x41, 0x00, 0x8D, 0xBE, 0x00, 0x50, 0xFE, 0xFF, 0x57, 0xEB, 0x0B, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB, 0x75, 0x07, 0x8B, 0x1E, 0x83, 0xEE, 0xFC, 0x11 }, "NaN" },   // !xSpeed.net 6
	{ 0x5674D4, { 0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xEC, 0x53, 0x33, 0xC0, 0x89, 0x45, 0xEC, 0xB8, 0x2C, 0x70, 0x56, 0x00, 0xE8, 0xC6, 0xFA, 0xE9, 0xFF, 0x8B, 0x1D, 0x98, 0xD8, 0x56, 0x00, 0x33, 0xC0, 0x55, 0x68 }, "NaN" },   // Cheat Engine 5.0
	{ 0x574EC0, { 0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xEC, 0x53, 0x33, 0xC0, 0x89, 0x45, 0xEC, 0xB8, 0xE0, 0x49, 0x57, 0x00, 0xE8, 0xCE, 0x20, 0xE9, 0xFF, 0x8B, 0x1D, 0xF8, 0xB8, 0x57, 0x00, 0x33, 0xC0, 0x55, 0x68 }, "NaN" },   // Cheat Engine 5.1.1
	{ 0x574EEC, { 0xE8, 0x8B, 0xEA, 0xF1, 0xFF, 0x8D, 0x45, 0xEC, 0xE8, 0x33, 0x56, 0xFF, 0xFF, 0xE8, 0x5A, 0x1F, 0xFD, 0xFF, 0x8B, 0x03, 0xBA, 0x68, 0x50, 0x57, 0x00, 0xE8, 0x6A, 0xE6, 0xF1, 0xFF, 0x8B, 0x03 }, "NaN" },   // Cheat Engine 5.1
	{ 0x4CBD70, { 0x8D, 0x85, 0x7C, 0xFE, 0xFF, 0xFF, 0xBA, 0x03, 0x00, 0x00, 0x00, 0xE8, 0xB0, 0x8F, 0xF3, 0xFF, 0x8D, 0x85, 0x88, 0xFE, 0xFF, 0xFF, 0xBA, 0x04, 0x00, 0x00, 0x00, 0xE8, 0xA0, 0x8F, 0xF3, 0xFF }, "NaN" },   // Cheat Engine 5.1
	{ 0x591F94, { 0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xEC, 0x53, 0x33, 0xC0, 0x89, 0x45, 0xEC, 0xB8, 0x5C, 0x1A, 0x59, 0x00, 0xE8, 0x26, 0x50, 0xE7, 0xFF, 0x8B, 0x1D, 0x20, 0x89, 0x59, 0x00, 0x33, 0xC0, 0x55, 0x68 }, "NaN" },   // Cheat Engine 5.2
	{ 0x591FC0, { 0xE8, 0x07, 0x23, 0xF0, 0xFF, 0x8D, 0x45, 0xEC, 0xE8, 0x1F, 0x4B, 0xFF, 0xFF, 0xE8, 0x76, 0x99, 0xFC, 0xFF, 0x8B, 0x03, 0xBA, 0x18, 0x21, 0x59, 0x00, 0xE8, 0xE6, 0x1E, 0xF0, 0xFF, 0x8B, 0x03 }, "NaN" },   // Cheat Engine 5.2
	{ 0x5839E7, { 0x8D, 0x45, 0xB0, 0x50, 0x6A, 0x08, 0x8D, 0x85, 0x78, 0xFF, 0xFF, 0xFF, 0x50, 0xA1, 0xB0, 0xA1, 0x59, 0x00, 0x8B, 0x55, 0xA4, 0x8B, 0x04, 0x90, 0x50, 0xA1, 0x28, 0xA1, 0x59, 0x00, 0x50, 0xA1 }, "NaN" },   // Cheat Engine 5.2
	{ 0x5AA16C, { 0xE8, 0x13, 0x40, 0xFF, 0xFF, 0xE8, 0x86, 0x2C, 0xFC, 0xFF, 0x8B, 0x03, 0xBA, 0xD4, 0xA2, 0x5A, 0x00, 0xE8, 0xC2, 0x98, 0xEE, 0xFF, 0x8B, 0x03, 0x83, 0xC0, 0x50, 0xBA, 0xF0, 0xA2, 0x5A, 0x00 }, "NaN" },   // Cheat Engine 5.3
	{ 0x4CBE2B, { 0x8D, 0x55, 0xF0, 0xB9, 0x04, 0x00, 0x00, 0x00, 0x8B, 0xC7, 0xE8, 0x02, 0x15, 0xF5, 0xFF, 0x8B, 0x55, 0xF0, 0x8B, 0xC3, 0xE8, 0x8C, 0xF7, 0xFD, 0xFF, 0x8D, 0x55, 0xF0, 0xB9, 0x04, 0x00, 0x00 }, "NaN" },   // Cheat Engine 5.3
	{ 0x5CF354, { 0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xEC, 0x53, 0x33, 0xC0, 0x89, 0x45, 0xEC, 0xB8, 0x44, 0xED, 0x5C, 0x00, 0xE8, 0x62, 0x7E, 0xE3, 0xFF, 0x8B, 0x1D, 0xD4, 0x5A, 0x5D, 0x00, 0x33, 0xC0, 0x55, 0x68 }, "NaN" },   // Cheat Engine 5.4
	{ 0x5CF440, { 0xE8, 0x37, 0xA3, 0xFC, 0xFF, 0xE8, 0x8E, 0x96, 0xF9, 0xFF, 0x8B, 0x03, 0xBA, 0xA8, 0xF5, 0x5C, 0x00, 0xE8, 0x2A, 0xBD, 0xEC, 0xFF, 0x8B, 0x03, 0x83, 0xC0, 0x50, 0xBA, 0xC4, 0xF5, 0x5C, 0x00 }, "NaN" },   // Chear Engine 5.4
	{ 0x5CF43D, { 0x8D, 0x45, 0xEC, 0xE8, 0x37, 0xA3, 0xFC, 0xFF, 0xE8, 0x8E, 0x96, 0xF9, 0xFF, 0x8B, 0x03, 0xBA, 0xA8, 0xF5, 0x5C, 0x00, 0xE8, 0x2A, 0xBD, 0xEC, 0xFF, 0x8B, 0x03, 0x83, 0xC0, 0x50, 0xBA, 0xC4 }, "NaN" },   // Cheat Engine 5.4 
	{ 0x5FECF4, { 0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xEC, 0x53, 0x33, 0xC0, 0x89, 0x45, 0xEC, 0xB8, 0xE4, 0xE4, 0x5F, 0x00, 0xE8, 0x9E, 0x89, 0xE0, 0xFF, 0x8B, 0x1D, 0xEC, 0x62, 0x60, 0x00, 0x33, 0xC0, 0x55, 0x68 }, "NaN" },   // Cheat Engine 5.5
	{ 0x5FECF4, { 0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xEC, 0x53, 0x33, 0xC0, 0x89, 0x45, 0xEC, 0xB8, 0xE4, 0xE4, 0x5F, 0x00, 0xE8, 0x9E, 0x89, 0xE0, 0xFF, 0x8B, 0x1D, 0xEC, 0x62, 0x60, 0x00, 0x33, 0xC0, 0x55, 0x68 }, "NaN" },   // Cheat Engine 5.5
	{ 0x5FED5B, { 0xE8, 0x10, 0xC3, 0xE9, 0xFF, 0x8B, 0x0D, 0x64, 0x5D, 0x60, 0x00, 0x8B, 0x03, 0x8B, 0x15, 0x00, 0x1D, 0x55, 0x00, 0xE8, 0xFD, 0xC2, 0xE9, 0xFF, 0x8B, 0x0D, 0xC8, 0x5E, 0x60, 0x00, 0x8B, 0x03 }, "NaN" },   // Cheat Engine 5.5
	{ 0x12C5B8, { 0x75, 0x07, 0x8B, 0x1E, 0x83, 0xEE, 0xFC, 0x11, 0xDB, 0x72, 0xED, 0xB8, 0x01, 0x00, 0x00, 0x00, 0x01, 0xDB, 0x75, 0x07, 0x8B, 0x1E, 0x83, 0xEE, 0xFC, 0x11, 0xDB, 0x11, 0xC0, 0x01, 0xDB, 0x73 }, "NaN" },   // UoPilot
	{ 0x401414, { 0x68, 0xA4, 0x22, 0x40, 0x00, 0xE8, 0xEE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x8E, 0xF7, 0x08 }, "NaN" },   // Speed Hack 99.62t
	{ 0x401E04, { 0x68, 0x28, 0x20, 0x41, 0x00, 0xE8, 0xEE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE3, 0x90, 0x67, 0x9A }, "NaN" },   // SpotHack 1.1
	{ 0x454181, { 0xBE, 0x00, 0x90, 0x43, 0x00, 0x8D, 0xBE, 0x00, 0x80, 0xFC, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB, 0x75 }, "NaN" },   // MJB Perfect DL Bot
	{ 0x59F001, { 0xE8, 0x00, 0x00, 0x00, 0x00, 0x5D, 0x50, 0x51, 0xEB, 0x0F, 0xB9, 0xEB, 0x0F, 0xB8, 0xEB, 0x07, 0xB9, 0xEB, 0x0F, 0x90, 0xEB, 0x08, 0xFD, 0xEB, 0x0B, 0xF2, 0xEB, 0xF5, 0xEB, 0xF6, 0xF2, 0xEB }, "NaN" },   // HahaMu 1.16
	{ 0x40FBB6, { 0x55, 0x8B, 0xEC, 0x6A, 0xFF, 0x68, 0x48, 0x3D, 0x41, 0x00, 0x68, 0x3C, 0xFD, 0x40, 0x00, 0x64, 0xA1, 0x00, 0x00, 0x00, 0x00, 0x50, 0x64, 0x89, 0x25, 0x00, 0x00, 0x00, 0x00, 0x83, 0xEC, 0x68 }, "NaN" },   // Game Speed Changer
	{ 0x438510, { 0x60, 0xBE, 0x00, 0x20, 0x42, 0x00, 0x8D, 0xBE, 0x00, 0xF0, 0xFD, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB }, "NaN" },   // eXpLoRer
	{ 0x4BCFA4, { 0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xF0, 0x53, 0x56, 0x57, 0xB8, 0xC4, 0xCC, 0x4B, 0x00, 0xE8, 0xB1, 0x9B, 0xF4, 0xFF, 0x8B, 0x3D, 0xB0, 0x03, 0x4C, 0x00, 0x68, 0xDC, 0xD0, 0x4B, 0x00, 0x6A, 0x04 }, "NaN" },   // Xelerator 1.4
	{ 0x473BBC, { 0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xF4, 0xB8, 0x04, 0x3A, 0x47, 0x00, 0xE8, 0xE0, 0x26, 0xF9, 0xFF, 0xA1, 0x1C, 0x5C, 0x47, 0x00, 0x8B, 0x00, 0xE8, 0x04, 0xBE, 0xFC, 0xFF, 0x8B, 0x0D, 0xE4, 0x5C }, "NaN" },   // Capotecheat(deltacholl)
	{ 0x55DE8C, { 0x87, 0xDE, 0xF7, 0xFA, 0x9F, 0xCA, 0x05, 0x5D, 0x83, 0x67, 0x02, 0x86, 0x59, 0xBF, 0xF1, 0xB6, 0x5B, 0x1F, 0x04, 0x6E, 0x79, 0x00, 0x18, 0x57, 0x8A, 0xD0, 0xA6, 0xFA, 0x8E, 0x5A, 0xE0, 0xD8 }, "NaN" },   // Cheat4Fun v0.9 Beta
	{ 0x493C90, { 0x60, 0xBE, 0x00, 0xC0, 0x45, 0x00, 0x8D, 0xBE, 0x00, 0x50, 0xFA, 0xFF, 0x57, 0xEB, 0x0B, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB, 0x75, 0x07, 0x8B, 0x1E, 0x83, 0xEE, 0xFC, 0x11 }, "NaN" },   // AutoBuff D-C
	{ 0x416014, { 0xB8, 0x00, 0x00, 0x00, 0x00, 0x60, 0x0B, 0xC0, 0x74, 0x68, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x58, 0x05, 0x53, 0x00, 0x00, 0x00, 0x80, 0x38, 0xE9, 0x75, 0x13, 0x61, 0xEB, 0x45, 0xDB, 0x2D, 0x37 }, "NaN" },   // HastyMu v0.1
	{ 0x416014, { 0xB8, 0x00, 0x00, 0x00, 0x00, 0x60, 0x0B, 0xC0, 0x74, 0x68, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x58, 0x05, 0x53, 0x00, 0x00, 0x00, 0x80, 0x38, 0xE9, 0x75, 0x13, 0x61, 0xEB, 0x45, 0xDB, 0x2D, 0x37 }, "NaN" },   // HastyMu v0.2
	{ 0x401704, { 0x68, 0x84, 0x24, 0x40, 0x00, 0xE8, 0xEE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x72, 0x80, 0x61, 0xF6 }, "NaN" },   // MuPie HG v2
	{ 0x401B28, { 0x68, 0xD8, 0x2A, 0x40, 0x00, 0xE8, 0xF0, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB9, 0xE3, 0x0E, 0xC3 }, "NaN" },   // MuPie HG v3
	{ 0x48C000, { 0xFC, 0xCF, 0xAB, 0xE7, 0x6D, 0x3A, 0x89, 0xBC, 0xB2, 0x9F, 0x73, 0x23, 0xA8, 0xFE, 0xB6, 0x49, 0x5D, 0x39, 0x5D, 0x8A, 0xCB, 0x63, 0x8D, 0xEA, 0x7D, 0x2B, 0x5F, 0xC3, 0xB1, 0xE9, 0x83, 0x29 }, "NaN" },   // Lipsum v1
	{ 0x48C000, { 0xFC, 0xCF, 0xAB, 0xE7, 0x6D, 0x3A, 0x89, 0xBC, 0xB2, 0x9F, 0x73, 0x23, 0xA8, 0xFE, 0xB6, 0x49, 0x5D, 0x39, 0x5D, 0x8A, 0xCB, 0x63, 0x8D, 0xEA, 0x7D, 0x2B, 0x5F, 0xC3, 0xB1, 0xE9, 0x83, 0x29 }, "NaN" },   // Lipsum v2
	{ 0xAF4014, { 0xB8, 0x00, 0x00, 0x00, 0x00, 0x60, 0x0B, 0xC0, 0x74, 0x68, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x58, 0x05, 0x53, 0x00, 0x00, 0x00, 0x80, 0x38, 0xE9, 0x75, 0x13, 0x61, 0xEB, 0x45, 0xDB, 0x2D, 0x37 }, "NaN" },   // FunnyZhyper v5
	{ 0x4380F0, { 0x53, 0x00, 0x5F, 0x00, 0x56, 0x00, 0x45, 0x00, 0x52, 0x00, 0x53, 0x00, 0x49, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x5F, 0x00, 0x49, 0x00, 0x4E, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x00, 0x00, 0x00, 0x00 }, "NaN" },   // MuPie v2 Beta
	{ 0x453180, { 0x60, 0xBE, 0x00, 0x80, 0x43, 0x00, 0x8D, 0xBE, 0x00, 0x90, 0xFC, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB }, "NaN" },   // Auto_Buff v5 Hack Rat
	{ 0x454180, { 0x60, 0xBE, 0x00, 0x80, 0x43, 0x00, 0x8D, 0xBE, 0x00, 0x90, 0xFC, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB }, "NaN" },   // Auto_Buff v9 Hack Rat
	{ 0x405110, { 0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xEC, 0x53, 0x56, 0x33, 0xC0, 0x89, 0x45, 0xEC, 0xA1, 0xAC, 0x60, 0x40, 0x00, 0xC6, 0x00, 0x01, 0xB8, 0xD0, 0x50, 0x40, 0x00, 0xE8, 0x69, 0xEE, 0xFF, 0xFF, 0x8B }, "NaN" },   // Minimizer
	{ 0x453180, { 0x60, 0xBE, 0x00, 0x80, 0x43, 0x00, 0x8D, 0xBE, 0x00, 0x90, 0xFC, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB }, "NaN" },   // AE/HYBRID AEBOT 0.9
	{ 0x48A220, { 0x60, 0xBE, 0x00, 0xA0, 0x45, 0x00, 0x8D, 0xBE, 0x00, 0x70, 0xFA, 0xFF, 0x57, 0xEB, 0x0B, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB, 0x75, 0x07, 0x8B, 0x1E, 0x83, 0xEE, 0xFC, 0x11 }, "NaN" },   // MU-SS4 Speed Hack 1.2
	{ 0x47A1C0, { 0x60, 0xBE, 0x00, 0xF0, 0x45, 0x00, 0x8D, 0xBE, 0x00, 0x20, 0xFA, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB }, "NaN" },   // Bot MG-DK-ELF
	{ 0x47A1C0, { 0x60, 0xBE, 0x00, 0xF0, 0x45, 0x00, 0x8D, 0xBE, 0x00, 0x20, 0xFA, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB }, "NaN" },   // Comercio Bot
	{ 0x455180, { 0x60, 0xBE, 0x00, 0xA0, 0x43, 0x00, 0x8D, 0xBE, 0x00, 0x70, 0xFC, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB }, "NaN" },   // Dizzys Auto Buff
	{ 0x401344, { 0xEB, 0x10, 0x66, 0x62, 0x3A, 0x43, 0x2B, 0x2B, 0x48, 0x4F, 0x4F, 0x4B, 0x90, 0xE9, 0x98, 0x00, 0x47, 0x00, 0xA1, 0x8B, 0x00, 0x47, 0x00, 0xC1, 0xE0, 0x02, 0xA3, 0x8F, 0x00, 0x47, 0x00, 0x52 }, "NaN" },   // GodMode
	{ 0x435000, { 0x60, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x5D, 0x50, 0x51, 0xEB, 0x0F, 0xB9, 0xEB, 0x0F, 0xB8, 0xEB, 0x07, 0xB9, 0xEB, 0x0F, 0x90, 0xEB, 0x08, 0xFD, 0xEB, 0x0B, 0xF2, 0xEB, 0xF5, 0xEB, 0xF6, 0xF2 }, "NaN" },   // Mu Cheater 16
	{ 0x401318, { 0x68, 0xA4, 0x1F, 0x40, 0x00, 0xE8, 0xEE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEC, 0x82, 0xBE, 0x15 }, "NaN" },   // MU Utilidades
	{ 0x4441C0, { 0x60, 0xBE, 0x00, 0x00, 0x43, 0x00, 0x8D, 0xBE, 0x00, 0x10, 0xFD, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB }, "NaN" },   // MuBot
	{ 0x481870, { 0x60, 0xBE, 0x00, 0x30, 0x45, 0x00, 0x8D, 0xBE, 0x00, 0xE0, 0xFA, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB }, "NaN" },   // Snd Bot 1.5
	{ 0x401E04, { 0x68, 0x28, 0x20, 0x41, 0x00, 0xE8, 0xEE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE3, 0x90, 0x67, 0x9A }, "NaN" },   // SpotHack 1.1
	{ 0x534000, { 0x8D, 0x8D, 0x51, 0x2E, 0x40, 0x00, 0x50, 0x51, 0x50, 0xFF, 0x95, 0xC7, 0x2C, 0x40, 0x00, 0x89, 0x85, 0x61, 0x2E, 0x40, 0x00, 0x58, 0x8D, 0x8D, 0x0F, 0x2E, 0x40, 0x00, 0x51, 0x50, 0xFF, 0x95 }, "NaN" },   // Godlike (Magic Shield)
	{ 0x555030, { 0x74, 0x37, 0x8D, 0x85, 0xFB, 0x2C, 0x40, 0x00, 0x50, 0xFF, 0x95, 0xD7, 0x2C, 0x40, 0x00, 0x8D, 0x8D, 0x51, 0x2E, 0x40, 0x00, 0x50, 0x51, 0x50, 0xFF, 0x95, 0xC7, 0x2C, 0x40, 0x00, 0x89, 0x85 }, "NaN" },   // Godlike
	{ 0x401462, { 0xE8, 0xD3, 0x16, 0x0E, 0x00, 0x8B, 0xD0, 0xE8, 0x8A, 0x67, 0x0D, 0x00, 0x5A, 0xE8, 0xE8, 0x66, 0x0D, 0x00, 0xE8, 0xBF, 0x67, 0x0D, 0x00, 0x6A, 0x00, 0xE8, 0xC4, 0x7B, 0x0D, 0x00, 0x59, 0x68 }, "NaN" },   // Mu Philiphinas Cheat II
	{ 0x401000, { 0xB8, 0x44, 0xFF, 0x41, 0x00, 0x50, 0x64, 0xFF, 0x35, 0x00, 0x00, 0x00, 0x00, 0x64, 0x89, 0x25, 0x00, 0x00, 0x00, 0x00, 0x33, 0xC0, 0x89, 0x08, 0x50, 0x45, 0x43, 0x6F, 0x6D, 0x70, 0x61, 0x63 }, "NaN" },   // ZhyperMu Packet Editor
	{ 0x496CA0, { 0x60, 0xBE, 0x00, 0x50, 0x46, 0x00, 0x8D, 0xBE, 0x00, 0xC0, 0xF9, 0xFF, 0xC7, 0x87, 0xA8, 0x50, 0x07, 0x00, 0x95, 0x01, 0xA9, 0x0C, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x0E, 0x90, 0x90, 0x90, 0x90 }, "NaN" },   // D-C DupeHack 1.0
	{ 0x499190, { 0x60, 0xBE, 0x00, 0x30, 0x46, 0x00, 0x8D, 0xBE, 0x00, 0xE0, 0xF9, 0xFF, 0x57, 0xEB, 0x0B, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB, 0x75, 0x07, 0x8B, 0x1E, 0x83, 0xEE, 0xFC, 0x11 }, "NaN" },   // Auto Combo
	{ 0x470B74, { 0x55, 0x8B, 0xEC, 0x83, 0xC4, 0xF0, 0xB8, 0x3C, 0x09, 0x47, 0x00, 0xE8, 0xEC, 0x53, 0xF9, 0xFF, 0xA1, 0x44, 0x2A, 0x47, 0x00, 0x8B, 0x00, 0xE8, 0xF8, 0x34, 0xFE, 0xFF, 0xA1, 0x44, 0x2A, 0x47 }, "NaN" },   // AIO Bots (Collection)
	{ 0x6B5000, { 0x60, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x5D, 0x50, 0x51, 0x0F, 0xCA, 0xF7, 0xD2, 0x9C, 0xF7, 0xD2, 0x0F, 0xCA, 0xEB, 0x0F, 0xB9, 0xEB, 0x0F, 0xB8, 0xEB, 0x07, 0xB9, 0xEB, 0x0F, 0x90, 0xEB, 0x08 }, "NaN" },    // Nsauditor 1.9.1 (Packet Tool)
	{ 0x4691A0, { 0x60, 0xBE, 0x00, 0xE0, 0x44, 0x00, 0x8D, 0xBE, 0x00, 0x30, 0xFB, 0xFF, 0x57, 0x83, 0xCD, 0xFF, 0xEB, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8A, 0x06, 0x46, 0x88, 0x07, 0x47, 0x01, 0xDB }, "NaN" },     // Super Bot
	{ 0x6AF728, { 0xE9, 0x66, 0xB9, 0xFB, 0xFF, 0xB1, 0xB0, 0xB3, 0xAA, 0xF3, 0x45, 0x2E, 0x25, 0xC8, 0x07, 0x04, 0x5D, 0x26, 0xC5, 0x74, 0x67, 0x8E, 0xE8, 0xE5, 0xFF, 0xFF, 0xFF, 0xEB, 0x50, 0xED, 0x00, 0xCC }, "NaN" },	//DN‰ ¬¬¯yŠO•žA?•zVer.3.3
	{ 0x7BD343, { 0xF6, 0xF6, 0xD9, 0x70, 0x92, 0x2D, 0xCD, 0x4E, 0x5A, 0xAD, 0x8B, 0xB1, 0x17, 0xE2, 0x76, 0xD4, 0x47, 0xB8, 0x35, 0x0C, 0x12, 0xCA, 0x68, 0xFA, 0xF2, 0xD2, 0xB6, 0x45, 0x23, 0x68, 0xAF, 0xDB }, "NaN" },	//dngtdn hack
	{ 0x94DA50, { 0x43, 0x68, 0x61, 0x6E, 0x67, 0x65, 0x00, 0x00, 0x1B, 0x63, 0x62, 0x44, 0x69, 0x73, 0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x64, 0x53, 0x63, 0x61, 0x6E, 0x6E, 0x69, 0x6E, 0x67, 0x43, 0x68 }, "NaN" },  //CE
	{ 0x401082, { 0x83, 0x3D, 0x1B, 0x01, 0x4B, 0x00, 0x00, 0x73, 0x0A, 0xB8, 0xFE, 0x00, 0x00, 0x00, 0xE8, 0xD7, 0xFF, 0xFF, 0xFF, 0xB9, 0x9C, 0x00, 0x00, 0x00, 0x51, 0x6A, 0x08, 0xE8, 0xF4, 0xDF, 0x0A, 0x00 }, "NaN" },   //ollydbg 1.1
	{ 0x44E148, { 0xE8, 0xD9, 0x33, 0x00, 0x00, 0x89, 0x75, 0xD0, 0x8D, 0x45, 0xA4, 0x50, 0xFF, 0x15, 0x94, 0xD1, 0x46, 0x00, 0xE8, 0x42, 0x42, 0x00, 0x00, 0x89, 0x45, 0x9C, 0xF6, 0x45, 0xD0, 0x01, 0x74, 0x06 }, "NaN" }, //DN私服检测器1.4（2015年03月29日）by笑笑
	{ 0xEED1CE, { 0x8B, 0xD8, 0x05, 0xF0, 0xB6, 0xDF, 0x00, 0x81, 0xC3, 0xDC, 0x93, 0x50, 0x00, 0xEB, 0xDB, 0xEB, 0x08, 0x00, 0x50, 0x76, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEB, 0x2C, 0xBB, 0x2A, 0xB8, 0xDF, 0x2A }, "NaN" }, //DN笑笑私服版_B类拖曳版本2.0(20150802更新)
	{ 0x449B74, { 0xC3, 0xC3, 0xB8, 0xC9, 0xE8, 0x44, 0x00, 0xC7, 0x05, 0x3C, 0x52, 0x48, 0x00, 0x73, 0xE5, 0x44, 0x00, 0xA3, 0x38, 0x52, 0x48, 0x00, 0xC7, 0x05, 0x40, 0x52, 0x48, 0x00, 0xD9, 0xE5, 0x44, 0x00 }, "NaN" }, //取龙之谷IP-BY笑笑出品2.0.exe
	{ 0x0118C168, { 0xEB, 0x08, 0x00, 0x20, 0xB3, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE9, 0x1E, 0xFE, 0xFF, 0xFF, 0xA9, 0xC8, 0x6B, 0x82, 0x3D, 0x0C, 0x66, 0xF7, 0xDD, 0x66, 0x8B, 0x6C, 0x24, 0x03, 0xF6, 0xD7, 0xBF }, "NaN" }, //DN笑笑私服D类1.6(20150817更新)(支持欢乐龙之谷)
	{ 0x00DBA36A, { 0xEB, 0x08, 0x00, 0xD0, 0x6B, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE9, 0x48, 0xFA, 0xFF, 0xFF, 0xB6, 0xA1, 0xE0, 0x23, 0x5A, 0x66, 0x87, 0x0C, 0x24, 0xF6, 0xDA, 0x0F, 0x31, 0x8B, 0x44, 0x24, 0x02 }, "NaN" }, //DN笑笑私服B类2.2(20150802更新)(原未来80EX龙玉版1226)
	{ 0x004920C2, { 0xD7, 0x20, 0x95, 0x31, 0x82, 0x9E, 0x61, 0x6A, 0x7E, 0xCA, 0xEA, 0x96, 0x4C, 0x2D, 0xE1, 0x5D, 0xB4, 0x6A, 0x90, 0x55, 0x19, 0xB2, 0x8B, 0xC1, 0x70, 0xBB, 0xD4, 0x29, 0xE6, 0xDC, 0x68, 0xDD }, "NaN" }, //DN笑笑私服版_笑笑谷EX版0724(修复回关卡功能)
	{ 0x00F0455D, { 0x8B, 0xFD, 0x66, 0xBF, 0xCD, 0x66, 0x66, 0x89, 0x74, 0x24, 0x14, 0x83, 0xC4, 0x16, 0x8D, 0x7B, 0xA2, 0xFC, 0xEB, 0xD6, 0xF8, 0x0F, 0xBD, 0xFA, 0xE8, 0x3E, 0x00, 0x00, 0x00, 0xC8, 0x51, 0xC1 }, "NaN" }, //DN笑笑私服版_B类拖曳版本3.6(20160121更新).exe
	{ 0x00D1D20F, { 0x83, 0xEC, 0x16, 0xEB, 0xD4, 0xF6, 0xE1, 0x20, 0x63, 0x9A, 0xF5, 0x0F, 0xA3, 0xC5, 0x89, 0x6C, 0x24, 0x0E, 0x89, 0x44, 0x24, 0x12, 0x8A, 0x54, 0x24, 0x1C, 0x0F, 0x93, 0xC0, 0x87, 0x54, 0x24 }, "NaN" }, //DN笑笑私服C类1.0(0301更新)(原光怒或173版).exe
	{ 0x00DAF2F2, { 0xF7, 0x8B, 0x3C, 0x24, 0x8B, 0x3C, 0x24, 0xBA, 0xF0, 0x1A, 0xF1, 0xC2, 0x66, 0x8B, 0xFD, 0xF9, 0x0F, 0x31, 0xEB, 0xD7, 0xC1, 0xD0, 0x1B, 0x86, 0x14, 0x24, 0xBF, 0x35, 0x9A, 0x3E, 0x71, 0x8A }, "NaN"}, //DN笑笑私服A类1.1(0331更新)(原GT0922龙玉版).exe
	{ 0x00E53179, { 0x8D, 0x64, 0x24, 0x05, 0x66, 0x87, 0x5C, 0x24, 0x02, 0x8A, 0x74, 0x24, 0x01, 0xEB, 0xD4, 0xF0, 0x68, 0xFE, 0x99, 0x68, 0xDF, 0x1E, 0x85, 0x15, 0x7C, 0x8F, 0x0A, 0xB4, 0xA7, 0xCE, 0x59, 0xB8 }, "NaN" }, //DN笑笑私服B类Home呼出版3.5(20160121更新)(原未来80EX龙玉版1226)
	{ 0x00DE6D56, { 0xBD, 0x75, 0x84, 0x3A, 0xCB, 0xFC, 0x86, 0xB2, 0xA8, 0xA7, 0x82, 0x4D, 0x57, 0x58, 0x20, 0xE0, 0xBB, 0x75, 0xF7, 0xDB, 0x96, 0x9F, 0x57, 0x45, 0xDC, 0xD3, 0xB9, 0xBA, 0x23, 0x2C, 0xBB, 0x7B}, "NaN" }, //DN笑笑私服版_笑笑谷EX版0724(修复回关卡功能)
	{ 0x007180E2, { 0x90, 0x5E, 0xFF, 0xA7, 0x1C, 0x6A, 0x0B, 0x09, 0xE8, 0x87, 0x03, 0xC9, 0xBC, 0x2A, 0xD0, 0x69, 0xCB, 0x1D, 0x0F, 0x22, 0xA7, 0x6C, 0xA7, 0x7D, 0xC7, 0x2B, 0xF4, 0x18, 0xA5, 0x55, 0xAA, 0xE8 }, "NaN" }, //tuoji_80ex_D1.exe
	{ 0x00839FB6, { 0x27, 0x71, 0x9A, 0x4B, 0x5A, 0x81, 0xE0, 0xFB, 0x0D, 0x6E, 0xA0, 0x1E, 0x43, 0xF0, 0xAD, 0x54, 0x7A, 0xF9, 0xCC, 0x88, 0xCB, 0xFD, 0xB3, 0xB2, 0x23, 0x07, 0x89, 0x7F, 0x0D, 0x42, 0x32, 0x91 }, "NaN"}  //tuoji_80ex_D1.exe
};



void SystemProcessesScan() {
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 pe32;
		pe32.dwSize = sizeof(PROCESSENTRY32);

		if (Process32First(hProcessSnap, &pe32))
		{
			do
			{
				HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
				if (hProcess != NULL)
				{
					if (ScanProcessMemory(hProcess))
					{
						//VIRTUALIZER_DOLPHIN_WHITE_START
						//HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);  // Close detected process
						TerminateProcess(hProcess, NULL);
						
						Sleep(300);
						DWORD exitCode = 0;
						if (GetExitCodeProcess(hProcess, &exitCode) == FALSE)
						{
							/*security s;
							//VIRTUALIZER_DOLPHIN_WHITE_START
								s.crash();
							//VIRTUALIZER_DOLPHIN_WHITE_END
							ExitProcess(0);*/
						}
						//VIRTUALIZER_DOLPHIN_WHITE_END
						if (exitCode != STILL_ACTIVE)
						{
#ifdef DEBUG_
//							Finalize_OpenPage();
							MessageBoxA(NULL, "Antihack , process was successfully terminated.\nYou can play.", "Memory Scanner", MB_OK);
#endif
							break;
						}
						else{
#ifdef DEBUG_
							MessageBoxA(NULL, "Cannot kill hack process.", "Memory Scanner", MB_OK);
#endif
							Finalize_OpenPage(pe32.szExeFile);
							//security s;
							//VIRTUALIZER_DOLPHIN_WHITE_START
								s.crash();
							//VIRTUALIZER_DOLPHIN_WHITE_END
							ExitProcess(0);
						

						}
						
						
#ifdef DEBUG_
						char buff[128];
						wsprintf(buff, "Hack detected No. %d PiD. %d", last_Hack, pe32.th32ProcessID);
						MessageBoxA(NULL, buff, "error", MB_OK);
#endif
						//ExitProcess(0);
						

					}
				}
			} while (Process32Next(hProcessSnap, &pe32));
		}
	}

	CloseHandle(hProcessSnap);
}

bool ScanProcessMemory(HANDLE hProcess)
{
	for (int i = 0; i < MAX_PROCESS_DUMP; i++)
	{
		char aTmpBuffer[MAX_DUMP_SIZE];
		SIZE_T aBytesRead = 0;
		ReadProcessMemory(hProcess, (LPCVOID)g_ProcessesDumps[i].m_aOffset, (LPVOID)aTmpBuffer, sizeof(aTmpBuffer), &aBytesRead);

		if (memcmp(aTmpBuffer, g_ProcessesDumps[i].m_aMemDump, MAX_DUMP_SIZE) == 0)
		{
			last_Hack = i;
			return true;
			break;
		}
	}
	return false;
}

void Antihack_MainThread()
{
again:
	SystemProcessesScan();
	Sleep(350);
	goto again;
}


void MemoryScanner()
{
	SystemProcessesScan();
}


#ifdef _MANAGED
#pragma managed(pop)
#endif

