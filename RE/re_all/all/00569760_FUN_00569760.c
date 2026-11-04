
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00569760(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  HMODULE pHVar6;
  wchar_t *lpLibFileName;
  int iVar7;
  undefined4 uVar8;
  HANDLE pvVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined1 auStack_230a [14];
  wchar_t *local_22fc [9];
  undefined1 local_22d8 [128];
  byte bStack_2258;
  undefined1 local_2000 [8188];
  undefined4 uStack_4;
  
  iVar5 = DAT_00a828c0;
  iVar4 = DAT_00a828bc;
  uVar3 = DAT_00a828a4;
  iVar2 = DAT_00a828a0;
  iVar1 = DAT_00a8289c;
  iVar10 = DAT_00a72b6c;
  iVar7 = DAT_00a72a64;
  uVar8 = DAT_00a72a60;
  uStack_4 = 0x56976a;
  if (DAT_00a828ac != (int *)0x0) {
    return 0;
  }
  if (DAT_00aaf10c != 0) {
    return 0;
  }
  DAT_00aaf10c = 1;
  FUN_0056d420(local_2000,&DAT_00a72b70,0x2000);
  FUN_0056d380(&DAT_00a72a60,0,0xfe68);
  DAT_00a72a60 = uVar8;
  DAT_00a72a64 = iVar7;
  DAT_00a72b6c = iVar10;
  DAT_00a8289c = iVar1;
  DAT_00a828a0 = iVar2;
  DAT_00a828a4 = uVar3;
  DAT_00a828bc = iVar4;
  DAT_00a828c0 = iVar5;
  FUN_0056d420(&DAT_00a72b70,local_2000,0x2000);
  DAT_00a828a8 = 1;
  if (DAT_00a828a0 == 0) {
    local_22fc[0] = L"xinput1_4.dll";
    local_22fc[1] = L"xinput1_3.dll";
    local_22fc[2] = L"xinput9_1_0.dll";
    local_22fc[3] = (wchar_t *)0x0;
    FUN_0056bb10(&PTR_LAB_007d772c);
    FUN_0056bfd0();
    if (DAT_00a8289c == 0) {
      FUN_0056bb10(&DAT_007d76a8);
      iVar10 = 0;
      lpLibFileName = L"xinput1_4.dll";
      pHVar6 = DAT_00a82890;
      do {
        DAT_00a82890 = pHVar6;
        DAT_00a82890 = LoadLibraryW(lpLibFileName);
        if (DAT_00a82890 != (HMODULE)0x0) {
          FUN_0056bb10(&DAT_007d4974);
          DAT_00a82894 = GetProcAddress(DAT_00a82890,"XInputGetState");
          DAT_00a82898 = GetProcAddress(DAT_00a82890,"XInputSetState");
          goto LAB_0056991e;
        }
        iVar10 = iVar10 + 1;
        lpLibFileName = local_22fc[iVar10];
        pHVar6 = (HMODULE)0x0;
      } while (lpLibFileName != (LPCWSTR)0x0);
      FUN_0056bb10(&DAT_007d7684);
    }
LAB_0056991e:
    FUN_0056bb10(&PTR_LAB_007d7638);
    if ((DAT_00a828a8 != 0) ||
       (iVar7 = (*DAT_00aba190)(&DAT_0085ed14,0,1,&DAT_0085edd4,&DAT_00a828ac), iVar7 < 0)) {
LAB_005699d6:
      if (DAT_00a828ac == (int *)0x0) {
        if (DAT_00a828a8 == 0) {
          FUN_0056bb10(&DAT_007d75ec);
          FUN_0056bca0(&DAT_007d75d0,iVar7);
        }
        goto LAB_00569a02;
      }
LAB_00569b42:
      FUN_005501a0();
      FUN_0054f3d0();
      DAT_00a828b0 = (int *)0x0;
      FUN_0056bb10(&DAT_007d7540);
      if (DAT_00a828a8 == 1) {
        iVar7 = (**(code **)(*DAT_00a828ac + 0xc))(DAT_00a828ac,&DAT_0085ed44);
      }
      else {
        iVar7 = (**(code **)(*DAT_00a828ac + 0x24))
                          (DAT_00a828ac,&DAT_0085ed44,&DAT_0085ed94,&DAT_00a828b0,0);
      }
      if (iVar7 == 0) {
        iVar7 = (**(code **)(*DAT_00a828b0 + 0x2c))(DAT_00a828b0,&DAT_0084f2e0);
        if (iVar7 != 0) {
          (**(code **)(*DAT_00a828b0 + 8))(DAT_00a828b0);
          DAT_00a828b0 = (int *)0x0;
          goto LAB_00569c0c;
        }
        iVar7 = *DAT_00a828b0;
        uVar8 = FUN_0050e7c0(10);
        iVar7 = (**(code **)(iVar7 + 0x34))(DAT_00a828b0,uVar8);
        if (iVar7 != 0) {
          (**(code **)(*DAT_00a828b0 + 8))(DAT_00a828b0);
          DAT_00a828b0 = (int *)0x0;
          goto LAB_00569c0c;
        }
        FUN_0056bb10(&DAT_007d75fc);
        if (DAT_00a828b0 == (int *)0x0) goto LAB_00569c0c;
      }
      else {
        DAT_00a828b0 = (int *)0x0;
LAB_00569c0c:
        FUN_0056bb10(&DAT_007d7518);
      }
      DAT_00a72a68 = (*DAT_00aba168)();
      DAT_00a828b4 = (int *)0x0;
      if (DAT_00a828c0 == 0) {
        FUN_0056bb10(&DAT_007d74f4);
        if (DAT_00a828a8 == 1) {
          iVar7 = (**(code **)(*DAT_00a828ac + 0xc))(DAT_00a828ac,&DAT_0085ed54);
        }
        else {
          iVar7 = (**(code **)(*DAT_00a828ac + 0x24))
                            (DAT_00a828ac,&DAT_0085ed54,&DAT_0085ed94,&DAT_00a828b4,0);
        }
        if (iVar7 == 0) {
          iVar7 = (**(code **)(*DAT_00a828b4 + 0x2c))(DAT_00a828b4,&DAT_0084e438);
          if (iVar7 == 0) {
            iVar7 = *DAT_00a828b4;
            if (DAT_00a828bc == 0) {
              uVar8 = 10;
            }
            else {
              uVar8 = 5;
            }
            uVar8 = FUN_0050e7c0(uVar8);
            iVar7 = (**(code **)(iVar7 + 0x34))(DAT_00a828b4,uVar8);
            if (iVar7 != 0) {
              (**(code **)(*DAT_00a828b4 + 8))(DAT_00a828b4);
              DAT_00a828b4 = (int *)0x0;
              goto LAB_00569da5;
            }
            iVar7 = (**(code **)(*DAT_00a828b4 + 0x18))(DAT_00a828b4,1,auStack_230a + -0xe);
            if (iVar7 != 0) {
              FUN_0056bb10(&DAT_007d74c8);
            }
            pvVar9 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
            iVar7 = (**(code **)(*DAT_00a828b4 + 0x30))(DAT_00a828b4,pvVar9);
            if ((iVar7 == 2) || (iVar7 == 0)) {
              DAT_00a828b8 = pvVar9;
              iVar7 = (**(code **)(*DAT_00a828b4 + 0x1c))(DAT_00a828b4);
              if ((iVar7 == 0) ||
                 (iVar7 = (**(code **)(*DAT_00a828b4 + 0x1c))(DAT_00a828b4), iVar7 == 0)) {
                FUN_0056bb10(&DAT_007d75fc);
                goto LAB_00569d9d;
              }
            }
            else {
              FUN_0056bb10(&DAT_007d7494);
            }
          }
          (**(code **)(*DAT_00a828b4 + 8))(DAT_00a828b4);
          DAT_00a828b4 = (int *)0x0;
LAB_00569da5:
          FUN_0056bb10(&DAT_007d7468);
        }
        else {
LAB_00569d9d:
          if (DAT_00a828b4 == (int *)0x0) goto LAB_00569da5;
        }
        DAT_00a72a68 = (*DAT_00aba168)();
      }
      FUN_0056bfe0();
      FUN_0056bb10(&PTR_LAB_007d742c);
      goto LAB_00569e1f;
    }
    FUN_0056bb10(&DAT_007d4974);
    FUN_0056bfd0();
    FUN_0056bb10(&DAT_007d761c);
    iVar7 = *DAT_00a828ac;
    uVar8 = (*DAT_00aba180)(0,0x700);
    iVar7 = (**(code **)(iVar7 + 0x1c))(DAT_00a828ac,uVar8);
    if (-1 < iVar7) {
      FUN_0056bb10(&DAT_007d75fc);
      FUN_0056bfe0();
      goto LAB_005699d6;
    }
    FUN_0056bb10(&DAT_007d760c);
    (**(code **)(*DAT_00a828ac + 8))(DAT_00a828ac);
    DAT_00a828ac = (int *)0x0;
LAB_00569a02:
    FUN_0056bb10(&PTR_LAB_007d759c);
    iVar7 = (*DAT_00aba190)(&DAT_0085ed34,0,1,&DAT_0085edc4,&DAT_00a828ac);
    if (iVar7 < 0) {
      FUN_0056bb10(&DAT_007d758c);
    }
    else {
      FUN_0056bb10(&DAT_007d4974);
      FUN_0056bfd0();
      FUN_0056bb10(&DAT_007d761c);
      iVar7 = *DAT_00a828ac;
      uVar8 = (*DAT_00aba180)(0,0x800);
      iVar7 = (**(code **)(iVar7 + 0x1c))(DAT_00a828ac,uVar8);
      if (-1 < iVar7) {
        FUN_0056bb10(&DAT_007d75fc);
        DAT_00a828a8 = 1;
        FUN_0056bfe0();
        goto LAB_00569b42;
      }
      FUN_0056bb10(&DAT_007d760c);
      (**(code **)(*DAT_00a828ac + 8))(DAT_00a828ac);
      DAT_00a828ac = (int *)0x0;
    }
    FUN_0056bb10(&PTR_LAB_007d7560);
    FUN_0056bfe0();
    if (DAT_00a828ac != (int *)0x0) {
      (**(code **)(*DAT_00a828ac + 8))(DAT_00a828ac);
    }
    DAT_00a828ac = (int *)0x0;
    DAT_00a828a0 = 1;
  }
  FUN_0056bfd0();
  iVar7 = 0;
  puVar11 = &DAT_00a74bc8;
  do {
    FUN_0056d380(local_22d8,0,0x2d8);
    iVar10 = (*DAT_00aba174)(iVar7,local_22d8,0x2d8);
    if (iVar10 != 0) break;
    if (((bStack_2258 & 1) == 0) || ((bStack_2258 & 2) == 0)) {
      uVar8 = 0;
    }
    else {
      uVar8 = 1;
    }
    puVar11[0x1f] = uVar8;
    *puVar11 = 0x5999;
    puVar11 = puVar11 + 0x135;
    iVar7 = iVar7 + 1;
  } while ((int)puVar11 < 0xa79908);
  DAT_00a74b80 = iVar7;
  FUN_0056bca0(&DAT_007d740c,iVar7);
  FUN_0056bfe0();
  DAT_00a828ac = (int *)0xffffffff;
  FUN_0056bb10(&DAT_007d73ec);
LAB_00569e1f:
  if (DAT_00a72b6c == 0) {
    DAT_00a72b6c = 1;
    puVar11 = &DAT_00a72b74;
    do {
      iVar7 = 0x20;
      do {
        puVar11[-1] = 0xffffffff;
        *puVar11 = 0xffffffff;
        puVar11 = puVar11 + 4;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    } while ((int)puVar11 < 0xa74b74);
    DAT_00a72b70 = 0x50;
    DAT_00a72b74 = 0xd0;
    DAT_00a72b80 = 0x4b;
    DAT_00a72b84 = 0xcb;
    _DAT_00a72b90 = 0x4d;
    _DAT_00a72b94 = 0xcd;
    _DAT_00a72ba0 = 0x48;
    _DAT_00a72ba4 = 200;
    _DAT_00a72bb0 = 0x2c;
    _DAT_00a72bc0 = 0x2d;
    _DAT_00a72bd0 = 0x2e;
    _DAT_00a72be0 = 0x1e;
    _DAT_00a72bf0 = 0x1f;
    _DAT_00a72c00 = 0x20;
    _DAT_00a72c10 = 0x10;
    _DAT_00a72c20 = 0x11;
    _DAT_00a72c30 = 1;
    _DAT_00a72c40 = 0x39;
  }
  DAT_00aaf10c = 0;
  return 0;
}

