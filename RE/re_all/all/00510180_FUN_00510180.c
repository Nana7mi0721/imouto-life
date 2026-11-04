
/* WARNING: Removing unreachable block (ram,0x00510902) */
/* WARNING: Removing unreachable block (ram,0x005108ef) */
/* WARNING: Removing unreachable block (ram,0x005108d9) */
/* WARNING: Removing unreachable block (ram,0x005108c6) */
/* WARNING: Removing unreachable block (ram,0x005108b3) */
/* WARNING: Removing unreachable block (ram,0x005108a0) */
/* WARNING: Removing unreachable block (ram,0x00510892) */
/* WARNING: Removing unreachable block (ram,0x00510882) */
/* WARNING: Removing unreachable block (ram,0x00510865) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00510180(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  byte bVar8;
  byte in_AF;
  byte bVar9;
  byte bVar10;
  byte in_TF;
  byte in_IF;
  byte bVar11;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined8 uVar12;
  undefined1 uStack00000000;
  undefined **lpText;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uStack_5b4;
  undefined1 local_5a0 [128];
  undefined1 local_520 [128];
  _OSVERSIONINFOW local_4a0;
  undefined4 local_38c;
  int local_388;
  int local_384;
  DWORD local_380;
  undefined1 local_270 [512];
  uint local_70;
  uint local_6c;
  uint local_68;
  _union_530 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40;
  int local_3c;
  int iStack_38;
  uint local_34;
  int local_30;
  uint local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined1 local_8;
  
  uStack_5b4 = L"쒃\xe804븲\x05傡ꮢ㌀㯶痆\xe80a꟒\x06傡ꮢ栀Ұ";
  FUN_0056bb10();
  FUN_0056bfd0();
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  uStack_5b4 = (WCHAR *)0x80;
  FUN_005764b0(L"3.19b",0xffffffff,DAT_00aba250,local_5a0);
  FUN_0057a6a0(0x4b0,1,0x3a4,0x4b0,local_520,0x40,&DAT_007d4cec,local_5a0);
  FUN_0056bb10(local_520);
  uStack_5b4 = (WCHAR *)0x510219;
  GetSystemInfo((LPSYSTEM_INFO)&local_64.s);
  uStack_5b4 = (WCHAR *)&DAT_007d4ccc;
  DAT_00a20bf4 = local_50;
  FUN_0056bca0();
  FUN_0056bb10(&DAT_007d4cc0);
  FUN_0056cf10(local_270);
  FUN_0056d380(&local_4a0,0,0x114);
  local_4a0.dwOSVersionInfoSize = 0x114;
  uStack_5b4 = L"薋ﭴ\xffff옫萏Ԇ";
  GetVersionExW(&local_4a0);
  if (local_4a0.dwPlatformId == 0) {
    uStack_5b4 = (WCHAR *)0x200;
    FUN_0056d040(local_270);
    DAT_00a2e8c8 = 0;
  }
  else if (local_4a0.dwPlatformId == 1) {
    if (local_4a0.dwMinorVersion == 0) {
      uStack_5b4 = (WCHAR *)0x200;
      FUN_0056d040(local_270);
      DAT_00a2e8c8 = 1;
      if (local_4a0.szCSDVersion[0] == L'C') {
        uStack_5b4 = (WCHAR *)0x200;
        FUN_0056d040(local_270);
      }
    }
    else if (local_4a0.dwMinorVersion == 10) {
      uStack_5b4 = (WCHAR *)0x200;
      FUN_0056d040(local_270);
      DAT_00a2e8c8 = 2;
      if (local_4a0.szCSDVersion[0] == L'A') {
        uStack_5b4 = (WCHAR *)0x200;
        FUN_0056d040(local_270);
      }
    }
    else if (local_4a0.dwMinorVersion == 0x5a) {
      uStack_5b4 = (WCHAR *)0x200;
      FUN_0056d040(local_270);
      DAT_00a2e8c8 = 3;
    }
  }
  else if (local_4a0.dwPlatformId == 2) {
    if (((local_4a0.dwMajorVersion < 6) || (local_4a0.dwMinorVersion < 2)) ||
       (((DAT_00aba184 == (code *)0x0 || (DAT_00aba188 == (code *)0x0)) &&
        (DAT_00aba200 == (code *)0x0)))) {
      switch(local_4a0.dwMajorVersion) {
      case 3:
        uStack_5b4 = (WCHAR *)0x200;
        FUN_0056d040(local_270);
        DAT_00a2e8c8 = 0x104;
        break;
      case 4:
        uStack_5b4 = (WCHAR *)0x200;
        FUN_0056d040(local_270);
        DAT_00a2e8c8 = 0x105;
        break;
      case 5:
        if (local_4a0.dwMinorVersion == 0) {
          uStack_5b4 = (WCHAR *)0x200;
          FUN_0056d040(local_270);
          DAT_00a2e8c8 = 0x106;
        }
        else if (local_4a0.dwMinorVersion == 1) {
          uStack_5b4 = (WCHAR *)0x200;
          FUN_0056d040(local_270);
          DAT_00a2e8c8 = 0x107;
        }
        break;
      case 6:
        switch(local_4a0.dwMinorVersion) {
        case 0:
switchD_00510376_caseD_0:
          uStack_5b4 = (WCHAR *)0x200;
          FUN_0056d040(local_270);
          DAT_00a2e8c8 = 0x108;
          break;
        case 1:
switchD_00510376_caseD_1:
          uStack_5b4 = (WCHAR *)0x200;
          FUN_0056d040(local_270);
          DAT_00a2e8c8 = 0x109;
          break;
        case 2:
switchD_00510376_caseD_2:
          uStack_5b4 = (WCHAR *)0x200;
          FUN_0056d040(local_270);
          DAT_00a2e8c8 = 0x10a;
          break;
        case 3:
switchD_00510376_caseD_3:
          uStack_5b4 = (WCHAR *)0x200;
          FUN_0056d040(local_270);
          DAT_00a2e8c8 = 0x10b;
          break;
        case 4:
switchD_00510376_caseD_4:
          uStack_5b4 = (WCHAR *)0x200;
          FUN_0056d040(local_270);
          DAT_00a2e8c8 = 0x10c;
        }
        break;
      case 10:
        if (local_4a0.dwMinorVersion == 0) {
          uStack_5b4 = (WCHAR *)0x200;
          FUN_0056d040(local_270);
          DAT_00a2e8c8 = 0x10c;
        }
      }
    }
    else {
      uStack_5b4 = (WCHAR *)0x0;
      FUN_0056d380(&local_38c);
      local_38c = 0x11c;
      if (DAT_00aba200 == (code *)0x0) {
        uStack_5b4 = (WCHAR *)0x2;
        uVar14 = 0;
        local_4a0.dwBuildNumber = 0;
        local_4a0.szCSDVersion[0] = L'\0';
        uVar13 = 0;
        uVar12 = (*DAT_00aba188)();
        uVar12 = (*DAT_00aba188)(uVar12,1,2,uVar13,uVar14);
        local_388 = 10;
        local_384 = 0;
        iVar5 = (*DAT_00aba184)(&local_38c,3,uVar12);
        if (iVar5 == 0) {
          uStack_5b4 = (WCHAR *)0x2;
          uVar14 = 0;
          uVar13 = 0;
          uVar12 = (*DAT_00aba188)();
          uVar12 = (*DAT_00aba188)(uVar12,1,3,uVar13,uVar14);
          local_388 = 10;
          local_384 = 0;
          iVar5 = (*DAT_00aba184)(&local_38c,3,uVar12);
          if (iVar5 == 0) {
            local_388 = 6;
            local_384 = 4;
            uStack_5b4 = (WCHAR *)(int)uVar12;
            iVar5 = (*DAT_00aba184)();
            if (iVar5 == 0) {
              local_388 = 6;
              local_384 = 3;
              uStack_5b4 = (WCHAR *)(int)uVar12;
              iVar5 = (*DAT_00aba184)();
              if (iVar5 == 0) {
                uStack_5b4 = (WCHAR *)0x200;
                FUN_0056d040(local_270);
                DAT_00a2e8c8 = 0x10a;
              }
              else {
                uStack_5b4 = (WCHAR *)0x200;
                FUN_0056d040(local_270);
                DAT_00a2e8c8 = 0x10b;
              }
              goto switchD_00510376_default;
            }
          }
          uStack_5b4 = (WCHAR *)0x200;
          FUN_0056d040(local_270);
          DAT_00a2e8c8 = 0x10c;
        }
        else {
          uStack_5b4 = (WCHAR *)0x200;
          FUN_0056d040(local_270);
          DAT_00a2e8c8 = 0x10c;
        }
      }
      else {
        uStack_5b4 = 
        L"閍ﲌ\xffff赒碅\xfffb僿﷨׋謀粅￼诿蒍￼菿ࣄ\xf883褆炍\xfffb瓿茺૸蔏Ѱ";
        (*DAT_00aba200)();
        uStack_5b4 = local_4a0.szCSDVersion;
        FUN_0056cf10();
        local_4a0.dwBuildNumber = local_380;
        if (local_388 == 6) {
          switch(local_384) {
          case 0:
            goto switchD_00510376_caseD_0;
          case 1:
            goto switchD_00510376_caseD_1;
          case 2:
            goto switchD_00510376_caseD_2;
          case 3:
            goto switchD_00510376_caseD_3;
          case 4:
            goto switchD_00510376_caseD_4;
          }
        }
        else if ((local_388 == 10) && (local_384 == 0)) {
          uStack_5b4 = (WCHAR *)0x200;
          FUN_0056d040(local_270);
          DAT_00a2e8c8 = 0x10c;
        }
      }
    }
  }
switchD_00510376_default:
  if (local_4a0.dwBuildNumber == 0) {
    uStack_5b4 = (WCHAR *)&DAT_007d4be8;
    FUN_0056d310();
  }
  else {
    uStack_5b4 = (WCHAR *)local_4a0.dwBuildNumber;
    FUN_0056d310(&DAT_00a201c8,0x100,L"%s ( Build %d %s )",local_270);
  }
  uStack_5b4 = (WCHAR *)&DAT_007d4be8;
  FUN_0056bc50();
  bVar7 = (undefined1 *)0xfffffff7 < &uStack_5b4;
  bVar11 = SCARRY4((int)&uStack_5b4,8);
  bVar10 = (int)(local_5a0 + -0xc) < 0;
  bVar9 = &uStack00000000 == (undefined1 *)0x5ac;
  bVar8 = (POPCOUNT((uint)(local_5a0 + -0xc) & 0xff) & 1U) == 0;
  uStack_5b4 = (WCHAR *)&local_2c;
  DAT_00a2e8c4 = 0x70000;
  (*DAT_00aba16c)();
  (*DAT_00aba160)(local_2c);
  local_1c = 0;
  local_20 = 0;
  local_18 = 0;
  local_14 = 0;
  local_70 = local_70 & 0xffffff00;
  local_40 = 0;
  DAT_00a2e8cc = 0;
  uVar4 = ((uint)(in_NT & 1) * 0x4000 | (uint)(bVar11 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
           (uint)(in_TF & 1) * 0x100 | (uint)(bVar10 & 1) * 0x80 | (uint)(bVar9 & 1) * 0x40 |
           (uint)(in_AF & 1) * 0x10 | (uint)(bVar8 & 1) * 4 | (uint)(bVar7 & 1) |
           (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 |
           (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000) ^ 0x200000;
  local_10 = 0;
  if (uVar4 == ((uint)((uVar4 & 0x4000) != 0) * 0x4000 | (uint)((uVar4 & 0x800) != 0) * 0x800 |
                (uint)((uVar4 & 0x200) != 0) * 0x200 | (uint)((uVar4 & 0x100) != 0) * 0x100 |
                (uint)((uVar4 & 0x80) != 0) * 0x80 | (uint)((uVar4 & 0x40) != 0) * 0x40 |
                (uint)((uVar4 & 0x10) != 0) * 0x10 | (uint)((uVar4 & 4) != 0) * 4 |
                (uint)((uVar4 & 1) != 0) | (uint)((uVar4 & 0x200000) != 0) * 0x200000 |
               (uint)((uVar4 & 0x40000) != 0) * 0x40000)) {
    puVar1 = (undefined4 *)cpuid_basic_info(0);
    local_24 = *puVar1;
    local_20 = puVar1[1];
    local_18 = puVar1[2];
    local_14 = puVar1[3];
    local_10 = 1;
    iVar5 = cpuid_Version_info(1);
    local_1c = (*(uint *)(iVar5 + 8) & 0x10) >> 4;
    puVar2 = (uint *)cpuid(0x80000000);
    if (0x80000003 < *puVar2) {
      puVar2 = (uint *)cpuid_brand_part1_info(0x80000002);
      local_70 = *puVar2;
      local_6c = puVar2[1];
      local_64.dwOemId = puVar2[2];
      local_68 = puVar2[3];
      puVar1 = (undefined4 *)cpuid_brand_part2_info(0x80000003);
      local_60 = *puVar1;
      local_5c = puVar1[1];
      local_54 = puVar1[2];
      local_58 = puVar1[3];
      puVar1 = (undefined4 *)cpuid_brand_part3_info(0x80000004);
      local_50 = *puVar1;
      local_4c = puVar1[1];
      local_44 = puVar1[2];
      local_48 = puVar1[3];
    }
    iVar5 = cpuid_Version_info(1);
    if ((*(uint *)(iVar5 + 8) & 0x800000) != 0) {
      local_10 = 3;
      iVar5 = cpuid_Version_info(1);
      if ((*(uint *)(iVar5 + 8) & 0x2000000) != 0) {
        local_10 = 4;
        iVar5 = cpuid_Version_info(1);
        if ((*(uint *)(iVar5 + 8) & 0x4000000) != 0) {
          local_10 = 5;
        }
      }
    }
  }
  DAT_00a2e8d8 = local_1c;
  if (local_1c != 0) {
    uVar12 = rdtsc();
    local_28 = (int)((ulonglong)uVar12 >> 0x20);
    local_2c = (uint)uVar12;
    iVar5 = FUN_00550060();
    do {
      iVar6 = FUN_00550060();
    } while (iVar6 - iVar5 < 100);
    uVar12 = rdtsc();
    local_30 = (int)((ulonglong)uVar12 >> 0x20);
    local_34 = (uint)uVar12;
    local_3c = local_34 - local_2c;
    iStack_38 = (local_30 - local_28) - (uint)(local_34 < local_2c);
    iVar5 = FUN_0050e240((double)CONCAT44(iStack_38,local_3c) / _DAT_007d4be0);
    uVar12 = __allmul(local_34 - local_2c,(local_30 - local_28) - (uint)(local_34 < local_2c),10,0);
    DAT_00a2e8e4 = (undefined4)((ulonglong)uVar12 >> 0x20);
    DAT_00a2e8e0 = (undefined4)uVar12;
    fVar3 = (float)iVar5;
    if (iVar5 < 0) {
      fVar3 = fVar3 + _DAT_007d4bd8;
    }
    iStack_38 = iVar5;
    FUN_0056bca0(&DAT_007d4bac,(double)(fVar3 / (float)_DAT_007d1010));
    _DAT_00a207c8 = iVar5;
  }
  switch(local_10) {
  case 0:
    FUN_0056bb10();
    break;
  case 1:
    FUN_0056bb10();
    break;
  case 3:
    FUN_0056bb10();
    goto LAB_00510a52;
  case 4:
    FUN_0056bb10();
    FUN_0056bb10(&DAT_007d4b3c);
    goto LAB_00510a4c;
  case 5:
    FUN_0056bb10();
    FUN_0056bb10(&DAT_007d4b3c);
    FUN_0056bb10(&DAT_007d4b1c);
    DAT_00a2e8d4 = 1;
LAB_00510a4c:
    DAT_00a2e8d0 = 1;
LAB_00510a52:
    DAT_00a2e8cc = 1;
  }
  if (0 < local_10) {
    FUN_0056bb10();
    local_8 = 0;
    local_c = local_20;
    FUN_0056ba10(&local_c);
    local_c = local_18;
    FUN_0056ba10(&local_c);
    local_c = local_14;
    FUN_0056ba10(&local_c);
    FUN_0056bb00(&DAT_007d4b08);
    if ((char)local_70 != '\0') {
      FUN_0056bc00(&DAT_007d4af8);
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      FUN_005764b0(&local_70,0xffffffff,0x7ffd,&DAT_00a205c8,0x200);
    }
  }
  FUN_0056bfe0();
  if (0x6ffff < DAT_00a2e8c4) {
    return 0;
  }
  if (DAT_00a2e8c4 == 0) {
    lpText = &PTR_LAB_007d4ab0;
  }
  else {
    lpText = &PTR_LAB_007d4a60;
  }
  MessageBoxW((HWND)0x0,(LPCWSTR)lpText,L"エラー",0);
                    /* WARNING: Subroutine does not return */
  ExitProcess(0xffffffff);
}

