
undefined4 __fastcall FUN_00467a90(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  iVar2 = FUN_004ce080();
  if ((iVar2 != 0) && (piVar3 = (int *)FUN_004ce990(0), *piVar3 == 2)) {
    piVar3 = (int *)FUN_004ce990(1);
    *(int *)(param_1 + 8) = *piVar3 + -1;
    return 1;
  }
  cVar1 = *(char *)(*(int *)(param_1 + 0x898) + 0x10);
  piVar3 = (int *)FUN_004ce990(1);
  if (*(int *)(param_1 + 0x38 + cVar1 * 4) == *piVar3) {
    *(undefined4 *)(param_1 + 0x38 + *(char *)(*(int *)(param_1 + 0x898) + 0x10) * 4) = 0xffffff9c;
    uVar4 = 1;
  }
  else {
    iVar2 = FUN_004ce080();
    if (iVar2 == 0) {
      uVar4 = FUN_00452530();
    }
    else {
      piVar3 = (int *)FUN_004ce990(1);
      *(int *)(param_1 + 8) = *piVar3 + -1;
      uVar4 = 1;
    }
  }
  return uVar4;
}

