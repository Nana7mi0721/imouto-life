
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0058c750(int param_1,int param_2,float param_3,int param_4,float *param_5,int param_6)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  int local_14;
  undefined4 local_10;
  
  if ((param_2 != 2) && (param_2 != 5)) {
    return 0xffffffff;
  }
  if ((param_4 == 1) && (param_5 == (float *)0x0)) {
    return 0xffffffff;
  }
  param_3 = param_3 / (float)_DAT_0081ec30;
  if (0.0 <= param_3) {
    if (1.0 < param_3) {
      param_3 = 1.0;
    }
  }
  else {
    param_3 = 0.0;
  }
  if (DAT_00a37dc8 == 1) {
    FUN_005db850(param_1,param_2,param_3,param_4,param_5,param_6);
    return 0;
  }
  iVar1 = (int)ROUND(param_3 * (float)_DAT_0081ec30 * (float)_DAT_007d9bb8);
  if (param_5 != (float *)0x0) {
    iVar5 = (int)ROUND(param_5[2] * (float)_DAT_0081ec30);
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    else if (0xff < iVar5) {
      iVar5 = 0xff;
    }
    iVar6 = (int)ROUND(param_5[1] * (float)_DAT_0081ec30);
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    else if (0xff < iVar6) {
      iVar6 = 0xff;
    }
    iVar7 = (int)ROUND(*param_5 * (float)_DAT_0081ec30);
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    else if (0xff < iVar7) {
      iVar7 = 0xff;
    }
    iVar8 = (int)ROUND(param_5[3] * (float)_DAT_0081ec30);
    if (iVar8 < 0) {
      iVar8 = 0;
    }
    else if (0xff < iVar8) {
      iVar8 = 0xff;
    }
    local_10 = CONCAT13((char)iVar8,CONCAT12((char)iVar7,CONCAT11((char)iVar6,(char)iVar5)));
  }
  uVar12 = local_10;
  iVar5 = FUN_00586970(param_1,0);
  if (iVar5 < 0) {
    return 0xffffffff;
  }
  iVar5 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20);
  puVar9 = *(uint **)(param_1 + 0x48c);
  puVar10 = *(uint **)(param_1 + 0xd0c);
  local_14 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24);
  iVar6 = *(int *)(param_1 + 0x488) + iVar5 * -4;
  iVar7 = *(int *)(param_1 + 0xd08) + iVar5 * -4;
  if (param_4 != 0) {
    if (param_6 != 0) {
      uVar11 = local_10 & 0xff;
      uVar3 = local_10 >> 0x18;
      uVar4 = local_10 >> 8;
      local_10._3_1_ = SUB41(uVar12,3);
      local_10._0_3_ =
           CONCAT12((&DAT_00a52a60)[uVar3 + (uVar12 >> 0x10 & 0xff) * 0x100],
                    CONCAT11((&DAT_00a52a60)[uVar3 + (uVar4 & 0xff) * 0x100],
                             (&DAT_00a52a60)[uVar3 + uVar11 * 0x100]));
    }
    if (param_2 == 5) {
      if (param_6 == 0) {
        do {
          iVar8 = iVar5;
          do {
            uVar12 = local_10;
            if ((int)((uint)*(byte *)((int)puVar9 + 1) * 0x964 +
                      (uint)*(byte *)((int)puVar9 + 2) * 0x4c8 + (uint)(byte)*puVar9 * 0x1d2) <=
                iVar1) {
              uVar12 = *puVar9;
            }
            *puVar10 = uVar12;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          puVar9 = (uint *)((int)puVar9 + iVar6);
          puVar10 = (uint *)((int)puVar10 + iVar7);
          local_14 = local_14 + -1;
        } while (local_14 != 0);
        FUN_00586b00();
        return 0;
      }
      do {
        iVar8 = iVar5;
        do {
          bVar2 = *(byte *)((int)puVar9 + 3);
          uVar12 = local_10;
          if ((int)((uint)(byte)(&DAT_00a62a60)[CONCAT11(*(byte *)((int)puVar9 + 1),bVar2)] * 0x964
                    + (uint)(byte)(&DAT_00a62a60)[CONCAT11(*(byte *)((int)puVar9 + 2),bVar2)] *
                      0x4c8 + (uint)(byte)(&DAT_00a62a60)[CONCAT11((byte)*puVar9,bVar2)] * 0x1d2) <=
              iVar1) {
            uVar12 = *puVar9;
          }
          *puVar10 = uVar12;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        puVar9 = (uint *)((int)puVar9 + iVar6);
        puVar10 = (uint *)((int)puVar10 + iVar7);
        local_14 = local_14 + -1;
      } while (local_14 != 0);
      FUN_00586b00();
      return 0;
    }
    if (param_6 != 0) {
      do {
        iVar8 = iVar5;
        do {
          bVar2 = *(byte *)((int)puVar9 + 3);
          uVar12 = local_10;
          if (iVar1 <= (int)((uint)(byte)(&DAT_00a62a60)[CONCAT11(*(byte *)((int)puVar9 + 1),bVar2)]
                             * 0x964 + (uint)(byte)(&DAT_00a62a60)
                                                   [CONCAT11(*(byte *)((int)puVar9 + 2),bVar2)] *
                                       0x4c8 +
                            (uint)(byte)(&DAT_00a62a60)[CONCAT11((byte)*puVar9,bVar2)] * 0x1d2)) {
            uVar12 = *puVar9;
          }
          *puVar10 = uVar12;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        puVar9 = (uint *)((int)puVar9 + iVar6);
        puVar10 = (uint *)((int)puVar10 + iVar7);
        local_14 = local_14 + -1;
      } while (local_14 != 0);
      FUN_00586b00();
      return 0;
    }
    do {
      iVar8 = iVar5;
      do {
        if ((int)((uint)*(byte *)((int)puVar9 + 1) * 0x964 +
                  (uint)*(byte *)((int)puVar9 + 2) * 0x4c8 + (uint)(byte)*puVar9 * 0x1d2) < iVar1) {
          *puVar10 = local_10;
        }
        else {
          *puVar10 = *puVar9;
        }
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      puVar9 = (uint *)((int)puVar9 + iVar6);
      puVar10 = (uint *)((int)puVar10 + iVar7);
      local_14 = local_14 + -1;
    } while (local_14 != 0);
    FUN_00586b00();
    return 0;
  }
  if (param_2 != 5) {
    if (param_6 == 0) {
      do {
        iVar8 = iVar5;
        do {
          if (iVar1 <= (int)((uint)*(byte *)((int)puVar9 + 1) * 0x964 +
                             (uint)*(byte *)((int)puVar9 + 2) * 0x4c8 + (uint)(byte)*puVar9 * 0x1d2)
             ) {
            *puVar10 = *puVar9;
          }
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        puVar9 = (uint *)((int)puVar9 + iVar6);
        puVar10 = (uint *)((int)puVar10 + iVar7);
        local_14 = local_14 + -1;
      } while (local_14 != 0);
      FUN_00586b00();
      return 0;
    }
    do {
      iVar8 = iVar5;
      do {
        bVar2 = *(byte *)((int)puVar9 + 3);
        if (iVar1 <= (int)((uint)(byte)(&DAT_00a62a60)[CONCAT11(*(byte *)((int)puVar9 + 1),bVar2)] *
                           0x964 + (uint)(byte)(&DAT_00a62a60)[CONCAT11((byte)*puVar9,bVar2)] *
                                   0x1d2 +
                          (uint)(byte)(&DAT_00a62a60)[CONCAT11(*(byte *)((int)puVar9 + 2),bVar2)] *
                          0x4c8)) {
          *puVar10 = *puVar9;
        }
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      puVar9 = (uint *)((int)puVar9 + iVar6);
      puVar10 = (uint *)((int)puVar10 + iVar7);
      local_14 = local_14 + -1;
    } while (local_14 != 0);
    FUN_00586b00();
    return 0;
  }
  if (param_6 == 0) {
    do {
      iVar8 = iVar5;
      do {
        if ((int)((uint)*(byte *)((int)puVar9 + 1) * 0x964 +
                  (uint)*(byte *)((int)puVar9 + 2) * 0x4c8 + (uint)(byte)*puVar9 * 0x1d2) <= iVar1)
        {
          *puVar10 = *puVar9;
        }
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      puVar9 = (uint *)((int)puVar9 + iVar6);
      puVar10 = (uint *)((int)puVar10 + iVar7);
      local_14 = local_14 + -1;
    } while (local_14 != 0);
    FUN_00586b00();
    return 0;
  }
  do {
    iVar8 = iVar5;
    do {
      bVar2 = *(byte *)((int)puVar9 + 3);
      if ((int)((uint)(byte)(&DAT_00a62a60)[CONCAT11(*(byte *)((int)puVar9 + 1),bVar2)] * 0x964 +
                (uint)(byte)(&DAT_00a62a60)[CONCAT11((byte)*puVar9,bVar2)] * 0x1d2 +
               (uint)(byte)(&DAT_00a62a60)[CONCAT11(*(byte *)((int)puVar9 + 2),bVar2)] * 0x4c8) <=
          iVar1) {
        *puVar10 = *puVar9;
      }
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    puVar9 = (uint *)((int)puVar9 + iVar6);
    puVar10 = (uint *)((int)puVar10 + iVar7);
    local_14 = local_14 + -1;
  } while (local_14 != 0);
  FUN_00586b00();
  return 0;
}

