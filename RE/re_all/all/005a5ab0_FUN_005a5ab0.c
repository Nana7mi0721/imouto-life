
undefined4
FUN_005a5ab0(int param_1,undefined4 param_2,int *param_3,int param_4,undefined4 param_5,int param_6,
            int param_7,char *param_8,int param_9,int param_10,undefined4 param_11,int param_12,
            undefined4 param_13)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_90;
  uint local_8c;
  int local_88;
  int local_84;
  int local_80;
  undefined4 local_7c;
  undefined4 local_78;
  char local_71;
  int local_70;
  int local_6c;
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  
  cVar1 = *param_8;
  iVar5 = -1;
  local_78 = 0;
  local_7c = 0;
  if ((((cVar1 == '\x01') || (cVar1 == '\x02')) || (cVar1 == '\x03')) ||
     ((cVar1 == '\x04' || (local_68 = 0, cVar1 == '\x05')))) {
    local_68 = 1;
  }
  local_71 = *(char *)(param_1 + 9);
  local_2c = (-(uint)(local_71 != '\0') & 5) + 1;
  if ((((*param_3 == 0) && (param_3[2] == param_6)) &&
      ((param_3[1] == 0 &&
       ((param_3[3] == param_7 &&
        (iVar4 = *(int *)(param_1 + 0x34), iVar4 <= *(int *)(param_8 + 0x438))))))) &&
     ((((cVar1 == '\x01' && (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) == 0x31545844)) ||
       (((cVar1 == '\x02' && (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) == 0x32545844)) ||
        (((cVar1 == '\x03' && (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) == 0x33545844))
         || ((cVar1 == '\x04' && (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) == 0x34545844)
             ))))))) ||
      ((cVar1 == '\x05' && (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) == 0x35545844))))))
  {
    if (local_71 != '\0') {
      local_84 = *(int *)(param_8 + 0x434);
      local_80 = 0;
      do {
        local_88 = param_6;
        local_90 = param_7;
        local_8c = 0;
        if (0 < iVar4) {
          do {
            if (local_68 == 0) {
              iVar4 = (uint)(byte)param_8[4] * local_90 * local_88;
            }
            else {
              iVar4 = ((int)(local_90 + 3 + (local_90 + 3 >> 0x1f & 3U)) >> 2) *
                      ((int)(local_88 + 3 + (local_88 + 3 >> 0x1f & 3U)) >> 2) *
                      (uint)(byte)param_8[5] * 2;
            }
            if (param_4 == 0) {
              iVar2 = FUN_005d5e30(param_5,local_80,local_8c,&local_64,0,0);
            }
            else {
              iVar5 = FUN_005a4db0(local_88,local_90,
                                   *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4),
                                   param_13);
              while (iVar5 == -1) {
                iVar5 = FUN_005501a0();
                if (iVar5 != 0) {
                  return 0xffffffff;
                }
                FUN_0056da20(1);
                iVar5 = FUN_005a4db0(local_88,local_90,
                                     *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4),
                                     param_13);
              }
              local_7c = (&DAT_00ecfb30)[iVar5 * 6];
              iVar2 = FUN_005d5f00(local_7c,&local_64,0,0x2000,param_13);
            }
            if (iVar2 != 0) {
              FUN_0056bb10(&DAT_007fc6f4);
              return 0xffffffff;
            }
            FUN_0056d420(local_60,local_84,iVar4);
            if (param_4 == 0) {
              FUN_005d5eb0(param_5,local_80,local_8c);
            }
            else {
              FUN_005d5f60(local_7c,param_13);
              FUN_005d5dd0(param_5,local_80,local_8c,&local_78,param_13);
              FUN_005d5a40(local_7c,0,local_78,0,param_13);
              FUN_005d5640(local_78,param_13);
              FUN_0059d1e0(iVar5,param_13);
              iVar5 = -1;
            }
            local_84 = local_84 + iVar4;
            local_90 = local_90 >> 1;
            local_88 = local_88 >> 1;
            if (local_88 < 1) {
              local_88 = 1;
            }
            if (local_90 < 1) {
              local_90 = 1;
            }
            local_8c = local_8c + 1;
            iVar4 = *(int *)(param_1 + 0x34);
          } while ((int)local_8c < iVar4);
        }
        local_80 = local_80 + 1;
        if (5 < local_80) {
          return 0;
        }
      } while( true );
    }
    local_88 = param_6;
    local_90 = param_7;
    local_84 = *(int *)(param_8 + 0x434);
    local_8c = 0;
    if (0 < iVar4) {
      while( true ) {
        if (local_68 == 0) {
          iVar4 = (uint)(byte)param_8[4] * local_90 * local_88;
        }
        else {
          iVar4 = ((int)(local_90 + 3 + (local_90 + 3 >> 0x1f & 3U)) >> 2) *
                  ((int)(local_88 + 3 + (local_88 + 3 >> 0x1f & 3U)) >> 2) * (uint)(byte)param_8[5]
                  * 2;
        }
        if (param_4 == 0) {
          iVar2 = FUN_005d5d10(param_5,local_8c,&local_64,0,0);
        }
        else {
          iVar5 = FUN_005a4db0(local_88,local_90,
                               *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4),param_13);
          while (iVar5 == -1) {
            iVar5 = FUN_005501a0();
            if (iVar5 != 0) {
              return 0xffffffff;
            }
            FUN_0056da20(1);
            iVar5 = FUN_005a4db0(local_88,local_90,
                                 *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4),param_13
                                );
          }
          local_7c = (&DAT_00ecfb30)[iVar5 * 6];
          iVar2 = FUN_005d5f00(local_7c,&local_64,0,0x2000,param_13);
        }
        if (iVar2 != 0) break;
        FUN_0056d420(local_60,local_84,iVar4);
        if (param_4 == 0) {
          FUN_005d5d80(param_5,local_8c);
        }
        else {
          FUN_005d5f60(local_7c,param_13);
          FUN_005d5cc0(param_5,local_8c,&local_78,param_13);
          FUN_005d5a40(local_7c,0,local_78,0,param_13);
          FUN_005d5640(local_78,param_13);
          FUN_0059d1e0(iVar5,param_13);
          iVar5 = -1;
        }
        local_84 = local_84 + iVar4;
        local_90 = local_90 >> 1;
        local_88 = local_88 >> 1;
        if (local_88 < 1) {
          local_88 = 1;
        }
        if (local_90 < 1) {
          local_90 = 1;
        }
        local_8c = local_8c + 1;
        if (*(int *)(param_1 + 0x34) <= (int)local_8c) {
          return 0;
        }
      }
LAB_005a6003:
      FUN_0056bb10(&DAT_007fc6c4);
      return 0xffffffff;
    }
  }
  else {
    iVar4 = *(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4);
    if ((((iVar4 == 0x31545844) || (iVar4 == 0x32545844)) || (iVar4 == 0x33545844)) ||
       ((iVar4 == 0x34545844 || (iVar4 == 0x35545844)))) {
      FUN_0056bb10(&DAT_007fc5e0);
    }
    else {
      iVar4 = *(int *)(param_1 + 0x34);
      if (*(int *)(param_8 + 0x438) < iVar4) {
        iVar4 = 1;
        local_5c = 1;
        if (1 < param_3[2] - *param_3) {
          do {
            iVar4 = iVar4 * 2;
          } while (iVar4 < param_3[2] - *param_3);
          local_5c = iVar4;
        }
        local_58 = 1;
        if (1 < param_3[3] - param_3[1]) {
          local_58 = 1;
          do {
            local_58 = local_58 * 2;
          } while (local_58 < param_3[3] - param_3[1]);
        }
        local_4c = (uint)*(byte *)(param_10 + 4) * local_5c;
        local_70 = local_4c * local_58;
        iVar4 = FUN_0056e030(local_70 * 2,
                             "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D9.cpp",
                             0x60ea);
        local_28 = local_70 + iVar4;
        if (iVar4 == 0) {
          FUN_0056bb10(&DAT_007fc678);
          return 0xffffffff;
        }
        local_70 = *(int *)(param_8 + 0x42c) * *(int *)(param_8 + 0x430);
        local_24 = *(int *)(param_9 + 0x42c) * *(int *)(param_9 + 0x430);
        local_80 = 0;
        if (0 < local_2c) {
          local_54 = 0;
          local_50 = 0;
          do {
            local_34 = local_58;
            local_68 = local_58;
            local_88 = param_6;
            local_30 = local_5c;
            local_48 = local_5c;
            local_90 = param_7;
            local_8c = 0;
            if (0 < *(int *)(param_1 + 0x34)) {
              do {
                if (local_8c == 0) {
                  if (((param_12 == 0) || (*(char *)(param_10 + 0xb) == '\0')) ||
                     (*(int *)(param_9 + 0x434) != 0)) {
                    uVar3 = 0;
                  }
                  else {
                    uVar3 = 1;
                  }
                  FUN_00549b20(iVar4,local_4c,param_10,*(int *)(param_8 + 0x434) + local_54,
                               *(undefined4 *)(param_8 + 0x430),param_8,
                               *(int *)(param_9 + 0x434) + local_50,*(undefined4 *)(param_9 + 0x430)
                               ,param_9,0,0,param_2,0,uVar3,*(undefined4 *)(param_1 + 0x1c),
                               DAT_00a52a50,0,param_11,0,0);
                  local_6c = iVar4;
                }
                else {
                  if ((local_8c & 1) == 0) {
                    iVar2 = local_28;
                    local_6c = iVar4;
                  }
                  else {
                    local_6c = local_28;
                    iVar2 = iVar4;
                  }
                  FUN_00542590(param_10,local_6c,local_4c,iVar2,local_4c,0,0,0,0,local_30,local_34);
                }
                local_40 = param_3[1] >> ((byte)local_8c & 0x1f);
                local_44 = *param_3 >> ((byte)local_8c & 0x1f);
                local_3c = param_3[2] >> ((byte)local_8c & 0x1f);
                local_38 = param_3[3] >> ((byte)local_8c & 0x1f);
                if (local_3c == local_44) {
                  local_3c = local_44 + 1;
                }
                if (local_38 == local_40) {
                  local_38 = local_40 + 1;
                }
                if (param_4 == 0) {
                  if (*(char *)(param_1 + 9) == '\0') {
                    iVar2 = FUN_005d5d10(param_5,local_8c,&local_64,&local_44,0);
                    goto joined_r0x005a676d;
                  }
                  iVar2 = FUN_005d5e30(param_5,local_80,local_8c,&local_64,&local_44);
                  if (iVar2 != 0) {
                    FUN_0056e1d0(iVar4);
                    FUN_0056bb10(&DAT_007fc6f4);
                    return 0xffffffff;
                  }
                }
                else {
                  iVar5 = FUN_005a4db0(local_88,local_90,
                                       *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4),
                                       param_13);
                  while (iVar5 == -1) {
                    iVar5 = FUN_005501a0();
                    if (iVar5 != 0) {
                      FUN_0056e1d0(iVar4);
                      FUN_0056bb10(&DAT_007fc630);
                      return 0xffffffff;
                    }
                    FUN_0056da20(1);
                    iVar5 = FUN_005a4db0(local_88,local_90,
                                         *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4),
                                         param_13);
                  }
                  local_7c = (&DAT_00ecfb30)[iVar5 * 6];
                  iVar2 = FUN_005d5f00(local_7c,&local_64,&local_44,0x2000,param_13);
joined_r0x005a676d:
                  if (iVar2 != 0) {
                    FUN_0056e1d0(iVar4);
                    FUN_0056bb10(&DAT_007fc6c4);
                    return 0xffffffff;
                  }
                }
                iVar2 = local_48;
                local_c = local_68;
                local_18 = 0;
                local_14 = 0;
                local_10 = local_48;
                FUN_00549b20(local_60,local_64,param_10,local_6c,local_4c,param_10,0,0,0,0,0,
                             &local_18,0,0,0,0,0,0,0,0);
                if (param_4 == 0) {
                  if (*(char *)(param_1 + 9) == '\0') {
                    FUN_005d5d80(param_5,local_8c);
                  }
                  else {
                    FUN_005d5eb0(param_5,local_80);
                  }
                }
                else {
                  local_6c = 0;
                  FUN_005d5f60(local_7c,param_13);
                  if (*(char *)(param_1 + 9) == '\0') {
                    FUN_005d5cc0(param_5,local_8c,&local_6c,param_13);
                  }
                  else {
                    FUN_005d5dd0(param_5,local_80,local_8c,&local_6c);
                  }
                  local_20 = local_44;
                  local_1c = local_40;
                  FUN_005d5a40(local_7c,&local_44,local_6c,&local_20,param_13);
                  FUN_005d5640(local_6c,param_13);
                  FUN_0059d1e0(iVar5,param_13);
                  iVar5 = -1;
                }
                local_30 = iVar2;
                local_48 = iVar2 >> 1;
                local_34 = local_68;
                local_68 = local_68 >> 1;
                if (local_48 == 0) {
                  local_48 = 1;
                }
                if (local_68 == 0) {
                  local_68 = 1;
                }
                local_90 = local_90 >> 1;
                local_88 = local_88 >> 1;
                if (local_88 < 1) {
                  local_88 = 1;
                }
                if (local_90 < 1) {
                  local_90 = 1;
                }
                local_8c = local_8c + 1;
              } while ((int)local_8c < *(int *)(param_1 + 0x34));
            }
            local_50 = local_50 + local_24;
            local_80 = local_80 + 1;
            local_54 = local_54 + local_70;
          } while (local_80 < local_2c);
        }
        FUN_0056e1d0(iVar4);
        return 0;
      }
      local_84 = *(int *)(param_8 + 0x434);
      if (local_71 != '\0') {
        local_80 = 0;
        do {
          local_90 = param_7;
          local_8c = 0;
          iVar2 = param_6;
          if (0 < iVar4) {
            do {
              local_70 = (uint)(byte)param_8[4] * local_90 * iVar2;
              if (param_4 == 0) {
                iVar4 = FUN_005d5e30(param_5,local_80,local_8c,&local_64,0,0);
              }
              else {
                iVar5 = FUN_005a4db0(iVar2,local_90,
                                     *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4),
                                     param_13);
                while (iVar5 == -1) {
                  iVar5 = FUN_005501a0();
                  if (iVar5 != 0) {
                    return 0xffffffff;
                  }
                  FUN_0056da20(1);
                  iVar5 = FUN_005a4db0(iVar2,local_90,
                                       *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4),
                                       param_13);
                }
                local_7c = (&DAT_00ecfb30)[iVar5 * 6];
                iVar4 = FUN_005d5f00(local_7c,&local_64,0,0x2000,param_13);
              }
              if (iVar4 != 0) goto LAB_005a6003;
              FUN_0056d420(local_60,local_84,local_70);
              if (param_4 == 0) {
                FUN_005d5eb0(param_5,local_80,local_8c);
              }
              else {
                FUN_005d5f60(local_7c,param_13);
                FUN_005d5dd0(param_5,local_80,local_8c,&local_78,param_13);
                FUN_005d5a40(local_7c,0,local_78,0,param_13);
                FUN_005d5640(local_78,param_13);
                FUN_0059d1e0(iVar5,param_13);
                iVar5 = -1;
              }
              local_84 = local_84 + local_70;
              local_90 = local_90 >> 1;
              iVar2 = iVar2 >> 1;
              if (iVar2 < 1) {
                iVar2 = 1;
              }
              if (local_90 < 1) {
                local_90 = 1;
              }
              local_8c = local_8c + 1;
              iVar4 = *(int *)(param_1 + 0x34);
            } while ((int)local_8c < iVar4);
          }
          local_80 = local_80 + 1;
          if (5 < local_80) {
            return 0;
          }
        } while( true );
      }
      local_90 = param_7;
      local_8c = 0;
      if (0 < iVar4) {
        do {
          local_70 = (uint)(byte)param_8[4] * local_90 * param_6;
          if (param_4 == 0) {
            iVar4 = FUN_005d5d10(param_5,local_8c,&local_64,0,0);
          }
          else {
            iVar5 = FUN_005a4db0(param_6,local_90,
                                 *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4),param_13
                                );
            if (iVar5 == -1) {
              do {
                iVar4 = FUN_005501a0();
                if (iVar4 != 0) {
                  if (iVar5 == -1) {
                    return 0xffffffff;
                  }
                  break;
                }
                FUN_0056da20(1);
                iVar5 = FUN_005a4db0(param_6,local_90,
                                     *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4),
                                     param_13);
              } while (iVar5 == -1);
            }
            local_7c = (&DAT_00ecfb30)[iVar5 * 6];
            iVar4 = FUN_005d5f00(local_7c,&local_64,0,0x2000,param_13);
          }
          if (iVar4 != 0) goto LAB_005a6003;
          FUN_0056d420(local_60,local_84,local_70);
          if (param_4 == 0) {
            FUN_005d5d80(param_5,local_8c);
          }
          else {
            FUN_005d5f60(local_7c,param_13);
            FUN_005d5cc0(param_5,local_8c,&local_78,param_13);
            FUN_005d5a40(local_7c,0,local_78,0,param_13);
            FUN_005d5640(local_78,param_13);
            FUN_0059d1e0(iVar5,param_13);
            iVar5 = -1;
          }
          local_84 = local_84 + local_70;
          local_90 = local_90 >> 1;
          param_6 = param_6 >> 1;
          if (param_6 < 1) {
            param_6 = 1;
          }
          if (local_90 < 1) {
            local_90 = 1;
          }
          local_8c = local_8c + 1;
          if (*(int *)(param_1 + 0x34) <= (int)local_8c) {
            return 0;
          }
        } while( true );
      }
    }
  }
  return 0;
}

