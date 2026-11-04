
void __thiscall FUN_00794110(int param_1,int param_2,int param_3)

{
  ushort *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int local_5c;
  float local_50;
  float local_4c;
  float local_48;
  int local_44;
  ushort local_40 [4];
  ushort local_38 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_44 = *(int *)(param_1 + 0x38);
  iVar8 = param_3 - param_2;
  if (iVar8 == 1) {
    if (*(char *)(param_1 + 0x3c) != '\0') {
      puVar6 = (undefined4 *)(*(int *)(param_1 + 0x74) + param_2 * 0x10);
      puVar9 = (undefined4 *)(local_44 * 0x10 + *(int *)(param_1 + 0x88));
      *puVar9 = *puVar6;
      puVar9[1] = puVar6[1];
      puVar9[2] = puVar6[2];
      puVar9[3] = puVar6[3];
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
      return;
    }
    puVar6 = (undefined4 *)(param_2 * 0x40 + *(int *)(param_1 + 0x4c));
    puVar9 = (undefined4 *)(local_44 * 0x40 + *(int *)(param_1 + 0x60));
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar9 = puVar9 + 1;
    }
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
    return;
  }
  uVar4 = FUN_00794af0(param_2,param_3);
  uVar4 = FUN_007946e0(param_2,param_3,uVar4);
  iVar2 = *(int *)(param_1 + 0x38);
  if (*(char *)(param_1 + 0x3c) == '\0') {
    puVar6 = (undefined4 *)(iVar2 * 0x40 + *(int *)(param_1 + 0x60));
    *puVar6 = *(undefined4 *)(param_1 + 0x14);
    puVar6[1] = *(undefined4 *)(param_1 + 0x18);
    puVar6[2] = *(undefined4 *)(param_1 + 0x1c);
    puVar6[3] = *(undefined4 *)(param_1 + 0x20);
  }
  else {
    FUN_00793100(iVar2 * 0x10 + *(int *)(param_1 + 0x88),(undefined4 *)(param_1 + 0x14),0);
  }
  if (*(char *)(param_1 + 0x3c) == '\0') {
    puVar6 = (undefined4 *)(*(int *)(param_1 + 0x38) * 0x40 + 0x10 + *(int *)(param_1 + 0x60));
    *puVar6 = *(undefined4 *)(param_1 + 4);
    puVar6[1] = *(undefined4 *)(param_1 + 8);
    puVar6[2] = *(undefined4 *)(param_1 + 0xc);
    puVar6[3] = *(undefined4 *)(param_1 + 0x10);
  }
  else {
    FUN_00793100(*(int *)(param_1 + 0x38) * 0x10 + 6 + *(int *)(param_1 + 0x88),
                 (undefined4 *)(param_1 + 4),1);
  }
  if (param_2 < param_3) {
    local_5c = param_2 << 6;
    iVar7 = param_2 << 4;
    do {
      if (*(char *)(param_1 + 0x3c) == '\0') {
        iVar5 = *(int *)(param_1 + 0x4c) + 0x10 + local_5c;
        local_30 = *(undefined4 *)(*(int *)(param_1 + 0x4c) + 0x10 + local_5c);
        local_2c = *(undefined4 *)(iVar5 + 4);
        local_28 = *(undefined4 *)(iVar5 + 8);
        local_24 = *(undefined4 *)(iVar5 + 0xc);
      }
      else {
        puVar1 = (ushort *)(*(int *)(param_1 + 0x74) + 6 + iVar7);
        local_4c = (float)*(ushort *)(*(int *)(param_1 + 0x74) + 10 + iVar7) /
                   *(float *)(param_1 + 0x2c);
        local_48 = (float)puVar1[1] / *(float *)(param_1 + 0x28);
        local_50 = (float)*puVar1 / *(float *)(param_1 + 0x24);
        FUN_005fc530(&local_50,&local_48,&local_4c);
        FUN_00612f50(param_1 + 4);
        local_30 = local_10;
        local_2c = local_c;
        local_28 = local_8;
        local_24 = local_4;
      }
      if (*(char *)(param_1 + 0x3c) == '\0') {
        puVar6 = (undefined4 *)(*(int *)(param_1 + 0x4c) + local_5c);
        local_20 = *puVar6;
        local_1c = puVar6[1];
        local_18 = puVar6[2];
        local_14 = puVar6[3];
      }
      else {
        FUN_00797350(&local_20,*(int *)(param_1 + 0x74) + iVar7);
      }
      iVar5 = *(int *)(param_1 + 0x38);
      if (*(char *)(param_1 + 0x3c) == '\0') {
        FUN_00797300(&local_20);
        FUN_007972b0(&local_30);
      }
      else {
        FUN_00793100(local_40,&local_20,0);
        FUN_00793100(local_38,&local_30,1);
        iVar10 = iVar5 * 0x10 + 6;
        iVar5 = 0;
        do {
          if (*(ushort *)((int)local_40 + iVar5) <
              *(ushort *)(iVar10 + -6 + *(int *)(param_1 + 0x88))) {
            *(ushort *)(iVar10 + -6 + *(int *)(param_1 + 0x88)) = *(ushort *)((int)local_40 + iVar5)
            ;
          }
          puVar1 = (ushort *)(iVar10 + *(int *)(param_1 + 0x88));
          if (*puVar1 < *(ushort *)((int)local_38 + iVar5)) {
            *puVar1 = *(ushort *)((int)local_38 + iVar5);
          }
          iVar5 = iVar5 + 2;
          iVar10 = iVar10 + 2;
        } while (iVar5 < 6);
      }
      iVar7 = iVar7 + 0x10;
      local_5c = local_5c + 0x40;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  iVar8 = *(int *)(param_1 + 0x38) + 1;
  *(int *)(param_1 + 0x38) = iVar8;
  FUN_00794110(param_2,uVar4);
  uVar3 = *(undefined4 *)(param_1 + 0x38);
  FUN_00794110(uVar4,param_3);
  iVar7 = *(int *)(param_1 + 0x38) - local_44;
  if (*(char *)(param_1 + 0x3c) != '\0') {
    if (0x800 < iVar7 * 0x10) {
      FUN_007944a0(iVar8,uVar3);
    }
    if (*(char *)(param_1 + 0x3c) != '\0') {
      *(int *)(*(int *)(param_1 + 0x88) + 0xc + iVar2 * 0x10) = -iVar7;
      return;
    }
  }
  *(int *)(iVar2 * 0x40 + 0x20 + *(int *)(param_1 + 0x60)) = iVar7;
  return;
}

