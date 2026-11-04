
undefined4
FUN_00563c40(int param_1,int param_2,int param_3,short *param_4,int param_5,undefined4 param_6,
            undefined4 param_7,int param_8,undefined4 param_9,undefined4 param_10,
            undefined4 param_11,int param_12,int param_13,int param_14,int *param_15,int *param_16)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int local_24;
  int local_20;
  undefined4 local_1c;
  ushort local_18 [4];
  int local_10;
  int local_c;
  int local_8;
  
  if (param_8 == -1) {
    param_8 = FUN_00530d70();
  }
  iVar7 = 0;
  if (param_14 != 0) {
    local_1c = FUN_00516960();
    FUN_00516940(0);
  }
  FUN_005162d0(&local_10);
  if (param_15 != (int *)0x0) {
    *param_15 = 0;
  }
  if (param_16 != (int *)0x0) {
    *param_16 = 0;
  }
  if (param_1 < local_10) {
    param_1 = local_10;
  }
  iVar9 = param_2;
  if (param_2 < local_c) {
    iVar9 = local_c;
  }
  if (local_8 < param_1) {
    do {
      iVar9 = iVar9 + param_3;
      param_1 = param_1 + (local_10 - local_8);
    } while (local_8 < param_1);
  }
  param_2 = 0;
  local_24 = 0;
  if (param_12 != -1) {
    if (param_12 < param_13) {
      local_24 = param_13;
      param_2 = param_12;
    }
    else {
      local_24 = param_12;
      param_2 = param_13;
    }
  }
  if (param_5 < 0) {
    param_5 = 0;
    sVar1 = *param_4;
    while (sVar1 != 0) {
      param_5 = param_5 + 1;
      sVar1 = param_4[param_5];
    }
  }
  iVar8 = param_1;
  iVar5 = param_1;
  if (0 < param_5) {
    do {
      uVar2 = param_4[iVar7];
      if ((uVar2 & 0xfc00) == 0xd800) {
        local_18[1] = param_4[iVar7 + 1];
        local_18[2] = 0;
        local_20 = 2;
LAB_00563d82:
        iVar5 = 0;
        uVar3 = uVar2;
        while (uVar3 != 0) {
          iVar5 = iVar5 + 1;
          uVar3 = local_18[iVar5];
        }
        local_18[0] = uVar2;
        iVar5 = FUN_0053e560(local_18,iVar5,param_8,0);
        if (param_14 != 0) {
          if (((param_12 == -1) || (iVar7 < param_2)) || (local_24 <= iVar7)) {
            iVar4 = 0;
            uVar2 = local_18[0];
            while (uVar2 != 0) {
              iVar4 = iVar4 + 1;
              uVar2 = local_18[iVar4];
            }
            uVar6 = param_6;
            uVar10 = param_7;
          }
          else {
            iVar4 = FUN_00536eb0(param_8,param_9,1);
            FUN_00526390(iVar8,iVar9,iVar5 + iVar8,iVar4 + iVar9);
            iVar4 = 0;
            uVar2 = local_18[0];
            while (uVar2 != 0) {
              iVar4 = iVar4 + 1;
              uVar2 = local_18[iVar4];
            }
            uVar6 = param_10;
            uVar10 = param_11;
          }
          FUN_0053f880(iVar8,iVar9,local_18,iVar4,uVar6,param_8,uVar10,0);
        }
        iVar5 = iVar5 + iVar8;
        if (local_8 < iVar5) {
          iVar5 = iVar8 + (local_10 - local_8);
          iVar9 = iVar9 + param_3;
        }
        else {
          iVar7 = iVar7 + local_20;
        }
      }
      else {
        if (uVar2 != 10) {
          local_18[1] = 0;
          local_20 = 1;
          goto LAB_00563d82;
        }
        iVar9 = iVar9 + param_3;
        iVar7 = iVar7 + 1;
        iVar5 = param_1;
      }
      iVar8 = iVar5;
    } while (iVar7 < param_5);
  }
  if (param_14 != 0) {
    FUN_00516940(local_1c);
  }
  if (param_15 != (int *)0x0) {
    *param_15 = iVar5;
  }
  if (param_16 != (int *)0x0) {
    *param_16 = iVar9;
  }
  return 0;
}

