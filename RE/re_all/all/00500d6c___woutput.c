
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    __woutput
   
   Library: Visual Studio 2003 Release */

int __woutput(undefined4 param_1,ushort *param_2,wchar_t *param_3)

{
  ushort uVar1;
  wchar_t wVar2;
  short *psVar3;
  ushort *puVar4;
  uint uVar5;
  wchar_t *pwVar6;
  int extraout_ECX;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  int iVar10;
  bool bVar11;
  longlong lVar12;
  uint local_45c;
  uint local_458;
  int local_450;
  uint local_44c;
  undefined4 local_448;
  int local_444;
  int local_440;
  size_t local_43c;
  int local_438;
  wchar_t *local_434;
  char local_430 [4];
  undefined2 local_42c;
  short local_42a;
  int local_428;
  uint local_424;
  int local_420;
  int local_41c;
  wchar_t *local_418;
  size_t local_414;
  uint local_410;
  uint local_40c;
  wchar_t local_408 [255];
  undefined2 local_209;
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  uVar9 = *param_2;
  local_444 = 0;
  local_414 = 0;
  local_41c = 0;
  local_434 = (wchar_t *)0x0;
  if (uVar9 != 0) {
    while (puVar4 = param_2 + 1, -1 < local_41c) {
      if ((uVar9 < 0x20) || (0x78 < uVar9)) {
        uVar5 = 0;
      }
      else {
        uVar5 = (int)(char)(&DAT_007d2a78)[uVar9] & 0xf;
      }
      local_444 = (int)(char)(&DAT_007d2a98)[uVar5 * 8 + local_444] >> 4;
      switch(local_444) {
      case 0:
switchD_00500df7_caseD_0:
        local_428 = 1;
        write_char(uVar9);
        break;
      case 1:
        local_410 = 0xffffffff;
        local_448 = 0;
        local_438 = 0;
        local_424 = 0;
        local_420 = 0;
        local_40c = 0;
        local_428 = 0;
        break;
      case 2:
        if (uVar9 == 0x20) {
          local_40c = local_40c | 2;
        }
        else if (uVar9 == 0x23) {
          local_40c = local_40c | 0x80;
        }
        else if (uVar9 == 0x2b) {
          local_40c = local_40c | 1;
        }
        else if (uVar9 == 0x2d) {
          local_40c = local_40c | 4;
        }
        else if (uVar9 == 0x30) {
          local_40c = local_40c | 8;
        }
        break;
      case 3:
        if (uVar9 == 0x2a) {
          pwVar6 = param_3 + 2;
          local_424 = *(uint *)param_3;
          param_3 = pwVar6;
          if ((int)local_424 < 0) {
            local_40c = local_40c | 4;
            local_424 = -local_424;
          }
        }
        else {
          local_424 = (uVar9 - 0x30) + local_424 * 10;
        }
        break;
      case 4:
        local_410 = 0;
        break;
      case 5:
        if (uVar9 == 0x2a) {
          pwVar6 = param_3 + 2;
          local_410 = *(uint *)param_3;
          param_3 = pwVar6;
          if ((int)local_410 < 0) {
            local_410 = 0xffffffff;
          }
        }
        else {
          local_410 = (uVar9 - 0x30) + local_410 * 10;
        }
        break;
      case 6:
        if (uVar9 == 0x49) {
          uVar1 = *puVar4;
          if ((uVar1 == 0x36) && (param_2[2] == 0x34)) {
            local_40c = local_40c | 0x8000;
            puVar4 = param_2 + 3;
          }
          else if ((uVar1 == 0x33) && (param_2[2] == 0x32)) {
            local_40c = local_40c & 0xffff7fff;
            puVar4 = param_2 + 3;
          }
          else if (uVar1 != 100) {
            if (uVar1 != 0x69) {
              if (uVar1 != 0x6f) {
                if (uVar1 != 0x75) {
                  if (uVar1 != 0x78) {
                    if (uVar1 != 0x58) {
                      local_444 = 0;
                      goto switchD_00500df7_caseD_0;
                    }
                  }
                }
              }
            }
          }
        }
        else if (uVar9 == 0x68) {
          local_40c = local_40c | 0x20;
        }
        else if (uVar9 == 0x6c) {
          local_40c = local_40c | 0x10;
        }
        else if (uVar9 == 0x77) {
          local_40c = local_40c | 0x800;
        }
        break;
      case 7:
        if (uVar9 < 0x68) {
          if (uVar9 < 0x65) {
            if (uVar9 < 0x59) {
              if (uVar9 == 0x58) {
LAB_005012e0:
                local_440 = 7;
LAB_005012e3:
                local_414 = 0x10;
                if ((local_40c & 0x80) != 0) {
                  local_42a = (short)local_440 + 0x51;
                  local_42c = 0x30;
                  local_420 = 2;
                }
                goto LAB_00501123;
              }
              if (uVar9 == 0x43) {
                if ((local_40c & 0x830) == 0) {
                  local_40c = local_40c | 0x20;
                }
                goto LAB_005010c1;
              }
              if ((uVar9 != 0x45) && (uVar9 != 0x47)) {
                if (uVar9 == 0x53) {
                  if ((local_40c & 0x830) == 0) {
                    local_40c = local_40c | 0x20;
                  }
                  goto LAB_0050101f;
                }
                goto LAB_0050143a;
              }
              local_448 = 1;
              uVar9 = uVar9 + 0x20;
              goto LAB_00501096;
            }
            if (uVar9 == 0x5a) {
              pwVar6 = param_3 + 2;
              psVar3 = *(short **)param_3;
              param_3 = pwVar6;
              if ((psVar3 == (short *)0x0) ||
                 (local_418 = *(wchar_t **)(psVar3 + 2), local_418 == (wchar_t *)0x0)) {
                local_418 = (wchar_t *)PTR_DAT_0084bc48;
                pwVar6 = (wchar_t *)PTR_DAT_0084bc48;
                goto LAB_00501260;
              }
              local_414 = (size_t)*psVar3;
              if ((local_40c & 0x800) == 0) {
                local_428 = 0;
              }
              else {
                local_414 = (int)local_414 / 2;
                local_428 = 1;
              }
              goto LAB_00501437;
            }
            if (uVar9 == 99) {
LAB_005010c1:
              wVar2 = *param_3;
              local_44c = (uint)(ushort)wVar2;
              local_428 = 1;
              if ((local_40c & 0x20) == 0) {
                local_408[0] = wVar2;
              }
              else {
                local_430[0] = (char)wVar2;
                local_430[1] = 0;
                iVar10 = _mbtowc(local_408,local_430,DAT_0084be60);
                if (iVar10 < 0) {
                  local_438 = 1;
                }
              }
              local_418 = local_408;
              local_414 = 1;
              param_3 = param_3 + 2;
            }
            else if (uVar9 == 100) goto LAB_00501118;
            goto LAB_0050143a;
          }
LAB_00501096:
          local_40c = local_40c | 0x40;
          pwVar6 = local_408;
          local_418 = pwVar6;
          if ((int)local_410 < 0) {
            local_410 = 6;
          }
          else if (local_410 == 0) {
            if (uVar9 == 0x67) {
              local_410 = 1;
            }
          }
          else {
            if (0x200 < (int)local_410) {
              local_410 = 0x200;
            }
            if (0xa3 < (int)local_410) {
              local_434 = _malloc(local_410 + 0x15d);
              if (local_434 == (wchar_t *)0x0) {
                local_410 = 0xa3;
              }
              else {
                pwVar6 = local_434;
                local_418 = local_434;
              }
            }
          }
          local_45c = *(uint *)param_3;
          local_458 = *(uint *)(param_3 + 2);
          (*(code *)PTR_FUN_0084b700)(&local_45c,pwVar6,(int)(char)uVar9,local_410,local_448);
          uVar5 = local_40c & 0x80;
          if ((uVar5 != 0) && (local_410 == 0)) {
            (*(code *)PTR_FUN_0084b70c)(pwVar6);
          }
          if ((uVar9 == 0x67) && (uVar5 == 0)) {
            (*(code *)PTR_FUN_0084b704)(pwVar6);
          }
          if ((byte)*pwVar6 == 0x2d) {
            local_40c = local_40c | 0x100;
            pwVar6 = (wchar_t *)((int)pwVar6 + 1);
            local_418 = pwVar6;
          }
          param_3 = param_3 + 4;
LAB_00501260:
          local_414 = _strlen((char *)pwVar6);
LAB_00501437:
LAB_0050143a:
          if (local_438 == 0) {
            if ((local_40c & 0x40) != 0) {
              if ((local_40c & 0x100) == 0) {
                if ((local_40c & 1) == 0) {
                  if ((local_40c & 2) == 0) goto LAB_00501475;
                  local_42c = 0x20;
                }
                else {
                  local_42c = 0x2b;
                }
              }
              else {
                local_42c = 0x2d;
              }
              local_420 = 1;
            }
LAB_00501475:
            iVar10 = (local_424 - local_420) - local_414;
            if ((local_40c & 0xc) == 0) {
              write_multi_char(0x20,iVar10,param_1);
            }
            write_string(local_420);
            if (((local_40c & 8) != 0) && ((local_40c & 4) == 0)) {
              write_multi_char(0x30,iVar10,param_1);
            }
            if ((local_428 == 0) && (0 < (int)local_414)) {
              local_43c = local_414;
              pwVar6 = local_418;
              do {
                local_43c = local_43c - 1;
                local_450 = _mbtowc((wchar_t *)&local_44c,(char *)pwVar6,DAT_0084be60);
                if (local_450 < 1) break;
                write_char(local_44c);
                pwVar6 = (wchar_t *)((int)pwVar6 + local_450);
              } while (0 < (int)local_43c);
            }
            else {
              write_string(local_414);
            }
            if ((local_40c & 4) != 0) {
              write_multi_char(0x20,iVar10,param_1);
            }
          }
        }
        else {
          if (uVar9 == 0x69) {
LAB_00501118:
            local_40c = local_40c | 0x40;
LAB_0050111c:
            local_414 = 10;
LAB_00501123:
            if ((local_40c & 0x8000) == 0) {
              if ((local_40c & 0x20) == 0) {
                uVar5 = *(uint *)param_3;
                if ((local_40c & 0x40) == 0) {
                  uVar8 = 0;
                  param_3 = param_3 + 2;
                  goto LAB_00501384;
                }
              }
              else if ((local_40c & 0x40) == 0) {
                uVar5 = (uint)(ushort)*param_3;
              }
              else {
                uVar5 = (uint)*param_3;
              }
              uVar8 = (int)uVar5 >> 0x1f;
              param_3 = param_3 + 2;
            }
            else {
              uVar5 = *(uint *)param_3;
              uVar8 = *(uint *)(param_3 + 2);
              param_3 = param_3 + 4;
            }
LAB_00501384:
            if ((((local_40c & 0x40) != 0) && ((int)uVar8 < 1)) && ((int)uVar8 < 0)) {
              bVar11 = uVar5 != 0;
              uVar5 = -uVar5;
              uVar8 = -(uVar8 + bVar11);
              local_40c = local_40c | 0x100;
            }
            if ((local_40c & 0x8000) == 0) {
              uVar8 = 0;
            }
            lVar12 = CONCAT44(uVar8,uVar5);
            if ((int)local_410 < 0) {
              local_410 = 1;
            }
            else {
              local_40c = local_40c & 0xfffffff7;
              if (0x200 < (int)local_410) {
                local_410 = 0x200;
              }
            }
            if (uVar5 == 0 && uVar8 == 0) {
              local_420 = 0;
            }
            pwVar6 = &local_209;
            while( true ) {
              iVar10 = (int)lVar12;
              uVar5 = local_410 - 1;
              if (((int)local_410 < 1) && (lVar12 == 0)) break;
              local_410 = uVar5;
              lVar12 = __aulldvrm(lVar12,local_414,(int)local_414 >> 0x1f);
              iVar7 = extraout_ECX + 0x30;
              if (0x39 < iVar7) {
                iVar7 = iVar7 + local_440;
              }
              *(byte *)pwVar6 = (byte)iVar7;
              pwVar6 = (wchar_t *)((int)pwVar6 + -1);
              local_450 = iVar10;
            }
            local_414 = (int)&local_209 + -(int)pwVar6;
            local_418 = (wchar_t *)((int)pwVar6 + 1);
            local_410 = uVar5;
            if ((local_40c & 0x200) != 0) {
              if (*(byte *)local_418 == 0x30) {
                if (local_414 != 0) goto LAB_0050143a;
              }
              *(byte *)pwVar6 = 0x30;
              local_414 = (int)&local_209 + -(int)pwVar6 + 1;
              local_418 = pwVar6;
              goto LAB_00501437;
            }
            goto LAB_0050143a;
          }
          if (uVar9 != 0x6e) {
            if (uVar9 != 0x6f) {
              if (uVar9 == 0x70) {
                local_410 = 8;
                goto LAB_005012e0;
              }
              if (uVar9 == 0x73) {
LAB_0050101f:
                uVar5 = local_410;
                if (local_410 == 0xffffffff) {
                  uVar5 = 0x7fffffff;
                }
                pwVar6 = param_3 + 2;
                local_418 = *(wchar_t **)param_3;
                param_3 = pwVar6;
                if ((local_40c & 0x20) != 0) {
                  if (local_418 == (wchar_t *)0x0) {
                    local_418 = (wchar_t *)PTR_DAT_0084bc48;
                  }
                  local_414 = 0;
                  pwVar6 = local_418;
                  if (0 < (int)uVar5) {
                    do {
                      if ((byte)*pwVar6 == 0) break;
                      if ((PTR_DAT_0084be08[(uint)(byte)*pwVar6 * 2 + 1] & 0x80) != 0) {
                        pwVar6 = (wchar_t *)((int)pwVar6 + 1);
                      }
                      pwVar6 = (wchar_t *)((int)pwVar6 + 1);
                      local_414 = local_414 + 1;
                    } while ((int)local_414 < (int)uVar5);
                  }
                  goto LAB_0050143a;
                }
                if (local_418 == (wchar_t *)0x0) {
                  local_418 = (wchar_t *)PTR_DAT_0084bc4c;
                }
                local_428 = 1;
                for (pwVar6 = local_418; (uVar5 != 0 && (uVar5 = uVar5 - 1, *pwVar6 != L'\0'));
                    pwVar6 = pwVar6 + 1) {
                }
                local_414 = (int)pwVar6 - (int)local_418 >> 1;
                goto LAB_00501437;
              }
              if (uVar9 != 0x75) {
                if (uVar9 != 0x78) goto LAB_0050143a;
                local_440 = 0x27;
                goto LAB_005012e3;
              }
              goto LAB_0050111c;
            }
            local_414 = 8;
            if ((local_40c & 0x80) != 0) {
              local_40c = local_40c | 0x200;
            }
            goto LAB_00501123;
          }
          if ((local_40c & 0x20) == 0) {
            **(int **)param_3 = local_41c;
          }
          else {
            *(undefined2 *)*(int **)param_3 = (undefined2)local_41c;
          }
          local_438 = 1;
          param_3 = param_3 + 2;
        }
        if (local_434 != (wchar_t *)0x0) {
          _free(local_434);
          local_434 = (wchar_t *)0x0;
        }
      }
      param_2 = puVar4;
      uVar9 = *param_2;
      if (uVar9 == 0) {
        return local_41c;
      }
    }
  }
  return local_41c;
}

