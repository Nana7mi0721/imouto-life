
int FUN_004fa190(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    iVar2 = -0x66;
  }
  else if (*(int *)(param_1 + 0x60) == 0 && *(int *)(param_1 + 100) == 0) {
    iVar2 = -100;
  }
  else {
    if ((((*(int *)(param_1 + 0x38) != 0xffff) || (*(int *)(param_1 + 0x3c) != 0)) &&
        (*(uint *)(param_1 + 0x50) + 1 == *(int *)(param_1 + 0x38))) &&
       (*(int *)(param_1 + 0x54) + (uint)(0xfffffffe < *(uint *)(param_1 + 0x50)) ==
        *(int *)(param_1 + 0x3c))) {
      return -100;
    }
    uVar3 = *(int *)(param_1 + 0xa8) + 0x2e + *(int *)(param_1 + 0xac) + *(int *)(param_1 + 0xb0);
    uVar1 = *(uint *)(param_1 + 0x58);
    *(uint *)(param_1 + 0x58) = uVar3 + *(uint *)(param_1 + 0x58);
    *(uint *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + (uint)CARRY4(uVar3,uVar1);
    uVar1 = *(uint *)(param_1 + 0x50);
    *(uint *)(param_1 + 0x50) = uVar1 + 1;
    *(uint *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + (uint)(0xfffffffe < uVar1);
    iVar2 = FUN_004f9850(param_1,param_1 + 0x80,param_1 + 0xd8,0,0,0,0,0,0);
    *(uint *)(param_1 + 0x60) = (uint)(iVar2 == 0);
    *(undefined4 *)(param_1 + 100) = 0;
  }
  return iVar2;
}

