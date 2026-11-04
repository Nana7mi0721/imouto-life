
int FUN_007a2170(int param_1,int param_2,byte param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = -1;
  uVar2 = *(uint *)(param_1 + 0x1c);
  do {
    uVar1 = uVar2;
    iVar3 = iVar3 + 1;
    uVar2 = (uint)*(byte *)(iVar3 + param_2) * (*(uint *)(param_1 + 0x1c) >> (param_3 & 0x1f));
  } while (*(uint *)(param_1 + 0x20) < uVar2);
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) - uVar2;
  *(uint *)(param_1 + 0x1c) = uVar1 - uVar2;
  FUN_007a2000(param_1);
  return iVar3;
}

