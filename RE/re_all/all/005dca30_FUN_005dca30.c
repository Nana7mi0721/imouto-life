
undefined4 FUN_005dca30(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x45c);
  param_2 = (uint)*(ushort *)(param_1 + 0x44) * param_2;
  if (param_2 < iVar3) {
    if (param_2 < *(int *)(param_1 + 0x6a)) {
      (*DAT_00f3a118)(*(undefined4 *)(param_1 + 0x4e),0);
      (*DAT_00f3a110)(param_1 + 0x4e,0,*(undefined4 *)(param_1 + 0x4a),param_1 + 0x38,0,0,0,4);
      (**(code **)(param_1 + 0x10))
                (*(undefined4 *)(param_1 + 0x24),*(int *)(param_1 + 0x30),
                 *(int *)(param_1 + 0x30) >> 0x1f,0);
      *(undefined4 *)(param_1 + 0x5e) = 0;
      *(undefined4 *)(param_1 + 0x454) = 0;
      *(undefined4 *)(param_1 + 0x458) = 0;
      *(undefined4 *)(param_1 + 0x45c) = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x52);
      puVar1 = (undefined4 *)(param_1 + 0x52);
      *puVar1 = *(undefined4 *)(param_1 + 0x4e);
      *(undefined4 *)(param_1 + 0x4e) = uVar2;
      *(undefined4 *)(param_1 + 0x5e) = *(undefined4 *)(param_1 + 0x66);
      *(int *)(param_1 + 0x458) = *(int *)(param_1 + 0x6a);
      *(undefined4 *)(param_1 + 0x45c) = *(undefined4 *)(param_1 + 0x6a);
      *(undefined4 *)(param_1 + 0x454) = 0;
      (*DAT_00f3a118)(*puVar1);
      (*DAT_00f3a110)(puVar1,0,*(undefined4 *)(param_1 + 0x4a),param_1 + 0x38,0,0,0,4);
      *(undefined4 *)(param_1 + 0x66) = 0;
      *(undefined4 *)(param_1 + 0x6a) = 0;
    }
  }
  else if (param_2 <= *(int *)(param_1 + 0x454) + iVar3) {
    param_2 = param_2 - iVar3;
    *(int *)(param_1 + 0x458) = *(int *)(param_1 + 0x458) + param_2;
    *(int *)(param_1 + 0x454) = *(int *)(param_1 + 0x454) - param_2;
    *(int *)(param_1 + 0x45c) = iVar3 + param_2;
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x45c) + *(int *)(param_1 + 0x454);
  while( true ) {
    if (param_2 <= iVar3) {
      param_2 = param_2 - *(int *)(param_1 + 0x45c);
      *(int *)(param_1 + 0x454) = *(int *)(param_1 + 0x454) - param_2;
      *(int *)(param_1 + 0x458) = *(int *)(param_1 + 0x458) + param_2;
      *(int *)(param_1 + 0x45c) = *(int *)(param_1 + 0x45c) + param_2;
      return 0;
    }
    *(int *)(param_1 + 0x45c) = *(int *)(param_1 + 0x45c) + *(int *)(param_1 + 0x454);
    *(undefined4 *)(param_1 + 0x454) = 0;
    *(undefined4 *)(param_1 + 0x458) = 0;
    iVar3 = FUN_005dc800(param_1);
    if (iVar3 == -1) break;
    iVar3 = *(int *)(param_1 + 0x45c) + *(int *)(param_1 + 0x454);
  }
  *(undefined4 *)(param_1 + 0x454) = 0;
  *(undefined4 *)(param_1 + 4) = 1;
  return 0;
}

