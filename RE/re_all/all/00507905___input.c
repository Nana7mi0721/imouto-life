
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Removing unreachable block (ram,0x00508643) */
/* Library Function - Single Match
    __input
   
   Library: Visual Studio 2003 Release */

int __input(undefined4 param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  wchar_t *pwVar9;
  char *pcVar10;
  char *pcVar11;
  wchar_t *pwVar12;
  byte *pbVar13;
  bool bVar14;
  longlong lVar15;
  undefined4 local_1e0;
  uint local_1d8;
  byte *local_1d4;
  wchar_t local_1d0 [2];
  int local_1cc;
  byte local_1c8;
  undefined1 local_1c7;
  uint local_1c4;
  undefined1 *local_1c0;
  int local_1bc;
  int local_1b8;
  wchar_t *local_1b4;
  undefined8 local_1b0;
  byte local_1a5;
  int local_1a4;
  int local_1a0;
  byte local_19c;
  char local_19b;
  char local_19a;
  char local_199;
  uint local_198;
  char local_192;
  char local_191;
  int local_190;
  char local_189;
  int local_188;
  char local_181;
  char local_180;
  char local_17f [351];
  undefined4 local_20;
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_007d40d0;
  uStack_c = 0x507914;
  local_20 = DAT_0084b484;
  local_1c0 = (undefined1 *)0x0;
  local_1b4 = (wchar_t *)0x0;
  local_198 = 0;
  local_199 = '\0';
  local_188 = 0;
  local_1bc = 0;
LAB_00507948:
  if (*param_2 == 0) {
LAB_0050863a:
    if ((local_198 == 0xffffffff) && ((local_1bc == 0 && (local_199 == '\0')))) {
      local_1bc = -1;
    }
    return local_1bc;
  }
  iVar3 = _isspace((uint)*param_2);
  if (iVar3 != 0) {
    local_188 = local_188 + -1;
    do {
      local_188 = local_188 + 1;
      iVar3 = __inc();
      iVar4 = _isspace(iVar3);
    } while (iVar4 != 0);
    if (iVar3 != -1) {
      __ungetc_lk(iVar3,param_1);
    }
    do {
      param_2 = param_2 + 1;
      iVar3 = _isspace((uint)*param_2);
    } while (iVar3 != 0);
    goto LAB_00507948;
  }
  if (*param_2 != 0x25) {
    local_188 = local_188 + 1;
    uVar8 = __inc();
    local_198 = uVar8;
    if (*param_2 != uVar8) goto LAB_00508601;
    pbVar13 = param_2 + 1;
    if ((PTR_DAT_0084be08[(uVar8 & 0xff) * 2 + 1] & 0x80) != 0) {
      local_188 = local_188 + 1;
      uVar5 = __inc();
      if (param_2[1] != uVar5) {
        if (uVar5 != 0xffffffff) {
          __ungetc_lk(uVar5,param_1);
        }
        goto LAB_00508601;
      }
      local_188 = local_188 + -1;
      pbVar13 = param_2 + 2;
    }
    goto LAB_0050861b;
  }
  iVar3 = 0;
  local_1a4 = 0;
  local_19c = 0;
  local_1a0 = 0;
  local_1b8 = 0;
  local_190 = 0;
  local_1a5 = 0;
  local_19b = '\0';
  local_192 = '\0';
  local_181 = '\0';
  local_19a = '\0';
  local_189 = '\0';
  local_191 = '\x01';
  local_1cc = 0;
  pbVar13 = param_2;
  do {
    param_2 = pbVar13 + 1;
    uVar8 = (uint)*param_2;
    iVar4 = _isdigit(uVar8);
    if (iVar4 == 0) {
      if (uVar8 < 0x4f) {
        if (uVar8 != 0x4e) {
          if (uVar8 == 0x2a) {
            local_192 = local_192 + '\x01';
          }
          else if (uVar8 != 0x46) {
            if (uVar8 == 0x49) {
              bVar7 = pbVar13[2];
              if ((bVar7 == 0x36) && (pbVar13[3] == 0x34)) {
                local_1cc = local_1cc + 1;
                local_1b0 = 0;
                param_2 = pbVar13 + 3;
              }
              else if ((bVar7 == 0x33) && (pbVar13[3] == 0x32)) {
                param_2 = pbVar13 + 3;
              }
              else if ((((bVar7 != 100) && (bVar7 != 0x69)) && (bVar7 != 0x6f)) &&
                      ((bVar7 != 0x78 && (bVar7 != 0x58)))) goto LAB_00507acf;
            }
            else if (uVar8 == 0x4c) {
              local_191 = local_191 + '\x01';
            }
            else {
LAB_00507acf:
              local_181 = local_181 + '\x01';
            }
          }
        }
      }
      else if (uVar8 == 0x68) {
        local_191 = local_191 + -1;
        local_189 = local_189 + -1;
      }
      else {
        if (uVar8 == 0x6c) {
          local_191 = local_191 + '\x01';
        }
        else if (uVar8 != 0x77) goto LAB_00507acf;
        local_189 = local_189 + '\x01';
      }
    }
    else {
      local_1b8 = local_1b8 + 1;
      iVar3 = (uVar8 - 0x30) + iVar3 * 10;
    }
    pbVar13 = param_2;
  } while (local_181 == '\0');
  if (local_192 == '\0') {
    local_1e0 = param_3;
    local_1b4 = (wchar_t *)*param_3;
    param_3 = param_3 + 1;
  }
  pwVar9 = local_1b4;
  local_181 = '\0';
  if ((local_189 == '\0') && ((*param_2 == 0x53 || (local_189 = -1, *param_2 == 0x43)))) {
    local_189 = '\x01';
  }
  uVar8 = *param_2 | 0x20;
  local_1c4 = uVar8;
  local_190 = iVar3;
  if (uVar8 != 0x6e) {
    if ((uVar8 == 99) || (uVar8 == 0x7b)) {
      local_188 = local_188 + 1;
      local_198 = __inc();
    }
    else {
      do {
        local_188 = local_188 + 1;
        uVar5 = __inc();
        iVar3 = _isspace(uVar5);
      } while (iVar3 != 0);
      local_198 = uVar5;
    }
  }
  if ((local_1b8 != 0) && (local_190 == 0)) {
LAB_00507eac:
    uVar8 = local_198;
LAB_00508601:
    if (uVar8 != 0xffffffff) {
      __ungetc_lk(local_198,param_1);
    }
    goto LAB_0050863a;
  }
  if (0x6f < uVar8) {
    if (uVar8 == 0x70) {
      local_191 = '\x01';
LAB_00508299:
      if (local_198 == 0x2d) {
        local_19b = '\x01';
      }
      else if (local_198 != 0x2b) goto LAB_005082dc;
      local_190 = local_190 + -1;
      if ((local_190 == 0) && (local_1b8 != 0)) {
        local_181 = '\x01';
      }
      else {
        local_188 = local_188 + 1;
        local_198 = __inc();
      }
    }
    else {
      if (uVar8 == 0x73) {
LAB_00507e5f:
        if ('\0' < local_189) {
          local_19a = '\x01';
        }
LAB_00508029:
        local_188 = local_188 + -1;
        pwVar12 = pwVar9;
        if (local_198 != 0xffffffff) {
          __ungetc_lk(local_198,param_1);
        }
        do {
          if ((local_1b8 != 0) &&
             (iVar3 = local_190 + -1, bVar14 = local_190 == 0, local_190 = iVar3, bVar14))
          goto LAB_0050824a;
          local_188 = local_188 + 1;
          local_198 = __inc();
          if (local_198 == 0xffffffff) goto LAB_00508234;
          bVar7 = (byte)local_198;
          if ((uVar8 != 99) &&
             (((uVar8 != 0x73 || ((8 < (int)local_198 && ((int)local_198 < 0xe)))) ||
              (local_198 == 0x20)))) {
            if ((uVar8 != 0x7b) ||
               (((int)(char)(local_1c0[(int)local_198 >> 3] ^ local_1a5) & 1 << (bVar7 & 7)) == 0))
            goto LAB_00508234;
            uVar8 = local_1c4;
          }
          if (local_192 == '\0') {
            if (local_19a == '\0') {
              *(byte *)pwVar9 = bVar7;
              pwVar9 = (wchar_t *)((int)pwVar9 + 1);
            }
            else {
              local_1c8 = bVar7;
              if ((PTR_DAT_0084be08[(local_198 & 0xff) * 2 + 1] & 0x80) != 0) {
                local_188 = local_188 + 1;
                local_1c7 = __inc();
              }
              _mbtowc(local_1d0,(char *)&local_1c8,DAT_0084be60);
              *pwVar9 = local_1d0[0];
              pwVar9 = pwVar9 + 1;
            }
            local_1b4 = pwVar9;
          }
          else {
            pwVar12 = (wchar_t *)((int)pwVar12 + 1);
          }
        } while( true );
      }
      if (uVar8 == 0x75) goto LAB_00508299;
      if (uVar8 != 0x78) {
        if (uVar8 == 0x7b) {
          if ('\0' < local_189) {
            local_19a = '\x01';
          }
          pbVar13 = param_2 + 1;
          local_1d4 = pbVar13;
          if (*pbVar13 == 0x5e) {
            local_1d4 = param_2 + 2;
            local_1a5 = 0xff;
          }
          if (local_1c0 == (undefined1 *)0x0) {
            local_1c = (undefined1 *)(local_1d0 + -0xe);
            local_1c0 = (undefined1 *)(local_1d0 + -0xe);
            local_8 = (undefined *)0xffffffff;
          }
          puVar2 = local_1c0;
          _memset(local_1c0,0,0x20);
          if (local_1c4 != 0x7b) goto LAB_00507ffd;
          if (*local_1d4 != 0x5d) goto LAB_00507ffd;
          local_1d4 = local_1d4 + 1;
          puVar2[0xb] = 0x20;
          bVar7 = 0x5d;
          while (bVar6 = *local_1d4, bVar6 != 0x5d) {
            if (((bVar6 == 0x2d) && (bVar7 != 0)) && (bVar1 = local_1d4[1], bVar1 != 0x5d)) {
              local_1d4 = local_1d4 + 2;
              if (bVar7 < bVar1) {
                bVar6 = bVar7;
                bVar7 = bVar1;
              }
              else {
                bVar6 = bVar1;
              }
              if (bVar6 <= bVar7) {
                uVar8 = (uint)bVar6;
                local_1d8 = (uint)(byte)((bVar7 - bVar6) + 1);
                do {
                  puVar2[uVar8 >> 3] = puVar2[uVar8 >> 3] | '\x01' << ((byte)uVar8 & 7);
                  uVar8 = uVar8 + 1;
                  local_1d8 = local_1d8 - 1;
                } while (local_1d8 != 0);
              }
              bVar7 = 0;
            }
            else {
              local_19c = bVar6;
              puVar2[bVar6 >> 3] = puVar2[bVar6 >> 3] | '\x01' << (bVar6 & 7);
              local_1d4 = local_1d4 + 1;
LAB_00507ffd:
              bVar7 = local_19c;
            }
          }
          param_2 = pbVar13;
          if (local_1c4 == 0x7b) {
            param_2 = local_1d4;
          }
          pwVar9 = local_1b4;
          uVar8 = local_1c4;
          goto LAB_00508029;
        }
        goto LAB_00507e9e;
      }
LAB_00507c26:
      if (local_198 == 0x2d) {
        local_19b = '\x01';
LAB_0050814c:
        local_190 = local_190 + -1;
        if ((local_190 == 0) && (local_1b8 != 0)) {
          local_181 = '\x01';
        }
        else {
          local_188 = local_188 + 1;
          local_198 = __inc();
        }
      }
      else if (local_198 == 0x2b) goto LAB_0050814c;
      if (local_198 == 0x30) {
        local_188 = local_188 + 1;
        local_198 = __inc();
        if (((char)local_198 == 'x') || ((char)local_198 == 'X')) {
          local_188 = local_188 + 1;
          local_198 = __inc();
          if ((local_1b8 != 0) && (local_190 = local_190 + -2, local_190 < 1)) {
            local_181 = local_181 + '\x01';
          }
          uVar8 = 0x78;
        }
        else {
          local_1a0 = 1;
          if (uVar8 == 0x78) {
            local_188 = local_188 + -1;
            if (local_198 != 0xffffffff) {
              __ungetc_lk(local_198,param_1);
            }
            local_198 = 0x30;
          }
          else {
            if ((local_1b8 != 0) && (local_190 = local_190 + -1, local_190 == 0)) {
              local_181 = local_181 + '\x01';
            }
            uVar8 = 0x6f;
          }
        }
      }
    }
LAB_005082dc:
    lVar15 = local_1b0;
    if (local_1cc == 0) {
      uVar5 = local_198;
      if (local_181 == '\0') {
        do {
          local_1b0 = lVar15;
          if ((uVar8 == 0x78) || (uVar8 == 0x70)) {
            iVar3 = _isxdigit(uVar5);
            if (iVar3 != 0) {
              local_1a4 = local_1a4 << 4;
              iVar3 = _isdigit(uVar5);
              if (iVar3 == 0) {
                uVar5 = (uVar5 & 0xffffffdf) - 7;
              }
              goto LAB_005084b9;
            }
LAB_005084b3:
            local_181 = local_181 + '\x01';
          }
          else {
            iVar3 = _isdigit(uVar5);
            if (iVar3 == 0) goto LAB_005084b3;
            if (uVar8 == 0x6f) {
              if (0x37 < (int)uVar5) goto LAB_005084b3;
              local_1a4 = local_1a4 << 3;
            }
            else {
              local_1a4 = local_1a4 * 10;
            }
          }
LAB_005084b9:
          lVar15 = local_1b0;
          if (local_181 == '\0') {
            local_1a0 = local_1a0 + 1;
            local_1a4 = local_1a4 + -0x30 + uVar5;
            if ((local_1b8 == 0) || (local_190 = local_190 + -1, local_190 != 0)) {
              local_188 = local_188 + 1;
              uVar5 = __inc();
              lVar15 = local_1b0;
            }
            else {
              local_181 = '\x01';
            }
          }
          else {
            local_188 = local_188 + -1;
            if (uVar5 != 0xffffffff) {
              __ungetc_lk(uVar5,param_1);
              lVar15 = local_1b0;
            }
          }
        } while (local_181 == '\0');
        local_198 = uVar5;
      }
      if (local_19b != '\0') {
        local_1a4 = -local_1a4;
      }
    }
    else {
      uVar5 = local_198;
      if (local_181 == '\0') {
        do {
          if ((uVar8 == 0x78) || (uVar8 == 0x70)) {
            iVar3 = _isxdigit(uVar5);
            if (iVar3 != 0) {
              local_1b0 = local_1b0 << 4;
              iVar3 = _isdigit(uVar5);
              if (iVar3 == 0) {
                uVar5 = (uVar5 & 0xffffffdf) - 7;
              }
              goto LAB_005083a4;
            }
LAB_0050839e:
            local_181 = local_181 + '\x01';
          }
          else {
            iVar3 = _isdigit(uVar5);
            if (iVar3 == 0) goto LAB_0050839e;
            if (uVar8 == 0x6f) {
              if (0x37 < (int)uVar5) goto LAB_0050839e;
              local_1b0 = local_1b0 << 3;
            }
            else {
              lVar15 = __allmul(local_1b0,10,0);
              local_1b0 = lVar15;
            }
          }
LAB_005083a4:
          if (local_181 == '\0') {
            local_1a0 = local_1a0 + 1;
            lVar15 = local_1b0 + (int)(uVar5 - 0x30);
            local_1b0 = local_1b0 + (int)(uVar5 - 0x30);
            if ((local_1b8 == 0) || (local_190 = local_190 + -1, local_190 != 0)) {
              local_188 = local_188 + 1;
              local_1b0 = lVar15;
              uVar5 = __inc();
            }
            else {
              local_181 = '\x01';
            }
          }
          else {
            local_188 = local_188 + -1;
            if (uVar5 != 0xffffffff) {
              __ungetc_lk(uVar5,param_1);
            }
          }
        } while (local_181 == '\0');
        local_198 = uVar5;
        lVar15 = local_1b0;
      }
      local_1b0._4_4_ = (int)((ulonglong)lVar15 >> 0x20);
      local_1b0._0_4_ = (int)lVar15;
      if (local_19b != '\0') {
        lVar15 = CONCAT44(-(local_1b0._4_4_ + (uint)((int)local_1b0 != 0)),-(int)local_1b0);
      }
    }
    if (uVar8 == 0x46) {
      local_1a0 = 0;
    }
    if (local_1a0 != 0) {
      local_1b0 = lVar15;
      if (local_192 == '\0') {
        local_1bc = local_1bc + 1;
        iVar3 = local_1a4;
        pwVar9 = local_1b4;
LAB_0050856d:
        local_1b0 = lVar15;
        if (local_1cc == 0) {
          if (local_191 == '\0') {
            *pwVar9 = (wchar_t)iVar3;
          }
          else {
            *(int *)pwVar9 = iVar3;
          }
        }
        else {
          *(longlong *)pwVar9 = lVar15;
        }
      }
      goto LAB_00508599;
    }
    goto LAB_0050863a;
  }
  if (uVar8 == 0x6f) goto LAB_00508299;
  if (uVar8 == 99) {
    if (local_1b8 == 0) {
      local_1b8 = 1;
      local_190 = local_190 + 1;
    }
    goto LAB_00507e5f;
  }
  if (uVar8 == 100) goto LAB_00508299;
  if (uVar8 < 0x65) {
LAB_00507e9e:
    if (*param_2 != local_198) goto LAB_00507eac;
    local_199 = local_199 + -1;
    if (local_192 == '\0') {
      param_3 = local_1e0;
    }
  }
  else {
    if (0x67 < uVar8) {
      if (uVar8 == 0x69) {
        uVar8 = 100;
        goto LAB_00507c26;
      }
      if (uVar8 != 0x6e) goto LAB_00507e9e;
      iVar3 = local_188;
      lVar15 = local_1b0;
      if (local_192 != '\0') goto LAB_00508599;
      goto LAB_0050856d;
    }
    pcVar10 = &local_180;
    if (local_198 == 0x2d) {
      local_180 = '-';
      pcVar10 = local_17f;
LAB_00507c65:
      local_190 = local_190 + -1;
      local_188 = local_188 + 1;
      local_198 = __inc();
    }
    else if (local_198 == 0x2b) goto LAB_00507c65;
    if ((local_1b8 == 0) || (0x15d < local_190)) {
      local_190 = 0x15d;
    }
    while( true ) {
      uVar8 = local_198;
      iVar3 = _isdigit(local_198);
      if ((iVar3 == 0) ||
         (iVar3 = local_190 + -1, bVar14 = local_190 == 0, local_190 = iVar3, bVar14)) break;
      local_1a0 = local_1a0 + 1;
      *pcVar10 = (char)uVar8;
      pcVar10 = pcVar10 + 1;
      local_188 = local_188 + 1;
      local_198 = __inc();
    }
    if ((DAT_0084be64 == (char)uVar8) &&
       (iVar3 = local_190 + -1, bVar14 = local_190 != 0, local_190 = iVar3, bVar14)) {
      local_188 = local_188 + 1;
      uVar8 = __inc();
      *pcVar10 = DAT_0084be64;
      while( true ) {
        pcVar10 = pcVar10 + 1;
        local_198 = uVar8;
        iVar3 = _isdigit(uVar8);
        if ((iVar3 == 0) ||
           (iVar3 = local_190 + -1, bVar14 = local_190 == 0, local_190 = iVar3, bVar14)) break;
        local_1a0 = local_1a0 + 1;
        *pcVar10 = (char)uVar8;
        local_188 = local_188 + 1;
        uVar8 = __inc();
      }
    }
    pcVar11 = pcVar10;
    if ((local_1a0 != 0) &&
       (((uVar8 == 0x65 || (uVar8 == 0x45)) &&
        (iVar3 = local_190 + -1, bVar14 = local_190 != 0, local_190 = iVar3, bVar14)))) {
      *pcVar10 = 'e';
      pcVar11 = pcVar10 + 1;
      local_188 = local_188 + 1;
      local_198 = __inc();
      if (local_198 == 0x2d) {
        *pcVar11 = '-';
        pcVar11 = pcVar10 + 2;
LAB_00507d9f:
        bVar14 = local_190 != 0;
        local_190 = local_190 + -1;
        if (bVar14) goto LAB_00507dd0;
        local_190 = 0;
      }
      else if (local_198 == 0x2b) goto LAB_00507d9f;
      while( true ) {
        uVar8 = local_198;
        iVar3 = _isdigit(local_198);
        if ((iVar3 == 0) ||
           (iVar3 = local_190 + -1, bVar14 = local_190 == 0, local_190 = iVar3, bVar14)) break;
        local_1a0 = local_1a0 + 1;
        *pcVar11 = (char)uVar8;
        pcVar11 = pcVar11 + 1;
LAB_00507dd0:
        local_188 = local_188 + 1;
        local_198 = __inc();
      }
    }
    local_188 = local_188 + -1;
    if (uVar8 != 0xffffffff) {
      __ungetc_lk(uVar8,param_1);
    }
    if (local_1a0 == 0) goto LAB_0050863a;
    if (local_192 == '\0') {
      local_1bc = local_1bc + 1;
      *pcVar11 = '\0';
      (*(code *)PTR_FUN_0084b708)(local_191 + -1,local_1b4,&local_180);
    }
  }
LAB_00508599:
  local_199 = local_199 + '\x01';
  pbVar13 = param_2 + 1;
LAB_0050861b:
  param_2 = pbVar13;
  if ((local_198 == 0xffffffff) && ((*param_2 != 0x25 || (param_2[1] != 0x6e)))) goto LAB_0050863a;
  goto LAB_00507948;
LAB_00508234:
  local_188 = local_188 + -1;
  if (local_198 != 0xffffffff) {
    __ungetc_lk(local_198,param_1);
  }
LAB_0050824a:
  if (pwVar12 == pwVar9) goto LAB_0050863a;
  if ((local_192 == '\0') && (local_1bc = local_1bc + 1, local_1c4 != 99)) {
    if (local_19a == '\0') {
      *(byte *)local_1b4 = 0;
    }
    else {
      *local_1b4 = L'\0';
    }
  }
  goto LAB_00508599;
}

