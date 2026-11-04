
undefined4 FUN_005f8eb0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1;
  param_1 = 0;
  iVar2 = *(int *)(iVar1 + 0x322);
  if (*(int *)(iVar1 + 0x468) == 0) {
    iVar2 = FUN_006ab9a0(iVar1 + 0x52,*(undefined4 *)(iVar1 + 0x44c),*(undefined4 *)(iVar1 + 0x450),
                         0,iVar2,iVar2 != 1,&param_1);
  }
  else {
    iVar2 = FUN_005f8f30(iVar1 + 0x52,*(undefined4 *)(iVar1 + 0x44c),*(undefined4 *)(iVar1 + 0x450),
                         0,iVar2,iVar2 != 1);
  }
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  *(int *)(iVar1 + 0x454) = iVar2;
  return 0;
}

