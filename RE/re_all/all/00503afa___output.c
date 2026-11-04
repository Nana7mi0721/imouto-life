
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */
/* Library Function - Single Match
    __output
   
   Library: Visual Studio 2003 Release */

int __output(undefined4 param_1,byte *param_2,wchar_t *param_3)

{
  byte bVar1;
  short *psVar2;
  uint uVar3;
  wchar_t *pwVar4;
  int iVar5;
  int iVar6;
  int extraout_ECX;
  byte bVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  bool bVar10;
  longlong lVar11;
  undefined4 local_258;
  undefined4 local_254;
  undefined1 *local_24c;
  int local_248;
  undefined4 local_244;
  int local_240;
  int local_23c;
  wchar_t *local_238;
  int local_234;
  int local_230;
  int local_22c;
  undefined1 local_228;
  char local_227;
  int local_224;
  undefined1 *local_220;
  wchar_t *local_21c;
  int local_218;
  uint local_214;
  wchar_t local_210 [255];
  undefined2 local_11;
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  local_220 = (undefined1 *)0x0;
  local_224 = 0;
  local_238 = (wchar_t *)0x0;
  bVar7 = *param_2;
  local_248 = 0;
  if (bVar7 != 0) {
    while (pbVar9 = param_2 + 1, -1 < local_224) {
      if (((char)bVar7 < ' ') || ('x' < (char)bVar7)) {
        uVar3 = 0;
      }
      else {
        uVar3 = (int)(char)(&DAT_007d2a78)[(char)bVar7] & 0xf;
      }
      local_248 = (int)(char)(&DAT_007d2a98)[uVar3 * 8 + local_248] >> 4;
      switch(local_248) {
      case 0:
switchD_00503b7f_caseD_0:
        local_234 = 0;
        if ((PTR_DAT_0084be08[(uint)bVar7 * 2 + 1] & 0x80) != 0) {
          write_char();
          pbVar9 = param_2 + 2;
        }
        param_2 = pbVar9;
        write_char();
        pbVar9 = param_2;
        break;
      case 1:
        local_218 = -1;
        local_244 = 0;
        local_23c = 0;
        local_230 = 0;
        local_22c = 0;
        local_214 = 0;
        local_234 = 0;
        break;
      case 2:
        if (bVar7 == 0x20) {
          local_214 = local_214 | 2;
        }
        else if (bVar7 == 0x23) {
          local_214 = local_214 | 0x80;
        }
        else if (bVar7 == 0x2b) {
          local_214 = local_214 | 1;
        }
        else if (bVar7 == 0x2d) {
          local_214 = local_214 | 4;
        }
        else if (bVar7 == 0x30) {
          local_214 = local_214 | 8;
        }
        break;
      case 3:
        if (bVar7 == 0x2a) {
          pwVar4 = param_3 + 2;
          local_230 = *(int *)param_3;
          param_3 = pwVar4;
          if (local_230 < 0) {
            local_214 = local_214 | 4;
            local_230 = -local_230;
          }
        }
        else {
          local_230 = (char)bVar7 + -0x30 + local_230 * 10;
        }
        break;
      case 4:
        local_218 = 0;
        break;
      case 5:
        if (bVar7 == 0x2a) {
          pwVar4 = param_3 + 2;
          local_218 = *(int *)param_3;
          param_3 = pwVar4;
          if (local_218 < 0) {
            local_218 = -1;
          }
        }
        else {
          local_218 = (char)bVar7 + -0x30 + local_218 * 10;
        }
        break;
      case 6:
        if (bVar7 == 0x49) {
          bVar1 = *pbVar9;
          if ((bVar1 == 0x36) && (param_2[2] == 0x34)) {
            local_214 = local_214 | 0x8000;
            pbVar9 = param_2 + 3;
          }
          else if ((bVar1 == 0x33) && (param_2[2] == 0x32)) {
            local_214 = local_214 & 0xffff7fff;
            pbVar9 = param_2 + 3;
          }
          else if (bVar1 != 100) {
            if (bVar1 != 0x69) {
              if (bVar1 != 0x6f) {
                if (bVar1 != 0x75) {
                  if (bVar1 != 0x78) {
                    if (bVar1 != 0x58) {
                      local_248 = 0;
                      goto switchD_00503b7f_caseD_0;
                    }
                  }
                }
              }
            }
          }
        }
        else if (bVar7 == 0x68) {
          local_214 = local_214 | 0x20;
        }
        else if (bVar7 == 0x6c) {
          local_214 = local_214 | 0x10;
        }
        else if (bVar7 == 0x77) {
          local_214 = local_214 | 0x800;
        }
        break;
      case 7:
        if ((char)bVar7 < 'h') {
          if ((char)bVar7 < 'e') {
            if ((char)bVar7 < 'Y') {
              if (bVar7 == 0x58) {
LAB_0050403d:
                local_240 = 7;
LAB_00504040:
                local_220 = (undefined1 *)0x10;
                if ((local_214 & 0x80) != 0) {
                  local_227 = (char)local_240 + 'Q';
                  local_228 = 0x30;
                  local_22c = 2;
                }
                goto LAB_00503e70;
              }
              if (bVar7 == 0x43) {
                if ((local_214 & 0x830) == 0) {
                  local_214 = local_214 | 0x800;
                }
                goto LAB_00503e1f;
              }
              if ((bVar7 != 0x45) && (bVar7 != 0x47)) {
                if (bVar7 == 0x53) {
                  if ((local_214 & 0x830) == 0) {
                    local_214 = local_214 | 0x800;
                  }
                  goto LAB_00503da2;
                }
                goto LAB_00504197;
              }
              local_244 = 1;
              bVar7 = bVar7 + 0x20;
              goto LAB_00503df3;
            }
            if (bVar7 == 0x5a) {
              pwVar4 = param_3 + 2;
              psVar2 = *(short **)param_3;
              param_3 = pwVar4;
              if ((psVar2 == (short *)0x0) ||
                 (local_21c = *(wchar_t **)(psVar2 + 2), local_21c == (wchar_t *)0x0)) {
                local_21c = (wchar_t *)PTR_DAT_0084bc48;
                pwVar4 = (wchar_t *)PTR_DAT_0084bc48;
                goto LAB_00503fb1;
              }
              local_220 = (undefined1 *)(int)*psVar2;
              if ((local_214 & 0x800) == 0) {
                local_234 = 0;
              }
              else {
                local_220 = (undefined1 *)((int)local_220 / 2);
                local_234 = 1;
              }
              goto LAB_00504194;
            }
            if (bVar7 == 99) {
LAB_00503e1f:
              if ((local_214 & 0x810) == 0) {
                local_210[0]._0_1_ = (char)*param_3;
                local_220 = (undefined1 *)0x1;
              }
              else {
                local_220 = (undefined1 *)_wctomb((char *)local_210,*param_3);
                if ((int)local_220 < 0) {
                  local_23c = 1;
                }
              }
              local_21c = local_210;
              param_3 = param_3 + 2;
            }
            else if (bVar7 == 100) goto LAB_00503e65;
          }
          else {
LAB_00503df3:
            local_214 = local_214 | 0x40;
            pwVar4 = local_210;
            local_21c = pwVar4;
            if (local_218 < 0) {
              local_218 = 6;
            }
            else if (local_218 == 0) {
              if (bVar7 == 0x67) {
                local_218 = 1;
              }
            }
            else {
              if (0x200 < local_218) {
                local_218 = 0x200;
              }
              if (0xa3 < local_218) {
                local_238 = _malloc(local_218 + 0x15d);
                if (local_238 == (wchar_t *)0x0) {
                  local_218 = 0xa3;
                }
                else {
                  pwVar4 = local_238;
                  local_21c = local_238;
                }
              }
            }
            local_258 = *(undefined4 *)param_3;
            local_254 = *(undefined4 *)(param_3 + 2);
            (*(code *)PTR_FUN_0084b700)(&local_258,pwVar4,(int)(char)bVar7,local_218,local_244);
            uVar3 = local_214 & 0x80;
            if ((uVar3 != 0) && (local_218 == 0)) {
              (*(code *)PTR_FUN_0084b70c)(pwVar4);
            }
            if ((bVar7 == 0x67) && (uVar3 == 0)) {
              (*(code *)PTR_FUN_0084b704)(pwVar4);
            }
            if ((char)*pwVar4 == '-') {
              local_214 = local_214 | 0x100;
              pwVar4 = (wchar_t *)((int)pwVar4 + 1);
              local_21c = pwVar4;
            }
            param_3 = param_3 + 4;
LAB_00503fb1:
            local_220 = (undefined1 *)_strlen((char *)pwVar4);
LAB_00504194:
          }
LAB_00504197:
          uVar3 = local_214;
          if (local_23c == 0) {
            if ((local_214 & 0x40) != 0) {
              if ((local_214 & 0x100) == 0) {
                if ((local_214 & 1) == 0) {
                  if ((local_214 & 2) == 0) goto LAB_005041cf;
                  local_228 = 0x20;
                }
                else {
                  local_228 = 0x2b;
                }
              }
              else {
                local_228 = 0x2d;
              }
              local_22c = 1;
            }
LAB_005041cf:
            iVar6 = (local_230 - local_22c) - (int)local_220;
            if ((local_214 & 0xc) == 0) {
              write_multi_char(0x20,iVar6,param_1);
            }
            write_string(local_22c);
            if (((uVar3 & 8) != 0) && ((uVar3 & 4) == 0)) {
              write_multi_char(0x30,iVar6,param_1);
            }
            if ((local_234 == 0) || ((int)local_220 < 1)) {
              write_string(local_220);
            }
            else {
              local_24c = local_220;
              pwVar4 = local_21c;
              do {
                local_24c = local_24c + 0xffffffff;
                iVar5 = _wctomb((char *)((int)&local_11 + 1),*pwVar4);
                pwVar4 = pwVar4 + 1;
                if (iVar5 < 1) break;
                write_string(iVar5);
              } while (local_24c != (undefined1 *)0x0);
            }
            if ((local_214 & 4) != 0) {
              write_multi_char(0x20,iVar6,param_1);
            }
          }
        }
        else {
          if (bVar7 == 0x69) {
LAB_00503e65:
            local_214 = local_214 | 0x40;
LAB_00503e69:
            local_220 = (undefined1 *)0xa;
LAB_00503e70:
            if ((local_214 & 0x8000) == 0) {
              if ((local_214 & 0x20) == 0) {
                uVar3 = *(uint *)param_3;
                if ((local_214 & 0x40) == 0) {
                  iVar6 = 0;
                  param_3 = param_3 + 2;
                  goto LAB_005040e1;
                }
              }
              else if ((local_214 & 0x40) == 0) {
                uVar3 = (uint)(ushort)*param_3;
              }
              else {
                uVar3 = (uint)*param_3;
              }
              iVar6 = (int)uVar3 >> 0x1f;
              param_3 = param_3 + 2;
            }
            else {
              uVar3 = *(uint *)param_3;
              iVar6 = *(int *)(param_3 + 2);
              param_3 = param_3 + 4;
            }
LAB_005040e1:
            if ((((local_214 & 0x40) != 0) && (iVar6 < 1)) && (iVar6 < 0)) {
              bVar10 = uVar3 != 0;
              uVar3 = -uVar3;
              iVar6 = -(iVar6 + (uint)bVar10);
              local_214 = local_214 | 0x100;
            }
            if ((local_214 & 0x8000) == 0) {
              iVar6 = 0;
            }
            lVar11 = CONCAT44(iVar6,uVar3);
            if (local_218 < 0) {
              local_218 = 1;
            }
            else {
              local_214 = local_214 & 0xfffffff7;
              if (0x200 < local_218) {
                local_218 = 0x200;
              }
            }
            if (uVar3 == 0 && iVar6 == 0) {
              local_22c = 0;
            }
            pwVar4 = &local_11;
            while( true ) {
              puVar8 = (undefined1 *)lVar11;
              iVar6 = local_218 + -1;
              if ((local_218 < 1) && (lVar11 == 0)) break;
              local_218 = iVar6;
              lVar11 = __aulldvrm(lVar11,local_220,(int)local_220 >> 0x1f);
              iVar6 = extraout_ECX + 0x30;
              if (0x39 < iVar6) {
                iVar6 = iVar6 + local_240;
              }
              *(char *)pwVar4 = (char)iVar6;
              pwVar4 = (wchar_t *)((int)pwVar4 + -1);
              local_24c = puVar8;
            }
            local_220 = (undefined1 *)((int)local_210 + -(int)pwVar4 + 0x1ff);
            local_21c = (wchar_t *)((int)pwVar4 + 1);
            local_218 = iVar6;
            if (((local_214 & 0x200) != 0) &&
               ((*(char *)local_21c != '0' || (local_220 == (undefined1 *)0x0)))) {
              *(char *)pwVar4 = '0';
              local_220 = (undefined1 *)((int)local_210 + -(int)pwVar4 + 0x200);
              local_21c = pwVar4;
              goto LAB_00504194;
            }
            goto LAB_00504197;
          }
          if (bVar7 != 0x6e) {
            if (bVar7 != 0x6f) {
              if (bVar7 == 0x70) {
                local_218 = 8;
                goto LAB_0050403d;
              }
              if (bVar7 == 0x73) {
LAB_00503da2:
                iVar6 = local_218;
                if (local_218 == -1) {
                  iVar6 = 0x7fffffff;
                }
                local_21c = *(wchar_t **)param_3;
                if ((local_214 & 0x810) == 0) {
                  if (local_21c == (wchar_t *)0x0) {
                    local_21c = (wchar_t *)PTR_DAT_0084bc48;
                  }
                  for (pwVar4 = local_21c;
                      (iVar6 != 0 && (iVar6 = iVar6 + -1, (char)*pwVar4 != '\0'));
                      pwVar4 = (wchar_t *)((int)pwVar4 + 1)) {
                  }
                  local_220 = (undefined1 *)((int)pwVar4 - (int)local_21c);
                  param_3 = param_3 + 2;
                }
                else {
                  if (local_21c == (wchar_t *)0x0) {
                    local_21c = (wchar_t *)PTR_DAT_0084bc4c;
                  }
                  local_234 = 1;
                  for (pwVar4 = local_21c; (iVar6 != 0 && (iVar6 = iVar6 + -1, *pwVar4 != L'\0'));
                      pwVar4 = pwVar4 + 1) {
                  }
                  local_220 = (undefined1 *)((int)pwVar4 - (int)local_21c >> 1);
                  param_3 = param_3 + 2;
                }
                goto LAB_00504194;
              }
              if (bVar7 != 0x75) {
                if (bVar7 != 0x78) goto LAB_00504197;
                local_240 = 0x27;
                goto LAB_00504040;
              }
              goto LAB_00503e69;
            }
            local_220 = (undefined1 *)0x8;
            if ((local_214 & 0x80) != 0) {
              local_214 = local_214 | 0x200;
            }
            goto LAB_00503e70;
          }
          if ((local_214 & 0x20) == 0) {
            **(int **)param_3 = local_224;
          }
          else {
            *(undefined2 *)*(int **)param_3 = (undefined2)local_224;
          }
          local_23c = 1;
          param_3 = param_3 + 2;
        }
        if (local_238 != (wchar_t *)0x0) {
          _free(local_238);
          local_238 = (wchar_t *)0x0;
        }
      }
      param_2 = pbVar9;
      bVar7 = *param_2;
      if (bVar7 == 0) {
        return local_224;
      }
    }
  }
  return local_224;
}

