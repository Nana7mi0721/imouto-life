
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_0057d0c0(void)

{
  short sVar1;
  double dVar2;
  double dVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  wchar_t *pwVar7;
  HMODULE hModule;
  FARPROC pFVar8;
  undefined *puVar9;
  undefined *puVar10;
  short sVar11;
  int unaff_ESI;
  undefined4 *puVar12;
  undefined4 unaff_EDI;
  undefined4 *puVar13;
  longlong lVar14;
  uint uVar15;
  longlong lVar16;
  undefined8 uVar17;
  int *piVar18;
  undefined **ppuVar19;
  undefined1 *puVar20;
  undefined1 auStack_752 [14];
  undefined4 uStack_72c;
  wchar_t *local_724;
  uint local_720;
  undefined *local_71c;
  undefined *local_718;
  int local_714 [4];
  undefined4 *puStack_704;
  undefined4 uStack_700;
  uint uStack_6fc;
  int iStack_6f8;
  undefined4 uStack_6f4;
  uint uStack_6e8;
  uint uStack_6e4;
  uint uStack_6e0;
  int iStack_6dc;
  undefined4 uStack_6d8;
  int iStack_6a4;
  int iStack_6a0;
  undefined4 auStack_688 [3];
  int iStack_67c;
  undefined1 auStack_660 [256];
  undefined1 auStack_560 [256];
  undefined2 uStack_460;
  ushort uStack_32;
  uint uStack_20;
  
  if (DAT_00aa4270 != (int *)0x0) {
    return 0xffffffff;
  }
LAB_0057d0f0:
  while (DAT_00a83c5c != 0) {
    if ((DAT_00a83c5c < 1) || (2 < DAT_00a83c5c)) goto LAB_0057d8e8;
    DAT_00aa4fa0 = 0;
    FUN_0056bb10();
    iVar5 = (*DAT_00aba190)();
    if (iVar5 < 0) goto code_r0x0057d13b;
    iVar5 = (*DAT_00aba190)();
    if (-1 < iVar5) {
      piVar18 = &uStack_72c;
      iVar5 = (*DAT_00aba190)();
      if (iVar5 < 0) {
        FUN_0056bb10();
        FUN_0055e710();
        return 0xffffffff;
      }
      iVar5 = (**(code **)*piVar18)();
      if (iVar5 < 0) {
        (**(code **)(_DAT_00000000 + 8))();
        FUN_0056bb10(&PTR_LAB_007d9290);
        FUN_0055e710();
        return 0xffffffff;
      }
      FUN_0056d380();
      auStack_688[0] = 0x134;
      lVar16 = ZEXT48(auStack_688) << 0x20;
      iVar5 = 0;
      lVar14 = 0x10057d568;
      iVar6 = (**(code **)(CONCAT13(DAT_00000004,DAT_00000000_1) + 0xc))();
      while (iVar6 != 1) {
        uVar15 = (uint)((ulonglong)lVar14 >> 0x20);
        FUN_0056cf70(auStack_560,0x106,auStack_660,uVar15,lVar16);
        uStack_460 = 0;
        pwVar7 = L"Output port";
        if (iStack_67c != 1) {
          pwVar7 = L"Input port";
        }
        FUN_0056bc50(L"%s  Device%d:%s ",pwVar7,iVar5,auStack_560);
        lVar14 = (ulonglong)uVar15 << 0x20;
        iVar5 = iVar5 + 1;
        iVar6 = (**(code **)(unaff_ESI + 0xc))(auStack_752 + 0x16,iVar5);
      }
      (**(code **)(unaff_ESI + 8))(auStack_752 + 0x16);
      (**(code **)(*piVar18 + 8))(piVar18);
      FUN_0056d380(auStack_752 + 0x1a,0,0x28);
      unaff_EDI = 0x28;
      local_724 = (wchar_t *)0xac44;
      uStack_72c = 0x3f;
      DAT_00aa4270 = (int *)0x0;
      iVar5 = (**(code **)(*DAT_00aa4250 + 0xb0))
                        (DAT_00aa4250,auStack_752 + -0xe,&DAT_00aa4270,0,
                         (-(uint)(DAT_00a83c5c != 2) & 0xfffffff9) + 8,0x40,0x3f,auStack_752 + 0x1a)
      ;
      if (iVar5 != 0) {
        FUN_0056bb10(&PTR_LAB_007d91e8);
        FUN_0055e710();
        return 0xffffffff;
      }
      (**(code **)(*DAT_00aa4250 + 0x84))(DAT_00aa4250,&DAT_0085ee24,&DAT_00a83c60,4);
LAB_0057d8e8:
      if (DAT_00aa4fa0 != 0) {
        if (DAT_00aa4254 == (HMODULE)0x0) {
          (**(code **)(*DAT_00aa4270 + 0x10))();
          FUN_0056bfd0();
          FUN_0056bc50();
          FUN_0056bca0();
          FUN_0056bca0();
          FUN_0056bca0();
          FUN_0056bfe0();
          DAT_00a834f4 = (uint)uStack_32;
          DAT_00aa4f2c = uStack_20;
        }
        else {
          (**(code **)(*DAT_00aa4f20 + 0x4c))();
          DAT_00a834f4 = 0;
          iVar5 = 0;
          do {
            if ((DAT_00aa4f2c & 1 << ((byte)iVar5 & 0x1f)) != 0) {
              DAT_00a834f4 = DAT_00a834f4 + 1;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < 0x20);
        }
        (*DAT_00aa4268)();
        goto LAB_0057ddd6;
      }
      FUN_0056d380();
      local_71c = (undefined *)0x10001;
      local_718 = (undefined *)0x5622;
      local_714[1] = 0x100002;
      local_714[0] = 0xac44;
      FUN_0056d380();
      uStack_6fc = (local_714[1] & 0xffffU) * 9000;
      uStack_700 = (-(uint)(DAT_00aa4fa4 != 0) & 6) + 2 | 0x180e0;
      uStack_6f4 = &local_71c;
      puStack_704 = (undefined4 *)0x24;
      iVar5 = (**(code **)(*DAT_00aa4270 + 0xc))();
      if (iVar5 == 0) {
LAB_0057daf9:
        puVar20 = auStack_752 + 0x1a;
        ppuVar19 = &local_718;
        iVar5 = (**(code **)(*DAT_00aa4f9c + 0x2c))(DAT_00aa4f9c,0,local_714[2]);
        if (iVar5 != 0) {
          FUN_0056bb10(&DAT_007d8fd0);
          (**(code **)(*DAT_00aa4f9c + 8))(DAT_00aa4f9c);
          DAT_00aa4f9c = (int *)0x0;
        }
        FUN_0056d380(auStack_752 + 0x16,0,unaff_EDI);
        if (puVar20 != (undefined1 *)0x0) {
          FUN_0056d380(puVar20,0,ppuVar19);
        }
        (**(code **)(*DAT_00aa4f9c + 0x4c))
                  (DAT_00aa4f9c,auStack_752 + 0x16,unaff_EDI,puVar20,ppuVar19);
        (**(code **)(*DAT_00aa4f9c + 0x30))(DAT_00aa4f9c,0,0,1);
      }
      else {
        FUN_0056d380();
        local_714[2] = (local_720 & 0xffff) * 9000;
        puStack_704 = &uStack_72c;
        local_714[1] = (-(uint)(DAT_00aa4fa4 != 0) & 6) + 2 | 0xc0;
        local_714[0] = 0x24;
        iVar5 = (**(code **)(*DAT_00aa4270 + 0xc))();
        if (iVar5 == 0) goto LAB_0057daf9;
        FUN_0056bb10();
        DAT_00aa4f9c = (int *)0x0;
      }
      if (DAT_00aa4270 != (int *)0x0) {
        FUN_0056bfd0();
        FUN_0056d380();
        uStack_6d8 = 0x60;
        (**(code **)(*DAT_00aa4270 + 0x10))();
        FUN_0056bb10();
        FUN_0056bfd0();
        hModule = LoadLibraryA("DSound.DLL");
        if (hModule != (HMODULE)0x0) {
          pFVar8 = GetProcAddress(hModule,"DirectSoundEnumerateW");
          if (pFVar8 != (FARPROC)0x0) {
            (*pFVar8)();
            FUN_0056bfe0();
            dVar2 = (double)(int)uStack_6e0;
            if ((int)uStack_6e0 < 0) {
              dVar2 = dVar2 + _DAT_007d49f0;
            }
            dVar3 = (double)iStack_6dc;
            if (iStack_6dc < 0) {
              dVar3 = dVar3 + _DAT_007d49f0;
            }
            FUN_0056bca0(&DAT_007d8ea8,dVar3 / _DAT_007d1010,dVar2 / _DAT_007d1010);
            dVar2 = (double)iStack_6a0;
            if (iStack_6a0 < 0) {
              dVar2 = dVar2 + _DAT_007d49f0;
            }
            dVar3 = (double)iStack_6a4;
            if (iStack_6a4 < 0) {
              dVar3 = dVar3 + _DAT_007d49f0;
            }
            FUN_0056bca0(&DAT_007d8e58,dVar3 * _DAT_007d62c0,dVar2 * _DAT_007d62c0);
            FUN_0056bb10(&DAT_007d8e38);
            FUN_0056bc50();
            puVar10 = &DAT_007d8e30;
            if ((uStack_6e4 & 0x400) == 0) {
              puVar10 = &DAT_007d8e28;
            }
            puVar9 = &DAT_007d8e30;
            if ((uStack_6e4 & 0x800) == 0) {
              puVar9 = &DAT_007d8e28;
            }
            uVar17 = CONCAT44(puVar10,puVar9);
            pwVar7 = L"  Secondary  16bit = %s  8bit = %s \n";
            FUN_0056bc50();
            FUN_0056bb10(&DAT_007d8d74,pwVar7,uVar17);
            FUN_0056bc50();
            FUN_0056bc50();
            FUN_0056bfe0();
            FreeLibrary(hModule);
            goto LAB_0057ddd6;
          }
          FreeLibrary(hModule);
        }
        FUN_0056bb10();
        FUN_0056bfe0();
        FUN_0056bfe0();
      }
LAB_0057ddd6:
      puVar12 = &DAT_007d8570;
      puVar13 = &DAT_00aa4f44;
      for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar13 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar13 = puVar13 + 1;
      }
      _DAT_00aa4f7c = 0;
      _DAT_00aa4f80 = 0;
      _DAT_00aa4f84 = 0;
      _DAT_00aa4f88 = 0;
      _DAT_00aa4f8c = 0;
      _DAT_00aa4f90 = 0;
      _DAT_00aa4f64 = 0;
      _DAT_00aa4f68 = 0;
      _DAT_00aa4f6c = 0x3f800000;
      _DAT_00aa4f74 = 0x3f800000;
      _DAT_00aa4f70 = 0;
      _DAT_00aa4f78 = 0;
      _DAT_00aa4f94 = &DAT_00aa4f44;
      return 0;
    }
    if (DAT_00aa424c != (int *)0x0) {
      (**(code **)(*DAT_00aa424c + 8))();
      DAT_00aa424c = (int *)0x0;
    }
    FUN_0056bb10();
    DAT_00a83c5c = 0;
  }
  if (DAT_00aa4fa0 == 0) {
    FUN_0056bb10();
    FUN_0056bb10();
    iVar5 = (*DAT_00aba190)();
    if (iVar5 < 0) {
      DAT_00aa4270 = (int *)0x0;
      FUN_0056bb10();
      return 0xffffffff;
    }
    FUN_0056bb10();
    FUN_0056bb10();
    iVar5 = (**(code **)(*DAT_00aa4270 + 0x28))();
    if (iVar5 < 0) {
      FUN_0056bb10();
      FUN_0056bc00(&DAT_007d9494);
    }
    else {
      FUN_0056bb10();
      iVar5 = *DAT_00aa4270;
      GetDesktopWindow();
      iVar5 = (**(code **)(iVar5 + 0x18))(DAT_00aa4270);
      if (iVar5 == 0) {
        FUN_0056d380(&local_720);
        local_71c = (undefined *)(-(uint)(DAT_00aa4fa4 != 0) & 8 | 1);
        local_720 = 0x24;
        iVar5 = (**(code **)(*DAT_00aa4270 + 0xc))();
        if (iVar5 == 0) {
          FUN_0056d380(&uStack_6e4);
          uStack_6e4 = 0x60;
          (**(code **)(*DAT_00aa4270 + 0x10))();
          sVar11 = ((uStack_6e8 & 2) != 0) + 1;
          uStack_6fc = uStack_6e0;
          if (0xac43 < uStack_6e0) {
            uStack_6fc = 0xac44;
          }
          sVar1 = ((uStack_6e8 & 8) != 0) + 1;
          FUN_0056d380(&uStack_700,0,0x12);
          uVar4 = sVar1 * sVar11;
          uStack_6f4 = (undefined **)CONCAT22(sVar1 * 8,uVar4);
          iStack_6f8 = uVar4 * uStack_6fc;
          uStack_700 = CONCAT22(sVar11,1);
          iVar5 = (**(code **)(*DAT_00aa4f98 + 0x38))();
          if (iVar5 != 0) {
            FUN_0056bb10();
          }
          goto LAB_0057d8e8;
        }
        FUN_0056bb10();
      }
      else {
        FUN_0056bb10();
      }
    }
    (**(code **)(*DAT_00aa4270 + 8))();
    DAT_00aa4270 = (int *)0x0;
    return 0xffffffff;
  }
  local_724 = L"X3DAudio1_7.dll";
  local_720 = 0;
  local_71c = &DAT_0085f0e4;
  local_718 = &DAT_0085f0f4;
  local_714[0] = 0;
  local_714[1] = 0;
  FUN_0056bb10();
  FUN_0056bfd0();
  DAT_00aa4254 = LoadLibraryW(L"XAudio2_8.dll");
  if (DAT_00aa4254 == (HMODULE)0x0) {
    FUN_0056bb10();
    iVar5 = 0;
    do {
      iVar6 = (*DAT_00aba190)();
      if (-1 < iVar6) break;
      iVar6 = iVar5 * 2;
      iVar5 = iVar5 + 1;
    } while (local_714[iVar6] != 0);
    if (local_714[iVar5 * 2 + -2] != 0) {
      FUN_0056bca0();
      FUN_0056bb10();
      iVar5 = (**(code **)(*DAT_00aa4270 + 0x14))();
      if (-1 < iVar5) {
        FUN_0056bb10();
        FUN_0056bb10();
        iVar5 = 0;
        pwVar7 = L"X3DAudio1_7.dll";
LAB_0057d3c0:
        DAT_00aa4264 = LoadLibraryW(pwVar7);
        if (DAT_00aa4264 == (HMODULE)0x0) goto code_r0x0057d3cc;
        FUN_0056bb10();
        DAT_00aa4268 = GetProcAddress(DAT_00aa4264,"X3DAudioInitialize");
        DAT_00aa426c = GetProcAddress(DAT_00aa4264,"X3DAudioCalculate");
        iVar5 = (**(code **)(*DAT_00aa4270 + 0x28))();
        if (-1 < iVar5) {
          iVar5 = 0;
          do {
            FUN_0057cb00();
            iVar5 = iVar5 + 0x34;
          } while (iVar5 < 0x618);
          goto LAB_0057d8e8;
        }
        FUN_0056bb10();
        if (DAT_00aa4264 != (HMODULE)0x0) {
          FreeLibrary(DAT_00aa4264);
          DAT_00aa4268 = (FARPROC)0x0;
          DAT_00aa426c = (FARPROC)0x0;
          DAT_00aa4264 = (HMODULE)0x0;
        }
        goto LAB_0057d46f;
      }
      FUN_0056bb10();
      FUN_0056bc00();
      goto LAB_0057d46f;
    }
    DAT_00aa4270 = (int *)0x0;
    FUN_0056bb10();
    DAT_00aa4fa0 = 0;
    goto LAB_0057d0f0;
  }
  FUN_0056bb10();
  DAT_00aa4258 = GetProcAddress(DAT_00aa4254,"XAudio2Create");
  _DAT_00aa425c = GetProcAddress(DAT_00aa4254,"CreateAudioVolumeMeter");
  DAT_00aa4260 = GetProcAddress(DAT_00aa4254,"CreateAudioReverb");
  DAT_00aa4268 = GetProcAddress(DAT_00aa4254,"X3DAudioInitialize");
  DAT_00aa426c = GetProcAddress(DAT_00aa4254,"X3DAudioCalculate");
  FUN_0056bb10();
  iVar5 = (*DAT_00aa4258)();
  if (iVar5 < 0) {
    FUN_0056bb10();
    FUN_0056bc00();
    (**(code **)(*DAT_00aa4270 + 8))();
    DAT_00aa4270 = (int *)0x0;
    DAT_00aa4fa0 = 0;
    goto LAB_0057d0f0;
  }
  FUN_0056bb10();
  iVar5 = (**(code **)(*DAT_00aa4270 + 0x1c))();
  if (-1 < iVar5) {
    puVar10 = &DAT_00aa488c;
    do {
      FUN_0057cd50();
      puVar10 = puVar10 + 0x38;
    } while ((int)puVar10 < 0xaa4f1c);
    goto LAB_0057d8e8;
  }
  FUN_0056bb10();
LAB_0057d46f:
  (**(code **)(*DAT_00aa4270 + 8))();
  DAT_00aa4270 = (int *)0x0;
  DAT_00aa4fa0 = 0;
  goto LAB_0057d0f0;
code_r0x0057d13b:
  FUN_0056bb10();
  FUN_0056bb10();
  DAT_00a83c5c = 0;
  goto LAB_0057d0f0;
code_r0x0057d3cc:
  pwVar7 = (wchar_t *)(&local_720)[iVar5];
  iVar5 = iVar5 + 1;
  if (pwVar7 == (LPCWSTR)0x0) goto code_r0x0057d3d7;
  goto LAB_0057d3c0;
code_r0x0057d3d7:
  FUN_0056bb10();
  goto LAB_0057d46f;
}

