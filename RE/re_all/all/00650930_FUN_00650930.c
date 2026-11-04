
undefined4 FUN_00650930(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_4;
  
  iVar2 = param_1;
  if (*(int *)(param_1 + 8) == 0) {
    return 1;
  }
  iVar1 = FUN_00650aa0(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  if ((((*(uint *)(iVar2 + 0xc) & 0x200000) != 0) && ((*(uint *)(iVar2 + 0xc) & 8) == 0)) &&
     (*(int *)(iVar2 + 8) == 2)) {
    param_1 = 0;
    local_4 = 0;
    iVar1 = FUN_006507c0(iVar2);
    if (iVar1 == 0) {
      iVar1 = FUN_0064e2c0(iVar2,0x111,&param_1);
      if (((iVar1 == 0) || (iVar1 = FUN_0064e2c0(iVar2,0x117,&local_4), iVar1 == 0)) ||
         (iVar1 = FUN_0065dbb0(iVar2,0x111,0x10,*(undefined4 *)(iVar2 + 0xa8),param_1), iVar1 == 0))
      goto LAB_00650a79;
      uVar4 = *(undefined4 *)(iVar2 + 0xa8);
      uVar3 = 0x117;
    }
    else {
      iVar1 = FUN_0064e2c0(iVar2,0x144,&param_1);
      if (((iVar1 == 0) || (iVar1 = FUN_0064e2c0(iVar2,0x145,&local_4), iVar1 == 0)) ||
         (iVar1 = FUN_0065dbb0(iVar2,0x144,0x10,*(undefined4 *)(iVar2 + 0xa8),param_1), iVar1 == 0))
      goto LAB_00650a79;
      uVar4 = *(undefined4 *)(iVar2 + 0xa8);
      uVar3 = 0x145;
    }
    iVar1 = FUN_0065dbb0(iVar2,uVar3,0x10,uVar4,local_4);
    if (iVar1 != 0) {
      *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xffdfffbf;
      return 1;
    }
  }
LAB_00650a79:
  if (((*(uint *)(iVar2 + 0xc) & 0x200008) == 0) || (iVar2 = FUN_0065a850(iVar2), iVar2 != 0)) {
    return 1;
  }
  return 0;
}

