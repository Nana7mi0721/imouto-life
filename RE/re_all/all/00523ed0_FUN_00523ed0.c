
undefined4
FUN_00523ed0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,int param_7,float param_8,int param_9,float param_10,uint *param_11,
            int param_12,undefined4 param_13,int param_14)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  int local_20;
  int local_1c;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (DAT_00a37d70 == 0) {
    return 0xffffffff;
  }
  if (param_14 == 0) {
    if (((((DAT_00cc47d0 != 0) && (uVar5 = *param_11, -1 < (int)uVar5)) &&
         ((uVar5 & 0x7c000000) == DAT_00cc47f8)) &&
        (((int)(uVar5 & 0xffff) < DAT_00cc4800 &&
         (piVar3 = *(int **)(DAT_00cc47d4 + (uVar5 & 0xffff) * 4), piVar3 != (int *)0x0)))) &&
       ((*piVar3 * 0x10000 == (uVar5 & 0x3ff0000) && (piVar3[4] == 0)))) goto LAB_00523f96;
  }
  else if ((((DAT_00cc47d0 != 0) && (uVar5 = *param_11, -1 < (int)uVar5)) &&
           ((uVar5 & 0x7c000000) == DAT_00cc47f8)) &&
          ((((int)(uVar5 & 0xffff) < DAT_00cc4800 &&
            (piVar3 = *(int **)(DAT_00cc47d4 + (uVar5 & 0xffff) * 4), piVar3 != (int *)0x0)) &&
           (*piVar3 * 0x10000 == (uVar5 & 0x3ff0000))))) {
LAB_00523f96:
    iVar1 = piVar3[0x13];
    piVar3[0x11] = 0;
    piVar3[0x12] = 0;
    iVar7 = 1;
    piVar3[0xf] = 0;
    piVar3[0x10] = 0;
    local_18 = 1;
    local_20 = 0;
    local_1c = 0;
    if (1 < param_3) {
      iVar6 = 0;
      do {
        if (param_14 == 0) {
          if (DAT_00cc47d0 == 0) {
            return 0xffffffff;
          }
          uVar5 = param_11[iVar7];
          if ((int)uVar5 < 0) {
            return 0xffffffff;
          }
          if ((uVar5 & 0x7c000000) != DAT_00cc47f8) {
            return 0xffffffff;
          }
          if (DAT_00cc4800 <= (int)(uVar5 & 0xffff)) {
            return 0xffffffff;
          }
          piVar2 = *(int **)(DAT_00cc47d4 + (uVar5 & 0xffff) * 4);
          if (piVar2 == (int *)0x0) {
            return 0xffffffff;
          }
          if (*piVar2 * 0x10000 != (uVar5 & 0x3ff0000)) {
            return 0xffffffff;
          }
          bVar8 = piVar2[4] == 0;
        }
        else {
          if (DAT_00cc47d0 == 0) {
            return 0xffffffff;
          }
          uVar5 = param_11[iVar7];
          if ((int)uVar5 < 0) {
            return 0xffffffff;
          }
          if ((uVar5 & 0x7c000000) != DAT_00cc47f8) {
            return 0xffffffff;
          }
          if (DAT_00cc4800 <= (int)(uVar5 & 0xffff)) {
            return 0xffffffff;
          }
          piVar2 = *(int **)(DAT_00cc47d4 + (uVar5 & 0xffff) * 4);
          if (piVar2 == (int *)0x0) {
            return 0xffffffff;
          }
          bVar8 = *piVar2 * 0x10000 == (uVar5 & 0x3ff0000);
        }
        if (!bVar8) {
          return 0xffffffff;
        }
        if (piVar2[0x13] == iVar1) {
          local_18 = local_18 + 1;
        }
        if (param_12 == 0) {
          iVar4 = local_20;
        }
        else {
          iVar4 = (param_4 - local_20) + -1;
        }
        piVar2[0x11] = (int)((float)iVar4 * param_8);
        local_20 = local_20 + 1;
        piVar2[0x12] = (int)((float)local_1c * param_10);
        piVar2[0xf] = iVar4 * param_7;
        piVar2[0x10] = iVar6;
        if (local_20 == param_4) {
          local_1c = local_1c + 1;
          iVar6 = iVar6 + param_9;
          local_20 = 0;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < param_3);
    }
    if (param_3 == local_18) {
      local_8 = *(undefined4 *)(piVar3[0x13] + 0x20);
      local_4 = *(undefined4 *)(piVar3[0x13] + 0x24);
      local_10 = 0;
      local_c = 0;
      FUN_00518620(&local_10,0,0,*param_11,param_1,param_2,*(undefined1 *)(iVar1 + 0x17),param_13,1,
                   param_14);
      return 0;
    }
    iVar7 = 0;
    if (0 < param_3) {
      do {
        if (param_14 == 0) {
          if ((((DAT_00cc47d0 == 0) || (uVar5 = param_11[iVar7], (int)uVar5 < 0)) ||
              (((uVar5 & 0x7c000000) != DAT_00cc47f8 ||
               ((DAT_00cc4800 <= (int)(uVar5 & 0xffff) ||
                (piVar3 = *(int **)(DAT_00cc47d4 + (uVar5 & 0xffff) * 4), piVar3 == (int *)0x0))))))
             || (*piVar3 * 0x10000 != (uVar5 & 0x3ff0000))) {
            return 0xffffffff;
          }
          bVar8 = piVar3[4] == 0;
        }
        else {
          if (DAT_00cc47d0 == 0) {
            return 0xffffffff;
          }
          uVar5 = param_11[iVar7];
          if ((int)uVar5 < 0) {
            return 0xffffffff;
          }
          if ((uVar5 & 0x7c000000) != DAT_00cc47f8) {
            return 0xffffffff;
          }
          if (DAT_00cc4800 <= (int)(uVar5 & 0xffff)) {
            return 0xffffffff;
          }
          piVar3 = *(int **)(DAT_00cc47d4 + (uVar5 & 0xffff) * 4);
          if (piVar3 == (int *)0x0) {
            return 0xffffffff;
          }
          bVar8 = *piVar3 * 0x10000 == (uVar5 & 0x3ff0000);
        }
        if (!bVar8) {
          return 0xffffffff;
        }
        local_10 = piVar3[0xf];
        local_c = piVar3[0x10];
        local_8 = piVar3[0x18] + local_10;
        local_4 = piVar3[0x19] + local_c;
        FUN_00518620(&local_10,0,0,uVar5,param_1,param_2,*(undefined1 *)(iVar1 + 0x17),param_13,0,
                     param_14);
        iVar7 = iVar7 + 1;
      } while (iVar7 < param_3);
    }
    return 0;
  }
  return 0xffffffff;
}

