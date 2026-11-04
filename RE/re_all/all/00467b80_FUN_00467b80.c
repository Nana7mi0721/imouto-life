
undefined4 __fastcall FUN_00467b80(int param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  
  cVar1 = *(char *)(*(int *)(param_1 + 0x898) + 0x10);
  piVar2 = (int *)FUN_004ce990(1);
  if (*(int *)(param_1 + 0x38 + cVar1 * 4) == *piVar2) {
    *(undefined4 *)(param_1 + 0x38 + *(char *)(*(int *)(param_1 + 0x898) + 0x10) * 4) = 0xffffff9c;
    uVar3 = 1;
  }
  else {
    uVar3 = FUN_00452530();
  }
  return uVar3;
}

