
void __thiscall FUN_00485b50(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  param_2 = param_2 * *(int *)(param_1 + 0xb4);
  param_3 = param_3 * *(int *)(param_1 + 0xb4);
  if ((param_2 != 0) || (param_3 != 0)) {
    iVar2 = FUN_004febf1();
    iVar3 = FUN_004febf1();
    if (iVar3 < iVar2) {
      if (param_2 < 0) {
        FUN_004785a0();
      }
      else {
        FUN_00478650();
      }
    }
    else if (param_3 < 0) {
      FUN_00478700();
    }
    else {
      FUN_004784f0();
    }
  }
  iVar3 = *(int *)(param_1 + 0x28) + param_2;
  iVar2 = *(int *)(param_1 + 0x2c) + param_3;
  if (((param_2 == 0) && (param_3 == 0)) || (cVar1 = FUN_00442730(iVar3,iVar2,0), cVar1 != '\0')) {
    FUN_00485cb0();
    *(int *)(param_1 + 0x28) = iVar3;
    *(int *)(param_1 + 0x2c) = iVar2;
    FUN_004fed84((double)(param_2 * param_2 + param_3 * param_3));
    iVar2 = FUN_004fe844();
    *(int *)(param_1 + 0x6c) = ((iVar2 + 0xf) - (int)*(short *)(param_1 + 0x5a)) / 2;
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x6c) << 1;
    *(undefined4 *)(param_1 + 100) = 0;
  }
  return;
}

