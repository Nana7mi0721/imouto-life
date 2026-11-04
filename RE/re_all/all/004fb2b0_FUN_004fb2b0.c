
undefined4 FUN_004fb2b0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xffffff9a;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xe0);
    if (iVar1 == 0) {
      uVar2 = 0xffffff9a;
    }
    else if (*(int *)(iVar1 + 0x80) == 0 && *(int *)(iVar1 + 0x84) == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

