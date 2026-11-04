
undefined4
FUN_005b49b0(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4,char *param_5,
            int param_6,undefined4 param_7,int param_8,int param_9,int param_10)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  undefined *puVar10;
  int local_74;
  int local_70;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int *local_54;
  int *local_50;
  undefined4 local_4c;
  int local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18 [6];
  
  local_74 = -1;
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_68 = 0;
  iVar2 = FUN_005d4b00();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  FUN_00568ca0(param_10);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  cVar1 = *param_5;
  if ((((cVar1 == '\x01') || (cVar1 == '\x02')) || (cVar1 == '\x03')) ||
     ((cVar1 == '\x04' || (local_4c = 0, cVar1 == '\x05')))) {
    local_4c = 1;
  }
  local_60 = param_1[2] - *param_1;
  local_64 = param_1[3] - param_1[1];
  if ((local_60 < 1) || (local_64 < 1)) {
    return 0;
  }
  if (param_10 == 0) {
    if (DAT_00cc47d0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_4 < 0) {
      return 0xffffffff;
    }
    if ((param_4 & 0x7c000000) != DAT_00cc47f8) {
      return 0xffffffff;
    }
    if (DAT_00cc4800 <= (int)(param_4 & 0xffff)) {
      return 0xffffffff;
    }
    local_50 = *(int **)(DAT_00cc47d4 + (param_4 & 0xffff) * 4);
    if (local_50 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*local_50 * 0x10000 != (param_4 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (local_50[4] != 0) {
      return 0xffffffff;
    }
  }
  else if ((((DAT_00cc47d0 == 0) || ((int)param_4 < 0)) || ((param_4 & 0x7c000000) != DAT_00cc47f8))
          || (((DAT_00cc4800 <= (int)(param_4 & 0xffff) ||
               (local_50 = *(int **)(DAT_00cc47d4 + (param_4 & 0xffff) * 4), local_50 == (int *)0x0)
               ) || (*local_50 * 0x10000 != (param_4 & 0x3ff0000))))) {
    return 0xffffffff;
  }
  iVar2 = local_50[0x13];
  local_70 = 1;
  if (*(int *)(param_5 + 0x43c) != 0) {
    local_70 = *(int *)(param_5 + 0x43c);
  }
  iVar3 = FUN_00598180(*(undefined4 *)(&DAT_00ddb4d4 + *(int *)(iVar2 + 4) * 4));
  local_48 = 0;
  local_44 = 0;
  if (*(char *)(iVar2 + 0xb) != '\0') {
    iVar9 = 0;
    if (0 < local_70) {
      piVar8 = local_18;
      do {
        iVar4 = FUN_005d59b0(local_60,local_64,
                             *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(iVar2 + 4) * 4),2,piVar8,0,
                             param_10);
        if (iVar4 != 0) break;
        FUN_005d5f00(*piVar8,&local_40,0,0x2000,param_10);
        local_38 = 0;
        local_34 = 0;
        local_30 = local_60;
        local_2c = local_64;
        if (((param_8 == 0) || (*(char *)(iVar3 + 0xb) == '\0')) ||
           (local_54 = (int *)0x1, *(int *)(param_6 + 0x434) != 0)) {
          local_54 = (int *)0x0;
        }
        FUN_00549b20(local_3c,local_40,iVar3,
                     *(int *)(param_5 + 0x42c) * *(int *)(param_5 + 0x430) * iVar9 +
                     *(int *)(param_5 + 0x434),*(int *)(param_5 + 0x430),param_5,
                     *(int *)(param_6 + 0x42c) * *(int *)(param_6 + 0x430) * iVar9 +
                     *(int *)(param_6 + 0x434),*(int *)(param_6 + 0x430),param_6,local_48,local_44,
                     &local_38,0,local_54,*(undefined4 *)(iVar2 + 0x1c),DAT_00a52a50,0,param_7,0,0);
        FUN_005d5f60(*piVar8,param_10);
        iVar9 = iVar9 + 1;
        piVar8 = piVar8 + 1;
      } while (iVar9 < local_70);
    }
    if (local_70 != iVar9) {
      if ((1 < local_70) || (1 < *(int *)(iVar2 + 0x38))) {
LAB_005b4d30:
        puVar10 = &DAT_007fcc38;
LAB_005b53fc:
        FUN_0056bb10(puVar10);
LAB_005b5404:
        iVar2 = 0;
        do {
          if (local_18[iVar2] != 0) {
            FUN_005d5640(local_18[iVar2],param_10);
            local_18[iVar2] = 0;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < 6);
        if (local_68 != 0) {
          FUN_005d5640(local_68,param_10);
          local_68 = 0;
        }
        if (local_74 != -1) {
          FUN_0059d160(local_74,param_10);
        }
        return 0xffffffff;
      }
      if (param_9 == 1) {
        uVar7 = *(undefined4 *)(iVar2 + 0x50);
        uVar6 = *(undefined4 *)(iVar2 + 0x54);
        puVar5 = *(undefined4 **)(iVar2 + 0x3c);
      }
      else {
        puVar5 = (undefined4 *)local_50[0x40];
        uVar7 = puVar5[5];
        uVar6 = puVar5[6];
        puVar5 = (undefined4 *)*puVar5;
      }
      local_50 = (int *)*puVar5;
      iVar4 = FUN_005d5820(uVar7,uVar6,1,0,*(undefined4 *)(&DAT_00ddb4d4 + *(int *)(iVar2 + 4) * 4),
                           2,&local_68,0,param_10);
      if (iVar4 != 0) goto LAB_005b4d30;
      FUN_005d5d10(local_68,0,&local_40,0,0x2000,param_10);
      local_38 = 0;
      local_34 = 0;
      local_30 = local_60;
      local_2c = local_64;
      if (((param_8 == 0) || (*(char *)(iVar3 + 0xb) == '\0')) ||
         (local_4c = 1, *(int *)(param_6 + 0x434) != 0)) {
        local_4c = 0;
      }
      FUN_00549b20(local_3c,local_40,iVar3,
                   *(int *)(param_5 + 0x42c) * *(int *)(param_5 + 0x430) * iVar9 +
                   *(int *)(param_5 + 0x434),*(int *)(param_5 + 0x430),param_5,
                   *(int *)(param_6 + 0x42c) * *(int *)(param_6 + 0x430) * iVar9 +
                   *(int *)(param_6 + 0x434),*(int *)(param_6 + 0x430),param_6,local_48,local_44,
                   &local_38,0,local_4c,*(undefined4 *)(iVar2 + 0x1c),DAT_00a52a50,0,param_7,0,0);
      FUN_005d5d80(local_68,0,param_10);
      FUN_005d5ab0(local_68,local_50,param_10);
      goto LAB_005b4e4f;
    }
  }
  if (param_9 == 1) {
    piVar8 = (int *)(iVar2 + 0x3c);
    local_5c = 0;
    if (0 < *(int *)(iVar2 + 0x38)) {
      do {
        iVar9 = FUN_00518d50(piVar8,param_1,local_60,local_64,param_2,param_3,&local_28,&local_38,
                             local_4c);
        if (-1 < iVar9) {
          if (*(char *)(iVar2 + 0xb) == '\x01') {
            iVar9 = 0;
            local_48 = local_28;
            local_44 = local_24;
            if (0 < local_70) {
              do {
                FUN_005d5a40(local_18[iVar9],&local_38,*(undefined4 *)(*piVar8 + 4 + iVar9 * 4),
                             &local_48,param_10);
                iVar9 = iVar9 + 1;
              } while (iVar9 < local_70);
            }
            if (*(int *)(*piVar8 + 0x1c) != 0) {
              FUN_005d5a40(local_18[0],&local_38,*(int *)(*piVar8 + 0x1c),&local_48,param_10);
            }
          }
          else {
            if ((local_20 - local_28 == piVar8[5]) && (local_1c - local_24 == piVar8[6])) {
              local_58 = 1;
              if (*(char *)(iVar2 + 0xd) != '\0') goto LAB_005b5003;
              local_74 = FUN_005a7dc0(iVar2,piVar8,param_10);
              if (local_74 == -1) {
                do {
                  iVar9 = FUN_005501a0();
                  if (iVar9 != 0) {
                    if (local_74 != -1) goto LAB_005b5080;
                    goto LAB_005b5404;
                  }
                  FUN_0056da20(1);
                  local_74 = FUN_005a7dc0(iVar2,piVar8,param_10);
                } while (local_74 == -1);
                uVar7 = (&DAT_00ec3b2c)[local_74 * 6];
              }
              else {
LAB_005b5080:
                uVar7 = (&DAT_00ec3b2c)[local_74 * 6];
              }
            }
            else {
              local_58 = 0;
LAB_005b5003:
              uVar7 = *(undefined4 *)*piVar8;
              local_74 = -1;
            }
            uVar6 = 1;
            if (*(int *)(iVar2 + 0x34) < 2) {
              if ((local_58 != 0) || (*(char *)(iVar2 + 0xd) != '\0')) {
                uVar6 = 0;
              }
              iVar9 = FUN_005a69a0(iVar2,&local_38,&local_28,uVar6,uVar7,piVar8[5],piVar8[6],
                                   piVar8[3],piVar8[4],param_5,param_6,iVar3,param_7,param_8,
                                   param_10);
            }
            else {
              if ((local_58 != 0) || (*(char *)(iVar2 + 0xd) != '\0')) {
                uVar6 = 0;
              }
              iVar9 = FUN_005a5ab0(iVar2,&local_38,&local_28,uVar6,uVar7,piVar8[5],piVar8[6],param_5
                                   ,param_6,iVar3,param_7,param_8,param_10);
            }
            if (iVar9 < 0) goto LAB_005b5404;
            if ((local_58 != 0) && (*(char *)(iVar2 + 0xd) == '\0')) {
              if (*(char *)(iVar2 + 9) == '\0') {
                uVar6 = *(undefined4 *)*piVar8;
              }
              else {
                uVar6 = *(undefined4 *)*piVar8;
              }
              FUN_005d5ab0(uVar7,uVar6,param_10);
              FUN_0059d160(local_74,param_10);
              local_74 = -1;
            }
          }
        }
        local_5c = local_5c + 1;
        piVar8 = piVar8 + 7;
      } while (local_5c < *(int *)(iVar2 + 0x38));
    }
  }
  else {
    local_54 = local_50 + 0x23;
    local_48 = 0;
    local_44 = 0;
    local_5c = 0;
    if (0 < local_50[0x22]) {
      piVar8 = local_50 + 0x40;
      do {
        iVar9 = FUN_00518f40(local_54,param_1,local_60,local_64,param_2,param_3,&local_28,&local_38,
                             local_4c);
        if (-1 < iVar9) {
          if (*(char *)(iVar2 + 0xb) == '\x01') {
            iVar9 = 0;
            local_48 = local_28;
            local_44 = local_24;
            if (0 < local_70) {
              do {
                iVar4 = FUN_005d5a40(local_18[iVar9],&local_38,
                                     *(undefined4 *)(*(int *)*piVar8 + 4 + iVar9 * 4),&local_48,
                                     param_10);
                if (iVar4 != 0) {
                  puVar10 = &DAT_007fcc04;
                  goto LAB_005b53fc;
                }
                iVar9 = iVar9 + 1;
              } while (iVar9 < local_70);
            }
          }
          else {
            puVar5 = (undefined4 *)*piVar8;
            if ((local_20 - local_28 == puVar5[5]) && (local_1c - local_24 == puVar5[6])) {
              local_58 = 1;
              if (*(char *)(iVar2 + 0xd) != '\0') goto LAB_005b52a3;
              local_74 = FUN_005a7dc0(iVar2,puVar5,param_10);
              if (local_74 == -1) {
                do {
                  iVar9 = FUN_005501a0();
                  if (iVar9 != 0) {
                    if (local_74 != -1) goto LAB_005b5322;
                    goto LAB_005b5404;
                  }
                  FUN_0056da20(1);
                  local_74 = FUN_005a7dc0(iVar2,*piVar8,param_10);
                } while (local_74 == -1);
                uVar7 = (&DAT_00ec3b2c)[local_74 * 6];
              }
              else {
LAB_005b5322:
                uVar7 = (&DAT_00ec3b2c)[local_74 * 6];
              }
            }
            else {
              local_58 = 0;
LAB_005b52a3:
              uVar7 = *(undefined4 *)*puVar5;
              local_74 = -1;
            }
            uVar6 = 1;
            if (*(int *)(iVar2 + 0x34) < 2) {
              if ((local_58 != 0) || (*(char *)(iVar2 + 0xd) != '\0')) {
                uVar6 = 0;
              }
              iVar9 = *piVar8;
              iVar9 = FUN_005a69a0(iVar2,&local_38,&local_28,uVar6,uVar7,
                                   *(undefined4 *)(iVar9 + 0x14),*(undefined4 *)(iVar9 + 0x18),
                                   *(undefined4 *)(iVar9 + 0xc),*(undefined4 *)(iVar9 + 0x10),
                                   param_5,param_6,iVar3,param_7,param_8,param_10);
            }
            else {
              if ((local_58 != 0) || (*(char *)(iVar2 + 0xd) != '\0')) {
                uVar6 = 0;
              }
              iVar9 = FUN_005a5ab0(iVar2,&local_38,&local_28,uVar6,uVar7,
                                   *(undefined4 *)(*piVar8 + 0x14),*(undefined4 *)(*piVar8 + 0x18),
                                   param_5,param_6,iVar3,param_7,param_8,param_10);
            }
            if (iVar9 < 0) goto LAB_005b5404;
            if ((local_58 != 0) && (*(char *)(iVar2 + 0xd) == '\0')) {
              FUN_005d5ab0(uVar7,**(undefined4 **)*piVar8,param_10);
              FUN_0059d160(local_74,param_10);
              local_74 = -1;
            }
          }
        }
        local_54 = local_54 + 0x1e;
        local_5c = local_5c + 1;
        piVar8 = piVar8 + 0x1e;
      } while (local_5c < local_50[0x22]);
    }
  }
LAB_005b4e4f:
  iVar2 = 0;
  do {
    if (local_18[iVar2] != 0) {
      FUN_005d5640(local_18[iVar2],param_10);
      local_18[iVar2] = 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  if (local_68 != 0) {
    FUN_005d5640(local_68,param_10);
    local_68 = 0;
  }
  if (local_74 != -1) {
    FUN_0059d160(local_74,param_10);
  }
  return 0;
}

