
#pragma once

// �H�U�����w�q�n�D���̧C���O�C�n�D���̧C���O
// �O�㦳�������ε{���һݥ\�઺ Windows�BInternet Explorer �����~��
// �̦������C�z�L�b���w�����Χ�C���������O�W�ҥΩҦ��i�Ϊ��\��A�����i�H
// ���`�u�@�C

// �p�G�����n�w��C��H�U���w���������O�A�Эק�U�C�w�q�C
// �������P���O�����Ȫ��̷s��T�A�аѦ� MSDN�C
#ifndef WINVER                          // ���w�n�D���̧C���O�O Windows Vista
#define WINVER 0x0600           // �N���ȧ�אּ�������ȡA�H�A�Ω� Windows ����L�����C
#endif

#ifndef _WIN32_WINNT            // ���w�n�D���̧C���O�O Windows Vista�C
#define _WIN32_WINNT 0x0600     // �N���ȧ�אּ�������ȡA�H�A�Ω� Windows ����L�����C
#endif

#ifndef _WIN32_WINDOWS          // ���w�n�D���̧C���O�O Windows 98�C
#define _WIN32_WINDOWS 0x0410 // �N���ȧ�אּ�A���ȡA�H�A�Ω� Windows Me �Χ󰪪����C
#endif

#ifndef _WIN32_IE                   // ���w�n�D���̧C���O�O Internet Explorer 7.0�C
#define _WIN32_IE 0x0700        // �N���ȧ�אּ�������ȡA�H�A�Ω� IE ����L�����C
#endif

