
undefined4
FUN_005a69a0(int param_1,int *param_2,int *param_3,int param_4,undefined4 param_5,int param_6,
            int param_7,int param_8,int param_9,char *param_10,int param_11,int param_12,
            undefined4 param_13,int param_14,undefined4 param_15)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  piVar2 = param_3;
  local_c = param_3[1];
  local_2c = 0;
  local_28 = 0;
  local_30 = 0;
  local_10 = *param_3;
  local_8 = param_3[2];
  local_4 = param_3[3];
  if ((param_8 < param_6) && (param_8 == local_8)) {
    local_8 = local_8 + 1;
    local_28 = 1;
  }
  if ((param_9 < param_7) && (param_9 == local_4)) {
    local_4 = local_4 + 1;
    local_30 = 1;
  }
  param_3 = (int *)0x0;
  local_24 = (-(uint)(*(char *)(param_1 + 9) != '\0') & 5) + 1;
  if (local_24 != 0) {
    do {
      if (param_4 == 0) {
        if (*(char *)(param_1 + 9) == '\0') {
          iVar3 = FUN_005d5d10(param_5,0,&local_20,&local_10,0);
          iVar6 = -1;
          local_34 = -1;
        }
        else {
          iVar3 = FUN_005d5e30(param_5,param_3,0,&local_20,&local_10);
          iVar6 = -1;
          local_34 = -1;
        }
      }
      else {
        iVar6 = FUN_005a4db0(param_6,param_7,
                             *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4),param_15);
        local_34 = iVar6;
        if (iVar6 == -1) {
          do {
            iVar3 = FUN_005501a0();
            if (iVar3 != 0) {
              local_34 = iVar6;
              if (iVar6 == -1) {
                return 0xffffffff;
              }
              goto LAB_005a6b0f;
            }
            FUN_0056da20(1);
            iVar6 = FUN_005a4db0(param_6,param_7,
                                 *(undefined4 *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4),param_15
                                );
          } while (iVar6 == -1);
          local_34 = iVar6;
        }
LAB_005a6b0f:
        iVar6 = local_34;
        local_2c = (&DAT_00ecfb30)[local_34 * 6];
        iVar3 = FUN_005d5f00(local_2c,&local_20,&local_10,0x2000,param_15);
      }
      if (iVar3 != 0) {
        FUN_0056bb10(&DAT_007fc734);
        return 0xffffffff;
      }
      if (((((*piVar2 == 0) && (piVar2[2] == param_6)) && (piVar2[1] == 0)) &&
          (piVar2[3] == param_7)) &&
         (((((cVar1 = *param_10, cVar1 == '\x01' &&
             (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) == 0x31545844)) ||
            ((cVar1 == '\x02' && (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) == 0x32545844)
             ))) || (((cVar1 == '\x03' &&
                      (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) == 0x33545844)) ||
                     ((cVar1 == '\x04' &&
                      (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) == 0x34545844)))))) ||
          ((cVar1 == '\x05' && (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) == 0x35545844)))
          ))) {
        iVar3 = (uint)(byte)param_10[5] * *(int *)(param_10 + 0x42c) * *(int *)(param_10 + 0x428);
        iVar3 = (int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3;
        FUN_0056d420(local_1c,iVar3 * (int)param_3 + *(int *)(param_10 + 0x434),iVar3);
      }
      else {
        iVar3 = *(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4);
        if (((iVar3 == 0x31545844) ||
            (((iVar3 == 0x32545844 || (iVar3 == 0x33545844)) || (iVar3 == 0x34545844)))) ||
           (iVar3 == 0x35545844)) {
          FUN_0056bb10(&DAT_007fc5e0);
        }
        else {
          if (((param_14 == 0) || (*(char *)(param_12 + 0xb) == '\0')) ||
             (*(int *)(param_11 + 0x434) != 0)) {
            uVar7 = 0;
          }
          else {
            uVar7 = 1;
          }
          FUN_00549b20(local_1c,local_20,param_12,
                       *(int *)(param_10 + 0x42c) * *(int *)(param_10 + 0x430) * (int)param_3 +
                       *(int *)(param_10 + 0x434),*(int *)(param_10 + 0x430),param_10,
                       *(int *)(param_11 + 0x42c) * *(int *)(param_11 + 0x430) * (int)param_3 +
                       *(int *)(param_11 + 0x434),*(int *)(param_11 + 0x430),param_11,0,0,param_2,0,
                       uVar7,*(undefined4 *)(param_1 + 0x1c),DAT_00a52a50,0,param_13,0,0);
          if (local_30 != 0) {
            FUN_0056d420((param_9 - piVar2[1]) * local_20 + local_1c,
                         ((param_9 - piVar2[1]) + -1) * local_20 + local_1c,
                         (param_2[2] - *param_2) * (uint)*(byte *)(param_12 + 4));
          }
          if (local_28 != 0) {
            uVar5 = (uint)*(byte *)(param_12 + 4);
            iVar6 = param_2[3] - param_2[1];
            puVar4 = (undefined4 *)((param_8 - *piVar2) * uVar5 + local_1c);
            if (uVar5 == 2) {
              if (0 < iVar6) {
                do {
                  *(undefined2 *)puVar4 = *(undefined2 *)((int)puVar4 + -2);
                  puVar4 = (undefined4 *)((int)puVar4 + local_20);
                  iVar6 = iVar6 + -1;
                } while (iVar6 != 0);
              }
            }
            else if ((uVar5 == 4) && (0 < iVar6)) {
              do {
                *puVar4 = puVar4[-1];
                puVar4 = (undefined4 *)((int)puVar4 + local_20);
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
            }
          }
          if ((local_30 != 0) && (local_28 != 0)) {
            uVar5 = (uint)*(byte *)(param_12 + 4);
            puVar4 = (undefined4 *)
                     ((param_8 - *piVar2) * uVar5 + (param_9 - piVar2[1]) * local_20 + local_1c);
            if (uVar5 == 2) {
              *(undefined2 *)puVar4 = *(undefined2 *)((int)puVar4 + (-2 - local_20));
            }
            else if (uVar5 == 4) {
              *puVar4 = *(undefined4 *)((int)puVar4 + (-4 - local_20));
            }
          }
          iVar6 = local_34;
        }
      }
      if (param_4 == 0) {
        if (*(char *)(param_1 + 9) == '\0') {
          FUN_005d5d80(param_5,0);
        }
        else {
          FUN_005d5eb0(param_5,param_3);
        }
      }
      else {
        local_34 = 0;
        FUN_005d5f60(local_2c,param_15);
        if (*(char *)(param_1 + 9) == '\0') {
          FUN_005d5cc0(param_5,0,&local_34,param_15);
        }
        else {
          FUN_005d5dd0(param_5,param_3);
        }
        local_18 = local_10;
        local_14 = local_c;
        FUN_005d5a40(local_2c,&local_10,local_34,&local_18,param_15);
        FUN_005d5640(local_34,param_15);
        FUN_0059d1e0(iVar6,param_15);
      }
      param_3 = (int *)((int)param_3 + 1);
    } while ((int)param_3 < local_24);
  }
  return 0;
}

