
undefined4 FUN_005f23c0(undefined4 param_1,int param_2,int param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  undefined4 uVar11;
  undefined4 local_4c;
  int *local_48;
  undefined4 local_3c;
  int local_30;
  int local_2c;
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
  
  piVar10 = (int *)0x0;
  piVar9 = (int *)0x0;
  piVar8 = (int *)0x0;
  local_48 = (int *)0x0;
  local_3c = 0;
  if ((DAT_00cc47d0 == 0) || (uVar4 = in_EAX[2], (int)uVar4 < 0)) {
LAB_005f242e:
    if (DAT_00cc79c0 == 0) {
      return 0xffffffff;
    }
    uVar4 = in_EAX[2];
    if ((int)uVar4 < 0) {
      return 0xffffffff;
    }
    if ((uVar4 & 0x7c000000) != DAT_00cc79e8) {
      return 0xffffffff;
    }
    if (DAT_00cc79f0 <= (int)(uVar4 & 0xffff)) {
      return 0xffffffff;
    }
    piVar10 = *(int **)(DAT_00cc79c4 + (uVar4 & 0xffff) * 4);
    if (piVar10 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar10 * 0x10000 != (uVar4 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar10[4] != 0) {
      return 0xffffffff;
    }
  }
  else {
    if (((uVar4 & 0x7c000000) != DAT_00cc47f8) || (DAT_00cc4800 <= (int)(uVar4 & 0xffff))) {
      piVar9 = (int *)0x0;
      goto LAB_005f242e;
    }
    piVar9 = *(int **)(DAT_00cc47d4 + (uVar4 & 0xffff) * 4);
    if (((piVar9 == (int *)0x0) || (*piVar9 * 0x10000 != (uVar4 & 0x3ff0000))) || (piVar9[4] != 0))
    goto LAB_005f242e;
  }
  if (((((((DAT_00cc47d0 != 0) && (uVar4 = in_EAX[4], -1 < (int)uVar4)) &&
         (((uVar4 & 0x7c000000) == DAT_00cc47f8 &&
          (((int)(uVar4 & 0xffff) < DAT_00cc4800 &&
           (local_48 = *(int **)(DAT_00cc47d4 + (uVar4 & 0xffff) * 4), local_48 != (int *)0x0))))))
        && (*local_48 * 0x10000 == (uVar4 & 0x3ff0000))) && (local_48[4] == 0)) ||
      (((((DAT_00cc79c0 != 0 && (uVar4 = in_EAX[4], -1 < (int)uVar4)) &&
         ((uVar4 & 0x7c000000) == DAT_00cc79e8)) &&
        (((int)(uVar4 & 0xffff) < DAT_00cc79f0 &&
         (piVar8 = *(int **)(DAT_00cc79c4 + (uVar4 & 0xffff) * 4), piVar8 != (int *)0x0)))) &&
       ((*piVar8 * 0x10000 == (uVar4 & 0x3ff0000) && (piVar8[4] == 0)))))) &&
     (iVar2 = FUN_0051c6a0(param_1,0), iVar2 != 0)) {
    if (piVar10 == (int *)0x0) {
      uVar5 = *(undefined4 *)(*(int *)piVar9[0x40] + 4);
      uVar7 = *(undefined4 *)(*(int *)piVar9[0x40] + 8);
    }
    else {
      uVar5 = *(undefined4 *)piVar10[0x114];
      uVar7 = ((undefined4 *)piVar10[0x114])[1];
    }
    if (piVar8 == (int *)0x0) {
      local_4c = *(undefined4 *)(*(int *)local_48[0x40] + 4);
      local_48 = (int *)**(undefined4 **)(*(int *)local_48[0x40] + 0xc);
    }
    else {
      local_4c = *(undefined4 *)piVar8[0x114];
      local_48 = (int *)((undefined4 *)piVar8[0x114])[2];
    }
    local_8 = in_EAX[10];
    local_4 = in_EAX[0xb];
    local_10 = in_EAX[8];
    local_c = in_EAX[9];
    iVar3 = local_8 - local_10;
    iVar6 = local_4 - local_c;
    if (param_3 == 1) {
      local_20 = in_EAX[0x10];
      local_18 = local_20 + iVar3;
      local_1c = in_EAX[0x11];
      local_14 = local_1c + iVar6;
    }
    else {
      local_20 = in_EAX[0x10];
      local_18 = iVar3 / param_3 + local_20;
      local_1c = in_EAX[0x11];
      local_14 = iVar6 / param_3 + local_1c;
    }
    iVar1 = *in_EAX;
    if ((iVar1 == 0) && ((int)param_4 < 0)) {
      uVar11 = local_3c;
LAB_005f2752:
      FUN_005bc910(3,1,&DAT_00ef1ba8);
      FUN_005caf30(uVar5,uVar7,&local_10,local_4c,local_48,&local_20,param_2 != 0,0,0,
                   **(undefined4 **)(iVar2 + 0x3c),uVar11,local_3c,&local_30,param_5);
      return 0;
    }
    if (DAT_00cc47d0 != 0) {
      if (iVar1 == 0) {
        uVar4 = param_4;
      }
      else {
        uVar4 = in_EAX[3];
      }
      if (-1 < (int)uVar4) {
        if (iVar1 == 0) {
          uVar4 = param_4;
        }
        else {
          uVar4 = in_EAX[3];
        }
        if ((uVar4 & 0x7c000000) == DAT_00cc47f8) {
          if (iVar1 == 0) {
            uVar4 = param_4;
          }
          else {
            uVar4 = in_EAX[3];
          }
          if ((int)(uVar4 & 0xffff) < DAT_00cc4800) {
            if (iVar1 == 0) {
              uVar4 = param_4;
            }
            else {
              uVar4 = in_EAX[3];
            }
            piVar9 = *(int **)(DAT_00cc47d4 + (uVar4 & 0xffff) * 4);
            if (piVar9 != (int *)0x0) {
              if (iVar1 != 0) {
                param_4 = in_EAX[3];
              }
              if ((*piVar9 * 0x10000 == (param_4 & 0x3ff0000)) && (piVar9[4] == 0)) {
                uVar11 = *(undefined4 *)(*(int *)piVar9[0x40] + 4);
                local_3c = *(undefined4 *)(*(int *)piVar9[0x40] + 8);
                if (in_EAX[0xf] == 0) {
                  local_30 = piVar9[0x27];
                  local_28 = piVar9[0x2b] + piVar9[0x27];
                  local_2c = piVar9[0x28];
                  local_24 = piVar9[0x2c] + piVar9[0x28];
                }
                else {
                  local_30 = in_EAX[0xd];
                  local_2c = in_EAX[0xe];
                  local_28 = local_30 + iVar3;
                  local_24 = local_2c + iVar6;
                }
                goto LAB_005f2752;
              }
            }
          }
        }
      }
    }
  }
  return 0xffffffff;
}

