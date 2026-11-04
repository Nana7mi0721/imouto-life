
int FUN_0047a4d0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_8;
  
  iVar1 = FUN_0047a490();
  iVar2 = FUN_0047a490();
  iVar3 = FUN_0047a490();
  iVar5 = (param_1 % (iVar1 << 1) + iVar2 * 2) % (iVar3 << 1);
  iVar1 = FUN_0047a4b0();
  iVar2 = FUN_0047a4b0();
  iVar3 = FUN_0047a4b0();
  iVar2 = (param_2 % (iVar1 << 1) + iVar2 * 2) % (iVar3 << 1);
  iVar1 = FUN_0047a490();
  if ((iVar1 * 2 <= iVar5) || (iVar1 = FUN_0047a4b0(), iVar1 * 2 <= iVar2)) {
    return -1;
  }
  iVar2 = iVar2 / 2;
  iVar5 = iVar5 / 2;
  FUN_004cd3a0(param_3);
  FUN_004cd3a0(iVar5);
  piVar4 = (int *)FUN_004ce0e0(iVar2);
  local_8 = *piVar4;
  if (local_8 < 100000) {
    local_8 = local_8 + 0x10;
  }
  else {
    local_8 = local_8 / 100000 + -1;
  }
  return local_8;
}

