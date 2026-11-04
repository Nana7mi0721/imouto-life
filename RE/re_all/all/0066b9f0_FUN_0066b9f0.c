
void FUN_0066b9f0(undefined4 param_1,int *param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = FUN_0066caf0(param_1,0x100);
  *param_2 = iVar2;
  iVar3 = FUN_0066b220(param_3);
  if (iVar3 == 0) {
    uVar4 = 0;
    do {
      *(char *)(uVar4 + iVar2) = (char)uVar4;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x100);
    return;
  }
  uVar4 = 0;
  do {
    uVar1 = FUN_0066b290(uVar4,param_3);
    *(undefined1 *)(uVar4 + iVar2) = uVar1;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x100);
  return;
}

