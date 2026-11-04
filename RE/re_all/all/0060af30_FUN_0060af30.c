
undefined4 FUN_0060af30(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x224) = 1;
  *(undefined4 *)(param_1 + 0x220) = 0;
  uVar2 = FUN_00550060(0);
  *(undefined4 *)(param_1 + 0x23c) = uVar2;
  iVar1 = param_1 + 0x240;
  iVar3 = FUN_0056db00(iVar1,FUN_0060af00,param_1);
  if (iVar3 == -1) {
    FUN_0056ba10(&DAT_00a06198);
    return 0xffffffff;
  }
  iVar3 = FUN_0056da00(iVar1);
  while (iVar3 != 1) {
    FUN_0056da20(0);
    iVar3 = FUN_0056da00(iVar1);
  }
  return 0;
}

