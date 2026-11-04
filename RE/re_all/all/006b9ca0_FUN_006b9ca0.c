
undefined4 FUN_006b9ca0(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1 + 0xc9b4;
  iVar2 = FUN_006bf110(iVar3);
  if (iVar2 != 0) {
    return 0xffffffe8;
  }
  uVar1 = FUN_006bf110(iVar3);
  *(undefined1 *)(param_1 + 0x368) = uVar1;
  uVar1 = FUN_006bf0c0(iVar3,6);
  *(undefined1 *)(param_1 + 0x36b) = uVar1;
  iVar2 = FUN_006bf110(iVar3);
  if (iVar2 == 0) {
    *(undefined1 *)(param_1 + 0x36a) = 1;
  }
  else {
    uVar1 = FUN_006bf0c0(iVar3,6);
    *(undefined1 *)(param_1 + 0x36c) = uVar1;
    iVar2 = FUN_006bf110(iVar3);
    if (iVar2 == 0) {
      *(undefined1 *)(param_1 + 0x36a) = 2;
    }
    else {
      uVar1 = FUN_006bf0c0(iVar3,6);
      *(undefined1 *)(param_1 + 0x36d) = uVar1;
      *(undefined1 *)(param_1 + 0x36a) = 3;
    }
  }
  if (*(char *)(param_1 + 0x368) == '\0') {
    iVar3 = FUN_006bf0c0(iVar3,3);
    if (iVar3 != 0) {
      return 0xffffffe9;
    }
  }
  return 0;
}

