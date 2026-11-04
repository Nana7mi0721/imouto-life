
void __fastcall FUN_004c92b0(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int local_64;
  int local_60;
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
  int local_30;
  undefined4 local_14 [4];
  
  if (*param_1 != DAT_00a18aa0) {
    FUN_004c9b50();
  }
  if (DAT_00a14341 != '\0') {
    FUN_004ca0a0();
  }
  if ((DAT_00a18aa0 != -1) && (param_1[1] != -1)) {
    if (DAT_00a18aac < 1) {
      if (0xff - DAT_00a117bc < DAT_00a18ab0) {
        local_38 = 0xff - DAT_00a117bc;
      }
      else {
        local_38 = DAT_00a18ab0;
      }
      if (local_38 < 0) {
        local_3c = 0;
      }
      else {
        if (0xff - DAT_00a117bc < DAT_00a18ab0) {
          local_40 = 0xff - DAT_00a117bc;
        }
        else {
          local_40 = DAT_00a18ab0;
        }
        local_3c = local_40;
      }
      FUN_005160d0(1,local_3c);
    }
    if (DAT_00a18aac == 1) {
      if (0xff - DAT_00a117bc < DAT_00a18ab0) {
        local_44 = 0xff - DAT_00a117bc;
      }
      else {
        local_44 = DAT_00a18ab0;
      }
      if (local_44 < 0) {
        local_48 = 0;
      }
      else {
        if (0xff - DAT_00a117bc < DAT_00a18ab0) {
          local_4c = 0xff - DAT_00a117bc;
        }
        else {
          local_4c = DAT_00a18ab0;
        }
        local_48 = local_4c;
      }
      FUN_005160d0(2,local_48);
    }
    if (DAT_00a18aac == 2) {
      if (0xff - DAT_00a117bc < DAT_00a18ab0) {
        local_50 = 0xff - DAT_00a117bc;
      }
      else {
        local_50 = DAT_00a18ab0;
      }
      if (local_50 < 0) {
        local_54 = 0;
      }
      else {
        if (0xff - DAT_00a117bc < DAT_00a18ab0) {
          local_58 = 0xff - DAT_00a117bc;
        }
        else {
          local_58 = DAT_00a18ab0;
        }
        local_54 = local_58;
      }
      FUN_005160d0(3,local_54);
    }
    if (2 < DAT_00a18aac) {
      if (0xff - DAT_00a117bc < DAT_00a18ab0) {
        local_5c = 0xff - DAT_00a117bc;
      }
      else {
        local_5c = DAT_00a18ab0;
      }
      if (local_5c < 0) {
        local_60 = 0;
      }
      else {
        if (0xff - DAT_00a117bc < DAT_00a18ab0) {
          local_64 = 0xff - DAT_00a117bc;
        }
        else {
          local_64 = DAT_00a18ab0;
        }
        local_60 = local_64;
      }
      FUN_005160d0(4,local_60);
    }
    if (DAT_0084b248 * DAT_00a18174 == 100) {
      uVar11 = 0;
      uVar10 = 0;
      uVar8 = 0;
      uVar9 = DAT_0084b240;
      FUN_004cde80(param_1[1]);
      puVar1 = (undefined4 *)FUN_004ce990(uVar8);
      FUN_00526e30((int)(param_1[10] + (param_1[10] >> 0x1f & 7U)) >> 3,
                   (int)(param_1[0xb] + (param_1[0xb] >> 0x1f & 7U)) >> 3,0,0,
                   param_1[6] - ((int)(param_1[10] + (param_1[10] >> 0x1f & 7U)) >> 3),
                   param_1[7] - ((int)(param_1[0xb] + (param_1[0xb] >> 0x1f & 7U)) >> 3),*puVar1,
                   uVar9,uVar10,uVar11);
      uVar11 = 0;
      uVar10 = 0;
      uVar8 = 0;
      uVar9 = DAT_0084b240;
      FUN_004cde80(param_1[1]);
      puVar1 = (undefined4 *)FUN_004ce990(uVar8);
      FUN_00526e30(0,0,param_1[6] - ((int)(param_1[10] + (param_1[10] >> 0x1f & 7U)) >> 3),
                   param_1[7] - ((int)(param_1[0xb] + (param_1[0xb] >> 0x1f & 7U)) >> 3),
                   (int)(param_1[10] + (param_1[10] >> 0x1f & 7U)) >> 3,
                   (int)(param_1[0xb] + (param_1[0xb] >> 0x1f & 7U)) >> 3,*puVar1,uVar9,uVar10,
                   uVar11);
      uVar9 = 0;
      FUN_004cde80(param_1[1]);
      puVar1 = (undefined4 *)FUN_004ce990(uVar9);
      FUN_00526e30(0,(int)(param_1[0xb] + (param_1[0xb] >> 0x1f & 7U)) >> 3,
                   param_1[6] - ((int)(param_1[10] + (param_1[10] >> 0x1f & 7U)) >> 3),0,
                   (int)(param_1[10] + (param_1[10] >> 0x1f & 7U)) >> 3,
                   param_1[7] - ((int)(param_1[0xb] + (param_1[0xb] >> 0x1f & 7U)) >> 3),*puVar1);
      uVar11 = 0;
      uVar10 = 0;
      uVar8 = 0;
      uVar9 = DAT_0084b240;
      FUN_004cde80(param_1[1]);
      puVar1 = (undefined4 *)FUN_004ce990(uVar8);
      FUN_00526e30((int)(param_1[10] + (param_1[10] >> 0x1f & 7U)) >> 3,0,0,
                   param_1[7] - ((int)(param_1[0xb] + (param_1[0xb] >> 0x1f & 7U)) >> 3),
                   param_1[6] - ((int)(param_1[10] + (param_1[10] >> 0x1f & 7U)) >> 3),
                   (int)(param_1[0xb] + (param_1[0xb] >> 0x1f & 7U)) >> 3,*puVar1,uVar9,uVar10,
                   uVar11);
    }
    else {
      if ((3 < param_1[10]) && (param_1[10] < 8)) {
        param_1[10] = 8;
      }
      if ((3 < param_1[0xb]) && (param_1[0xb] < 8)) {
        param_1[0xb] = 8;
      }
      uVar9 = 0;
      FUN_004cde80(param_1[1]);
      puVar1 = (undefined4 *)FUN_004ce990(uVar9);
      local_14[0] = FUN_0052a120(0,0,param_1[6] -
                                     ((int)(param_1[10] + (param_1[10] >> 0x1f & 7U)) >> 3),
                                 param_1[7] -
                                 ((int)(param_1[0xb] + (param_1[0xb] >> 0x1f & 7U)) >> 3),*puVar1);
      uVar9 = 0;
      FUN_004cde80(param_1[1]);
      puVar1 = (undefined4 *)FUN_004ce990(uVar9);
      local_14[1] = FUN_0052a120(param_1[6] - ((int)(param_1[10] + (param_1[10] >> 0x1f & 7U)) >> 3)
                                 ,param_1[7] -
                                  ((int)(param_1[0xb] + (param_1[0xb] >> 0x1f & 7U)) >> 3),
                                 (int)(param_1[10] + (param_1[10] >> 0x1f & 7U)) >> 3,
                                 (int)(param_1[0xb] + (param_1[0xb] >> 0x1f & 7U)) >> 3,*puVar1);
      uVar9 = 0;
      FUN_004cde80(param_1[1]);
      puVar1 = (undefined4 *)FUN_004ce990(uVar9);
      local_14[2] = FUN_0052a120(param_1[6] - ((int)(param_1[10] + (param_1[10] >> 0x1f & 7U)) >> 3)
                                 ,0,(int)(param_1[10] + (param_1[10] >> 0x1f & 7U)) >> 3,
                                 param_1[7] -
                                 ((int)(param_1[0xb] + (param_1[0xb] >> 0x1f & 7U)) >> 3),*puVar1);
      uVar9 = 0;
      FUN_004cde80(param_1[1]);
      puVar1 = (undefined4 *)FUN_004ce990(uVar9);
      local_14[3] = FUN_0052a120(0,param_1[7] -
                                   ((int)(param_1[0xb] + (param_1[0xb] >> 0x1f & 7U)) >> 3),
                                 param_1[6] - ((int)(param_1[10] + (param_1[10] >> 0x1f & 7U)) >> 3)
                                 ,(int)(param_1[0xb] + (param_1[0xb] >> 0x1f & 7U)) >> 3,*puVar1);
      iVar2 = (-DAT_00a1816c * DAT_0084b248 * (DAT_00a18174 + -100)) / 100;
      iVar4 = ((int)(param_1[10] * DAT_0084b248 + (param_1[10] * DAT_0084b248 >> 0x1f & 7U)) >> 3) +
              ((((int)(param_1[10] + (param_1[10] >> 0x1f & 7U)) >> 3) - DAT_00a1816c) *
               DAT_0084b248 * (DAT_00a18174 + -100)) / 100;
      iVar5 = param_1[6] * DAT_0084b248 +
              ((param_1[6] - DAT_00a1816c) * DAT_0084b248 * (DAT_00a18174 + -100)) / 100;
      iVar3 = (-DAT_00a18170 * DAT_0084b248 * (DAT_00a18174 + -100)) / 100;
      iVar6 = ((int)(param_1[0xb] * DAT_0084b248 + (param_1[0xb] * DAT_0084b248 >> 0x1f & 7U)) >> 3)
              + ((((int)(param_1[0xb] + (param_1[0xb] >> 0x1f & 7U)) >> 3) - DAT_00a18170) *
                 DAT_0084b248 * (DAT_00a18174 + -100)) / 100;
      iVar7 = param_1[7] * DAT_0084b248 +
              ((param_1[7] - DAT_00a18170) * DAT_0084b248 * (DAT_00a18174 + -100)) / 100;
      FUN_0051f060(iVar4,iVar6,iVar5,iVar7,local_14[0],DAT_0084b240);
      FUN_0051f060(iVar2,iVar3,iVar4,iVar6,local_14[1],DAT_0084b240);
      FUN_0051f060(iVar2,iVar6,iVar4,iVar7,local_14[2],DAT_0084b240);
      FUN_0051f060(iVar4,iVar3,iVar5,iVar6,local_14[3],DAT_0084b240);
      for (local_30 = 0; local_30 < 4; local_30 = local_30 + 1) {
        FUN_00515700(local_14[local_30],0);
      }
    }
  }
  return;
}

