
void __thiscall
FUN_004a1d80(int param_1,int *param_2,int *param_3,undefined4 *param_4,undefined4 *param_5,
            undefined4 *param_6,undefined4 *param_7,undefined4 *param_8,undefined4 *param_9,
            undefined4 *param_10,undefined4 *param_11,undefined4 *param_12,undefined4 *param_13,
            undefined4 *param_14,byte *param_15)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int local_8;
  
  FUN_0049b960(param_2,param_1 + 0x94);
  local_8 = *(int *)(param_1 + 0x94);
  do {
    iVar1 = FUN_004d3180();
    if (iVar1 <= local_8) {
      return;
    }
    iVar1 = FUN_004d31e0(local_8);
    if ((*(int *)(iVar1 + 0x26c) < *param_2) ||
       (iVar1 = FUN_004d31e0(local_8), *param_3 < *(int *)(iVar1 + 0x26c))) {
      iVar1 = FUN_004d31e0(local_8);
      if (*param_3 < *(int *)(iVar1 + 0x26c)) {
        return;
      }
    }
    else {
      uVar2 = (uint)*param_15;
      uVar13 = *param_14;
      uVar12 = *param_13;
      uVar11 = *param_12;
      uVar10 = *param_11;
      uVar9 = *param_10;
      uVar8 = *param_9;
      uVar7 = *param_8;
      uVar6 = *param_7;
      uVar5 = *param_6;
      uVar4 = *param_5;
      uVar3 = *param_4;
      FUN_004d31e0(local_8);
      FUN_004a1ef0(uVar3,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12,uVar13,uVar2);
      iVar1 = FUN_004d31e0(local_8);
      *(undefined4 *)(iVar1 + 0x36c) = DAT_00a17eb8;
      iVar1 = FUN_004d31e0(local_8);
      *(undefined4 *)(iVar1 + 0x370) = DAT_00a0f818;
      iVar1 = FUN_004d31e0(local_8);
      *(undefined4 *)(iVar1 + 0x374) = DAT_00a11794;
      iVar1 = FUN_004d31e0(local_8);
      *(undefined4 *)(iVar1 + 0x378) = DAT_00a0f814;
    }
    local_8 = local_8 + 1;
  } while( true );
}

