
undefined4
FUN_0066a110(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((*(ushort *)((int)param_2 + 0x4a) & 0x8000) != 0) {
    return 0;
  }
  if ((param_5 < 2) && ((*(ushort *)((int)param_2 + 0x4a) & 2) != 0)) {
    iVar1 = FUN_0066a040(param_3,param_2 + 1,100);
    if (iVar1 == 0) {
      *(byte *)((int)param_2 + 0x4b) = *(byte *)((int)param_2 + 0x4b) | 0x80;
      FUN_00668960(param_1,s_inconsistent_chromaticities_00a0be8c);
      return 0;
    }
    if (param_5 == 0) {
      return 1;
    }
  }
  puVar2 = param_3;
  puVar3 = param_2;
  for (iVar1 = 8; puVar3 = puVar3 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
  }
  puVar3 = param_2 + 9;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *param_4;
    param_4 = param_4 + 1;
    puVar3 = puVar3 + 1;
  }
  *(byte *)((int)param_2 + 0x4a) = *(byte *)((int)param_2 + 0x4a) | 2;
  iVar1 = FUN_0066a040(param_3,&DAT_0081e2d8,1000);
  if (iVar1 == 0) {
    *(ushort *)((int)param_2 + 0x4a) = *(ushort *)((int)param_2 + 0x4a) & 0xffbf;
    return 2;
  }
  *(byte *)((int)param_2 + 0x4a) = *(byte *)((int)param_2 + 0x4a) | 0x40;
  return 2;
}

